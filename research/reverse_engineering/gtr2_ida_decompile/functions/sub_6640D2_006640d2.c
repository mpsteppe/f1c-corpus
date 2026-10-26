int __thiscall sub_6640D2(_DWORD *this, int a2, double *a3)
{
  int v3; // esi
  double *v4; // eax
  double v5; // st7
  int result; // eax
  double X[2]; // [esp+Ch] [ebp-10h] BYREF

  v3 = *(_DWORD *)(*(_DWORD *)(this[2] + 20) + 4 * a2);
  if ( *(char *)v3 >= 0 )
  {
    result = sub_662830((int)this, a2, X);
    if ( result < 0 )
      return result;
    if ( X[0] == X[1] && _finite(X[0]) )
    {
      v4 = a3;
      if ( a3 )
      {
        v5 = X[0];
        goto LABEL_10;
      }
      return 0;
    }
  }
  else if ( _finite(*(double *)(v3 + 32)) )
  {
    v4 = a3;
    if ( a3 )
    {
      v5 = *(double *)(v3 + 32);
LABEL_10:
      *v4 = v5;
      return 0;
    }
    return 0;
  }
  return -2147467259;
}
