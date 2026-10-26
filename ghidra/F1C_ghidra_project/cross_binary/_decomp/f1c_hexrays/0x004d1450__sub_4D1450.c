// f1c  0x004d1450  size=403
int __thiscall sub_4D1450(_DWORD *this)
{
  const char *v2; // ecx
  const char *v3; // eax
  int result; // eax
  int i; // esi
  char *v6; // eax
  int v7; // eax
  const char *v8; // edx
  int v9; // [esp+4h] [ebp-214h] BYREF
  char v10[8]; // [esp+8h] [ebp-210h] BYREF
  char v11[8]; // [esp+10h] [ebp-208h] BYREF
  char v12[64]; // [esp+18h] [ebp-200h] BYREF
  _BYTE v13[64]; // [esp+58h] [ebp-1C0h] BYREF
  _BYTE v14[64]; // [esp+98h] [ebp-180h] BYREF
  _BYTE v15[64]; // [esp+D8h] [ebp-140h] BYREF
  _BYTE v16[256]; // [esp+118h] [ebp-100h] BYREF

  v9 = 0;
  v2 = (const char *)dword_5EC420;
  if ( !dword_5EC420 )
    v2 = byte_5EA438;
  v3 = (const char *)dword_5EC3D8;
  if ( !dword_5EC3D8 )
    v3 = byte_5EA438;
  sub_58969D(v16, 256, "%s%s%s%s", v3, v2, aCommon, aLogomapMas);
  result = sub_53CBC0(&v9, v16);
  if ( !result )
  {
    for ( i = 0; i < 52; ++i )
    {
      v6 = sub_4D1410(this, i);
      if ( !v6 )
        break;
      sub_58815F(v11, "%.4s", v6);
      v7 = sub_568210(aGameName);
      v10[0] = 0;
      if ( v7 )
      {
        v8 = (const char *)sub_567970(v7);
        if ( strlen(v8) >= 3 )
          sub_58815F(v10, "%.4s", v8 + 3);
      }
      sub_58815F(v12, "PBOX%02d", i);
      sub_58815F(v14, "Logo%s%s.bmp", v11, v10);
      sub_58815F(v13, "Logo%s.bmp", v11);
      sub_58815F(v15, "%s.bmp", v12);
      sub_4DC770(v14, v13, v15, 1, 0);
    }
    return sub_53CE40(v9);
  }
  return result;
}
