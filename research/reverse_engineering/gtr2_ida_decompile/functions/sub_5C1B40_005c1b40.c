int __thiscall sub_5C1B40(int this, int a2)
{
  float *v3; // esi
  float *v4; // ebx
  float *v5; // ebp
  float v6; // ecx
  float v7; // edx
  float v8; // eax
  float v9; // ecx
  float v10; // edx
  float *v11; // eax
  float v12; // ecx
  float v13; // edx
  double v14; // st6
  double v15; // st7
  float v16; // ecx
  float v17; // eax
  double v18; // st7
  double v19; // st7
  double v20; // st6
  long double v21; // st2
  long double v22; // st5
  double v23; // st4
  double v24; // st5
  float *v25; // esi
  float v26; // ecx
  float v27; // edx
  double v28; // st5
  double v29; // st4
  double v30; // st7
  float v31; // edx
  double v32; // st6
  double v33; // st7
  float *v34; // ebx
  double v35; // st7
  double v36; // st7
  double v37; // st6
  long double v38; // st5
  long double v39; // st4
  long double v40; // st3
  long double v41; // st2
  long double v42; // st5
  float v43; // eax
  float v44; // edx
  long double v45; // st4
  double v46; // st5
  double v47; // st4
  float v49; // [esp+10h] [ebp-10Ch]
  float v50; // [esp+10h] [ebp-10Ch]
  float v51; // [esp+10h] [ebp-10Ch]
  float v52; // [esp+10h] [ebp-10Ch]
  float v53; // [esp+10h] [ebp-10Ch]
  float v54; // [esp+10h] [ebp-10Ch]
  float v55; // [esp+10h] [ebp-10Ch]
  float v56; // [esp+14h] [ebp-108h]
  float v57; // [esp+14h] [ebp-108h]
  float v58; // [esp+14h] [ebp-108h]
  float v59; // [esp+14h] [ebp-108h]
  float v60; // [esp+18h] [ebp-104h]
  float v61; // [esp+18h] [ebp-104h]
  float v62; // [esp+18h] [ebp-104h]
  float v63; // [esp+1Ch] [ebp-100h]
  float v64; // [esp+1Ch] [ebp-100h]
  float v65; // [esp+1Ch] [ebp-100h]
  int v66; // [esp+20h] [ebp-FCh] BYREF
  float v67; // [esp+24h] [ebp-F8h]
  float v68; // [esp+28h] [ebp-F4h]
  float v69; // [esp+2Ch] [ebp-F0h] BYREF
  float v70; // [esp+30h] [ebp-ECh]
  float v71; // [esp+34h] [ebp-E8h]
  float v72; // [esp+38h] [ebp-E4h] BYREF
  float v73; // [esp+3Ch] [ebp-E0h]
  float v74; // [esp+40h] [ebp-DCh]
  float v75; // [esp+44h] [ebp-D8h] BYREF
  float v76; // [esp+48h] [ebp-D4h]
  float v77; // [esp+4Ch] [ebp-D0h]
  float v78; // [esp+50h] [ebp-CCh] BYREF
  float v79; // [esp+54h] [ebp-C8h]
  float v80; // [esp+58h] [ebp-C4h]
  float v81; // [esp+5Ch] [ebp-C0h] BYREF
  float v82; // [esp+60h] [ebp-BCh]
  float v83; // [esp+64h] [ebp-B8h]
  int v84; // [esp+68h] [ebp-B4h]
  float v85; // [esp+6Ch] [ebp-B0h]
  float v86; // [esp+70h] [ebp-ACh]
  float v87; // [esp+74h] [ebp-A8h]
  int v88; // [esp+78h] [ebp-A4h]
  float v89; // [esp+7Ch] [ebp-A0h]
  float v90; // [esp+80h] [ebp-9Ch]
  float v91; // [esp+84h] [ebp-98h]
  int v92; // [esp+88h] [ebp-94h]
  float v93; // [esp+8Ch] [ebp-90h]
  float v94; // [esp+90h] [ebp-8Ch]
  float v95; // [esp+94h] [ebp-88h]
  int v96; // [esp+98h] [ebp-84h]
  float v97[16]; // [esp+9Ch] [ebp-80h] BYREF
  float v98[16]; // [esp+DCh] [ebp-40h] BYREF

  v3 = *(float **)(this + 36);
  v4 = *(float **)(this + 40);
  v5 = *(float **)(this + 44);
  v6 = v3[30];
  v7 = v3[31];
  v69 = v3[29];
  v66 = *((_DWORD *)v4 + 29);
  v8 = v5[29];
  v70 = v6;
  v9 = v4[30];
  v71 = v7;
  v10 = v4[31];
  v75 = v8;
  v11 = *(float **)(this + 48);
  v67 = v9;
  v12 = v5[30];
  v68 = v10;
  v13 = v5[31];
  v76 = v12;
  v77 = v13;
  if ( v11 )
  {
    v14 = v11[29];
    v15 = v11[30];
    v74 = v11[31];
    v78 = v14;
    v16 = v74;
    v79 = v15;
  }
  else
  {
    v17 = *(float *)(this + 16);
    v16 = *(float *)(this + 20);
    v78 = *(float *)(this + 12);
    v79 = v17;
  }
  v80 = v16;
  *(_BYTE *)(this + 52) = sub_5C18D0(&v69, (float *)&v66, &v75, &v78, (float *)(this + 24), &v72);
  v81 = 1.0;
  v82 = 0.0;
  v83 = 0.0;
  v84 = 0;
  v85 = 0.0;
  v86 = 1.0;
  v87 = 0.0;
  v88 = 0;
  v89 = 0.0;
  v90 = 0.0;
  v91 = 1.0;
  v92 = 0;
  v93 = 0.0;
  v94 = 0.0;
  v95 = 0.0;
  v96 = 1065353216;
  if ( v3 == v4 || v4 == v5 )
  {
    v32 = v4[29];
    v33 = v4[30];
    v71 = v4[31];
    v72 = v32;
    v74 = v71;
    v73 = v33;
  }
  else
  {
    v18 = v72 - v69;
    v67 = v73 - v70;
    v68 = v74 - v71;
    v49 = 1.0 / sqrt(v18 * v18 + v68 * v68 + v67 * v67);
    v19 = v18 * v49;
    v20 = v67 * v49;
    v68 = v68 * v49;
    v21 = sqrt(v3[21] * v3[21] + v3[22] * v3[22] + v3[23] * v3[23]);
    v50 = 1.0 / v21;
    v22 = 1.0 / v21 * v3[21];
    v3[21] = v22;
    v23 = v50 * v3[22];
    v3[22] = v23;
    v51 = v50 * v3[23];
    v3[23] = v51;
    v69 = v22;
    v56 = v51 * v20 - v23 * v68;
    v24 = v68 * v69 - v51 * v19;
    v63 = v23 * v19 - v20 * v69;
    v25 = *(float **)(this + 36);
    v26 = v25[64];
    v27 = v25[65];
    v75 = v25[63];
    v76 = v26;
    v77 = v27;
    v83 = v68;
    v52 = 1.0 / sqrt(v56 * v56 + v63 * v63 + v24 * v24);
    v57 = v56 * v52;
    v60 = v24 * v52;
    v64 = v63 * v52;
    v28 = v60 * v68 - v64 * v20;
    v29 = v64 * v19 - v68 * v57;
    v71 = v20 * v57 - v60 * v19;
    v53 = 1.0 / sqrt(v28 * v28 + v71 * v71 + v29 * v29);
    v69 = v28 * v53;
    v85 = v69;
    v89 = v57;
    v70 = v29 * v53;
    v86 = v70;
    v90 = v60;
    v71 = v71 * v53;
    v87 = v71;
    v81 = v19;
    v91 = v64;
    v82 = v20;
    sub_4F12D0(&v81, v75, v26, v27);
    v30 = v25[30];
    v31 = v25[31];
    v93 = v25[29];
    v71 = v31;
    v94 = v30;
    v95 = v31;
    sub_5C0560(v25, (int)&v81);
  }
  v34 = *(float **)(this + 40);
  qmemcpy(v98, v34 + 17, sizeof(v98));
  sub_4F3F50(v98);
  v35 = v78 - v72;
  qmemcpy(v97, v98, sizeof(v97));
  v67 = v79 - v73;
  v68 = v80 - v74;
  v54 = 1.0 / sqrt(v35 * v35 + v68 * v68 + v67 * v67);
  v36 = v35 * v54;
  v37 = v67 * v54;
  v68 = v68 * v54;
  v38 = 1.0 / sqrt(v97[4] * v97[4] + v97[5] * v97[5] + v97[6] * v97[6]);
  v39 = v97[4] * v38;
  v40 = v97[5] * v38;
  v41 = v97[6] * v38;
  v58 = v41 * v37 - v40 * v68;
  v61 = v39 * v68 - v41 * v36;
  v42 = v40 * v36 - v39 * v37;
  v43 = v34[63];
  v44 = v34[65];
  v76 = v34[64];
  v75 = v43;
  v77 = v44;
  v83 = v68;
  v45 = 1.0 / sqrt(v58 * v58 + v42 * v42 + v61 * v61);
  v59 = v58 * v45;
  v62 = v61 * v45;
  v65 = v42 * v45;
  v46 = v62 * v68 - v65 * v37;
  v47 = v65 * v36 - v68 * v59;
  v74 = v37 * v59 - v62 * v36;
  v55 = 1.0 / sqrt(v46 * v46 + v74 * v74 + v47 * v47);
  v72 = v46 * v55;
  v85 = v72;
  v89 = v59;
  v73 = v47 * v55;
  v86 = v73;
  v90 = v62;
  v74 = v74 * v55;
  v87 = v74;
  v81 = v36;
  v91 = v65;
  v82 = v37;
  sub_4F12D0(&v81, v43, v76, v44);
  v93 = v97[12];
  v94 = v97[13];
  v95 = v97[14];
  return sub_5C0560(v34, (int)&v81);
}
