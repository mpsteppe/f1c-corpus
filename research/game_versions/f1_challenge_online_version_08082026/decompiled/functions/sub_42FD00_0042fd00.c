int __thiscall sub_42FD00(char *this, int a2, char a3)
{
  int i; // esi
  char *v6; // eax
  _DWORD *v7; // eax
  int v8; // edx
  int v9; // ecx
  int v10; // esi
  char *v11; // edi
  int j; // edi
  _BYTE v13[28]; // [esp+14h] [ebp-A0h] BYREF
  char v14[132]; // [esp+30h] [ebp-84h] BYREF

  if ( !a3 && !*this )
    return 0;
  sub_5668B0(v13);
  if ( (unsigned __int8)sub_566940(a2, 0, 0, 1) == 1 )
  {
    sub_566C30(v13, aGeneral_0);
    for ( i = 0; ; i += 128 )
    {
      v6 = (char *)*((_DWORD *)this + 26);
      if ( !v6 )
        v6 = &byte_5EA438;
      sub_587DD0(v14, &v6[i], 128);
      v14[128] = 0;
      sub_566C30(v13, aNotesS);
      if ( strlen(v14) < 0x80 )
        break;
    }
    sub_566C30(v13, aSymmetricD);
    sub_566C30(v13, aCgrightsetting_0);
    sub_566C30(v13, aCgrearsettingD);
    sub_566C30(v13, aWedgesettingD);
    sub_566C30(v13, aTirecompoundse_0);
    sub_566C30(v13, aFuelsettingD);
    sub_566C30(v13, aNumpitstopsset_0);
    sub_566C30(v13, aPitstop1settin_0);
    sub_566C30(v13, aPitstop2settin_0);
    sub_566C30(v13, aPitstop3settin_0);
    sub_566C30(v13, &word_5C30B4);
    sub_566C30(v13, aLeftfender_0);
    sub_566C30(v13, aFenderflareset_0);
    sub_566C30(v13, &word_5C30B4);
    sub_566C30(v13, aRightfender_0);
    sub_566C30(v13, aFenderflareset_0);
    sub_566C30(v13, &word_5C30B4);
    sub_566C30(v13, aFrontwing_0);
    sub_566C30(v13, aFwsettingD);
    sub_566C30(v13, &word_5C30B4);
    sub_566C30(v13, aRearwing_0);
    sub_566C30(v13, aRwsettingD);
    sub_566C30(v13, &word_5C30B4);
    sub_566C30(v13, aBodyaero_0);
    sub_566C30(v13, aRadiatorsettin_0);
    sub_566C30(v13, aBrakeductsetti_0);
    sub_566C30(v13, &word_5C30B4);
    sub_566C30(v13, aSuspension_2);
    sub_566C30(v13, aFrontantisways_0);
    sub_566C30(v13, aRearantiswayse_0);
    sub_566C30(v13, aFronttoeinsett_0);
    sub_566C30(v13, aReartoeinsetti_0);
    sub_566C30(v13, aLeftcastersett_0);
    sub_566C30(v13, aRightcasterset_0);
    sub_566C30(v13, aLefttrackbarse_0);
    sub_566C30(v13, aRighttrackbars_0);
    sub_566C30(v13, aFront3rdpacker_1);
    sub_566C30(v13, aFront3rdspring_1);
    sub_566C30(v13, aFront3rdslowbu_1);
    sub_566C30(v13, aFront3rdfastbu_1);
    sub_566C30(v13, aFront3rdslowre_1);
    sub_566C30(v13, aFront3rdfastre_1);
    sub_566C30(v13, aRear3rdpackers_0);
    sub_566C30(v13, aRear3rdsprings_0);
    sub_566C30(v13, aRear3rdslowbum_1);
    sub_566C30(v13, aRear3rdfastbum_1);
    sub_566C30(v13, aRear3rdslowreb_1);
    sub_566C30(v13, aRear3rdfastreb_1);
    sub_566C30(v13, &word_5C30B4);
    sub_566C30(v13, aControls_1);
    sub_566C30(v13, aSteerlocksetti_0);
    sub_566C30(v13, aRearbrakesetti_0);
    sub_566C30(v13, aBrakepressures_0);
    sub_566C30(v13, aHandbrakepress_1);
    sub_566C30(v13, &word_5C30B4);
    sub_566C30(v13, aEngine_1);
    sub_566C30(v13, aRevlimitsettin_0);
    sub_566C30(v13, aEnginemapsetti_0);
    sub_566C30(v13, aEnginebrakemap);
    sub_566C30(v13, &word_5C30B4);
    v7 = this + 5892;
    v8 = 6;
    do
    {
      v9 = *(v7 - 16);
      if ( *v7 < v9 )
        *v7 = v9;
      v7 += 16;
      --v8;
    }
    while ( v8 );
    sub_566C30(v13, aDriveline_0);
    sub_566C30(v13, aFinaldrivesett);
    sub_566C30(v13, aReversesetting);
    v10 = 44;
    v11 = this + 5828;
    do
    {
      if ( v11[8] )
        sub_566C30(v13, aGearDsettingD);
      ++v10;
      v11 += 64;
    }
    while ( v10 <= 50 );
    sub_566C30(v13, aDiffpumpsettin);
    sub_566C30(v13, aDiffpowersetti);
    sub_566C30(v13, aDiffcoastsetti);
    sub_566C30(v13, aDiffpreloadset);
    sub_566C30(v13, &word_5C30B4);
    for ( j = 0; j < 4; ++j )
    {
      switch ( j )
      {
        case 0:
          sub_566C30(v13, aFrontleft_0);
          break;
        case 1:
          sub_566C30(v13, aFrontright_0);
          break;
        case 2:
          sub_566C30(v13, aRearleft_0);
          break;
        case 3:
          sub_566C30(v13, aRearright_0);
          break;
        default:
          break;
      }
      sub_566C30(v13, aCambersettingD);
      sub_566C30(v13, aPressuresettin_0);
      sub_566C30(v13, aPackersettingD);
      sub_566C30(v13, aSpringsettingD);
      sub_566C30(v13, aRideheightsett_0);
      sub_566C30(v13, aSlowbumpsettin_0);
      sub_566C30(v13, aFastbumpsettin_0);
      sub_566C30(v13, aSlowreboundset_0);
      sub_566C30(v13, aFastreboundset_0);
      sub_566C30(v13, aBrakediscsetti_0);
      sub_566C30(v13, aBrakepadsettin_0);
      sub_566C30(v13, &word_5C30B4);
    }
    sub_566C30(v13, aBasic_0);
    sub_566C30(v13, aDownforceF);
    sub_566C30(v13, aBalanceF);
    sub_566C30(v13, aRideF);
    sub_566C30(v13, aGearingF);
    sub_566C30(v13, aCustomD);
    sub_566C30(v13, &word_5C30B4);
    sub_566B90(v13);
    *this = 0;
    sub_5668D0(v13);
    return 0;
  }
  if ( (unsigned __int8)sub_4D7A50(1, aDDevF119992002_18, 1380) )
    sub_4D7AA0(&unk_8AD25C, aFailedToOpenSF);
  sub_5668D0(v13);
  return -1;
}
