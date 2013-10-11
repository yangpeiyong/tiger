#include "answer.h"
#include "prog1.h"

int main(void)
{
  /*printf("%d\n", maxargs(prog()));*/
  interp(prog());
  return 0;
}
