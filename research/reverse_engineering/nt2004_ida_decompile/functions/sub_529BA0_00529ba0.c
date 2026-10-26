double __thiscall sub_529BA0(float *this, float a2, _DWORD *a3, _DWORD *a4)
{
  float *v4; // eax
  double result; // st7
  double v6; // st6
  double v7; // st6

  v4 = (float *)*((_DWORD *)this + 86);
  result = 99999.898;
  if ( v4 )
    result = *v4;
  if ( result < flt_628F78 )
    result = flt_628F78;
  if ( (this[23] - this[22]) * 1.5 > 0.0 )
  {
    *a3 = *((_DWORD *)this + 22);
    *a4 = *((_DWORD *)this + 23);
    v6 = this[22] + 0.5;
    if ( a2 >= v6 )
    {
      v7 = this[23] - 0.5;
      if ( a2 > v7 )
        return result * (a2 - v7 + 1.0);
    }
    else
    {
      return result * (v6 - a2 + 1.0);
    }
  }
  else
  {
    *a3 = *((_DWORD *)this + 22);
    *a4 = *((_DWORD *)this + 23);
  }
  return result;
}
