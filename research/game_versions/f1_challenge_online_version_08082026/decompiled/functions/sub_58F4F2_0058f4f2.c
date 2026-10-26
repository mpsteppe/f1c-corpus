int sub_58F4F2()
{
  LCID v0; // edi
  int v1; // esi
  int v2; // esi
  int v3; // esi
  char v5; // al
  _BYTE *v6; // eax
  _BYTE *v7; // eax
  char v8; // al

  v0 = (unsigned __int16)word_8D3F8E;
  if ( dword_8D3F40 )
  {
    v1 = sub_5968F6(1, (unsigned __int16)word_8D3F8E, 0xEu, (int)&dword_8D3F5C);
    v2 = sub_5968F6(1, v0, 0xFu, (int)&dword_8D3F60) | v1;
    v3 = sub_5968F6(1, v0, 0x10u, (int)&dword_8D3F64) | v2;
    sub_58F6C7(dword_8D3F64);
    if ( v3 )
    {
      sub_58AA6F(dword_8D3F5C);
      sub_58AA6F(dword_8D3F60);
      sub_58AA6F(dword_8D3F64);
      dword_8D3F5C = 0;
      dword_8D3F60 = 0;
      dword_8D3F64 = 0;
      return -1;
    }
    if ( *off_5E9AC0 != &unk_5E9A88 )
    {
      sub_58AA6F(*off_5E9AC0);
      sub_58AA6F(off_5E9AC0[1]);
      sub_58AA6F(off_5E9AC0[2]);
    }
    *off_5E9AC0 = dword_8D3F5C;
    off_5E9AC0[1] = dword_8D3F60;
    off_5E9AC0[2] = dword_8D3F64;
    v5 = *(_BYTE *)*off_5E9AC0;
    dword_5E6BDC = 1;
    byte_5E6BD8 = v5;
  }
  else
  {
    sub_58AA6F(dword_8D3F5C);
    sub_58AA6F(dword_8D3F60);
    sub_58AA6F(dword_8D3F64);
    dword_8D3F5C = 0;
    dword_8D3F60 = 0;
    dword_8D3F64 = 0;
    *off_5E9AC0 = (_UNKNOWN *)sub_58A935(2);
    if ( !*off_5E9AC0 )
      return -1;
    sub_58FCA0(*off_5E9AC0);
    off_5E9AC0[1] = (_UNKNOWN *)sub_58A935(2);
    v6 = off_5E9AC0[1];
    if ( !v6 )
      return -1;
    *v6 = 0;
    off_5E9AC0[2] = (_UNKNOWN *)sub_58A935(2);
    v7 = off_5E9AC0[2];
    if ( !v7 )
      return -1;
    *v7 = 0;
    v8 = *(_BYTE *)*off_5E9AC0;
    dword_5E6BDC = 1;
    byte_5E6BD8 = v8;
  }
  return 0;
}
