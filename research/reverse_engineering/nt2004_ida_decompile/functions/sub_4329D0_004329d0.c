int __userpurge sub_4329D0@<eax>(int a1@<ecx>, char a2@<dil>, char *ArgList, char a4)
{
  int i; // esi
  CHAR *v7; // eax
  _DWORD *v8; // eax
  int v9; // edx
  int v10; // ecx
  int v11; // esi
  int v12; // edi
  int j; // edi
  _DWORD *v14; // esi
  char v15; // [esp-34h] [ebp-E8h]
  char v16; // [esp-30h] [ebp-E4h]
  char v17; // [esp-30h] [ebp-E4h]
  char v18; // [esp-30h] [ebp-E4h]
  char v19; // [esp-28h] [ebp-DCh]
  char v20; // [esp-28h] [ebp-DCh]
  char v21; // [esp-28h] [ebp-DCh]
  char v22; // [esp-28h] [ebp-DCh]
  char v23; // [esp-28h] [ebp-DCh]
  char v24; // [esp-20h] [ebp-D4h]
  char v25; // [esp-1Ch] [ebp-D0h]
  char v26; // [esp-1Ch] [ebp-D0h]
  char v27; // [esp-14h] [ebp-C8h]
  char v28; // [esp-14h] [ebp-C8h]
  char v29; // [esp-Ch] [ebp-C0h]
  char v30; // [esp-4h] [ebp-B8h]
  char v31; // [esp+0h] [ebp-B4h]
  char v32; // [esp+0h] [ebp-B4h]
  double v33; // [esp+0h] [ebp-B4h]
  double v34; // [esp+0h] [ebp-B4h]
  double v35; // [esp+0h] [ebp-B4h]
  double v36; // [esp+0h] [ebp-B4h]
  char v37; // [esp+8h] [ebp-ACh]
  char v38; // [esp+8h] [ebp-ACh]
  char v39; // [esp+8h] [ebp-ACh]
  char v40; // [esp+Ch] [ebp-A8h]
  char v41[4]; // [esp+14h] [ebp-A0h] BYREF
  char Destination[132]; // [esp+30h] [ebp-84h] BYREF

  if ( !a4 && !*(_BYTE *)a1 )
    return 0;
  sub_57A080(v41);
  if ( (unsigned __int8)sub_57A110(ArgList, 0, 0, 1) == 1 )
  {
    sub_57A400((int)v41, aGeneral, v40);
    for ( i = 0; ; i += 128 )
    {
      v7 = *(CHAR **)(a1 + 104);
      if ( !v7 )
        v7 = &byte_629120;
      strncpy(Destination, &v7[i], 0x80u);
      Destination[128] = 0;
      sub_57A400((int)v41, aNotesS, (char)Destination);
      if ( strlen(Destination) < 0x80 )
        break;
    }
    sub_57A400((int)v41, aSymmetricD, *(_BYTE *)(a1 + 6565));
    sub_57A400((int)v41, aCgrightsetting, *(_DWORD *)(a1 + 3076));
    sub_57A400((int)v41, aCgrearsettingD, *(_DWORD *)(a1 + 3140));
    sub_57A400((int)v41, aWedgesettingD, *(_DWORD *)(a1 + 3204));
    sub_57A400((int)v41, aTirecompoundse, *(_DWORD *)(a1 + 3012));
    sub_57A400((int)v41, aFuelsettingD, *(_DWORD *)(a1 + 3268));
    sub_57A400((int)v41, aNumpitstopsset, *(_DWORD *)(a1 + 6276));
    sub_57A400((int)v41, aPitstop1settin, *(_DWORD *)(a1 + 6340));
    sub_57A400((int)v41, aPitstop2settin, *(_DWORD *)(a1 + 6404));
    sub_57A400((int)v41, aPitstop3settin, *(_DWORD *)(a1 + 6468));
    sub_57A400((int)v41, asc_5FB9D8, v19);
    sub_57A400((int)v41, aLeftfender, v16);
    sub_57A400((int)v41, aFenderflareset, *(_DWORD *)(a1 + 3588));
    sub_57A400((int)v41, asc_5FB9D8, v30);
    sub_57A400((int)v41, aRightfender, v29);
    sub_57A400((int)v41, aFenderflareset, *(_DWORD *)(a1 + 3652));
    sub_57A400((int)v41, asc_5FB9D8, v24);
    sub_57A400((int)v41, aFrontwing, v20);
    sub_57A400((int)v41, aFwsettingD, *(_DWORD *)(a1 + 4740));
    sub_57A400((int)v41, asc_5FB9D8, a2);
    sub_57A400((int)v41, aRearwing, v31);
    sub_57A400((int)v41, aRwsettingD, *(_DWORD *)(a1 + 4804));
    sub_57A400((int)v41, asc_5FB9D8, v27);
    sub_57A400((int)v41, aBodyaero, v25);
    sub_57A400((int)v41, aRadiatorsettin, *(_DWORD *)(a1 + 4868));
    sub_57A400((int)v41, aBrakeductsetti, *(_DWORD *)(a1 + 4932));
    sub_57A400((int)v41, asc_5FB9D8, v37);
    sub_57A400((int)v41, aSuspension, v32);
    sub_57A400((int)v41, aFrontantisways, *(_DWORD *)(a1 + 3332));
    sub_57A400((int)v41, aRearantiswayse, *(_DWORD *)(a1 + 3396));
    sub_57A400((int)v41, aFronttoeinsett, *(_DWORD *)(a1 + 3460));
    sub_57A400((int)v41, aReartoeinsetti, *(_DWORD *)(a1 + 3524));
    sub_57A400((int)v41, aLeftcastersett, *(_DWORD *)(a1 + 3716));
    sub_57A400((int)v41, aRightcasterset, *(_DWORD *)(a1 + 3780));
    sub_57A400((int)v41, aLefttrackbarse, *(_DWORD *)(a1 + 3844));
    sub_57A400((int)v41, aRighttrackbars, *(_DWORD *)(a1 + 3908));
    sub_57A400((int)v41, aFront3rdpacker, *(_DWORD *)(a1 + 3972));
    sub_57A400((int)v41, aFront3rdspring, *(_DWORD *)(a1 + 4036));
    sub_57A400((int)v41, aFront3rdslowbu, *(_DWORD *)(a1 + 4100));
    sub_57A400((int)v41, aFront3rdfastbu, *(_DWORD *)(a1 + 4164));
    sub_57A400((int)v41, aFront3rdslowre, *(_DWORD *)(a1 + 4228));
    sub_57A400((int)v41, aFront3rdfastre, *(_DWORD *)(a1 + 4292));
    sub_57A400((int)v41, aRear3rdpackers, *(_DWORD *)(a1 + 4356));
    sub_57A400((int)v41, aRear3rdsprings, *(_DWORD *)(a1 + 4420));
    sub_57A400((int)v41, aRear3rdslowbum, *(_DWORD *)(a1 + 4484));
    sub_57A400((int)v41, aRear3rdfastbum, *(_DWORD *)(a1 + 4548));
    sub_57A400((int)v41, aRear3rdslowreb, *(_DWORD *)(a1 + 4612));
    sub_57A400((int)v41, aRear3rdfastreb, *(_DWORD *)(a1 + 4676));
    sub_57A400((int)v41, asc_5FB9D8, v21);
    sub_57A400((int)v41, aControls, v17);
    sub_57A400((int)v41, aSteerlocksetti, *(_DWORD *)(a1 + 5188));
    sub_57A400((int)v41, aRearbrakesetti, *(_DWORD *)(a1 + 4996));
    sub_57A400((int)v41, aBrakepressures, *(_DWORD *)(a1 + 5060));
    sub_57A400((int)v41, aHandbrakepress, *(_DWORD *)(a1 + 5124));
    sub_57A400((int)v41, asc_5FB9D8, v22);
    sub_57A400((int)v41, aEngine, v18);
    sub_57A400((int)v41, aRevlimitsettin, *(_DWORD *)(a1 + 5508));
    sub_57A400((int)v41, aEnginemapsetti, *(_DWORD *)(a1 + 5572));
    sub_57A400((int)v41, aEnginebrakingm, *(_DWORD *)(a1 + 5636));
    sub_57A400((int)v41, asc_5FB9D8, v26);
    v8 = (_DWORD *)(a1 + 5892);
    v9 = 6;
    do
    {
      v10 = *(v8 - 16);
      if ( *v8 < v10 )
        *v8 = v10;
      v8 += 16;
      --v9;
    }
    while ( v9 );
    sub_57A400((int)v41, aDriveline, v38);
    sub_57A400((int)v41, aFinaldrivesett, *(_DWORD *)(a1 + 5700));
    sub_57A400((int)v41, aReversesetting, *(_DWORD *)(a1 + 5764));
    v11 = 44;
    v12 = a1 + 5828;
    do
    {
      if ( *(_BYTE *)(v12 + 8) )
        sub_57A400((int)v41, aGearDsettingD, v11 - 43);
      ++v11;
      v12 += 64;
    }
    while ( v11 <= 50 );
    sub_57A400((int)v41, aDiffpumpsettin, *(_DWORD *)(a1 + 5252));
    sub_57A400((int)v41, aDiffpowersetti, *(_DWORD *)(a1 + 5316));
    sub_57A400((int)v41, aDiffcoastsetti, *(_DWORD *)(a1 + 5380));
    sub_57A400((int)v41, aDiffpreloadset, *(_DWORD *)(a1 + 5444));
    sub_57A400((int)v41, asc_5FB9D8, v23);
    for ( j = 0; j < 4; ++j )
    {
      switch ( j )
      {
        case 0:
          sub_57A400((int)v41, aFrontleft, v39);
          break;
        case 1:
          sub_57A400((int)v41, aFrontright, v39);
          break;
        case 2:
          sub_57A400((int)v41, aRearleft, v39);
          break;
        case 3:
          sub_57A400((int)v41, aRearright, v39);
          break;
        default:
          break;
      }
      v14 = (_DWORD *)(704 * j + a1);
      sub_57A400((int)v41, aCambersettingD, v14[49]);
      sub_57A400((int)v41, aPressuresettin, v14[65]);
      sub_57A400((int)v41, aPackersettingD, v14[97]);
      sub_57A400((int)v41, aSpringsettingD, v14[113]);
      sub_57A400((int)v41, aRideheightsett, v14[81]);
      sub_57A400((int)v41, aSlowbumpsettin, v14[129]);
      sub_57A400((int)v41, aFastbumpsettin, v14[145]);
      sub_57A400((int)v41, aSlowreboundset, v14[161]);
      sub_57A400((int)v41, aFastreboundset, v14[177]);
      sub_57A400((int)v41, aBrakediscsetti, v14[193]);
      sub_57A400((int)v41, aBrakepadsettin, v14[209]);
      sub_57A400((int)v41, asc_5FB9D8, v15);
    }
    sub_57A400((int)v41, aBasic, v39);
    v33 = *(float *)(a1 + 7336);
    sub_57A400((int)v41, aDownforceF, SLOBYTE(v33));
    v34 = *(float *)(a1 + 7340);
    sub_57A400((int)v41, aBalanceF, SLOBYTE(v34));
    v35 = *(float *)(a1 + 7344);
    sub_57A400((int)v41, aRideF, SLOBYTE(v35));
    v36 = *(float *)(a1 + 7348);
    sub_57A400((int)v41, aGearingF, SLOBYTE(v36));
    sub_57A400((int)v41, aCustomD, *(_BYTE *)(a1 + 6564));
    sub_57A400((int)v41, asc_5FB9D8, v28);
    sub_57A360(v41);
    *(_BYTE *)a1 = 0;
    sub_57A0A0(v41);
    return 0;
  }
  if ( (unsigned __int8)sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_9, 1459) )
    sub_500FE0((int)&unk_7D7920, aFailedToOpenSF, (char)ArgList);
  sub_57A0A0(v41);
  return -1;
}
