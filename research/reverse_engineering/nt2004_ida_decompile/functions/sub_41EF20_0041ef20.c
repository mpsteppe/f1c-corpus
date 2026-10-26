int __stdcall sub_41EF20(char *Str, _BYTE *a2, _BYTE *a3)
{
  int v3; // ebx
  char *v5; // eax
  char *v6; // eax
  char *v7; // eax
  char *v8; // eax
  char *v9; // ecx
  char v10; // dl
  char v11; // dl
  char *i; // ecx
  unsigned int v13; // ecx
  char v14; // bl
  char *v15; // edx
  char v16; // al
  unsigned int j; // ecx
  int v18; // [esp+Ch] [ebp-4h]

  v3 = 0;
  v18 = 0;
  if ( !Str )
    return -1;
  v5 = strstr(Str, asc_5FD0CC);
  if ( v5 )
    *v5 = 0;
  v6 = strstr(Str, asc_5FB9D8);
  if ( v6 )
    *v6 = 0;
  v7 = strstr(Str, asc_5FD0C8);
  if ( v7 )
    *v7 = 0;
  if ( !strlen(Str) )
    return -1;
  if ( a2 )
    *a2 = 0;
  if ( a3 )
    *a3 = 0;
  v8 = strstr(Str, Delimiter);
  if ( v8 )
  {
    v9 = Str;
    if ( *Str == 34 )
    {
LABEL_19:
      if ( v9 < v8 )
      {
        v11 = v9[1];
        for ( i = v9 + 1; v11 != 34; ++i )
        {
          if ( i == v8 )
            break;
          a2[v3] = v11;
          v11 = i[1];
          ++v3;
        }
        a2[v3] = 0;
      }
    }
    else
    {
      while ( v9 != v8 )
      {
        v10 = *++v9;
        if ( v10 == 34 )
          goto LABEL_19;
      }
    }
    v13 = (unsigned int)v8;
    if ( *v8 != 34 )
    {
      do
      {
        if ( (char *)v13 == v8 + 256 )
          break;
        v14 = *(_BYTE *)++v13;
      }
      while ( v14 != 34 );
    }
    v15 = v8 + 256;
    if ( v13 < (unsigned int)(v8 + 256) )
    {
      v16 = *(_BYTE *)(v13 + 1);
      for ( j = v13 + 1; v16 != 34; ++v18 )
      {
        if ( (char *)j == v15 )
          break;
        a3[v18] = v16;
        v16 = *(_BYTE *)++j;
      }
      a3[v18] = 0;
    }
  }
  return 0;
}
