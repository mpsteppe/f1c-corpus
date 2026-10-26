int sub_4A00A0()
{
  int v0; // edi
  const char *v1; // eax
  int v2; // edx
  int v3; // eax
  int v4; // esi
  _BYTE v6[256]; // [esp+8h] [ebp-100h] BYREF

  v0 = 0;
  while ( ShowCursor(0) >= 0 )
    ;
  if ( dword_7D0410 == 4 && dword_7C56A4 == 7 && dword_7D032C == 1 )
  {
    v1 = (const char *)dword_5EC418;
    if ( !dword_5EC418 )
      v1 = byte_5EA438;
    sub_58815F(v6, "%s%s", v1, aFiashortBik);
    v0 = sub_4F9B70(v6, 1);
  }
  sub_463E00(dword_7CD25C);
  sub_4A0D30(0);
  sub_42D210(&dword_7C569C, 0);
  sub_4F9F70(0);
  sub_453560(&ppvOut);
  sub_40D410((int)&dword_5EA510);
  v2 = dword_7C54F0[dword_7C54E4];
  dword_7C54DC = dword_7C54E4;
  dword_7C54E0 = v2;
  sub_40D100(&dword_5EA510);
  sub_40D090(&dword_5EA510);
  sub_408450((int)&flt_5EA4E8, 0.0);
  sub_495060();
  sub_4950C0();
  sub_45BDF0(&dword_7CD204);
  sub_4B9FD0(&dword_8AB6E4);
  if ( sub_42BC10() )
  {
    sub_434000((char **)&dword_7C73E8);
    sub_4C6D90(0);
    v3 = dword_7C54E8;
    v4 = *(_DWORD *)(dword_7C54E8 + 13024);
    if ( v4 )
    {
      if ( *(_BYTE *)(dword_7C54E8 + 13388) )
        sub_4A4000(*(_DWORD *)(dword_7C54E8 + 13024));
      sub_4A3B50(v4);
      v3 = dword_7C54E8;
    }
    if ( dword_7C56A4 != 7 || dword_7C56A8 != 2 && dword_7C56A8 != 3 && dword_7C56A8 != 4 )
    {
      sub_4EFA40(0);
      v3 = dword_7C54E8;
    }
    sub_4E4910(v3 + 12);
  }
  sub_4D4A80(&dword_8AD238);
  return v0;
}
