int __thiscall sub_5DECD0(int this)
{
  const char *v2; // ebp
  int i; // ecx
  char v4; // al
  char *v5; // eax
  int v6; // edx
  char v7; // cl
  char *v8; // eax
  signed int v9; // esi
  char v10; // al
  char v12; // al
  signed int v13; // esi
  char *j; // edi
  char v15; // al
  char v16; // al
  char v17; // al
  char v18; // al
  int v19; // edi
  char *v20; // edx
  char *v21; // eax
  int v22; // ebp
  char v23; // cl
  char v26[1024]; // [esp+14h] [ebp-400h] BYREF

  v2 = (const char *)(this + 12);
  *(_BYTE *)(strlen((const char *)(this + 12)) + this + 11) = 0;
  if ( *(_BYTE *)(strlen(v2) + this + 11) == 13 )
    *(_BYTE *)(strlen(v2) + this + 11) = 0;
  strcpy(v26, v2);
  for ( i = 0; ; ++i )
  {
    v4 = v26[i];
    if ( v4 != 32 && v4 != 9 )
      break;
  }
  v5 = &v26[i];
  v6 = v2 - &v26[i];
  do
  {
    v7 = *v5;
    v5[v6] = *v5;
    ++v5;
  }
  while ( v7 );
  v8 = strstr(v2, "//");
  *(_DWORD *)(this + 2060) = v8;
  if ( v8 )
    *v8 = 0;
  v9 = strlen(v2) - 1;
  if ( *(_BYTE *)(v9 + this + 12) == 32 )
  {
    do
    {
      if ( v9 <= 0 )
        break;
      v10 = v2[--v9];
    }
    while ( v10 == 32 );
  }
  *(_BYTE *)(v9 + this + 13) = 0;
  if ( !strncmp(v2, "//", 2u) )
    return 2;
  if ( !strlen(v2) )
    return 2;
  v12 = *(_BYTE *)(v9 + this + 12);
  if ( v12 == 32 || v12 == 125 )
    return 1;
  v13 = 0;
  if ( (int)strlen(v2) > 0 )
  {
    j = (char *)v2;
    do
    {
      if ( *j != 61 )
      {
        do
        {
          if ( !*j )
            break;
          ++v13;
          *j = sub_633CD6((unsigned __int8)*j);
          j = (char *)&v2[v13];
        }
        while ( v2[v13] != 61 );
      }
      v15 = v2[++v13];
      if ( v15 == 34 )
      {
        v16 = v2[++v13];
        if ( v16 != 34 )
        {
          do
            v17 = v2[++v13];
          while ( v17 != 34 );
        }
      }
      v18 = v2[v13];
      for ( j = (char *)&v2[v13]; v18 != 32; j = (char *)&v2[v13] )
      {
        if ( !v18 )
          break;
        v18 = v2[++v13];
      }
    }
    while ( v13 < (int)strlen(v2) );
  }
  v19 = 0;
  if ( (int)strlen(v2) > 0 )
  {
    v20 = (char *)v2;
    do
    {
      if ( *v20 != 32 || v26[v19 - 1] != 44 )
        v26[v19++] = *v20;
      ++v20;
    }
    while ( (int)&v20[-12 - this] < (int)strlen(v2) );
  }
  v21 = v26;
  v26[v19] = 0;
  v22 = v2 - v26;
  do
  {
    v23 = *v21;
    v21[v22] = *v21;
    ++v21;
  }
  while ( v23 );
  return 0;
}
