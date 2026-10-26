int __thiscall sub_436740(int this, char *Destination, int a3)
{
  char *v3; // ebx
  char *v5; // eax
  int v6; // eax
  char *v7; // ecx
  char *v8; // ebp
  int *v9; // eax
  int v10; // ebx
  int v11; // esi
  const char *v12; // eax
  CHAR *v13; // eax
  const char *v14; // eax
  int v15; // eax
  int *v16; // eax
  const char *v17; // eax
  int v19; // [esp+10h] [ebp-8h]
  int v20; // [esp+14h] [ebp-4h]

  v3 = Destination;
  *Destination = 0;
  if ( !*(_BYTE *)(this + 24) )
    sub_435C20(this);
  v5 = dword_7665D8;
  if ( !dword_7665D8 )
    v5 = &byte_629120;
  v19 = sub_4E7790(v5);
  if ( !*(_BYTE *)(this + 24) || *(int *)(this + 40) <= 0 )
    goto LABEL_34;
  v6 = sub_435C00(dword_75CBB0);
  v7 = dword_766594;
  v20 = v6;
  if ( !dword_766594 )
    v7 = &byte_629120;
  v8 = sub_435430(v7);
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
    v12 = *(const char **)v11;
    if ( !*(_DWORD *)v11 )
      v12 = &byte_629120;
    if ( !_strcmpi(v8, v12) )
    {
      v13 = *(CHAR **)(v11 + 8);
      if ( !v13 )
        v13 = &byte_629120;
      if ( !*v13 || !v19 )
        goto LABEL_21;
      v14 = *(const char **)(v11 + 8);
      if ( !v14 )
        v14 = &byte_629120;
      if ( !_strcmpi((const char *)(v19 + 630), v14) )
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
    v3 = Destination;
LABEL_34:
    strncpy(v3, &byte_629120, a3 - 1);
    v3[a3 - 1] = 0;
    return 1;
  }
  v17 = *(const char **)(v10 + 20);
  if ( !v17 )
    v17 = &byte_629120;
  strncpy(Destination, v17, a3 - 1);
  Destination[a3 - 1] = 0;
  return 0;
}
