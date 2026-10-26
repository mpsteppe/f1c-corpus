_DWORD *__thiscall sub_695C88(_DWORD *this)
{
  _DWORD *result; // eax
  _DWORD *v3; // eax
  _DWORD *v4; // esi
  _DWORD *v5; // eax
  _DWORD *v6; // eax
  _DWORD *v7; // eax

  if ( !this[6] )
    return 0;
  v3 = (_DWORD *)sub_65B229(36);
  if ( v3 )
    v4 = sub_67F53B(v3);
  else
    v4 = 0;
  if ( !v4 )
    return 0;
  v4[4] = 6;
  v5 = (_DWORD *)sub_65B229(80);
  v6 = v5 ? sub_67F5FE(v5, 0, 0, 0, 0, 1, this + 8) : 0;
  if ( !v6 )
    return 0;
  v4[6] = v6;
  v7 = (_DWORD *)sub_65B229(20);
  result = v7 ? sub_67ED1B(v7, (int)v4, 0, (int)"Stmts") : 0;
  if ( !result )
    return 0;
  return result;
}
