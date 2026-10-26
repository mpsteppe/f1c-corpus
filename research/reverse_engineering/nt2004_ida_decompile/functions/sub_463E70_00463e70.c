double __thiscall sub_463E70(int *this, double a2)
{
  int v2; // ecx
  double result; // st7
  unsigned __int8 v5; // c2
  unsigned __int8 v6; // c3
  double v7; // st7

  v2 = *this;
  result = a2;
  if ( !(v6 | v5) )
  {
    v7 = a2 * 0.01;
    if ( *(double *)(v2 + 668) >= 0.0 )
    {
      if ( v7 < *(double *)(v2 + 668) )
      {
        *(double *)(v2 + 668) = *(double *)(v2 + 668) - v7;
        return v7 + a2;
      }
      else
      {
        result = a2 + *(double *)(v2 + 668);
        *(_DWORD *)(v2 + 668) = 0;
        *(_DWORD *)(v2 + 672) = 0;
      }
    }
    else if ( v7 < -*(double *)(v2 + 668) )
    {
      *(double *)(v2 + 668) = v7 + *(double *)(v2 + 668);
      return a2 - v7;
    }
    else
    {
      result = a2 + *(double *)(v2 + 668);
      *(_DWORD *)(v2 + 668) = 0;
      *(_DWORD *)(v2 + 672) = 0;
    }
  }
  return result;
}
