_DWORD *__thiscall sub_695F7A(_DWORD **this, _DWORD *a2, _DWORD *a3)
{
  _DWORD *v4; // eax
  const char *v5; // ebx
  unsigned int v6; // kr00_4
  unsigned int v7; // kr04_4
  int v8; // edi
  int v9; // eax
  int v10; // esi
  _DWORD *result; // eax
  char v12[16]; // [esp+Ch] [ebp-14h] BYREF
  _DWORD **v13; // [esp+1Ch] [ebp-4h]
  _DWORD *v14; // [esp+28h] [ebp+8h]
  int v15; // [esp+2Ch] [ebp+Ch]

  v13 = this;
  if ( !a2 || a2[1] != 3 || a2[4] != 2 || !a3 || a3[1] != 3 || a3[4] != 9 )
    return 0;
  v4 = (_DWORD *)sub_65B229(48);
  v14 = v4 ? sub_67EF22(v4, a3 + 4) : 0;
  if ( !v14 )
    return 0;
  v5 = (const char *)a3[6];
  v15 = a2[6];
  sub_632041((int)v12, 16, "%u", v15);
  v12[15] = 0;
  v6 = strlen(v12);
  v7 = strlen(v5);
  v8 = v7 + v6 + 1;
  v9 = sub_67EB7E(v13[1], v8, 1u);
  v10 = v9;
  if ( !v9 )
    return 0;
  sub_632041(v9, v8, "%u%s", v15, v5);
  result = v14;
  *(_BYTE *)(v10 + v7 + v6) = 0;
  v14[6] = v10;
  return result;
}
