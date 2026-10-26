long double __stdcall sub_41FE80(float a1, float a2)
{
  long double result; // st7

  result = a2 - a1;
  if ( fabs(result) >= 3.141592653589793 )
  {
    if ( result >= 0.0 )
      return result - 6.2831855;
    else
      return result + 6.2831855;
  }
  return result;
}
