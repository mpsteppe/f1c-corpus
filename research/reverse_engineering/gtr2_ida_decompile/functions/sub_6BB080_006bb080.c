int __stdcall sub_6BB080(int a1, int a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // ebx
  unsigned int v5; // edi
  const char *v6; // ecx
  int v7; // eax
  const char *v8; // esi
  int v9; // ecx
  int v11; // ecx
  unsigned int v12; // ecx
  unsigned int v13; // ecx
  unsigned int v14; // edx
  unsigned int v15; // ecx
  unsigned int v16; // edx
  _DWORD *v17; // [esp+1Ch] [ebp+10h]

  v3 = *(_DWORD *)(a3 + 20);
  v4 = *(_DWORD **)(v3 + 4 * a1);
  v5 = v4[24];
  v6 = *(const char **)(v5 + 32);
  v17 = *(_DWORD **)(v3 + 4 * a2);
  v8 = WindowName;
  if ( !v6 )
    v6 = WindowName;
  v7 = v17[24];
  if ( *(_DWORD *)(v7 + 32) )
    v8 = *(const char **)(v7 + 32);
  v9 = strcmp(v6, v8);
  if ( v9 > 0 )
    return 1;
  if ( v9 < 0 )
    return -1;
  v11 = strcmp(*(const char **)(*(_DWORD *)(v5 + 20) + 24), *(const char **)(*(_DWORD *)(v17[24] + 20) + 24));
  if ( v11 > 0 )
    return 1;
  if ( v11 < 0 )
    return -1;
  v12 = v17[24];
  if ( v5 > v12 )
    return 1;
  if ( v5 < v12 )
    return -1;
  v13 = v4[29];
  v14 = v17[29];
  if ( v13 < v14 )
    return -1;
  if ( v13 > v14 )
    return 1;
  v15 = v4[4];
  v16 = v17[4];
  if ( v16 > v15 )
    return -1;
  return v16 < v15;
}
