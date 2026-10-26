double __cdecl _ceil_default(double a1)
{
  __int16 v1; // cx
  int v2; // ebx
  int v3; // eax
  double result; // st7
  __int16 v5; // [esp+10h] [ebp-14h]

  v2 = _ctrlfp(v1);
  if ( (HIWORD(a1) & 0x7FF0) == 0x7FF0 )
  {
    v3 = _sptype(SLODWORD(a1), SHIDWORD(a1));
    if ( v3 <= 0 )
    {
LABEL_7:
      result = a1;
      _except1(8u, 12, a1, a1 + 1.0, v2);
      return result;
    }
    if ( v3 > 2 )
    {
      if ( v3 == 3 )
        return _handle_qnan1(12, a1, v2);
      goto LABEL_7;
    }
  }
  else
  {
    _frnd(a1);
  }
  _ctrlfp(v5);
  return a1;
}
