int __thiscall sub_521110(int this, char *Source, char *a3, float a4, float a5)
{
  int v7; // eax
  double *v8; // edi
  double *v9; // edi
  double *v10; // ebx
  double v11; // st7
  double v12; // st6
  double *v13; // edi
  double *v14; // ebx
  double v15; // st7
  double v16; // st6
  double *v17; // edi
  double *v18; // [esp+14h] [ebp-33Ch]
  int v19; // [esp+18h] [ebp-338h]
  _BYTE v20[28]; // [esp+1Ch] [ebp-334h] BYREF
  int v21[97]; // [esp+38h] [ebp-318h] BYREF
  char v22; // [esp+1BCh] [ebp-194h]
  int v23; // [esp+1C4h] [ebp-18Ch]
  int v24; // [esp+1C8h] [ebp-188h]
  int v25; // [esp+1CCh] [ebp-184h]
  char Buffer[384]; // [esp+1D0h] [ebp-180h] BYREF

  sub_57A080(v20);
  memset(Buffer, 0, sizeof(Buffer));
  v21[96] = 0;
  v25 = 0;
  v23 = 0;
  v24 = 0;
  v22 = 1;
  if ( !(unsigned __int8)sub_57A2F0(Source, 0) )
  {
    sub_57A0A0(v20);
    return -1;
  }
  v19 = 0;
  if ( !sub_57A490(Buffer, 384) )
    goto LABEL_52;
  v18 = (double *)(this + 1832);
  do
  {
    v7 = sub_577B60(v21);
    if ( v7 == 1 )
      break;
    if ( !v7 )
    {
      sub_578450(aFuelconsumptio, this + 1740, 0, 0, 0);
      sub_578450(aFuelestimate, this + 1748, 0, 0, 0);
      if ( sub_578450(aEngineinertia, this + 1756, 0, 0, 0) )
        *(double *)(this + 1756) = a5 * *(double *)(this + 1756);
      v8 = (double *)(this + 1780);
      if ( sub_578450(aIdlethrottle, this + 1780, 0, 0, 0) )
      {
        *v8 = a4 * *v8;
        if ( *v8 < 0.0 )
        {
          *(_DWORD *)(this + 1784) = 0;
          goto LABEL_14;
        }
        if ( *v8 > 1.0 )
        {
          *(_DWORD *)(this + 1784) = 1072693248;
LABEL_14:
          *(_DWORD *)v8 = 0;
        }
      }
      v9 = (double *)(this + 1772);
      v10 = (double *)(this + 1764);
      if ( sub_578450(aIdlerpmlogic, this + 1764, this + 1772, 0, 0) )
      {
        v11 = a4 * *v10 * 0.1047197551196598;
        *v10 = v11;
        v12 = a4 * *v9 * 0.1047197551196598;
        *v9 = v12;
        if ( v12 <= v11 && dword_75CBA8 != 5 && sub_500F90(&unk_7D7920, 1, aDDevNascar2004_25, 673) )
          sub_500FE0((int)&unk_7D7920, aBadEngineIdleR);
      }
      sub_578450(aLaunchefficien, this + 1788, 0, 0, 0);
      v13 = (double *)(this + 1804);
      v14 = (double *)(this + 1796);
      if ( sub_578450(aLaunchrpmlogic, this + 1796, this + 1804, 0, 0) )
      {
        v15 = a4 * *v14 * 0.1047197551196598;
        *v14 = v15;
        v16 = a4 * *v13 * 0.1047197551196598;
        *v13 = v16;
        if ( v16 <= v15 && dword_75CBA8 != 5 && sub_500F90(&unk_7D7920, 1, aDDevNascar2004_25, 688) )
          sub_500FE0((int)&unk_7D7920, aBadEngineLaunc);
      }
      if ( sub_578450(aRevlimitlogic, this + 1812, 0, 0, 0) )
        *(double *)(this + 1812) = a4 * *(double *)(this + 1812) * 0.1047197551196598;
      v17 = v18 - 1;
      if ( sub_578450(aRpmtorque, (int)(v18 - 1), (int)v18, (int)(v18 + 1), 0) )
      {
        *v18 = a5 * *v18;
        v18[1] = a5 * v18[1];
        *v17 = a4 * *v17 * 0.1047197551196598;
        if ( v19 >= 127 && dword_75CBA8 != 5 && sub_500F90(&unk_7D7920, 1, aDDevNascar2004_25, 710) )
          sub_500FE0((int)&unk_7D7920, "Too many RPM-torque points @ %f", *v17 * 9.549296585513721);
        if ( v18[1] < *v18 && dword_75CBA8 != 5 && sub_500F90(&unk_7D7920, 1, aDDevNascar2004_25, 716) )
          sub_500FE0((int)&unk_7D7920, "RPM-torque brake > throttle @ %f", *v17 * 9.549296585513721);
        if ( v19 > 0 && *v17 <= *(v18 - 4) && dword_75CBA8 != 5 && sub_500F90(&unk_7D7920, 1, aDDevNascar2004_25, 722) )
          sub_500FE0((int)&unk_7D7920, "RPM-torque curve out of order @ %f", *v17 * 9.549296585513721);
        ++v19;
        v18 += 3;
      }
      if ( sub_578450(aLifetimeengine, this + 4968, this + 4976, 0, 0) )
      {
        *(double *)(this + 4968) = a4 * *(double *)(this + 4968) * 0.1047197551196598;
        *(double *)(this + 4976) = a4 * *(double *)(this + 4976) * 0.1047197551196598;
      }
      if ( sub_578450(aLifetimeoiltem, this + 4984, this + 4992, 0, 0) )
        *(double *)(this + 4984) = *(double *)(this + 4984) + 273.16;
      sub_578450(aLifetimeavg, this + 5000, 0, 0, 0);
      sub_578450(aLifetimevar, this + 5008, 0, 0, 0);
      sub_578450(aEngineemission, this + 5016, this + 5024, this + 5032, 0);
      sub_577FA0(aOnboardstarter, this + 5041, 0, 0, 0);
      sub_578450(aStartertiming, this + 5044, this + 5052, this + 5060, 0);
      if ( sub_578450(aOptimumoiltemp, this + 4896, 0, 0, 0) )
        *(double *)(this + 4896) = *(double *)(this + 4896) + 273.16;
      sub_578450(aCombustionheat, this + 4904, 0, 0, 0);
      sub_578450(aEnginespeedhea, this + 4912, 0, 0, 0);
      sub_578450(aOilminimumcool, this + 4920, 0, 0, 0);
      sub_578450(aOilwaterheattr, this + 4928, this + 4936, 0, 0);
      sub_578450(aWaterminimumco, this + 4944, 0, 0, 0);
      sub_578450(aRadiatorcoolin, this + 4952, this + 4960, 0, 0);
      sub_5210A0((int)v21, a3, a4);
    }
  }
  while ( sub_57A490(Buffer, 384) );
  if ( v19 > 0 )
    *(_DWORD *)(this + 1820) = v19;
LABEL_52:
  sub_57A360(v20);
  sub_57A0A0(v20);
  return 0;
}
