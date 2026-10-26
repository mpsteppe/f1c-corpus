int __thiscall sub_4F7480(_DWORD *this, int a2)
{
  int v3; // eax
  float v4; // ecx
  _DWORD *v5; // eax
  int v6; // ecx
  _DWORD *v7; // eax
  int v8; // ecx
  int v9; // eax
  float v10; // ecx
  int v11; // eax
  int v12; // esi
  int v13; // esi
  double v14; // st7
  double v15; // st6
  float *v16; // eax
  double v17; // st7
  long double v18; // st5
  long double v19; // st7
  double v20; // st6
  double v21; // st7
  double v22; // st7
  double v23; // st6
  float *v24; // eax
  int v25; // eax
  int v26; // ecx
  double v27; // st7
  int v28; // eax
  int v29; // eax
  float v30; // ecx
  double v31; // rtt
  double v32; // st7
  double v33; // st6
  float *v34; // eax
  double v35; // st7
  double v36; // st6
  double v37; // st7
  double v38; // st6
  double v39; // rtt
  double v40; // st7
  double v41; // st6
  float *v42; // eax
  int v43; // eax
  int v44; // eax
  int v45; // eax
  double v46; // st7
  double v47; // st6
  float v48; // eax
  int v49; // eax
  float v51; // [esp+Ch] [ebp-170h]
  float v52; // [esp+Ch] [ebp-170h]
  float v53; // [esp+Ch] [ebp-170h]
  float v54; // [esp+Ch] [ebp-170h]
  float v55; // [esp+Ch] [ebp-170h]
  float v56; // [esp+Ch] [ebp-170h]
  float v57; // [esp+Ch] [ebp-170h]
  float v58; // [esp+Ch] [ebp-170h]
  float v59; // [esp+Ch] [ebp-170h]
  float v60; // [esp+10h] [ebp-16Ch]
  float v61; // [esp+10h] [ebp-16Ch]
  float v62; // [esp+14h] [ebp-168h]
  float v63; // [esp+14h] [ebp-168h]
  float v64; // [esp+18h] [ebp-164h]
  float v65; // [esp+18h] [ebp-164h]
  float v66; // [esp+18h] [ebp-164h]
  float v67; // [esp+18h] [ebp-164h]
  float v68; // [esp+1Ch] [ebp-160h]
  float v69; // [esp+1Ch] [ebp-160h]
  float v70; // [esp+1Ch] [ebp-160h]
  float v71; // [esp+1Ch] [ebp-160h]
  float v72; // [esp+20h] [ebp-15Ch]
  float v73; // [esp+20h] [ebp-15Ch]
  float v74; // [esp+24h] [ebp-158h]
  float v75; // [esp+24h] [ebp-158h]
  float v76; // [esp+24h] [ebp-158h]
  float v77; // [esp+24h] [ebp-158h]
  float v78; // [esp+28h] [ebp-154h]
  float v79; // [esp+28h] [ebp-154h]
  float v80; // [esp+28h] [ebp-154h]
  float v81; // [esp+28h] [ebp-154h]
  float v82; // [esp+2Ch] [ebp-150h]
  float v83; // [esp+2Ch] [ebp-150h]
  float v84; // [esp+30h] [ebp-14Ch]
  float v85; // [esp+30h] [ebp-14Ch]
  float v86; // [esp+30h] [ebp-14Ch]
  float v87; // [esp+30h] [ebp-14Ch]
  float v88; // [esp+30h] [ebp-14Ch]
  float v89; // [esp+34h] [ebp-148h]
  float v90; // [esp+34h] [ebp-148h]
  float v91; // [esp+38h] [ebp-144h]
  float v92; // [esp+38h] [ebp-144h]
  float v93; // [esp+3Ch] [ebp-140h]
  float v94; // [esp+3Ch] [ebp-140h]
  float v95; // [esp+40h] [ebp-13Ch] BYREF
  float v96; // [esp+44h] [ebp-138h]
  float v97; // [esp+48h] [ebp-134h]
  float v98; // [esp+4Ch] [ebp-130h] BYREF
  float v99; // [esp+50h] [ebp-12Ch]
  float v100; // [esp+54h] [ebp-128h]
  int v101; // [esp+58h] [ebp-124h]
  float v102; // [esp+5Ch] [ebp-120h]
  float v103; // [esp+60h] [ebp-11Ch]
  float v104; // [esp+64h] [ebp-118h]
  int v105; // [esp+68h] [ebp-114h]
  float v106; // [esp+6Ch] [ebp-110h]
  float v107; // [esp+70h] [ebp-10Ch]
  float v108; // [esp+74h] [ebp-108h]
  int v109; // [esp+78h] [ebp-104h]
  float v110; // [esp+7Ch] [ebp-100h]
  float v111; // [esp+80h] [ebp-FCh]
  int v112; // [esp+84h] [ebp-F8h]
  int v113; // [esp+88h] [ebp-F4h]
  float v114; // [esp+8Ch] [ebp-F0h]
  float v115; // [esp+90h] [ebp-ECh]
  float v116; // [esp+94h] [ebp-E8h]
  float v117; // [esp+98h] [ebp-E4h] BYREF
  float v118; // [esp+9Ch] [ebp-E0h]
  float v119; // [esp+A0h] [ebp-DCh]
  int v120; // [esp+A4h] [ebp-D8h]
  int v121; // [esp+A8h] [ebp-D4h]
  int v122; // [esp+ACh] [ebp-D0h]
  _DWORD v123[3]; // [esp+B0h] [ebp-CCh] BYREF
  float v124[16]; // [esp+BCh] [ebp-C0h] BYREF
  _DWORD v125[16]; // [esp+FCh] [ebp-80h] BYREF
  float v126[16]; // [esp+13Ch] [ebp-40h] BYREF

  v3 = ((int (*)(void))sub_5C1530)();
  v4 = *(float *)(v3 + 116);
  v3 += 116;
  v114 = v4;
  v115 = *(float *)(v3 + 4);
  v116 = *(float *)(v3 + 8);
  v5 = (_DWORD *)sub_5C1540(this);
  v6 = v5[29];
  v5 += 29;
  v120 = v6;
  v121 = v5[1];
  v122 = v5[2];
  v7 = (_DWORD *)sub_5C1550(this);
  v8 = v7[29];
  v7 += 29;
  v123[0] = v8;
  v123[1] = v7[1];
  v123[2] = v7[2];
  qmemcpy(v124, (const void *)(sub_5C1550(this) + 68), sizeof(v124));
  v9 = sub_5C1560(this);
  v10 = *(float *)(v9 + 116);
  v9 += 116;
  v117 = v10;
  v118 = *(float *)(v9 + 4);
  v119 = *(float *)(v9 + 8);
  v11 = sub_5C1580(this);
  sub_5C18D0(v123, &v117, v11, &v95);
  v98 = 1.0;
  v99 = 0.0;
  v100 = 0.0;
  v101 = 0;
  v102 = 0.0;
  v103 = 1.0;
  v104 = 0.0;
  v105 = 0;
  v106 = 0.0;
  v107 = 0.0;
  v108 = 1.0;
  v109 = 0;
  v110 = 0.0;
  v111 = 0.0;
  v112 = 0;
  v113 = 1065353216;
  v12 = sub_5C1540(this);
  if ( sub_5C1530(this) == v12 || (v13 = sub_5C1550(this), sub_5C1540(this) == v13) )
  {
    v29 = sub_5C1540(this);
    v30 = *(float *)(v29 + 124);
    v31 = *(float *)(v29 + 120);
    v95 = *(float *)(v29 + 116);
    v96 = v31;
    v97 = v30;
  }
  else
  {
    v14 = v95 - v114;
    v15 = v96 - v115;
    v64 = v97 - v116;
    v51 = 1.0 / sqrt(v14 * v14 + v64 * v64 + v15 * v15);
    v60 = v14 * v51;
    v62 = v15 * v51;
    v65 = v64 * v51;
    v16 = (float *)sub_5C1530(this);
    v17 = v16[23];
    v16 += 21;
    v18 = sqrt(v17 * v17 + *v16 * *v16 + v16[1] * v16[1]);
    v52 = 1.0 / v18;
    v19 = 1.0 / v18 * *v16;
    *v16 = v19;
    v20 = v52 * v16[1];
    v16[1] = v20;
    v53 = v52 * v16[2];
    v16[2] = v53;
    v78 = v19;
    v68 = v62 * v53 - v20 * v65;
    v21 = v65 * v78 - v53 * v60;
    v74 = v20 * v60 - v62 * v78;
    v54 = 1.0 / sqrt(v68 * v68 + v74 * v74 + v21 * v21);
    v69 = v68 * v54;
    v72 = v21 * v54;
    v75 = v74 * v54;
    v22 = v72 * v65 - v75 * v62;
    v23 = v75 * v60 - v65 * v69;
    v84 = v62 * v69 - v72 * v60;
    v55 = 1.0 / sqrt(v22 * v22 + v84 * v84 + v23 * v23);
    v79 = v22 * v55;
    v82 = v23 * v55;
    v85 = v84 * v55;
    v24 = (float *)sub_5C1530(this);
    v89 = v24[63];
    v91 = v24[64];
    v93 = v24[65];
    v98 = v60;
    v99 = v62;
    v100 = v65;
    v102 = v79;
    v103 = v82;
    v104 = v85;
    v106 = v69;
    v107 = v72;
    v108 = v75;
    sub_4F12D0(&v98, v89, v91, v93);
    v25 = sub_5C1530(this);
    v26 = *(_DWORD *)(v25 + 124);
    v27 = *(float *)(v25 + 120);
    v110 = *(float *)(v25 + 116);
    v111 = v27;
    v112 = v26;
    v28 = sub_5C1530(this);
    sub_5C0560(v28, &v98);
  }
  qmemcpy(v126, (const void *)(sub_5C1540(this) + 68), sizeof(v126));
  sub_4F3F50(v126);
  v32 = v117 - v95;
  qmemcpy(v125, v126, sizeof(v125));
  v33 = v118 - v96;
  v66 = v119 - v97;
  v56 = 1.0 / sqrt(v32 * v32 + v66 * v66 + v33 * v33);
  v61 = v32 * v56;
  v63 = v33 * v56;
  v67 = v66 * v56;
  v34 = (float *)sub_5C1580(this);
  v35 = v67 * v34[1] - v63 * v34[2];
  v36 = v61 * v34[2] - v67 * *v34;
  v86 = v63 * *v34 - v61 * v34[1];
  v57 = 1.0 / sqrt(v35 * v35 + v86 * v86 + v36 * v36);
  v80 = v35 * v57;
  v37 = v36 * v57;
  v38 = v86 * v57;
  v70 = v63 * v38 - v37 * v67;
  v39 = v67 * v80 - v38 * v61;
  v76 = v37 * v61 - v63 * v80;
  v58 = 1.0 / sqrt(v70 * v70 + v76 * v76 + v39 * v39);
  v71 = v70 * v58;
  v73 = v39 * v58;
  v77 = v76 * v58;
  v40 = v73 * v67 - v77 * v63;
  v41 = v77 * v61 - v67 * v71;
  v87 = v63 * v71 - v73 * v61;
  v59 = 1.0 / sqrt(v40 * v40 + v87 * v87 + v41 * v41);
  v81 = v40 * v59;
  v83 = v41 * v59;
  v88 = v87 * v59;
  v42 = (float *)sub_5C1540(this);
  v90 = v42[63];
  v92 = v42[64];
  v94 = v42[65];
  v98 = v61;
  v99 = v63;
  v102 = v81;
  v100 = v67;
  v103 = v83;
  v106 = v71;
  v104 = v88;
  v107 = v73;
  v108 = v77;
  sub_4F12D0(&v98, v90, v92, v94);
  v110 = *(float *)&v125[12];
  v111 = *(float *)&v125[13];
  v112 = v125[14];
  v43 = sub_5C1540(this);
  sub_5C0560(v43, &v98);
  v44 = this[14];
  if ( v44 )
    sub_4F25A0(v124, *(float *)(v44 + 60));
  v45 = sub_5C1550(this);
  v46 = *(float *)(v45 + 116);
  v47 = *(float *)(v45 + 120);
  v48 = *(float *)(v45 + 124);
  v124[12] = v46;
  v124[14] = v48;
  v124[13] = v47;
  v49 = sub_5C1550(this);
  return sub_5C0560(v49, v124);
}
