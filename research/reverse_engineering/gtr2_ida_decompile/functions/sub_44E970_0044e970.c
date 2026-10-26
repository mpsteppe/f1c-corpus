int __thiscall sub_44E970(int this, int a2, int a3)
{
  int v3; // edi
  int v5; // esi
  double *v6; // eax
  long double v7; // st7
  double v8; // st6
  int v9; // edx
  double v10; // st5
  double *v11; // edx
  double v12; // st7
  double v13; // st7
  double v14; // st7
  double v15; // st7
  double v16; // st7
  double v17; // st7
  double v18; // st7
  int v19; // ecx
  double v20; // st7
  int v21; // eax
  double v22; // st7
  int v23; // edx
  int v24; // eax
  double v25; // st7
  int v26; // eax
  double v27; // st7
  double v28; // st7
  double v29; // st7
  double v30; // st7
  double *v31; // edi
  bool v32; // al
  char v33; // dl
  bool v34; // al
  double *v35; // ecx
  double v36; // st7
  double *v37; // edx
  double v38; // st7
  double *v39; // ecx
  int v40; // edx
  double v41; // st6
  double v42; // st6
  int v43; // edx
  int v44; // ecx
  int v45; // eax
  bool v46; // zf
  double *v47; // edx
  double v48; // st7
  int v49; // edx
  double v50; // st7
  int v51; // edx
  int v52; // edi
  double v53; // st7
  double v54; // st7
  int v55; // edi
  double v56; // st7
  long double v57; // st7
  double v58; // st7
  double v59; // st7
  double v60; // st7
  double v61; // st7
  int v62; // ecx
  double v63; // st7
  int v64; // eax
  int v65; // ecx
  double v66; // st7
  int v67; // eax
  int v68; // ecx
  int v69; // eax
  double v70; // st7
  int v71; // edx
  int v72; // eax
  double v73; // st7
  double v74; // st7
  int v75; // edx
  int v76; // eax
  double v77; // st7
  int v78; // edx
  int v79; // eax
  double v80; // st7
  int v81; // edx
  int v82; // eax
  double v83; // st7
  int v84; // edx
  int v85; // eax
  double v86; // st7
  double v87; // st7
  int v88; // edx
  int v89; // eax
  double v90; // st7
  int v91; // edx
  int v92; // eax
  double v93; // st7
  int v94; // edx
  int v95; // eax
  double v96; // st7
  int v97; // edx
  int v98; // eax
  double v99; // st7
  int v100; // edx
  int v101; // eax
  int v102; // edx
  int v103; // eax
  double v104; // st7
  double v105; // st7
  double v106; // st6
  double v107; // st7
  int v108; // eax
  double v109; // st7
  double v110; // st7
  unsigned __int64 v111; // rax
  int v112; // eax
  int v113; // esi
  int v114; // ecx
  double v115; // st7
  double v116; // st7
  double v117; // st7
  double v118; // st7
  double v119; // st7
  double v120; // st7
  int v121; // eax
  int v122; // ecx
  double v123; // st7
  int v124; // edx
  double *v125; // ecx
  double v126; // st6
  double v127; // st7
  int result; // eax
  _BYTE v129[28]; // [esp+68h] [ebp-F0h] BYREF
  double v130; // [esp+84h] [ebp-D4h]
  __int128 v131; // [esp+8Ch] [ebp-CCh]
  double v132; // [esp+9Ch] [ebp-BCh]
  __int128 v133; // [esp+A4h] [ebp-B4h]
  __int128 v134; // [esp+B4h] [ebp-A4h]
  double v135; // [esp+C4h] [ebp-94h]
  _BYTE v136[56]; // [esp+CCh] [ebp-8Ch] BYREF
  __int128 v137; // [esp+104h] [ebp-54h] BYREF
  double v138; // [esp+114h] [ebp-44h]
  __int128 v139; // [esp+124h] [ebp-34h] BYREF
  double v140; // [esp+134h] [ebp-24h]
  double v141; // [esp+144h] [ebp-14h]
  double v142; // [esp+14Ch] [ebp-Ch]

  v3 = a2 + 312;
  HIDWORD(v133) = a3 + 5840;
  HIDWORD(v130) = a3 + 5840;
  v5 = this + 896;
  *(_DWORD *)&v136[4] = 4;
  do
  {
    v6 = (double *)HIDWORD(v130);
    *(double *)(v5 - 8) = 0.0;
    *(double *)v5 = 0.0;
    *(double *)(v5 + 8) = 0.0;
    *(double *)(v5 + 16) = 0.0;
    *(double *)(v5 + 40) = 0.0;
    *(double *)(v5 + 144) = 1.0;
    *(double *)(v5 + 152) = 1.0;
    *(double *)(v5 + 72) = -1.797693134862316e308;
    *(double *)(v5 + 104) = -1.797693134862316e308;
    *(double *)(v5 + 24) = *(v6 - 1);
    v7 = 1.0;
    if ( *(_BYTE *)(a3 + 1537) )
      v7 = 1.0 / *v6;
    v8 = v7 * *(double *)(a3 + 1504);
    v9 = HIDWORD(v130);
    v10 = v7 * *(double *)(a3 + 1512);
    *(_BYTE *)(v5 + 272) = 0;
    *(_BYTE *)(v5 + 336) = 0;
    sub_439540(
      (double *)(v5 - 184),
      v7,
      v8,
      v10,
      (double *)(v9 - 144),
      ((double)*(int *)(v3 + 140) * *(double *)(v3 + 128) + *(double *)(v3 + 120)) * *(double *)(v9 - 80),
      (double)*(int *)(v3 + 76) * *(double *)(v3 + 64) + *(double *)(v3 + 56),
      ((double)*(int *)(v3 + 268) * *(double *)(v3 + 256) + *(double *)(v3 + 248)) * *(double *)(v9 - 72),
      ((double)*(int *)(v3 + 204) * *(double *)(v3 + 192) + *(double *)(v3 + 184)) * *(double *)(v9 - 72),
      ((double)*(int *)(v3 + 396) * *(double *)(v3 + 384) + *(double *)(v3 + 376)) * *(double *)(v9 - 72),
      ((double)*(int *)(v3 + 332) * *(double *)(v3 + 320) + *(double *)(v3 + 312)) * *(double *)(v9 - 72),
      (double)*(int *)(v3 + 12) * *(double *)v3 + *(double *)(v3 - 8),
      *(double *)(v9 + 8));
    *(double *)(v5 + 944) = v11[2];
    v12 = v11[3];
    *(double *)(v5 + 952) = v12;
    *(double *)(v5 + 1064) = v12;
    *(double *)(v5 + 960) = v11[3];
    v13 = v11[5];
    *(double *)(v5 + 968) = v13;
    *(double *)(v5 + 976) = 3.141592653589793 / v13;
    DWORD1(v133) = *(_DWORD *)(v3 + 456) - 1;
    v14 = (double)SDWORD1(v133) * *(double *)(v3 + 448) + *(double *)(v3 + 440);
    *(double *)(v5 + 984) = flt_FB1F2C + 273.16;
    *(double *)(v5 + 992) = v11[4];
    *(double *)(v5 + 1000) = v14 * v11[6];
    *(double *)(v5 + 1008) = v14 * v11[7];
    *(double *)(v5 + 1016) = (((double)*(int *)(a2 + 4996) * *(double *)(a2 + 4984) + *(double *)(a2 + 4976)) * v11[9]
                            + v11[8])
                           * v14;
    v15 = (double)*(int *)(v3 + 460) * *(double *)(v3 + 448) + *(double *)(v3 + 440);
    *(double *)(v5 + 1024) = v15;
    *(double *)(v5 + 1056) = v15;
    *(double *)(v5 + 1040) = v11[11] / (*(double *)(v5 + 992) * *(double *)(v5 + 992) * *(double *)(v5 + 992));
    v16 = sub_51C800(&dword_BE08A0);
    *(double *)(v5 + 1048) = v16 * *(double *)(HIDWORD(v130) + 104) + *(double *)(HIDWORD(v130) + 96);
    *(double *)((char *)&v133 + 4) = *(double *)(v5 + 1024) * 0.99;
    v17 = *(double *)(v5 + 1024) * 0.01;
    if ( v17 <= *(double *)(v5 + 1048) )
    {
      if ( *(double *)(v5 + 1048) <= *(double *)((char *)&v133 + 4) )
        goto LABEL_8;
      v17 = *(double *)((char *)&v133 + 4);
    }
    *(double *)(v5 + 1048) = v17;
LABEL_8:
    v18 = *(double *)(HIDWORD(v130) + 80);
    v19 = *(_DWORD *)(v5 + 168);
    *(double *)(v5 + 1032) = v18;
    v20 = v18 * *(double *)(v5 + 1024);
    *(_QWORD *)&v129[8] = *(_QWORD *)(v19 + 192);
    *(_QWORD *)&v129[16] = *(_QWORD *)(v19 + 200);
    *(_DWORD *)&v129[24] = *(_DWORD *)(v19 + 208);
    v21 = *(_DWORD *)(v19 + 212);
    *(double *)&v129[8] = v20 + *(double *)(v5 + 24);
    LODWORD(v130) = v21;
    sub_619170(&v129[8]);
    v22 = *(double *)(v5 + 1032) * *(double *)(v5 + 1024);
    v23 = HIDWORD(v130);
    v24 = *(_DWORD *)&v136[4];
    *(_DWORD *)(v5 + 456) = 0;
    v25 = v22 + *(double *)(v5 + 24);
    v5 += 1280;
    v3 += 704;
    --v24;
    HIDWORD(v130) = v23 + 256;
    *(_DWORD *)&v136[4] = v24;
    *(double *)(v5 - 1248) = 1.0 / v25;
    *(double *)(v5 - 816) = 1.0;
    *(double *)(v5 - 808) = 0.0;
    *(double *)(v5 - 456) = (double)*(int *)(v3 - 756) * *(double *)(v3 - 768) + *(double *)(v3 - 776);
  }
  while ( v24 );
  v26 = sub_560950(&dword_FAE908, a3 + 136);
  *(_DWORD *)(this + 5896) = v26;
  if ( !v26
    && dword_B640C0 != 5
    && (unsigned __int8)sub_5612D0((int)byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\hdvehicle.cpp", 4262) )
  {
    sub_561210((int)byte_FAE910, "*.hdc file references unknown tire compound \"%s\"", a3 - 120);
  }
  *(_DWORD *)(this + 5900) = *(_DWORD *)(a2 + 3012);
  *(_DWORD *)(this + 5904) = *(_DWORD *)(a2 + 3076);
  LODWORD(v130) = 0;
  do
  {
    sub_4427C0(this, SLODWORD(v130), LODWORD(v130));
    ++LODWORD(v130);
  }
  while ( SLODWORD(v130) < 4 );
  if ( *(_BYTE *)(a3 + 1537) )
    v27 = 0.5 / *(double *)(a3 + 6096) + 0.5 / *(double *)DWORD2(v133);
  else
    v27 = 1.0;
  *((double *)&v133 + 1) = v27;
  *(double *)v136 = v27 * *(double *)(a3 + 1504);
  v141 = v27 * *(double *)(a3 + 1512);
  v28 = (double)*(int *)(a2 + 3396) * *(double *)(a2 + 3384) + *(double *)(a2 + 3376);
  sub_585FD0(v28);
  *(double *)(this + 5864) = v28 * *(double *)v136 * 0.5;
  if ( *(_BYTE *)(a3 + 1537) )
    v29 = 0.5 / *(double *)(a3 + 6608) + 0.5 / *(double *)(a3 + 6352);
  else
    v29 = 1.0;
  *(double *)&v133 = v29;
  v130 = v29 * *(double *)(a3 + 1504);
  v142 = v29 * *(double *)(a3 + 1512);
  v30 = (double)*(int *)(a2 + 3460) * *(double *)(a2 + 3448) + *(double *)(a2 + 3440);
  sub_586030(v30);
  *(double *)(this + 5872) = v30 * v130 * 0.5;
  sub_439540(
    (double *)(this + 5912),
    *((long double *)&v133 + 1),
    *(double *)v136,
    v141,
    (double *)(a3 + 1632),
    (double)*(int *)(a2 + 4100) * *(double *)(a2 + 4088) + *(double *)(a2 + 4080),
    (double)*(int *)(a2 + 4036) * *(double *)(a2 + 4024) + *(double *)(a2 + 4016),
    (double)*(int *)(a2 + 4228) * *(double *)(a2 + 4216) + *(double *)(a2 + 4208),
    (double)*(int *)(a2 + 4164) * *(double *)(a2 + 4152) + *(double *)(a2 + 4144),
    (double)*(int *)(a2 + 4356) * *(double *)(a2 + 4344) + *(double *)(a2 + 4336),
    (double)*(int *)(a2 + 4292) * *(double *)(a2 + 4280) + *(double *)(a2 + 4272),
    ((double)*(int *)(a2 + 324) * *(double *)(a2 + 312)
   + *(double *)(a2 + 304)
   + (double)*(int *)(a2 + 1028) * *(double *)(a2 + 1016)
   + *(double *)(a2 + 1008))
  * 0.5,
    (*(double *)(a3 + 6104) + *(double *)(a3 + 5848)) * 0.5);
  v31 = (double *)(a3 + 1696);
  v32 = sub_439540(
          (double *)(this + 6032),
          *(long double *)&v133,
          v130,
          v142,
          v31,
          (double)*(int *)(a2 + 4484) * *(double *)(a2 + 4472) + *(double *)(a2 + 4464),
          (double)*(int *)(a2 + 4420) * *(double *)(a2 + 4408) + *(double *)(a2 + 4400),
          (double)*(int *)(a2 + 4612) * *(double *)(a2 + 4600) + *(double *)(a2 + 4592),
          (double)*(int *)(a2 + 4548) * *(double *)(a2 + 4536) + *(double *)(a2 + 4528),
          (double)*(int *)(a2 + 4740) * *(double *)(a2 + 4728) + *(double *)(a2 + 4720),
          (double)*(int *)(a2 + 4676) * *(double *)(a2 + 4664) + *(double *)(a2 + 4656),
          ((double)*(int *)(a2 + 1732) * *(double *)(a2 + 1720)
         + *(double *)(a2 + 1712)
         + (double)*(int *)(a2 + 2436) * *(double *)(a2 + 2424)
         + *(double *)(a2 + 2416))
        * 0.5,
          (v31[615] + v31[583]) * 0.5);
  v34 = v33 || v32;
  *(_BYTE *)(this + 5908) = v34;
  *(_BYTE *)(this + 144) = byte_B6F118 == 0;
  *(double *)(this + 6152) = (double)*(int *)(a2 + 5188) * *(double *)(a2 + 5176) + *(double *)(a2 + 5168);
  *(double *)(this + 6160) = (double)*(int *)(a2 + 5124) * *(double *)(a2 + 5112) + *(double *)(a2 + 5104);
  qmemcpy((void *)(this + 6176), (const void *)(a2 + 5040), 0x40u);
  *(_BYTE *)(this + 6240) = *(_BYTE *)(a3 + 1816);
  v35 = (double *)(*(_DWORD *)(this + 2344) + 8);
  v36 = (double)*(int *)(this + 6196) * *(double *)(this + 6184) + *(double *)(this + 6176);
  v37 = *(double **)(this + 1064);
  *(_DWORD *)(this + 232) = 1;
  *(double *)(this + 6168) = v36;
  ++v37;
  *(double *)(this + 6424) = *(double *)(a3 + 1760);
  *(double *)(this + 6432) = 0.0;
  *(double *)&v131 = *v35 + *v37;
  *((double *)&v131 + 1) = v37[1] + v35[1];
  v38 = v37[2] + v35[2];
  v134 = v131;
  *(double *)&v131 = *(double *)&v131 * 0.5;
  v135 = v38;
  *((double *)&v131 + 1) = *((double *)&v131 + 1) * 0.5;
  *(double *)&v136[32] = *(double *)&v134 * 0.5;
  *(double *)&v136[40] = *((double *)&v134 + 1) * 0.5;
  v132 = v38 * 0.5;
  *(double *)&v136[40] = -*(double *)(a3 + 96);
  v39 = *(double **)(this + 4904);
  *(double *)&v136[48] = v132;
  v40 = *(_DWORD *)(this + 3624);
  v41 = *(double *)(v40 + 8) + *++v39;
  v40 += 8;
  *(double *)&v131 = v41;
  *((double *)&v131 + 1) = v39[1] + *(double *)(v40 + 8);
  v42 = v39[2] + *(double *)(v40 + 16);
  *(_QWORD *)&v134 = v131;
  *(double *)&v136[8] = *(double *)&v131 * 0.5;
  *(double *)&v136[16] = *(double *)&v136[40];
  *(double *)&v136[24] = v42 * 0.5;
  *(double *)&v131 = *(double *)&v131 * 0.5 + *(double *)&v136[32];
  *(double *)&v129[4] = *(double *)&v134 * 0.5 + *(double *)&v136[32];
  *((double *)&v131 + 1) = *(double *)&v136[40] + *(double *)&v136[40];
  *(double *)&v129[12] = *((double *)&v131 + 1);
  v132 = v42 * 0.5 + v132;
  *(double *)&v129[20] = v42 * 0.5 + v38 * 0.5;
  *(double *)&v134 = *(double *)&v129[4] * 0.5;
  *((double *)&v134 + 1) = *((double *)&v131 + 1) * 0.5;
  v139 = v134;
  v135 = v132 * 0.5;
  v140 = v135;
  v43 = 0;
  LODWORD(v133) = a2 + 312;
  LODWORD(v130) = 0;
  v44 = this + 6904;
  *(_DWORD *)v136 = this + 6456;
  v45 = a3 + 5400;
  do
  {
    v46 = *(_BYTE *)(a3 + 5376) == 0;
    v131 = v134;
    v132 = v135;
    if ( !v46 )
    {
      if ( (unsigned int)v43 > 1 )
      {
        if ( v43 == 2 || v43 == 3 )
          v47 = (double *)&v136[8];
        else
          v47 = (double *)&v139;
      }
      else
      {
        v47 = (double *)&v136[32];
      }
      v131 = *(_OWORD *)v47;
      v132 = v47[2];
    }
    v48 = *(double *)&v131 + *(double *)(v45 - 16);
    v49 = *(_DWORD *)v136 - 8;
    v44 += 8;
    v45 += 24;
    *(double *)&v129[4] = v48;
    *(double *)&v129[12] = *((double *)&v131 + 1) + *(double *)(v45 - 32);
    v50 = v132 + *(double *)(v45 - 24);
    *(_QWORD *)v49 = *(_QWORD *)&v129[4];
    *(double *)&v129[20] = v50;
    *(_DWORD *)(v49 + 8) = *(_DWORD *)&v129[12];
    *(_DWORD *)(v49 + 12) = *(_DWORD *)&v129[16];
    *(_QWORD *)(v49 + 16) = *(_QWORD *)&v129[20];
    v51 = v133;
    v52 = LODWORD(v130);
    *(double *)(v44 - 152) = **(double **)v136;
    v53 = (double)*(int *)(v51 + 12);
    v51 += 704;
    LODWORD(v130) = v52 + 1;
    v54 = v53 * *(double *)(v51 - 704);
    LODWORD(v133) = v51;
    v55 = *(_DWORD *)v136 + 24;
    v56 = v54 + *(double *)(v51 - 712);
    v43 = LODWORD(v130);
    *(double *)(v44 - 8) = v56;
    *(double *)(v44 + 120) = v56;
    *(_DWORD *)v136 = v55;
  }
  while ( v43 < 12 );
  *(long double *)(this + 6736) = -fabs(*(double *)(a3 + 5672));
  *(long double *)(this + 6744) = -fabs(*(double *)(a3 + 5680));
  v57 = *(double *)(a3 + 5688);
  *(_BYTE *)(this + 7008) = 0;
  *(long double *)(this + 6752) = fabs(v57);
  *(long double *)(this + 7000) = fabs(*(double *)(this + 6464) - *(double *)(this + 6512));
  *(double *)(this + 7016) = 0.0;
  *(double *)(this + 360) = *(double *)(a3 + 1768);
  *(double *)(this + 368) = *(double *)(a3 + 1776);
  *(double *)(this + 376) = *(double *)(a3 + 1784);
  *(double *)(this + 384) = *(double *)(a3 + 1792);
  *(double *)(this + 392) = *(double *)(a3 + 1800);
  if ( *(double *)(this + 392) < 0.0 )
  {
    v58 = 0.0;
    goto LABEL_39;
  }
  if ( *(double *)(this + 392) > 1.0 )
  {
    v58 = 1.0;
LABEL_39:
    *(double *)(this + 392) = v58;
  }
  *(double *)(this + 400) = *(double *)(a3 + 1808);
  if ( *(double *)(this + 400) < 0.0 )
  {
    v59 = 0.0;
    goto LABEL_44;
  }
  if ( *(double *)(this + 400) > 1.0 )
  {
    v59 = 1.0;
LABEL_44:
    *(double *)(this + 400) = v59;
  }
  *(double *)(this + 408) = 0.0;
  *(_BYTE *)(this + 416) = *(_BYTE *)(a3 + 1817);
  *(double *)(this + 424) = *(double *)(a3 + 1824);
  *(double *)(this + 432) = *(double *)(a3 + 1832);
  *(double *)(this + 440) = *(double *)(a3 + 1840);
  if ( *(double *)(this + 440) < 0.0 )
  {
    v60 = 0.0;
    goto LABEL_49;
  }
  if ( *(double *)(this + 440) > 1.0 )
  {
    v60 = 1.0;
LABEL_49:
    *(double *)(this + 440) = v60;
  }
  *(double *)(this + 448) = *(double *)(a3 + 1848);
  if ( *(double *)(this + 448) < 0.0 )
  {
    v61 = 0.0;
    goto LABEL_54;
  }
  if ( *(double *)(this + 448) > 1.0 )
  {
    v61 = 1.0;
LABEL_54:
    *(double *)(this + 448) = v61;
  }
  *(double *)(this + 456) = (double)*(int *)(a2 + 3332) * *(double *)(a2 + 3320) + *(double *)(a2 + 3312);
  DWORD2(v133) = *(_DWORD *)(a2 + 3328) - 1;
  *(double *)(this + 464) = (double)SDWORD2(v133) * *(double *)(a2 + 3320) + *(double *)(a2 + 3312);
  *(double *)(this + 472) = *(double *)(a3 + 1856);
  *(double *)(this + 480) = flt_BE27A8 * (double)dword_B72E08 * *(double *)(this + 136);
  *(double *)&v129[4] = *(double *)&v136[8] + *(double *)(a3 + 200);
  v62 = *(_DWORD *)&v129[8];
  *(double *)&v129[12] = *(double *)&v136[16] + *(double *)(a3 + 208);
  v63 = *(double *)&v136[24] + *(double *)(a3 + 216);
  *(_DWORD *)(this + 488) = *(_DWORD *)&v129[4];
  v64 = *(_DWORD *)&v129[12];
  *(_DWORD *)(this + 492) = v62;
  v65 = *(_DWORD *)&v129[16];
  *(double *)&v129[20] = v63;
  v66 = *(double *)(this + 456);
  *(_DWORD *)(this + 496) = v64;
  v67 = *(_DWORD *)&v129[20];
  *(_DWORD *)(this + 500) = v65;
  v68 = *(_DWORD *)&v129[24];
  *(_DWORD *)(this + 504) = v67;
  v69 = *(_DWORD *)(this + 512);
  *(_DWORD *)(this + 508) = v68;
  v70 = v66 * 0.74 + 1.0;
  *(double *)&v137 = 0.0;
  *((double *)&v137 + 1) = 0.0;
  v138 = 0.0;
  *(double *)(v69 + 176) = v70;
  *(double *)(v69 + 184) = 1.0 / v70;
  v71 = *(_DWORD *)(this + 512) + 8;
  *(_OWORD *)v71 = v137;
  *(double *)(v71 + 16) = v138;
  sub_61B6E0(&v137);
  v72 = *(_DWORD *)(this + 512) + 104;
  *(_DWORD *)v72 = *(_DWORD *)&v136[52];
  *(_OWORD *)(v72 + 4) = v137;
  *(_DWORD *)(v72 + 20) = LODWORD(v138);
  sub_61B710(&v136[52]);
  *(double *)(this + 520) = *(double *)(a3 + 224);
  v73 = *(double *)(a3 + 232);
  *(_BYTE *)(this + 7024) = 0;
  *(double *)(this + 528) = v73 + v73;
  sub_441E40(this, a2, a3);
  *(double *)v129 = *(double *)&v136[28] + *(double *)(a3 + 408);
  *(double *)&v129[8] = *(double *)&v136[36] + *(double *)(a3 + 416);
  v74 = *(double *)&v136[44] + *(double *)(a3 + 424);
  *(_DWORD *)(this + 7480) = *(_DWORD *)v129;
  v75 = *(_DWORD *)&v129[8];
  *(_DWORD *)(this + 7484) = *(_DWORD *)&v129[4];
  v76 = *(_DWORD *)&v129[12];
  *(double *)&v129[16] = v74;
  v77 = *(double *)&v136[28];
  *(_DWORD *)(this + 7488) = v75;
  v78 = *(_DWORD *)&v129[16];
  *(_DWORD *)(this + 7492) = v76;
  v79 = *(_DWORD *)&v129[20];
  *(_DWORD *)(this + 7496) = v78;
  *(_DWORD *)(this + 7500) = v79;
  *(double *)v129 = v77 + *(double *)(a3 + 512);
  *(double *)&v129[8] = *(double *)&v136[36] + *(double *)(a3 + 520);
  v80 = *(double *)&v136[44] + *(double *)(a3 + 528);
  *(_DWORD *)(this + 7608) = *(_DWORD *)v129;
  v81 = *(_DWORD *)&v129[8];
  *(_DWORD *)(this + 7612) = *(_DWORD *)&v129[4];
  v82 = *(_DWORD *)&v129[12];
  *(double *)&v129[16] = v80;
  v83 = *(double *)&v136[28];
  *(_DWORD *)(this + 7616) = v81;
  v84 = *(_DWORD *)&v129[16];
  *(_DWORD *)(this + 7620) = v82;
  v85 = *(_DWORD *)&v129[20];
  *(_DWORD *)(this + 7624) = v84;
  *(_DWORD *)(this + 7628) = v85;
  *(double *)v129 = v83 + *(double *)(a3 + 800);
  *(double *)&v129[8] = *(double *)&v136[36] + *(double *)(a3 + 808);
  *(double *)&v129[16] = *(double *)&v136[44] + *(double *)(a3 + 816);
  v86 = *(double *)&v136[4];
  *(_QWORD *)(this + 7728) = *(_QWORD *)v129;
  *(_QWORD *)(this + 7736) = *(_QWORD *)&v129[8];
  *(_QWORD *)(this + 7744) = *(_QWORD *)&v129[16];
  *(double *)v129 = v86 + *(double *)(a3 + 1072);
  *(double *)&v129[8] = *(double *)&v136[12] + *(double *)(a3 + 1080);
  v87 = *(double *)&v136[20] + *(double *)(a3 + 1088);
  *(_DWORD *)(this + 7968) = *(_DWORD *)v129;
  v88 = *(_DWORD *)&v129[8];
  *(_DWORD *)(this + 7972) = *(_DWORD *)&v129[4];
  v89 = *(_DWORD *)&v129[12];
  *(double *)&v129[16] = v87;
  *(_DWORD *)(this + 7976) = v88;
  v90 = *(double *)&v136[4];
  v91 = *(_DWORD *)&v129[16];
  *(_DWORD *)(this + 7980) = v89;
  v92 = *(_DWORD *)&v129[20];
  *(_DWORD *)(this + 7984) = v91;
  *(_DWORD *)(this + 7988) = v92;
  *(double *)v129 = v90 + *(double *)(a3 + 1128);
  *(double *)&v129[8] = *(double *)&v136[12] + *(double *)(a3 + 1136);
  v93 = *(double *)&v136[20] + *(double *)(a3 + 1144);
  *(_DWORD *)(this + 0x2000) = *(_DWORD *)v129;
  v94 = *(_DWORD *)&v129[8];
  *(_DWORD *)(this + 8196) = *(_DWORD *)&v129[4];
  v95 = *(_DWORD *)&v129[12];
  *(double *)&v129[16] = v93;
  v96 = *(double *)&v136[4];
  *(_DWORD *)(this + 8200) = v94;
  v97 = *(_DWORD *)&v129[16];
  *(_DWORD *)(this + 8204) = v95;
  v98 = *(_DWORD *)&v129[20];
  *(_DWORD *)(this + 8208) = v97;
  *(_DWORD *)(this + 8212) = v98;
  *(double *)v129 = v96 + *(double *)(a3 + 1448);
  *(double *)&v129[8] = *(double *)&v136[12] + *(double *)(a3 + 1456);
  v99 = *(double *)&v136[20] + *(double *)(a3 + 1464);
  *(_DWORD *)(this + 8536) = *(_DWORD *)v129;
  v100 = *(_DWORD *)&v129[8];
  *(_DWORD *)(this + 8540) = *(_DWORD *)&v129[4];
  v101 = *(_DWORD *)&v129[12];
  *(double *)&v129[16] = v99;
  *(_DWORD *)(this + 8544) = v100;
  v102 = *(_DWORD *)&v129[16];
  *(_DWORD *)(this + 8548) = v101;
  v103 = *(_DWORD *)&v129[20];
  *(_DWORD *)(this + 8552) = v102;
  *(_DWORD *)(this + 8556) = v103;
  *(double *)(this + 8640) = ((double)*(int *)(a2 + 5700) * *(double *)(a2 + 5688) + *(double *)(a2 + 5680))
                           * 0.09549296585513721;
  *(_BYTE *)(this + 8648) = *(_BYTE *)(a3 + 5184);
  *(double *)(this + 8840) = 0.0;
  *(_BYTE *)(this + 8649) = 0;
  *(_BYTE *)(this + 8650) = 0;
  *(double *)(this + 8656) = 0.0;
  *(double *)(this + 8664) = 0.0;
  v104 = *(double *)(a3 + 1872);
  *(double *)(this + 8672) = v104;
  *(double *)(this + 8680) = 1.0 / v104;
  *(double *)(this + 8688) = *(double *)(a3 + 1896);
  *(double *)(this + 8696) = *(double *)(a3 + 1880);
  *(double *)(this + 8704) = *(double *)(a3 + 1888);
  v105 = (double)*(int *)(a2 + 5572) * *(double *)(a2 + 5560) + *(double *)(a2 + 5552);
  *(double *)(this + 8784) = v105;
  v106 = v105;
  v107 = *(double *)(a3 + 1928) * 0.5;
  *(double *)(this + 8800) = v106 + v107;
  *(double *)(this + 8792) = *(double *)(this + 8784) - v107;
  *(double *)(this + 8712) = *(double *)(a3 + 5336) * *(double *)(this + 8784);
  if ( *(double *)(a3 + 5344) > 0.0 )
    *(double *)(this + 8712) = (double)*(int *)(a2 + 5572) * *(double *)(a2 + 5560)
                             + *(double *)(a2 + 5552)
                             - *(double *)(a2 + 5552)
                             + *(double *)(a3 + 5344);
  v108 = *(_DWORD *)(a3 + 1940);
  if ( v108 <= 0 )
    v109 = 0.0;
  else
    v109 = *(double *)(a3 + 8 * (3 * v108 + 240));
  v110 = v109 + v109;
  *(double *)(this + 8808) = v110;
  v111 = (unsigned __int64)(v110 * -0.03125);
  *(_DWORD *)(this + 8828) = 2 - v111;
  *(_DWORD *)(this + 8816) = operator new(8 * (2 - v111));
  v112 = *(_DWORD *)(this + 8828);
  v113 = 0;
  *(_DWORD *)&v129[24] = 0;
  if ( v112 > 0 )
  {
    do
    {
      sub_585E70(
        a3,
        COERCE_UNSIGNED_INT64((double)*(int *)&v129[24] * 32.0),
        HIDWORD(COERCE_UNSIGNED_INT64((double)*(int *)&v129[24] * 32.0)));
      *(float *)(*(_DWORD *)(this + 8816) + 8 * v113) = *(double *)((char *)&v137 + 4);
      v114 = *(_DWORD *)(this + 8816);
      *(_DWORD *)&v129[8] = ++v113;
      *(float *)(v114 + 8 * v113 - 4) = *(double *)((char *)&v139 + 4) - *(double *)((char *)&v137 + 4);
    }
    while ( v113 < *(_DWORD *)(this + 8828) );
  }
  *(double *)(this + 8912) = *(double *)(a3 + 5016);
  *(double *)(this + 8920) = *(double *)(a3 + 5024);
  *(double *)(this + 8928) = *(double *)(a3 + 5032);
  *(double *)(this + 8936) = *(double *)(a3 + 5040);
  *(double *)(this + 8952) = *(double *)(a3 + 5048);
  *(double *)(this + 8960) = *(double *)(a3 + 5056);
  *(double *)(this + 8976) = *(double *)(a3 + 5064);
  *(double *)(this + 8904) = (flt_FB1F2C + 273.16 + *(double *)(this + 8912)) * 0.5;
  *(double *)(this + 8944) = 0.0;
  *(double *)(this + 8968) = flt_FB1F2C + 273.16;
  *(double *)(this + 8992) = 0.0;
  v115 = sub_51C800(&dword_BE08A0) * *(double *)(a3 + 5128) + *(double *)(a3 + 5120);
  *(double *)(this + 9008) = v115;
  if ( v115 <= 0.0 )
    *(double *)(this + 9008) = *(double *)(a3 + 5120);
  if ( !dword_B6FD6C )
  {
    *(double *)(this + 9008) = 1.797693134862316e308;
    *(double *)(this + 1936) = 0.0;
    *(double *)(this + 3216) = 0.0;
    *(double *)(this + 4496) = 0.0;
    v116 = 0.0;
    goto LABEL_70;
  }
  if ( dword_B6FD6C == 2 )
  {
    if ( *(_DWORD *)dword_B640C8 == 6 )
      *(double *)(this + 9008) = *(double *)(this + 9008) / flt_FADE28;
    *(double *)(this + 1936) = flt_FADE28 * *(double *)(this + 1936);
    *(double *)(this + 3216) = flt_FADE28 * *(double *)(this + 3216);
    *(double *)(this + 4496) = flt_FADE28 * *(double *)(this + 4496);
    v116 = flt_FADE28 * *(double *)(this + 5776);
LABEL_70:
    *(double *)(this + 5776) = v116;
  }
  *(double *)(this + 9000) = 0.0;
  *(double *)(this + 9016) = *(double *)(a3 + 5088);
  *(double *)(this + 9024) = 1.0 / *(double *)(a3 + 5096);
  *(double *)(this + 9032) = *(double *)(a3 + 5104);
  v117 = 1.0 / *(double *)(a3 + 5112);
  *(double *)(this + 9040) = v117;
  *(double *)(this + 9048) = 3.0 / v117 + *(double *)(this + 9032);
  *(double *)(this + 9056) = 0.0;
  *(double *)(this + 9064) = 0.0;
  *(double *)(this + 9072) = 0.0;
  *(_BYTE *)(this + 8832) = *(_BYTE *)(a3 + 5185);
  *(double *)(this + 8848) = *(double *)(a3 + 5192);
  *(double *)(this + 8856) = *(double *)(a3 + 5200);
  *(double *)(this + 8864) = *(double *)(a3 + 5208);
  *(_DWORD *)(this + 8872) = 0;
  *(double *)(this + 8880) = *(double *)(a3 + 1904);
  *(double *)(this + 8888) = *(double *)(a3 + 1912);
  *(double *)(this + 8896) = *(double *)(a3 + 1920);
  *(_DWORD *)(this + 9104) = *(_DWORD *)(a3 + 5320);
  *(double *)(this + 9112) = ((double)*(int *)(a2 + 5316) * *(double *)(a2 + 5304) + *(double *)(a2 + 5296))
                           * *(double *)(a3 + 5328);
  *(double *)(this + 9120) = (double)*(int *)(a2 + 5380) * *(double *)(a2 + 5368) + *(double *)(a2 + 5360);
  *(double *)(this + 9128) = (double)*(int *)(a2 + 5444) * *(double *)(a2 + 5432) + *(double *)(a2 + 5424);
  *(double *)(this + 9136) = (double)*(int *)(a2 + 5508) * *(double *)(a2 + 5496) + *(double *)(a2 + 5488);
  *(double *)(this + 9144) = 0.0;
  *(double *)(this + 9152) = 0.0;
  v118 = *(double *)(a3 + 5224);
  *(double *)(this + 9160) = v118;
  *(double *)(this + 9168) = 1.0 / v118;
  *(double *)(this + 9176) = *(double *)(a3 + 5232);
  *(double *)(this + 9184) = *(double *)(a3 + 5240);
  *(double *)(this + 9192) = *(double *)(a3 + 5248);
  *(double *)(this + 9200) = *(double *)(a3 + 5216) * *(double *)(this + 136);
  *(double *)(this + 9208) = *(double *)(a3 + 5256);
  *(_BYTE *)(this + 145) = *(_BYTE *)(a3 + 5264);
  *(_BYTE *)(this + 9216) = *(_BYTE *)(a3 + 5265);
  *(double *)(this + 9232) = *(double *)(a3 + 5272);
  *(double *)(this + 9240) = -*(double *)(a3 + 5280);
  *(double *)(this + 9248) = *(double *)(a3 + 5288);
  if ( *(double *)(this + 9248) < 0.0 )
  {
    v119 = 0.0;
    goto LABEL_75;
  }
  if ( *(double *)(this + 9248) > 1.0 )
  {
    v119 = 1.0;
LABEL_75:
    *(double *)(this + 9248) = v119;
  }
  *(double *)(this + 9256) = *(double *)(a3 + 5296);
  *(double *)(this + 9264) = -*(double *)(a3 + 5304);
  *(double *)(this + 9272) = *(double *)(a3 + 5312);
  if ( *(double *)(this + 9272) < 0.0 )
  {
    v120 = 0.0;
    goto LABEL_80;
  }
  v120 = *(double *)(this + 9272);
  if ( v120 > 1.0 )
  {
    v120 = 1.0;
LABEL_80:
    *(double *)(this + 9272) = v120;
  }
  v121 = *(_DWORD *)(a3 + 5324);
  *(_DWORD *)(this + 9304) = v121;
  *(_DWORD *)&v129[8] = 0;
  if ( v121 >= 0 )
  {
    DWORD1(v131) = this + 9312;
    do
    {
      sub_4318C0();
      v122 = v131;
      *(double *)v131 = v120;
      LODWORD(v131) = v122 + 8;
      ++*(_DWORD *)&v129[4];
    }
    while ( *(int *)&v129[4] <= *(_DWORD *)(this + 9304) );
  }
  sub_4318F0((int *)a2);
  *(double *)(this + 9288) = v120;
  if ( v120 == 0.0 )
    v123 = 0.0;
  else
    v123 = 1.0 / *(double *)(this + 9288);
  *(double *)(this + 9296) = v123;
  v124 = 2;
  *(double *)&v131 = *(double *)(this + 8 * *(_DWORD *)(this + 9304) + 9304) - *(double *)(this + 9320);
  *((double *)&v131 + 1) = *(double *)(this + 8704);
  *(double *)(this + 8720) = *((double *)&v131 + 1);
  *(double *)(this + 8728) = *((double *)&v131 + 1);
  if ( *(int *)(this + 9304) >= 2 )
  {
    v125 = (double *)(this + 9320);
    do
    {
      if ( *(double *)&v131 == 0.0 )
        v126 = 1.0;
      else
        v126 = (*v125 - *(double *)(this + 9320)) / *(double *)&v131;
      v127 = v125[1]
           / *v125
           * *(double *)(this + 8712)
           * ((*(double *)(a3 + 5352) - *(double *)(a3 + 5360)) * v126 + *(double *)(a3 + 5360));
      if ( v127 < *((double *)&v131 + 1) )
        v127 = *((double *)&v131 + 1);
      *(v125 - 73) = v127;
      ++v124;
      ++v125;
    }
    while ( v124 <= *(_DWORD *)(this + 9304) );
  }
  result = 0;
  *(_DWORD *)(this + 9384) = 0;
  *(_DWORD *)(this + 9376) = 0;
  *(_DWORD *)(this + 9380) = 0;
  *(_DWORD *)(this + 9388) = 0;
  *(_DWORD *)(this + 48) = -2;
  *(_DWORD *)(this + 52) = 3;
  *(double *)(this + 56) = 0.0;
  *(double *)(this + 9400) = 0.0;
  *(double *)(this + 9408) = 0.0;
  *(double *)(this + 9416) = 0.0;
  *(double *)(this + 9424) = 0.0;
  *(double *)(this + 9432) = 0.0;
  *(double *)(this + 9440) = 0.0;
  *(_DWORD *)(this + 200) = 0;
  *(double *)(this + 208) = 0.0;
  *(double *)(this + 216) = 0.0;
  *(double *)(this + 224) = 0.0;
  *(double *)(this + 264) = 0.0;
  *(double *)(this + 272) = 0.0;
  *(double *)(this + 280) = 0.0;
  *(double *)(this + 288) = 0.0;
  *(double *)(this + 296) = 0.0;
  *(double *)(this + 304) = 0.0;
  *(_DWORD *)(this + 312) = 0;
  *(double *)(this + 320) = 0.0;
  *(double *)(this + 328) = 0.0;
  *(double *)(this + 336) = 0.0;
  *(double *)(this + 344) = 0.0;
  return result;
}
