_DWORD *__thiscall sub_69D661(void *this, int a2, int a3, int a4, int a5)
{
  int v6; // eax
  _DWORD *v7; // eax
  _DWORD *v8; // ebx
  _DWORD *v9; // eax
  _DWORD *v10; // eax
  int v11; // eax
  _DWORD *v12; // eax
  _DWORD *v13; // eax
  _DWORD *v14; // ebx
  _DWORD *v15; // eax
  _DWORD *v16; // eax
  _DWORD *v17; // eax
  _DWORD *v18; // eax
  _DWORD *v19; // eax
  _DWORD *v20; // eax
  const char *v21; // [esp-Ch] [ebp-30h]
  int v22; // [esp+Ch] [ebp-18h] BYREF
  int v23; // [esp+10h] [ebp-14h]
  const void *v24; // [esp+18h] [ebp-Ch]
  int v25; // [esp+1Ch] [ebp-8h]
  _DWORD *v26; // [esp+20h] [ebp-4h]

  v25 = (int)this;
  if ( !a2 || !a3 )
    return 0;
  v21 = *(const char **)(a2 + 24);
  v24 = (const void *)(a2 + 16);
  if ( sub_6460B4(v21, 2, &v22) < 0 )
  {
    sub_694B97(v25, a2 + 16, 3041, "unsupported compiler target '%s'", *(const char **)(a2 + 24));
    return 0;
  }
  if ( (v23 & 0xFFFF0000) == 0xFFFE0000 )
  {
    v6 = 2 * (a5 != 0) + 26;
  }
  else
  {
    if ( (v23 & 0xFFFF0000) != 0xFFFF0000 )
      goto LABEL_11;
    v6 = 2 * (a5 != 0) + 25;
  }
  a5 = v6;
LABEL_11:
  v7 = (_DWORD *)sub_65B229(80);
  if ( v7 )
  {
    v8 = sub_67F5FE(v7, 0, 27, 0, 0, 1, (const void *)(a2 + 16));
    v26 = v8;
  }
  else
  {
    v26 = 0;
    v8 = 0;
  }
  if ( !v8 )
    return 0;
  v9 = (_DWORD *)sub_65B229(36);
  v10 = v9 ? sub_67F2D4(v9, 3, a5, 1, 1, 512) : 0;
  v8[4] = v10;
  if ( !v10 )
    return 0;
  v11 = sub_67ECC3(a2);
  v8[8] = v11;
  if ( !v11 )
    return 0;
  v12 = sub_69D249((_DWORD *)v25, a3, a4, 1);
  v8[9] = v12;
  if ( !v12 )
    return 0;
  v13 = (_DWORD *)sub_65B229(80);
  v14 = v13 ? sub_67F5FE(v13, 0, 0, 0, 0, 1, v24) : 0;
  if ( !v14 )
    return 0;
  v15 = (_DWORD *)sub_65B229(36);
  v16 = v15 ? sub_67F2D4(v15, 3, a5, 1, 1, 512) : 0;
  v14[4] = v16;
  if ( !v16 )
    return 0;
  v17 = (_DWORD *)sub_65B229(20);
  v18 = v17 ? sub_67ED1B(v17, 0, 0, (int)"Value") : 0;
  v14[8] = v18;
  if ( !v18 )
    return 0;
  v19 = (_DWORD *)sub_65B229(64);
  v20 = v19 ? sub_67F780(v19, 4, (int)v26, v24) : 0;
  *(_DWORD *)(v14[8] + 8) = v20;
  if ( !v20 )
    return 0;
  sub_695BDE((_DWORD *)v25, v14);
  return v14;
}
