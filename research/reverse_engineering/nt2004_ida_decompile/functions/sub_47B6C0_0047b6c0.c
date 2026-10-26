bool __stdcall sub_47B6C0(char *String2)
{
  char *v1; // eax
  bool v2; // bl
  const char *i; // eax
  const char *v4; // ecx
  char *v5; // eax
  char *j; // esi
  char Buffer[256]; // [esp+4h] [ebp-300h] BYREF
  char String1[509]; // [esp+104h] [ebp-200h] BYREF
  __int16 v10; // [esp+301h] [ebp-3h]
  char v11; // [esp+303h] [ebp-1h]

  v1 = *(char **)dword_62A0D0;
  v2 = 1;
  if ( !*(_DWORD *)dword_62A0D0 )
    v1 = &byte_629120;
  sub_578A30(aPlr_0, 1, v1, 1);
  sub_578E30(2);
  for ( i = (const char *)sub_578D80(&unk_7D7A0C); i; i = (const char *)sub_578D80(&unk_7D7A0C) )
  {
    v4 = *(const char **)dword_62A0D0;
    if ( !*(_DWORD *)dword_62A0D0 )
      v4 = &byte_629120;
    sprintf(Buffer, "%s%s", v4, i);
    v5 = &Buffer[strlen(Buffer)];
    if ( v5 > Buffer )
    {
      while ( *v5 != 46 )
      {
        if ( --v5 <= Buffer )
          goto LABEL_11;
      }
      *v5 = 0;
    }
LABEL_11:
    for ( j = &Buffer[strlen(Buffer)]; j > Buffer; --j )
    {
      if ( *j == 92 )
        break;
    }
    String1[0] = byte_629120;
    memset(&String1[1], 0, 0x1FCu);
    v10 = 0;
    v11 = 0;
    sub_57B340(512);
    if ( !_strcmpi(String1, String2) )
      v2 = byte_76BB81 && !_strcmpi(aPlayernameneve, String2);
    sub_5789D0(&unk_7D7A0C);
  }
  sub_578960(&unk_7D7A0C);
  return v2;
}
