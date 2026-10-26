int __thiscall sub_4339E0(int this, _BYTE *a2, int a3)
{
  _BYTE *v3; // ebx
  char *v5; // eax
  int v6; // eax
  char *v7; // ecx
  int v8; // ebp
  int *v9; // eax
  int v10; // ebx
  int v11; // esi
  char *v12; // eax
  char *v13; // eax
  char *v14; // eax
  int v15; // eax
  int *v16; // eax
  char *v17; // eax
  int v19; // [esp+10h] [ebp-8h]
  int v20; // [esp+14h] [ebp-4h]

  v3 = a2;
  *a2 = 0;
  if ( !*(_BYTE *)(this + 24) )
    AutoLoadEntryListLoader(this);
  v5 = (char *)dword_7CE64C;
  if ( !dword_7CE64C )
    v5 = &byte_5EA438;
  v19 = ConditionalDispatch_40b0(v5);
  if ( !*(_BYTE *)(this + 24) || *(int *)(this + 40) <= 0 )
    goto LABEL_34;
  v6 = IterationCountMap(dword_7C56A4);
  v7 = (char *)dword_7CE5EC;
  v20 = v6;
  if ( !dword_7CE5EC )
    v7 = &byte_5EA438;
  v8 = SettingsFolderResolver(v7);
  v9 = *(int **)(this + 28);
  v10 = 0;
  *(_DWORD *)(this + 36) = v9;
  if ( !v9 )
    goto LABEL_33;
  v11 = *v9;
  if ( !*v9 )
    goto LABEL_33;
  do
  {
    v12 = *(char **)v11;
    if ( !*(_DWORD *)v11 )
      v12 = &byte_5EA438;
    if ( !sub_588410(v8, v12) )
    {
      v13 = *(char **)(v11 + 8);
      if ( !v13 )
        v13 = &byte_5EA438;
      if ( !*v13 || !v19 )
        goto LABEL_21;
      v14 = *(char **)(v11 + 8);
      if ( !v14 )
        v14 = &byte_5EA438;
      if ( !sub_588410(v19 + 444, v14) )
      {
LABEL_21:
        if ( !v10 )
          v10 = v11;
        if ( *(_DWORD *)(v11 + 16) == v20 && *(_DWORD *)(v10 + 16) != v20 )
          v10 = v11;
      }
    }
    v15 = *(_DWORD *)(this + 36);
    if ( !v15 )
      break;
    v16 = *(int **)(v15 + 4);
    *(_DWORD *)(this + 36) = v16;
    if ( !v16 )
      break;
    v11 = *v16;
  }
  while ( *v16 );
  if ( !v10 )
  {
LABEL_33:
    v3 = a2;
LABEL_34:
    sub_587DD0(v3, &byte_5EA438, a3 - 1);
    v3[a3 - 1] = 0;
    return 1;
  }
  v17 = *(char **)(v10 + 20);
  if ( !v17 )
    v17 = &byte_5EA438;
  sub_587DD0(a2, v17, a3 - 1);
  a2[a3 - 1] = 0;
  return 0;
}

