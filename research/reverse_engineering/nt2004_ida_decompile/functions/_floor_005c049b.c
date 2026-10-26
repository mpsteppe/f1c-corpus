double __cdecl floor(double X)
{
  double result; // st7
  int v2; // ebx
  int v3; // eax
  int v4; // [esp+10h] [ebp-14h]

  result = X;
  v2 = _ctrlfp(dword_625208, 0xFFFF);
  if ( (HIWORD(X) & 0x7FF0) == 0x7FF0 )
  {
    v3 = _sptype(LODWORD(X), HIDWORD(X));
    if ( v3 > 0 )
    {
      if ( v3 <= 2 )
      {
        _ctrlfp(v2, 0xFFFF);
        return X;
      }
      if ( v3 == 3 )
      {
        result = X;
        _handle_qnan1(v4, 11, X, v2);
        return result;
      }
    }
    result = X;
    _except1(
      8u,
      11,
      SLODWORD(X),
      SHIDWORD(X),
      COERCE_UNSIGNED_INT64(X + 1.0),
      HIDWORD(COERCE_UNSIGNED_INT64(X + 1.0)),
      v2);
  }
  else
  {
    _frnd(X);
    _ctrlfp(v2, 0xFFFF);
  }
  return result;
}
