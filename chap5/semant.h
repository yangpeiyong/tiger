#ifndef __SEMANT_H__
#define __SEMANT_H__

#include "env.h"
#include "absyn.h"
#include "types.h"
#include "table.h"

typedef void *Tr_exp;
struct expty {
  Tr_exp exp;
  Ty_ty ty;
};

struct expty ExpTy(Tr_exp exp, Ty_ty ty);

struct expty transVar(S_table venv, S_table tenv, A_var v);
struct expty transExp(S_table venv, S_table tenv, A_exp e);

struct expty transCallExp(S_table venv, S_table tenv, A_exp e);
struct expty transOpExp(S_table venv, S_table tenv, A_exp e);
struct expty transRecordExp(S_table venv, S_table tenv, A_exp e);
struct expty transSeqExp(S_table venv, S_table tenv, A_expList e);
struct expty transAssignExp(S_table venv, S_table tenv, A_exp e);
struct expty transIfExp(S_table venv, S_table tenv, A_exp e);
struct expty transWhileExp(S_table venv, S_table tenv, A_exp e);
struct expty transForExp(S_table venv, S_table tenv, A_exp e);
struct expty transBreakExp(S_table venv, S_table tenv, A_exp e);
struct expty transLetExp(S_table venv, S_table tenv, A_exp e);
struct expty transArrayExp(S_table venv, S_table tenv, A_exp e);

void transDec(S_table venv, S_table tenv, A_dec d);
void transFuncDec(S_table venv, S_table tenv, A_dec d);
void transVarDec(S_table venv, S_table tenv, A_dec d);
void transTypeDec(S_table venv, S_table tenv, A_dec d);
Ty_ty transTy(S_table tenv, A_ty t);
Ty_tyList makeFormalTyList(S_table tenv, A_fieldList fieldList);

// check the whole program
void SEM_transProg(A_exp exp);

#endif
