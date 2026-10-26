double __thiscall sub_464A00(void *this, int a2, float a3)
{
  float *v3; // edx
  double result; // st7
  long double v5; // st6

  v3 = (float *)((char *)&unk_62BF68 + 25304 * a2);
  if ( a3 <= 0.0 )
    result = *(float *)(*(_DWORD *)this + 4);
  else
    result = a3;
  v5 = fabs(sqrt(v3[4407] * v3[4407] + v3[4408] * v3[4408] + v3[4409] * v3[4409]) * 2.2369363);
  if ( v5 < 25.0 )
    result = result * (1.25 - v5 * 0.039999999 * 1.25 + 1.0);
  if ( *((_DWORD *)v3 + 6325) )
  {
    if ( ((_DWORD)v3[6324] & 2) == 0 )
      return 2.0;
  }
  else
  {
    if ( ((_DWORD)v3[6324] & 2) == 0 )
      result = result * 4.0;
    if ( result >= 0.0 )
    {
      if ( result > 0.5 )
        return 0.5;
    }
    else
    {
      return 0.0;
    }
  }
  return result;
}
