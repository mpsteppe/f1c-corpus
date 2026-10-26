char __thiscall sub_4C1E80(int this, _DWORD *a2)
{
  int v3; // eax
  int v4; // eax
  int v6; // eax
  LPVOID *v7; // edi
  int v8; // eax
  int v9; // [esp+10h] [ebp-104h] BYREF
  CHAR v10[256]; // [esp+14h] [ebp-100h] BYREF

  if ( *a2 )
  {
    while ( ConditionalDispatchBasedOnFlag(&unk_8AC1E8, 256) )
    {
      v3 = sub_5651B0(&unk_8AC050);
      if ( v3 )
      {
        v4 = v3 - 1;
        if ( !v4 || v4 == 3 )
          return 0;
      }
      else if ( sub_587C20(&unk_8AC1E8, aCareerseason) )
      {
        v6 = OperatorNewNhMallocWrapper(45396);
        if ( v6 )
          v7 = (LPVOID *)AudioSubsystemInitializer(v6);
        else
          v7 = 0;
        if ( CareerSeasonStateFileReader((int)v7, a2) )
        {
          if ( v7 )
          {
            v8 = OperatorNewNhMallocWrapper(12);
            if ( v8 )
            {
              *(_DWORD *)v8 = v7;
              *(_DWORD *)(v8 + 4) = 0;
              *(_BYTE *)(v8 + 8) = 1;
            }
            else
            {
              v8 = 0;
            }
            if ( *(_DWORD *)this )
            {
              *(_DWORD *)(*(_DWORD *)(this + 4) + 4) = v8;
            }
            else
            {
              *(_DWORD *)this = v8;
              *(_DWORD *)(this + 8) = v8;
            }
            *(_DWORD *)(this + 4) = v8;
            ++*(_DWORD *)(this + 12);
          }
        }
        else if ( v7 )
        {
          PitStopMemoryCleanup(v7);
          FreeWrapper_7bcf(v7);
        }
      }
      else if ( sub_587C20(&unk_8AC1E8, aPlayertracksta) )
      {
        PlayerCareerStatsGameOptionsLoader((float *)this, a2);
      }
      else
      {
        sub_565760(aAbortedseasons, this + 32, 0, 0, 0);
        sub_565760(aTotallaps, this + 36, 0, 0, 0);
        sub_565760(aTotalraces, this + 40, 0, 0, 0);
        sub_565760(aTotalraceswith, this + 44, 0, 0, 0);
        sub_565760(aTotalpointssco, this + 48, 0, 0, 0);
        sub_565760(aTotalchampions, this + 52, 0, 0, 0);
        sub_565760(aTotalwins, this + 56, 0, 0, 0);
        sub_565760(aTotalpoles, this + 60, 0, 0, 0);
        sub_565760(aTotallaprecord, this + 64, 0, 0, 0);
        if ( sub_565520(aAvgstartpositi, v10, 0) )
          *(float *)(this + 68) = sub_58850F(v10);
        if ( sub_565520(aAvgfinishposit, v10, 0) )
          *(float *)(this + 72) = sub_58850F(v10);
        if ( sub_565520(aAvgracedistanc, v10, 0) )
          *(float *)(this + 76) = sub_58850F(v10);
        if ( sub_565520(aAvgopponentstr, v10, 0) )
          *(float *)(this + 80) = sub_58850F(v10);
        v9 = 0;
        if ( sub_565760(aMechfailRate, &v9, 0, 0, 0) )
          *(_DWORD *)(this + 84) = v9;
        sub_565760(aRacecondReconn, this + 88, 0, 0, 0);
        sub_565760(aRacecondWalkth, this + 92, 0, 0, 0);
        sub_565760(aRacecondFormat, this + 96, 0, 0, 0);
        sub_565760(aRacecondFlagRu, this + 100, 0, 0, 0);
        if ( sub_565760(aRacecondWeathe, &v9, 0, 0, 0) )
          *(_DWORD *)(this + 104) = v9;
        if ( sub_565760(aRacecondTimesc, &v9, 0, 0, 0) )
          *(_BYTE *)(this + 108) = v9 != 0;
        sub_565760(aGameoptQualify, this + 112, 0, 0, 0);
        sub_565760(aGameoptRaceLap, this + 116, 0, 0, 0);
        sub_565760(aGameoptRaceTim, this + 120, 0, 0, 0);
        sub_565870(aGameoptRaceLen, this + 124, 0, 0, 0, 0, 0, 0, 0);
        sub_565760(aGameoptOpponen, this + 128, 0, 0, 0);
        sub_565760(aGameoptFuelMul, this + 132, 0, 0, 0);
        sub_565760(aGameoptTireMul, this + 136, 0, 0, 0);
        sub_565760(aGameoptSpeedCo, this + 140, 0, 0, 0);
      }
    }
  }
  return 0;
}
