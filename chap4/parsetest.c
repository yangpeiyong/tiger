#include <stdio.h>
#include <stdlib.h>
#include "parse.h"
#include "prabsyn.h"

int main(int argc, char **argv)
{
  extern int yydebug;
  yydebug = 1;

  if (argc!=2) {
    fprintf(stderr,"usage: a.out filename\n");
    exit(1);
  }
  pr_exp(stdout, parse(argv[1]), 4);
  return 0;
}
