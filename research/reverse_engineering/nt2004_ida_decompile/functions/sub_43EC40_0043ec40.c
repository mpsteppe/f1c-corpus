int __thiscall sub_43EC40(int this, __int64 a2)
{
  int v3; // ecx
  int v4; // edx
  int v5; // edi
  int v6; // esi
  double v7; // st7
  double v8; // st7
  int v9; // edx
  double v10; // st7
  double v11; // st7
  int v12; // eax
  double v13; // st6
  double v14; // st7
  int v15; // esi
  double v16; // st7
  double v17; // st7
  int v18; // ecx
  int v19; // eax
  double v20; // st7
  double v21; // st7
  bool v22; // al
  char v23; // dl
  bool v24; // al
  double *v25; // ecx
  double *v26; // esi
  double v27; // st7
  double v28; // st7
  double v29; // st6
  double *v30; // esi
  double *v31; // ecx
  double v32; // st6
  double v33; // st5
  int v34; // edx
  int v35; // eax
  double *v36; // esi
  double v37; // st7
  int v38; // esi
  double v39; // st7
  double v40; // st7
  long double v41; // st7
  double v42; // st7
  int v43; // eax
  double v44; // st7
  double v45; // st7
  double v46; // st7
  double v47; // st7
  double v48; // st7
  double v49; // st7
  double v50; // st7
  double v51; // st7
  double v52; // st7
  double v53; // st6
  int v54; // eax
  double v55; // st7
  double v56; // st7
  __int64 v57; // rax
  int v58; // esi
  double v59; // st7
  double v60; // st7
  double v61; // st7
  double v62; // st7
  int v63; // eax
  int v64; // ecx
  _DWORD *v65; // eax
  int v66; // ecx
  double v67; // st7
  double v68; // st7
  double v69; // st7
  int v70; // eax
  int v71; // esi
  unsigned int v72; // eax
  unsigned int v73; // ecx
  char v74; // dl
  int result; // eax
  int v76; // esi
  double *v77; // ecx
  double v78; // st6
  double v79; // st7
  double v80; // [esp+50h] [ebp-C8h]
  double v81; // [esp+50h] [ebp-C8h]
  double v82; // [esp+50h] [ebp-C8h]
  int v83; // [esp+58h] [ebp-C0h]
  int i; // [esp+58h] [ebp-C0h]
  double v85; // [esp+58h] [ebp-C0h]
  int v86; // [esp+58h] [ebp-C0h]
  int j; // [esp+58h] [ebp-C0h]
  double v88; // [esp+60h] [ebp-B8h]
  double v89; // [esp+60h] [ebp-B8h]
  double v90; // [esp+60h] [ebp-B8h]
  int v91; // [esp+68h] [ebp-B0h]
  double v92; // [esp+68h] [ebp-B0h]
  int v93; // [esp+68h] [ebp-B0h]
  double *v94; // [esp+68h] [ebp-B0h]
  double v95[3]; // [esp+70h] [ebp-A8h] BYREF
  double v96; // [esp+88h] [ebp-90h]
  double v97; // [esp+90h] [ebp-88h]
  double v98; // [esp+98h] [ebp-80h]
  double v99[3]; // [esp+A0h] [ebp-78h] BYREF
  double v100[3]; // [esp+B8h] [ebp-60h] BYREF
  double v101[3]; // [esp+D0h] [ebp-48h] BYREF
  _DWORD v102[6]; // [esp+E8h] [ebp-30h] BYREF
  double v103; // [esp+100h] [ebp-18h]
  int v104[2]; // [esp+108h] [ebp-10h] BYREF
  int v105[2]; // [esp+110h] [ebp-8h] BYREF

  v3 = HIDWORD(a2);
  v4 = a2 + 312;
  v5 = HIDWORD(a2) + 5328;
  v6 = this + 848;
  LODWORD(v96) = a2 + 312;
  LODWORD(v98) = HIDWORD(a2) + 5328;
  v83 = this + 848;
  v91 = 4;
  while ( 1 )
  {
    *(_DWORD *)(v6 - 8) = 0;
    *(_DWORD *)(v6 - 4) = 0;
    *(_DWORD *)v6 = 0;
    *(_DWORD *)(v6 + 4) = 0;
    *(_DWORD *)(v6 + 8) = 0;
    *(_DWORD *)(v6 + 12) = 0;
    *(_DWORD *)(v6 + 16) = 0;
    *(_DWORD *)(v6 + 20) = 0;
    *(_DWORD *)(v6 + 40) = 0;
    *(_DWORD *)(v6 + 44) = 0;
    *(_DWORD *)(v6 + 144) = 0;
    *(_DWORD *)(v6 + 152) = 0;
    *(_DWORD *)(v6 + 148) = 1072693248;
    *(_DWORD *)(v6 + 156) = 1072693248;
    *(_DWORD *)(v6 + 72) = -1;
    *(_DWORD *)(v6 + 76) = -1048577;
    *(_DWORD *)(v6 + 104) = -1;
    *(_DWORD *)(v6 + 108) = -1048577;
    *(_DWORD *)(v6 + 24) = *(_DWORD *)(v5 - 8);
    *(_DWORD *)(v6 + 28) = *(_DWORD *)(v5 - 4);
    v88 = *(_BYTE *)(v3 + 1437) ? 1.0 / *(double *)v5 : 1.0;
    v97 = v88 * *(double *)(v3 + 1412);
    v7 = v88 * *(double *)(v3 + 1420);
    *(_BYTE *)(v6 + 272) = 0;
    *(_BYTE *)(v6 + 332) = 0;
    sub_438D30(
      (double *)(v6 - 180),
      v88,
      v97,
      v7,
      (double *)(v5 - 160),
      ((double)*(int *)(v4 + 140) * *(double *)(v4 + 128) + *(double *)(v4 + 120)) * *(double *)(v5 - 96),
      (double)*(int *)(v4 + 76) * *(double *)(v4 + 64) + *(double *)(v4 + 56),
      (double)*(int *)(v4 + 268) * *(double *)(v4 + 256) + *(double *)(v4 + 248),
      (double)*(int *)(v4 + 204) * *(double *)(v4 + 192) + *(double *)(v4 + 184),
      (double)*(int *)(v4 + 396) * *(double *)(v4 + 384) + *(double *)(v4 + 376),
      (double)*(int *)(v4 + 332) * *(double *)(v4 + 320) + *(double *)(v4 + 312),
      (double)*(int *)(v4 + 12) * *(double *)v4 + *(double *)(v4 - 8),
      *(double *)(v5 + 8));
    *(_DWORD *)(v6 + 940) = *(_DWORD *)(v5 + 16);
    *(_DWORD *)(v6 + 944) = *(_DWORD *)(v5 + 20);
    *(_DWORD *)(v6 + 948) = *(_DWORD *)(v5 + 24);
    *(_DWORD *)(v6 + 952) = *(_DWORD *)(v5 + 28);
    *(_DWORD *)(v6 + 956) = *(_DWORD *)(v5 + 24);
    *(_DWORD *)(v6 + 960) = *(_DWORD *)(v5 + 28);
    v8 = *(double *)(v5 + 40);
    *(double *)(v6 + 964) = v8;
    *(double *)(v6 + 972) = 3.141592653589793 / v8;
    v10 = (double)(*(_DWORD *)(v9 + 456) - 1) * *(double *)(v9 + 448) + *(double *)(v9 + 440);
    *(double *)(v6 + 980) = flt_7DAB0C + 273.16;
    *(_DWORD *)(v6 + 988) = *(_DWORD *)(v5 + 32);
    *(_DWORD *)(v6 + 992) = *(_DWORD *)(v5 + 36);
    *(double *)(v6 + 996) = v10 * *(double *)(v5 + 48);
    *(double *)(v6 + 1004) = v10 * *(double *)(v5 + 56);
    *(double *)(v6 + 1012) = (((double)*(int *)(a2 + 4932) * *(double *)(a2 + 4920) + *(double *)(a2 + 4912))
                            * *(double *)(v5 + 72)
                            + *(double *)(v5 + 64))
                           * v10;
    *(double *)(v6 + 1020) = (double)*(int *)(v9 + 460) * *(double *)(v9 + 448) + *(double *)(v9 + 440);
    *(double *)(v6 + 1036) = *(double *)(v5 + 88)
                           / (*(double *)(v6 + 988)
                            * *(double *)(v6 + 988)
                            * *(double *)(v6 + 988));
    *(double *)(v6 + 1044) = sub_4D1B00(&dword_7D3C50) * *(double *)(v5 + 104) + *(double *)(v5 + 96);
    v80 = *(double *)(v6 + 1020) * 0.99;
    v11 = *(double *)(v6 + 1020) * 0.01;
    if ( v11 <= *(double *)(v6 + 1044) )
    {
      if ( *(double *)(v6 + 1044) > v80 )
        *(double *)(v6 + 1044) = v80;
    }
    else
    {
      *(double *)(v6 + 1044) = v11;
    }
    v12 = *(_DWORD *)(v83 + 168);
    v13 = *(double *)(LODWORD(v98) + 80);
    *(double *)(v83 + 1028) = v13;
    v14 = v13 * *(double *)(v83 + 1020);
    qmemcpy(v95, (const void *)(v12 + 188), sizeof(v95));
    v95[0] = v14 + *(double *)(v83 + 24);
    sub_57C530(v95);
    v15 = LODWORD(v98);
    v16 = *(double *)(v83 + 1020) * *(double *)(v83 + 1028);
    *(_DWORD *)(v83 + 488) = 0;
    *(_DWORD *)(v83 + 492) = 0;
    v17 = v16 + *(double *)(v83 + 24);
    *(_DWORD *)(v83 + 500) = 0;
    *(_DWORD *)(v83 + 504) = 0;
    v18 = LODWORD(v96);
    *(_DWORD *)(v83 + 496) = 1072693248;
    v83 += 1256;
    v18 += 704;
    LODWORD(v98) = v15 + 272;
    LODWORD(v96) = v18;
    *(double *)(v83 - 1224) = 1.0 / v17;
    *(double *)(v83 - 436) = (double)*(int *)(v18 - 756) * *(double *)(v18 - 768) + *(double *)(v18 - 776);
    if ( !--v91 )
      break;
    v3 = HIDWORD(a2);
    v5 = LODWORD(v98);
    v6 = v83;
    v4 = LODWORD(v96);
  }
  v19 = sub_500DC0((char *)(HIDWORD(a2) + 132));
  *(_DWORD *)(this + 5752) = v19;
  if ( !v19 && dword_75CBA8 != 5 && (unsigned __int8)sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004, 3417) )
    sub_500FE0((int)&unk_7D7920, aHdvFileReferen, BYTE4(a2) - 124);
  *(_DWORD *)(this + 5756) = *(_DWORD *)(a2 + 3012);
  for ( i = 0; i < 4; ++i )
    sub_440480(this, i);
  if ( *(_BYTE *)(HIDWORD(a2) + 1437) )
    v89 = 0.5 / *(double *)(HIDWORD(a2) + 5600) + 0.5 / *(double *)(HIDWORD(a2) + 5328);
  else
    v89 = 1.0;
  v92 = v89 * *(double *)(HIDWORD(a2) + 1412);
  v85 = v89 * *(double *)(HIDWORD(a2) + 1420);
  v20 = (double)*(int *)(a2 + 3332) * *(double *)(a2 + 3320) + *(double *)(a2 + 3312);
  sub_524180(v20);
  *(double *)(this + 5720) = v20 * v92 * 0.5;
  if ( *(_BYTE *)(HIDWORD(a2) + 1437) )
    v81 = 0.5 / *(double *)(HIDWORD(a2) + 6144) + 0.5 / *(double *)(HIDWORD(a2) + 5872);
  else
    v81 = 1.0;
  v96 = v81 * *(double *)(HIDWORD(a2) + 1412);
  v103 = v81 * *(double *)(HIDWORD(a2) + 1420);
  v21 = (double)*(int *)(a2 + 3396) * *(double *)(a2 + 3384) + *(double *)(a2 + 3376);
  sub_5241E0(v21);
  *(double *)(this + 5728) = v21 * v96 * 0.5;
  v98 = ((double)*(int *)(a2 + 324) * *(double *)(a2 + 312)
       + *(double *)(a2 + 304)
       + (double)*(int *)(a2 + 1028) * *(double *)(a2 + 1016)
       + *(double *)(a2 + 1008))
      * 0.5;
  v97 = (*(double *)(HIDWORD(a2) + 5608) + *(double *)(HIDWORD(a2) + 5336)) * 0.5;
  sub_438D30(
    (double *)(this + 5764),
    v89,
    v92,
    v85,
    (double *)(HIDWORD(a2) + 1524),
    (double)*(int *)(a2 + 4036) * *(double *)(a2 + 4024) + *(double *)(a2 + 4016),
    (double)*(int *)(a2 + 3972) * *(double *)(a2 + 3960) + *(double *)(a2 + 3952),
    (double)*(int *)(a2 + 4164) * *(double *)(a2 + 4152) + *(double *)(a2 + 4144),
    (double)*(int *)(a2 + 4100) * *(double *)(a2 + 4088) + *(double *)(a2 + 4080),
    (double)*(int *)(a2 + 4292) * *(double *)(a2 + 4280) + *(double *)(a2 + 4272),
    (double)*(int *)(a2 + 4228) * *(double *)(a2 + 4216) + *(double *)(a2 + 4208),
    v98,
    v97);
  v90 = ((double)*(int *)(a2 + 2436) * *(double *)(a2 + 2424)
       + *(double *)(a2 + 2416)
       + (double)*(int *)(a2 + 1732) * *(double *)(a2 + 1720)
       + *(double *)(a2 + 1712))
      * 0.5;
  v97 = (*(double *)(HIDWORD(a2) + 6152) + *(double *)(HIDWORD(a2) + 5880)) * 0.5;
  v22 = sub_438D30(
          (double *)(this + 5884),
          v81,
          v96,
          v103,
          (double *)(HIDWORD(a2) + 1588),
          (double)*(int *)(a2 + 4420) * *(double *)(a2 + 4408) + *(double *)(a2 + 4400),
          (double)*(int *)(a2 + 4356) * *(double *)(a2 + 4344) + *(double *)(a2 + 4336),
          (double)*(int *)(a2 + 4548) * *(double *)(a2 + 4536) + *(double *)(a2 + 4528),
          (double)*(int *)(a2 + 4484) * *(double *)(a2 + 4472) + *(double *)(a2 + 4464),
          (double)*(int *)(a2 + 4676) * *(double *)(a2 + 4664) + *(double *)(a2 + 4656),
          (double)*(int *)(a2 + 4612) * *(double *)(a2 + 4600) + *(double *)(a2 + 4592),
          v90,
          v97);
  v24 = v23 || v22;
  *(_BYTE *)(this + 5760) = v24;
  *(_BYTE *)(this + 144) = byte_76617C == 0;
  *(double *)(this + 6004) = (double)*(int *)(a2 + 5124) * *(double *)(a2 + 5112) + *(double *)(a2 + 5104);
  *(double *)(this + 6012) = (double)*(int *)(a2 + 5060) * *(double *)(a2 + 5048) + *(double *)(a2 + 5040);
  qmemcpy((void *)(this + 6028), (const void *)(a2 + 4976), 0x40u);
  *(_BYTE *)(this + 6092) = *(_BYTE *)(HIDWORD(a2) + 1736);
  v25 = (double *)(*(_DWORD *)(this + 2272) + 4);
  v26 = (double *)(*(_DWORD *)(this + 1016) + 4);
  v27 = (double)*(int *)(this + 6048) * *(double *)(this + 6036) + *(double *)(this + 6028);
  *(_DWORD *)(this + 224) = 1;
  *(_DWORD *)(this + 6268) = 0;
  *(_DWORD *)(this + 6272) = 0;
  *(double *)(this + 6020) = v27;
  v28 = *v25 + *v26;
  v29 = v26[1] + v25[1];
  v95[2] = v26[2] + v25[2];
  v100[0] = v28 * 0.5;
  v100[1] = v29 * 0.5;
  v100[2] = v95[2] * 0.5;
  qmemcpy(v101, v100, sizeof(v101));
  v30 = *(double **)(this + 3528);
  v31 = (double *)(*(_DWORD *)(this + 4784) + 4);
  v101[1] = -*(double *)(HIDWORD(a2) + 92);
  v30 = (double *)((char *)v30 + 4);
  v32 = *v31 + *v30;
  v33 = v30[1] + v31[1];
  v95[2] = v30[2] + v31[2];
  v93 = a2 + 312;
  v86 = 0;
  v34 = this + 6420;
  v100[0] = v32 * 0.5;
  v35 = HIDWORD(a2) + 5312;
  v100[1] = v33 * 0.5;
  v100[2] = v95[2] * 0.5;
  qmemcpy(v99, v100, sizeof(v99));
  v99[1] = v101[1];
  LODWORD(v96) = this + 6284;
  do
  {
    if ( !v86 || (v36 = v99, v86 == 1) )
      v36 = v101;
    qmemcpy(v100, v36, sizeof(v100));
    v95[0] = v100[0] + *(double *)(v35 - 16);
    v37 = v100[1] + *(double *)(v35 - 8);
    v35 += 272;
    v34 += 8;
    v95[1] = v37;
    v95[2] = v100[2] + *(double *)(v35 - 272);
    qmemcpy((void *)(LODWORD(v96) - 8), v95, 0x18u);
    v38 = LODWORD(v96);
    *(_DWORD *)(v34 - 56) = *(_DWORD *)LODWORD(v96);
    *(_DWORD *)(v34 - 52) = *(_DWORD *)(v38 + 4);
    ++v86;
    v39 = (double)*(int *)(v93 + 12) * *(double *)v93;
    LODWORD(v96) = v38 + 24;
    v93 += 704;
    v40 = v39 + *(double *)(v93 - 712);
    *(double *)(v34 - 8) = v40;
    *(double *)(v34 + 48) = v40;
  }
  while ( v86 < 4 );
  v41 = *(double *)(this + 6292) - *(double *)(this + 6340);
  *(_BYTE *)(this + 6460) = 0;
  *(_DWORD *)(this + 6464) = 0;
  *(_DWORD *)(this + 6468) = 0;
  *(long double *)(this + 6452) = fabs(v41);
  *(_QWORD *)(this + 336) = *(_QWORD *)(HIDWORD(a2) + 1652);
  *(_QWORD *)(this + 344) = *(_QWORD *)(HIDWORD(a2) + 1660);
  *(_QWORD *)(this + 352) = *(_QWORD *)(HIDWORD(a2) + 1668);
  *(_QWORD *)(this + 360) = *(_QWORD *)(HIDWORD(a2) + 1676);
  *(_QWORD *)(this + 368) = *(_QWORD *)(HIDWORD(a2) + 1684);
  if ( *(double *)(this + 368) >= 0.0 )
  {
    if ( *(double *)(this + 368) > 1.0 )
    {
      *(_DWORD *)(this + 368) = 0;
      *(_DWORD *)(this + 372) = 1072693248;
    }
  }
  else
  {
    *(_DWORD *)(this + 368) = 0;
    *(_DWORD *)(this + 372) = 0;
  }
  *(_QWORD *)(this + 376) = *(_QWORD *)(HIDWORD(a2) + 1692);
  if ( *(double *)(this + 376) >= 0.0 )
  {
    if ( *(double *)(this + 376) <= 1.0 )
      goto LABEL_41;
    *(_DWORD *)(this + 380) = 1072693248;
  }
  else
  {
    *(_DWORD *)(this + 380) = 0;
  }
  *(_DWORD *)(this + 376) = 0;
LABEL_41:
  *(_DWORD *)(this + 384) = 0;
  *(_DWORD *)(this + 388) = 0;
  *(_BYTE *)(this + 392) = *(_BYTE *)(HIDWORD(a2) + 1700);
  *(_QWORD *)(this + 396) = *(_QWORD *)(HIDWORD(a2) + 1704);
  *(_QWORD *)(this + 404) = *(_QWORD *)(HIDWORD(a2) + 1712);
  *(_QWORD *)(this + 412) = *(_QWORD *)(HIDWORD(a2) + 1720);
  if ( *(double *)(this + 412) >= 0.0 )
  {
    if ( *(double *)(this + 412) <= 1.0 )
      goto LABEL_46;
    *(_DWORD *)(this + 416) = 1072693248;
  }
  else
  {
    *(_DWORD *)(this + 416) = 0;
  }
  *(_DWORD *)(this + 412) = 0;
LABEL_46:
  *(_QWORD *)(this + 420) = *(_QWORD *)(HIDWORD(a2) + 1728);
  if ( *(double *)(this + 420) >= 0.0 )
  {
    if ( *(double *)(this + 420) <= 1.0 )
      goto LABEL_51;
    *(_DWORD *)(this + 424) = 1072693248;
  }
  else
  {
    *(_DWORD *)(this + 424) = 0;
  }
  *(_DWORD *)(this + 420) = 0;
LABEL_51:
  v42 = (double)*(int *)(a2 + 3268);
  memset(v102, 0, sizeof(v102));
  *(double *)(this + 428) = v42 * *(double *)(a2 + 3256) + *(double *)(a2 + 3248);
  *(double *)(this + 436) = (double)(*(_DWORD *)(a2 + 3264) - 1) * *(double *)(a2 + 3256) + *(double *)(a2 + 3248);
  *(_QWORD *)(this + 444) = *(_QWORD *)(HIDWORD(a2) + 1740);
  *(double *)(this + 452) = flt_7D7418 * *(double *)(this + 136) * (double)*(int *)dword_76926C;
  v95[0] = v99[0] + *(double *)(HIDWORD(a2) + 196);
  v95[1] = v99[1] + *(double *)(HIDWORD(a2) + 204);
  v43 = *(_DWORD *)(this + 484);
  v95[2] = v99[2] + *(double *)(HIDWORD(a2) + 212);
  v44 = *(double *)(this + 428);
  qmemcpy((void *)(this + 460), v95, 0x18u);
  v45 = v44 * 0.726 + 1.0;
  *(double *)(v43 + 172) = v45;
  *(double *)(v43 + 180) = 1.0 / v45;
  qmemcpy((void *)(*(_DWORD *)(this + 484) + 4), v102, 0x18u);
  sub_57BF60(v102);
  qmemcpy((void *)(*(_DWORD *)(this + 484) + 100), v102, 0x18u);
  sub_57C010(v102);
  *(_QWORD *)(this + 488) = *(_QWORD *)(HIDWORD(a2) + 220);
  *(double *)(this + 496) = *(double *)(HIDWORD(a2) + 228) + *(double *)(HIDWORD(a2) + 228);
  *(_BYTE *)(this + 6472) = 0;
  sub_43E640(this, a2, SHIDWORD(a2));
  v95[0] = v101[0] + *(double *)(HIDWORD(a2) + 396);
  v95[1] = v101[1] + *(double *)(HIDWORD(a2) + 404);
  v95[2] = v101[2] + *(double *)(HIDWORD(a2) + 412);
  v46 = v101[0];
  qmemcpy((void *)(this + 6856), v95, 0x18u);
  v95[0] = v46 + *(double *)(HIDWORD(a2) + 496);
  v95[1] = v101[1] + *(double *)(HIDWORD(a2) + 504);
  v95[2] = v101[2] + *(double *)(HIDWORD(a2) + 512);
  v47 = v101[0];
  qmemcpy((void *)(this + 6980), v95, 0x18u);
  v95[0] = v47 + *(double *)(HIDWORD(a2) + 780);
  v95[1] = v101[1] + *(double *)(HIDWORD(a2) + 788);
  v95[2] = v101[2] + *(double *)(HIDWORD(a2) + 796);
  v48 = v99[0];
  qmemcpy((void *)(this + 7100), v95, 0x18u);
  v95[0] = v48 + *(double *)(HIDWORD(a2) + 1048);
  v95[1] = v99[1] + *(double *)(HIDWORD(a2) + 1056);
  v95[2] = v99[2] + *(double *)(HIDWORD(a2) + 1064);
  v49 = v99[0];
  qmemcpy((void *)(this + 7336), v95, 0x18u);
  v95[0] = v49 + *(double *)(HIDWORD(a2) + 1104);
  v95[1] = v99[1] + *(double *)(HIDWORD(a2) + 1112);
  v95[2] = v99[2] + *(double *)(HIDWORD(a2) + 1120);
  v50 = v99[0];
  qmemcpy((void *)(this + 7560), v95, 0x18u);
  v95[0] = v50 + *(double *)(HIDWORD(a2) + 1356);
  v95[1] = v99[1] + *(double *)(HIDWORD(a2) + 1364);
  v95[2] = v99[2] + *(double *)(HIDWORD(a2) + 1372);
  qmemcpy((void *)(this + 7820), v95, 0x18u);
  *(double *)(this + 7924) = ((double)*(int *)(a2 + 5636) * *(double *)(a2 + 5624) + *(double *)(a2 + 5616))
                           * 0.09549296585513721;
  *(_BYTE *)(this + 7932) = *(_BYTE *)(HIDWORD(a2) + 5040);
  *(_BYTE *)(this + 7933) = 0;
  *(_BYTE *)(this + 7934) = 0;
  *(_DWORD *)(this + 8116) = 0;
  *(_DWORD *)(this + 8120) = 0;
  *(_DWORD *)(this + 7936) = 0;
  *(_DWORD *)(this + 7940) = 0;
  *(_DWORD *)(this + 7944) = 0;
  *(_DWORD *)(this + 7948) = 0;
  v51 = *(double *)(HIDWORD(a2) + 1756);
  *(double *)(this + 7952) = v51;
  *(double *)(this + 7960) = 1.0 / v51;
  *(_QWORD *)(this + 7968) = *(_QWORD *)(HIDWORD(a2) + 1780);
  *(_QWORD *)(this + 7976) = *(_QWORD *)(HIDWORD(a2) + 1764);
  *(_QWORD *)(this + 7984) = *(_QWORD *)(HIDWORD(a2) + 1772);
  v52 = (double)*(int *)(a2 + 5508) * *(double *)(a2 + 5496) + *(double *)(a2 + 5488);
  *(double *)(this + 8064) = v52;
  v53 = *(double *)(HIDWORD(a2) + 1812) * 0.5;
  *(double *)(this + 8080) = v53 + v52;
  *(double *)(this + 8072) = *(double *)(this + 8064) - v53;
  *(double *)(this + 7992) = *(double *)(this + 8064) * 0.9350000000000001;
  v54 = *(_DWORD *)(HIDWORD(a2) + 1820);
  if ( v54 <= 0 )
    v55 = 0.0;
  else
    v55 = *(double *)(HIDWORD(a2) + 8 * (3 * v54 + 225));
  v56 = v55 + v55;
  *(double *)(this + 8088) = v56;
  v57 = (__int64)(v56 * -0.03125);
  *(_DWORD *)(this + 8108) = 2 - v57;
  *(_DWORD *)(this + 8096) = operator new(8 * (2 - v57));
  v58 = 0;
  for ( j = 0;
        v58 < *(_DWORD *)(this + 8108);
        *(float *)(*(_DWORD *)(this + 8096) + 8 * v58 - 4) = *(double *)v105 - *(double *)v104 )
  {
    sub_524050((double)j * 32.0, (int)v104, (int)v105);
    *(float *)(*(_DWORD *)(this + 8096) + 8 * v58++) = *(double *)v104;
    j = v58;
  }
  sub_4410A0(this);
  sub_440E20(this);
  *(_QWORD *)(this + 8184) = *(_QWORD *)(HIDWORD(a2) + 4896);
  *(_QWORD *)(this + 0x2000) = *(_QWORD *)(HIDWORD(a2) + 4904);
  *(_QWORD *)(this + 8200) = *(_QWORD *)(HIDWORD(a2) + 4912);
  *(_QWORD *)(this + 8208) = *(_QWORD *)(HIDWORD(a2) + 4920);
  *(_QWORD *)(this + 8224) = *(_QWORD *)(HIDWORD(a2) + 4928);
  *(_QWORD *)(this + 8232) = *(_QWORD *)(HIDWORD(a2) + 4936);
  *(_QWORD *)(this + 8248) = *(_QWORD *)(HIDWORD(a2) + 4944);
  v59 = flt_7DAB0C + 273.16;
  *(_DWORD *)(this + 8216) = 0;
  v60 = v59 + *(double *)(this + 8184);
  *(_DWORD *)(this + 8220) = 0;
  *(double *)(this + 8176) = v60 * 0.5;
  v61 = flt_7DAB0C;
  *(_DWORD *)(this + 8264) = 0;
  *(_DWORD *)(this + 8268) = 0;
  *(double *)(this + 8240) = v61 + 273.16;
  v62 = sub_4D1B00(&dword_7D3C50) * *(double *)(HIDWORD(a2) + 5008) + *(double *)(HIDWORD(a2) + 5000);
  *(double *)(this + 8280) = v62;
  if ( v62 <= 0.0 )
    *(_QWORD *)(this + 8280) = *(_QWORD *)(HIDWORD(a2) + 5000);
  if ( *(_DWORD *)dword_766B6C )
  {
    if ( *(int *)dword_766B6C > 1 && *(int *)dword_766B6C <= 3 )
    {
      if ( dword_75CBB0 == 7 )
        *(double *)(this + 8280) = *(double *)(this + 8280) / flt_7D74C4;
      v63 = this + 1884;
      v64 = 4;
      do
      {
        v63 += 1256;
        --v64;
        *(double *)(v63 - 1256) = flt_7D74C4 * *(double *)(v63 - 1256);
      }
      while ( v64 );
    }
  }
  else
  {
    *(_DWORD *)(this + 8280) = -1;
    *(_DWORD *)(this + 8284) = 2146435071;
    v65 = (_DWORD *)(this + 1884);
    v66 = 4;
    do
    {
      *v65 = 0;
      v65[1] = 0;
      v65 += 314;
      --v66;
    }
    while ( v66 );
  }
  *(_DWORD *)(this + 8272) = 0;
  *(_DWORD *)(this + 8276) = 0;
  *(_QWORD *)(this + 8288) = *(_QWORD *)(HIDWORD(a2) + 4968);
  *(double *)(this + 8296) = 1.0 / *(double *)(HIDWORD(a2) + 4976);
  *(_QWORD *)(this + 8304) = *(_QWORD *)(HIDWORD(a2) + 4984);
  v67 = 1.0 / *(double *)(HIDWORD(a2) + 4992);
  *(_DWORD *)(this + 8328) = 0;
  *(_DWORD *)(this + 8332) = 0;
  *(_DWORD *)(this + 8336) = 0;
  *(_DWORD *)(this + 8340) = 0;
  *(_DWORD *)(this + 8344) = 0;
  *(_DWORD *)(this + 8348) = 0;
  *(double *)(this + 8312) = v67;
  *(double *)(this + 8320) = 3.0 / v67 + *(double *)(this + 8304);
  *(_BYTE *)(this + 8112) = *(_BYTE *)(HIDWORD(a2) + 5041);
  *(_QWORD *)(this + 8124) = *(_QWORD *)(HIDWORD(a2) + 5044);
  *(_QWORD *)(this + 8132) = *(_QWORD *)(HIDWORD(a2) + 5052);
  *(_QWORD *)(this + 8140) = *(_QWORD *)(HIDWORD(a2) + 5060);
  *(_DWORD *)(this + 8148) = 0;
  *(_QWORD *)(this + 8152) = *(_QWORD *)(HIDWORD(a2) + 1788);
  *(_QWORD *)(this + 8160) = *(_QWORD *)(HIDWORD(a2) + 1796);
  *(_QWORD *)(this + 8168) = *(_QWORD *)(HIDWORD(a2) + 1804);
  *(_DWORD *)(this + 8376) = *(_DWORD *)(HIDWORD(a2) + 5152);
  *(double *)(this + 8380) = ((double)*(int *)(a2 + 5252) * *(double *)(a2 + 5240) + *(double *)(a2 + 5232))
                           * *(double *)(HIDWORD(a2) + 5160);
  *(double *)(this + 8388) = (double)*(int *)(a2 + 5316) * *(double *)(a2 + 5304) + *(double *)(a2 + 5296);
  *(double *)(this + 8396) = (double)*(int *)(a2 + 5380) * *(double *)(a2 + 5368) + *(double *)(a2 + 5360);
  *(double *)(this + 8404) = (double)*(int *)(a2 + 5444) * *(double *)(a2 + 5432) + *(double *)(a2 + 5424);
  *(_DWORD *)(this + 8412) = 0;
  *(_DWORD *)(this + 8416) = 0;
  *(_DWORD *)(this + 8420) = 0;
  *(_DWORD *)(this + 8424) = 0;
  v68 = *(double *)(HIDWORD(a2) + 5068);
  *(double *)(this + 8428) = v68;
  *(double *)(this + 8436) = 1.0 / v68;
  *(_QWORD *)(this + 8444) = *(_QWORD *)(HIDWORD(a2) + 5076);
  *(_QWORD *)(this + 8452) = *(_QWORD *)(HIDWORD(a2) + 5084);
  *(_QWORD *)(this + 8460) = *(_QWORD *)(HIDWORD(a2) + 5092);
  *(_QWORD *)(this + 8468) = *(_QWORD *)(HIDWORD(a2) + 5100);
  *(_BYTE *)(this + 145) = *(_BYTE *)(HIDWORD(a2) + 5108);
  *(_BYTE *)(this + 8476) = *(_BYTE *)(HIDWORD(a2) + 5109);
  *(_QWORD *)(this + 8488) = *(_QWORD *)(HIDWORD(a2) + 5112);
  *(double *)(this + 8496) = -*(double *)(HIDWORD(a2) + 5120);
  *(_QWORD *)(this + 8504) = *(_QWORD *)(HIDWORD(a2) + 5128);
  *(double *)(this + 8512) = -*(double *)(HIDWORD(a2) + 5136);
  *(_QWORD *)(this + 8520) = *(_QWORD *)(HIDWORD(a2) + 5144);
  v69 = *(double *)(this + 8520);
  if ( v69 >= 0.0 )
  {
    v69 = *(double *)(this + 8520);
    if ( v69 <= 1.0 )
      goto LABEL_73;
    *(_DWORD *)(this + 8524) = 1072693248;
  }
  else
  {
    *(_DWORD *)(this + 8524) = 0;
  }
  *(_DWORD *)(this + 8520) = 0;
LABEL_73:
  v70 = *(_DWORD *)(HIDWORD(a2) + 5156);
  v71 = 0;
  *(_DWORD *)(this + 8536) = v70;
  if ( v70 >= 0 )
  {
    v94 = (double *)(this + 8540);
    do
    {
      v69 = sub_431A00((int *)a2, v71 + 43);
      *v94++ = v69;
      ++v71;
    }
    while ( v71 <= *(_DWORD *)(this + 8536) );
  }
  sub_431A30((int *)a2);
  if ( v69 == 0.0 )
  {
    *(_DWORD *)(this + 8528) = 0;
    *(_DWORD *)(this + 8532) = 0;
  }
  else
  {
    *(double *)(this + 8528) = 1.0 / v69;
  }
  v72 = *(_DWORD *)(this + 7984);
  v73 = *(_DWORD *)(this + 7988);
  v74 = byte_7D74CB;
  *(_DWORD *)(this + 8000) = v72;
  *(_DWORD *)(this + 8004) = v73;
  *(_DWORD *)(this + 8008) = v72;
  v82 = COERCE_DOUBLE(__PAIR64__(v73, v72));
  *(_DWORD *)(this + 8012) = v73;
  result = *(_DWORD *)(this + 8536);
  v76 = 2;
  if ( result >= 2 )
  {
    v77 = (double *)(this + 8548);
    do
    {
      if ( v74 )
        v78 = 0.835;
      else
        v78 = 0.705;
      v79 = v77[1] / *v77 * *(double *)(this + 7992) * v78;
      if ( v79 < v82 )
        v79 = v82;
      *(double *)((char *)v77 - 532) = v79;
      result = *(_DWORD *)(this + 8536);
      ++v76;
      ++v77;
    }
    while ( v76 <= result );
  }
  *(_DWORD *)(this + 8612) = 0;
  *(_DWORD *)(this + 8604) = 0;
  *(_DWORD *)(this + 8608) = 0;
  *(_DWORD *)(this + 8616) = 0;
  *(_DWORD *)(this + 48) = -2;
  *(_DWORD *)(this + 52) = 3;
  *(_DWORD *)(this + 56) = 0;
  *(_DWORD *)(this + 60) = 0;
  *(_DWORD *)(this + 8624) = 0;
  *(_DWORD *)(this + 8628) = 0;
  *(_DWORD *)(this + 8632) = 0;
  *(_DWORD *)(this + 8636) = 0;
  *(_DWORD *)(this + 8640) = 0;
  *(_DWORD *)(this + 8644) = 0;
  *(_DWORD *)(this + 8648) = 0;
  *(_DWORD *)(this + 8652) = 0;
  *(_DWORD *)(this + 8656) = 0;
  *(_DWORD *)(this + 8660) = 0;
  *(_DWORD *)(this + 8664) = 0;
  *(_DWORD *)(this + 8668) = 0;
  *(_DWORD *)(this + 196) = 0;
  *(_DWORD *)(this + 200) = 0;
  *(_DWORD *)(this + 204) = 0;
  *(_DWORD *)(this + 208) = 0;
  *(_DWORD *)(this + 212) = 0;
  *(_DWORD *)(this + 216) = 0;
  *(_DWORD *)(this + 220) = 0;
  *(_DWORD *)(this + 252) = 0;
  *(_DWORD *)(this + 256) = 0;
  *(_DWORD *)(this + 260) = 0;
  *(_DWORD *)(this + 264) = 0;
  *(_DWORD *)(this + 268) = 0;
  *(_DWORD *)(this + 272) = 0;
  *(_DWORD *)(this + 276) = 0;
  *(_DWORD *)(this + 280) = 0;
  *(_DWORD *)(this + 284) = 0;
  *(_DWORD *)(this + 288) = 0;
  *(_DWORD *)(this + 292) = 0;
  *(_DWORD *)(this + 296) = 0;
  *(_DWORD *)(this + 300) = 0;
  *(_DWORD *)(this + 304) = 0;
  *(_DWORD *)(this + 308) = 0;
  *(_DWORD *)(this + 312) = 0;
  *(_DWORD *)(this + 316) = 0;
  *(_DWORD *)(this + 320) = 0;
  *(_DWORD *)(this + 324) = 0;
  *(_DWORD *)(this + 328) = 0;
  *(_DWORD *)(this + 332) = 0;
  return result;
}
