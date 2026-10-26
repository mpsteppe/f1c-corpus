double __thiscall sub_473750(int *this, double a2)
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
    if ( *(double *)(v2 + 2144) >= 0.0 )
    {
      if ( v7 >= *(double *)(v2 + 2144) )
        goto LABEL_4;
      *(double *)(v2 + 2144) = *(double *)(v2 + 2144) - v7;
      return v7 + a2;
    }
    else
    {
      if ( v7 >= -*(double *)(v2 + 2144) )
      {
LABEL_4:
        result = a2 + *(double *)(v2 + 2144);
        *(double *)(v2 + 2144) = 0.0;
        return result;
      }
      *(double *)(v2 + 2144) = v7 + *(double *)(v2 + 2144);
      return a2 - v7;
    }
  }
  return result;
}
