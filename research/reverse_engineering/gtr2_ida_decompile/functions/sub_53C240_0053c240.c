int __thiscall sub_53C240(char *this)
{
  const CHAR *v2; // eax
  bool v3; // zf
  const CHAR *v4; // esi
  _DWORD *v6; // edi
  int v7; // ecx
  double v8; // st7
  double v9; // st6
  int i; // edi
  char *v11; // eax
  char v12; // cl
  char *v13; // edi
  const CHAR *v14; // eax
  char *v15; // eax
  char *v16; // ecx
  char v17; // al
  char *j; // eax
  const char *v19; // eax
  char v20; // cl
  const char *k; // ecx
  char *v22; // edi
  const char *v23; // ecx
  int v24; // kr00_4
  char *v25; // eax
  int v26; // [esp+10h] [ebp-7E8h] BYREF
  char v27; // [esp+16h] [ebp-7E2h]
  char v28; // [esp+17h] [ebp-7E1h]
  int v29; // [esp+18h] [ebp-7E0h] BYREF
  char *String2; // [esp+1Ch] [ebp-7DCh]
  int v31; // [esp+20h] [ebp-7D8h] BYREF
  int v32; // [esp+24h] [ebp-7D4h] BYREF
  char v33[512]; // [esp+30h] [ebp-7C8h] BYREF
  int v34; // [esp+230h] [ebp-5C8h]
  char v35; // [esp+234h] [ebp-5C4h]
  int v36; // [esp+23Ch] [ebp-5BCh]
  char v37[4]; // [esp+240h] [ebp-5B8h] BYREF
  int v38; // [esp+244h] [ebp-5B4h]
  char Buffer[512]; // [esp+248h] [ebp-5B0h] BYREF
  _BYTE v40[88]; // [esp+448h] [ebp-3B0h] BYREF
  _BYTE v41[61]; // [esp+4A8h] [ebp-350h] BYREF
  __int16 v42; // [esp+4E5h] [ebp-313h]
  char v43; // [esp+4E7h] [ebp-311h]
  int v44[16]; // [esp+5E8h] [ebp-210h] BYREF
  int v45[6]; // [esp+628h] [ebp-1D0h] BYREF
  int v46; // [esp+668h] [ebp-190h] BYREF
  int v47[14]; // [esp+6A8h] [ebp-150h] BYREF
  int v48[45]; // [esp+6E0h] [ebp-118h] BYREF
  int v49; // [esp+79Ch] [ebp-5Ch]
  int v50; // [esp+7F4h] [ebp-4h]

  sub_613B30(v40);
  memset(Buffer, 0, sizeof(Buffer));
  memset(v41, 0, sizeof(v41));
  v42 = 0;
  v43 = 0;
  v50 = 0;
  v34 = 0;
  v38 = 0;
  v36 = 0;
  *(_DWORD *)v37 = 0;
  v35 = 1;
  v28 = 0;
  v27 = 0;
  String2 = 0;
  if ( dword_B72338 )
  {
    if ( dword_B72338 == 1 )
    {
      String2 = "PRO_HDVehicle";
    }
    else if ( dword_B72338 == 2 )
    {
      String2 = "SIM_HDVehicle";
    }
  }
  else
  {
    String2 = "ARC_HDVehicle";
  }
  v2 = *(const CHAR **)this;
  v3 = *(_DWORD *)this == 0;
  LOBYTE(v46) = 0;
  LOBYTE(v44[0]) = 0;
  LOBYTE(v47[0]) = 0;
  LOBYTE(v45[0]) = 0;
  this[384] = 0;
  this[448] = 0;
  if ( v3 )
    v2 = WindowName;
  if ( (unsigned __int8)sub_614460(v2, 1) )
  {
    if ( sub_613DE0(Buffer, 512) )
    {
      do
      {
        sub_612EB0(v33);
        sub_6131C0("HDVehicle", (int)v44);
        sub_6131C0("HeadPhysics", (int)&v46);
        sub_6131C0("Sounds", (int)v45);
        sub_6131C0("Graphics", (int)v47);
        sub_6131C0("GenString", (int)(this + 40));
        sub_6131C0(String2, (int)v41);
        v6 = this + 56;
        if ( sub_6134B0("Eyepoint", (int)(this + 56), (int)(this + 60), (int)(this + 64), 0, 0, 0, 0, 0) )
        {
          if ( !v28 )
          {
            *((_DWORD *)this + 17) = *v6;
            v7 = *((_DWORD *)this + 16);
            *((_DWORD *)this + 18) = *((_DWORD *)this + 15);
            *((_DWORD *)this + 19) = v7;
          }
          if ( !v27 )
          {
            v8 = *((float *)this + 16) - 0.94999999;
            v9 = *((float *)this + 15);
            *((_DWORD *)this + 20) = *v6;
            *((float *)this + 21) = v9 - 0.090000004;
            *((float *)this + 22) = v8;
          }
        }
        if ( sub_6134B0("CameraTarget", (int)(this + 68), (int)(this + 72), (int)(this + 76), 0, 0, 0, 0, 0) )
          v28 = 1;
        if ( sub_6134B0("MirrorPos", (int)(this + 80), (int)(this + 84), (int)(this + 88), 0, 0, 0, 0, 0) )
          v27 = 1;
        sub_6134B0("MirrorNorm", (int)(this + 92), (int)(this + 96), (int)(this + 100), 0, 0, 0, 0, 0);
        sub_6134B0("SteeringWheelAxis", (int)(this + 104), (int)(this + 108), (int)(this + 112), 0, 0, 0, 0, 0);
        sub_6134B0("FlowCenter", (int)(this + 116), (int)(this + 120), (int)(this + 124), 0, 0, 0, 0, 0);
        sub_613240("FrontWheelsInCockpit", (int)(this + 128), 0, 0, 0);
        sub_6134B0("MaxSeatFront", (int)(this + 132), 0, 0, 0, 0, 0, 0, 0);
        sub_6134B0("MaxSeatRear", (int)(this + 136), 0, 0, 0, 0, 0, 0, 0);
        sub_6134B0("MaxSeatUp", (int)(this + 140), 0, 0, 0, 0, 0, 0, 0);
        sub_6134B0("MaxSeatDown", (int)(this + 144), 0, 0, 0, 0, 0, 0, 0);
        sub_6133A0("Exhausts", (int)(this + 280), 0, 0, 0);
        sub_6134B0("ExhaustAmount", (int)(this + 380), 0, 0, 0, 0, 0, 0, 0);
        sub_6134B0("Exhaust1", (int)(this + 284), (int)(this + 288), (int)(this + 292), 0, 0, 0, 0, 0);
        sub_6134B0("Exhaust2", (int)(this + 296), (int)(this + 300), (int)(this + 304), 0, 0, 0, 0, 0);
        sub_6134B0("Exhaust3", (int)(this + 308), (int)(this + 312), (int)(this + 316), 0, 0, 0, 0, 0);
        sub_6134B0("Exhaust4", (int)(this + 320), (int)(this + 324), (int)(this + 328), 0, 0, 0, 0, 0);
        sub_6134B0("ExhaustVel1", (int)(this + 332), (int)(this + 336), (int)(this + 340), 0, 0, 0, 0, 0);
        sub_6134B0("ExhaustVel2", (int)(this + 344), (int)(this + 348), (int)(this + 352), 0, 0, 0, 0, 0);
        sub_6134B0("ExhaustVel3", (int)(this + 356), (int)(this + 360), (int)(this + 364), 0, 0, 0, 0, 0);
        sub_6134B0("ExhaustVel4", (int)(this + 368), (int)(this + 372), (int)(this + 376), 0, 0, 0, 0, 0);
        sub_6131C0("RimType", (int)(this + 384));
        sub_6131C0("TyreType", (int)(this + 448));
        sub_6133A0("DigitalDisplays", (int)(this + 512), 0, 0, 0);
        for ( i = 0; i < 3; ++i )
          sub_538460();
        sub_6134B0(
          "SpeedometerRange",
          (int)(this + 1380),
          (int)(this + 1384),
          (int)(this + 1396),
          (int)(this + 1400),
          0,
          0,
          0,
          0);
        sub_6134B0("SpeedometerNeedle", (int)(this + 1388), (int)(this + 1392), 0, 0, 0, 0, 0, 0);
        sub_6134B0(
          "TachometerRange",
          (int)(this + 1428),
          (int)(this + 1432),
          (int)(this + 1444),
          (int)(this + 1448),
          0,
          0,
          0,
          0);
        sub_6134B0("TachometerNeedle", (int)(this + 1436), (int)(this + 1440), 0, 0, 0, 0, 0, 0);
        sub_6134B0(
          "WaterTempRange",
          (int)(this + 1476),
          (int)(this + 1480),
          (int)(this + 1492),
          (int)(this + 1496),
          0,
          0,
          0,
          0);
        sub_6134B0("WaterTempNeedle", (int)(this + 1484), (int)(this + 1488), 0, 0, 0, 0, 0, 0);
        sub_6134B0(
          "OilTempRange",
          (int)(this + 1524),
          (int)(this + 1528),
          (int)(this + 1540),
          (int)(this + 1544),
          0,
          0,
          0,
          0);
        sub_6134B0("OilTempNeedle", (int)(this + 1532), (int)(this + 1536), 0, 0, 0, 0, 0, 0);
        sub_6134B0(
          "OilPressureRange",
          (int)(this + 1572),
          (int)(this + 1576),
          (int)(this + 1588),
          (int)(this + 1592),
          0,
          0,
          0,
          0);
        sub_6134B0("OilPressureNeedle", (int)(this + 1580), (int)(this + 1584), 0, 0, 0, 0, 0, 0);
        sub_6134B0(
          "FuelPressureRange",
          (int)(this + 1620),
          (int)(this + 1624),
          (int)(this + 1636),
          (int)(this + 1640),
          0,
          0,
          0,
          0);
        sub_6134B0("FuelPressureNeedle", (int)(this + 1628), (int)(this + 1632), 0, 0, 0, 0, 0, 0);
        sub_6134B0(
          "FuelVolumeRange",
          (int)(this + 1668),
          (int)(this + 1672),
          (int)(this + 1684),
          (int)(this + 1688),
          0,
          0,
          0,
          0);
        sub_6134B0("FuelVolumeNeedle", (int)(this + 1676), (int)(this + 1680), 0, 0, 0, 0, 0, 0);
        sub_6134B0(
          "HUDSpeedometerRange",
          (int)(this + 1404),
          (int)(this + 1408),
          (int)(this + 1420),
          (int)(this + 1424),
          0,
          0,
          0,
          0);
        sub_6134B0("HUDSpeedometerNeedle", (int)(this + 1412), (int)(this + 1416), 0, 0, 0, 0, 0, 0);
        sub_6134B0(
          "HUDTachometerRange",
          (int)(this + 1452),
          (int)(this + 1456),
          (int)(this + 1468),
          (int)(this + 1472),
          0,
          0,
          0,
          0);
        sub_6134B0("HUDTachometerNeedle", (int)(this + 1460), (int)(this + 1464), 0, 0, 0, 0, 0, 0);
        sub_6134B0(
          "HUDWaterTempRange",
          (int)(this + 1500),
          (int)(this + 1504),
          (int)(this + 1516),
          (int)(this + 1520),
          0,
          0,
          0,
          0);
        sub_6134B0("HUDWaterTempNeedle", (int)(this + 1508), (int)(this + 1512), 0, 0, 0, 0, 0, 0);
        sub_6134B0(
          "HUDOilTempRange",
          (int)(this + 1548),
          (int)(this + 1552),
          (int)(this + 1564),
          (int)(this + 1568),
          0,
          0,
          0,
          0);
        sub_6134B0("HUDOilTempNeedle", (int)(this + 1556), (int)(this + 1560), 0, 0, 0, 0, 0, 0);
        sub_6134B0(
          "HUDOilPressureRange",
          (int)(this + 1596),
          (int)(this + 1600),
          (int)(this + 1612),
          (int)(this + 1616),
          0,
          0,
          0,
          0);
        sub_6134B0("HUDOilPressureNeedle", (int)(this + 1604), (int)(this + 1608), 0, 0, 0, 0, 0, 0);
        sub_6134B0(
          "HUDFuelPressureRange",
          (int)(this + 1644),
          (int)(this + 1648),
          (int)(this + 1660),
          (int)(this + 1664),
          0,
          0,
          0,
          0);
        sub_6134B0("HUDFuelPressureNeedle", (int)(this + 1652), (int)(this + 1656), 0, 0, 0, 0, 0, 0);
        sub_6134B0(
          "HUDFuelVolumeRange",
          (int)(this + 1692),
          (int)(this + 1696),
          (int)(this + 1708),
          (int)(this + 1712),
          0,
          0,
          0,
          0);
        sub_6134B0("HUDFuelVolumeNeedle", (int)(this + 1700), (int)(this + 1704), 0, 0, 0, 0, 0, 0);
        sub_6131C0("Number", (int)(this + 1716));
        if ( sub_6131C0("Team", (int)(this + 1724)) && !this[1788] )
        {
          v11 = this + 1724;
          do
          {
            v12 = *v11;
            v11[64] = *v11;
            ++v11;
          }
          while ( v12 );
        }
        sub_6131C0("PitGroup", (int)(this + 1788));
        sub_6131C0("Driver", (int)(this + 1852));
        sub_6131C0("Driver1", (int)(this + 1852));
        sub_6131C0("Driver2", (int)(this + 1916));
        sub_6131C0("Description", (int)(this + 1980));
        sub_6131C0("Engine", (int)(this + 2044));
        sub_6131C0("Manufacturer", (int)(this + 2108));
        sub_6131C0("Classes", (int)(this + 2172));
        sub_6131C0("FullTeamName", (int)(this + 2428));
        sub_6131C0("TeamFounded", (int)(this + 2556));
        sub_6131C0("TeamHeadquarters", (int)(this + 2572));
        sub_6131C0("TeamStarts", (int)(this + 2636));
        sub_6131C0("TeamPoles", (int)(this + 2652));
        sub_6131C0("TeamWins", (int)(this + 2668));
        sub_6131C0("TeamWorldChampionships", (int)(this + 2684));
        if ( sub_6133A0("Color", (int)&v29, (int)&v31, (int)&v32, 0) )
          *((_DWORD *)this + 681) = v32 | ((v31 | ((v29 | 0xFFFFFF00) << 8)) << 8);
        if ( sub_6133A0("SteeringWheelType", (int)&v26, 0, 0, 0) )
          *((_DWORD *)this + 37) = v26;
        sub_6134B0("FirstPersonDriverPosition", (int)(this + 152), (int)(this + 156), (int)(this + 160), 0, 0, 0, 0, 0);
        sub_6134B0("ExternalDriverPosition", (int)(this + 164), (int)(this + 168), (int)(this + 172), 0, 0, 0, 0, 0);
        if ( sub_6133A0("LeftSideSteering", (int)&v26, 0, 0, 0) )
          this[176] = v26 != 0;
        sub_6134B0("ShiftStickPosition", (int)(this + 180), (int)(this + 184), (int)(this + 188), 0, 0, 0, 0, 0);
        sub_6134B0("ClutchPedalPosition", (int)(this + 192), (int)(this + 196), (int)(this + 200), 0, 0, 0, 0, 0);
        sub_6134B0("BrakePedalPosition", (int)(this + 204), (int)(this + 208), (int)(this + 212), 0, 0, 0, 0, 0);
        sub_6134B0("AcceleratorPedalPosition", (int)(this + 216), (int)(this + 220), (int)(this + 224), 0, 0, 0, 0, 0);
        sub_6134B0("LeftLegBendAngle", (int)(this + 228), 0, 0, 0, 0, 0, 0, 0);
        sub_6134B0("RightLegBendAngle", (int)(this + 232), 0, 0, 0, 0, 0, 0, 0);
        sub_6134B0("FuelCapPositionL", (int)(this + 236), (int)(this + 240), (int)(this + 244), 0, 0, 0, 0, 0);
        sub_6134B0("FuelCapAngleL", (int)(this + 248), 0, 0, 0, 0, 0, 0, 0);
        sub_6134B0("FuelCapPositionR", (int)(this + 252), (int)(this + 256), (int)(this + 260), 0, 0, 0, 0, 0);
        sub_6134B0("FuelCapAngleR", (int)(this + 264), 0, 0, 0, 0, 0, 0, 0);
        sub_6133A0("FuelAnimations", (int)(this + 268), 0, 0, 0);
        sub_6133A0("FuelRigType", (int)(this + 272), 0, 0, 0);
        sub_6134B0("FuelTechDistance", (int)(this + 276), 0, 0, 0, 0, 0, 0, 0);
        if ( sub_6133A0("ComparativeTime", (int)&v26, 0, 0, 0) )
          *((float *)this + 675) = (double)v26 * 0.0099999998;
        if ( sub_6133A0("BodyTintR", (int)&v29, 0, 0, 0) )
          *((_DWORD *)this + 676) = v29 << 16;
        if ( sub_6133A0("BodyTintG", (int)&v31, 0, 0, 0) )
          *((_DWORD *)this + 676) |= v31 << 8;
        if ( sub_6133A0("BodyTintB", (int)&v32, 0, 0, 0) )
          *((_DWORD *)this + 676) |= v32;
        if ( sub_6131C0("ChangeCarAtRace", (int)&v41[56]) )
          sub_615860(&v41[56]);
        if ( sub_6131C0("2ndVEHFile", (int)&v41[56]) )
        {
          _strupr(&v41[56]);
          sub_615860(&v41[56]);
        }
        if ( sub_6131C0("DefaultLivery", (int)&v41[56]) )
          sub_615860(&v41[56]);
        if ( sub_6131C0("DriverLivery", (int)&v41[56]) )
          sub_615860(&v41[56]);
        if ( sub_6131C0("PitcrewLivery", (int)&v41[56]) )
          sub_615860(&v41[56]);
        if ( sub_6131C0("TrackLivery", (int)&v41[56]) )
        {
          v13 = strstr(&v41[56], ",");
          if ( v13 )
          {
            v15 = (char *)operator new(0x14u);
            if ( v15 )
            {
              *(_DWORD *)v15 = 0;
              *((_DWORD *)v15 + 1) = -1;
              *((_DWORD *)v15 + 2) = 0;
              *((_DWORD *)v15 + 3) = -1;
              String2 = v15;
            }
            else
            {
              String2 = 0;
            }
            v16 = &v41[56];
            if ( v41[56] == 32 )
            {
              do
                v17 = *++v16;
              while ( v17 == 32 );
            }
            for ( j = v13; j > v16; --j )
            {
              if ( *j != 32 && *j != 44 )
                break;
            }
            j[1] = 0;
            sub_615860(v16);
            v19 = v13 + 1;
            if ( v13[1] == 32 )
            {
              do
                v20 = *++v19;
              while ( v20 == 32 );
            }
            for ( k = &v19[strlen(v19)]; k > v19; --k )
            {
              if ( *k != 32 && *k )
                break;
            }
            v22 = String2;
            *((_BYTE *)k + 1) = 0;
            sub_615860(v19);
            *((_DWORD *)v22 + 4) = *((_DWORD *)this + 686);
            *((_DWORD *)this + 686) = v22;
          }
          else if ( (unsigned __int8)sub_5612D0(
                                       (int)byte_FAE910,
                                       1,
                                       "\\Dev\\Src\\Copperhead\\App\\Source\\setup.cpp",
                                       498) )
          {
            v14 = *(const CHAR **)this;
            if ( !*(_DWORD *)this )
              v14 = WindowName;
            sub_561210(
              (int)byte_FAE910,
              "Format is: TrackLivery=\"<trackname>,<liveryname>\" in file \"%s\"",
              (char)v14);
          }
        }
      }
      while ( sub_613DE0(v37, 512) );
    }
    sub_613C30(&Buffer[504]);
    sub_53C040();
    if ( !this[1980] )
      sprintf(this + 1980, "#%.4s %.50s", this + 1716, this + 1724);
    v23 = *(const char **)this;
    if ( !*(_DWORD *)this )
      v23 = WindowName;
    strcpy((char *)v48, v23);
    v24 = strlen((const char *)v48);
    if ( v24 > 0 )
    {
      v25 = (char *)&v47[13] + v24 + 3;
      if ( (int *)((char *)&v47[13] + v24 + 3) >= v48 )
      {
        do
        {
          if ( *v25 == 92 )
            break;
          *v25-- = 0;
        }
        while ( v25 >= (char *)v48 );
      }
    }
    if ( sub_5396B0() == -1 )
      sub_5396B0();
    sub_5396B0();
    sub_5396B0();
    sub_5396B0();
    v49 = -1;
    sub_614140(&Buffer[424]);
    return 0;
  }
  else
  {
    if ( (unsigned __int8)sub_5612D0((int)byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\setup.cpp", 294) )
    {
      v4 = *(const CHAR **)this;
      if ( !v4 )
        v4 = WindowName;
      sub_561210((int)byte_FAE910, "Could not open %s", (char)v4);
    }
    v50 = -1;
    sub_614140(v40);
    return -1;
  }
}
