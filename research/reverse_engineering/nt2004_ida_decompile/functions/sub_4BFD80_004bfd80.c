int sub_4BFD80()
{
  int result; // eax
  const char *v1; // ecx
  const char *v2; // eax
  int i; // esi
  const char *v4; // ecx
  const char *v5; // eax
  char v6; // dl
  char *v7; // edi
  char v8[509]; // [esp+0h] [ebp-600h] BYREF
  __int16 v9; // [esp+1FDh] [ebp-403h]
  char v10; // [esp+1FFh] [ebp-401h]
  char Buffer[509]; // [esp+200h] [ebp-400h] BYREF
  __int16 v12; // [esp+3FDh] [ebp-203h]
  char v13; // [esp+3FFh] [ebp-201h]
  char FileName[509]; // [esp+400h] [ebp-200h] BYREF
  __int16 v15; // [esp+5FDh] [ebp-3h]
  char v16; // [esp+5FFh] [ebp-1h]

  sub_4BD290(dword_766238);
  result = sub_42DBA0();
  if ( (_BYTE)result )
  {
    Buffer[0] = byte_629120;
    memset(&Buffer[1], 0, 0x1FCu);
    v12 = 0;
    v13 = 0;
    v8[0] = byte_629120;
    memset(&v8[1], 0, 0x1FCu);
    v9 = 0;
    v10 = 0;
    FileName[0] = byte_629120;
    memset(&FileName[1], 0, 0x1FCu);
    v15 = 0;
    v16 = 0;
    v1 = (const char *)dword_62A0B0;
    if ( !dword_62A0B0 )
      v1 = &byte_629120;
    v2 = *(const char **)dword_62A068;
    if ( !*(_DWORD *)dword_62A068 )
      v2 = &byte_629120;
    sprintf(Buffer, "%s%sPITS\\", v2, v1);
    sub_591F10(Buffer);
    for ( i = 0; i < 14; ++i )
    {
      v4 = (const char *)dword_62A0B0;
      if ( !dword_62A0B0 )
        v4 = &byte_629120;
      v5 = *(const char **)dword_62A068;
      if ( !*(_DWORD *)dword_62A068 )
        v5 = &byte_629120;
      sprintf(v8, "%s%s%s%s", v5, v4, aPits_0, off_60A018[i]);
      if ( !sub_404F90(&flt_628F60) )
      {
        v6 = byte_60A152;
        v7 = &v8[strlen(v8)];
        *(_WORD *)v7 = word_60A150;
        v7[2] = v6;
      }
      sub_591F10(v8);
      sprintf(FileName, "%s\\PITCREW.SCR", v8);
      sub_4BE8C0(dword_766238, i, FileName);
      sub_592030(v8);
    }
    sub_4BDDB0(dword_766238);
    return sub_592030(Buffer);
  }
  return result;
}
