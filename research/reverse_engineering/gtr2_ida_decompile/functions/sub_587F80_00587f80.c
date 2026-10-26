int __thiscall sub_587F80(int this, int a2, char *a3)
{
  int v5; // eax
  double *v6; // edi
  double v7; // st7
  double *v8; // edi
  double *v9; // ebx
  double v10; // st7
  double v11; // st6
  double *v12; // edi
  double *v13; // ebx
  double v14; // st7
  double v15; // st6
  int v16; // eax
  int v17; // edx
  int v18; // eax
  int v19; // edx
  int v20; // eax
  char v21; // [esp+17h] [ebp-491h]
  int v22; // [esp+18h] [ebp-490h]
  double *v23; // [esp+1Ch] [ebp-48Ch]
  _BYTE v24[96]; // [esp+20h] [ebp-488h] BYREF
  _BYTE v25[512]; // [esp+80h] [ebp-428h] BYREF
  int v26; // [esp+280h] [ebp-228h]
  char v27; // [esp+284h] [ebp-224h]
  int v28; // [esp+28Ch] [ebp-21Ch]
  int v29; // [esp+290h] [ebp-218h]
  int v30; // [esp+294h] [ebp-214h]
  char Buffer[516]; // [esp+298h] [ebp-210h] BYREF
  int v32; // [esp+4A4h] [ebp-4h]

  sub_613B30(v24);
  memset(Buffer, 0, 0x200u);
  v21 = 0;
  v32 = 0;
  v26 = 0;
  v30 = 0;
  v28 = 0;
  v29 = 0;
  v27 = 1;
  if ( !(unsigned __int8)sub_614460(a2, 1) )
  {
    v32 = -1;
    sub_614140(v24);
    return -1;
  }
  v22 = 0;
  if ( !sub_613DE0(Buffer, 512) )
    goto LABEL_57;
  v23 = (double *)(this + 1944);
  do
  {
    v5 = sub_612EB0(v25);
    if ( v5 == 1 )
      break;
    if ( !v5 )
    {
      sub_6136D0("FuelConsumption", this + 1856, 0, 0, 0);
      sub_6136D0("FuelEstimate", this + 1864, 0, 0, 0);
      sub_6136D0("EngineInertia", this + 1872, 0, 0, 0);
      v6 = (double *)(this + 1896);
      if ( sub_6136D0("IdleThrottle", this + 1896, 0, 0, 0) )
      {
        if ( *v6 < 0.0 )
        {
          v7 = 0.0;
          goto LABEL_12;
        }
        if ( *v6 > 1.0 )
        {
          v7 = 1.0;
LABEL_12:
          *v6 = v7;
        }
      }
      v8 = (double *)(this + 1888);
      v9 = (double *)(this + 1880);
      if ( sub_6136D0("IdleRPMLogic", this + 1880, this + 1888, 0, 0) )
      {
        v10 = *v9 * 0.1047197551196598;
        *v9 = v10;
        v11 = *v8 * 0.1047197551196598;
        *v8 = v11;
        if ( v11 <= v10
          && dword_B640C0 != 5
          && sub_5612D0(byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\vehload.cpp", 682) )
        {
          sub_561210((int)byte_FAE910, "Bad engine idle range");
        }
      }
      sub_6136D0("LaunchEfficiency", this + 1904, 0, 0, 0);
      v12 = (double *)(this + 1920);
      v13 = (double *)(this + 1912);
      if ( sub_6136D0("LaunchRPMLogic", this + 1912, this + 1920, 0, 0) )
      {
        v14 = *v13 * 0.1047197551196598;
        *v13 = v14;
        v15 = *v12 * 0.1047197551196598;
        *v12 = v15;
        if ( v15 <= v14
          && dword_B640C0 != 5
          && sub_5612D0(byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\vehload.cpp", 694) )
        {
          sub_561210((int)byte_FAE910, "Bad engine launch range");
        }
      }
      if ( sub_6136D0("RevLimitLogic", this + 1928, 0, 0, 0) )
        *(double *)(this + 1928) = *(double *)(this + 1928) * 0.1047197551196598;
      if ( sub_613240("RevLimitAvailable", this + 1936, 0, 0, 0) )
        a3[6920] = *(_BYTE *)(this + 1936);
      if ( sub_6136D0("RPMTorque", (int)v23, (int)(v23 + 1), (int)(v23 + 2), 0) )
      {
        *v23 = *v23 * 0.1047197551196598;
        if ( v22 >= 127
          && dword_B640C0 != 5
          && sub_5612D0(byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\vehload.cpp", 711) )
        {
          sub_561210((int)byte_FAE910, "Too many RPM-torque points @ %f", *v23 * 9.549296585513721);
        }
        if ( v23[2] < v23[1]
          && dword_B640C0 != 5
          && sub_5612D0(byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\vehload.cpp", 717) )
        {
          sub_561210((int)byte_FAE910, "RPM-torque brake > throttle @ %f", *v23 * 9.549296585513721);
        }
        if ( v22 > 0
          && *v23 <= *(v23 - 3)
          && dword_B640C0 != 5
          && sub_5612D0(byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\vehload.cpp", 723) )
        {
          sub_561210((int)byte_FAE910, "RPM-torque curve out of order @ %f", *v23 * 9.549296585513721);
        }
        ++v22;
        v23 += 3;
      }
      if ( sub_6136D0("LifetimeEngineRPM", this + 5088, this + 5096, 0, 0) )
      {
        *(double *)(this + 5088) = *(double *)(this + 5088) * 0.1047197551196598;
        *(double *)(this + 5096) = *(double *)(this + 5096) * 0.1047197551196598;
      }
      if ( sub_6136D0("LifetimeOilTemp", this + 5104, this + 5112, 0, 0) )
        *(double *)(this + 5104) = *(double *)(this + 5104) + 273.16;
      sub_6136D0("LifetimeAvg", this + 5120, 0, 0, 0);
      sub_6136D0("LifetimeVar", this + 5128, 0, 0, 0);
      if ( sub_6136D0("EngineEmission", this + 5136, this + 5144, this + 5152, 0) && !v21 )
      {
        v16 = *(_DWORD *)(this + 5140);
        *(_DWORD *)(this + 5160) = *(_DWORD *)(this + 5136);
        v17 = *(_DWORD *)(this + 5144);
        *(_DWORD *)(this + 5164) = v16;
        v18 = *(_DWORD *)(this + 5148);
        *(_DWORD *)(this + 5168) = v17;
        v19 = *(_DWORD *)(this + 5152);
        *(_DWORD *)(this + 5172) = v18;
        v20 = *(_DWORD *)(this + 5156);
        *(_DWORD *)(this + 5176) = v19;
        *(_DWORD *)(this + 5180) = v20;
      }
      if ( sub_6136D0("EngineSound", this + 5160, this + 5168, this + 5176, 0) )
        v21 = 1;
      sub_613240("OnboardStarter", this + 5185, 0, 0, 0);
      sub_6136D0("StarterTiming", this + 5192, this + 5200, this + 5208, 0);
      if ( sub_6136D0("OptimumOilTemp", this + 5016, 0, 0, 0) )
        *(double *)(this + 5016) = *(double *)(this + 5016) + 273.16;
      sub_6136D0("CombustionHeat", this + 5024, 0, 0, 0);
      sub_6136D0("EngineSpeedHeat", this + 5032, 0, 0, 0);
      sub_6136D0("OilMinimumCooling", this + 5040, 0, 0, 0);
      sub_6136D0("OilWaterHeatTransfer", this + 5048, this + 5056, 0, 0);
      sub_6136D0("WaterMinimumCooling", this + 5064, 0, 0, 0);
      sub_6136D0("RadiatorCooling", this + 5072, this + 5080, 0, 0);
      sub_587F00((int)v25, a3);
    }
  }
  while ( sub_613DE0(Buffer, 512) );
  if ( v22 > 0 )
    *(_DWORD *)(this + 1940) = v22;
LABEL_57:
  sub_613C30(v24);
  v32 = -1;
  sub_614140(v24);
  return 0;
}
