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
      sub_566C30(a2, a3);
      sub_566C30(a2, &word_5C30B4);
    }
    sub_566C30(a2, aAbortedseasons_0);
    sub_566C30(a2, aTotallapsD);
    sub_566C30(a2, aTotalracesD);
    sub_566C30(a2, aTotalraceswith_0);
    sub_566C30(a2, aTotalpointssco_0);
    sub_566C30(a2, aTotalchampions_0);
    sub_566C30(a2, aTotalwinsD);
    sub_566C30(a2, aTotalpolesD);
    sub_566C30(a2, aTotallaprecord_0);
    sub_566C30(a2, aAvgstartpositi_0);
    sub_566C30(a2, aAvgfinishposit_0);
    sub_566C30(a2, aAvgracedistanc_0);
    sub_566C30(a2, aAvgopponentstr_0);
    sub_566C30(a2, aChampionshipSe);
    sub_566C30(a2, aMechfailRateD);
    sub_566C30(a2, aRacecondReconn_0);
    sub_566C30(a2, aRacecondWalkth_0);
    sub_566C30(a2, aRacecondFormat_0);
    sub_566C30(a2, aRacecondFlagRu_0);
    sub_566C30(a2, aRacecondWeathe_0);
    sub_566C30(a2, aRacecondTimesc_0);
    sub_566C30(a2, aGameoptQualify_0);
    sub_566C30(a2, aGameoptRaceLap_0);
    sub_566C30(a2, aGameoptRaceTim_0);
    sub_566C30(a2, aGameoptRaceLen_0);
    sub_566C30(a2, aGameoptOpponen_0);
    sub_566C30(a2, aGameoptFuelMul_0);
    sub_566C30(a2, aGameoptTireMul_0);
    sub_566C30(a2, aGameoptSpeedCo_0);
    v4 = (int *)this[1];
    this[2] = v4;
    if ( v4 )
    {
      for ( i = *v4; i; i = *v7 )
      {
        sub_4C0CC0(i, a2, (int)aCareerseason);
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
        sub_566C30(a2, aS_7);
        sub_566C30(a2, aTracknameS);
        sub_566C30(a2, aTrackfileS);
        sub_566C30(a2, aTotalnumlapsD);
        sub_566C30(a2, aBestlaptimeF);
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
    sub_566C30(a2, &word_5C30B4);
  }
  return 0;
}
