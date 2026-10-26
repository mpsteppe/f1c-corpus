int __thiscall sub_43C250(int this, __int64 a2)
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
  double v12; // st7
  int v13; // eax
  double *v14; // esi
  double v15; // st7
  int v16; // edx
  double v17; // st7
  int v18; // eax
  bool v19; // zf
  int v20; // eax
  double v21; // st7
  double v22; // st7
  bool v23; // al
  char v24; // dl
  bool v25; // al
  double *v26; // edx
  double *v27; // ecx
  double v28; // st7
  double v29; // st7
  double v30; // st6
  double v31; // st7
  double v32; // st6
  double v33; // st5
  int v34; // eax
  int v35; // esi
  double *v36; // esi
  int v37; // esi
  double v38; // st7
  int v39; // edi
  double v40; // st7
  double v41; // st7
  long double v42; // st7
  double v43; // st7
  int v44; // eax
  double v45; // st7
  double v46; // st7
  double v47; // st7
  double v48; // st7
  double v49; // st7
  double v50; // st7
  int v51; // esi
  double v52; // st7
  double v53; // st7
  double v54; // st7
  double v55; // st6
  int v56; // ecx
  double v57; // st7
  double v58; // st7
  int v59; // eax
  double v60; // st7
  double v61; // st7
  double v62; // st7
  double v63; // st7
  int v64; // eax
  int v65; // edx
  _DWORD *v66; // eax
  int v67; // edx
  double v68; // st7
  double v69; // st7
  double v70; // st7
  double v71; // st7
  int v72; // eax
  int v73; // esi
  double *v74; // eax
  double v75; // rax
  int result; // eax
  int v77; // esi
  double *v78; // edx
  double v79; // st7
  double v80; // st7
  double v81; // [esp+50h] [ebp-C8h]
  double v82; // [esp+50h] [ebp-C8h]
  double v83; // [esp+50h] [ebp-C8h]
  int v84; // [esp+58h] [ebp-C0h]
  int i; // [esp+58h] [ebp-C0h]
  double v86; // [esp+58h] [ebp-C0h]
  int v87; // [esp+58h] [ebp-C0h]
  int v88; // [esp+58h] [ebp-C0h]
  double v89; // [esp+60h] [ebp-B8h]
  double v90; // [esp+60h] [ebp-B8h]
  double v91; // [esp+60h] [ebp-B8h]
  int v92; // [esp+68h] [ebp-B0h]
  double v93; // [esp+68h] [ebp-B0h]
  int v94; // [esp+68h] [ebp-B0h]
  double *v95; // [esp+68h] [ebp-B0h]
  double v96[3]; // [esp+70h] [ebp-A8h] BYREF
  double v97; // [esp+88h] [ebp-90h]
  double v98; // [esp+90h] [ebp-88h]
  double v99; // [esp+98h] [ebp-80h]
  double v100[3]; // [esp+A0h] [ebp-78h] BYREF
  double v101[3]; // [esp+B8h] [ebp-60h] BYREF
  double v102[3]; // [esp+D0h] [ebp-48h] BYREF
  _DWORD v103[6]; // [esp+E8h] [ebp-30h] BYREF
  double v104; // [esp+100h] [ebp-18h]
  int v105[2]; // [esp+108h] [ebp-10h] BYREF
  int v106[2]; // [esp+110h] [ebp-8h] BYREF

  v3 = HIDWORD(a2);
  v4 = a2 + 312;
  v5 = HIDWORD(a2) + 5224;
  v6 = this + 832;
  LODWORD(v97) = a2 + 312;
  LODWORD(v98) = HIDWORD(a2) + 5224;
  v84 = this + 832;
  v92 = 4;
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
    v89 = *(_BYTE *)(v3 + 1353) ? 1.0 / *(double *)v5 : 1.0;
    v99 = v89 * *(double *)(v3 + 1336);
    v7 = v89 * *(double *)(v3 + 1344);
    *(_BYTE *)(v6 + 272) = 0;
    *(_BYTE *)(v6 + 332) = 0;
    ConstraintComplianceMatrixBuild(
      (double *)(v6 - 180),
      v89,
      v99,
      v7,
      (double *)(v5 - 152),
      (double)*(int *)(v4 + 140) * *(double *)(v4 + 128) + *(double *)(v4 + 120),
      (double)*(int *)(v4 + 76) * *(double *)(v4 + 64) + *(double *)(v4 + 56),
      (double)*(int *)(v4 + 268) * *(double *)(v4 + 256) + *(double *)(v4 + 248),
      (double)*(int *)(v4 + 204) * *(double *)(v4 + 192) + *(double *)(v4 + 184),
      (double)*(int *)(v4 + 396) * *(double *)(v4 + 384) + *(double *)(v4 + 376),
      (double)*(int *)(v4 + 332) * *(double *)(v4 + 320) + *(double *)(v4 + 312),
      (double)*(int *)(v4 + 12) * *(double *)v4 + *(double *)(v4 - 8),
      *(double *)(v5 + 8));
    *(_DWORD *)(v6 + 808) = *(_DWORD *)(v5 + 16);
    *(_DWORD *)(v6 + 812) = *(_DWORD *)(v5 + 20);
    *(_DWORD *)(v6 + 816) = *(_DWORD *)(v5 + 24);
    *(_DWORD *)(v6 + 820) = *(_DWORD *)(v5 + 28);
    *(_DWORD *)(v6 + 824) = *(_DWORD *)(v5 + 24);
    *(_DWORD *)(v6 + 828) = *(_DWORD *)(v5 + 28);
    v8 = *(double *)(v5 + 40);
    *(double *)(v6 + 832) = v8;
    *(double *)(v6 + 840) = 3.141592653589793 / v8;
    v10 = (double)(*(_DWORD *)(v9 + 456) - 1) * *(double *)(v9 + 448) + *(double *)(v9 + 440);
    *(double *)(v6 + 848) = flt_8AFEF0 + 273.16;
    *(_DWORD *)(v6 + 856) = *(_DWORD *)(v5 + 32);
    *(_DWORD *)(v6 + 860) = *(_DWORD *)(v5 + 36);
    *(double *)(v6 + 864) = v10 * *(double *)(v5 + 48);
    *(double *)(v6 + 872) = v10 * *(double *)(v5 + 56);
    *(double *)(v6 + 880) = (((double)*(int *)(a2 + 4932) * *(double *)(a2 + 4920) + *(double *)(a2 + 4912))
                           * *(double *)(v5 + 72)
                           + *(double *)(v5 + 64))
                          * v10;
    *(double *)(v6 + 888) = (double)*(int *)(v9 + 460) * *(double *)(v9 + 448) + *(double *)(v9 + 440);
    *(double *)(v6 + 904) = *(double *)(v5 + 88)
                          / (*(double *)(v6 + 856)
                           * *(double *)(v6 + 856)
                           * *(double *)(v6 + 856));
    *(double *)(v6 + 912) = RandomNoiseValueGenerator(&dword_8AAE70) * *(double *)(v5 + 104) + *(double *)(v5 + 96);
    v81 = *(double *)(v6 + 888) * 0.99;
    v11 = *(double *)(v6 + 888) * 0.01;
    if ( v11 <= *(double *)(v6 + 912) )
    {
      if ( *(double *)(v6 + 912) > v81 )
        *(double *)(v6 + 912) = v81;
    }
    else
    {
      *(double *)(v6 + 912) = v11;
    }
    v12 = *(double *)(v5 + 80);
    v13 = *(_DWORD *)(v6 + 168);
    *(double *)(v6 + 896) = v12;
    qmemcpy(v96, (const void *)(v13 + 188), sizeof(v96));
    v14 = (double *)v84;
    v96[0] = v12 * *(double *)(v84 + 888) + *(double *)(v84 + 24);
    StructCopyWithReciprocalDivision(v96);
    v15 = v14[112] * v14[111];
    v16 = LODWORD(v98);
    *(_DWORD *)(v84 + 432) = 0;
    v17 = v15 + *(double *)(v84 + 24);
    *(_DWORD *)(v84 + 436) = 0;
    *(_DWORD *)(v84 + 444) = 0;
    *(_DWORD *)(v84 + 448) = 0;
    v18 = LODWORD(v97);
    *(_DWORD *)(v84 + 440) = 1072693248;
    v18 += 704;
    LODWORD(v97) = v18;
    v84 += 1124;
    LODWORD(v98) = v16 + 264;
    v14[4] = 1.0 / v17;
    v19 = v92 == 1;
    v14[89] = (double)*(int *)(v18 - 756) * *(double *)(v18 - 768) + *(double *)(v18 - 776);
    --v92;
    if ( v19 )
      break;
    v6 = v84;
    v5 = LODWORD(v98);
    v4 = LODWORD(v97);
    v3 = HIDWORD(a2);
  }
  v20 = TireBrandLookup(HIDWORD(a2) + 136);
  *(_DWORD *)(this + 5208) = v20;
  if ( !v20 && dword_7C569C != 5 && (unsigned __int8)StringSplitLoop(1, aDDevF119992002, 3301) )
    DebugLogWrite(&dword_8AD25C, aHdvFileReferen);
  *(_DWORD *)(this + 5212) = *(_DWORD *)(a2 + 3012);
  for ( i = 0; i < 4; ++i )
    TireCompoundPerWheelPhysicsApplication(i);
  if ( *(_BYTE *)(HIDWORD(a2) + 1353) )
    v90 = 0.5 / *(double *)(HIDWORD(a2) + 5488) + 0.5 / *(double *)(HIDWORD(a2) + 5224);
  else
    v90 = 1.0;
  v93 = v90 * *(double *)(HIDWORD(a2) + 1336);
  v86 = v90 * *(double *)(HIDWORD(a2) + 1344);
  v21 = (double)*(int *)(a2 + 3332) * *(double *)(a2 + 3320) + *(double *)(a2 + 3312);
  RandomOffsetCalculator(v21);
  *(double *)(this + 5176) = v21 * v93 * 0.5;
  if ( *(_BYTE *)(HIDWORD(a2) + 1353) )
    v82 = 0.5 / *(double *)(HIDWORD(a2) + 6016) + 0.5 / *(double *)(HIDWORD(a2) + 5752);
  else
    v82 = 1.0;
  v97 = v82 * *(double *)(HIDWORD(a2) + 1336);
  v104 = v82 * *(double *)(HIDWORD(a2) + 1344);
  v22 = (double)*(int *)(a2 + 3396) * *(double *)(a2 + 3384) + *(double *)(a2 + 3376);
  BiasValueComputation(v22);
  *(double *)(this + 5184) = v22 * v97 * 0.5;
  v98 = ((double)*(int *)(a2 + 324) * *(double *)(a2 + 312)
       + *(double *)(a2 + 304)
       + (double)*(int *)(a2 + 1028) * *(double *)(a2 + 1016)
       + *(double *)(a2 + 1008))
      * 0.5;
  v99 = (*(double *)(HIDWORD(a2) + 5496) + *(double *)(HIDWORD(a2) + 5232)) * 0.5;
  ConstraintComplianceMatrixBuild(
    (double *)(this + 5220),
    v90,
    v93,
    v86,
    (double *)(HIDWORD(a2) + 1440),
    (double)*(int *)(a2 + 4036) * *(double *)(a2 + 4024) + *(double *)(a2 + 4016),
    (double)*(int *)(a2 + 3972) * *(double *)(a2 + 3960) + *(double *)(a2 + 3952),
    (double)*(int *)(a2 + 4164) * *(double *)(a2 + 4152) + *(double *)(a2 + 4144),
    (double)*(int *)(a2 + 4100) * *(double *)(a2 + 4088) + *(double *)(a2 + 4080),
    (double)*(int *)(a2 + 4292) * *(double *)(a2 + 4280) + *(double *)(a2 + 4272),
    (double)*(int *)(a2 + 4228) * *(double *)(a2 + 4216) + *(double *)(a2 + 4208),
    v98,
    v99);
  v91 = ((double)*(int *)(a2 + 2436) * *(double *)(a2 + 2424)
       + *(double *)(a2 + 2416)
       + (double)*(int *)(a2 + 1732) * *(double *)(a2 + 1720)
       + *(double *)(a2 + 1712))
      * 0.5;
  v99 = (*(double *)(HIDWORD(a2) + 6024) + *(double *)(HIDWORD(a2) + 5760)) * 0.5;
  v23 = ConstraintComplianceMatrixBuild(
          (double *)(this + 5340),
          v82,
          v97,
          v104,
          (double *)(HIDWORD(a2) + 1504),
          (double)*(int *)(a2 + 4420) * *(double *)(a2 + 4408) + *(double *)(a2 + 4400),
          (double)*(int *)(a2 + 4356) * *(double *)(a2 + 4344) + *(double *)(a2 + 4336),
          (double)*(int *)(a2 + 4548) * *(double *)(a2 + 4536) + *(double *)(a2 + 4528),
          (double)*(int *)(a2 + 4484) * *(double *)(a2 + 4472) + *(double *)(a2 + 4464),
          (double)*(int *)(a2 + 4676) * *(double *)(a2 + 4664) + *(double *)(a2 + 4656),
          (double)*(int *)(a2 + 4612) * *(double *)(a2 + 4600) + *(double *)(a2 + 4592),
          v91,
          v99);
  v25 = v24 || v23;
  *(_BYTE *)(this + 5216) = v25;
  *(_BYTE *)(this + 112) = byte_7CE254 == 0;
  v26 = (double *)(*(_DWORD *)(this + 1000) + 4);
  *(double *)(this + 5460) = (double)*(int *)(a2 + 5124) * *(double *)(a2 + 5112) + *(double *)(a2 + 5104);
  *(double *)(this + 5468) = (double)*(int *)(a2 + 5060) * *(double *)(a2 + 5048) + *(double *)(a2 + 5040);
  qmemcpy((void *)(this + 5484), (const void *)(a2 + 4976), 0x40u);
  v27 = (double *)(*(_DWORD *)(this + 2124) + 4);
  v28 = (double)*(int *)(this + 5504) * *(double *)(this + 5492) + *(double *)(this + 5484);
  *(_DWORD *)(this + 208) = 1;
  *(_DWORD *)(this + 5720) = 0;
  *(_DWORD *)(this + 5724) = 0;
  *(double *)(this + 5476) = v28;
  v29 = *v27 + *v26;
  v30 = v26[1] + v27[1];
  v96[2] = v26[2] + v27[2];
  v101[0] = v29 * 0.5;
  v101[1] = v30 * 0.5;
  v101[2] = v96[2] * 0.5;
  v31 = *(double *)(HIDWORD(a2) + 96);
  qmemcpy(v102, v101, sizeof(v102));
  v102[1] = -v31;
  v32 = *(double *)(*(_DWORD *)(this + 4372) + 4) + *(double *)(*(_DWORD *)(this + 3248) + 4);
  v33 = *(double *)(*(_DWORD *)(this + 3248) + 12) + *(double *)(*(_DWORD *)(this + 4372) + 12);
  v96[2] = *(double *)(*(_DWORD *)(this + 3248) + 20) + *(double *)(*(_DWORD *)(this + 4372) + 20);
  v34 = this + 5872;
  v101[0] = v32 * 0.5;
  v101[1] = v33 * 0.5;
  v101[2] = v96[2] * 0.5;
  qmemcpy(v100, v101, sizeof(v100));
  v100[1] = v102[1];
  LODWORD(v98) = this + 5736;
  v35 = 0;
  v94 = a2 + 312;
  v87 = 0;
  LODWORD(v97) = HIDWORD(a2) + 5208;
  while ( 1 )
  {
    if ( !v35 || (v19 = v35 == 1, v36 = v100, v19) )
      v36 = v102;
    qmemcpy(v101, v36, sizeof(v101));
    v34 += 8;
    v96[0] = v101[0] + *(double *)(LODWORD(v97) - 16);
    v96[1] = v101[1] + *(double *)(LODWORD(v97) - 8);
    v96[2] = v101[2] + *(double *)LODWORD(v97);
    qmemcpy((void *)(LODWORD(v98) - 8), v96, 0x18u);
    v37 = LODWORD(v98);
    *(_DWORD *)(v34 - 56) = *(_DWORD *)LODWORD(v98);
    *(_DWORD *)(v34 - 52) = *(_DWORD *)(v37 + 4);
    v38 = (double)*(int *)(v94 + 12);
    ++v87;
    v94 += 704;
    v39 = LODWORD(v97) + 264;
    v40 = v38 * *(double *)(v94 - 704) + *(double *)(v94 - 712);
    *(double *)(v34 - 8) = v40;
    *(double *)(v34 + 48) = v40;
    LODWORD(v97) = v39;
    LODWORD(v98) = v37 + 24;
    if ( v87 >= 4 )
      break;
    v35 = v87;
  }
  v41 = *(double *)(this + 5744);
  *(_BYTE *)(this + 5912) = 0;
  v42 = v41 - *(double *)(this + 5792);
  *(_DWORD *)(this + 5916) = 0;
  *(_DWORD *)(this + 5920) = 0;
  *(long double *)(this + 5904) = fabs(v42);
  *(_QWORD *)(this + 320) = *(_QWORD *)(HIDWORD(a2) + 1568);
  *(_QWORD *)(this + 328) = *(_QWORD *)(HIDWORD(a2) + 1576);
  *(_QWORD *)(this + 336) = *(_QWORD *)(HIDWORD(a2) + 1584);
  *(_QWORD *)(this + 344) = *(_QWORD *)(HIDWORD(a2) + 1592);
  *(_QWORD *)(this + 352) = *(_QWORD *)(HIDWORD(a2) + 1600);
  if ( *(double *)(this + 352) >= 0.0 )
  {
    if ( *(double *)(this + 352) > 1.0 )
    {
      *(_DWORD *)(this + 352) = 0;
      *(_DWORD *)(this + 356) = 1072693248;
    }
  }
  else
  {
    *(_DWORD *)(this + 352) = 0;
    *(_DWORD *)(this + 356) = 0;
  }
  *(_QWORD *)(this + 360) = *(_QWORD *)(HIDWORD(a2) + 1608);
  if ( *(double *)(this + 360) >= 0.0 )
  {
    if ( *(double *)(this + 360) <= 1.0 )
      goto LABEL_42;
    *(_DWORD *)(this + 364) = 1072693248;
  }
  else
  {
    *(_DWORD *)(this + 364) = 0;
  }
  *(_DWORD *)(this + 360) = 0;
LABEL_42:
  *(_DWORD *)(this + 368) = 0;
  *(_DWORD *)(this + 372) = 0;
  *(_BYTE *)(this + 376) = *(_BYTE *)(HIDWORD(a2) + 1616);
  *(_QWORD *)(this + 380) = *(_QWORD *)(HIDWORD(a2) + 1620);
  *(_QWORD *)(this + 388) = *(_QWORD *)(HIDWORD(a2) + 1628);
  *(_QWORD *)(this + 396) = *(_QWORD *)(HIDWORD(a2) + 1636);
  if ( *(double *)(this + 396) >= 0.0 )
  {
    if ( *(double *)(this + 396) <= 1.0 )
      goto LABEL_47;
    *(_DWORD *)(this + 400) = 1072693248;
  }
  else
  {
    *(_DWORD *)(this + 400) = 0;
  }
  *(_DWORD *)(this + 396) = 0;
LABEL_47:
  *(_QWORD *)(this + 404) = *(_QWORD *)(HIDWORD(a2) + 1644);
  if ( *(double *)(this + 404) >= 0.0 )
  {
    if ( *(double *)(this + 404) <= 1.0 )
      goto LABEL_52;
    *(_DWORD *)(this + 408) = 1072693248;
  }
  else
  {
    *(_DWORD *)(this + 408) = 0;
  }
  *(_DWORD *)(this + 404) = 0;
LABEL_52:
  v43 = (double)*(int *)(a2 + 3268);
  memset(v103, 0, sizeof(v103));
  *(double *)(this + 412) = v43 * *(double *)(a2 + 3256) + *(double *)(a2 + 3248);
  *(double *)(this + 420) = (double)(*(_DWORD *)(a2 + 3264) - 1) * *(double *)(a2 + 3256) + *(double *)(a2 + 3248);
  *(_QWORD *)(this + 428) = *(_QWORD *)(HIDWORD(a2) + 1652);
  v44 = *(_DWORD *)(this + 468);
  *(double *)(this + 436) = (double)dword_7D0B64 * *(double *)(this + 104);
  v96[0] = v100[0] + *(double *)(HIDWORD(a2) + 200);
  v96[1] = v100[1] + *(double *)(HIDWORD(a2) + 208);
  v96[2] = v100[2] + *(double *)(HIDWORD(a2) + 216);
  v45 = *(double *)(this + 412);
  qmemcpy((void *)(this + 444), v96, 0x18u);
  v46 = v45 * 0.75 + 1.0;
  *(double *)(v44 + 172) = v46;
  *(double *)(v44 + 180) = 1.0 / v46;
  qmemcpy((void *)(*(_DWORD *)(this + 468) + 4), v103, 0x18u);
  F_3x3RotationTensorMatrixTransform(v103);
  qmemcpy((void *)(*(_DWORD *)(this + 468) + 100), v103, 0x18u);
  Copy6DwordsToStructCall(v103);
  *(_QWORD *)(this + 472) = *(_QWORD *)(HIDWORD(a2) + 224);
  *(double *)(this + 480) = *(double *)(HIDWORD(a2) + 232) + *(double *)(HIDWORD(a2) + 232);
  *(_BYTE *)(this + 5924) = 0;
  sub_43BC20(this, a2, SHIDWORD(a2));
  v96[0] = v102[0] + *(double *)(HIDWORD(a2) + 384);
  v96[1] = v102[1] + *(double *)(HIDWORD(a2) + 392);
  v96[2] = v102[2] + *(double *)(HIDWORD(a2) + 400);
  qmemcpy((void *)(this + 6276), v96, 0x18u);
  v96[0] = v102[0] + *(double *)(HIDWORD(a2) + 468);
  v96[1] = v102[1] + *(double *)(HIDWORD(a2) + 476);
  v96[2] = v102[2] + *(double *)(HIDWORD(a2) + 484);
  v47 = v102[0];
  qmemcpy((void *)(this + 6376), v96, 0x18u);
  v96[0] = v47 + *(double *)(HIDWORD(a2) + 736);
  v96[1] = v102[1] + *(double *)(HIDWORD(a2) + 744);
  v96[2] = v102[2] + *(double *)(HIDWORD(a2) + 752);
  v48 = v100[0];
  qmemcpy((void *)(this + 6472), v96, 0x18u);
  v96[0] = v48 + *(double *)(HIDWORD(a2) + 988);
  v96[1] = v100[1] + *(double *)(HIDWORD(a2) + 996);
  v96[2] = v100[2] + *(double *)(HIDWORD(a2) + 1004);
  v49 = v100[0];
  qmemcpy((void *)(this + 6684), v96, 0x18u);
  v96[0] = v49 + *(double *)(HIDWORD(a2) + 1044);
  v96[1] = v100[1] + *(double *)(HIDWORD(a2) + 1052);
  v96[2] = v100[2] + *(double *)(HIDWORD(a2) + 1060);
  v50 = v100[0];
  qmemcpy((void *)(this + 6908), v96, 0x18u);
  v96[0] = v50 + *(double *)(HIDWORD(a2) + 1280);
  v96[1] = v100[1] + *(double *)(HIDWORD(a2) + 1288);
  v96[2] = v100[2] + *(double *)(HIDWORD(a2) + 1296);
  qmemcpy((void *)(this + 7144), v96, 0x18u);
  v51 = 0;
  v52 = (double)*(int *)(a2 + 5636) * *(double *)(a2 + 5624) + *(double *)(a2 + 5616);
  *(_BYTE *)(this + 7256) = 0;
  *(_BYTE *)(this + 7257) = 0;
  *(_DWORD *)(this + 7440) = 0;
  *(_DWORD *)(this + 7444) = 0;
  *(_DWORD *)(this + 7260) = 0;
  *(_DWORD *)(this + 7264) = 0;
  *(_DWORD *)(this + 7268) = 0;
  *(_DWORD *)(this + 7272) = 0;
  *(double *)(this + 7248) = v52 * 0.09549296585513721;
  v53 = *(double *)(HIDWORD(a2) + 1668);
  *(double *)(this + 7276) = v53;
  *(double *)(this + 7284) = 1.0 / v53;
  *(_QWORD *)(this + 7292) = *(_QWORD *)(HIDWORD(a2) + 1692);
  *(_QWORD *)(this + 7300) = *(_QWORD *)(HIDWORD(a2) + 1676);
  *(_QWORD *)(this + 7308) = *(_QWORD *)(HIDWORD(a2) + 1684);
  v54 = (double)*(int *)(a2 + 5508) * *(double *)(a2 + 5496) + *(double *)(a2 + 5488);
  *(double *)(this + 7388) = v54;
  v55 = *(double *)(HIDWORD(a2) + 1724) * 0.5;
  *(double *)(this + 7404) = v55 + v54;
  *(double *)(this + 7396) = *(double *)(this + 7388) - v55;
  *(double *)(this + 7316) = *(double *)(this + 7388) * 0.975;
  v56 = *(_DWORD *)(HIDWORD(a2) + 1732);
  if ( v56 <= 0 )
    v57 = 0.0;
  else
    v57 = *(double *)(HIDWORD(a2) + 24 * v56 + 1712);
  v58 = v57 + v57;
  *(double *)(this + 7412) = v58;
  v59 = CRTFtol(v58 * -0.03125);
  *(_DWORD *)(this + 7432) = 2 - v59;
  *(_DWORD *)(this + 7420) = OperatorNewNhMallocWrapper(8 * (2 - v59));
  v88 = 0;
  if ( *(int *)(this + 7432) > 0 )
  {
    do
    {
      ParameterizedCurveInterpolation((double)v88 * 32.0, (int)v105, (int)v106);
      *(float *)(*(_DWORD *)(this + 7420) + 8 * v51++) = *(double *)v105;
      v88 = v51;
      *(float *)(*(_DWORD *)(this + 7420) + 8 * v51 - 4) = *(double *)v106 - *(double *)v105;
    }
    while ( v51 < *(_DWORD *)(this + 7432) );
  }
  *(_QWORD *)(this + 7508) = *(_QWORD *)(HIDWORD(a2) + 4808);
  *(_QWORD *)(this + 7516) = *(_QWORD *)(HIDWORD(a2) + 4816);
  *(_QWORD *)(this + 7524) = *(_QWORD *)(HIDWORD(a2) + 4824);
  *(_QWORD *)(this + 7532) = *(_QWORD *)(HIDWORD(a2) + 4832);
  *(_QWORD *)(this + 7548) = *(_QWORD *)(HIDWORD(a2) + 4840);
  *(_QWORD *)(this + 7556) = *(_QWORD *)(HIDWORD(a2) + 4848);
  *(_QWORD *)(this + 7572) = *(_QWORD *)(HIDWORD(a2) + 4856);
  v60 = flt_8AFEF0 + 273.16;
  *(_DWORD *)(this + 7540) = 0;
  v61 = v60 + *(double *)(this + 7508);
  *(_DWORD *)(this + 7544) = 0;
  *(double *)(this + 7500) = v61 * 0.5;
  v62 = flt_8AFEF0;
  *(_DWORD *)(this + 7588) = 0;
  *(_DWORD *)(this + 7592) = 0;
  *(double *)(this + 7564) = v62 + 273.16;
  v63 = RandomNoiseValueGenerator(&dword_8AAE70) * *(double *)(HIDWORD(a2) + 4920) + *(double *)(HIDWORD(a2) + 4912);
  *(double *)(this + 7604) = v63;
  if ( v63 <= 0.0 )
    *(_QWORD *)(this + 7604) = *(_QWORD *)(HIDWORD(a2) + 4912);
  if ( dword_7CEA5C )
  {
    if ( dword_7CEA5C > 1 && dword_7CEA5C <= 3 )
    {
      if ( dword_7C56A4 == 7 )
        *(double *)(this + 7604) = *(double *)(this + 7604) / flt_8ACF9C;
      v64 = this + 1736;
      v65 = 4;
      do
      {
        v64 += 1124;
        --v65;
        *(double *)(v64 - 1124) = flt_8ACF9C * *(double *)(v64 - 1124);
      }
      while ( v65 );
    }
  }
  else
  {
    *(_DWORD *)(this + 7604) = -1;
    *(_DWORD *)(this + 7608) = 2146435071;
    v66 = (_DWORD *)(this + 1736);
    v67 = 4;
    do
    {
      *v66 = 0;
      v66[1] = 0;
      v66 += 281;
      --v67;
    }
    while ( v67 );
  }
  *(_DWORD *)(this + 7596) = 0;
  *(_DWORD *)(this + 7600) = 0;
  *(_QWORD *)(this + 7612) = *(_QWORD *)(HIDWORD(a2) + 4880);
  *(double *)(this + 7620) = 1.0 / *(double *)(HIDWORD(a2) + 4888);
  *(_QWORD *)(this + 7628) = *(_QWORD *)(HIDWORD(a2) + 4896);
  v68 = 1.0 / *(double *)(HIDWORD(a2) + 4904);
  *(_DWORD *)(this + 7652) = 0;
  *(_DWORD *)(this + 7656) = 0;
  *(_DWORD *)(this + 7660) = 0;
  *(_DWORD *)(this + 7664) = 0;
  *(_DWORD *)(this + 7668) = 0;
  *(_DWORD *)(this + 7672) = 0;
  *(double *)(this + 7636) = v68;
  *(double *)(this + 7644) = 3.0 / v68 + *(double *)(this + 7628);
  *(_BYTE *)(this + 7436) = *(_BYTE *)(HIDWORD(a2) + 4952);
  *(_QWORD *)(this + 7448) = *(_QWORD *)(HIDWORD(a2) + 4956);
  *(_QWORD *)(this + 7456) = *(_QWORD *)(HIDWORD(a2) + 4964);
  *(_QWORD *)(this + 7464) = *(_QWORD *)(HIDWORD(a2) + 4972);
  *(_DWORD *)(this + 7472) = 0;
  v69 = *(double *)(HIDWORD(a2) + 1700);
  *(double *)(this + 7476) = v69;
  if ( byte_7CE97C )
  {
    if ( v69 <= 0.75 )
      v69 = 0.75;
    *(double *)(this + 7476) = v69;
  }
  *(_QWORD *)(this + 7484) = *(_QWORD *)(HIDWORD(a2) + 1708);
  *(_QWORD *)(this + 7492) = *(_QWORD *)(HIDWORD(a2) + 1716);
  *(_DWORD *)(this + 7700) = *(_DWORD *)(HIDWORD(a2) + 5056);
  *(double *)(this + 7704) = ((double)*(int *)(a2 + 5252) * *(double *)(a2 + 5240) + *(double *)(a2 + 5232))
                           * *(double *)(HIDWORD(a2) + 5064);
  *(double *)(this + 7712) = (double)*(int *)(a2 + 5316) * *(double *)(a2 + 5304) + *(double *)(a2 + 5296);
  *(double *)(this + 7720) = (double)*(int *)(a2 + 5380) * *(double *)(a2 + 5368) + *(double *)(a2 + 5360);
  *(double *)(this + 7728) = (double)*(int *)(a2 + 5444) * *(double *)(a2 + 5432) + *(double *)(a2 + 5424);
  *(_DWORD *)(this + 7736) = 0;
  *(_DWORD *)(this + 7740) = 0;
  *(_DWORD *)(this + 7744) = 0;
  *(_DWORD *)(this + 7748) = 0;
  v70 = *(double *)(HIDWORD(a2) + 4980);
  *(double *)(this + 7752) = v70;
  *(double *)(this + 7760) = 1.0 / v70;
  *(_QWORD *)(this + 7768) = *(_QWORD *)(HIDWORD(a2) + 4988);
  *(_QWORD *)(this + 7776) = *(_QWORD *)(HIDWORD(a2) + 4996);
  *(_QWORD *)(this + 7784) = *(_QWORD *)(HIDWORD(a2) + 5004);
  *(_QWORD *)(this + 7792) = *(_QWORD *)(HIDWORD(a2) + 5012);
  *(_BYTE *)(this + 113) = *(_BYTE *)(HIDWORD(a2) + 5020);
  *(_BYTE *)(this + 7800) = *(_BYTE *)(HIDWORD(a2) + 5021);
  *(_QWORD *)(this + 7812) = *(_QWORD *)(HIDWORD(a2) + 5024);
  *(double *)(this + 7820) = -*(double *)(HIDWORD(a2) + 5032);
  *(_QWORD *)(this + 7828) = *(_QWORD *)(HIDWORD(a2) + 5040);
  v71 = -*(double *)(HIDWORD(a2) + 5048);
  *(double *)(this + 7836) = v71;
  v72 = *(_DWORD *)(HIDWORD(a2) + 5060);
  v73 = 0;
  *(_DWORD *)(this + 7852) = v72;
  if ( v72 >= 0 )
  {
    v95 = (double *)(this + 7856);
    do
    {
      v71 = SessionStateIndexedLookup((int *)a2, v73 + 43);
      v74 = v95;
      if ( v73 == 8 )
        v74 = (double *)(dword_5C7530 + 64);
      *v74 = v71;
      v95 = v74 + 1;
      ++v73;
    }
    while ( v73 <= *(_DWORD *)(this + 7852) );
  }
  AIPathNodeDelegate((int *)a2);
  if ( v71 == 0.0 )
  {
    *(_DWORD *)(this + 7844) = 0;
    *(_DWORD *)(this + 7848) = 0;
  }
  else
  {
    *(double *)(this + 7844) = 1.0 / v71;
  }
  v75 = *(double *)(this + 7308);
  *(double *)(this + 7324) = v75;
  *(double *)(this + 7332) = v75;
  v83 = v75;
  result = *(_DWORD *)(this + 7852);
  v77 = 2;
  if ( result >= 2 )
  {
    v78 = (double *)(this + 7872);
    do
    {
      if ( v77 == 8 )
      {
        v78 = (double *)(dword_5C7530 + 64);
        v79 = *(double *)(dword_5C7530 + 64) / dbl_7C9310;
      }
      else
      {
        v79 = *v78 / *(v78 - 1);
      }
      v80 = v79 * *(double *)(this + 7316) * 0.825;
      if ( v80 < v83 )
        v80 = v83;
      if ( v77 < 8 )
        *(double *)((char *)v78 - 532) = v80;
      else
        *(v78 - 8) = v80;
      result = *(_DWORD *)(this + 7852);
      ++v77;
      ++v78;
    }
    while ( v77 <= result );
  }
  *(_DWORD *)(this + 7928) = 0;
  *(_DWORD *)(this + 7920) = 0;
  *(_DWORD *)(this + 7924) = 0;
  *(_DWORD *)(this + 7932) = 0;
  *(_DWORD *)(this + 48) = -2;
  *(_DWORD *)(this + 52) = 3;
  *(_DWORD *)(this + 56) = 0;
  *(_DWORD *)(this + 60) = 0;
  *(_DWORD *)(this + 7940) = 0;
  *(_DWORD *)(this + 7944) = 0;
  *(_DWORD *)(this + 7948) = 0;
  *(_DWORD *)(this + 7952) = 0;
  *(_DWORD *)(this + 7956) = 0;
  *(_DWORD *)(this + 7960) = 0;
  *(_DWORD *)(this + 7964) = 0;
  *(_DWORD *)(this + 7968) = 0;
  *(_DWORD *)(this + 7972) = 0;
  *(_DWORD *)(this + 7976) = 0;
  *(_DWORD *)(this + 7980) = 0;
  *(_DWORD *)(this + 7984) = 0;
  *(_DWORD *)(this + 180) = 0;
  *(_DWORD *)(this + 184) = 0;
  *(_DWORD *)(this + 188) = 0;
  *(_DWORD *)(this + 192) = 0;
  *(_DWORD *)(this + 196) = 0;
  *(_DWORD *)(this + 200) = 0;
  *(_DWORD *)(this + 204) = 0;
  *(_DWORD *)(this + 236) = 0;
  *(_DWORD *)(this + 240) = 0;
  *(_DWORD *)(this + 244) = 0;
  *(_DWORD *)(this + 248) = 0;
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
  return result;
}

