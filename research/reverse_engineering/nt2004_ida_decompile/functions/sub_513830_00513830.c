void __thiscall sub_513830(int this, char a2)
{
  double v2; // st7
  float *v4; // ebx
  double v5; // st6
  float *v6; // ecx
  int v7; // edx
  double v8; // st6
  double v9; // st5
  double v10; // st4
  double v11; // st4
  double v12; // st6
  int v13; // edx
  float *v14; // ecx
  double v15; // st6
  double v16; // st5
  double v17; // st5
  double v18; // st4
  double v19; // st4
  double v20; // st5
  int v21; // edi
  int v22; // ecx
  float *v23; // edx
  double v24; // st4
  double v25; // st4
  double v26; // st3
  double v27; // st4
  int v28; // edx
  float *v29; // ecx
  double v30; // st3
  double v31; // st3
  double v32; // st2
  double v33; // st2
  double v34; // st3
  int v35; // edx
  float *v36; // ecx
  double v37; // st2
  double v38; // st2
  double v39; // st1
  double v40; // st1
  int v41; // eax
  int v42; // eax
  double v43; // st7
  double v44; // st7
  double v45; // st7
  float *v46; // edx
  int v47; // eax
  float *v48; // ecx
  double v49; // st6
  double v50; // st6
  double v51; // st7
  int v52; // ecx
  double v53; // st6
  double v54; // st5
  int v55; // ecx
  int v56; // eax
  double v57; // st7
  double v58; // st6
  double v59; // st7
  double v60; // st6
  double v61; // st5
  int v62; // edi
  float *v63; // ebx
  double v64; // st7
  double X; // st7
  int v66; // eax
  double v67; // st7
  double v68; // st7
  int v69; // eax
  double v70; // st7
  double v71; // st7
  double v72; // st7
  double v73; // st7
  double v74; // st7
  double v75; // st7
  float v76; // [esp+14h] [ebp-44h]
  float v77; // [esp+14h] [ebp-44h]
  int v78; // [esp+18h] [ebp-40h]
  int v79; // [esp+18h] [ebp-40h]
  float v80; // [esp+18h] [ebp-40h]
  int v81; // [esp+18h] [ebp-40h]
  float v82; // [esp+18h] [ebp-40h]
  float v83; // [esp+1Ch] [ebp-3Ch]
  float v84; // [esp+1Ch] [ebp-3Ch]
  float v85; // [esp+20h] [ebp-38h]
  float v86; // [esp+20h] [ebp-38h]
  float *v87; // [esp+24h] [ebp-34h]
  float v88; // [esp+24h] [ebp-34h]
  float v89; // [esp+28h] [ebp-30h]
  float v90; // [esp+2Ch] [ebp-2Ch]
  float v91; // [esp+2Ch] [ebp-2Ch]
  float v92; // [esp+30h] [ebp-28h]
  float v93; // [esp+30h] [ebp-28h]
  float v94; // [esp+30h] [ebp-28h]
  int v95; // [esp+30h] [ebp-28h]
  float v96; // [esp+34h] [ebp-24h]
  float v97; // [esp+34h] [ebp-24h]
  float v98; // [esp+38h] [ebp-20h]
  float v99; // [esp+44h] [ebp-14h]
  float v100[4]; // [esp+48h] [ebp-10h]

  v2 = flt_76875C;
  v78 = 0;
  v4 = (float *)(this + 17864);
  v87 = (float *)(this + 19560);
  v89 = 1.0 / flt_768780;
  v5 = 1.0 / (0.071428575 * flt_76875C);
  *(float *)(this + 19364) = v5;
  *(float *)(this + 19428) = v5;
  *(float *)(this + 19492) = v5;
  *(float *)(this + 19556) = v5;
  *(float *)(this + 19620) = 1.0 / (v89 * 0.071428575);
  v96 = 1.0
      / (fabs(*(float *)(this + 17960) + *(float *)(this + 17712) - *(float *)(this + 18208) - *(float *)(this + 18456))
       * 0.5);
  v92 = 1.0
      / (fabs(*(float *)(this + 17704) - *(float *)(this + 17952) + *(float *)(this + 18200) - *(float *)(this + 18448))
       * 0.5);
  do
  {
    v6 = v4;
    v7 = 4;
    v76 = (double)v78 * v2 * 0.071428575;
    v8 = 0.0;
    do
    {
      v9 = v76 * v6[18];
      if ( v9 <= *v6 )
        v10 = v9;
      else
        v10 = *v6;
      v11 = v10 * *(v6 - 1);
      v6 += 62;
      --v7;
      v8 = v8 + (v11 + 1.0) * *(v6 - 66) * v9;
    }
    while ( v7 );
    v12 = v8 * *(float *)(this + 20740);
    v13 = 0;
    v14 = v4;
    v85 = v96 * v12 * 0.5;
    v83 = v12 * v92 * 0.5;
    v15 = 0.0;
    do
    {
      if ( (unsigned int)v13 > 1 )
        v16 = -v85;
      else
        v16 = v85;
      v17 = v16 + v76 * v14[18];
      if ( v17 <= *v14 )
        v18 = v17;
      else
        v18 = *v14;
      v19 = v18 * *(v14 - 1);
      ++v13;
      v14 += 62;
      v15 = v15 + (v19 + 1.0) * *(v14 - 66) * v17;
    }
    while ( v13 < 4 );
    v20 = 0.0;
    v21 = *(_DWORD *)(this + 18768);
    v22 = 0;
    v23 = v4;
    do
    {
      if ( v21 )
      {
        if ( v21 == 2 && (unsigned int)v22 > 1 )
          goto LABEL_30;
      }
      else
      {
        if ( v22 == 2 )
          goto LABEL_24;
        if ( v22 != 3 )
          goto LABEL_30;
      }
      if ( v22 != 2 && v22 != 3 )
      {
        v24 = -v85;
        goto LABEL_26;
      }
LABEL_24:
      v24 = v85;
LABEL_26:
      v25 = v24 + v76 * v23[18];
      if ( v25 <= *v23 )
        v26 = v25;
      else
        v26 = *v23;
      v20 = v20 + (v26 * *(v23 - 1) + 1.0) * *(v23 - 4) * v25;
LABEL_30:
      ++v22;
      v23 += 62;
    }
    while ( v22 < 4 );
    v27 = 0.0;
    v28 = 0;
    v29 = v4;
    do
    {
      if ( v28 == 1 || v28 == 3 )
        v30 = v83;
      else
        v30 = -v83;
      v31 = v30 + v76 * v29[18];
      if ( v31 <= *v29 )
        v32 = v31;
      else
        v32 = *v29;
      v33 = v32 * *(v29 - 1);
      ++v28;
      v29 += 62;
      v27 = v27 + (v33 + 1.0) * *(v29 - 66) * v31;
    }
    while ( v28 < 4 );
    v34 = 0.0;
    v35 = 0;
    v36 = v4;
    do
    {
      if ( v35 && v35 != 2 )
        v37 = -v83;
      else
        v37 = v83;
      v38 = v37 + v76 * v36[18];
      if ( v38 <= *v36 )
        v39 = v38;
      else
        v39 = *v36;
      v40 = v39 * *(v36 - 1);
      ++v35;
      v36 += 62;
      v34 = v34 + (v40 + 1.0) * *(v36 - 66) * v38;
    }
    while ( v35 < 4 );
    *(v87 - 48) = v15;
    *v87 = v20;
    *(v87 - 32) = v27;
    ++v78;
    *(++v87 - 17) = v34;
  }
  while ( v78 < 15 );
  v41 = *(_DWORD *)(this + 18768);
  if ( !v41 )
  {
    v43 = *(float *)(this + 18580) + *(float *)(this + 18332);
LABEL_56:
    v44 = v43 * 0.5;
    goto LABEL_57;
  }
  v42 = v41 - 1;
  if ( !v42 )
  {
    v44 = (*(float *)(this + 18580) + *(float *)(this + 18332) + *(float *)(this + 18084) + *(float *)(this + 17836))
        * 0.25;
LABEL_57:
    *(float *)(this + 19688) = v44;
    goto LABEL_58;
  }
  if ( v42 == 1 )
  {
    v43 = *(float *)(this + 18084) + *(float *)(this + 17836);
    goto LABEL_56;
  }
LABEL_58:
  v45 = 0.0;
  v46 = (float *)(this + 17836);
  v47 = 0;
  v48 = (float *)(this + 17836);
  do
  {
    if ( (unsigned int)v47 > 1 )
      v49 = *(float *)(this + 18912);
    else
      v49 = *(float *)(this + 18892);
    v50 = v49 / *v48;
    ++v47;
    v48 += 62;
    v45 = v45 + v50;
  }
  while ( v47 < 4 );
  v51 = v45 * *(float *)(this + 17588);
  v52 = 0;
  *(float *)(this + 19684) = v51;
  v53 = *(float *)(this + 18952);
  *(float *)(this + 19692) = *(float *)(this + 18952);
  v54 = *(float *)(this + 18956) * 4096.0 - *(float *)(this + 17584) * -9.8100004;
  do
  {
    if ( *v46 <= 0.0 )
      v100[v52] = 0.0;
    else
      v100[v52] = v54 / *v46 * v46[10];
    ++v52;
    v46 += 62;
  }
  while ( v52 < 4 );
  v55 = 15;
  v56 = this + 19432;
  *(float *)(this + 19692) = ((v100[3] + v100[2]) * 0.27500001 + (v100[1] + v100[0]) * 0.22499999) * 0.00024414062 + v53;
  if ( a2 )
  {
    *(float *)(this + 19684) = v51 * 0.93000001;
    v57 = 1.0 / *(float *)(this + 19356);
    do
    {
      v58 = *(float *)(v56 - 64);
      v56 += 4;
      --v55;
      *(float *)(v56 - 68) = v58 * v57 * 0.93000001;
      *(float *)(v56 - 4) = *(float *)(v56 - 4) * v57 * 0.86000001;
      *(float *)(v56 + 60) = *(float *)(v56 + 60) * v57 * 0.86000001;
      *(float *)(v56 + 124) = *(float *)(v56 + 124) * v57 * 0.93000001;
    }
    while ( v55 );
  }
  else
  {
    *(float *)(this + 19684) = v51 * flt_7686F0;
    v59 = flt_768714;
    v60 = flt_768738;
    do
    {
      v61 = *(float *)(v56 - 64);
      v56 += 4;
      --v55;
      *(float *)(v56 - 68) = v61 * v59;
      *(float *)(v56 - 4) = *(float *)(v56 - 4) * v60;
      *(float *)(v56 + 60) = *(float *)(v56 + 60) * v60;
      *(float *)(v56 + 124) = *(float *)(v56 + 124) * 0.97000003;
    }
    while ( v55 );
  }
  v62 = 0;
  v79 = 0;
  v63 = (float *)(this + 19624);
  do
  {
    v77 = 0.0;
    v86 = 0.0;
    v97 = 0.0;
    v84 = 128.0;
    v98 = (double)v79 * v89 * 0.071428575;
    while ( 1 )
    {
      v88 = v77 * *(float *)(this + 17584) * v77 * v98;
      v64 = v77 * v77 * *(float *)(this + 18956) - (v77 * v77 * 0.0 - 9.8100004) * *(float *)(this + 17584);
      v93 = v64;
      X = v64 * *(float *)(this + 19428);
      v90 = X;
      v80 = floor(X);
      v66 = (int)v80;
      v81 = v66;
      if ( v66 >= 0 )
      {
        if ( v66 >= 14 )
        {
          v66 = 13;
          v81 = 13;
        }
        v67 = *(float *)(this + 4 * v66 + 19432);
        v82 = (*(float *)(this + 4 * v66 + 19436) - v67) * (v90 - (double)v81) + v67;
      }
      else
      {
        v82 = *(float *)(this + 19432);
      }
      v68 = v93 * *(float *)(this + 19492);
      v91 = v68;
      v94 = floor(v68);
      v69 = (int)v94;
      v95 = v69;
      if ( v69 >= 0 )
      {
        if ( v69 >= 14 )
        {
          v69 = 13;
          v95 = 13;
        }
        v71 = *(float *)(this + 4 * v69 + 19496);
        v70 = v71 + (*(float *)(this + 4 * v69 + 19500) - v71) * (v91 - (double)v95);
      }
      else
      {
        v70 = *(float *)(this + 19496);
      }
      if ( v82 > v70 )
        v70 = v82;
      v99 = v86;
      v86 = v88 == 0.0 ? 1024.0 : v70 / v88;
      if ( v84 < 0.40000001 )
        break;
      v97 = v77;
      if ( v70 < v88 )
        v72 = v77 - v84;
      else
        v72 = v84 + v77;
      v77 = v72;
      v84 = v84 * 0.5;
    }
    v73 = v86 - v99;
    if ( v73 == 0.0 )
    {
      v75 = v77;
    }
    else
    {
      v74 = (v86 - 1.0) / v73;
      if ( v74 >= -1.0 )
      {
        if ( v74 > 2.0 )
          v74 = 2.0;
        v75 = v74 * (v97 - v77) + v77;
      }
      else
      {
        v75 = -1.0 * (v97 - v77) + v77;
      }
    }
    if ( v75 < 0.0 )
      v75 = 0.0;
    ++v62;
    *v63++ = v75;
    v79 = v62;
  }
  while ( v62 < 15 );
}
