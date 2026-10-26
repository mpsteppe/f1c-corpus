_DWORD *__thiscall sub_6975BA(_DWORD *this, int a2)
{
  int *v3; // ebx
  _DWORD *v4; // eax
  _DWORD *v5; // esi
  _DWORD *v6; // eax
  _DWORD *v7; // eax
  _DWORD *v8; // eax
  _DWORD *v9; // eax
  _DWORD *v10; // eax
  _DWORD *v12; // [esp+14h] [ebp+8h]

  if ( !a2 )
    return 0;
  v3 = (int *)(a2 + 16);
  v4 = (_DWORD *)sub_65B229(80);
  if ( v4 )
    v5 = sub_67F5FE(v4, 0, 0, 0, 0, 1, v3);
  else
    v5 = 0;
  if ( !v5 )
    return 0;
  v6 = (_DWORD *)sub_65B229(36);
  v7 = v6 ? sub_67F2D4(v6, 3, 14, 1, 1, 512) : 0;
  v5[4] = v7;
  if ( !v7 )
    return 0;
  v12 = (_DWORD *)sub_65B229(64);
  v8 = v12 ? sub_67F7B5(v12, 5, v3[2], strlen((const char *)v3[2]) + 1, v3) : 0;
  v5[8] = v8;
  if ( !v8 )
    return 0;
  v9 = (_DWORD *)sub_65B229(20);
  v10 = v9 ? sub_67ED1B(v9, v5[8], 0, (int)"Value") : 0;
  if ( !v10 )
    return 0;
  v5[8] = v10;
  sub_695BDE(this, v5);
  return v5;
}
