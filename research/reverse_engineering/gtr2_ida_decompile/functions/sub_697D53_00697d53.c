_DWORD *__thiscall sub_697D53(_DWORD *this, int a2)
{
  _DWORD *v3; // eax
  _DWORD *v4; // edi
  _DWORD *v5; // eax
  _DWORD *v6; // eax
  _DWORD *v7; // eax
  _DWORD *v8; // esi
  int v9; // eax
  _DWORD *v10; // eax
  _DWORD *v11; // eax

  v3 = (_DWORD *)sub_65B229(80);
  if ( v3 )
    v4 = sub_67F5FE(v3, 0, 0, 0, 0, 1, this + 8);
  else
    v4 = 0;
  if ( !v4 )
    return 0;
  v5 = (_DWORD *)sub_65B229(36);
  v6 = v5 ? sub_67F2D4(v5, 3, 20, 1, 1, 512) : 0;
  v4[4] = v6;
  if ( !v6 )
    return 0;
  v7 = (_DWORD *)sub_65B229(64);
  v8 = v7 ? sub_67F780(v7, 4, 0, this + 8) : 0;
  if ( !v8 )
    return 0;
  v4[8] = v8;
  if ( a2 )
  {
    v9 = sub_67ECC3(a2);
    v8[6] = v9;
    if ( !v9 )
      return 0;
  }
  v10 = (_DWORD *)sub_65B229(20);
  v11 = v10 ? sub_67ED1B(v10, v4[8], 0, (int)"Value") : 0;
  if ( !v11 )
    return 0;
  v4[8] = v11;
  sub_695BDE(this, v4);
  return v4;
}
