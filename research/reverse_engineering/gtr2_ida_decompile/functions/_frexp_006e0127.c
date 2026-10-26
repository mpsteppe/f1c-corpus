double __cdecl frexp(double X, int *Y)
{
  __int16 v2; // cx
  int v3; // edi
  int v4; // eax
  double result; // st7
  double v6; // st7
  __int16 v7; // cx
  double v8; // [esp+8h] [ebp-14h]
  double Xa; // [esp+24h] [ebp+8h]

  v3 = _ctrlfp(v2);
  if ( (HIWORD(X) & 0x7FF0) == 0x7FF0 )
  {
    *Y = -1;
    v4 = _sptype(SLODWORD(X), SHIDWORD(X));
    if ( v4 > 0 )
    {
      if ( v4 <= 2 )
      {
        v6 = dbl_913460;
LABEL_8:
        v8 = v6;
        result = X;
        _except1(8u, 23, X, v8, v3);
        return result;
      }
      if ( v4 == 3 )
        return _handle_qnan1(23, X, v3);
    }
    v6 = X + 1.0;
    goto LABEL_8;
  }
  Xa = _decomp(X, Y);
  _ctrlfp(v7);
  return Xa;
}
