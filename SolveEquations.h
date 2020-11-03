//{============================================================================
//!  @mainpage  This libruary is solving square and linear equations
//!  @author    Roman Lem
//!  @version   2.0
//}============================================================================

#include <math.h>
#include <assert.h>

const int INF_ROOTS = -1;

//{============================================================================
//!  This function solve square equations
//!
//!  @param [in]   a  first coefficient
//!  @param [in]   b  second coefficient
//!  @param [in]   c  third coefficient
//!  @param [out]  x1 first root
//!  @param [out]  x2 second root
//!
//!  @return Number of roots
//}============================================================================

int SquareEq(double a, double b, double c, double* x1, double* x2);

//{============================================================================
//!  This function solve linear equations
//!
//!  @param [in]   a  first coefficient in ax + b = 0
//!  @param [in]   b  second coefficient in ax + b = 0
//!  @param [out]  x1 root of equation
//!
//!  @return Number of roots
//}============================================================================

int LineEq(double a, double b, double* x1);

//{============================================================================
//!  This function check, isn't value is 0
//!
//!  @param [in]   number  -tested value
//!
//!  @return 1 or 0
//}============================================================================

int isZero(double number);

//-----------------------------------------------------------------------------

int Test_isZero();

//-----------------------------------------------------------------------------

int SquareEq(double a, double b, double c, double* x1, double* x2){

  assert(isfinite (a));
  assert(isfinite (b));
  assert(isfinite (c));

  assert(x1 != NULL);
  assert(x2 != NULL);
  assert(x1 != x2);

  const int INF_ROOTS = -1;
  if(isZero(a)){
    if(isZero(b)){
      return (isZero(c))? INF_ROOTS : 0;
    }
    else{ /*if (b != 0)*/
      *x1 = -c/b;
      return 1;
    }
  }
  else{  /*if (a != 0)*/
    double d = b*b - 4*a*c;

    if(! isZero(d) && d < 0){
      return 0;
    }
    else if (isZero(d)){
      *x1 = -b/(2*a);
      return 1;
    }
    else{ /*if (d > 0)*/
      *x1 = (-b + sqrt(d))/(2*a);
      *x2 = (-b - sqrt(d))/(2*a);
      return 2;
    }
  }
}

//-----------------------------------------------------------------------------

int LineEq(double a, double b, double* x){

  assert(isfinite (a));
  assert(isfinite (b));
  assert(x != NULL);

  if(isZero(a)){
    return (isZero(b))? INF_ROOTS : 0;
  }
  else{        /*if (b != 0)*/
    *x = -b/a;
    return 1;
  }

}

//-----------------------------------------------------------------------------

int isZero(double number){

  double accuracy = 1e-6;

  return (fabs(number) <= accuracy) ? 1 : 0;
}

//-----------------------------------------------------------------------------

int Test_isZero(){

  double value = 0;
  int expected = 0, result = 0;

  #define DO_TEST                                                                   \
  result = isZero(value);                                                           \
  if(result == expected){                                                           \
    printf("Test on %d line: PASSED\n", __LINE__);                                  \
  }                                                                                 \
  else{                                                                             \
    printf("Test on %d line: FAILED (%d):(%d)", __LINE__, result, expected);        \
    return 0;                                                                       \
  }

  value = 0;
  expected = 1;
  DO_TEST

  value = 1;
  expected = 0;
  DO_TEST

  value = -1;
  expected = 0;
  DO_TEST

  value = 1e-6;
  expected = 1;
  DO_TEST

  value = -1e-6;
  expected = 1;
  DO_TEST

  #undef DO_TEST

  return 0;
}

//-----------------------------------------------------------------------------

