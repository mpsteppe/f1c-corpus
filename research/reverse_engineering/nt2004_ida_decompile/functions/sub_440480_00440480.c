void __thiscall sub_440480(_DWORD *this, int a2)
{
  _DWORD *v2; // ebx
  int v3; // eax
  int v4; // esi
  int v5; // edi
  double v6; // st7
  double v7; // st7
  double v8; // st7
  double v9; // st6
  double v10; // st7
  int v11; // eax
  int v12; // ecx
  double v13; // st7
  unsigned __int8 v15; // c0
  unsigned __int8 v16; // c3
  _DWORD *v17; // eax
  int v18; // ecx
  double v19; // st7
  int v20; // ecx
  int v21; // edx
  double v22; // st6
  double v23; // st7
  double v24; // st7
  double v25; // st6
  double v26; // st6
  double v27; // st6
  unsigned __int8 v29; // c0
  unsigned __int8 v30; // c3
  double v31; // st7
  double v32; // st7
  double v33; // st7
  double v34; // st7
  float *v35; // ecx
  int v36; // edx
  double v37; // [esp-8h] [ebp-60h]
  char v38; // [esp+0h] [ebp-58h]
  double v40; // [esp+10h] [ebp-48h]
  double v41; // [esp+28h] [ebp-30h]
  double v42; // [esp+30h] [ebp-28h]
  char String[32]; // [esp+38h] [ebp-20h] BYREF

  v2 = this;
  v3 = sub_5009C0(this[1439]);
  v4 = (int)&v2[314 * a2 + 167];
  v5 = v3 + (a2 << 9) + 24;
  *(_DWORD *)(v4 + 524) = *(_DWORD *)(v3 + (a2 << 9) + 56);
  *(_DWORD *)(v4 + 528) = *(_DWORD *)(v3 + (a2 << 9) + 60);
  *(_DWORD *)(v4 + 532) = *(_DWORD *)(v3 + (a2 << 9) + 64);
  *(_DWORD *)(v4 + 536) = *(_DWORD *)(v3 + (a2 << 9) + 68);
  *(_DWORD *)(v4 + 572) = *(_DWORD *)(v3 + (a2 << 9) + 104);
  *(_DWORD *)(v4 + 576) = *(_DWORD *)(v3 + (a2 << 9) + 108);
  *(_DWORD *)(v4 + 580) = *(_DWORD *)(v3 + (a2 << 9) + 112);
  *(_DWORD *)(v4 + 584) = *(_DWORD *)(v3 + (a2 << 9) + 116);
  *(_DWORD *)(v4 + 588) = *(_DWORD *)(v3 + (a2 << 9) + 120);
  *(_DWORD *)(v4 + 592) = *(_DWORD *)(v3 + (a2 << 9) + 124);
  *(_DWORD *)(v4 + 596) = *(_DWORD *)(v3 + (a2 << 9) + 128);
  *(_DWORD *)(v4 + 600) = *(_DWORD *)(v3 + (a2 << 9) + 132);
  v6 = *(double *)(v3 + (a2 << 9) + 136);
  *(double *)(v4 + 604) = v6;
  if ( *(double *)&v2[314 * a2 + 314] >= 6.283185307179586 || v6 <= 0.0 )
  {
    v2[314 * a2 + 310] = 0;
    v2[314 * a2 + 311] = 0;
  }
  if ( *(double *)&v2[314 * a2 + 316] < 0.0 )
    *(double *)&v2[314 * a2 + 316] = *(double *)&v2[314 * a2 + 316] * -1.0;
  v37 = *(double *)&v2[314 * a2 + 417];
  *(double *)&v2[314 * a2 + 302] = *(double *)(v3 + (a2 << 9) + 72) * 0.45;
  v7 = *(double *)(v3 + (a2 << 9) + 72) * 0.15;
  *(double *)&v2[314 * a2 + 304] = v7;
  sub_4FFA70(v37);
  *(double *)&v2[314 * a2 + 306] = v7;
  v2[314 * a2 + 308] = *(_DWORD *)(v5 + 72);
  v2[314 * a2 + 309] = *(_DWORD *)(v5 + 76);
  v2[314 * a2 + 320] = *(_DWORD *)(v5 + 144);
  v2[314 * a2 + 321] = *(_DWORD *)(v5 + 148);
  v2[314 * a2 + 322] = *(_DWORD *)(v5 + 152);
  v2[314 * a2 + 323] = *(_DWORD *)(v5 + 156);
  sub_4FEAA0(*(double *)(v5 + 120), *(double *)(v5 + 128), *(double *)(v5 + 136));
  v2[314 * a2 + 475] = *(_DWORD *)v5;
  v2[314 * a2 + 476] = *(_DWORD *)(v5 + 4);
  v2[314 * a2 + 339] = *(_DWORD *)v5;
  v2[314 * a2 + 340] = *(_DWORD *)(v5 + 4);
  *(double *)&v2[314 * a2 + 341] = *(double *)v5 - *(double *)(v5 + 16);
  v2[314 * a2 + 477] = *(_DWORD *)(v5 + 8);
  v2[314 * a2 + 478] = *(_DWORD *)(v5 + 12);
  v2[314 * a2 + 343] = *(_DWORD *)(v5 + 8);
  v2[314 * a2 + 344] = *(_DWORD *)(v5 + 12);
  *(double *)&v2[314 * a2 + 345] = *(double *)(v5 + 8) - *(double *)(v5 + 24);
  v8 = *(double *)v5 + *(double *)(v5 + 8);
  v9 = *(double *)(v5 + 16) + *(double *)(v5 + 24);
  *(double *)&v2[314 * a2 + 475] = *(double *)&v2[314 * a2 + 475] * *(double *)(v2 + 2169);
  *(double *)&v2[314 * a2 + 339] = *(double *)&v2[314 * a2 + 339] * *(double *)(v2 + 2169);
  *(double *)&v2[314 * a2 + 341] = *(double *)&v2[314 * a2 + 341] * *(double *)(v2 + 2169);
  *(double *)&v2[314 * a2 + 477] = *(double *)&v2[314 * a2 + 477] * *(double *)(v2 + 2169);
  *(double *)&v2[314 * a2 + 343] = *(double *)&v2[314 * a2 + 343] * *(double *)(v2 + 2169);
  *(double *)&v2[314 * a2 + 345] = *(double *)(v2 + 2169) * *(double *)&v2[314 * a2 + 345];
  v42 = v8 * *(double *)(v2 + 2169);
  v10 = v9 * *(double *)(v2 + 2169);
  v41 = v10;
  sub_4FED10(
    &v2[314 * a2 + 347],
    *(_DWORD *)(v5 + 160),
    *(_DWORD *)(v5 + 164),
    *(_DWORD *)(v5 + 168),
    *(_DWORD *)(v5 + 172),
    *(_DWORD *)(v5 + 176),
    *(_DWORD *)(v5 + 180));
  sub_4FED10(
    &v2[314 * a2 + 355],
    *(_DWORD *)(v5 + 184),
    *(_DWORD *)(v5 + 188),
    *(_DWORD *)(v5 + 192),
    *(_DWORD *)(v5 + 196),
    *(_DWORD *)(v5 + 200),
    *(_DWORD *)(v5 + 204));
  v2[314 * a2 + 363] = sub_500AB0((char *)(v5 + 416));
  v2[314 * a2 + 364] = sub_500AB0((char *)(v5 + 448));
  v11 = sub_500AB0((char *)(v5 + 480));
  v12 = v2[314 * a2 + 363];
  v2[314 * a2 + 365] = v11;
  if ( (!v12 || !v2[314 * a2 + 364] || !v11) && dword_75CBA8 != 5 )
  {
    if ( (unsigned __int8)sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004, 3870) )
      sub_500FE0((int)&unk_7D7920, aCouldNotFindOn, v5 - 96);
    v2 = this;
  }
  sub_4FF6C0(1.0, 0.0001);
  sub_4FF6C0(1.0, 0.0001);
  sub_4FF6C0(1.0, 0.0001);
  *(double *)(v4 + 796) = 1.0 / ((v10 + v10 + v10 + v10) * 2500.0);
  if ( *(double *)(v5 + 208) >= 1.570796326794897 && dword_75CBA8 != 5 )
  {
    if ( (unsigned __int8)sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004, 3887) )
      sub_500FE0((int)&unk_7D7920, aTireOptimumCam, v38);
    v2 = this;
  }
  v13 = *(double *)(v5 + 208);
  *(double *)(v4 + 812) = v13;
  if ( v15 | v16 )
  {
    *(_DWORD *)(v4 + 828) = 0;
    *(_DWORD *)(v4 + 832) = 0;
  }
  else
  {
    *(double *)(v4 + 828) = 1.570796326794897 / v13;
  }
  *(_DWORD *)(v4 + 804) = *(_DWORD *)(v5 + 216);
  *(_DWORD *)(v4 + 808) = *(_DWORD *)(v5 + 220);
  v17 = (_DWORD *)(v4 + 952);
  v18 = 3;
  *(double *)(v4 + 820) = *(double *)(v5 + 224) * 0.6366197723675814;
  *(double *)(v4 + 836) = 3.141592653589793 / (1.570796326794897 - *(double *)(v4 + 812));
  *(double *)(v4 + 876) = *(double *)(v5 + 368) + 273.16;
  do
  {
    *v17 = *(_DWORD *)(v4 + 876);
    v17[1] = *(_DWORD *)(v4 + 880);
    v17 += 2;
    --v18;
  }
  while ( v18 );
  v19 = *(double *)(v4 + 876);
  v20 = *(_DWORD *)(v4 + 1000);
  *(double *)(v4 + 976) = v19;
  v21 = *(_DWORD *)(v4 + 1004);
  v22 = *(double *)(v4 + 1000);
  *(_DWORD *)(v4 + 296) = 1076887552;
  *(_DWORD *)(v4 + 992) = v20;
  *(_DWORD *)(v4 + 996) = v21;
  *(_DWORD *)(v4 + 292) = 0;
  *(double *)(v4 + 984) = v22 / v19;
  *(_DWORD *)(v4 + 1008) = *(_DWORD *)(v5 + 56);
  *(_DWORD *)(v4 + 1012) = *(_DWORD *)(v5 + 60);
  *(_DWORD *)(v4 + 1016) = *(_DWORD *)(v5 + 64);
  *(_DWORD *)(v4 + 1020) = *(_DWORD *)(v5 + 68);
  if ( *(_DWORD *)dword_766AA4 )
  {
    v23 = *(double *)(v4 + 1008);
    *(_DWORD *)(v4 + 292) = 0;
    *(_DWORD *)(v4 + 296) = 1077149696;
    *(double *)(v4 + 1008) = v23 * 0.9200000166893005;
    *(double *)(v4 + 1016) = *(double *)(v4 + 1016) * 0.9200000166893005;
    *(double *)(v4 + 564) = *(double *)(v4 + 564) * 0.9200000166893005;
  }
  if ( sub_4E8E50(String, 32, aTireheatmult, 0) )
    v24 = 1.0;
  else
    v24 = atof(String);
  *(double *)(v4 + 300) = 1.0 / *(double *)(v4 + 292);
  v25 = *(double *)(v5 + 360) + 273.16;
  *(double *)(v4 + 884) = v25;
  if ( *(double *)(v5 + 360) <= 0.0 )
    v26 = 0.0;
  else
    v26 = 1.0 / v25;
  *(double *)(v4 + 892) = v26;
  *(double *)(v4 + 900) = -(v26 * *(double *)(v5 + 392));
  v27 = v26 * *(double *)(v5 + 400);
  *(double *)(v4 + 908) = v27;
  if ( v29 | v30 )
  {
    *(_DWORD *)(v4 + 916) = -1;
    *(_DWORD *)(v4 + 920) = 2146435071;
  }
  else
  {
    *(double *)(v4 + 916) = 1.0 / v27 + *(double *)(v4 + 884);
  }
  *(_DWORD *)(v4 + 924) = *(_DWORD *)(v5 + 376);
  *(_DWORD *)(v4 + 928) = *(_DWORD *)(v5 + 380);
  *(_DWORD *)(v4 + 932) = *(_DWORD *)(v5 + 384);
  *(_DWORD *)(v4 + 936) = *(_DWORD *)(v5 + 388);
  *(_DWORD *)(v4 + 940) = *(_DWORD *)(v5 + 408);
  *(_DWORD *)(v4 + 944) = *(_DWORD *)(v5 + 412);
  *(_BYTE *)(v4 + 948) = 0;
  *(_DWORD *)(v4 + 1248) = *(_DWORD *)(v5 + 232);
  *(_DWORD *)(v4 + 1252) = *(_DWORD *)(v5 + 236);
  *(_DWORD *)(v4 + 868) = *(_DWORD *)(v5 + 232);
  *(_DWORD *)(v4 + 872) = *(_DWORD *)(v5 + 236);
  *(double *)(v4 + 1056) = v24 * *(double *)(v5 + 240);
  *(double *)(v4 + 1064) = *(double *)(v5 + 248) * *(double *)(v4 + 796) * v24;
  *(_DWORD *)(v4 + 1072) = *(_DWORD *)(v5 + 256);
  *(_DWORD *)(v4 + 1076) = *(_DWORD *)(v5 + 260);
  *(_DWORD *)(v4 + 1080) = *(_DWORD *)(v5 + 264);
  *(_DWORD *)(v4 + 1084) = *(_DWORD *)(v5 + 268);
  *(_DWORD *)(v4 + 1088) = *(_DWORD *)(v5 + 272);
  *(_DWORD *)(v4 + 1092) = *(_DWORD *)(v5 + 276);
  if ( *(double *)(v5 + 280) <= 0.0 )
    v31 = 0.0;
  else
    v31 = 1.0 / *(double *)(v5 + 280);
  *(double *)(v4 + 1040) = v31;
  if ( *(double *)(v5 + 288) <= 0.0 )
    v32 = 0.0;
  else
    v32 = 1.0 / *(double *)(v5 + 288);
  *(double *)(v4 + 1048) = v32;
  *(_DWORD *)(v4 + 1096) = *(_DWORD *)(v5 + 296);
  *(_DWORD *)(v4 + 1100) = *(_DWORD *)(v5 + 300);
  v33 = flt_7D7414 * *(double *)(v5 + 304) * (double)*(int *)dword_7693B0;
  *(_DWORD *)(v4 + 1024) = 0;
  *(_DWORD *)(v4 + 1028) = 1072693248;
  *(double *)(v4 + 1104) = v33 * *(double *)(v4 + 796);
  sub_43AB60((double *)v4);
  v34 = 0.0;
  if ( dword_7D73D8 > 0 )
  {
    v35 = (float *)(dword_7D73DC + 12);
    v36 = dword_7D73D8;
    do
    {
      v40 = *(v35 - 1) - *v35;
      if ( v34 < v40 )
        v34 = v40;
      v35 += 26;
      --v36;
    }
    while ( v36 );
  }
  *(double *)(v2 + 47) = v41 / v42 * v34;
}
