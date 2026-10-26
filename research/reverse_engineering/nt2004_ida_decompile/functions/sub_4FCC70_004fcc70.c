void __thiscall sub_4FCC70(_BYTE *this)
{
  CHAR *v1; // esi
  char *v2; // ebx
  size_t v3; // esi
  int v4; // ecx
  struct tm *v5; // eax
  char *v6; // eax
  CHAR *v7; // eax
  CHAR *v8; // eax
  CHAR *v9; // eax
  char v10; // di
  int *v11; // esi
  int *v12; // esi
  int *v13; // edi
  char v14; // al
  int i; // ebx
  int v16; // ebx
  int *v17; // ebp
  int v18; // edx
  CHAR *v19; // eax
  CHAR *v20; // eax
  char v21; // [esp-28h] [ebp-4C0h]
  char v22; // [esp-20h] [ebp-4B8h]
  char v23; // [esp-Ch] [ebp-4A4h]
  char v24; // [esp-8h] [ebp-4A0h]
  char v25; // [esp+0h] [ebp-498h]
  double v26; // [esp+8h] [ebp-490h]
  double v27; // [esp+8h] [ebp-490h]
  double v28; // [esp+8h] [ebp-490h]
  char v29; // [esp+8h] [ebp-490h]
  double v30; // [esp+8h] [ebp-490h]
  double v31; // [esp+8h] [ebp-490h]
  double v32; // [esp+8h] [ebp-490h]
  double v33; // [esp+8h] [ebp-490h]
  char v34; // [esp+10h] [ebp-488h]
  char v35; // [esp+10h] [ebp-488h]
  char v36; // [esp+10h] [ebp-488h]
  char v37; // [esp+10h] [ebp-488h]
  char ArgList[4]; // [esp+20h] [ebp-478h] BYREF
  int v39; // [esp+3Ch] [ebp-45Ch]
  char *FileName; // [esp+40h] [ebp-458h]
  int v41; // [esp+44h] [ebp-454h]
  char *Source; // [esp+48h] [ebp-450h]
  int v43; // [esp+4Ch] [ebp-44Ch]
  char v44[4]; // [esp+50h] [ebp-448h] BYREF
  __time32_t Time; // [esp+54h] [ebp-444h] BYREF
  char Buffer[64]; // [esp+58h] [ebp-440h] BYREF
  char Destination[1024]; // [esp+98h] [ebp-400h] BYREF

  if ( dword_75CBB0 == 7 && this[160] && byte_7697C0 )
  {
    v1 = dword_62A0C8;
    if ( !dword_62A0C8 )
      v1 = &byte_629120;
    Source = (char *)operator new(0x100u);
    *Source = 0;
    v43 = 256;
    sub_578600(v1);
    sub_578560(aResults);
    v2 = Source;
    if ( !Source )
      v2 = &byte_629120;
    v3 = 0;
    v4 = strlen(v2);
    v39 = v4;
    if ( v4 > 0 )
    {
      do
      {
        if ( v3 >= 0x400 )
          break;
        if ( Destination[v3 + v2 - Destination] == 92 )
        {
          strncpy(Destination, v2, v3);
          Destination[v3] = 0;
          _mkdir(Destination);
          v4 = v39;
        }
        ++v3;
      }
      while ( (int)v3 < v4 );
    }
    _mkdir(v2);
    time(&Time);
    v5 = localtime(&Time);
    sprintf(
      Buffer,
      "%d_%0.2d_%0.2d_%0.2d_%0.2d_%0.2d",
      v5->tm_year + 1900,
      v5->tm_mon + 1,
      v5->tm_mday,
      v5->tm_hour,
      v5->tm_min,
      v5->tm_sec);
    FileName = (char *)operator new(0x100u);
    *FileName = 0;
    v6 = Source;
    v41 = 256;
    if ( !Source )
      v6 = &byte_629120;
    sub_578600(v6);
    sub_578560(Buffer);
    sub_578560(aTxt);
    sub_57A080(ArgList);
    v7 = FileName;
    if ( !FileName )
      v7 = &byte_629120;
    sub_57A110(v7, 0, 1, 1);
    sub_57A400((int)ArgList, aHeader, v34);
    sub_57A400((int)ArgList, aGameS, (char)aNascarThunderT);
    sub_57A400((int)ArgList, aVersion3f, 0);
    sub_57A400((int)ArgList, aTimestringS, (char)Buffer);
    sub_57A400((int)ArgList, asc_5FB9D8, v22);
    sub_57A400((int)ArgList, aRace_1, v21);
    sub_57A400((int)ArgList, aRacemodeD, dword_7689CC[0]);
    LOBYTE(v8) = (_BYTE)dword_766578;
    if ( !dword_766578 )
      v8 = &byte_629120;
    sub_57A400((int)ArgList, aSceneS, (char)v8);
    LOBYTE(v9) = (_BYTE)::Source;
    if ( !::Source )
      v9 = &byte_629120;
    sub_57A400((int)ArgList, aAidbS, (char)v9);
    sub_57A400((int)ArgList, aQualifyLapsD, dword_768A2C[0]);
    sub_57A400((int)ArgList, aRaceLapsD, dword_768B70[0]);
    sub_57A400((int)ArgList, aRaceTimeD, dword_768CB4[0]);
    v26 = flt_768DF8;
    sub_57A400((int)ArgList, aRaceLength3f, SLOBYTE(v26));
    v27 = flt_6290D0;
    sub_57A400((int)ArgList, aTrackLength4f, SLOBYTE(v27));
    sub_57A400((int)ArgList, asc_5FB9D8, v25);
    sub_57A400((int)ArgList, aLocalSettings, v24);
    sub_57A400((int)ArgList, aDriveaidsSteer, dword_7667B0[0]);
    sub_57A400((int)ArgList, aDriveaidsSteer_0, dword_7667D4[0]);
    sub_57A400((int)ArgList, aDriveaidsThrot, dword_7667F8[0]);
    sub_57A400((int)ArgList, aDriveaidsBrake, dword_76681C[0]);
    sub_57A400((int)ArgList, aDriveaidsAntil, dword_766840[0]);
    sub_57A400((int)ArgList, aDriveaidsSpinR, dword_766864[0]);
    sub_57A400((int)ArgList, aDriveaidsInvul, dword_766888[0]);
    sub_57A400((int)ArgList, aDriveaidsAutop, dword_7668AC[0]);
    sub_57A400((int)ArgList, aDriveaidsAutoP, dword_7668D0[0]);
    sub_57A400((int)ArgList, aDriveaidsOppos, dword_7668F4[0]);
    sub_57A400((int)ArgList, aDriveaidsStabi, dword_766918[0]);
    sub_57A400((int)ArgList, aDriveaidsNoAiC, dword_76693C[0]);
    sub_57A400((int)ArgList, aDriveaidsAllow, byte_766960);
    sub_57A400((int)ArgList, aDriveaidsAutoC, dword_766978[0]);
    sub_57A400((int)ArgList, aDriveaidsShift, dword_7669CC[0]);
    sub_57A400((int)ArgList, aDriveaidsAutoR, dword_766A38[0]);
    v28 = flt_766A80;
    sub_57A400((int)ArgList, aDriveaidsSpeed, SLOBYTE(v28));
    sub_57A400((int)ArgList, aDriveaidsHalfR, dword_766AA4[0]);
    sub_57A400((int)ArgList, aMechfailRateD, dword_766B6C[0]);
    sub_57A400((int)ArgList, aGameoptDamagem, dword_7684BC[0]);
    sub_57A400((int)ArgList, aFuelMultD, dword_76926C[0]);
    sub_57A400((int)ArgList, aTireMultD, dword_7693B0[0]);
    sub_57A400((int)ArgList, aAllCarsEqualD, dword_7694F4[0]);
    sub_57A400((int)ArgList, aVehiclesAllowe, dword_769638[0]);
    sub_57A400((int)ArgList, aMultiDataRateD, dword_76986C[0]);
    sub_57A400((int)ArgList, aNoplayerD, dword_76BB84[0]);
    sub_57A400((int)ArgList, asc_5FB9D8, v35);
    sub_57A400((int)ArgList, aControls_0, v29);
    v10 = 0;
    v11 = dword_76A67C;
    do
    {
      sub_57A400((int)ArgList, aDDD_1, v10);
      v11 += 7;
      ++v10;
    }
    while ( (int)v11 < (int)&dword_76AD28 );
    sub_57A400((int)ArgList, asc_5FB9D8, v36);
    v12 = dword_631104;
    do
    {
      if ( v12 != (int *)20892 && *(v12 - 1077) != -1 )
      {
        v13 = v12 - 14;
        sub_57A400((int)ArgList, aSlot, v37);
        sub_57A400((int)ArgList, aPlaceD, *(v12 - 2));
        sub_57A400((int)ArgList, aSlotidD, v12[1089]);
        sub_57A400((int)ArgList, aControlD, *(v12 - 1077));
        sub_57A400((int)ArgList, aDriverS, (_BYTE)v12 + 40);
        sub_57A400((int)ArgList, aVehiclenameS, (_BYTE)v12 + 104);
        sub_57A400((int)ArgList, aVehiclefileS, (_BYTE)v12 + 4);
        sub_57A400((int)ArgList, aGarageindexD, v12[1094]);
        sub_57A400((int)ArgList, aPitindexD, v12[1093]);
        sub_57A400((int)ArgList, aDnfD, *v12 == 2);
        sub_57A400((int)ArgList, aDnfReasonD, v12[1]);
        sub_57A400((int)ArgList, aDqD, *v12 == 3);
        v14 = sub_4DEBD0(v12 - 14);
        sub_57A400((int)ArgList, aLapsleadD, v14);
        v30 = *((float *)v12 + 17);
        sub_57A400((int)ArgList, aBestLapTime3f, SLOBYTE(v30));
        v31 = *((float *)v12 + 23);
        sub_57A400((int)ArgList, aBestLapStart3f, SLOBYTE(v31));
        v32 = *((float *)v12 + 24);
        sub_57A400((int)ArgList, aTotalEt3f, SLOBYTE(v32));
        sub_57A400((int)ArgList, aTotalLapsD, *(v12 - 11));
        for ( i = 0; i < *(v12 - 11); ++i )
        {
          *(float *)&v39 = sub_4DD090(v12 - 14, i);
          if ( sub_4DD0C0(v12 - 14, i) != -1.0 )
            sub_57A400((int)ArgList, aLapD3f3f, i);
        }
        v16 = 0;
        v17 = v13 + 34;
        do
        {
          sub_57A400((int)ArgList, aSectorDBest3f, v16++);
          ++v17;
        }
        while ( v16 < 3 );
        v33 = *((float *)v13 + 46);
        sub_57A400((int)ArgList, aTotalFinesF, SLOBYTE(v33));
        sub_57A400((int)ArgList, aQualificationD, v13[10]);
        sub_57A400((int)ArgList, asc_5FB9D8, v23);
      }
      v12 += 6326;
    }
    while ( (int)v12 < (int)dword_759984 );
    sub_57A360(ArgList);
    *(_DWORD *)v44 = 0;
    rand();
    v18 = rand() % 200;
    v19 = FileName;
    LOBYTE(v39) = v18 + 32;
    if ( !FileName )
      v19 = &byte_629120;
    if ( (unsigned __int8)sub_57B490(v19, v39, (int)v44) )
    {
      v20 = FileName;
      if ( !FileName )
        v20 = &byte_629120;
      if ( (unsigned __int8)sub_57A240(v20, 0, 1, 1) )
      {
        sub_57A400((int)ArgList, aScs, v37);
        sub_57A400((int)ArgList, aSCDD, v39);
        sub_57A400((int)ArgList, aResultD, v44[0]);
        sub_57A360(ArgList);
      }
    }
    sub_57A0A0(ArgList);
    if ( FileName )
      sub_5BE8AE();
    if ( Source )
      sub_5BE8AE();
  }
}
