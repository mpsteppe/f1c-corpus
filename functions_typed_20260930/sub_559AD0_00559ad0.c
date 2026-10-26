int __thiscall sub_559AD0(const char *this)
{
  const char *v1; // ebp
  const char *v2; // ebx
  char v3; // al
  char *v4; // eax
  char v5; // cl
  int i; // ecx
  char v7; // al
  char *v8; // eax
  int v9; // edx
  char v10; // cl
  unsigned int v11; // kr10_4
  int v12; // esi
  char v13; // al
  char v15; // al
  _BYTE *v16; // eax
  signed int v17; // esi
  char *k; // ebp
  unsigned __int8 j; // al
  char v20; // al
  char v21; // al
  char v22; // al
  char v23; // al
  int v24; // edx
  const char *v25; // esi
  char *v26; // eax
  int v27; // ebx
  char v28; // cl
  const char *v29; // [esp+10h] [ebp-184h]
  _BYTE v30[384]; // [esp+14h] [ebp-180h] BYREF

  v1 = this;
  v2 = this + 12;
  this[strlen(this + 12) + 11] = 0;
  v3 = v1[strlen(v1 + 12) + 11];
  v29 = v1;
  if ( v3 == 13 )
    v1[strlen(v1 + 12) + 11] = 0;
  v4 = (char *)(v1 + 12);
  do
  {
    v5 = *v4;
    v4[v30 - v2] = *v4;
    ++v4;
  }
  while ( v5 );
  for ( i = 0; ; ++i )
  {
    v7 = v30[i];
    if ( v7 != 32 && v7 != 9 )
      break;
  }
  v8 = &v30[i];
  v9 = v2 - &v30[i];
  do
  {
    v10 = *v8;
    v8[v9] = *v8;
    ++v8;
  }
  while ( v10 );
  v11 = strlen(v1 + 12) + 1;
  v12 = v11 - 2;
  if ( v1[v11 + 10] == 32 )
  {
    do
    {
      if ( v12 <= 0 )
        break;
      v13 = v2[--v12];
    }
    while ( v13 == 32 );
  }
  v1[v12 + 13] = 0;
  if ( !sub_588640(v1 + 12, &unk_5C30B8, 2) )
    return 2;
  if ( !strlen(v1 + 12) )
    return 2;
  v15 = v1[v12 + 12];
  if ( v15 == 32 )
    return 1;
  if ( v15 == 125 )
    return 1;
  v16 = (_BYTE *)sub_587C20(v1 + 12, &unk_5C30B8);
  *((_DWORD *)v1 + 195) = v16;
  if ( v16 )
    *v16 = 0;
  v17 = 0;
  if ( (int)strlen(v1 + 12) > 0 )
  {
    k = (char *)(v1 + 12);
    do
    {
      for ( j = *k; j != 61; k = (char *)&v2[v17] )
      {
        if ( !j )
          break;
        ++v17;
        *k = sub_589A35(j);
        j = v2[v17];
      }
      v20 = v2[++v17];
      if ( v20 == 34 )
      {
        v21 = v2[++v17];
        if ( v21 != 34 )
        {
          do
            v22 = v2[++v17];
          while ( v22 != 34 );
        }
      }
      v23 = v2[v17];
      for ( k = (char *)&v2[v17]; v23 != 32; k = (char *)&v2[v17] )
      {
        if ( !v23 )
          break;
        v23 = v2[++v17];
      }
    }
    while ( v17 < (int)strlen(v2) );
    v1 = v29;
  }
  v24 = 0;
  if ( (int)strlen(v2) > 0 )
  {
    v25 = v2;
    v29 = (const char *)(-12 - (_DWORD)v1);
    do
    {
      if ( *v25 != 32 || v30[v24 - 1] != 44 )
        v30[v24++] = *v25;
      ++v25;
    }
    while ( (int)&v29[(int)v25] < (int)strlen(v2) );
  }
  v30[v24] = 0;
  v26 = v30;
  v27 = v2 - v30;
  do
  {
    v28 = *v26;
    v26[v27] = *v26;
    ++v26;
  }
  while ( v28 );
  return 0;
}

