char __thiscall sub_4ECCB0(_DWORD *this, char *String2)
{
  int *v3; // eax
  int v4; // edi
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // ecx
  int v8; // eax
  int *v9; // eax
  int v11; // eax
  int *v12; // ecx
  int v13; // esi
  int v14; // eax
  int v15; // ecx
  int v16; // eax
  int *v17; // eax
  CHAR *v18; // eax
  CHAR *v19; // eax
  CHAR *v20; // eax
  int v21; // eax

  if ( !this[24] )
    return 0;
  v3 = (int *)this[8];
  this[10] = v3;
  if ( !v3 )
    return 0;
  v4 = *v3;
  if ( !*v3 )
    return 0;
  while ( 1 )
  {
    v5 = *(const char **)v4;
    if ( !*(_DWORD *)v4 )
      v5 = &byte_629120;
    if ( !_strcmpi(v5, String2) )
    {
      v6 = *(const char **)(this[24] + 20);
      if ( !v6 )
        v6 = &byte_629120;
      v7 = *(const char **)(v4 + 28);
      if ( !v7 )
        v7 = &byte_629120;
      if ( !_strcmpi(v7, v6) )
        break;
    }
    v8 = this[10];
    if ( v8 )
      this[10] = *(_DWORD *)(v8 + 4);
    v9 = (int *)this[10];
    if ( v9 )
    {
      v4 = *v9;
      if ( *v9 )
        continue;
    }
    return 0;
  }
  v11 = this[24];
  v12 = *(int **)(v11 + 68);
  *(_DWORD *)(v11 + 76) = v12;
  if ( !v12 )
    return 0;
  v13 = *v12;
  if ( !*v12 )
    return 0;
  while ( *(_DWORD *)(v13 + 8) != 1 )
  {
    v14 = this[24];
    v15 = *(_DWORD *)(v14 + 76);
    v16 = v14 + 68;
    if ( v15 )
      *(_DWORD *)(v16 + 8) = *(_DWORD *)(v15 + 4);
    v17 = *(int **)(v16 + 8);
    if ( !v17 )
      return 0;
    v13 = *v17;
    if ( !*v17 )
      return 0;
  }
  v18 = *(CHAR **)v4;
  if ( !*(_DWORD *)v4 )
    v18 = &byte_629120;
  sub_578600(v18);
  *(_DWORD *)(v13 + 8) = *(_DWORD *)(v4 + 8);
  v19 = *(CHAR **)(v4 + 12);
  if ( !v19 )
    v19 = &byte_629120;
  sub_578600(v19);
  *(_DWORD *)(v13 + 20) = *(_DWORD *)(v4 + 20);
  *(_WORD *)(v13 + 24) = *(_WORD *)(v4 + 24);
  v20 = *(CHAR **)(v4 + 28);
  if ( !v20 )
    v20 = &byte_629120;
  sub_578600(v20);
  v21 = *(_DWORD *)(v13 + 40);
  *(_WORD *)(v13 + 36) = *(_WORD *)(v4 + 36);
  if ( v21 )
    sub_592310(v21);
  *(_DWORD *)(v13 + 40) = *(_DWORD *)(v4 + 40);
  *(_DWORD *)(v4 + 40) = 0;
  return 1;
}
