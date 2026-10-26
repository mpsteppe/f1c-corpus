void __fastcall sub_4AA270(int a1, int a2)
{
  bool v3; // cc
  _DWORD *v4; // ecx
  _BYTE *v5; // eax
  int v6; // eax
  _BYTE *v7; // eax
  int v8; // eax
  _BYTE *v9; // eax
  int v10; // eax
  _BYTE *v11; // eax
  int v12; // eax
  _BYTE *v13; // eax
  int v14; // eax
  _BYTE *v15; // eax
  int v16; // eax
  _BYTE *v17; // eax
  int v18; // eax
  _BYTE *v19; // eax
  int v20; // eax
  _BYTE *v21; // eax
  int v22; // eax
  int v23; // eax
  int v24; // eax
  int v25; // eax
  int v26; // eax
  int v27; // eax
  int v28; // eax
  int v29; // eax
  int v30; // eax
  int v31; // eax
  int v32; // eax
  int v33; // eax
  int v34; // eax
  int v35; // eax
  int v36; // eax
  int v37; // eax
  int v38; // eax
  int v39; // edx
  int v40; // [esp-14h] [ebp-134h]
  int v41; // [esp+10h] [ebp-110h]
  int v42; // [esp+10h] [ebp-110h]
  int i; // [esp+10h] [ebp-110h]
  int v44; // [esp+10h] [ebp-110h]
  int v45; // [esp+10h] [ebp-110h]
  int v46; // [esp+10h] [ebp-110h]
  int v47; // [esp+10h] [ebp-110h]
  int v48; // [esp+10h] [ebp-110h]
  int v49; // [esp+10h] [ebp-110h]
  int v50; // [esp+10h] [ebp-110h]
  int v51; // [esp+10h] [ebp-110h]
  int v52; // [esp+10h] [ebp-110h]
  int v53; // [esp+10h] [ebp-110h]
  int v54; // [esp+10h] [ebp-110h]
  int v55; // [esp+10h] [ebp-110h]
  int v56; // [esp+10h] [ebp-110h]
  int j; // [esp+10h] [ebp-110h]
  int v58; // [esp+10h] [ebp-110h]
  _DWORD *v59; // [esp+14h] [ebp-10Ch]
  _DWORD *v60; // [esp+14h] [ebp-10Ch]
  _DWORD *v61; // [esp+14h] [ebp-10Ch]
  _DWORD *v62; // [esp+14h] [ebp-10Ch]
  _DWORD *v63; // [esp+14h] [ebp-10Ch]
  _BYTE *v64; // [esp+14h] [ebp-10Ch]
  int v65; // [esp+14h] [ebp-10Ch]
  int v66; // [esp+14h] [ebp-10Ch]
  int v67; // [esp+14h] [ebp-10Ch]
  int v68; // [esp+14h] [ebp-10Ch]
  int v69; // [esp+14h] [ebp-10Ch]
  int v70; // [esp+14h] [ebp-10Ch]
  int v71; // [esp+14h] [ebp-10Ch]
  int v72; // [esp+14h] [ebp-10Ch]
  char *v73; // [esp+14h] [ebp-10Ch]
  int k; // [esp+14h] [ebp-10Ch]
  int v75; // [esp+14h] [ebp-10Ch]
  char *v76; // [esp+18h] [ebp-108h]
  int v77; // [esp+18h] [ebp-108h]
  int v78; // [esp+1Ch] [ebp-104h]
  int v79; // [esp+1Ch] [ebp-104h]
  int v80; // [esp+1Ch] [ebp-104h]
  _BYTE v81[256]; // [esp+20h] [ebp-100h] BYREF

  v81[0] = 0;
  FlagSetterWithGlobalUpdate(a1, a2, 1);
  SettingsPathBuilder((void *)(a1 + 280), (int)aScene);
  TripleDispatchWrapper((void *)(a1 + 292), (int)aSceneFile, (int)byte_5EA438, 0);
  TripleDispatchWrapper((void *)(a1 + 320), (int)aSceneDescripti, (int)byte_5EA438, 0);
  TripleDispatchWrapper((void *)(a1 + 348), (int)aAiDatabaseFile, (int)byte_5EA438, 0);
  SettingsPathBuilder((void *)(a1 + 376), (int)aDriver_1);
  TripleDispatchWrapper((void *)(a1 + 388), (int)aProfileVehicle, (int)byte_5EA438, 0);
  TripleDispatchWrapper((void *)(a1 + 416), (int)aVehicleFile, (int)byte_5EA438, 0);
  TripleDispatchWrapper((void *)(a1 + 444), (int)aDriverName, (int)byte_5EA438, 0);
  TripleDispatchWrapper((void *)(a1 + 472), (int)aNationality, (int)byte_5EA438, 0);
  SettingsPathBuilder((void *)(a1 + 500), (int)aDrivingAids);
  StringCopyWithBufferRealloc(aSteeringHelp);
  *(_DWORD *)(a1 + 536) = 1;
  *(_DWORD *)(a1 + 540) = 0;
  *(_DWORD *)(a1 + 544) = 2;
  *(_DWORD *)(a1 + 532) = 1;
  ShortComputation_1b70((void *)(a1 + 512));
  StringCopyWithBufferRealloc(aSteeringHelpFu);
  *(_DWORD *)(a1 + 572) = 1;
  *(_DWORD *)(a1 + 576) = 0;
  *(_DWORD *)(a1 + 580) = 3;
  StringCopyWithBufferRealloc(a0NewHelp1NewHe);
  *(_DWORD *)(a1 + 568) = 1;
  ShortComputation_1b70((void *)(a1 + 548));
  StringCopyWithBufferRealloc(aThrottleContro);
  *(_DWORD *)(a1 + 608) = 1;
  *(_DWORD *)(a1 + 612) = 0;
  *(_DWORD *)(a1 + 616) = 2;
  *(_DWORD *)(a1 + 604) = 1;
  ShortComputation_1b70((void *)(a1 + 584));
  StringCopyWithBufferRealloc(aBrakeHelp);
  *(_DWORD *)(a1 + 644) = 1;
  *(_DWORD *)(a1 + 648) = 0;
  *(_DWORD *)(a1 + 652) = 2;
  *(_DWORD *)(a1 + 640) = 1;
  ShortComputation_1b70((void *)(a1 + 620));
  StringCopyWithBufferRealloc(aAntilockBrakes);
  *(_DWORD *)(a1 + 680) = 1;
  *(_DWORD *)(a1 + 684) = 0;
  *(_DWORD *)(a1 + 688) = 2;
  *(_DWORD *)(a1 + 676) = 1;
  ShortComputation_1b70((void *)(a1 + 656));
  StringCopyWithBufferRealloc(aSpinRecovery_0);
  *(_DWORD *)(a1 + 716) = 1;
  *(_DWORD *)(a1 + 720) = 0;
  *(_DWORD *)(a1 + 724) = 2;
  *(_DWORD *)(a1 + 712) = 1;
  ShortComputation_1b70((void *)(a1 + 692));
  StringCopyWithBufferRealloc(aInvulnerabilit_0);
  *(_DWORD *)(a1 + 752) = 1;
  *(_DWORD *)(a1 + 756) = 0;
  *(_DWORD *)(a1 + 760) = 1;
  *(_DWORD *)(a1 + 748) = 1;
  ShortComputation_1b70((void *)(a1 + 728));
  StringCopyWithBufferRealloc(aAutopit);
  *(_DWORD *)(a1 + 788) = 1;
  *(_DWORD *)(a1 + 792) = 0;
  *(_DWORD *)(a1 + 796) = 1;
  *(_DWORD *)(a1 + 784) = 1;
  ShortComputation_1b70((void *)(a1 + 764));
  StringCopyWithBufferRealloc(aOppositeLock);
  *(_DWORD *)(a1 + 824) = 1;
  *(_DWORD *)(a1 + 828) = 0;
  *(_DWORD *)(a1 + 832) = 1;
  *(_DWORD *)(a1 + 820) = 1;
  ShortComputation_1b70((void *)(a1 + 800));
  StringCopyWithBufferRealloc(aStabilityContr);
  *(_DWORD *)(a1 + 860) = 1;
  *(_DWORD *)(a1 + 864) = 0;
  *(_DWORD *)(a1 + 868) = 2;
  *(_DWORD *)(a1 + 856) = 1;
  ShortComputation_1b70((void *)(a1 + 836));
  StringCopyWithBufferRealloc(aNoAiControl);
  *(_DWORD *)(a1 + 896) = 0;
  *(_DWORD *)(a1 + 900) = 0;
  *(_DWORD *)(a1 + 904) = 1;
  StringCopyWithBufferRealloc(aAiNeverHasCont);
  *(_DWORD *)(a1 + 892) = 0;
  ShortComputation_1b70((void *)(a1 + 872));
  StringCopyWithBufferRealloc(aPitcrewPush);
  *(_BYTE *)(a1 + 929) = 1;
  *(_BYTE *)(a1 + 930) = 0;
  *(_BYTE *)(a1 + 931) = 1;
  StringCopyWithBufferRealloc(aWhenOutOfFuelI);
  *(_BYTE *)(a1 + 928) = 1;
  ShortComputation_1b70((void *)(a1 + 908));
  StringCopyWithBufferRealloc(aAutoClutch);
  *(_DWORD *)(a1 + 956) = 1;
  *(_DWORD *)(a1 + 960) = 0;
  *(_DWORD *)(a1 + 964) = 1;
  *(_DWORD *)(a1 + 952) = 1;
  ShortComputation_1b70((void *)(a1 + 932));
  StringCopyWithBufferRealloc(aAutoLift);
  *(_BYTE *)(a1 + 989) = 0;
  *(_BYTE *)(a1 + 990) = 0;
  *(_BYTE *)(a1 + 991) = 1;
  StringCopyWithBufferRealloc(aWhetherToAutom);
  *(_BYTE *)(a1 + 988) = 0;
  ShortComputation_1b70((void *)(a1 + 968));
  StringCopyWithBufferRealloc(aAutoBlip);
  *(_BYTE *)(a1 + 1013) = 1;
  *(_BYTE *)(a1 + 1014) = 0;
  *(_BYTE *)(a1 + 1015) = 1;
  StringCopyWithBufferRealloc(aWhetherToAutom_0);
  *(_BYTE *)(a1 + 1012) = 1;
  ShortComputation_1b70((void *)(a1 + 992));
  StringCopyWithBufferRealloc(aShiftMode);
  *(_DWORD *)(a1 + 1040) = 3;
  *(_DWORD *)(a1 + 1044) = 0;
  *(_DWORD *)(a1 + 1048) = 4;
  *(_DWORD *)(a1 + 1036) = 3;
  ShortComputation_1b70((void *)(a1 + 1016));
  StringCopyWithBufferRealloc(aManualShiftOve);
  *(_DWORD *)(a1 + 1076) = 1058642330;
  *(_DWORD *)(a1 + 1080) = 0;
  *(_DWORD *)(a1 + 1084) = 1176255488;
  StringCopyWithBufferRealloc(aHowLongAfterAM);
  *(_DWORD *)(a1 + 1072) = 1058642330;
  ShortComputation_1b70((void *)(a1 + 1052));
  StringCopyWithBufferRealloc(aAutoShiftOverr);
  *(_DWORD *)(a1 + 1112) = 1057803469;
  *(_DWORD *)(a1 + 1116) = 0;
  *(_DWORD *)(a1 + 1120) = 1176255488;
  StringCopyWithBufferRealloc(aHowLongAfterAn);
  *(_DWORD *)(a1 + 1108) = 1057803469;
  ShortComputation_1b70((void *)(a1 + 1088));
  StringCopyWithBufferRealloc(aAutoReverse);
  *(_DWORD *)(a1 + 1148) = 1;
  *(_DWORD *)(a1 + 1152) = 0;
  *(_DWORD *)(a1 + 1156) = 1;
  *(_DWORD *)(a1 + 1144) = 1;
  ShortComputation_1b70((void *)(a1 + 1124));
  StringCopyWithBufferRealloc(aSpeedSensitive);
  *(_DWORD *)(a1 + 1184) = 1058642330;
  *(_DWORD *)(a1 + 1188) = 0;
  *(_DWORD *)(a1 + 1192) = 1065353216;
  *(_DWORD *)(a1 + 1180) = 1058642330;
  ShortComputation_1b70((void *)(a1 + 1160));
  StringCopyWithBufferRealloc(aHalfRate);
  *(_DWORD *)(a1 + 1220) = 1;
  *(_DWORD *)(a1 + 1224) = 0;
  *(_DWORD *)(a1 + 1228) = 1;
  StringCopyWithBufferRealloc(a0SuperHighPhys);
  *(_DWORD *)(a1 + 1216) = 1;
  ShortComputation_1b70((void *)(a1 + 1196));
  StringCopyWithBufferRealloc(aLaunchControl);
  *(_BYTE *)(a1 + 1253) = 1;
  *(_BYTE *)(a1 + 1254) = 0;
  *(_BYTE *)(a1 + 1255) = 1;
  StringCopyWithBufferRealloc(aWhetherOldCars);
  *(_BYTE *)(a1 + 1252) = 1;
  ShortComputation_1b70((void *)(a1 + 1232));
  StringCopyWithBufferRealloc(aTireSampling);
  *(_BYTE *)(a1 + 1277) = 0;
  *(_BYTE *)(a1 + 1278) = 0;
  *(_BYTE *)(a1 + 1279) = 1;
  StringCopyWithBufferRealloc(a0Normal1ExtraH);
  *(_BYTE *)(a1 + 1276) = 0;
  ShortComputation_1b70((void *)(a1 + 1256));
  StringCopyWithBufferRealloc(aTelemetryVersi);
  *(_DWORD *)(a1 + 1304) = 0;
  *(_DWORD *)(a1 + 1308) = 0;
  *(_DWORD *)(a1 + 1312) = 99;
  StringCopyWithBufferRealloc(aVersionOfTelem);
  *(_DWORD *)(a1 + 1300) = 0;
  ShortComputation_1b70((void *)(a1 + 1280));
  StringCopyWithBufferRealloc(aTelemetryRate);
  *(_DWORD *)(a1 + 1340) = 8;
  *(_DWORD *)(a1 + 1344) = 0;
  *(_DWORD *)(a1 + 1348) = 40;
  *(_DWORD *)(a1 + 1336) = 8;
  ShortComputation_1b70((void *)(a1 + 1316));
  StringCopyWithBufferRealloc(aTelemetryInRac);
  *(_DWORD *)(a1 + 1376) = 1;
  *(_DWORD *)(a1 + 1380) = 0;
  *(_DWORD *)(a1 + 1384) = 1;
  *(_DWORD *)(a1 + 1372) = 1;
  ShortComputation_1b70((void *)(a1 + 1352));
  TripleDispatchWrapper((void *)(a1 + 1388), (int)aTelemetryExe, (int)aTelemetryF1Tel, 0);
  TripleDispatchWrapper((void *)(a1 + 1416), (int)aTelemetryFile, (int)aTelemetryTelem, 0);
  SettingsPathBuilder((void *)(a1 + 1444), (int)aMechanicalFail);
  v41 = 0;
  v59 = (_DWORD *)(a1 + 1480);
  do
  {
    sub_4AA1E0(v41, aFailureRate, v81);
    StringCopyWithBufferRealloc(v81);
    *v59 = 2;
    v59[1] = 0;
    v59[2] = 3;
    StringCopyWithBufferRealloc(aMechanicalFail_0);
    *(v59 - 1) = 2;
    ShortComputation_1b70(v59 - 6);
    v3 = ++v41 < 7;
    v59 += 9;
  }
  while ( v3 );
  SettingsPathBuilder((void *)(a1 + 1708), (int)aRaceConditions);
  StringCopyWithBufferRealloc(aRunPractice1);
  *(_BYTE *)(a1 + 1741) = 1;
  *(_BYTE *)(a1 + 1742) = 0;
  *(_BYTE *)(a1 + 1743) = 1;
  *(_BYTE *)(a1 + 1740) = 1;
  ShortComputation_1b70((void *)(a1 + 1720));
  StringCopyWithBufferRealloc(aRunPractice2);
  *(_BYTE *)(a1 + 1765) = 1;
  *(_BYTE *)(a1 + 1766) = 0;
  *(_BYTE *)(a1 + 1767) = 1;
  *(_BYTE *)(a1 + 1764) = 1;
  ShortComputation_1b70((void *)(a1 + 1744));
  StringCopyWithBufferRealloc(aRunPractice3);
  *(_BYTE *)(a1 + 1789) = 1;
  *(_BYTE *)(a1 + 1790) = 0;
  *(_BYTE *)(a1 + 1791) = 1;
  *(_BYTE *)(a1 + 1788) = 1;
  ShortComputation_1b70((void *)(a1 + 1768));
  StringCopyWithBufferRealloc(aRunPractice4);
  *(_BYTE *)(a1 + 1813) = 1;
  *(_BYTE *)(a1 + 1814) = 0;
  *(_BYTE *)(a1 + 1815) = 1;
  *(_BYTE *)(a1 + 1812) = 1;
  ShortComputation_1b70((void *)(a1 + 1792));
  StringCopyWithBufferRealloc(aRunQualify);
  *(_BYTE *)(a1 + 1837) = 1;
  *(_BYTE *)(a1 + 1838) = 0;
  *(_BYTE *)(a1 + 1839) = 1;
  *(_BYTE *)(a1 + 1836) = 1;
  ShortComputation_1b70((void *)(a1 + 1816));
  StringCopyWithBufferRealloc(aRunWarmup);
  *(_BYTE *)(a1 + 1861) = 1;
  *(_BYTE *)(a1 + 1862) = 0;
  *(_BYTE *)(a1 + 1863) = 1;
  *(_BYTE *)(a1 + 1860) = 1;
  ShortComputation_1b70((void *)(a1 + 1840));
  StringCopyWithBufferRealloc(aRaceTimer);
  *(_DWORD *)(a1 + 1888) = 0;
  *(_DWORD *)(a1 + 1892) = 0;
  *(_DWORD *)(a1 + 1896) = 0x7FFFFFFF;
  StringCopyWithBufferRealloc(aSecondsBetween);
  *(_DWORD *)(a1 + 1884) = 0;
  ShortComputation_1b70((void *)(a1 + 1864));
  StringCopyWithBufferRealloc(aAiFollowGrid);
  *(_BYTE *)(a1 + 1921) = 1;
  *(_BYTE *)(a1 + 1922) = 0;
  *(_BYTE *)(a1 + 1923) = 1;
  StringCopyWithBufferRealloc(aAiFollowsCente);
  *(_BYTE *)(a1 + 1920) = 1;
  ShortComputation_1b70((void *)(a1 + 1900));
  StringCopyWithBufferRealloc(aReconPitOpen);
  *(_DWORD *)(a1 + 1948) = 300;
  *(_DWORD *)(a1 + 1952) = 30;
  *(_DWORD *)(a1 + 1956) = 900;
  StringCopyWithBufferRealloc(aTimeThatPitsRe);
  *(_DWORD *)(a1 + 1944) = 300;
  ShortComputation_1b70((void *)(a1 + 1924));
  StringCopyWithBufferRealloc(aReconPitClosed);
  *(_DWORD *)(a1 + 1984) = 150;
  *(_DWORD *)(a1 + 1988) = 30;
  *(_DWORD *)(a1 + 1992) = 900;
  StringCopyWithBufferRealloc(aTimeThatPitsAr);
  *(_DWORD *)(a1 + 1980) = 150;
  ShortComputation_1b70((void *)(a1 + 1960));
  StringCopyWithBufferRealloc(aReconTimer);
  *(_BYTE *)(a1 + 2017) = 1;
  *(_BYTE *)(a1 + 2018) = 0;
  *(_BYTE *)(a1 + 2019) = 1;
  StringCopyWithBufferRealloc(aWhetherTimerIs);
  *(_BYTE *)(a1 + 2016) = 1;
  ShortComputation_1b70((void *)(a1 + 1996));
  v42 = 0;
  v60 = (_DWORD *)(a1 + 2044);
  do
  {
    sub_4AA1E0(v42, aReconnaissance, v81);
    StringCopyWithBufferRealloc(v81);
    *v60 = 0;
    v60[1] = 0;
    v60[2] = 12;
    StringCopyWithBufferRealloc(aReconnaissance_0);
    *(v60 - 1) = 0;
    ShortComputation_1b70(v60 - 6);
    v3 = ++v42 < 7;
    v60 += 9;
  }
  while ( v3 );
  for ( i = 0; i < 7; ++i )
  {
    sub_4AA1E0(i, aGridWalkthroug, v81);
    StringCopyWithBufferRealloc(v81);
    if ( i == 5 )
    {
      v4 = (_DWORD *)(a1 + 2452);
      *(_DWORD *)(a1 + 2476) = 0;
      *(_DWORD *)(a1 + 2472) = 0;
    }
    else
    {
      v4 = (_DWORD *)(a1 + 36 * i + 2272);
      v4[6] = 1;
      v4[5] = 1;
    }
    v4[8] = 1;
    v4[7] = 0;
    ShortComputation_1b70(v4);
  }
  v44 = 0;
  v61 = (_DWORD *)(a1 + 2548);
  do
  {
    sub_4AA1E0(v44, aFormationLap, v81);
    StringCopyWithBufferRealloc(v81);
    *v61 = 0;
    v61[1] = 0;
    v61[2] = 1;
    *(v61 - 1) = 0;
    ShortComputation_1b70(v61 - 6);
    v3 = ++v44 < 7;
    v61 += 9;
  }
  while ( v3 );
  v45 = 0;
  v62 = (_DWORD *)(a1 + 2800);
  do
  {
    sub_4AA1E0(v45, aFlagRules, v81);
    StringCopyWithBufferRealloc(v81);
    *v62 = 1;
    v62[1] = 0;
    v62[2] = 1;
    StringCopyWithBufferRealloc(aLevelOfRuleEnf);
    *(v62 - 1) = 1;
    ShortComputation_1b70(v62 - 6);
    v3 = ++v45 < 7;
    v62 += 9;
  }
  while ( v3 );
  v46 = 0;
  v63 = (_DWORD *)(a1 + 3052);
  do
  {
    sub_4AA1E0(v46, aWeather_1, v81);
    StringCopyWithBufferRealloc(v81);
    *v63 = 0;
    v63[1] = 0;
    v63[2] = 5;
    StringCopyWithBufferRealloc(aRandomSeasonSu);
    *(v63 - 1) = 0;
    ShortComputation_1b70(v63 - 6);
    v3 = ++v46 < 7;
    v63 += 9;
  }
  while ( v3 );
  v47 = 0;
  v64 = (_BYTE *)(a1 + 3301);
  do
  {
    sub_4AA1E0(v47, aTimescaledweat, v81);
    StringCopyWithBufferRealloc(v81);
    *v64 = 1;
    v64[1] = 0;
    v64[2] = 1;
    StringCopyWithBufferRealloc(aWhetherWeather);
    *(v64 - 1) = 1;
    ShortComputation_1b70(v64 - 21);
    v3 = ++v47 < 7;
    v64 += 24;
  }
  while ( v3 );
  SettingsPathBuilder((void *)(a1 + 3448), (int)aSoundOptions);
  StringCopyWithBufferRealloc(aMaximumEffects);
  *(_DWORD *)(a1 + 3484) = 16;
  *(_DWORD *)(a1 + 3488) = 1;
  *(_DWORD *)(a1 + 3492) = 64;
  StringCopyWithBufferRealloc(aMaximumSoundEf);
  *(_DWORD *)(a1 + 3480) = 16;
  ShortComputation_1b70((void *)(a1 + 3460));
  StringCopyWithBufferRealloc(aMusic);
  *(_DWORD *)(a1 + 3520) = 1;
  *(_DWORD *)(a1 + 3524) = 0;
  *(_DWORD *)(a1 + 3528) = 1;
  StringCopyWithBufferRealloc(aMusicToggle);
  *(_DWORD *)(a1 + 3516) = 1;
  ShortComputation_1b70((void *)(a1 + 3496));
  StringCopyWithBufferRealloc(aMinAnnouncerPa);
  *(_DWORD *)(a1 + 3556) = 1;
  *(_DWORD *)(a1 + 3560) = 0;
  *(_DWORD *)(a1 + 3564) = 6;
  StringCopyWithBufferRealloc(aInSeconds);
  *(_DWORD *)(a1 + 3552) = 1;
  ShortComputation_1b70((void *)(a1 + 3532));
  StringCopyWithBufferRealloc(aTrackLoadComme);
  *(_BYTE *)(a1 + 3589) = 1;
  *(_BYTE *)(a1 + 3590) = 0;
  *(_BYTE *)(a1 + 3591) = 1;
  StringCopyWithBufferRealloc(aWhetherOrNotTh);
  *(_BYTE *)(a1 + 3588) = 1;
  ShortComputation_1b70((void *)(a1 + 3568));
  StringCopyWithBufferRealloc(aRealtimeInMoni);
  *(_BYTE *)(a1 + 3613) = 1;
  *(_BYTE *)(a1 + 3614) = 0;
  *(_BYTE *)(a1 + 3615) = 1;
  StringCopyWithBufferRealloc(aWhetherToPlayR);
  *(_BYTE *)(a1 + 3612) = 1;
  ShortComputation_1b70((void *)(a1 + 3592));
  StringCopyWithBufferRealloc(aSoundfxVolume);
  *(_DWORD *)(a1 + 3640) = 1065353216;
  *(_DWORD *)(a1 + 3644) = 0;
  *(_DWORD *)(a1 + 3648) = 1065353216;
  StringCopyWithBufferRealloc(a0010);
  *(_DWORD *)(a1 + 3636) = 1065353216;
  ShortComputation_1b70((void *)(a1 + 3616));
  StringCopyWithBufferRealloc(aEngineVolume);
  *(_DWORD *)(a1 + 3676) = 1065353216;
  *(_DWORD *)(a1 + 3680) = 0;
  *(_DWORD *)(a1 + 3684) = 1065353216;
  StringCopyWithBufferRealloc(a0010);
  *(_DWORD *)(a1 + 3672) = 1065353216;
  ShortComputation_1b70((void *)(a1 + 3652));
  StringCopyWithBufferRealloc(aTractionContro_1);
  *(_DWORD *)(a1 + 3712) = 1071644672;
  *(_DWORD *)(a1 + 3716) = 0;
  *(_DWORD *)(a1 + 3720) = 1098907648;
  StringCopyWithBufferRealloc(aVolumeMultipli);
  *(_DWORD *)(a1 + 3708) = 1071644672;
  ShortComputation_1b70((void *)(a1 + 3688));
  StringCopyWithBufferRealloc(aPlayerVolumeRa);
  *(_DWORD *)(a1 + 3748) = 1065353216;
  *(_DWORD *)(a1 + 3752) = 0;
  *(_DWORD *)(a1 + 3756) = 1082130432;
  StringCopyWithBufferRealloc(aAdditionalVolu);
  *(_DWORD *)(a1 + 3744) = 1065353216;
  ShortComputation_1b70((void *)(a1 + 3724));
  StringCopyWithBufferRealloc(aOtherVolumeRat);
  *(_DWORD *)(a1 + 3784) = 1065353216;
  *(_DWORD *)(a1 + 3788) = 0;
  *(_DWORD *)(a1 + 3792) = 1082130432;
  StringCopyWithBufferRealloc(aAdditionalVolu_0);
  *(_DWORD *)(a1 + 3780) = 1065353216;
  ShortComputation_1b70((void *)(a1 + 3760));
  StringCopyWithBufferRealloc(aMusicVolume);
  *(_DWORD *)(a1 + 3820) = 1051931443;
  *(_DWORD *)(a1 + 3824) = 0;
  *(_DWORD *)(a1 + 3828) = 1065353216;
  StringCopyWithBufferRealloc(a0010);
  *(_DWORD *)(a1 + 3816) = 1051931443;
  ShortComputation_1b70((void *)(a1 + 3796));
  StringCopyWithBufferRealloc(aPitVolume);
  *(_DWORD *)(a1 + 3856) = 1056964608;
  *(_DWORD *)(a1 + 3860) = 0;
  *(_DWORD *)(a1 + 3864) = 1065353216;
  StringCopyWithBufferRealloc(a0010ControlsVo);
  *(_DWORD *)(a1 + 3852) = 1056964608;
  ShortComputation_1b70((void *)(a1 + 3832));
  StringCopyWithBufferRealloc(aAnnouncerVolum);
  *(_DWORD *)(a1 + 3892) = 1056964608;
  *(_DWORD *)(a1 + 3896) = 0;
  *(_DWORD *)(a1 + 3900) = 1065353216;
  StringCopyWithBufferRealloc(a0010);
  *(_DWORD *)(a1 + 3888) = 1056964608;
  ShortComputation_1b70((void *)(a1 + 3868));
  StringCopyWithBufferRealloc(aSoundDetail);
  *(_DWORD *)(a1 + 4468) = 0;
  *(_DWORD *)(a1 + 4472) = 0;
  *(_DWORD *)(a1 + 4476) = 3;
  *(_DWORD *)(a1 + 4464) = 0;
  ShortComputation_1b70((void *)(a1 + 4444));
  StringCopyWithBufferRealloc(aCrowdRange);
  *(_DWORD *)(a1 + 3928) = 1117126656;
  *(_DWORD *)(a1 + 3932) = 1075838976;
  *(_DWORD *)(a1 + 3936) = 1167867904;
  StringCopyWithBufferRealloc(aVolumeRangePar);
  *(_DWORD *)(a1 + 3924) = 1117126656;
  ShortComputation_1b70((void *)(a1 + 3904));
  StringCopyWithBufferRealloc(aCrowdShape);
  *(_DWORD *)(a1 + 3964) = 1061158912;
  *(_DWORD *)(a1 + 3968) = 0;
  *(_DWORD *)(a1 + 3972) = 1065353216;
  StringCopyWithBufferRealloc(aShapeOfVolumeA);
  *(_DWORD *)(a1 + 3960) = 1061158912;
  ShortComputation_1b70((void *)(a1 + 3940));
  StringCopyWithBufferRealloc(aCrowdAmbient);
  *(_DWORD *)(a1 + 4000) = 1075838976;
  *(_DWORD *)(a1 + 4004) = 1036831949;
  *(_DWORD *)(a1 + 4008) = 1149239296;
  StringCopyWithBufferRealloc(aAmbientRangeWh);
  *(_DWORD *)(a1 + 3996) = 1075838976;
  ShortComputation_1b70((void *)(a1 + 3976));
  StringCopyWithBufferRealloc(aAirhornRange);
  *(_DWORD *)(a1 + 4036) = 1117126656;
  *(_DWORD *)(a1 + 4040) = 1075838976;
  *(_DWORD *)(a1 + 4044) = 1167867904;
  *(_DWORD *)(a1 + 4032) = 1117126656;
  ShortComputation_1b70((void *)(a1 + 4012));
  StringCopyWithBufferRealloc(aAirhornShape);
  *(_DWORD *)(a1 + 4072) = 1061158912;
  *(_DWORD *)(a1 + 4076) = 0;
  *(_DWORD *)(a1 + 4080) = 1065353216;
  *(_DWORD *)(a1 + 4068) = 1061158912;
  ShortComputation_1b70((void *)(a1 + 4048));
  StringCopyWithBufferRealloc(aAirhornAmbient);
  *(_DWORD *)(a1 + 4108) = 1075838976;
  *(_DWORD *)(a1 + 4112) = 1036831949;
  *(_DWORD *)(a1 + 4116) = 1149239296;
  *(_DWORD *)(a1 + 4104) = 1075838976;
  ShortComputation_1b70((void *)(a1 + 4084));
  StringCopyWithBufferRealloc(aPublicAddressR);
  *(_DWORD *)(a1 + 4144) = 1112014848;
  *(_DWORD *)(a1 + 4148) = 1075838976;
  *(_DWORD *)(a1 + 4152) = 1167867904;
  *(_DWORD *)(a1 + 4140) = 1112014848;
  ShortComputation_1b70((void *)(a1 + 4120));
  StringCopyWithBufferRealloc(aPublicAddressS);
  *(_DWORD *)(a1 + 4180) = 1061158912;
  *(_DWORD *)(a1 + 4184) = 0;
  *(_DWORD *)(a1 + 4188) = 1065353216;
  *(_DWORD *)(a1 + 4176) = 1061158912;
  ShortComputation_1b70((void *)(a1 + 4156));
  StringCopyWithBufferRealloc(aPublicAddressA);
  *(_DWORD *)(a1 + 4216) = 1075838976;
  *(_DWORD *)(a1 + 4220) = 1036831949;
  *(_DWORD *)(a1 + 4224) = 1149239296;
  *(_DWORD *)(a1 + 4212) = 1075838976;
  ShortComputation_1b70((void *)(a1 + 4192));
  StringCopyWithBufferRealloc(aPithornRange);
  *(_DWORD *)(a1 + 4252) = 1106247680;
  *(_DWORD *)(a1 + 4256) = 1075838976;
  *(_DWORD *)(a1 + 4260) = 1167867904;
  *(_DWORD *)(a1 + 4248) = 1106247680;
  ShortComputation_1b70((void *)(a1 + 4228));
  StringCopyWithBufferRealloc(aPithornShape);
  *(_DWORD *)(a1 + 4288) = 1055286886;
  *(_DWORD *)(a1 + 4292) = 0;
  *(_DWORD *)(a1 + 4296) = 1065353216;
  *(_DWORD *)(a1 + 4284) = 1055286886;
  ShortComputation_1b70((void *)(a1 + 4264));
  StringCopyWithBufferRealloc(aPithornAmbient);
  *(_DWORD *)(a1 + 4324) = 1069547520;
  *(_DWORD *)(a1 + 4328) = 1036831949;
  *(_DWORD *)(a1 + 4332) = 1149239296;
  *(_DWORD *)(a1 + 4320) = 1069547520;
  ShortComputation_1b70((void *)(a1 + 4300));
  StringCopyWithBufferRealloc(aHelicopterRang);
  *(_DWORD *)(a1 + 4360) = 1117126656;
  *(_DWORD *)(a1 + 4364) = 1075838976;
  *(_DWORD *)(a1 + 4368) = 1167867904;
  *(_DWORD *)(a1 + 4356) = 1117126656;
  ShortComputation_1b70((void *)(a1 + 4336));
  StringCopyWithBufferRealloc(aHelicopterShap);
  *(_DWORD *)(a1 + 4396) = 1060320051;
  *(_DWORD *)(a1 + 4400) = 0;
  *(_DWORD *)(a1 + 4404) = 1065353216;
  *(_DWORD *)(a1 + 4392) = 1060320051;
  ShortComputation_1b70((void *)(a1 + 4372));
  StringCopyWithBufferRealloc(aHelicopterAmbi);
  *(_DWORD *)(a1 + 4432) = 1075838976;
  *(_DWORD *)(a1 + 4436) = 1036831949;
  *(_DWORD *)(a1 + 4440) = 1149239296;
  *(_DWORD *)(a1 + 4428) = 1075838976;
  ShortComputation_1b70((void *)(a1 + 4408));
  SettingsPathBuilder((void *)(a1 + 4480), (int)aGraphicOptions);
  StringCopyWithBufferRealloc(aBroadcastOverl);
  *(_DWORD *)(a1 + 4516) = 1;
  *(_DWORD *)(a1 + 4520) = 0;
  *(_DWORD *)(a1 + 4524) = 1;
  *(_DWORD *)(a1 + 4512) = 1;
  ShortComputation_1b70((void *)(a1 + 4492));
  v78 = dword_5EC4AC;
  StringCopyWithBufferRealloc(aTextureDetail);
  *(_DWORD *)(a1 + 4552) = v78;
  *(_DWORD *)(a1 + 4556) = 0;
  *(_DWORD *)(a1 + 4560) = 4;
  *(_DWORD *)(a1 + 4548) = v78;
  ShortComputation_1b70((void *)(a1 + 4528));
  StringCopyWithBufferRealloc(aRearview_0);
  *(_DWORD *)(a1 + 4588) = 0;
  *(_DWORD *)(a1 + 4592) = 0;
  *(_DWORD *)(a1 + 4596) = 1;
  *(_DWORD *)(a1 + 4584) = 0;
  ShortComputation_1b70((void *)(a1 + 4564));
  StringCopyWithBufferRealloc(aRearviewWidth);
  *(_DWORD *)(a1 + 4624) = 1115684864;
  *(_DWORD *)(a1 + 4628) = 1048576000;
  *(_DWORD *)(a1 + 4632) = 1127481344;
  *(_DWORD *)(a1 + 4620) = 1115684864;
  ShortComputation_1b70((void *)(a1 + 4600));
  StringCopyWithBufferRealloc(aRearviewHeight);
  *(_DWORD *)(a1 + 4660) = 1096810496;
  *(_DWORD *)(a1 + 4664) = 1048576000;
  *(_DWORD *)(a1 + 4668) = 1127481344;
  *(_DWORD *)(a1 + 4656) = 1096810496;
  ShortComputation_1b70((void *)(a1 + 4636));
  StringCopyWithBufferRealloc(aRearviewPartic);
  *(_DWORD *)(a1 + 4696) = 0;
  *(_DWORD *)(a1 + 4700) = 0;
  *(_DWORD *)(a1 + 4704) = 1;
  *(_DWORD *)(a1 + 4692) = 0;
  ShortComputation_1b70((void *)(a1 + 4672));
  StringCopyWithBufferRealloc(aSelfInRearview);
  *(_BYTE *)(a1 + 4729) = 0;
  *(_BYTE *)(a1 + 4730) = 0;
  *(_BYTE *)(a1 + 4731) = 1;
  StringCopyWithBufferRealloc(aShowRearWingAn);
  *(_BYTE *)(a1 + 4728) = 0;
  ShortComputation_1b70((void *)(a1 + 4708));
  StringCopyWithBufferRealloc(aVehicleSparks);
  *(_BYTE *)(a1 + 4753) = 0;
  *(_BYTE *)(a1 + 4754) = 0;
  *(_BYTE *)(a1 + 4755) = 1;
  StringCopyWithBufferRealloc(aWhetherSparksO);
  *(_BYTE *)(a1 + 4752) = 0;
  ShortComputation_1b70((void *)(a1 + 4732));
  StringCopyWithBufferRealloc(aBackfireAnimSp);
  *(_DWORD *)(a1 + 4780) = 1106247680;
  *(_DWORD *)(a1 + 4784) = 1065353216;
  *(_DWORD *)(a1 + 4788) = 1124073472;
  *(_DWORD *)(a1 + 4776) = 1106247680;
  ShortComputation_1b70((void *)(a1 + 4756));
  StringCopyWithBufferRealloc(aMovingSteering);
  *(_DWORD *)(a1 + 4816) = 1;
  *(_DWORD *)(a1 + 4820) = 0;
  *(_DWORD *)(a1 + 4824) = 2;
  *(_DWORD *)(a1 + 4812) = 1;
  ShortComputation_1b70((void *)(a1 + 4792));
  StringCopyWithBufferRealloc(&off_5D11C0);
  *(_DWORD *)(a1 + 4852) = 1;
  *(_DWORD *)(a1 + 4856) = 0;
  *(_DWORD *)(a1 + 4860) = 1;
  *(_DWORD *)(a1 + 4848) = 1;
  ShortComputation_1b70((void *)(a1 + 4828));
  StringCopyWithBufferRealloc(aLcdDisplayMode);
  *(_DWORD *)(a1 + 4888) = 3;
  *(_DWORD *)(a1 + 4892) = 0;
  *(_DWORD *)(a1 + 4896) = 7;
  StringCopyWithBufferRealloc(aAddTheModesToA);
  *(_DWORD *)(a1 + 4884) = 3;
  ShortComputation_1b70((void *)(a1 + 4864));
  StringCopyWithBufferRealloc(aAutomap);
  *(_DWORD *)(a1 + 4924) = 1;
  *(_DWORD *)(a1 + 4928) = 0;
  *(_DWORD *)(a1 + 4932) = 1;
  *(_DWORD *)(a1 + 4920) = 1;
  ShortComputation_1b70((void *)(a1 + 4900));
  v79 = dword_5EC4A8;
  StringCopyWithBufferRealloc(aPlayerDetail);
  *(_DWORD *)(a1 + 4960) = v79;
  *(_DWORD *)(a1 + 4964) = 0;
  *(_DWORD *)(a1 + 4968) = 3;
  *(_DWORD *)(a1 + 4956) = v79;
  ShortComputation_1b70((void *)(a1 + 4936));
  v80 = dword_5EC4A8;
  StringCopyWithBufferRealloc(aOpponentDetail);
  *(_DWORD *)(a1 + 4996) = v80;
  *(_DWORD *)(a1 + 5000) = 0;
  *(_DWORD *)(a1 + 5004) = 3;
  *(_DWORD *)(a1 + 4992) = v80;
  ShortComputation_1b70((void *)(a1 + 4972));
  StringCopyWithBufferRealloc(aGarageDetail);
  *(_DWORD *)(a1 + 5032) = 1056964608;
  *(_DWORD *)(a1 + 5036) = 0;
  *(_DWORD *)(a1 + 5040) = 1065353216;
  StringCopyWithBufferRealloc(aLodMultiplierW);
  *(_DWORD *)(a1 + 5028) = 1056964608;
  ShortComputation_1b70((void *)(a1 + 5008));
  StringCopyWithBufferRealloc(aShadows);
  *(_DWORD *)(a1 + 5068) = 1;
  *(_DWORD *)(a1 + 5072) = 0;
  *(_DWORD *)(a1 + 5076) = 3;
  *(_DWORD *)(a1 + 5064) = 1;
  ShortComputation_1b70((void *)(a1 + 5044));
  StringCopyWithBufferRealloc(aPitcrewDetail);
  *(_DWORD *)(a1 + 5104) = 1;
  *(_DWORD *)(a1 + 5108) = 0;
  *(_DWORD *)(a1 + 5112) = 3;
  *(_DWORD *)(a1 + 5100) = 1;
  ShortComputation_1b70((void *)(a1 + 5080));
  StringCopyWithBufferRealloc(aSpecialFx);
  *(_DWORD *)(a1 + 5140) = 1;
  *(_DWORD *)(a1 + 5144) = 0;
  *(_DWORD *)(a1 + 5148) = 4;
  *(_DWORD *)(a1 + 5136) = 1;
  ShortComputation_1b70((void *)(a1 + 5116));
  StringCopyWithBufferRealloc(aLightningProba);
  *(_DWORD *)(a1 + 5176) = 1065353216;
  *(_DWORD *)(a1 + 5180) = 0;
  *(_DWORD *)(a1 + 5184) = 1069547520;
  StringCopyWithBufferRealloc(aProbabilityOfS);
  *(_DWORD *)(a1 + 5172) = 1065353216;
  ShortComputation_1b70((void *)(a1 + 5152));
  StringCopyWithBufferRealloc(aThunderProbabi);
  *(_DWORD *)(a1 + 5212) = 1069547520;
  *(_DWORD *)(a1 + 5216) = 0;
  *(_DWORD *)(a1 + 5220) = 1069547520;
  StringCopyWithBufferRealloc(aProbabilityOfH);
  *(_DWORD *)(a1 + 5208) = 1069547520;
  ShortComputation_1b70((void *)(a1 + 5188));
  StringCopyWithBufferRealloc(aCloudScroll);
  *(_DWORD *)(a1 + 5248) = 0;
  *(_DWORD *)(a1 + 5252) = 0;
  *(_DWORD *)(a1 + 5256) = 1008981770;
  StringCopyWithBufferRealloc(aMaximumCloudSc);
  *(_DWORD *)(a1 + 5244) = 0;
  ShortComputation_1b70((void *)(a1 + 5224));
  StringCopyWithBufferRealloc(aCloudBlend);
  *(_BYTE *)(a1 + 5281) = 0;
  *(_BYTE *)(a1 + 5282) = 0;
  *(_BYTE *)(a1 + 5283) = 1;
  StringCopyWithBufferRealloc(aWhetherToRollT);
  *(_BYTE *)(a1 + 5280) = 0;
  ShortComputation_1b70((void *)(a1 + 5260));
  StringCopyWithBufferRealloc(aSkyboxPosition);
  *(_DWORD *)(a1 + 5308) = 1064682127;
  *(_DWORD *)(a1 + 5312) = 0;
  *(_DWORD *)(a1 + 5316) = 1065353216;
  StringCopyWithBufferRealloc(aNumbersLessTha);
  *(_DWORD *)(a1 + 5304) = 1064682127;
  ShortComputation_1b70((void *)(a1 + 5284));
  StringCopyWithBufferRealloc(aVehicleFlowRad);
  *(_DWORD *)(a1 + 5344) = 1082130432;
  *(_DWORD *)(a1 + 5348) = 1036831949;
  *(_DWORD *)(a1 + 5352) = 2139095039;
  StringCopyWithBufferRealloc(aVehicleSphereR);
  *(_DWORD *)(a1 + 5340) = 1082130432;
  ShortComputation_1b70((void *)(a1 + 5320));
  StringCopyWithBufferRealloc(aVehicleFlowOff);
  *(_DWORD *)(a1 + 5380) = 1078355558;
  *(_DWORD *)(a1 + 5384) = -8388609;
  *(_DWORD *)(a1 + 5388) = 2139095039;
  StringCopyWithBufferRealloc(aOffsetBelowVeh);
  *(_DWORD *)(a1 + 5376) = 1078355558;
  ShortComputation_1b70((void *)(a1 + 5356));
  StringCopyWithBufferRealloc(aEngineEmitterF);
  *(_BYTE *)(a1 + 5413) = 0;
  *(_BYTE *)(a1 + 5414) = 0;
  *(_BYTE *)(a1 + 5415) = 1;
  StringCopyWithBufferRealloc(aWhetherEngineS);
  *(_BYTE *)(a1 + 5412) = 0;
  ShortComputation_1b70((void *)(a1 + 5392));
  StringCopyWithBufferRealloc(aTireEmitterFlo);
  *(_BYTE *)(a1 + 5437) = 0;
  *(_BYTE *)(a1 + 5438) = 0;
  *(_BYTE *)(a1 + 5439) = 1;
  StringCopyWithBufferRealloc(aWhetherTireSmo);
  *(_BYTE *)(a1 + 5436) = 0;
  ShortComputation_1b70((void *)(a1 + 5416));
  StringCopyWithBufferRealloc(aSmokeFlow);
  *(_BYTE *)(a1 + 5461) = 0;
  *(_BYTE *)(a1 + 5462) = 0;
  *(_BYTE *)(a1 + 5463) = 1;
  StringCopyWithBufferRealloc(aWhetherAllSmok);
  *(_BYTE *)(a1 + 5460) = 0;
  ShortComputation_1b70((void *)(a1 + 5440));
  StringCopyWithBufferRealloc(aRaindropFlow);
  *(_DWORD *)(a1 + 5488) = 0;
  *(_DWORD *)(a1 + 5492) = 0;
  *(_DWORD *)(a1 + 5496) = 3;
  StringCopyWithBufferRealloc(aAddToEnable1Fl);
  *(_DWORD *)(a1 + 5484) = 0;
  ShortComputation_1b70((void *)(a1 + 5464));
  StringCopyWithBufferRealloc(aRainsprayFlow);
  *(_DWORD *)(a1 + 5524) = 0;
  *(_DWORD *)(a1 + 5528) = 0;
  *(_DWORD *)(a1 + 5532) = 3;
  StringCopyWithBufferRealloc(aAddToEnable1Fl);
  *(_DWORD *)(a1 + 5520) = 0;
  ShortComputation_1b70((void *)(a1 + 5500));
  StringCopyWithBufferRealloc(aSparkFlow);
  *(_DWORD *)(a1 + 5560) = 0;
  *(_DWORD *)(a1 + 5564) = 0;
  *(_DWORD *)(a1 + 5568) = 3;
  StringCopyWithBufferRealloc(aAddToEnable1Fl);
  *(_DWORD *)(a1 + 5556) = 0;
  ShortComputation_1b70((void *)(a1 + 5536));
  StringCopyWithBufferRealloc(aGlanceRate);
  *(_DWORD *)(a1 + 5596) = 1088421888;
  *(_DWORD *)(a1 + 5600) = 0;
  *(_DWORD *)(a1 + 5604) = 2139095039;
  StringCopyWithBufferRealloc(aRateToFollowCo);
  *(_DWORD *)(a1 + 5592) = 1088421888;
  ShortComputation_1b70((void *)(a1 + 5572));
  StringCopyWithBufferRealloc(aLookUpDownAngl);
  *(_DWORD *)(a1 + 5632) = 1061158912;
  *(_DWORD *)(a1 + 5636) = -8388609;
  *(_DWORD *)(a1 + 5640) = 2139095039;
  StringCopyWithBufferRealloc(aAngleToLookUpD);
  *(_DWORD *)(a1 + 5628) = 1061158912;
  ShortComputation_1b70((void *)(a1 + 5608));
  StringCopyWithBufferRealloc(aLeanaheadAngle);
  *(_DWORD *)(a1 + 5668) = 0;
  *(_DWORD *)(a1 + 5672) = -8388609;
  *(_DWORD *)(a1 + 5676) = 2139095039;
  StringCopyWithBufferRealloc(aAngleToLeanHea);
  *(_DWORD *)(a1 + 5664) = 0;
  ShortComputation_1b70((void *)(a1 + 5644));
  StringCopyWithBufferRealloc(aLookRollAngle);
  *(_DWORD *)(a1 + 5704) = 1061158912;
  *(_DWORD *)(a1 + 5708) = -8388609;
  *(_DWORD *)(a1 + 5712) = 2139095039;
  StringCopyWithBufferRealloc(aAngleToLeanHea_0);
  *(_DWORD *)(a1 + 5700) = 1061158912;
  ShortComputation_1b70((void *)(a1 + 5680));
  StringCopyWithBufferRealloc(aGlanceAngle);
  *(_DWORD *)(a1 + 5740) = 1061158912;
  *(_DWORD *)(a1 + 5744) = -8388609;
  *(_DWORD *)(a1 + 5748) = 2139095039;
  StringCopyWithBufferRealloc(aAngleToLookLef);
  *(_DWORD *)(a1 + 5736) = 1061158912;
  ShortComputation_1b70((void *)(a1 + 5716));
  StringCopyWithBufferRealloc(aLookaheadAngle);
  *(_DWORD *)(a1 + 5776) = 0;
  *(_DWORD *)(a1 + 5780) = -8388609;
  *(_DWORD *)(a1 + 5784) = 2139095039;
  StringCopyWithBufferRealloc(aAngleToLookahe);
  *(_DWORD *)(a1 + 5772) = 0;
  ShortComputation_1b70((void *)(a1 + 5752));
  StringCopyWithBufferRealloc(aHeadPhysics);
  *(_DWORD *)(a1 + 5812) = 1061158912;
  *(_DWORD *)(a1 + 5816) = 0;
  *(_DWORD *)(a1 + 5820) = 1132462080;
  StringCopyWithBufferRealloc(aFractionOfHead);
  *(_DWORD *)(a1 + 5808) = 1061158912;
  ShortComputation_1b70((void *)(a1 + 5788));
  StringCopyWithBufferRealloc(aHeadRotation);
  *(_DWORD *)(a1 + 5848) = 1065353216;
  *(_DWORD *)(a1 + 5852) = 0;
  *(_DWORD *)(a1 + 5856) = 1132462080;
  StringCopyWithBufferRealloc(aAdditionalHead);
  *(_DWORD *)(a1 + 5844) = 1065353216;
  ShortComputation_1b70((void *)(a1 + 5824));
  StringCopyWithBufferRealloc(aTrackDetail);
  *(_DWORD *)(a1 + 5884) = 1;
  *(_DWORD *)(a1 + 5888) = 0;
  *(_DWORD *)(a1 + 5892) = 3;
  *(_DWORD *)(a1 + 5880) = 1;
  ShortComputation_1b70((void *)(a1 + 5860));
  StringCopyWithBufferRealloc(aGroove_0);
  *(_DWORD *)(a1 + 5920) = 1;
  *(_DWORD *)(a1 + 5924) = 0;
  *(_DWORD *)(a1 + 5928) = 1;
  *(_DWORD *)(a1 + 5916) = 1;
  ShortComputation_1b70((void *)(a1 + 5896));
  StringCopyWithBufferRealloc(aEnvironmentMap);
  *(_DWORD *)(a1 + 5956) = 0;
  *(_DWORD *)(a1 + 5960) = 0;
  *(_DWORD *)(a1 + 5964) = 1;
  *(_DWORD *)(a1 + 5952) = 0;
  ShortComputation_1b70((void *)(a1 + 5932));
  StringCopyWithBufferRealloc(aMipMapping);
  *(_DWORD *)(a1 + 5992) = 1;
  *(_DWORD *)(a1 + 5996) = 0;
  *(_DWORD *)(a1 + 6000) = 1;
  *(_DWORD *)(a1 + 5988) = 1;
  ShortComputation_1b70((void *)(a1 + 5968));
  StringCopyWithBufferRealloc(aCompressedText);
  *(_DWORD *)(a1 + 6028) = 1;
  *(_DWORD *)(a1 + 6032) = 0;
  *(_DWORD *)(a1 + 6036) = 1;
  *(_DWORD *)(a1 + 6024) = 1;
  ShortComputation_1b70((void *)(a1 + 6004));
  StringCopyWithBufferRealloc(aSpecular_0);
  *(_DWORD *)(a1 + 6064) = 1;
  *(_DWORD *)(a1 + 6068) = 0;
  *(_DWORD *)(a1 + 6072) = 1;
  *(_DWORD *)(a1 + 6060) = 1;
  ShortComputation_1b70((void *)(a1 + 6040));
  StringCopyWithBufferRealloc(aDynamicLightin);
  *(_DWORD *)(a1 + 6100) = 1;
  *(_DWORD *)(a1 + 6104) = 0;
  *(_DWORD *)(a1 + 6108) = 2;
  *(_DWORD *)(a1 + 6096) = 1;
  ShortComputation_1b70((void *)(a1 + 6076));
  StringCopyWithBufferRealloc(aMaxVisibleVehi);
  *(_DWORD *)(a1 + 6136) = 260;
  *(_DWORD *)(a1 + 6140) = 1;
  *(_DWORD *)(a1 + 6144) = 260;
  *(_DWORD *)(a1 + 6132) = 260;
  ShortComputation_1b70((void *)(a1 + 6112));
  StringCopyWithBufferRealloc(aMapOppdetailTo);
  *(_BYTE *)(a1 + 6169) = 1;
  *(_BYTE *)(a1 + 6170) = 0;
  *(_BYTE *)(a1 + 6171) = 1;
  StringCopyWithBufferRealloc(aMapOpponentDet);
  *(_BYTE *)(a1 + 6168) = 1;
  ShortComputation_1b70((void *)(a1 + 6148));
  StringCopyWithBufferRealloc(aShadowsInTvCoc);
  *(_DWORD *)(a1 + 6196) = 1;
  *(_DWORD *)(a1 + 6200) = 0;
  *(_DWORD *)(a1 + 6204) = 1;
  *(_DWORD *)(a1 + 6192) = 1;
  ShortComputation_1b70((void *)(a1 + 6172));
  StringCopyWithBufferRealloc(aWheelsVisibleI);
  *(_DWORD *)(a1 + 6232) = 1;
  *(_DWORD *)(a1 + 6236) = 0;
  *(_DWORD *)(a1 + 6240) = 1;
  *(_DWORD *)(a1 + 6228) = 1;
  ShortComputation_1b70((void *)(a1 + 6208));
  StringCopyWithBufferRealloc(aInCarDash);
  *(_DWORD *)(a1 + 6268) = 2;
  *(_DWORD *)(a1 + 6272) = 0;
  *(_DWORD *)(a1 + 6276) = 2;
  *(_DWORD *)(a1 + 6264) = 2;
  ShortComputation_1b70((void *)(a1 + 6244));
  StringCopyWithBufferRealloc(aDustDetail);
  *(_DWORD *)(a1 + 6304) = 2;
  *(_DWORD *)(a1 + 6308) = 0;
  *(_DWORD *)(a1 + 6312) = 4;
  *(_DWORD *)(a1 + 6300) = 2;
  ShortComputation_1b70((void *)(a1 + 6280));
  StringCopyWithBufferRealloc(aSmokeDetail);
  *(_DWORD *)(a1 + 6340) = 2;
  *(_DWORD *)(a1 + 6344) = 0;
  *(_DWORD *)(a1 + 6348) = 4;
  *(_DWORD *)(a1 + 6336) = 2;
  ShortComputation_1b70((void *)(a1 + 6316));
  StringCopyWithBufferRealloc(aSkidDetail);
  *(_DWORD *)(a1 + 6376) = 2;
  *(_DWORD *)(a1 + 6380) = 0;
  *(_DWORD *)(a1 + 6384) = 4;
  *(_DWORD *)(a1 + 6372) = 2;
  ShortComputation_1b70((void *)(a1 + 6352));
  StringCopyWithBufferRealloc(aParticleDetail);
  *(_DWORD *)(a1 + 6412) = 2;
  *(_DWORD *)(a1 + 6416) = 0;
  *(_DWORD *)(a1 + 6420) = 4;
  *(_DWORD *)(a1 + 6408) = 2;
  ShortComputation_1b70((void *)(a1 + 6388));
  StringCopyWithBufferRealloc(aStartingView);
  *(_DWORD *)(a1 + 6448) = 0;
  *(_DWORD *)(a1 + 6452) = 0;
  *(_DWORD *)(a1 + 6456) = 4;
  *(_DWORD *)(a1 + 6444) = 0;
  ShortComputation_1b70((void *)(a1 + 6424));
  StringCopyWithBufferRealloc(aSkyboxDetail);
  *(_DWORD *)(a1 + 6484) = 2;
  *(_DWORD *)(a1 + 6488) = 0;
  *(_DWORD *)(a1 + 6492) = 2;
  *(_DWORD *)(a1 + 6480) = 2;
  ShortComputation_1b70((void *)(a1 + 6460));
  TripleDispatchWrapper((void *)(a1 + 6496), (int)aPlayerLivery, (int)byte_5EA438, (int)aOverridesDefau);
  StringCopyWithBufferRealloc(aMipmapLodSpeed);
  *(_DWORD *)(a1 + 6548) = 1120403456;
  *(_DWORD *)(a1 + 6552) = 1065353216;
  *(_DWORD *)(a1 + 6556) = 2139095039;
  StringCopyWithBufferRealloc(aSpeedMphAtWhic);
  *(_DWORD *)(a1 + 6544) = 1120403456;
  ShortComputation_1b70((void *)(a1 + 6524));
  StringCopyWithBufferRealloc(aMipmapLodBias);
  *(_DWORD *)(a1 + 6584) = 0;
  *(_DWORD *)(a1 + 6588) = -1073741824;
  *(_DWORD *)(a1 + 6592) = 1084227584;
  StringCopyWithBufferRealloc(byte_5EA438);
  *(_DWORD *)(a1 + 6580) = 0;
  ShortComputation_1b70((void *)(a1 + 6560));
  StringCopyWithBufferRealloc(aAllowHudInCock);
  *(_BYTE *)(a1 + 6617) = 1;
  *(_BYTE *)(a1 + 6618) = 0;
  *(_BYTE *)(a1 + 6619) = 1;
  *(_BYTE *)(a1 + 6616) = 1;
  ShortComputation_1b70((void *)(a1 + 6596));
  StringCopyWithBufferRealloc(aAllowSwingmanI);
  *(_BYTE *)(a1 + 6641) = 0;
  *(_BYTE *)(a1 + 6642) = 0;
  *(_BYTE *)(a1 + 6643) = 1;
  *(_BYTE *)(a1 + 6640) = 0;
  ShortComputation_1b70((void *)(a1 + 6620));
  StringCopyWithBufferRealloc(aDisplayIcons);
  *(_DWORD *)(a1 + 6668) = 1;
  *(_DWORD *)(a1 + 6672) = 0;
  *(_DWORD *)(a1 + 6676) = 3;
  StringCopyWithBufferRealloc(aIconsDisplayed);
  *(_DWORD *)(a1 + 6664) = 1;
  ShortComputation_1b70((void *)(a1 + 6644));
  StringCopyWithBufferRealloc(aNightLighting);
  *(_DWORD *)(a1 + 6704) = 1065353216;
  *(_DWORD *)(a1 + 6708) = 0;
  *(_DWORD *)(a1 + 6712) = 1065353216;
  StringCopyWithBufferRealloc(a00NightLightLe);
  *(_DWORD *)(a1 + 6700) = 1065353216;
  ShortComputation_1b70((void *)(a1 + 6680));
  StringCopyWithBufferRealloc(aAlwaysRebuildH);
  *(_BYTE *)(a1 + 6737) = 0;
  *(_BYTE *)(a1 + 6738) = 0;
  *(_BYTE *)(a1 + 6739) = 1;
  StringCopyWithBufferRealloc(aBuildHatDataba);
  *(_BYTE *)(a1 + 6736) = 0;
  ShortComputation_1b70((void *)(a1 + 6716));
  SettingsPathBuilder((void *)(a1 + 6740), (int)aGameOptions);
  StringCopyWithBufferRealloc(aChampionshipBa);
  *(_DWORD *)(a1 + 6776) = 1;
  *(_DWORD *)(a1 + 6780) = 0;
  *(_DWORD *)(a1 + 6784) = 4;
  *(_DWORD *)(a1 + 6772) = 1;
  ShortComputation_1b70((void *)(a1 + 6752));
  StringCopyWithBufferRealloc(aBasicRules);
  *(_DWORD *)(a1 + 6860) = 1;
  *(_DWORD *)(a1 + 6864) = 0;
  *(_DWORD *)(a1 + 6868) = 2;
  *(_DWORD *)(a1 + 6856) = 1;
  ShortComputation_1b70((void *)(a1 + 6836));
  StringCopyWithBufferRealloc(aBasicControls);
  *(_DWORD *)(a1 + 6896) = 0;
  *(_DWORD *)(a1 + 6900) = 0;
  *(_DWORD *)(a1 + 6904) = 3;
  *(_DWORD *)(a1 + 6892) = 0;
  ShortComputation_1b70((void *)(a1 + 6872));
  MultiFieldSetterWithStrings(aBasicDisplay, 2, 0, 4, 0, 1);
  MultiFieldSetterWithStrings(aBasicAudio, 2, 0, 3, 0, 1);
  MultiFieldSetterWithStrings(aTimesCompariso, 1, 0, 3, aAddTheFollowin, 1);
  MultiFieldSetterWithStrings(aDamageMultipli, 1, 0, 200, 0, 1);
  MultiFieldSetterWithStrings(aRecordReplays, 1, 0, 1, aWhetherToRecor, 1);
  MultiFieldSetterWithStrings(aRecordHotlaps, 1, 0, 1, aWhetherToRecor_0, 1);
  MultiFieldSetterWithStrings(aInstantReplayL, 15, 10, 180, 0, 1);
  MultiFieldSetterWithStrings(aReplayFidelity, 3, 0, 4, 0, 1);
  MultiFieldSetterWithStrings(aPrivateTestDay, 1, 0, 1, 0, 1);
  MultiFieldSetterWithStrings(aRaceSession, 0, 0, 7, 0, 1);
  MultiFieldSetterWithStrings(aQuickRaceStart, 101, 0, 101, 0, 1);
  MultiFieldSetterWithStrings(aDamageDynamics, 1, 0, 1, 0, 1);
  MultiFieldSetterWithStrings(aDifficulty, 1, 0, 5, 0, 1);
  MultiFieldSetterWithStrings(aAiDriverStreng, 75, 70, 120, 0, 1);
  MultiFieldSetterWithStrings(aAiPowerCalibra, 7, 0, 7, aAdjustmentsWit, 1);
  MultiFieldSetterWithStringCopy(aAiAdditionalFu, 1064514355, 1036831949, 0x40000000, aAdditionalFuel, 1);
  MultiFieldSetterWithStringCopy(aAiBrakePowerUs, 1065017672, 1036831949, 0x40000000, aFractionOfTheo, 1);
  MultiFieldSetterWithStringCopy(aAiBrakeGripUsa, 1064849900, 1036831949, 0x40000000, aFractionOfTheo_0, 1);
  MultiFieldSetterWithStringCopy(aAiCornerGripUs, 1064178811, 1036831949, 0x40000000, aFractionOfTheo_1, 1);
  MultiFieldSetterWithStringCopy(aAiMaxLoad, 1193033728, 1036831949, 2139095039, aMaximumTotalLo, 1);
  MultiFieldSetterWithStringCopy(aAiMinRadius, 1101004800, 1036831949, 2139095039, aMinimumRadiusT, 1);
  MultiFieldSetterWithStrings(aPlayerCarEqual, 1, 0, 1, 0, 1);
  MultiFieldSetterWithStrings(aMessageCenterD, 3, 0, 3, 0, 1);
  MultiFieldSetterWithStrings(aCommentaryDeta, 2, 0, 3, 0, 1);
  MultiFieldSetterWithStrings(aPlayMovies, 1, 0, 1, 0, 1);
  MultiFieldSetterWithStrings(aLockedPitCam, 1, 0, 1, 0, 1);
  MultiFieldSetterWithStrings(aRaceStintOffse, 0, 0x80000000, 0x7FFFFFFF, aOffsetEachSche, 1);
  MultiFieldSetterWithStrings(aFidelityUnilat, 0, 0, 9999, 0, 1);
  MultiFieldSetterWithStrings(aAutocalibrateA, 0, 0, 3, 0, 1);
  sub_4B1C20(aVehicleSpecifi, 0, 0, 1, aIf1SearchSpeci, 1);
  sub_4B1C20(aDefaultPlayerS, 1, 0, 1, aIf1AttemptsToE, 1);
  MultiFieldSetterWithStringCopy(aAiRealism, 1056964608, 0, 1065353216, 0, 1);
  sub_4B1C20(aDisplayDriverS, 0, 0, 1, 0, 1);
  sub_4B1C20(aDisplayTrackSt, 0, 0, 1, 0, 1);
  MultiFieldSetterWithStrings(aSettingsType, 2, 0, 6, 0, 1);
  TripleDispatchWrapper((void *)(a1 + 8072), (int)&off_5D0070, (int)aF12002Gdb, (int)aTheCurrentGdbF);
  MultiFieldSetterWithStrings(aMeasurementUni, 0, 0, 1, aUnitsForEveryt, 1);
  sub_4B1C20(aSpeedUnits, 1, 0, 1, a0Mph1Kph, 1);
  sub_4B1C20(aHorizontalTire, 0, 0, 1, aInGarageOption, 1);
  v48 = 0;
  v65 = a1 + 8184;
  do
  {
    v5 = (_BYTE *)IdentityFunction(v81);
    sub_4AA1E0(v48, aQualifyLaps, v5);
    v6 = IdentityFunction(v81);
    MultiFieldSetterWithStrings(v6, 12, 1, 24, 0, 1);
    v3 = ++v48 < 7;
    v65 += 36;
  }
  while ( v3 );
  v49 = 0;
  v66 = a1 + 8436;
  do
  {
    v7 = (_BYTE *)IdentityFunction(v81);
    sub_4AA1E0(v49, aRaceLaps, v7);
    v8 = IdentityFunction(v81);
    MultiFieldSetterWithStrings(v8, 5, 0, 0x7FFF, 0, 1);
    v3 = ++v49 < 7;
    v66 += 36;
  }
  while ( v3 );
  v50 = 0;
  v67 = a1 + 8688;
  do
  {
    v9 = (_BYTE *)IdentityFunction(v81);
    sub_4AA1E0(v50, aRaceTime, v9);
    v10 = IdentityFunction(v81);
    MultiFieldSetterWithStrings(v10, 0x7FFF, 0, 0x7FFF, 0, 1);
    v3 = ++v50 < 7;
    v67 += 36;
  }
  while ( v3 );
  v51 = 0;
  v68 = a1 + 8940;
  do
  {
    v11 = (_BYTE *)IdentityFunction(v81);
    sub_4AA1E0(v51, aRaceLength, v11);
    v12 = IdentityFunction(v81);
    MultiFieldSetterWithStringCopy(v12, 1036831949, 0, 1065353216, 0, 1);
    v3 = ++v51 < 7;
    v68 += 36;
  }
  while ( v3 );
  v52 = 0;
  v69 = a1 + 9192;
  do
  {
    v13 = (_BYTE *)IdentityFunction(v81);
    sub_4AA1E0(v52, aSpeedCompensat, v13);
    v14 = IdentityFunction(v81);
    MultiFieldSetterWithStrings(v14, 0, 0, 1, 0, 1);
    v3 = ++v52 < 7;
    v69 += 36;
  }
  while ( v3 );
  v53 = 0;
  v70 = a1 + 9444;
  do
  {
    v15 = (_BYTE *)IdentityFunction(v81);
    sub_4AA1E0(v53, aOpponents, v15);
    if ( v53 < 2 || v53 > 4 )
      v40 = 0;
    else
      v40 = ShortComputation_3060(dword_5EC3D0) - 1;
    v16 = IdentityFunction(v81);
    MultiFieldSetterWithStrings(v16, v40, 0, 103, 0, 1);
    v3 = ++v53 < 7;
    v70 += 36;
  }
  while ( v3 );
  MultiFieldSetterWithStringCopy(aVehicleRemoval, 1092616192, 0, 1315859240, aSecondsUntilSt, 1);
  MultiFieldSetterWithStringCopy(aDebrisRemoval, 1092616192, 0, 1315859240, aSecondsUntilSt_0, 1);
  MultiFieldSetterWithStringCopy(aPartsDuration, 1101004800, 0, 1315859240, aSecondsAfterPa, 1);
  sub_4B1C20(aCrashRecovery, 1, 0, 1, aArtificiallyKe, 1);
  sub_4B1C20(aFines, 0, 0, 1, aGetFinesInstea, 1);
  sub_4B1C20(aExtraStats, 0, 0, 1, aSavesSeparateV, 1);
  MultiFieldSetterWithStrings(aVehiclesPerTea, 2, 1, 3, aUsedForAssigni, 1);
  v54 = 0;
  v71 = a1 + 9912;
  do
  {
    v17 = (_BYTE *)IdentityFunction(v81);
    sub_4AA1E0(v54, aFuelConsumptio, v17);
    v18 = IdentityFunction(v81);
    MultiFieldSetterWithStrings(v18, 1, 0, 7, 0, 1);
    v3 = ++v54 < 7;
    v71 += 36;
  }
  while ( v3 );
  v55 = 0;
  v72 = a1 + 10164;
  do
  {
    v19 = (_BYTE *)IdentityFunction(v81);
    sub_4AA1E0(v55, aTireWearMultip, v19);
    v20 = IdentityFunction(v81);
    MultiFieldSetterWithStrings(v20, 1, 0, 7, 0, 1);
    v3 = ++v55 < 7;
    v72 += 36;
  }
  while ( v3 );
  v56 = 0;
  v73 = (char *)(a1 + 10416);
  do
  {
    v21 = (_BYTE *)IdentityFunction(v81);
    sub_4AA1E0(v56, aAllowedVehicle, v21);
    v22 = IdentityFunction(v81);
    TripleDispatchWrapper(v73, v22, (int)aAndFormulaoneO, 0);
    v3 = ++v56 < 7;
    v73 += 28;
  }
  while ( v3 );
  MultiFieldSetterWithStrings(aInactiveSleepT, -1, -1, 250, aNumberOfMillis, 1);
  SettingsPathBuilder((void *)(a1 + 10648), (int)aMultiplayerOpt);
  MultiFieldSetterWithStrings(aNetConnectionT, 4, 0, 4, a028k156k2Isdn3, 1);
  MultiFieldSetterWithStrings(aMultiplayerEnu, 1, 0, 1, a0Lan1Internet, 1);
  MultiFieldSetterWithStrings(aNetDataRate, 32, 6, 32, aClientSetting, 1);
  MultiFieldSetterWithStrings(aNetDataRateMax, 32, 6, 32, aDefinedByTheHo, 1);
  MultiFieldSetterWithStrings(aNetFlushThresh, 1024, 0, 1024, aThresholdForAu, 1);
  MultiFieldSetterWithStrings(aNetLazyFlush, 0, 0, 1, aAnExplicitFlus, 1);
  MultiFieldSetterWithStringCopy(aNetJoinTimeout, 1125515264, 1092616192, 1150681088, aHowLongToWaitW, 1);
  MultiFieldSetterWithStrings(aMultiAllowedAi, -1, 0x80000000, 0x7FFFFFFF, 0, 1);
  MultiFieldSetterWithStrings(aForcePhysics, 24, 0, 31, aAddTheFollowin_0, 1);
  sub_4B1C20(aAnnounceHost, 1, 0, 1, aWhetherServers, 1);
  sub_4B1C20(aGamelistAutore, 1, 0, 1, aIfTrueTheGamel, 1);
  MultiFieldSetterWithStrings(aMaxMpPlayers, 16, 2, 104, 0, 1);
  ShortFieldSetter(aGamespyQueryPo, 34297, 1025, 0xFFFF, aRangeIs1025655, 1);
  ShortFieldSetter(aPortStart, 34397, 1025, 0xFFFF, aRangeIs1025655, 1);
  MultiFieldSetterWithStrings(aGameListSortMe, 1, 0, 3, a0SortByName1So, 1);
  sub_4B1C20(aAllowChatInCar, 1, 0, 1, aWhetherToAllow, 1);
  sub_4B1C20(aClosedMpQualif, 0, 0, 1, aIfTrueTheSessi, 1);
  sub_4B1C20(aThrottling, 1, 0, 1, aEnableThrottli, 1);
  MultiFieldSetterWithStringCopy(aCollisionThres, 1050253722, 0, 1115815936, aMaximumLatency, 1);
  MultiFieldSetterWithStrings(aDedicatedTarge, 128, 32, 1024, aTargetRateForD, 1);
  sub_4B1C20(aUniqueVehicleC, 0, 0, 1, aServerSettingW, 1);
  MultiFieldSetterWithStrings(aThrottleUpstre, -1, -1, 100000000, aKbitsPerSecond, 1);
  MultiFieldSetterWithStrings(aServerSessionE, 300, 0, 1000000, aSessionIsAdvan, 1);
  MultiFieldSetterWithStringCopy(aSplineGenerate, 1041865114, 1017370378, 1051361018, aHowOftenInSeco, 1);
  MultiFieldSetterWithStringCopy(aBonespringThre, 1065353216, 0, 1065353216, aIfLatencyIsBel, 1);
  MultiFieldSetterWithStringCopy(aBonespringMinC, 1103626240, 1008981770, 1148846080, aBonespringTmCo, 1);
  MultiFieldSetterWithStringCopy(aBonespringMaxC, 1123680256, 1008981770, 1148846080, aBonespringTmCo_0, 1);
  MultiFieldSetterWithStringCopy(aDampingMultipl, 1065353216, 1008981770, 1148846080, a10CriticalDamp, 1);
  TripleDispatchWrapper((void *)(a1 + 11580), (int)aPreviousGameDa, (int)byte_5EA438, (int)aUsedToRestoreT);
  TripleDispatchWrapper((void *)(a1 + 11608), (int)aPreviousVehicl, (int)byte_5EA438, (int)aUsedToRestoreT_0);
  SettingsPathBuilder((void *)(a1 + 11636), (int)aOptions_0);
  MultiFieldSetterWithStringCopy(aTooltipDelay, 1065772646, 0, 1203982336, 0, 1);
  MultiFieldSetterWithStrings(aPageTransition, 1, 0, 1, 0, 1);
  MultiFieldSetterWithStrings(aKeyRepeatRate, 1, 0, 3, 0, 1);
  SettingsPathBuilder((void *)(a1 + 11756), (int)aControls_2);
  MultiFieldSetterWithStringCopy(aKeyboardSteeri, 1045220557, 0, 1065353216, 0, 1);
  MultiFieldSetterWithStringCopy(aKeyboardThrott, 1056964608, 0, 1065353216, 0, 1);
  MultiFieldSetterWithStringCopy(aKeyboardBrake, 1056964608, 0, 1065353216, 0, 1);
  MultiFieldSetterWithStringCopy(aKeyboardClutch, 1045220557, 0, 1065353216, 0, 1);
  MultiFieldSetterWithStrings(aForceFeedback, 0, 0, 1, 0, 1);
  sub_4B1C20(aMimicSteering, 1, 0, 1, aMimicAiOrPitla, 1);
  sub_4B1C20(aGearSelectButt, 0, 0, 1, aEnableThisOpti, 1);
  sub_4B1C20(aAlternateRearl, 1, 0, 1, aIfLeftLookAndR, 1);
  sub_4B1C20(aVfx3dHeadTrack, 0, 0, 1, aEnableThisOpti_0, 1);
  MultiFieldSetterWithStringCopy(aHmdPitchExpone, 1065353216, -8388609, 2139095039, aExponentToAppl, 1);
  MultiFieldSetterWithStringCopy(aHmdYawExponent, 1065353216, -8388609, 2139095039, aExponentToAppl_0, 1);
  MultiFieldSetterWithStringCopy(aHmdRollExponen, 1065353216, -8388609, 2139095039, aExponentToAppl_1, 1);
  MultiFieldSetterWithStrings(aOptionsNumCont, 26, 26, 44, aNumberOfConfig, 1);
  for ( j = 0; j < 2; ++j )
  {
    v23 = 0;
    for ( k = 0; ; v23 = k )
    {
      v76 = 0;
      switch ( v23 )
      {
        case 0:
          if ( j )
            v76 = aController2X;
          else
            v76 = aController1X;
          break;
        case 1:
          if ( j )
            v76 = aController2Y;
          else
            v76 = aController1Y;
          break;
        case 2:
          if ( j )
            v76 = aController2Z;
          else
            v76 = aController1Z;
          break;
        case 3:
          if ( j )
            v76 = aController2Rx;
          else
            v76 = aController1Rx;
          break;
        case 4:
          if ( j )
            v76 = aController2Ry;
          else
            v76 = aController1Ry;
          break;
        case 5:
          if ( j )
            v76 = aController2Rz;
          else
            v76 = aController1Rz;
          break;
        case 6:
          if ( j )
            v76 = aController2S0;
          else
            v76 = aController1S0;
          break;
        case 7:
          v76 = aController1S1;
          if ( j )
            v76 = aController2S1;
          break;
        default:
          break;
      }
      v24 = IdentityFunction(v81);
      StringFormatWithBufferOverflowCheck(v24, "Axis [%2.2d, %2.2d] Dead Zone", j, k);
      v25 = IdentityFunction(v81);
      MultiFieldSetterWithStringCopy(v25, 0, 0, 1065353216, v76, 1);
      v26 = IdentityFunction(v81);
      StringFormatWithBufferOverflowCheck(v26, "Axis [%2.2d, %2.2d] Sensitivity", j, k);
      v27 = IdentityFunction(v81);
      MultiFieldSetterWithStringCopy(v27, 1056964608, 0, 1065353216, 0, 1);
      v28 = IdentityFunction(v81);
      StringFormatWithBufferOverflowCheck(v28, "Axis [%2.2d, %2.2d] Center", j, k);
      v29 = IdentityFunction(v81);
      MultiFieldSetterWithStringCopy(v29, 1056964608, 0, 1065353216, k++ != 0 ? 0 : a00Min05Center1, 1);
      if ( k >= 8 )
        break;
    }
  }
  FunctionCallWrapper_7010((_DWORD *)(a1 + 13916), (int)aControlAcceler, 0, 30);
  FunctionCallWrapper_7010((_DWORD *)(a1 + 13944), (int)aControlBrake, 0, 44);
  FunctionCallWrapper_7010((_DWORD *)(a1 + 13972), (int)aControlSteerLe, 0, 51);
  FunctionCallWrapper_7010((_DWORD *)(a1 + 14000), (int)aControlSteerRi, 0, 52);
  FunctionCallWrapper_7010((_DWORD *)(a1 + 14028), (int)aControlShiftUp, 0, 56);
  FunctionCallWrapper_7010((_DWORD *)(a1 + 14056), (int)aControlShiftDo, 0, 184);
  FunctionCallWrapper_7010((_DWORD *)(a1 + 14084), (int)aControlNeutral, 0, 89);
  FunctionCallWrapper_7010((_DWORD *)(a1 + 14644), (int)aControlReverse, 0, 89);
  FunctionCallWrapper_7010((_DWORD *)(a1 + 14672), (int)aControlFirstGe, 0, 89);
  FunctionCallWrapper_7010((_DWORD *)(a1 + 14700), (int)aControlSecondG, 0, 89);
  FunctionCallWrapper_7010((_DWORD *)(a1 + 14728), (int)aControlThirdGe, 0, 89);
  FunctionCallWrapper_7010((_DWORD *)(a1 + 14756), (int)aControlFourthG, 0, 89);
  FunctionCallWrapper_7010((_DWORD *)(a1 + 14784), (int)aControlFifthGe, 0, 89);
  FunctionCallWrapper_7010((_DWORD *)(a1 + 14812), (int)aControlSixthGe, 0, 89);
  FunctionCallWrapper_7010((_DWORD *)(a1 + 14840), (int)aControlSeventh, 0, 89);
  FunctionCallWrapper_7010((_DWORD *)(a1 + 14112), (int)aControlClutchI, 0, 16);
  FunctionCallWrapper_7010((_DWORD *)(a1 + 14140), (int)aControlDisplay, 0, 28);
  FunctionCallWrapper_7010((_DWORD *)(a1 + 14168), (int)aControlPitRequ, 0, 31);
  FunctionCallWrapper_7010((_DWORD *)(a1 + 14196), (int)aControlPitMenu, 0, 200);
  FunctionCallWrapper_7010((_DWORD *)(a1 + 14224), (int)aControlPitMenu_0, 0, 208);
  FunctionCallWrapper_7010((_DWORD *)(a1 + 14252), (int)aControlPitMenu_1, 0, 205);
  FunctionCallWrapper_7010((_DWORD *)(a1 + 14280), (int)aControlPitMenu_2, 0, 203);
  FunctionCallWrapper_7010((_DWORD *)(a1 + 14308), (int)aControlTcoverr, 0, 24);
  FunctionCallWrapper_7010((_DWORD *)(a1 + 14336), (int)aControlLaunchC, 0, 53);
  FunctionCallWrapper_7010((_DWORD *)(a1 + 14364), (int)aControlSpeedLi, 0, 38);
  FunctionCallWrapper_7010((_DWORD *)(a1 + 14392), (int)aControlBiasFor, 0, 26);
  FunctionCallWrapper_7010((_DWORD *)(a1 + 14420), (int)aControlBiasRea, 0, 27);
  FunctionCallWrapper_7010((_DWORD *)(a1 + 14448), (int)aControlLookLef, 0, 47);
  FunctionCallWrapper_7010((_DWORD *)(a1 + 14476), (int)aControlLookRig, 0, 49);
  FunctionCallWrapper_7010((_DWORD *)(a1 + 14504), (int)aControlRearLoo, 0, 48);
  FunctionCallWrapper_7010((_DWORD *)(a1 + 14560), (int)aControlInstant, 0, 19);
  FunctionCallWrapper_7010((_DWORD *)(a1 + 14588), (int)aControlPause, 0, 25);
  FunctionCallWrapper_7010((_DWORD *)(a1 + 14616), (int)aControlRestart, 0, 21);
  FunctionCallWrapper_7010((_DWORD *)(a1 + 14868), (int)aControlZeroHmd, 0, 89);
  FunctionCallWrapper_7010((_DWORD *)(a1 + 14532), (int)aControlDisplay_0, 0, 15);
  FunctionCallWrapper_7010((_DWORD *)(a1 + 14896), (int)aControlIgnitio, 0, 89);
  FunctionCallWrapper_7010((_DWORD *)(a1 + 14924), (int)aControlStarter, 0, 89);
  FunctionCallWrapper_7010((_DWORD *)(a1 + 14952), (int)aControlHorn, 0, 89);
  FunctionCallWrapper_7010((_DWORD *)(a1 + 14980), (int)aControlHeadlig, 0, 89);
  FunctionCallWrapper_7010((_DWORD *)(a1 + 15008), (int)aControlHandbra, 0, 89);
  FunctionCallWrapper_7010((_DWORD *)(a1 + 15036), (int)aControlLookUp, 0, 89);
  FunctionCallWrapper_7010((_DWORD *)(a1 + 15064), (int)aControlLookDow, 0, 89);
  FunctionCallWrapper_7010((_DWORD *)(a1 + 15092), (int)aControlLookRol, 0, 89);
  FunctionCallWrapper_7010((_DWORD *)(a1 + 15120), (int)aControlLookRol_0, 0, 89);
  MultiFieldSetterWithStrings(aFfbDeviceType, 0, 0, 3, aTypeOfFfbContr, 1);
  MultiFieldSetterWithStrings(aFfbEffectsLeve, 0, 0, 5, aNumberOfFfbEff, 1);
  MultiFieldSetterWithStringCopy(aFfbGain, 1065353216, 0, 1065353216, aStrengthOfForc, 1);
  MultiFieldSetterWithStrings(aFfbThrottleFxO, 0, 0, 1, a0ThrottleEffec, 1);
  MultiFieldSetterWithStrings(aFfbBrakeFxOnSt, 0, 0, 1, a0BrakeEffectsO, 1);
  MultiFieldSetterWithStringCopy(aFfbSteerVibeFr, 0, 0, 1287568416, aControlsFreque, 1);
  MultiFieldSetterWithStringCopy(aFfbSteerVibeZe, 1039516303, -859915232, 1287568416, aMagnitudeOfSte, 1);
  MultiFieldSetterWithStringCopy(aFfbSteerVibeSl, 0, -859915232, 1287568416, aSlopeOfLineDef, 1);
  MultiFieldSetterWithStrings(aFfbSteerVibeWa, 0, 0, 4, aTypeOfWaveToUs, 1);
  MultiFieldSetterWithStringCopy(aFfbSteerForceA, 1056964608, 1008981770, 1065353216, aHowMuchWeightI, 1);
  MultiFieldSetterWithStringCopy(aFfbSteerForceE, 1065353216, 0, 1287568416, aSteeringForceO, 1);
  MultiFieldSetterWithStringCopy(aFfbSteerForceI, 1177792512, -859915232, 1287568416, aRecommended115, 1);
  MultiFieldSetterWithStringCopy(aFfbSteerForceO, 1065353216, -859915232, 1287568416, aMaximumForceOu, 1);
  MultiFieldSetterWithStringCopy(aFfbSteerForceG, 1061997773, 0, 1065353216, aRange00To10Rec, 1);
  MultiFieldSetterWithStringCopy(aFfbSteerUpdate, 1014350479, 0, 1065353216, aAmountOfChange, 1);
  MultiFieldSetterWithStringCopy(aFfbSteerFricti, 1036831949, -1082130432, 1065353216, aCoefficientToU, 1);
  MultiFieldSetterWithStringCopy(aFfbSteerFricti_0, 1065353216, 0, 1065353216, aSaturationValu, 1);
  MultiFieldSetterWithStringCopy(aFfbSteerDamper, 1036831949, -1082130432, 1065353216, aCoefficientToU_0, 1);
  MultiFieldSetterWithStringCopy(aFfbSteerDamper_0, 1065353216, 0, 1065353216, aSaturationValu_0, 1);
  MultiFieldSetterWithStringCopy(aFfbThrottleVib, 1036831949, 0, 1287568416, aScalesActualEn, 1);
  MultiFieldSetterWithStringCopy(aFfbThrottleVib_0, 1043542835, -859915232, 1287568416, aMagnitudeOfEng, 1);
  MultiFieldSetterWithStringCopy(aFfbThrottleVib_1, 0, -859915232, 1287568416, aSlopeOfLineDef_0, 1);
  MultiFieldSetterWithStrings(aFfbThrottleVib_2, 0, 0, 4, aTypeOfWaveToUs, 1);
  MultiFieldSetterWithStringCopy(aFfbThrottleVib_3, 1034147594, 0, 1065353216, aAmountOfChange_0, 1);
  MultiFieldSetterWithStringCopy(aFfbBrakeVibeFr, 0, 0, 1287568416, aScalesActualBr, 1);
  MultiFieldSetterWithStringCopy(aFfbBrakeVibeZe, 1043542835, 0, 1065353216, aMagnitudeOfBra, 1);
  MultiFieldSetterWithStringCopy(aFfbBrakeVibeSl, 0, -859915232, 1287568416, aSlopeOfLineDef_1, 1);
  MultiFieldSetterWithStrings(aFfbBrakeVibeWa, 0, 0, 4, aTypeOfWaveToUs, 1);
  MultiFieldSetterWithStringCopy(aFfbBrakeVibeUp, 1028443341, 0, 1065353216, aAmountOfChange_1, 1);
  MultiFieldSetterWithStringCopy(aFfbRumbleStrip, 1051931443, 0, 1065353216, aHowStrongTheRu, 1);
  MultiFieldSetterWithStringCopy(aFfbRumbleStrip_0, 1059481190, 0, 1287568416, aRumbleStipFreq, 1);
  MultiFieldSetterWithStrings(aFfbRumbleStrip_1, 0, 0, 5, aTypeOfWaveToUs, 1);
  MultiFieldSetterWithStringCopy(aFfbRumbleStrip_2, 1069547520, -859915232, 1287568416, aHowStronglyWhe, 1);
  MultiFieldSetterWithStringCopy(aFfbRumbleStrip_3, 1028443341, 0, 1065353216, aAmountOfChange_2, 1);
  MultiFieldSetterWithStringCopy(aFfbJoltMagnitu, 1069547520, -859915232, 1287568416, aHowStrongJolts, 1);
  v58 = 0;
  v30 = a1 + 16984;
  do
  {
    v77 = 0;
    v75 = v30;
    do
    {
      v31 = IdentityFunction(v81);
      StringFormatWithBufferOverflowCheck(v31, "FFB Joy[%2.2d] Axis[%2.2d] Spring Saturation Pos", v58, v77);
      v32 = IdentityFunction(v81);
      MultiFieldSetterWithStringCopy(v32, 1065353216, 0, 1065353216, aDirectinputSat, 1);
      v33 = IdentityFunction(v81);
      StringFormatWithBufferOverflowCheck(v33, "FFB Joy[%2.2d] Axis[%2.2d] Spring Coefficient Pos", v58, v77);
      v34 = IdentityFunction(v81);
      MultiFieldSetterWithStringCopy(v34, 1056964608, 0, 1065353216, aDirectinputCoe, 1);
      v35 = IdentityFunction(v81);
      StringFormatWithBufferOverflowCheck(v35, "FFB Joy[%2.2d] Axis[%2.2d] Spring Saturation Neg", v58, v77);
      v36 = IdentityFunction(v81);
      MultiFieldSetterWithStringCopy(v36, 1065353216, 0, 1065353216, aDirectinputSat, 1);
      v37 = IdentityFunction(v81);
      StringFormatWithBufferOverflowCheck(v37, "FFB Joy[%2.2d] Axis[%2.2d] Spring Coefficient Neg", v58, v77);
      v38 = IdentityFunction(v81);
      MultiFieldSetterWithStringCopy(v38, 1056964608, 0, 1065353216, aDirectinputCoe, 1);
      v39 = v75 + 36;
      v3 = ++v77 < 8;
      v75 += 36;
    }
    while ( v3 );
    v3 = ++v58 < 2;
    v30 = v39;
  }
  while ( v3 );
  FlagSetterWithGlobalUpdate(a1, v39, 0);
  EmptyStub_aa60();
}
