void __thiscall sub_43DA10(_DWORD *this, unsigned int a2)
{
  _DWORD *v2; // ebx
  int v3; // eax
  int v4; // edi
  int v5; // esi
  double v6; // rax
  double v7; // st7
  double v8; // st7
  char *v9; // eax
  char *v10; // eax
  char *v11; // eax
  int v12; // eax
  int v13; // ecx
  double v14; // st7
  unsigned __int8 v16; // c0
  unsigned __int8 v17; // c3
  double v18; // st7
  int v19; // eax
  int v20; // ecx
  double v21; // st7
  double v22; // st7
  double v23; // st7
  int v24; // edx
  float *v25; // ecx
  int v26; // edx
  double v28; // [esp+10h] [ebp-28h]
  double v29; // [esp+28h] [ebp-10h]
  double v30; // [esp+30h] [ebp-8h]

  v2 = this;
  v3 = sub_4D7570(this[1303]);
  v4 = v3 + 352;
  if ( a2 <= 1 )
    v4 = v3 + 24;
  v5 = (int)&v2[281 * a2 + 163];
  *(_DWORD *)(v5 + 524) = *(_DWORD *)(v4 + 32);
  *(_DWORD *)(v5 + 528) = *(_DWORD *)(v4 + 36);
  HIDWORD(v6) = v2[281 * a2 + 387];
  *(_DWORD *)(v5 + 532) = *(_DWORD *)(v4 + 40);
  LODWORD(v6) = v2[281 * a2 + 386];
  *(_DWORD *)(v5 + 536) = *(_DWORD *)(v4 + 44);
  *(double *)(v5 + 540) = *(double *)(v4 + 48) * 0.45;
  v7 = *(double *)(v4 + 48) * 0.15;
  *(double *)(v5 + 548) = v7;
  sub_4D6AE0(v6);
  *(double *)(v5 + 556) = v7;
  *(_DWORD *)(v5 + 564) = *(_DWORD *)(v4 + 72);
  *(_DWORD *)(v5 + 568) = *(_DWORD *)(v4 + 76);
  sub_4D5C70(*(double *)(v4 + 80), *(double *)(v4 + 88), *(double *)(v4 + 96));
  *(_DWORD *)(v5 + 1100) = *(_DWORD *)v4;
  *(_DWORD *)(v5 + 1104) = *(_DWORD *)(v4 + 4);
  *(_DWORD *)(v5 + 632) = *(_DWORD *)v4;
  *(_DWORD *)(v5 + 636) = *(_DWORD *)(v4 + 4);
  *(double *)(v5 + 640) = *(double *)v4 - *(double *)(v4 + 16);
  *(_DWORD *)(v5 + 1108) = *(_DWORD *)(v4 + 8);
  *(_DWORD *)(v5 + 1112) = *(_DWORD *)(v4 + 12);
  *(_DWORD *)(v5 + 648) = *(_DWORD *)(v4 + 8);
  *(_DWORD *)(v5 + 652) = *(_DWORD *)(v4 + 12);
  *(double *)(v5 + 656) = *(double *)(v4 + 8) - *(double *)(v4 + 24);
  v30 = *(double *)(v4 + 8) + *(double *)v4;
  v8 = *(double *)(v4 + 16) + *(double *)(v4 + 24);
  v29 = v8;
  sub_4D5EE0(*(double *)(v4 + 104), *(double *)(v4 + 112), *(double *)(v4 + 120));
  sub_4D5EE0(*(double *)(v4 + 128), *(double *)(v4 + 136), *(double *)(v4 + 144));
  v9 = *(char **)(v4 + 304);
  if ( !v9 )
    v9 = &byte_5EA438;
  v2[281 * a2 + 345] = sub_4D75D0(v9);
  v10 = *(char **)(v4 + 312);
  if ( !v10 )
    v10 = &byte_5EA438;
  v2[281 * a2 + 346] = sub_4D75D0(v10);
  v11 = *(char **)(v4 + 320);
  if ( !v11 )
    v11 = &byte_5EA438;
  v12 = sub_4D75D0(v11);
  v13 = v2[281 * a2 + 345];
  v2[281 * a2 + 347] = v12;
  if ( (!v13 || !v2[281 * a2 + 346] || !v12) && dword_7C569C != 5 )
  {
    if ( (unsigned __int8)sub_4D7A50(1, aDDevF119992002, 3730) )
      sub_4D7AA0(&unk_8AD25C, aCouldNotFindOn);
    v2 = this;
  }
  sub_4D6830(1.0, 0.0001);
  sub_4D6830(1.0, 0.0001);
  sub_4D6830(1.0, 0.0001);
  *(double *)(v5 + 740) = 1.0 / ((v8 + v8 + v8 + v8) * 2500.0);
  if ( *(double *)(v4 + 152) >= 1.570796326794897 && dword_7C569C != 5 )
  {
    if ( (unsigned __int8)sub_4D7A50(1, aDDevF119992002, 3747) )
      sub_4D7AA0(&unk_8AD25C, aTireOptimumCam);
    v2 = this;
  }
  v14 = *(double *)(v4 + 152);
  *(double *)(v5 + 756) = v14;
  if ( v16 | v17 )
  {
    *(_DWORD *)(v5 + 772) = 0;
    *(_DWORD *)(v5 + 776) = 0;
  }
  else
  {
    *(double *)(v5 + 772) = 1.570796326794897 / v14;
  }
  *(_DWORD *)(v5 + 748) = *(_DWORD *)(v4 + 160);
  *(_DWORD *)(v5 + 752) = *(_DWORD *)(v4 + 164);
  *(double *)(v5 + 764) = *(double *)(v4 + 168) * 0.6366197723675814;
  *(double *)(v5 + 780) = 3.141592653589793 / (1.570796326794897 - *(double *)(v5 + 756));
  *(_DWORD *)(v5 + 844) = -1889785610;
  *(_DWORD *)(v5 + 848) = 1081507266;
  *(_DWORD *)(v5 + 852) = *(_DWORD *)(v5 + 844);
  *(_DWORD *)(v5 + 856) = *(_DWORD *)(v5 + 848);
  *(_DWORD *)(v5 + 860) = *(_DWORD *)(v5 + 852);
  *(_DWORD *)(v5 + 864) = *(_DWORD *)(v5 + 856);
  v18 = *(double *)(v5 + 892) * 0.002778858444950814;
  v19 = *(_DWORD *)(v5 + 892);
  v20 = *(_DWORD *)(v5 + 896);
  *(_DWORD *)(v5 + 868) = -1889785610;
  *(double *)(v5 + 876) = v18;
  *(_DWORD *)(v5 + 872) = 1081507266;
  *(_DWORD *)(v5 + 296) = 1076625408;
  *(_DWORD *)(v5 + 884) = v19;
  *(_DWORD *)(v5 + 888) = v20;
  *(_DWORD *)(v5 + 292) = 0;
  *(_DWORD *)(v5 + 900) = *(_DWORD *)(v4 + 56);
  *(_DWORD *)(v5 + 904) = *(_DWORD *)(v4 + 60);
  *(_DWORD *)(v5 + 908) = *(_DWORD *)(v4 + 64);
  *(_DWORD *)(v5 + 912) = *(_DWORD *)(v4 + 68);
  if ( dword_7CE958 )
  {
    v21 = *(double *)(v5 + 900);
    *(_DWORD *)(v5 + 292) = 0;
    *(_DWORD *)(v5 + 296) = 1076985856;
    *(double *)(v5 + 900) = v21 * 0.9200000166893005;
    *(double *)(v5 + 908) = *(double *)(v5 + 908) * 0.9200000166893005;
    *(double *)(v5 + 564) = *(double *)(v5 + 564) * 0.9200000166893005;
  }
  *(double *)(v5 + 300) = 1.0 / *(double *)(v5 + 292);
  *(double *)(v5 + 820) = *(double *)(v4 + 280) + 273.16;
  *(_DWORD *)(v5 + 828) = *(_DWORD *)(v4 + 288);
  *(_DWORD *)(v5 + 832) = *(_DWORD *)(v4 + 292);
  *(_DWORD *)(v5 + 836) = *(_DWORD *)(v4 + 296);
  *(_DWORD *)(v5 + 840) = *(_DWORD *)(v4 + 300);
  *(_DWORD *)(v5 + 1116) = *(_DWORD *)(v4 + 176);
  *(_DWORD *)(v5 + 1120) = *(_DWORD *)(v4 + 180);
  *(_DWORD *)(v5 + 812) = *(_DWORD *)(v4 + 176);
  *(_DWORD *)(v5 + 816) = *(_DWORD *)(v4 + 180);
  *(_DWORD *)(v5 + 932) = *(_DWORD *)(v4 + 184);
  *(_DWORD *)(v5 + 936) = *(_DWORD *)(v4 + 188);
  *(double *)(v5 + 940) = *(double *)(v4 + 192) * *(double *)(v5 + 740);
  *(_DWORD *)(v5 + 948) = *(_DWORD *)(v4 + 200);
  *(_DWORD *)(v5 + 952) = *(_DWORD *)(v4 + 204);
  *(_DWORD *)(v5 + 956) = *(_DWORD *)(v4 + 208);
  *(_DWORD *)(v5 + 960) = *(_DWORD *)(v4 + 212);
  *(_DWORD *)(v5 + 964) = *(_DWORD *)(v4 + 216);
  *(_DWORD *)(v5 + 968) = *(_DWORD *)(v4 + 220);
  v22 = (double)dword_7D0C60 * *(double *)(v4 + 224);
  *(_DWORD *)(v5 + 916) = 0;
  *(_DWORD *)(v5 + 920) = 1072693248;
  *(double *)(v5 + 972) = v22 * *(double *)(v5 + 740);
  sub_438100(v5);
  v23 = 0.0;
  if ( dword_8ACEA8 > v24 )
  {
    v25 = (float *)(dword_8ACEAC + 12);
    v26 = dword_8ACEA8;
    do
    {
      v28 = *(v25 - 1) - *v25;
      if ( v23 < v28 )
        v23 = v28;
      v25 += 27;
      --v26;
    }
    while ( v26 );
  }
  *(double *)(v2 + 43) = v29 / v30 * v23;
}
