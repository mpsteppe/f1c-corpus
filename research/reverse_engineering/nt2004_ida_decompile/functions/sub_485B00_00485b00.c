int __thiscall sub_485B00(_DWORD *this)
{
  int v2; // edi
  LPVOID **v3; // ecx
  int v4; // eax
  int v5; // eax

  sub_4A2340();
  v2 = this[13];
  while ( v2 )
  {
    v3 = (LPVOID **)v2;
    v2 = *(_DWORD *)(v2 + 4);
    sub_414480(v3, 1);
  }
  this[13] = 0;
  this[14] = 0;
  this[15] = 0;
  this[16] = 0;
  sub_49D5B0(aCurrent_0, -1);
  sub_49D5B0(aTesting_0, -1);
  sub_49D5B0(aQuickrace, -1);
  sub_49D5B0(aRace_2, -1);
  sub_49D5B0(aCareer_1, -1);
  sub_49D5B0(aMultiplayer, -1);
  sub_49D5B0(aDrivingSchool_0, -1);
  sub_49D5B0(aReplayPlayback, -1);
  v4 = *(_DWORD *)dword_7689CC;
  if ( !*(_DWORD *)dword_7689CC || *(_DWORD *)dword_7689CC == 2 || *(_DWORD *)dword_7689CC == 7 )
  {
    v4 = 3;
    *(_DWORD *)dword_7689CC = 3;
    if ( dword_7689D4 > 3 )
    {
      v4 = dword_7689D4;
LABEL_10:
      *(_DWORD *)dword_7689CC = v4;
      goto LABEL_11;
    }
    if ( dword_7689D8 < 3 )
    {
      v4 = dword_7689D8;
      goto LABEL_10;
    }
  }
LABEL_11:
  v5 = sub_49D690(v4);
  sub_578600(v5);
  this[211] = *(_DWORD *)dword_7689CC;
  return 0;
}
