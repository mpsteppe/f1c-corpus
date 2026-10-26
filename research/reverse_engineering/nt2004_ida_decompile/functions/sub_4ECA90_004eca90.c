char __thiscall sub_4ECA90(int **this, char *String2)
{
  int *v3; // eax
  const char *v4; // esi
  int *v5; // eax
  bool v6; // zf
  int v7; // edi
  const char *v8; // eax
  int *v9; // eax
  int *v10; // eax
  int v12; // esi
  int v13; // ecx
  int v14; // eax
  const char **v15; // eax
  const char *v16; // eax
  int v17; // ecx
  int v18; // eax
  char **v19; // eax
  char *v20; // eax
  int *v21; // edi
  int *v22; // esi
  CHAR *v23; // [esp+10h] [ebp-4h]

  v3 = this[24];
  if ( !v3 )
    return 0;
  v4 = (const char *)v3[5];
  if ( !v4 )
    v4 = &byte_629120;
  v23 = (CHAR *)v3[3];
  if ( !v23 )
    v23 = &byte_629120;
  v5 = *this;
  v6 = *this == 0;
  this[2] = *this;
  if ( v6 )
    return 0;
  v7 = *v5;
  if ( !*v5 )
    return 0;
  while ( 1 )
  {
    v8 = *(const char **)v7;
    if ( !*(_DWORD *)v7 )
      v8 = &byte_629120;
    if ( !_strcmpi(v8, v4) )
      break;
    v9 = this[2];
    if ( v9 )
    {
      v10 = (int *)v9[1];
      this[2] = v10;
      if ( v10 )
      {
        v7 = *v10;
        if ( *v10 )
          continue;
      }
    }
    return 0;
  }
  v12 = 0;
  if ( *(int *)(v7 + 20) <= 0 )
    return 0;
  while ( 1 )
  {
    v13 = v12;
    if ( v12 >= 0 && v12 < *(_DWORD *)(v7 + 20) )
    {
      v14 = *(_DWORD *)(v7 + 8);
      if ( v12 > 0 )
      {
        while ( v14 )
        {
          v14 = *(_DWORD *)(v14 + 4);
          if ( --v13 <= 0 )
            goto LABEL_21;
        }
        goto LABEL_26;
      }
LABEL_21:
      if ( v14 )
      {
        v15 = *(const char ***)v14;
        if ( v15 )
        {
          v16 = *v15;
          if ( !v16 )
            v16 = &byte_629120;
          if ( !_strcmpi(v16, String2) )
            break;
        }
      }
    }
LABEL_26:
    if ( ++v12 >= *(_DWORD *)(v7 + 20) )
      return 0;
  }
  v17 = v12;
  if ( v12 >= *(_DWORD *)(v7 + 36) )
    return 0;
  v18 = *(_DWORD *)(v7 + 24);
  if ( v12 <= 0 )
  {
LABEL_32:
    if ( !v18 )
      return 0;
    v19 = *(char ***)v18;
    if ( !v19 )
      return 0;
    v20 = *v19;
    if ( !v20 )
      v20 = &byte_629120;
    v21 = sub_4EB6C0(this, v20);
    if ( !v21 )
      return 0;
    sub_4E9CE0(v21, this[24]);
    sub_578600(v23);
    v22 = this[24];
    if ( v22 )
    {
      sub_4EACE0(v22 + 25);
      sub_40D5B0((LPVOID *)v22 + 32);
      sub_40D5B0((LPVOID *)v22 + 28);
      sub_40D5B0((LPVOID *)v22 + 25);
      sub_4EDBE0(v22 + 21);
      sub_4EDAD0(v22 + 17);
      sub_4EDAD0(v22 + 13);
      sub_4667A0(v22 + 9);
      sub_40D5B0((LPVOID *)v22 + 7);
      sub_40D5B0((LPVOID *)v22 + 5);
      sub_40D5B0((LPVOID *)v22 + 3);
      sub_40D5B0((LPVOID *)v22 + 1);
      sub_5BE8AE(v22);
    }
    this[24] = v21;
    return 1;
  }
  else
  {
    while ( v18 )
    {
      v18 = *(_DWORD *)(v18 + 4);
      if ( --v17 <= 0 )
        goto LABEL_32;
    }
    return 0;
  }
}
