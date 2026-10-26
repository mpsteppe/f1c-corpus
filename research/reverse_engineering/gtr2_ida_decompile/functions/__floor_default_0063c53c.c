double __cdecl _floor_default(double a1)
{
  int v1; // ebx
  int v2; // eax
  double result; // st7

  v1 = _ctrlfp(dword_913314, 0xFFFF);
  if ( (HIWORD(a1) & 0x7FF0) == 0x7FF0 )
  {
    v2 = _sptype(LODWORD(a1), HIDWORD(a1));
    if ( v2 <= 0 )
    {
LABEL_7:
      result = a1;
      _except1(
        8u,
        11,
        SLODWORD(a1),
        SHIDWORD(a1),
        COERCE_UNSIGNED_INT64(a1 + 1.0),
        HIDWORD(COERCE_UNSIGNED_INT64(a1 + 1.0)),
        v1);
      return result;
    }
    if ( v2 > 2 )
    {
      if ( v2 == 3 )
      {
        result = a1;
        _handle_qnan1(11, a1, v1);
        return result;
      }
      goto LABEL_7;
    }
  }
  else
  {
    _frnd(a1);
  }
  _ctrlfp(v1, 0xFFFF);
  return a1;
}
