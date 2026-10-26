int sub_4BA330()
{
  int result; // eax
  const char *v1; // ecx
  const char *v2; // eax
  char String1[125]; // [esp+4h] [ebp-280h] BYREF
  __int16 v4; // [esp+81h] [ebp-203h]
  char v5; // [esp+83h] [ebp-201h]
  char Buffer[509]; // [esp+84h] [ebp-200h] BYREF
  __int16 v7; // [esp+281h] [ebp-3h]
  char v8; // [esp+283h] [ebp-1h]

  Buffer[0] = byte_629120;
  memset(&Buffer[1], 0, 0x1FCu);
  v7 = 0;
  v8 = 0;
  String1[0] = byte_629120;
  memset(&String1[1], 0, 0x7Cu);
  v4 = 0;
  v5 = 0;
  sub_4E8E50(String1, 128, aJetFlyover, 0);
  result = _strcmpi(String1, aNo);
  if ( result )
  {
    v1 = (const char *)dword_62A0B0;
    if ( !dword_62A0B0 )
      v1 = &byte_629120;
    v2 = *(const char **)dword_62A068;
    if ( !*(_DWORD *)dword_62A068 )
      v2 = &byte_629120;
    sprintf(Buffer, "%s%s%s", v2, v1, aCommonJetsMas);
    result = sub_5061D0(&unk_7660D0, aJetflyover, aJetMts, aJetAnm, 0, Buffer);
    dword_766120 = 0;
  }
  return result;
}
