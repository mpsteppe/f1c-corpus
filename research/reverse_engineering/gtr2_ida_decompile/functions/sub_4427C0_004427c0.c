int __fastcall sub_4427C0(int a1, int a2, unsigned int a3)
{
  int result; // eax
  int v5; // eax
  double *v6; // esi
  int v7; // edi
  double v8; // st7
  int v9; // eax
  int v10; // ecx
  double v11; // st7
  unsigned __int8 v13; // c0
  unsigned __int8 v14; // c3
  double v15; // st7
  double v16; // st6
  double v17; // st7
  double v18; // st6
  double v19; // st6
  double v20; // st6
  double v21; // st7
  double v22; // st7
  double v23; // st7
  int v24; // edx
  double v25; // st7
  float *v26; // ecx
  char v27; // [esp+10h] [ebp-78h]
  double v28; // [esp+1Ch] [ebp-6Ch]
  double v29; // [esp+24h] [ebp-64h]
  double v30; // [esp+28h] [ebp-60h]
  double v31; // [esp+28h] [ebp-60h]
  _BYTE v32[12]; // [esp+2Ch] [ebp-5Ch]
  _BYTE v33[12]; // [esp+38h] [ebp-50h] BYREF
  double v34; // [esp+44h] [ebp-44h]

  LODWORD(v34) = a1;
  if ( a3 <= 1 )
    return off_16C9540(a3);
  v5 = sub_560800(*(_DWORD *)(a1 + 5904));
  v6 = (double *)(v5 + 496 * a3 + 24);
  v7 = 1280 * a3 + a1 + 712;
  *(double *)(v7 + 536) = *(double *)(v5 + 496 * a3 + 56);
  *(double *)(v7 + 544) = *(double *)(v5 + 496 * a3 + 64);
  *(double *)(v7 + 552) = *(double *)(v5 + 496 * a3 + 72) * 0.45;
  *(double *)(v7 + 560) = *(double *)(v5 + 496 * a3 + 72) * 0.15;
  v8 = *(double *)(v7 + 1008);
  sub_55F260(v8);
  *(double *)(v7 + 568) = v8;
  *(double *)(v7 + 576) = v6[9];
  *(double *)(v7 + 584) = v6[13];
  *(double *)(v7 + 592) = v6[14];
  *(double *)v32 = v6[12];
  v29 = v6[11];
  v28 = v6[10];
  sub_55F390(v7 + 600);
  *(double *)(v7 + 1256) = *v6;
  *(double *)(v7 + 672) = *v6;
  *(double *)(v7 + 680) = *v6 - v6[2];
  *(double *)(v7 + 1264) = v6[1];
  *(double *)(v7 + 688) = v6[1];
  *(double *)(v7 + 696) = v6[1] - v6[3];
  *(double *)&v33[4] = v6[1] + *v6;
  v34 = v6[3] + v6[2];
  sub_55F550(
    v7 + 704,
    COERCE_UNSIGNED_INT64(v6[15]),
    HIDWORD(COERCE_UNSIGNED_INT64(v6[15])),
    COERCE_UNSIGNED_INT64(v6[16]),
    HIDWORD(COERCE_UNSIGNED_INT64(v6[16])),
    COERCE_UNSIGNED_INT64(v6[17]),
    HIDWORD(COERCE_UNSIGNED_INT64(v6[17])));
  sub_55F550(
    v7 + 736,
    COERCE_UNSIGNED_INT64(v6[18]),
    HIDWORD(COERCE_UNSIGNED_INT64(v6[18])),
    COERCE_UNSIGNED_INT64(v6[19]),
    HIDWORD(COERCE_UNSIGNED_INT64(v6[19])),
    COERCE_UNSIGNED_INT64(v6[20]),
    HIDWORD(COERCE_UNSIGNED_INT64(v6[20])));
  *(_DWORD *)(v7 + 768) = sub_560860(*(_DWORD *)(HIDWORD(v29) + 5896), v6 + 50);
  *(_DWORD *)(v7 + 772) = sub_560860(*(_DWORD *)(LODWORD(v29) + 5896), v6 + 54);
  v9 = sub_560860(*(_DWORD *)(HIDWORD(v28) + 5896), v6 + 58);
  v10 = *(_DWORD *)(v7 + 768);
  *(_DWORD *)(v7 + 776) = v9;
  if ( (!v10 || !*(_DWORD *)(v7 + 772) || !v9)
    && dword_B640C0 != 5
    && (unsigned __int8)sub_5612D0((int)byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\hdvehicle.cpp", 4708) )
  {
    sub_561210((int)byte_FAE910, "Could not find one of tire slip curves %s/%s/%s", (_BYTE)v6 - 112);
  }
  sub_55FEB0(1.0, 0.0001);
  sub_55FEB0(1.0, 0.0001);
  sub_55FEB0(1.0, 0.0001);
  *(double *)(v7 + 784) = 1.0 / ((1.0 + 1.0 + 1.0 + 1.0) * 2500.0);
  *(double *)(v7 + 792) = v6[22] * v6[21];
  *(double *)(v7 + 800) = 1.0 - v6[21];
  if ( v6[23] >= 1.570796326794897
    && dword_B640C0 != 5
    && (unsigned __int8)sub_5612D0((int)byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\hdvehicle.cpp", 4729) )
  {
    sub_561210((int)byte_FAE910, "Tire optimum camber angle should be less than 90 degrees", v27);
  }
  v11 = v6[23];
  *(double *)(v7 + 816) = v11;
  if ( v13 | v14 )
    *(double *)(v7 + 832) = 0.0;
  else
    *(double *)(v7 + 832) = 1.570796326794897 / v11;
  *(double *)(v7 + 808) = v6[24];
  *(double *)(v7 + 824) = v6[25] * 0.6366197723675814;
  *(double *)(v7 + 840) = 3.141592653589793 / (1.570796326794897 - *(double *)(v7 + 816));
  if ( *(_DWORD *)dword_B72314 == 7 )
  {
    if ( byte_B731C8 )
      goto LABEL_21;
  }
  else if ( *(_DWORD *)dword_B72314 == 8 )
  {
    goto LABEL_21;
  }
  if ( dword_B72338 )
  {
    v30 = v6[43];
    v15 = *(double *)(v7 + 1008);
    goto LABEL_23;
  }
LABEL_21:
  v30 = *(double *)(v7 + 888) - 273.16;
  v15 = 200.0;
  *(double *)(v7 + 1168) = (double)150 + 273.16;
LABEL_23:
  *(double *)(v7 + 880) = v30 + 273.16;
  *(double *)(v7 + 960) = v30 + 273.16;
  *(double *)(v7 + 968) = *(double *)(v7 + 880);
  *(double *)(v7 + 976) = *(double *)(v7 + 880);
  v16 = *(double *)(v7 + 880);
  *(double *)(v7 + 984) = v16;
  *(double *)(v7 + 296) = 14.0;
  *(double *)(v7 + 1000) = v15;
  *(double *)(v7 + 992) = v15 / v16;
  *(double *)(v7 + 1016) = v6[7];
  *(double *)(v7 + 1024) = v6[8];
  if ( dword_B6FC28 )
  {
    *(double *)(v7 + 1016) = *(double *)(v7 + 1016) * 0.9200000166893005;
    *(double *)(v7 + 1024) = *(double *)(v7 + 1024) * 0.9200000166893005;
    *(double *)(v7 + 576) = *(double *)(v7 + 576) * 0.9200000166893005;
    *(double *)(v7 + 296) = 17.5;
  }
  if ( (a3 != 2 && a3 != 3 || sub_53A2B0((int)&v33[8], 32, "RearTireHeatMult", 0))
    && sub_53A2B0((int)&v33[8], 32, "TireHeatMult", 0) )
  {
    v17 = 1.0;
  }
  else
  {
    v17 = atof(&v33[8]);
  }
  *(double *)(v7 + 304) = 1.0 / *(double *)(v7 + 296);
  v18 = v6[42] + 273.16;
  *(double *)(v7 + 888) = v18;
  if ( v6[42] <= 0.0 )
    v19 = 0.0;
  else
    v19 = 1.0 / v18;
  *(double *)(v7 + 896) = v19;
  *(double *)(v7 + 904) = -(v19 * v6[46]);
  *(double *)(v7 + 912) = v19 * v6[47];
  *(double *)(v7 + 920) = v6[49] + 273.16;
  *(double *)(v7 + 928) = v6[44];
  *(double *)(v7 + 936) = v6[45];
  v20 = v6[48];
  *(_BYTE *)(v7 + 952) = 0;
  *(double *)(v7 + 944) = v20;
  *(double *)(v7 + 1272) = v6[26];
  *(double *)(v7 + 872) = v6[26];
  *(double *)(v7 + 1064) = v17 * v6[27];
  *(double *)(v7 + 1072) = v17 * v6[28] * *(double *)(v7 + 784);
  *(double *)(v7 + 1080) = v6[29];
  *(double *)(v7 + 1088) = v6[30];
  *(double *)(v7 + 1096) = v6[31];
  if ( v6[32] <= 0.0 )
    v21 = 0.0;
  else
    v21 = 1.0 / v6[32];
  *(double *)(v7 + 1048) = v21;
  if ( v6[33] <= 0.0 )
    v22 = 0.0;
  else
    v22 = 1.0 / v6[33];
  *(double *)(v7 + 1056) = v22;
  *(double *)(v7 + 1104) = v6[34];
  *(double *)(v7 + 1112) = (double)dword_B72F4C * v6[35] * flt_BE27A4 * *(double *)(v7 + 784);
  *(double *)(v7 + 1032) = 1.0;
  v23 = *(double *)(v7 + 992) * *(double *)(v7 + 984);
  *(double *)(v7 + 1000) = v23;
  *(double *)(v7 + 568) = v23 * *(double *)(v7 + 1024) + *(double *)(v7 + 1016);
  v24 = dword_BE2730;
  v25 = 0.0;
  if ( dword_BE2730 > 0 )
  {
    v26 = (float *)(dword_BE2734 + 12);
    do
    {
      v31 = *(v26 - 1) - *v26;
      if ( v25 < v31 )
        v25 = v31;
      v26 += 26;
      --v24;
    }
    while ( v24 );
  }
  result = LODWORD(v28);
  *(double *)(LODWORD(v28) + 192) = v25 / *(double *)&v32[4] * *(double *)v33;
  return result;
}
