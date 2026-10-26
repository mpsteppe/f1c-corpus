int __thiscall sub_4F3C80(int this, int a2, char *a3)
{
  int v5; // eax
  double *v6; // edi
  double *v7; // edi
  double *v8; // ebx
  double v9; // st7
  double v10; // st6
  double *v11; // edi
  double *v12; // ebx
  double v13; // st7
  double v14; // st6
  int v15; // [esp+18h] [ebp-340h]
  double *v16; // [esp+1Ch] [ebp-33Ch]
  _BYTE v17[28]; // [esp+24h] [ebp-334h] BYREF
  _BYTE v18[384]; // [esp+40h] [ebp-318h] BYREF
  int v19; // [esp+1C0h] [ebp-198h]
  char v20; // [esp+1C4h] [ebp-194h]
  int v21; // [esp+1CCh] [ebp-18Ch]
  int v22; // [esp+1D0h] [ebp-188h]
  int v23; // [esp+1D4h] [ebp-184h]
  _BYTE v24[384]; // [esp+1D8h] [ebp-180h] BYREF

  sub_5668B0(v17);
  memset(v24, 0, sizeof(v24));
  v19 = 0;
  v23 = 0;
  v21 = 0;
  v22 = 0;
  v20 = 1;
  if ( !(unsigned __int8)sub_566B20(a2, 0) )
  {
    sub_5668D0(v17);
    return -1;
  }
  v15 = 0;
  if ( !sub_566CC0(v24, 384) )
    goto LABEL_50;
  v16 = (double *)(this + 1736);
  do
  {
    v5 = sub_5651B0(v18);
    if ( v5 == 1 )
      break;
    if ( !v5 )
    {
      sub_565AA0(aFuelconsumptio, this + 1652, 0, 0, 0);
      sub_565AA0(aFuelestimate, this + 1660, 0, 0, 0);
      sub_565AA0(aEngineinertia, this + 1668, 0, 0, 0);
      v6 = (double *)(this + 1692);
      if ( sub_565AA0(aIdlethrottle, this + 1692, 0, 0, 0) )
      {
        if ( *v6 < 0.0 )
        {
          *(_DWORD *)(this + 1696) = 0;
          goto LABEL_12;
        }
        if ( *v6 > 1.0 )
        {
          *(_DWORD *)(this + 1696) = 1072693248;
LABEL_12:
          *(_DWORD *)v6 = 0;
        }
      }
      v7 = (double *)(this + 1684);
      v8 = (double *)(this + 1676);
      if ( sub_565AA0(aIdlerpmlogic, this + 1676, this + 1684, 0, 0) )
      {
        v9 = *v8 * 0.1047197551196598;
        *v8 = v9;
        v10 = *v7 * 0.1047197551196598;
        *v7 = v10;
        if ( v10 <= v9 && dword_7C569C != 5 && sub_4D7A50(dword_8AD25C, 1, (int)aDDevF119992002_7, 599) )
          sub_4D7AA0((int)dword_8AD25C, (int)aBadEngineIdleR);
      }
      sub_565AA0(aLaunchefficien, this + 1700, 0, 0, 0);
      v11 = (double *)(this + 1716);
      v12 = (double *)(this + 1708);
      if ( sub_565AA0(aLaunchrpmlogic, this + 1708, this + 1716, 0, 0) )
      {
        v13 = *v12 * 0.1047197551196598;
        *v12 = v13;
        v14 = *v11 * 0.1047197551196598;
        *v11 = v14;
        if ( v14 <= v13 && dword_7C569C != 5 && sub_4D7A50(dword_8AD25C, 1, (int)aDDevF119992002_7, 611) )
          sub_4D7AA0((int)dword_8AD25C, (int)aBadEngineLaunc);
      }
      if ( sub_565AA0(aRevlimitlogic, this + 1724, 0, 0, 0) )
        *(double *)(this + 1724) = *(double *)(this + 1724) * 0.1047197551196598;
      if ( sub_565AA0(aRpmtorque, v16, v16 + 1, v16 + 2, 0) )
      {
        *v16 = *v16 * 0.1047197551196598;
        if ( v15 >= 127 && dword_7C569C != 5 && sub_4D7A50(dword_8AD25C, 1, (int)aDDevF119992002_7, 626) )
          sub_4D7AA0((int)dword_8AD25C, (int)"Too many RPM-torque points @ %f", *v16 * 9.549296585513721);
        if ( v16[2] < v16[1] && dword_7C569C != 5 && sub_4D7A50(dword_8AD25C, 1, (int)aDDevF119992002_7, 632) )
          sub_4D7AA0((int)dword_8AD25C, (int)"RPM-torque brake > throttle @ %f", *v16 * 9.549296585513721);
        if ( v15 > 0
          && *v16 <= *(v16 - 3)
          && dword_7C569C != 5
          && sub_4D7A50(dword_8AD25C, 1, (int)aDDevF119992002_7, 638) )
        {
          sub_4D7AA0((int)dword_8AD25C, (int)"RPM-torque curve out of order @ %f", *v16 * 9.549296585513721);
        }
        ++v15;
        v16 += 3;
      }
      if ( sub_565AA0(aLifetimeengine, this + 4880, this + 4888, 0, 0) )
      {
        *(double *)(this + 4880) = *(double *)(this + 4880) * 0.1047197551196598;
        *(double *)(this + 4888) = *(double *)(this + 4888) * 0.1047197551196598;
      }
      if ( sub_565AA0(aLifetimeoiltem, this + 4896, this + 4904, 0, 0) )
        *(double *)(this + 4896) = *(double *)(this + 4896) + 273.16;
      sub_565AA0(aLifetimeavg, this + 4912, 0, 0, 0);
      sub_565AA0(aLifetimevar, this + 4920, 0, 0, 0);
      sub_565AA0(aEngineemission, this + 4928, this + 4936, this + 4944, 0);
      sub_5655F0(aOnboardstarter, this + 4952, 0, 0, 0);
      sub_565AA0(aStartertiming, this + 4956, this + 4964, this + 4972, 0);
      if ( sub_565AA0(aOptimumoiltemp, this + 4808, 0, 0, 0) )
        *(double *)(this + 4808) = *(double *)(this + 4808) + 273.16;
      sub_565AA0(aCombustionheat, this + 4816, 0, 0, 0);
      sub_565AA0(aEnginespeedhea, this + 4824, 0, 0, 0);
      sub_565AA0(aOilminimumcool, this + 4832, 0, 0, 0);
      sub_565AA0(aOilwaterheattr, this + 4840, this + 4848, 0, 0);
      sub_565AA0(aWaterminimumco, this + 4856, 0, 0, 0);
      sub_565AA0(aRadiatorcoolin, this + 4864, this + 4872, 0, 0);
      sub_4F3C10((int)v18, a3);
    }
  }
  while ( sub_566CC0(v24, 384) );
  if ( v15 > 0 )
    *(_DWORD *)(this + 1732) = v15;
LABEL_50:
  sub_566B90(v17);
  sub_5668D0(v17);
  return 0;
}
