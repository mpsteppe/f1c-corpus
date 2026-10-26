int __userpurge sub_433900@<eax>(int a1@<ecx>, char a2@<bpl>, char a3@<sil>, int ArgList, char a5)
{
  int i; // esi
  const CHAR *v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // esi
  int v16; // ebp
  int j; // ebp
  _DWORD *v18; // esi
  char v19; // [esp-20h] [ebp-134h]
  char v20; // [esp-18h] [ebp-12Ch]
  char v21; // [esp-18h] [ebp-12Ch]
  char v22; // [esp-18h] [ebp-12Ch]
  char v23; // [esp-14h] [ebp-128h]
  char v24; // [esp-10h] [ebp-124h]
  char v25; // [esp-10h] [ebp-124h]
  char v26; // [esp-10h] [ebp-124h]
  char v27; // [esp-10h] [ebp-124h]
  char v28; // [esp-8h] [ebp-11Ch]
  char v29; // [esp-4h] [ebp-118h]
  char v30; // [esp-4h] [ebp-118h]
  char v31; // [esp+0h] [ebp-114h]
  char v32; // [esp+4h] [ebp-110h]
  char v33; // [esp+Ch] [ebp-108h]
  char v34; // [esp+14h] [ebp-100h]
  double v35; // [esp+14h] [ebp-100h]
  double v36; // [esp+14h] [ebp-100h]
  double v37; // [esp+14h] [ebp-100h]
  double v38; // [esp+14h] [ebp-100h]
  char v39; // [esp+18h] [ebp-FCh]
  char v40; // [esp+18h] [ebp-FCh]
  char v41; // [esp+1Ch] [ebp-F8h]
  char v42; // [esp+20h] [ebp-F4h]
  char v43; // [esp+20h] [ebp-F4h]
  char v44[4]; // [esp+28h] [ebp-ECh] BYREF
  char v45[132]; // [esp+84h] [ebp-90h] BYREF
  int v46; // [esp+110h] [ebp-4h]

  if ( !a5 && !*(_BYTE *)a1 )
    return 0;
  sub_613B30(v44);
  v46 = 0;
  if ( (unsigned __int8)sub_6146B0(ArgList, 0, 1, 1, 1) )
  {
    sub_613D30((int)v44, "[GENERAL]\n", a3);
    for ( i = 0; ; i += 128 )
    {
      v8 = *(const CHAR **)(a1 + 104);
      if ( !v8 )
        v8 = WindowName;
      sub_630FE0(v45, &v8[i], 128);
      v45[128] = 0;
      sub_613D30((int)v44, "Notes=\"%s\"\n", (char)v45);
      if ( strlen(v45) < 0x80 )
        break;
    }
    sub_613D30((int)v44, "Symmetric=%d\n", *(_BYTE *)(a1 + 6953));
    sub_613D30((int)v44, "CGRightSetting=%d\n", *(_DWORD *)(a1 + 3140));
    sub_613D30((int)v44, "CGRearSetting=%d\n", *(_DWORD *)(a1 + 3204));
    sub_613D30((int)v44, "WedgeSetting=%d\n", *(_DWORD *)(a1 + 3268));
    sub_613D30((int)v44, "FrontTireCompoundSetting=%d\n", *(_DWORD *)(a1 + 3012));
    sub_613D30((int)v44, "RearTireCompoundSetting=%d\n", *(_DWORD *)(a1 + 3076));
    sub_613D30((int)v44, "FuelSetting=%d\n", *(_DWORD *)(a1 + 3332));
    sub_613D30((int)v44, "NumPitstopsSetting=%d\n", *(_DWORD *)(a1 + 6340));
    sub_613D30((int)v44, "Pitstop1Setting=%d\n", *(_DWORD *)(a1 + 6404));
    sub_613D30((int)v44, "Pitstop2Setting=%d\n", *(_DWORD *)(a1 + 6468));
    sub_613D30((int)v44, "Pitstop3Setting=%d\n", *(_DWORD *)(a1 + 6532));
    sub_613D30((int)v44, "Pitstop4Setting=%d\n", *(_DWORD *)(a1 + 6596));
    sub_613D30((int)v44, "Pitstop5Setting=%d\n", *(_DWORD *)(a1 + 6660));
    sub_613D30((int)v44, "Pitstop6Setting=%d\n", *(_DWORD *)(a1 + 6724));
    sub_613D30((int)v44, "Pitstop7Setting=%d\n", *(_DWORD *)(a1 + 6788));
    sub_613D30((int)v44, "Pitstop8Setting=%d\n", *(_DWORD *)(a1 + 6852));
    sub_613D30((int)v44, (char *)word_6F2E64, v24);
    sub_613D30((int)v44, "[LEFTFENDER]\n", v20);
    sub_613D30((int)v44, "FenderFlareSetting=%d\n", *(_DWORD *)(a1 + 3652));
    sub_613D30((int)v44, (char *)word_6F2E64, v34);
    sub_613D30((int)v44, "[RIGHTFENDER]\n", v33);
    sub_613D30((int)v44, "FenderFlareSetting=%d\n", *(_DWORD *)(a1 + 3716));
    sub_613D30((int)v44, (char *)word_6F2E64, v28);
    sub_613D30((int)v44, "[FRONTWING]\n", v25);
    sub_613D30((int)v44, "FWSetting=%d\n", *(_DWORD *)(a1 + 4804));
    sub_613D30((int)v44, (char *)word_6F2E64, v42);
    sub_613D30((int)v44, "[REARWING]\n", v39);
    sub_613D30((int)v44, "RWSetting=%d\n", *(_DWORD *)(a1 + 4868));
    sub_613D30((int)v44, (char *)word_6F2E64, v32);
    sub_613D30((int)v44, "[BODYAERO]\n", v29);
    sub_613D30((int)v44, "RadiatorSetting=%d\n", *(_DWORD *)(a1 + 4932));
    sub_613D30((int)v44, "BrakeDuctSetting=%d\n", *(_DWORD *)(a1 + 4996));
    sub_613D30((int)v44, (char *)word_6F2E64, v43);
    sub_613D30((int)v44, "[SUSPENSION]\n", v40);
    sub_613D30((int)v44, "FrontAntiSwaySetting=%d\n", *(_DWORD *)(a1 + 3396));
    sub_613D30((int)v44, "RearAntiSwaySetting=%d\n", *(_DWORD *)(a1 + 3460));
    sub_613D30((int)v44, "FrontToeInSetting=%d\n", *(_DWORD *)(a1 + 3524));
    sub_613D30((int)v44, "RearToeInSetting=%d\n", *(_DWORD *)(a1 + 3588));
    sub_613D30((int)v44, "LeftCasterSetting=%d\n", *(_DWORD *)(a1 + 3780));
    sub_613D30((int)v44, "RightCasterSetting=%d\n", *(_DWORD *)(a1 + 3844));
    sub_613D30((int)v44, "LeftTrackBarSetting=%d\n", *(_DWORD *)(a1 + 3908));
    sub_613D30((int)v44, "RightTrackBarSetting=%d\n", *(_DWORD *)(a1 + 3972));
    sub_613D30((int)v44, "Front3rdPackerSetting=%d\n", *(_DWORD *)(a1 + 4036));
    sub_613D30((int)v44, "Front3rdSpringSetting=%d\n", *(_DWORD *)(a1 + 4100));
    sub_613D30((int)v44, "Front3rdSlowBumpSetting=%d\n", *(_DWORD *)(a1 + 4164));
    sub_613D30((int)v44, "Front3rdFastBumpSetting=%d\n", *(_DWORD *)(a1 + 4228));
    sub_613D30((int)v44, "Front3rdSlowReboundSetting=%d\n", *(_DWORD *)(a1 + 4292));
    sub_613D30((int)v44, "Front3rdFastReboundSetting=%d\n", *(_DWORD *)(a1 + 4356));
    sub_613D30((int)v44, "Rear3rdPackerSetting=%d\n", *(_DWORD *)(a1 + 4420));
    sub_613D30((int)v44, "Rear3rdSpringSetting=%d\n", *(_DWORD *)(a1 + 4484));
    sub_613D30((int)v44, "Rear3rdSlowBumpSetting=%d\n", *(_DWORD *)(a1 + 4548));
    sub_613D30((int)v44, "Rear3rdFastBumpSetting=%d\n", *(_DWORD *)(a1 + 4612));
    sub_613D30((int)v44, "Rear3rdSlowReboundSetting=%d\n", *(_DWORD *)(a1 + 4676));
    sub_613D30((int)v44, "Rear3rdFastReboundSetting=%d\n", *(_DWORD *)(a1 + 4740));
    sub_613D30((int)v44, (char *)word_6F2E64, v26);
    sub_613D30((int)v44, "[CONTROLS]\n", v21);
    sub_613D30((int)v44, "SteerLockSetting=%d\n", *(_DWORD *)(a1 + 5252));
    sub_613D30((int)v44, "RearBrakeSetting=%d\n", *(_DWORD *)(a1 + 5060));
    sub_613D30((int)v44, "BrakePressureSetting=%d\n", *(_DWORD *)(a1 + 5124));
    sub_613D30((int)v44, "HandbrakePressSetting=%d\n", *(_DWORD *)(a1 + 5188));
    sub_613D30((int)v44, (char *)word_6F2E64, v27);
    sub_613D30((int)v44, "[ENGINE]\n", v22);
    sub_613D30((int)v44, "RevLimitSetting=%d\n", *(_DWORD *)(a1 + 5572));
    sub_613D30((int)v44, "EngineMapSetting=%d\n", *(_DWORD *)(a1 + 5636));
    sub_613D30((int)v44, "EngineBrakingMapSetting=%d\n", *(_DWORD *)(a1 + 5700));
    sub_613D30((int)v44, (char *)word_6F2E64, v30);
    v9 = *(_DWORD *)(a1 + 5892);
    if ( *(_DWORD *)(a1 + 5956) < v9 )
      *(_DWORD *)(a1 + 5956) = v9;
    v10 = *(_DWORD *)(a1 + 5956);
    if ( *(_DWORD *)(a1 + 6020) < v10 )
      *(_DWORD *)(a1 + 6020) = v10;
    v11 = *(_DWORD *)(a1 + 6020);
    if ( *(_DWORD *)(a1 + 6084) < v11 )
      *(_DWORD *)(a1 + 6084) = v11;
    v12 = *(_DWORD *)(a1 + 6084);
    if ( *(_DWORD *)(a1 + 6148) < v12 )
      *(_DWORD *)(a1 + 6148) = v12;
    v13 = *(_DWORD *)(a1 + 6148);
    if ( *(_DWORD *)(a1 + 6212) < v13 )
      *(_DWORD *)(a1 + 6212) = v13;
    v14 = *(_DWORD *)(a1 + 6212);
    if ( *(_DWORD *)(a1 + 6276) < v14 )
      *(_DWORD *)(a1 + 6276) = v14;
    sub_613D30((int)v44, "[DRIVELINE]\n", a2);
    sub_613D30((int)v44, "FinalDriveSetting=%d\n", *(_DWORD *)(a1 + 5764));
    sub_613D30((int)v44, "ReverseSetting=%d\n", *(_DWORD *)(a1 + 5828));
    v15 = 45;
    v16 = a1 + 5892;
    do
    {
      if ( *(_BYTE *)(v16 + 8) )
        sub_613D30((int)v44, "Gear%dSetting=%d\n", v15 - 44);
      ++v15;
      v16 += 64;
    }
    while ( v15 <= 51 );
    sub_613D30((int)v44, "DiffPumpSetting=%d\n", *(_DWORD *)(a1 + 5316));
    sub_613D30((int)v44, "DiffPowerSetting=%d\n", *(_DWORD *)(a1 + 5380));
    sub_613D30((int)v44, "DiffCoastSetting=%d\n", *(_DWORD *)(a1 + 5444));
    sub_613D30((int)v44, "DiffPreloadSetting=%d\n", *(_DWORD *)(a1 + 5508));
    sub_613D30((int)v44, (char *)word_6F2E64, v23);
    for ( j = 0; j < 4; ++j )
    {
      switch ( j )
      {
        case 0:
          sub_613D30((int)v44, "[FRONTLEFT]\n", v41);
          break;
        case 1:
          sub_613D30((int)v44, "[FRONTRIGHT]\n", v41);
          break;
        case 2:
          sub_613D30((int)v44, "[REARLEFT]\n", v41);
          break;
        case 3:
          sub_613D30((int)v44, "[REARRIGHT]\n", v41);
          break;
        default:
          break;
      }
      v18 = (_DWORD *)(704 * j + a1);
      sub_613D30((int)v44, "CamberSetting=%d\n", v18[49]);
      sub_613D30((int)v44, "PressureSetting=%d\n", v18[65]);
      sub_613D30((int)v44, "PackerSetting=%d\n", v18[97]);
      sub_613D30((int)v44, "SpringSetting=%d\n", v18[113]);
      sub_613D30((int)v44, "RideHeightSetting=%d\n", v18[81]);
      sub_613D30((int)v44, "SlowBumpSetting=%d\n", v18[129]);
      sub_613D30((int)v44, "FastBumpSetting=%d\n", v18[145]);
      sub_613D30((int)v44, "SlowReboundSetting=%d\n", v18[161]);
      sub_613D30((int)v44, "FastReboundSetting=%d\n", v18[177]);
      sub_613D30((int)v44, "BrakeDiscSetting=%d\n", v18[193]);
      sub_613D30((int)v44, "BrakePadSetting=%d\n", v18[209]);
      sub_613D30((int)v44, (char *)word_6F2E64, v19);
    }
    sub_613D30((int)v44, "[BASIC]\n", v41);
    v35 = *(float *)(a1 + 7724);
    sub_613D30((int)v44, "Downforce=%f\n", SLOBYTE(v35));
    v36 = *(float *)(a1 + 7728);
    sub_613D30((int)v44, "Balance=%f\n", SLOBYTE(v36));
    v37 = *(float *)(a1 + 7732);
    sub_613D30((int)v44, "Ride=%f\n", SLOBYTE(v37));
    v38 = *(float *)(a1 + 7736);
    sub_613D30((int)v44, "Gearing=%f\n", SLOBYTE(v38));
    sub_613D30((int)v44, "Custom=%d\n", *(_BYTE *)(a1 + 6952));
    sub_613D30((int)v44, (char *)word_6F2E64, v31);
    sub_613C30(v44);
    *(_BYTE *)a1 = 0;
    v46 = -1;
    sub_614140(v44);
    return 0;
  }
  else
  {
    if ( (unsigned __int8)sub_5612D0((int)byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\garage.cpp", 1507) )
      sub_561210((int)byte_FAE910, "Failed to open %s for writing", ArgList);
    v46 = -1;
    sub_614140(v44);
    return -1;
  }
}
