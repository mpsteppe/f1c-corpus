_DWORD *__thiscall sub_696069(_DWORD **this, _DWORD *a2, _DWORD *a3)
{
  _DWORD *v4; // eax
  const char *v5; // ebx
  int v6; // edi
  int v7; // eax
  int v8; // esi
  _DWORD *result; // eax
  _DWORD *v11; // [esp+18h] [ebp+8h]
  const char *v12; // [esp+1Ch] [ebp+Ch]

  if ( !a2 || a2[1] != 3 || a2[4] != 10 || !a3 || a3[1] != 3 || a3[4] != 10 )
    return 0;
  v4 = (_DWORD *)sub_65B229(48);
  v11 = v4 ? sub_67EF22(v4, a2 + 4) : 0;
  if ( !v11 )
    return 0;
  v5 = (const char *)a3[6];
  v12 = (const char *)a2[6];
  v6 = strlen(v5) + strlen(v12) + 1;
  v7 = sub_67EB7E(this[1], v6, 1u);
  v8 = v7;
  if ( !v7 )
    return 0;
  sub_632041(v7, v6, "%s%s", v12, v5);
  result = v11;
  *(_BYTE *)(v8 + v6 - 1) = 0;
  v11[6] = v8;
  return result;
}
