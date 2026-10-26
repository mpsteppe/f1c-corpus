int __stdcall sub_4236F0(const char *a1, _BYTE *a2, _BYTE *a3)
{
  int v3; // ebx
  _BYTE *v5; // eax
  _BYTE *v6; // eax
  _BYTE *v7; // eax
  const char *v8; // eax
  const char *v9; // ecx
  char v10; // dl
  char v11; // dl
  const char *i; // ecx
  unsigned int v13; // ecx
  char v14; // bl
  _BYTE *v15; // edx
  char v16; // al
  unsigned int j; // ecx
  int v18; // [esp+Ch] [ebp-4h]

  v3 = 0;
  v18 = 0;
  if ( !a1 )
    return -1;
  v5 = (_BYTE *)sub_587C20(a1, &unk_5C30B8);
  if ( v5 )
    *v5 = 0;
  v6 = (_BYTE *)sub_587C20(a1, &word_5C30B4);
  if ( v6 )
    *v6 = 0;
  v7 = (_BYTE *)sub_587C20(a1, asc_5C30B0);
  if ( v7 )
    *v7 = 0;
  if ( !strlen(a1) )
    return -1;
  if ( a2 )
    *a2 = 0;
  if ( a3 )
    *a3 = 0;
  v8 = (const char *)sub_587C20(a1, asc_5C30AC);
  if ( v8 )
  {
    v9 = a1;
    if ( *a1 == 34 )
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
        if ( (const char *)v13 == v8 + 256 )
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
        if ( (_BYTE *)j == v15 )
          break;
        a3[v18] = v16;
        v16 = *(_BYTE *)++j;
      }
      a3[v18] = 0;
    }
  }
  return 0;
}

