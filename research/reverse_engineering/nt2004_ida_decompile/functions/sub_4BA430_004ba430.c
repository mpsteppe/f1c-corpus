char sub_4BA430()
{
  char result; // al
  const char *v1; // eax
  _BYTE v2[4]; // [esp+0h] [ebp-118h] BYREF
  float v3; // [esp+4h] [ebp-114h]
  char v4[12]; // [esp+Ch] [ebp-10Ch] BYREF
  char Buffer[253]; // [esp+18h] [ebp-100h] BYREF
  __int16 v6; // [esp+115h] [ebp-3h]
  char v7; // [esp+117h] [ebp-1h]

  result = 0;
  if ( dword_766120 )
  {
    if ( dword_766120 == 1 )
    {
      sub_5065C0(&unk_7660D0);
      sub_4F8EF0(dword_75AACC, v2, v4);
      v3 = v3 + 70.0;
      sub_5065F0(v2, v4);
      if ( dword_75CBB0 == 7 )
      {
        Buffer[0] = byte_629120;
        memset(&Buffer[1], 0, 0xFCu);
        v6 = 0;
        v7 = 0;
        sub_4E8E50(Buffer, 256, aJetFlyover, 0);
        if ( _strcmpi(Buffer, aNo) )
        {
          sub_506540(&unk_7660D0);
          sub_4F0220(8, dword_76782C);
        }
        v1 = *(const char **)dword_62A070;
        if ( !*(_DWORD *)dword_62A070 )
          v1 = &byte_629120;
        sprintf(Buffer, "%s%s%s", v1, aAmbient, aPreraceMp3);
        sub_4F0320(Buffer, dword_76782C);
      }
      dword_766120 = 2;
      return 1;
    }
  }
  else
  {
    dword_766120 = 1;
  }
  return result;
}
