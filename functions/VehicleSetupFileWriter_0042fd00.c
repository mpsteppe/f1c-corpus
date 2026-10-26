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
  ZeroInitSmallStruct(v13);
  if ( (unsigned __int8)sub_566940(a2, 0, 0, 1) == 1 )
  {
    BufferWriteWithStringLengthCheck(v13, aGeneral_0);
    for ( i = 0; ; i += 128 )
    {
      v6 = (char *)*((_DWORD *)this + 26);
      if ( !v6 )
        v6 = &byte_5EA438;
      sub_587DD0(v14, &v6[i], 128);
      v14[128] = 0;
      BufferWriteWithStringLengthCheck(v13, aNotesS);
      if ( strlen(v14) < 0x80 )
        break;
    }
    BufferWriteWithStringLengthCheck(v13, aSymmetricD);
    BufferWriteWithStringLengthCheck(v13, aCgrightsetting_0);
    BufferWriteWithStringLengthCheck(v13, aCgrearsettingD);
    BufferWriteWithStringLengthCheck(v13, aWedgesettingD);
    BufferWriteWithStringLengthCheck(v13, aTirecompoundse_0);
    BufferWriteWithStringLengthCheck(v13, aFuelsettingD);
    BufferWriteWithStringLengthCheck(v13, aNumpitstopsset_0);
    BufferWriteWithStringLengthCheck(v13, aPitstop1settin_0);
    BufferWriteWithStringLengthCheck(v13, aPitstop2settin_0);
    BufferWriteWithStringLengthCheck(v13, aPitstop3settin_0);
    BufferWriteWithStringLengthCheck(v13, &word_5C30B4);
    BufferWriteWithStringLengthCheck(v13, aLeftfender_0);
    BufferWriteWithStringLengthCheck(v13, aFenderflareset_0);
    BufferWriteWithStringLengthCheck(v13, &word_5C30B4);
    BufferWriteWithStringLengthCheck(v13, aRightfender_0);
    BufferWriteWithStringLengthCheck(v13, aFenderflareset_0);
    BufferWriteWithStringLengthCheck(v13, &word_5C30B4);
    BufferWriteWithStringLengthCheck(v13, aFrontwing_0);
    BufferWriteWithStringLengthCheck(v13, aFwsettingD);
    BufferWriteWithStringLengthCheck(v13, &word_5C30B4);
    BufferWriteWithStringLengthCheck(v13, aRearwing_0);
    BufferWriteWithStringLengthCheck(v13, aRwsettingD);
    BufferWriteWithStringLengthCheck(v13, &word_5C30B4);
    BufferWriteWithStringLengthCheck(v13, aBodyaero_0);
    BufferWriteWithStringLengthCheck(v13, aRadiatorsettin_0);
    BufferWriteWithStringLengthCheck(v13, aBrakeductsetti_0);
    BufferWriteWithStringLengthCheck(v13, &word_5C30B4);
    BufferWriteWithStringLengthCheck(v13, aSuspension_2);
    BufferWriteWithStringLengthCheck(v13, aFrontantisways_0);
    BufferWriteWithStringLengthCheck(v13, aRearantiswayse_0);
    BufferWriteWithStringLengthCheck(v13, aFronttoeinsett_0);
    BufferWriteWithStringLengthCheck(v13, aReartoeinsetti_0);
    BufferWriteWithStringLengthCheck(v13, aLeftcastersett_0);
    BufferWriteWithStringLengthCheck(v13, aRightcasterset_0);
    BufferWriteWithStringLengthCheck(v13, aLefttrackbarse_0);
    BufferWriteWithStringLengthCheck(v13, aRighttrackbars_0);
    BufferWriteWithStringLengthCheck(v13, aFront3rdpacker_1);
    BufferWriteWithStringLengthCheck(v13, aFront3rdspring_1);
    BufferWriteWithStringLengthCheck(v13, aFront3rdslowbu_1);
    BufferWriteWithStringLengthCheck(v13, aFront3rdfastbu_1);
    BufferWriteWithStringLengthCheck(v13, aFront3rdslowre_1);
    BufferWriteWithStringLengthCheck(v13, aFront3rdfastre_1);
    BufferWriteWithStringLengthCheck(v13, aRear3rdpackers_0);
    BufferWriteWithStringLengthCheck(v13, aRear3rdsprings_0);
    BufferWriteWithStringLengthCheck(v13, aRear3rdslowbum_1);
    BufferWriteWithStringLengthCheck(v13, aRear3rdfastbum_1);
    BufferWriteWithStringLengthCheck(v13, aRear3rdslowreb_1);
    BufferWriteWithStringLengthCheck(v13, aRear3rdfastreb_1);
    BufferWriteWithStringLengthCheck(v13, &word_5C30B4);
    BufferWriteWithStringLengthCheck(v13, aControls_1);
    BufferWriteWithStringLengthCheck(v13, aSteerlocksetti_0);
    BufferWriteWithStringLengthCheck(v13, aRearbrakesetti_0);
    BufferWriteWithStringLengthCheck(v13, aBrakepressures_0);
    BufferWriteWithStringLengthCheck(v13, aHandbrakepress_1);
    BufferWriteWithStringLengthCheck(v13, &word_5C30B4);
    BufferWriteWithStringLengthCheck(v13, aEngine_1);
    BufferWriteWithStringLengthCheck(v13, aRevlimitsettin_0);
    BufferWriteWithStringLengthCheck(v13, aEnginemapsetti_0);
    BufferWriteWithStringLengthCheck(v13, aEnginebrakemap);
    BufferWriteWithStringLengthCheck(v13, &word_5C30B4);
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
    BufferWriteWithStringLengthCheck(v13, aDriveline_0);
    BufferWriteWithStringLengthCheck(v13, aFinaldrivesett);
    BufferWriteWithStringLengthCheck(v13, aReversesetting);
    v10 = 44;
    v11 = this + 5828;
    do
    {
      if ( v11[8] )
        BufferWriteWithStringLengthCheck(v13, aGearDsettingD);
      ++v10;
      v11 += 64;
    }
    while ( v10 <= 50 );
    BufferWriteWithStringLengthCheck(v13, aDiffpumpsettin);
    BufferWriteWithStringLengthCheck(v13, aDiffpowersetti);
    BufferWriteWithStringLengthCheck(v13, aDiffcoastsetti);
    BufferWriteWithStringLengthCheck(v13, aDiffpreloadset);
    BufferWriteWithStringLengthCheck(v13, &word_5C30B4);
    for ( j = 0; j < 4; ++j )
    {
      switch ( j )
      {
        case 0:
          BufferWriteWithStringLengthCheck(v13, aFrontleft_0);
          break;
        case 1:
          BufferWriteWithStringLengthCheck(v13, aFrontright_0);
          break;
        case 2:
          BufferWriteWithStringLengthCheck(v13, aRearleft_0);
          break;
        case 3:
          BufferWriteWithStringLengthCheck(v13, aRearright_0);
          break;
        default:
          break;
      }
      BufferWriteWithStringLengthCheck(v13, aCambersettingD);
      BufferWriteWithStringLengthCheck(v13, aPressuresettin_0);
      BufferWriteWithStringLengthCheck(v13, aPackersettingD);
      BufferWriteWithStringLengthCheck(v13, aSpringsettingD);
      BufferWriteWithStringLengthCheck(v13, aRideheightsett_0);
      BufferWriteWithStringLengthCheck(v13, aSlowbumpsettin_0);
      BufferWriteWithStringLengthCheck(v13, aFastbumpsettin_0);
      BufferWriteWithStringLengthCheck(v13, aSlowreboundset_0);
      BufferWriteWithStringLengthCheck(v13, aFastreboundset_0);
      BufferWriteWithStringLengthCheck(v13, aBrakediscsetti_0);
      BufferWriteWithStringLengthCheck(v13, aBrakepadsettin_0);
      BufferWriteWithStringLengthCheck(v13, &word_5C30B4);
    }
    BufferWriteWithStringLengthCheck(v13, aBasic_0);
    BufferWriteWithStringLengthCheck(v13, aDownforceF);
    BufferWriteWithStringLengthCheck(v13, aBalanceF);
    BufferWriteWithStringLengthCheck(v13, aRideF);
    BufferWriteWithStringLengthCheck(v13, aGearingF);
    BufferWriteWithStringLengthCheck(v13, aCustomD);
    BufferWriteWithStringLengthCheck(v13, &word_5C30B4);
    ConditionalFileHandleCloseWithFlagDispatch(v13);
    *this = 0;
    SubCallWithConditionalFieldFree(v13);
    return 0;
  }
  if ( (unsigned __int8)StringSplitLoop(1, aDDevF119992002_18, 1380) )
    DebugLogWrite(&dword_8AD25C, aFailedToOpenSF);
  SubCallWithConditionalFieldFree(v13);
  return -1;
}
