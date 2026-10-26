int __thiscall sub_4326E0(char **this)
{
  char *v2; // ecx
  int v3; // eax
  int v4; // edi
  int v5; // eax
  int v6; // ecx
  char **v7; // esi
  char *v8; // eax
  char *v9; // esi

  SettingsSetupFileRead(this);
  SettingsCopySetupFileCopy((char ***)this);
  Wrapper(this);
  v2 = (char *)dword_7CE5EC;
  if ( !dword_7CE5EC )
    v2 = &byte_5EA438;
  v3 = SettingsFolderResolver(v2);
  StringCopyWithBufferRealloc(v3);
  if ( BinarySearchInStringTable(byte_5EC4C0, &byte_5EA438, byte_5EC4CC) )
  {
    if ( &byte_5EA438 )
      strcpy(byte_5EC4CC, &byte_5EA438);
    else
      byte_5EC4CC[0] = 0;
  }
  StringCopyWithBufferRealloc(byte_5EC4CC);
  v4 = 0;
  while ( 1 )
  {
    v5 = v4++;
    if ( v5 < 0 || v5 >= *((_DWORD *)*this + 11) )
      break;
    v6 = *((_DWORD *)*this + 8);
    if ( v5 > 0 )
    {
      while ( v6 )
      {
        v6 = *(_DWORD *)(v6 + 4);
        if ( --v5 <= 0 )
          goto LABEL_13;
      }
      break;
    }
LABEL_13:
    if ( !v6 )
      break;
    v7 = *(char ***)v6;
    if ( !*(_DWORD *)v6 )
      break;
    v8 = *v7;
    if ( !*v7 )
      v8 = &byte_5EA438;
    if ( !sub_588410(v8, &byte_5EA438) )
    {
      v9 = *v7;
      if ( !v9 )
        v9 = &byte_5EA438;
      PathNormalizerFileEnumeration(v9);
      break;
    }
  }
  Wrapper(this);
  return 0;
}

