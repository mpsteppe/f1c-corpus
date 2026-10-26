char __thiscall sub_4EC870(int **this, char *String2)
{
  int *v3; // eax
  const char *v4; // ebp
  const char *v5; // eax
  int *v6; // eax
  bool v7; // zf
  int v8; // edi
  const char *v9; // eax
  int *v10; // eax
  int *v11; // eax
  int v13; // esi
  int v14; // ecx
  int v15; // eax
  const char **v16; // eax
  const char *v17; // eax
  int v18; // ecx
  int v19; // eax
  char **v20; // eax
  char *v21; // eax
  int *v22; // edi
  int *v23; // esi
  CHAR *v24; // [esp+10h] [ebp-4h]

  v3 = this[24];
  if ( !v3 )
    return 0;
  v4 = (const char *)v3[7];
  if ( !v4 )
    v4 = &byte_629120;
  v24 = (CHAR *)v3[3];
  if ( !v24 )
    v24 = &byte_629120;
  v5 = (const char *)v3[5];
  if ( !v5 )
    v5 = &byte_629120;
  if ( !_strcmpi(v5, String2) )
    return 0;
  v6 = *this;
  v7 = *this == 0;
  this[2] = *this;
  if ( v7 )
    return 0;
  v8 = *v6;
  if ( !*v6 )
    return 0;
  while ( 1 )
  {
    v9 = *(const char **)v8;
    if ( !*(_DWORD *)v8 )
      v9 = &byte_629120;
    if ( !_strcmpi(v9, String2) )
      break;
    v10 = this[2];
    if ( v10 )
    {
      v11 = (int *)v10[1];
      this[2] = v11;
      if ( v11 )
      {
        v8 = *v11;
        if ( *v11 )
          continue;
      }
    }
    return 0;
  }
  v13 = 0;
  if ( *(int *)(v8 + 20) <= 0 )
    return 0;
  while ( 1 )
  {
    v14 = v13;
    if ( v13 >= 0 && v13 < *(_DWORD *)(v8 + 20) )
    {
      v15 = *(_DWORD *)(v8 + 8);
      if ( v13 > 0 )
      {
        while ( v15 )
        {
          v15 = *(_DWORD *)(v15 + 4);
          if ( --v14 <= 0 )
            goto LABEL_24;
        }
        goto LABEL_29;
      }
LABEL_24:
      if ( v15 )
      {
        v16 = *(const char ***)v15;
        if ( v16 )
        {
          v17 = *v16;
          if ( !v17 )
            v17 = &byte_629120;
          if ( !_strcmpi(v17, v4) )
            break;
        }
      }
    }
LABEL_29:
    if ( ++v13 >= *(_DWORD *)(v8 + 20) )
      return 0;
  }
  v18 = v13;
  if ( v13 >= *(_DWORD *)(v8 + 36) )
    return 0;
  v19 = *(_DWORD *)(v8 + 24);
  if ( v13 <= 0 )
  {
LABEL_35:
    if ( !v19 )
      return 0;
    v20 = *(char ***)v19;
    if ( !v20 )
      return 0;
    v21 = *v20;
    if ( !v21 )
      v21 = &byte_629120;
    v22 = sub_4EB6C0(this, v21);
    if ( !v22 )
      return 0;
    sub_4E9CE0(v22, this[24]);
    sub_578600(v24);
    v23 = this[24];
    if ( v23 )
    {
      sub_4ECA40(v23 + 25);
      sub_4EDBE0(v23 + 21);
      sub_4EDAD0(v23 + 17);
      sub_4EDAD0(v23 + 13);
      sub_4667A0(v23 + 9);
      if ( v23[7] )
        sub_5BE8AE((LPVOID)v23[7]);
      sub_40D5B0((LPVOID *)v23 + 5);
      sub_40D5B0((LPVOID *)v23 + 3);
      sub_40D5B0((LPVOID *)v23 + 1);
      sub_5BE8AE(v23);
    }
    this[24] = v22;
    return 1;
  }
  else
  {
    while ( v19 )
    {
      v19 = *(_DWORD *)(v19 + 4);
      if ( --v18 <= 0 )
        goto LABEL_35;
    }
    return 0;
  }
}
