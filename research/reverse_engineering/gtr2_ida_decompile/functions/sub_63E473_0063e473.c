double __cdecl sub_63E473(double a1, int a2)
{
  int v2; // esi
  int v3; // edi
  int v4; // eax
  double result; // st7
  int v6; // eax
  double v7; // st7
  double Number; // [esp+8h] [ebp-28h]
  double Numbera; // [esp+8h] [ebp-28h]
  double v10; // [esp+10h] [ebp-20h]
  double v11; // [esp+10h] [ebp-20h]
  int v12; // [esp+18h] [ebp-18h]
  int v13; // [esp+18h] [ebp-18h]
  int v14; // [esp+2Ch] [ebp-4h] BYREF

  v2 = dword_16C9AE8;
  v3 = _ctrlfp(4927, dword_16C9AE8);
  if ( (HIWORD(a1) & 0x7FF0) == 0x7FF0 )
  {
    v4 = _sptype(LODWORD(a1), HIDWORD(a1));
    if ( v4 <= 0 )
    {
LABEL_6:
      result = a1;
      _except2(
        8u,
        25,
        SLODWORD(a1),
        SHIDWORD(a1),
        (double)a2,
        COERCE_UNSIGNED_INT64(a1 + 1.0),
        HIDWORD(COERCE_UNSIGNED_INT64(a1 + 1.0)),
        v3);
      return result;
    }
    if ( v4 > 2 )
    {
      if ( v4 == 3 )
      {
        result = a1;
        _handle_qnan2(25, a1, (double)a2, v3);
        return result;
      }
      goto LABEL_6;
    }
    goto LABEL_8;
  }
  if ( a1 == 0.0 )
  {
LABEL_8:
    _ctrlfp(v3, v2);
    return a1;
  }
  _decomp(a1, (int)&v14);
  v6 = v14 + a2;
  result = a1;
  if ( v14 + a2 > 2560 )
  {
    v12 = v3;
    v10 = _copysign(dbl_913458, a1);
    Number = (double)a2;
LABEL_11:
    result = a1;
    _except2(0x11u, 25, SLODWORD(a1), SHIDWORD(a1), Number, SLODWORD(v10), SHIDWORD(v10), v12);
    return result;
  }
  if ( v6 > 1024 )
  {
    _set_exp(a1, v6 - 1536);
    v12 = v3;
    v10 = a1;
    Number = (double)a2;
    goto LABEL_11;
  }
  if ( v6 < -2557 )
  {
    v13 = v3;
    v11 = a1 * 0.0;
    v7 = (double)a2;
LABEL_18:
    Numbera = v7;
    result = a1;
    _except2(0x12u, 25, SLODWORD(a1), SHIDWORD(a1), Numbera, SLODWORD(v11), SHIDWORD(v11), v13);
    return result;
  }
  if ( v6 < -1021 )
  {
    _set_exp(a1, v6 + 1536);
    v13 = v3;
    v11 = a1;
    v7 = (double)a2;
    goto LABEL_18;
  }
  _set_exp(a1, v6);
  _ctrlfp(v3, v2);
  return result;
}
