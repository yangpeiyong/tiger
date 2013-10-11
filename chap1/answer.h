#ifndef __ANSWER_H
#define __ANSWER_H

#include "util.h"
#include "slp.h"

typedef struct table *Table_;
struct table {
  string id;
  int value;
  Table_ tail;
};
struct int_and_table {
  int value;
  Table_ t;
};

int maxargs(A_stm);
int maxargs_exp(A_exp);
int maxargs_explist(A_expList);
int length_explist(A_expList);

Table_ Table(string id, int value, Table_ tail);
int lookup(Table_ t, string key);
Table_ update(Table_ t, string id, int value);
void interp(A_stm s);
Table_ interpStm(A_stm s, Table_ t);
struct int_and_table interpExp(A_exp e, Table_ t);
Table_ print(A_expList explist, Table_ t);
#endif
