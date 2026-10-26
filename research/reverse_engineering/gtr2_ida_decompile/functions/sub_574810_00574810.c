int __thiscall sub_574810(int this)
{
  long double v2; // st7
  int v3; // ecx
  unsigned int v4; // eax
  int v5; // eax
  int v6; // ecx
  double v7; // st7
  int v8; // eax
  int v9; // eax
  double v10; // st7
  double v11; // st7
  double v12; // st7
  double v13; // st7
  double v14; // st7
  int result; // eax
  double v16; // st7
  double v17; // st6
  double v18; // st5
  double v19; // st7
  int v20; // ecx
  double v21; // [esp+8h] [ebp-18h] BYREF
  double v22; // [esp+10h] [ebp-10h]
  double v23; // [esp+18h] [ebp-8h]

  sub_43A370((double *)(dword_B678E8 + 32), (double *)(dword_B678E8 + 8), &dbl_B678F8, &v21);
  *(float *)(this + 15972) = v21;
  *(float *)(this + 15976) = v22;
  *(float *)(this + 15980) = v23;
  *(float *)(this + 15936) = *(double *)(dword_B678E8 + 32);
  *(float *)(this + 15940) = *(double *)(dword_B678E8 + 40);
  *(float *)(this + 15944) = *(double *)(dword_B678E8 + 48);
  *(float *)(this + 15948) = *(double *)(dword_B678E8 + 56);
  *(float *)(this + 15952) = *(double *)(dword_B678E8 + 64);
  *(float *)(this + 15956) = *(double *)(dword_B678E8 + 72);
  *(float *)(this + 15960) = *(double *)(dword_B678E8 + 80);
  *(float *)(this + 15964) = *(double *)(dword_B678E8 + 88);
  *(float *)(this + 15968) = *(double *)(dword_B678E8 + 96);
  *(float *)(this + 15984) = -asin(*(float *)(this + 15956));
  if ( 1.0 == fabs(*(float *)(this + 15956)) )
  {
    v2 = atan2(-*(float *)(this + 15960), *(float *)(this + 15936));
    *(_DWORD *)(this + 15992) = 0;
    *(float *)(this + 15988) = v2;
  }
  else
  {
    *(float *)(this + 15988) = atan2(*(float *)(this + 15944), *(float *)(this + 15968));
    *(float *)(this + 15992) = atan2(*(float *)(this + 15948), *(float *)(this + 15952));
  }
  v3 = *(_DWORD *)(dword_B678E8 + 108);
  LODWORD(v21) = *(_DWORD *)(dword_B678E8 + 104);
  v4 = *(_DWORD *)(dword_B678E8 + 112);
  HIDWORD(v21) = v3;
  v22 = COERCE_DOUBLE(__PAIR64__(*(_DWORD *)(dword_B678E8 + 116), v4));
  v5 = *(_DWORD *)(dword_B678E8 + 120);
  v6 = *(_DWORD *)(dword_B678E8 + 124);
  *(float *)(this + 15996) = v21;
  LODWORD(v23) = v5;
  *(float *)(this + 16000) = v22;
  HIDWORD(v23) = v6;
  *(float *)(this + 16004) = v23;
  *(float *)(this + 16008) = *(float *)(this + 15960) * *(float *)(this + 16004)
                           + *(float *)(this + 15948) * *(float *)(this + 16000)
                           + *(float *)(this + 15936) * *(float *)(this + 15996);
  *(float *)(this + 16012) = *(float *)(this + 15964) * *(float *)(this + 16004)
                           + *(float *)(this + 15952) * *(float *)(this + 16000)
                           + *(float *)(this + 15940) * *(float *)(this + 15996);
  *(float *)(this + 16016) = *(float *)(this + 15968) * *(float *)(this + 16004)
                           + *(float *)(this + 15956) * *(float *)(this + 16000)
                           + *(float *)(this + 15944) * *(float *)(this + 15996);
  v21 = *(double *)(dword_B678E8 + 80) * *(double *)(dword_B678E8 + 144)
      + *(double *)(dword_B678E8 + 56) * *(double *)(dword_B678E8 + 136)
      + *(double *)(dword_B678E8 + 128) * *(double *)(dword_B678E8 + 32);
  v22 = *(double *)(dword_B678E8 + 40) * *(double *)(dword_B678E8 + 128)
      + *(double *)(dword_B678E8 + 88) * *(double *)(dword_B678E8 + 144)
      + *(double *)(dword_B678E8 + 64) * *(double *)(dword_B678E8 + 136);
  v23 = *(double *)(dword_B678E8 + 48) * *(double *)(dword_B678E8 + 128)
      + *(double *)(dword_B678E8 + 96) * *(double *)(dword_B678E8 + 144)
      + *(double *)(dword_B678E8 + 72) * *(double *)(dword_B678E8 + 136);
  v7 = v22;
  *(float *)(this + 16020) = v21;
  *(float *)(this + 16024) = v7;
  *(float *)(this + 16028) = v23;
  *(float *)(this + 16196) = dbl_B663C8;
  *(_DWORD *)(this + 0x4000) = dword_B66588;
  *(float *)(this + 16220) = dbl_B66440;
  *(float *)(this + 16224) = dbl_B66448;
  *(float *)(this + 16228) = dbl_B66450;
  *(float *)(this + 16240) = dbl_B66798;
  *(float *)(this + 16448) = dbl_B668C8;
  *(_DWORD *)(this + 16636) = dword_B66A88;
  *(float *)(this + 16472) = dbl_B66940;
  *(float *)(this + 16476) = dbl_B66948;
  *(float *)(this + 16480) = dbl_B66950;
  *(float *)(this + 16492) = dbl_B66C98;
  *(float *)(this + 16700) = dbl_B66DC8;
  *(_DWORD *)(this + 16888) = dword_B66F88;
  *(float *)(this + 16724) = dbl_B66E40;
  *(float *)(this + 16728) = dbl_B66E48;
  *(float *)(this + 16732) = dbl_B66E50;
  *(float *)(this + 16744) = dbl_B67198;
  *(float *)(this + 16952) = dbl_B672C8;
  *(_DWORD *)(this + 17140) = dword_B67488;
  *(float *)(this + 16976) = dbl_B67340;
  *(float *)(this + 16980) = dbl_B67348;
  *(float *)(this + 16984) = dbl_B67350;
  *(float *)(this + 16996) = dbl_B67698;
  v8 = *(_DWORD *)(this + 17244);
  if ( !v8 )
  {
    v10 = *(float *)(this + 16952) + *(float *)(this + 16700);
LABEL_10:
    v11 = v10 * 0.5;
    goto LABEL_11;
  }
  v9 = v8 - 1;
  if ( v9 )
  {
    if ( v9 != 1 )
      goto LABEL_12;
    v10 = *(float *)(this + 16448) + *(float *)(this + 16196);
    goto LABEL_10;
  }
  v11 = (*(float *)(this + 16952) + *(float *)(this + 16700) + *(float *)(this + 16448) + *(float *)(this + 16196))
      * 0.25;
LABEL_11:
  *(float *)(this + 17160) = v11;
LABEL_12:
  *(_DWORD *)(this + 17304) = dword_B684E0;
  if ( dbl_B68210 >= 0.0 )
  {
    if ( dbl_B68210 <= dbl_B682A8 )
      v12 = dbl_B68210;
    else
      v12 = dbl_B682A8;
  }
  else
  {
    v12 = 0.0;
  }
  *(float *)(this + 17212) = v12;
  *(float *)(this + 16132) = dbl_B66048;
  *(float *)(this + 16136) = dbl_B660B8 * dbl_B66040;
  *(float *)(this + 16140) = dbl_B66050;
  if ( dbl_B68370 <= 0.0 )
  {
    if ( *(float *)(this + 18416) >= 0.0 )
      *(_DWORD *)(this + 18416) = -1082130432;
    *(float *)(this + 18388) = dbl_B683A0;
    *(float *)(this + 18392) = dbl_B683A8;
    *(float *)(this + 18396) = dbl_B683B0;
  }
  v13 = dbl_B66208;
  *(float *)(this + 17180) = dbl_B66208;
  v14 = v13 * 0.74000001 + *(float *)(this + 16068) + *(float *)(this + 16032);
  *(float *)(this + 16036) = v14;
  *(float *)(this + 16040) = 1.0 / v14;
  result = dword_B678E8;
  v16 = *(double *)(dword_B678E8 + 184);
  v21 = *(double *)(dword_B678E8 + 312);
  v17 = v21 * v16;
  v22 = *(double *)(dword_B678E8 + 320);
  v18 = v16;
  v19 = v16 * v22;
  v20 = *(_DWORD *)(dword_B678E8 + 332);
  LODWORD(v23) = *(_DWORD *)(dword_B678E8 + 328);
  HIDWORD(v23) = v20;
  v23 = v18 * v23;
  *(float *)(this + 16072) = v17;
  *(float *)(this + 16076) = v19;
  *(float *)(this + 16080) = v23;
  *(float *)(this + 16084) = *(float *)(this + 15960) * *(float *)(this + 16080)
                           + *(float *)(this + 15948) * *(float *)(this + 16076)
                           + *(float *)(this + 16072) * *(float *)(this + 15936);
  *(float *)(this + 16088) = *(float *)(this + 15964) * *(float *)(this + 16080)
                           + *(float *)(this + 15952) * *(float *)(this + 16076)
                           + *(float *)(this + 15940) * *(float *)(this + 16072);
  *(float *)(this + 16092) = *(float *)(this + 15968) * *(float *)(this + 16080)
                           + *(float *)(this + 15956) * *(float *)(this + 16076)
                           + *(float *)(this + 15944) * *(float *)(this + 16072);
  return result;
}
