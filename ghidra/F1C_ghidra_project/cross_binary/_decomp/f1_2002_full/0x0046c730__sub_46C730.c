// f1_2002_full  0x0046c730  size=257
int __thiscall sub_46C730(_DWORD *this)
{
  int v2; // edi
  int v3; // eax
  int v4; // eax

  sub_486130();
  v2 = this[17];
  while ( v2 )
  {
    v2 = *(_DWORD *)(v2 + 4);
    sub_42C1F0(1);
  }
  this[17] = 0;
  this[18] = 0;
  this[19] = 0;
  this[20] = 0;
  sub_481060(aCurrent_0, -1);
  sub_481060(aTestDay_0, -1);
  sub_481060(aQuickrace, -1);
  sub_481060(aRace_1, -1);
  sub_481060(aChampionship, -1);
  sub_481060(aMultiplayer, -1);
  sub_481060(aDrivingSchool_0, -1);
  sub_481060(aReplayPlayback, -1);
  v3 = dword_6392F4;
  if ( !dword_6392F4 || dword_6392F4 == 2 || dword_6392F4 == 7 )
  {
    v3 = 3;
    dword_6392F4 = 3;
    if ( dword_6392FC > 3 )
    {
      v3 = dword_6392FC;
LABEL_10:
      dword_6392F4 = v3;
      goto LABEL_11;
    }
    if ( dword_639300 < 3 )
    {
      v3 = dword_639300;
      goto LABEL_10;
    }
  }
LABEL_11:
  v4 = sub_481140(v3);
  sub_55B160(v4);
  this[199] = dword_6392F4;
  return 0;
}
