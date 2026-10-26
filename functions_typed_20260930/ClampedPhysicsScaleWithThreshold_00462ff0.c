double __thiscall sub_462FF0(void *this, int a2, float a3)
{
  float *v3; // edx
  double result; // st7
  long double v5; // st6

  v3 = (float *)((char *)&stru_5EC6D8 + 18624 * a2);
  if ( a3 <= 0.0 )
    result = *(float *)(*(_DWORD *)this + 4);
  else
    result = a3;
  v5 = fabs(sqrt(v3[3390] * v3[3390] + v3[3391] * v3[3391] + v3[3392] * v3[3392]) * 2.2369363);
  if ( v5 < 25.0 )
    result = result * (1.25 - v5 * 0.039999999 * 1.25 + 1.0);
  if ( ((_DWORD)v3[4655] & 2) == 0 )
    result = result * 4.0;
  if ( result < 0.0 )
    return 0.0;
  if ( result > 0.5 )
    return 0.5;
  return result;
}

