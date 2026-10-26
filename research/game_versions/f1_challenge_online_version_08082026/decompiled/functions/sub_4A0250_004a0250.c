int sub_4A0250()
{
  char v0; // al
  bool v1; // bl
  _DWORD *v2; // eax
  _DWORD *v3; // esi
  int i; // esi

  sub_554E10(dword_8AFE88);
  while ( ShowCursor(1) <= 0 )
    ;
  if ( dword_7C56A4 == 7 && dword_7D0410 != 6 )
  {
    v0 = sub_4D21D0(&unk_8ACEE0);
    v1 = dword_7D0410 == 5;
    if ( v0 )
    {
      if ( !*(_DWORD *)(dword_7C54E8 + 13000) )
        sub_4BC060(1);
      if ( !v1 )
      {
        v2 = (_DWORD *)(*(int (__thiscall **)(int, int))(*(_DWORD *)dword_7CD8C0 + 28))(dword_7CD8C0, 33);
        v3 = v2;
        if ( v2 )
        {
          sub_46BA20(v2, 0);
          sub_46C030(v3);
        }
      }
      sub_497940((_DWORD *)dword_7CD8C0, (int)aPostRaceMonito, -1);
    }
    else if ( dword_7D0410 != 5 && !dword_7CEC90 )
    {
      sub_4A0DA0(&unk_7CE24D);
      sub_42D210(&dword_7C569C, 1);
      sub_4C8D60(&byte_8AC494);
    }
  }
  sub_4D5840(&dword_8AD238);
  sub_4A0D30(1);
  if ( sub_42BC10() )
  {
    sub_4EFAC0(dword_7C54E8 + 12);
    sub_4C6D90(0);
  }
  sub_4C8D80(&byte_8AC494);
  sub_4C8180(&flt_8AC4B0);
  for ( i = 0; i < dword_5C329C; ++i )
  {
    if ( *(_BYTE *)(dword_7C54F0[i] + 196) )
      sub_4F7010(0);
  }
  sub_40D410((int)&dword_5EA510);
  sub_40D240(&dword_5EA510, *(_DWORD *)(dword_7C54F0[dword_7C54E4] + 18580));
  sub_408450((int)&flt_5EA4E8, 0.0);
  sub_4D8760(-1, 0);
  return 0;
}
