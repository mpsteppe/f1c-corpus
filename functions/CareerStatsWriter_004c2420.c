char __thiscall sub_4C2420(_DWORD *this, _DWORD *a2, int a3)
{
  int *v4; // eax
  int i; // eax
  int v6; // eax
  int *v7; // eax
  _DWORD *v8; // eax
  int v9; // eax
  _DWORD *v10; // eax

  if ( *a2 )
  {
    if ( a3 )
    {
      BufferWriteWithStringLengthCheck(a2, a3);
      BufferWriteWithStringLengthCheck(a2, &word_5C30B4);
    }
    BufferWriteWithStringLengthCheck(a2, aAbortedseasons_0);
    BufferWriteWithStringLengthCheck(a2, aTotallapsD);
    BufferWriteWithStringLengthCheck(a2, aTotalracesD);
    BufferWriteWithStringLengthCheck(a2, aTotalraceswith_0);
    BufferWriteWithStringLengthCheck(a2, aTotalpointssco_0);
    BufferWriteWithStringLengthCheck(a2, aTotalchampions_0);
    BufferWriteWithStringLengthCheck(a2, aTotalwinsD);
    BufferWriteWithStringLengthCheck(a2, aTotalpolesD);
    BufferWriteWithStringLengthCheck(a2, aTotallaprecord_0);
    BufferWriteWithStringLengthCheck(a2, aAvgstartpositi_0);
    BufferWriteWithStringLengthCheck(a2, aAvgfinishposit_0);
    BufferWriteWithStringLengthCheck(a2, aAvgracedistanc_0);
    BufferWriteWithStringLengthCheck(a2, aAvgopponentstr_0);
    BufferWriteWithStringLengthCheck(a2, aChampionshipSe);
    BufferWriteWithStringLengthCheck(a2, aMechfailRateD);
    BufferWriteWithStringLengthCheck(a2, aRacecondReconn_0);
    BufferWriteWithStringLengthCheck(a2, aRacecondWalkth_0);
    BufferWriteWithStringLengthCheck(a2, aRacecondFormat_0);
    BufferWriteWithStringLengthCheck(a2, aRacecondFlagRu_0);
    BufferWriteWithStringLengthCheck(a2, aRacecondWeathe_0);
    BufferWriteWithStringLengthCheck(a2, aRacecondTimesc_0);
    BufferWriteWithStringLengthCheck(a2, aGameoptQualify_0);
    BufferWriteWithStringLengthCheck(a2, aGameoptRaceLap_0);
    BufferWriteWithStringLengthCheck(a2, aGameoptRaceTim_0);
    BufferWriteWithStringLengthCheck(a2, aGameoptRaceLen_0);
    BufferWriteWithStringLengthCheck(a2, aGameoptOpponen_0);
    BufferWriteWithStringLengthCheck(a2, aGameoptFuelMul_0);
    BufferWriteWithStringLengthCheck(a2, aGameoptTireMul_0);
    BufferWriteWithStringLengthCheck(a2, aGameoptSpeedCo_0);
    v4 = (int *)this[1];
    this[2] = v4;
    if ( v4 )
    {
      for ( i = *v4; i; i = *v7 )
      {
        PlayerOpponentStateWriter(i, a2, (int)aCareerseason);
        v6 = this[2];
        if ( !v6 )
          break;
        v7 = *(int **)(v6 + 4);
        this[2] = v7;
        if ( !v7 )
          break;
      }
    }
    v8 = (_DWORD *)this[4];
    this[6] = v8;
    if ( v8 && *v8 )
    {
      do
      {
        BufferWriteWithStringLengthCheck(a2, aS_7);
        BufferWriteWithStringLengthCheck(a2, aTracknameS);
        BufferWriteWithStringLengthCheck(a2, aTrackfileS);
        BufferWriteWithStringLengthCheck(a2, aTotalnumlapsD);
        BufferWriteWithStringLengthCheck(a2, aBestlaptimeF);
        v9 = this[6];
        if ( !v9 )
          break;
        v10 = *(_DWORD **)(v9 + 4);
        this[6] = v10;
        if ( !v10 )
          break;
      }
      while ( *v10 );
    }
    BufferWriteWithStringLengthCheck(a2, &word_5C30B4);
  }
  return 0;
}
