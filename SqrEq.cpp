#include <stdio.h>
#include "SolveEquations.h"

//-----------------------------------------------------------------------------

int main(){

  double a = 0, b = 0, c = 0;
  double x1 = 0, x2 = 0;
  int NumberOfRoots = 0;

  printf("Enter a, b, c \n");
  scanf("%lg %lg %lg", &a, &b, &c);

  if(isZero(a)){
    printf("You are solving: %lgX + (%lg) = 0\n", b, c);
    NumberOfRoots = LineEq(b, c, &x1);
  }
  else{
    printf("You are solving: %lgX^2 + (%lg)X + (%lg) = 0\n", a, b, c);
    NumberOfRoots = SquareEq(a, b, c, &x1, &x2);
  }

  switch(NumberOfRoots){
    case 0: printf("No roots");
            break;
    case 1: printf("x = %lg", x1);
            break;
    case 2: printf("x1 = %lg \nx2 = %lg", x1, x2);
            break;
    case INF_ROOTS: printf("Any x");
            break;
    default: printf("ERROR: Number of roots out of range %d", NumberOfRoots);
            break;
  }

  return 0;
}
