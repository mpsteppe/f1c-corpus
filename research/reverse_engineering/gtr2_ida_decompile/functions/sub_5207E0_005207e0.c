double __stdcall sub_5207E0(float a1, float a2)
{
  double result; // st7

  if ( a1 <= (double)a2 )
    result = a2 - a1;
  else
    result = a1 - a2;
  if ( result > 3.141592653589793 )
    return result - (result - 3.141592653589793);
  return result;
}
