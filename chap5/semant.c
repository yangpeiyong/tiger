#include "semant.h"

void SEM_transProg(A_exp exp)
{
  transExp(E_base_venv(), E_base_tenv(), exp);
}

/* 对语义错误的处理方式：
 * 1. 发现错误时打印错误信息后马上返回(return NULL or return)
 */

struct expty ExpTy(Tr_exp exp, Ty_ty ty)
{
  struct expty e;
  e.exp = exp;
  e.ty = ty;
  return e;
}

/* translate expression 
 */
struct expty transExp(S_table venv, S_table tenv, A_exp e)
{
  switch (e->kind) {
    case A_varExp:
      return transVar(venv, tenv, e->u.var);

    case A_nilExp:
      return ExpTy(NULL, Ty_Nil());

    case A_intExp:
      return ExpTy(NULL, Ty_Int());

    case A_stringExp:
      return ExpTy(NULL, Ty_String());

    case A_callExp:
      return transCallExp(venv, tenv, e);

    case A_opExp:
      return transOpExp(venv, tenv, e);

    case A_recordExp:
      return transRecordExp(venv, tenv, e);

    case A_seqExp:
      return transSeqExp(venv, tenv, e->u.seq);

    case A_assignExp:
      return transAssignExp(venv, tenv, e);

    case A_ifExp:
      return transIfExp(venv, tenv, e);

    case A_whileExp:
      return transWhileExp(venv, tenv, e);

    case A_forExp:
      return transForExp(venv, tenv, e);

    case A_breakExp:
      return transBreakExp(venv, tenv, e);

    case A_letExp:
      return transLetExp(venv, tenv, e);

    case A_arrayExp:
      return transArrayExp(venv, tenv, e);
  }

  assert(0);
}

// translate function call: check that arguments match the
// formal params
struct expty transCallExp(S_table venv, S_table tenv, A_exp e)
{
  E_enventry ee = S_look(venv, e->u.call.func);
  if (!ee) {
    EM_error(e->pos, "undefined function %s", S_name(e->u.call.func));
    return ExpTy(NULL, NULL);
  }

  Ty_tyList formals = ee->u.fun.formals;
  A_expList args = e->u.call.args;
  for (; formals && args; formals = formals->tail, args = args->tail) {
    if (!Ty_is_compatible(formals->head, transExp(venv, tenv, args->head).ty)) {
      EM_error(e->pos, "arguments type mismatch");
      return ExpTy(NULL, NULL);
    }
  }
  return ExpTy(NULL, ee->u.fun.result);
}

/* exp op exp, rules:
 * 1. +,-,*,/ only apply to integer operands
 * 2. =,<>,>,<,>=,<= apply to:
 *  integers
 *  record or array of the same type: compare pointers
 *  strings: compare contents
 */
struct expty transOpExp(S_table venv, S_table tenv, A_exp e)
{
  struct expty left = transExp(venv, tenv, e->u.op.left);
  struct expty right = transExp(venv, tenv, e->u.op.right);

  switch (e->u.op.oper) {
    case A_plusOp:
    case A_minusOp:
    case A_timesOp:
    case A_divideOp:
      if (left.ty->kind != Ty_int) {
        EM_error(e->u.op.left->pos, "integer required");
      }
      if (right.ty->kind != Ty_int) {
        EM_error(e->u.op.right->pos, "integer required");
      }
      return ExpTy(NULL, Ty_Int());

    case A_eqOp:
    case A_neqOp:
    case A_ltOp:
    case A_leOp:
    case A_gtOp:
    case A_geOp:
      if (!Ty_is_compatible(left.ty, right.ty)) {
        EM_error(e->pos, "operands type mismatch");
      }
      return ExpTy(NULL, Ty_Int());
  }

  assert(0);
}

/* type-id { id = exp {, id = exp}} or type-id {}
 * the field names and types of the record exp must match
 * those of the named type, in the order given
 */
struct expty transRecordExp(S_table venv, S_table tenv, A_exp e)
{
  Ty_ty recordType = S_look(tenv, e->u.record.typ);
  if (!recordType) {
    EM_error(e->pos, "undefined record type %s",
        S_name(e->u.record.typ));
    return ExpTy(NULL, NULL);
  }

  A_efieldList efl = e->u.record.fields;
  Ty_fieldList tfl = recordType->u.record;

  while (efl && tfl) {
    if (efl->head->name != tfl->head->name) {
      EM_error(e->pos, "field name error %s", S_name(efl->head->name));
    }
    if (transExp(venv, tenv, efl->head->exp).ty != tfl->head->ty) {
      EM_error(e->pos, "field type error %s", S_name(efl->head->name));
    }

    efl = efl->tail;
    tfl = tfl->tail;
  }
  return ExpTy(NULL, recordType);
}

// evaluate the exp list from left to right, use the last
// exp's result as the result of the whole list
struct expty transSeqExp(S_table venv, S_table tenv, A_expList el)
{
  while (el->tail) {
    transExp(venv, tenv, el->head);
    el = el->tail;
  }

  return transExp(venv, tenv, el->head);
}

/* lvalue := exp
 * evaluates lvalue, then exp; set the contents of the lvalue
 * to the result of exp; check that the types of lvalue and
 * the exp are the same, but the whole assignment exp produce
 * no value, so (a := b) + c is illegal
 */
struct expty transAssignExp(S_table venv, S_table tenv, A_exp e)
{
  struct expty lv = transVar(venv, tenv, e->u.assign.var);
  struct expty exp = transExp(venv, tenv, e->u.assign.exp);
  if (!Ty_is_compatible(lv.ty, exp.ty)) {
    EM_error(e->pos, "assignment types mismatch");
  }

  return ExpTy(NULL, Ty_Void());
}

/* if exp1 then exp2 [else exp3]
 * 1. exp1 is integer type
 * 2. exp2 and exp3 are the same type if exp3 exists
 * 3. exp2 produce no value if exp3 does not exists
 */
struct expty transIfExp(S_table venv, S_table tenv, A_exp e)
{
  struct expty test = transExp(venv, tenv, e->u.iff.test);
  struct expty then = transExp(venv, tenv, e->u.iff.then);

  if (test.ty != Ty_Int()) {
    EM_error(e->pos, "test exp of if is not integer");
  }

  if (e->u.iff.elsee) {
    struct expty elsee = transExp(venv, tenv, e->u.iff.elsee);
    if (!Ty_is_compatible(then.ty, elsee.ty)) {
      EM_error(e->pos, "then and elsee type of if mismatch");
    }
    return ExpTy(NULL, elsee.ty);
  } else {
    if (then.ty != Ty_Void()) {
      EM_error(e->pos, "then type of if is NOT void");
    }
    return ExpTy(NULL, Ty_Void());
  }
}

/* while exp1 do exp2
 * 1. exp1's type is integer
 * 2. exp2 produces no value
 */
struct expty transWhileExp(S_table venv, S_table tenv, A_exp e)
{
  struct expty test = transExp(venv, tenv, e->u.whilee.test);
  struct expty body = transExp(venv, tenv, e->u.whilee.body);
  if (test.ty != Ty_Int()) {
    EM_error(e->pos, "test type of while is not integer");
  }

  if (body.ty != Ty_Void()) {
    EM_error(e->pos, "body's type of while must be void");
  }

  return ExpTy(NULL, Ty_Void());
}

/* for id := exp1 to exp2 do exp3
 * 1. both exp1 and exp2 are integer type
 * 2. exp3 is void type
 * 3. id is a new variable implicitly declared by the for 
 * statement, whose scope covers only exp3
 */
struct expty transForExp(S_table venv, S_table tenv, A_exp e)
{
  struct expty lo = transExp(venv, tenv, e->u.forr.lo);
  struct expty hi = transExp(venv, tenv, e->u.forr.hi);
  struct expty body;

  if (lo.ty != Ty_Int() || hi.ty != Ty_Int()) {
    EM_error(e->pos, "low or high range type is not integer");
  }

  S_beginScope(venv);
  transDec(venv, tenv, 
      A_VarDec(e->pos,
        e->u.forr.var,
        S_Symbol("int"),
        e->u.forr.lo));
  body = transExp(venv, tenv, e->u.forr.body);
  if (body.ty != Ty_Void()) {
    EM_error(e->pos, "body of for is not void");
  }
  S_endScope(venv);
  return ExpTy(NULL, Ty_Void());
}

// TODO
struct expty transBreakExp(S_table venv, S_table tenv, A_exp e)
{
}

/* let decs in expseq end
 * the result of the last exp of expseq is that of the entire
 * let-exp
 */
struct expty transLetExp(S_table venv, S_table tenv, A_exp e)
{
  struct expty exp;
  A_decList d;
  S_beginScope(venv);
  S_beginScope(tenv);

  for (d = e->u.let.decs; d; d = d->tail) {
    transDec(venv, tenv, d->head);
  }

  exp = transSeqExp(venv, tenv, e->u.let.body);

  S_endScope(venv);
  S_endScope(tenv);

  return exp;
}

/* type-id[exp1] of exp2
 * 1. type-id is array
 * 2. exp1 is integer
 */
struct expty transArrayExp(S_table venv, S_table tenv, A_exp e)
{
  struct expty size = transExp(venv, tenv, e->u.array.size);
  struct expty init = transExp(venv, tenv, e->u.array.init);
  Ty_ty typ = S_look(tenv, e->u.array.typ);

  if (size.ty != Ty_Int()) {
    EM_error(e->pos, "type of array size is not integer");
  }

  if (typ->kind != Ty_array) {
    EM_error(e->pos, "%s is not a array", S_name(e->u.array.typ));
  }

  if (init.ty != typ->u.array) {
    EM_error(e->pos, "type of element of array mismatch");
  }

  return ExpTy(NULL, typ);
}

struct expty transVar(S_table venv, S_table tenv, A_var v)
{
  switch(v->kind) {
    case A_simpleVar: {
      E_enventry x = S_look(venv, v->u.simple);
      if (x && x->kind == E_varEntry)
        return ExpTy(NULL, x->u.var.ty);
      else {
        EM_error(v->pos, "undefined variable %s",
            S_name(v->u.simple));
        return ExpTy(NULL, NULL);
      }
    }

    case A_fieldVar: {
      struct expty et = transVar(venv, tenv, v->u.field.var);
      if (et.ty && et.ty->kind == Ty_record) {
        Ty_fieldList fl = et.ty->u.record;
        for(; fl; fl = fl->tail) {
          if (fl->head->name == v->u.field.sym) {
            return ExpTy(NULL, fl->head->ty);
          }
        }
      }
      // can NOT get the v's name, use field name instaed
      EM_error(v->pos, "undefined variable %s",
          S_name(v->u.field.sym));
      return ExpTy(NULL, NULL);
    }

    case A_subscriptVar: {
      struct expty et = transVar(venv, tenv, v->u.field.var);
      if (et.ty && et.ty->kind == Ty_array) {
        return ExpTy(NULL, et.ty->u.array);
      }
      // can NOT get v's name
      EM_error(v->pos, "undefined variable");
      return ExpTy(NULL, NULL);
    }
  }
}

void transDec(S_table venv, S_table tenv, A_dec d)
{
  switch(d->kind) {
    case A_functionDec:
      transFuncDec(venv, tenv, d);
      break;
    case A_varDec:
      transVarDec(venv, tenv, d);
      break;
    case A_typeDec:
      transTypeDec(venv, tenv, d);
      break;
  }
}

Ty_tyList makeFormalTyList(S_table tenv, A_fieldList fieldList)
{
  A_fieldList fl = fieldList;
  Ty_tyList tl = NULL;
  Ty_tyList ret = NULL;
  Ty_ty ty;

  // 从左到右构造参数
  for (; fl; fl = fl->tail) {
    ty = S_look(tenv, fl->head->typ);
    if (ty) {
      if (tl) {
        tl = tl->tail = Ty_TyList(ty, NULL);
      } else {
        ret = tl = Ty_TyList(ty, tl);
      }
    } else {
      EM_error(fl->head->pos, "undefined type %s", S_name(fl->head->typ));
    }
  }

  return ret;
}

/* translate function declaration
 * TODO
 * reduce the result type from the body and check that
 * it maps the specified result(including the void case
 * -it is a procedure)
 */
void transFuncDec(S_table venv, S_table tenv, A_dec d)
{
  // add the function itself
  Ty_ty resultTy;
  if (d->u.function.result)
    resultTy = S_look(tenv, d->u.function.result);
  else
    resultTy = Ty_Void();

  Ty_tyList formalTys = makeFormalTyList(tenv, d->u.function.params);
  S_enter(venv, d->u.function.name, E_FunEntry(formalTys, resultTy));

  // re-parse the formal params and add them as variable
  // binding for the body
  S_beginScope(venv);
  A_fieldList fl = d->u.function.params;
  Ty_tyList tl = formalTys;
  for (; fl; fl = fl->tail, tl = tl->tail) {
    S_enter(venv, fl->head->name, E_VarEntry(tl->head));
  }
  transExp(venv, tenv, d->u.function.body);
  S_endScope(venv);
}

/* translate variable declaration
 * var id:type-id := exp
 */
void transVarDec(S_table venv, S_table tenv, A_dec d)
{
  struct expty e = transExp(venv, tenv, d->u.var.init);
  if (d->u.var.typ) {
    /* 1. check the type constraint if any
     * 2. init value of type Ty_Nil must be constrainted 
     * by a Ty_Record type
     */
    Ty_ty expected_ty = S_look(tenv, d->u.var.typ);
    if (!expected_ty) {
      EM_error(d->pos, "undefined type %s", S_name(d->u.var.typ));
      return;
    }

    if ((expected_ty->kind != Ty_record && e.ty == Ty_Nil())
        || expected_ty != e.ty) {
      EM_error(d->pos, "inconsistent var type %s",
          S_name(d->u.var.var));
      return;
    }
  }

  S_enter(venv, d->u.var.var, E_VarEntry(e.ty));
}

/* translate type declaration
 */
void transTypeDec(S_table venv, S_table tenv, A_dec d)
{
  Ty_ty ty = transTy(tenv, d->u.type.name, d->u.type.ty);
  if (ty)
    S_enter(tenv, d->u.type.name, ty);
  else
    EM_error(d->pos, "type defined error %s", d->u.type.name);
}

/* translate A_ty in AST to real type representation
 */
Ty_ty transTy(S_table tenv, S_symbol ty_name, A_ty t)
{
  switch(t->kind) {
    case A_nameTy: {
      Ty_ty ty = S_look(tenv, t->u.name);
      if (ty)
        return Ty_Name(ty);
      else
        return NULL;
    }
    case A_recordTy: {
      A_fieldList a_record = NULL;
      A_field a_field = NULL;
      Ty_fieldList t_record = NULL;
      Ty_fieldList saved_t_record = NULL;
      Ty_ty ty = NULL;

      /* we only allow record field type to refer itself or already defined
       * type: type record = { id : record, id : other_defined_type }
       */
      for (a_record = t->u.record; a_record; a_record = a_record->tail) {
        a_field = a_record->head;
        ty = S_look(tenv, a_field->typ);
        if (ty_name == a_field->typ || ty) {
          if (t_record) {
            t_record->tail = Ty_FieldList(Ty_Field(a_field->name, ty), NULL);
            t_record = t_record->tail;
          } else {
            t_record = Ty_FieldList(Ty_Field(a_field->name, ty), NULL);
            saved_t_record = t_record;
          }
        } else {
          EM_error(a_field->pos, "undefined type %s", S_name(a_field->typ));
          return NULL;
        }
      }
      
      // fill the record's self-recursive reference
      Ty_ty new_record = Ty_Record(saved_t_record);
      Ty_fieldList tfl = NULL;
      for (tfl = t_record; tfl; tfl = tfl->tail) {
        if (!tfl->head->ty) {
          tfl->head->ty = new_record;
        }
      }
      return new_record;
    }
    case A_arrayTy: {
      Ty_ty ty = S_look(tenv, t->u.array);
      if (ty)
        return Ty_Array(ty);
      else
        return NULL;
    }
  }
}
