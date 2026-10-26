int __userpurge sub_49F95E@<eax>(int a1@<ecx>, int a2@<ebp>, char a3@<dil>, int a4, int a5)
{
  int v5; // esi
  int v6; // edi
  float *v7; // eax
  float *v8; // ecx
  float *v9; // edx
  double v10; // st7
  double v11; // st7
  float *v12; // eax
  float *v13; // edx
  float *v14; // ebx
  int v15; // ecx
  double v16; // st7
  double v17; // st7
  float *v18; // eax
  int v19; // edx
  double v20; // st7
  double v21; // st6
  double v22; // st6
  float v23; // eax
  float *v24; // eax
  double v25; // st7
  double v26; // st6
  int v27; // ecx
  double v28; // st5
  double v29; // st7
  double v30; // st6
  double v31; // st5
  int v32; // edx
  double v33; // st7
  double v34; // st6
  double v35; // st5
  int v36; // ebx
  double v37; // st7
  double v38; // st6
  double v39; // st5
  int v40; // ebx
  double v41; // st7
  double v42; // st6
  double v43; // st5
  int v44; // ecx
  double v45; // st5
  double v46; // st7
  double v47; // st6
  double v48; // st5
  int v49; // ecx
  int v50; // eax
  float *v51; // eax
  double v52; // st7
  int v53; // eax
  int v54; // esi
  char v56; // [esp-Ch] [ebp-1A8h]
  float *v57; // [esp+4h] [ebp-198h]
  float *v58; // [esp+8h] [ebp-194h]
  float v59; // [esp+8h] [ebp-194h]
  float v61; // [esp+10h] [ebp-18Ch]
  float i; // [esp+18h] [ebp-184h]
  int v63; // [esp+1Ch] [ebp-180h]
  int v64; // [esp+20h] [ebp-17Ch]
  int v65; // [esp+24h] [ebp-178h]
  float v66; // [esp+28h] [ebp-174h]
  int v67; // [esp+2Ch] [ebp-170h]
  int v68; // [esp+30h] [ebp-16Ch]
  _DWORD v69[6]; // [esp+34h] [ebp-168h] BYREF
  double v70; // [esp+4Ch] [ebp-150h] BYREF
  double v71; // [esp+54h] [ebp-148h]
  double v72; // [esp+5Ch] [ebp-140h]
  double v73; // [esp+64h] [ebp-138h]
  double v74; // [esp+6Ch] [ebp-130h]
  double v75; // [esp+74h] [ebp-128h]
  double v76; // [esp+7Ch] [ebp-120h]
  double v77; // [esp+84h] [ebp-118h] BYREF
  double v78; // [esp+8Ch] [ebp-110h]
  double v79; // [esp+94h] [ebp-108h]
  double v80; // [esp+9Ch] [ebp-100h]
  double v81; // [esp+A4h] [ebp-F8h]
  double v82; // [esp+ACh] [ebp-F0h]
  double v83; // [esp+B4h] [ebp-E8h]
  double v84; // [esp+BCh] [ebp-E0h] BYREF
  double v85; // [esp+C4h] [ebp-D8h]
  double v86; // [esp+CCh] [ebp-D0h]
  double v87; // [esp+D4h] [ebp-C8h]
  double v88; // [esp+DCh] [ebp-C0h]
  double v89; // [esp+E4h] [ebp-B8h]
  double v90; // [esp+ECh] [ebp-B0h]
  double v91[6]; // [esp+F4h] [ebp-A8h] BYREF
  double v92; // [esp+124h] [ebp-78h]
  double v93[6]; // [esp+12Ch] [ebp-70h] BYREF
  double v94; // [esp+15Ch] [ebp-40h]
  double v95[6]; // [esp+164h] [ebp-38h] BYREF
  double v96; // [esp+194h] [ebp-8h]

  v5 = *(_DWORD *)(a2 + 8);
  v56 = a3;
  v6 = a1;
  *(_DWORD *)(a1 + 84) = sub_542B70(*(unsigned __int16 *)(v5 + 26));
  *(_BYTE *)(v6 + 88) = *(_BYTE *)(v5 + 24);
  v7 = *(float **)v5;
  v8 = *(float **)(v5 + 8);
  v9 = *(float **)(v5 + 16);
  *(float *)(v6 + 48) = *(float *)(*(_DWORD *)v5 + 16) - v8[4];
  v10 = *v8 - *v7;
  *(float *)(v6 + 52) = v10;
  v11 = v10 * v7[4] + *v7 * *(float *)(v6 + 48);
  *(float *)(v6 + 56) = v11;
  if ( v9[4] * *(float *)(v6 + 52) + *(float *)(v6 + 48) * *v9 < v11 )
  {
    *(float *)(v6 + 48) = -*(float *)(v6 + 48);
    *(float *)(v6 + 52) = -*(float *)(v6 + 52);
    *(float *)(v6 + 56) = -*(float *)(v6 + 56);
  }
  v12 = *(float **)(v5 + 8);
  v13 = *(float **)(v5 + 16);
  v14 = *(float **)v5;
  v15 = v6 + 60;
  v61 = *(float *)(v6 + 48) * *(float *)(v6 + 48) + *(float *)(v6 + 52) * *(float *)(v6 + 52);
  *(float *)(v6 + 60) = v12[4] - v13[4];
  v16 = *v13 - *v12;
  *(float *)(v6 + 64) = v16;
  v17 = v16 * v12[4] + *v12 * *(float *)(v6 + 60);
  *(float *)(v6 + 68) = v17;
  if ( v14[4] * *(float *)(v6 + 64) + *(float *)(v6 + 60) * *v14 < v17 )
  {
    *(float *)v15 = -*(float *)v15;
    *(float *)(v6 + 64) = -*(float *)(v6 + 64);
    *(float *)(v6 + 68) = -*(float *)(v6 + 68);
  }
  v18 = *(float **)(v5 + 16);
  v57 = *(float **)v5;
  v58 = *(float **)(v5 + 8);
  v19 = v6 + 72;
  v20 = *(float *)v15 * *(float *)v15 + *(float *)(v6 + 64) * *(float *)(v6 + 64);
  *(float *)(v6 + 72) = v18[4] - *(float *)(*(_DWORD *)v5 + 16);
  v21 = *v57 - *v18;
  *(float *)(v6 + 76) = v21;
  v22 = v21 * v18[4] + *v18 * *(float *)(v6 + 72);
  *(float *)(v6 + 80) = v22;
  if ( v58[4] * *(float *)(v6 + 76) + *(float *)(v6 + 72) * *v58 < v22 )
  {
    *(float *)v19 = -*(float *)v19;
    *(float *)(v6 + 76) = -*(float *)(v6 + 76);
    *(float *)(v6 + 80) = -*(float *)(v6 + 80);
  }
  for ( i = *(float *)v19 * *(float *)v19 + *(float *)(v6 + 76) * *(float *)(v6 + 76); ; i = v59 )
  {
    while ( v61 < v20 )
    {
      v63 = *(_DWORD *)(v6 + 48);
      v65 = *(_DWORD *)(v6 + 56);
      v64 = *(_DWORD *)(v6 + 52);
      *(_DWORD *)(v6 + 48) = *(_DWORD *)v15;
      *(_DWORD *)(v6 + 52) = *(_DWORD *)(v15 + 4);
      *(_DWORD *)(v6 + 56) = *(_DWORD *)(v15 + 8);
      *(_DWORD *)v15 = v63;
      *(_DWORD *)(v15 + 4) = v64;
      *(_DWORD *)(v15 + 8) = v65;
      v23 = v61;
      v61 = v20;
      v6 = a1;
      v20 = v23;
    }
    if ( v20 >= i )
      break;
    v59 = v20;
    v20 = i;
    v66 = *(float *)v15;
    v68 = *(_DWORD *)(v15 + 8);
    v67 = *(_DWORD *)(v15 + 4);
    *(_DWORD *)v15 = *(_DWORD *)v19;
    *(_DWORD *)(v15 + 4) = *(_DWORD *)(v19 + 4);
    *(_DWORD *)(v15 + 8) = *(_DWORD *)(v19 + 8);
    *(float *)v19 = v66;
    *(_DWORD *)(v19 + 4) = v67;
    *(_DWORD *)(v19 + 8) = v68;
    v6 = a1;
  }
  v24 = *(float **)v5;
  v69[0] = &v70;
  v25 = *v24;
  v26 = *((double *)v24 + 3);
  v27 = *(_DWORD *)(v5 + 8);
  v28 = v24[4];
  v69[1] = &v77;
  v70 = v25 * v25;
  v71 = v28 * v28;
  v72 = v28 * v25;
  v73 = v25;
  v74 = v28;
  v75 = 1.0;
  v76 = v26;
  v29 = *(float *)v27;
  v30 = *(double *)(v27 + 24);
  v31 = *(float *)(v27 + 16);
  v69[2] = &v84;
  v32 = *(_DWORD *)(v5 + 16);
  v77 = v29 * v29;
  v78 = v31 * v31;
  v79 = v31 * v29;
  v80 = v29;
  v81 = v31;
  v82 = 1.0;
  v83 = v30;
  v33 = *(float *)v32;
  v34 = *(double *)(v32 + 24);
  v35 = *(float *)(v32 + 16);
  v69[3] = v91;
  v36 = *(_DWORD *)(v5 + 4);
  v84 = v33 * v33;
  v85 = v35 * v35;
  v86 = v35 * v33;
  v87 = v33;
  v88 = v35;
  v89 = 1.0;
  v90 = v34;
  v37 = (*(float *)v27 + *v24) * 0.5;
  v38 = *(double *)(v36 + 24);
  v39 = (*(float *)(v27 + 16) + v24[4]) * 0.5;
  v91[0] = v37 * v37;
  v69[4] = v93;
  v40 = *(_DWORD *)(v5 + 12);
  v91[1] = v39 * v39;
  v91[2] = v39 * v37;
  v91[3] = v37;
  v91[4] = v39;
  v91[5] = 1.0;
  v92 = v38;
  v41 = (*(float *)v32 + *(float *)v27) * 0.5;
  v42 = *(double *)(v40 + 24);
  v43 = *(float *)(v32 + 16) + *(float *)(v27 + 16);
  v69[5] = v95;
  v44 = *(_DWORD *)(v5 + 20);
  v45 = v43 * 0.5;
  v93[0] = v41 * v41;
  v93[1] = v45 * v45;
  v93[2] = v45 * v41;
  v93[3] = v41;
  v93[4] = v45;
  v93[5] = 1.0;
  v94 = v42;
  v46 = (*v24 + *(float *)v32) * 0.5;
  v47 = *(double *)(v44 + 24);
  v48 = (v24[4] + *(float *)(v32 + 16)) * 0.5;
  v95[0] = v46 * v46;
  v95[1] = v48 * v48;
  v95[2] = v48 * v46;
  v95[3] = v46;
  v95[4] = v48;
  v95[5] = 1.0;
  v96 = v47;
  if ( sub_6156E0(v69, 6)
    && (unsigned __int8)sub_5612D0((int)byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\htree.cpp", 367) )
  {
    sub_561210((int)byte_FAE910, "Gaussian elimination for HAT poly failed once", v56);
  }
  v49 = 0;
  *(double *)v6 = v76;
  *(double *)(v6 + 8) = v83;
  *(double *)(v6 + 16) = v90;
  *(double *)(v6 + 24) = v92;
  *(double *)(v6 + 32) = v94;
  *(double *)(v6 + 40) = v96;
  while ( 1 )
  {
    v50 = *(_DWORD *)(v5 + 8 * v49);
    if ( fabs(
           (*(float *)(v50 + 16) * v90 + *(float *)v50 * v76 + v92) * *(float *)v50
         + (*(float *)(v50 + 16) * v83 + v94) * *(float *)(v50 + 16)
         + v96
         - *(double *)(v50 + 24)) > 0.001 )
      break;
    if ( ++v49 >= 3 )
      goto LABEL_24;
  }
  v51 = *(float **)v5;
  v70 = **(float **)v5;
  v71 = v51[4];
  v72 = 1.0;
  v52 = *((double *)v51 + 3);
  v53 = *(_DWORD *)(v5 + 8);
  v54 = *(_DWORD *)(v5 + 16);
  v73 = v52;
  v77 = *(float *)v53;
  v78 = *(float *)(v53 + 16);
  v79 = 1.0;
  v80 = *(double *)(v53 + 24);
  v84 = *(float *)v54;
  v85 = *(float *)(v54 + 16);
  v86 = 1.0;
  v87 = *(double *)(v54 + 24);
  if ( !sub_6156E0(v69, 3) )
  {
    *(double *)v6 = 0.0;
    *(double *)(v6 + 8) = 0.0;
    *(double *)(v6 + 16) = 0.0;
    *(double *)(v6 + 24) = v73;
    *(double *)(v6 + 32) = v80;
    *(double *)(v6 + 40) = v87;
LABEL_24:
    if ( *(_BYTE *)(a2 + 12) )
      *(double *)(v6 + 40) = *(double *)(v6 + 40) - *(double *)(*(_DWORD *)(v6 + 84) + 96);
    return 0;
  }
  if ( (unsigned __int8)sub_5612D0((int)byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\htree.cpp", 405) )
    sub_561210((int)byte_FAE910, "Gaussian elimination for HAT poly failed twice", v56);
  return -1;
}
