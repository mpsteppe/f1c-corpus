void __thiscall sub_4E8010(int this, char a2)
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
  int v60; // edi
  float *v61; // ebx
  double v62; // st7
  double v63; // st7
  int v64; // eax
  double v65; // st7
  double v66; // st7
  int v67; // eax
  double v68; // st7
  double v69; // st7
  double v70; // st7
  double v71; // st7
  double v72; // st7
  double v73; // st7
  float v74; // [esp+14h] [ebp-44h]
  float v75; // [esp+14h] [ebp-44h]
  int v76; // [esp+18h] [ebp-40h]
  int v77; // [esp+18h] [ebp-40h]
  float v78; // [esp+18h] [ebp-40h]
  int v79; // [esp+18h] [ebp-40h]
  float v80; // [esp+18h] [ebp-40h]
  float v81; // [esp+1Ch] [ebp-3Ch]
  float v82; // [esp+1Ch] [ebp-3Ch]
  float v83; // [esp+20h] [ebp-38h]
  float v84; // [esp+20h] [ebp-38h]
  float *v85; // [esp+24h] [ebp-34h]
  float v86; // [esp+24h] [ebp-34h]
  float v87; // [esp+28h] [ebp-30h]
  float v88; // [esp+2Ch] [ebp-2Ch]
  float v89; // [esp+2Ch] [ebp-2Ch]
  float v90; // [esp+30h] [ebp-28h]
  float v91; // [esp+30h] [ebp-28h]
  float v92; // [esp+30h] [ebp-28h]
  int v93; // [esp+30h] [ebp-28h]
  float v94; // [esp+34h] [ebp-24h]
  float v95; // [esp+34h] [ebp-24h]
  float v96; // [esp+38h] [ebp-20h]
  float v97; // [esp+44h] [ebp-14h]
  float v98[4]; // [esp+48h] [ebp-10h]

  v2 = flt_7D0278;
  v76 = 0;
  v4 = (float *)(this + 13868);
  v85 = (float *)(this + 15552);
  v87 = 1.0 / flt_7D029C;
  v5 = 1.0 / (0.071428575 * flt_7D0278);
  *(float *)(this + 15356) = v5;
  *(float *)(this + 15420) = v5;
  *(float *)(this + 15484) = v5;
  *(float *)(this + 15548) = v5;
  *(float *)(this + 15612) = 1.0 / (v87 * 0.071428575);
  v94 = 1.0
      / (fabs(*(float *)(this + 13964) + *(float *)(this + 13716) - *(float *)(this + 14212) - *(float *)(this + 14460))
       * 0.5);
  v90 = 1.0
      / (fabs(*(float *)(this + 13708) - *(float *)(this + 13956) + *(float *)(this + 14204) - *(float *)(this + 14452))
       * 0.5);
  do
  {
    v6 = v4;
    v7 = 4;
    v74 = (double)v76 * v2 * 0.071428575;
    v8 = 0.0;
    do
    {
      v9 = v74 * v6[18];
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
    v12 = v8 * *(float *)(this + 16420);
    v13 = 0;
    v14 = v4;
    v83 = v94 * v12 * 0.5;
    v81 = v12 * v90 * 0.5;
    v15 = 0.0;
    do
    {
      if ( (unsigned int)v13 > 1 )
        v16 = -v83;
      else
        v16 = v83;
      v17 = v16 + v74 * v14[18];
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
    v21 = *(_DWORD *)(this + 14772);
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
        v24 = -v83;
        goto LABEL_26;
      }
LABEL_24:
      v24 = v83;
LABEL_26:
      v25 = v24 + v74 * v23[18];
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
        v30 = v81;
      else
        v30 = -v81;
      v31 = v30 + v74 * v29[18];
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
        v37 = -v81;
      else
        v37 = v81;
      v38 = v37 + v74 * v36[18];
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
    *(v85 - 48) = v15;
    *v85 = v20;
    *(v85 - 32) = v27;
    ++v76;
    *(++v85 - 17) = v34;
  }
  while ( v76 < 15 );
  v41 = *(_DWORD *)(this + 14772);
  if ( !v41 )
  {
    v43 = *(float *)(this + 14584) + *(float *)(this + 14336);
LABEL_56:
    v44 = v43 * 0.5;
    goto LABEL_57;
  }
  v42 = v41 - 1;
  if ( !v42 )
  {
    v44 = (*(float *)(this + 14584) + *(float *)(this + 14336) + *(float *)(this + 14088) + *(float *)(this + 13840))
        * 0.25;
LABEL_57:
    *(float *)(this + 15680) = v44;
    goto LABEL_58;
  }
  if ( v42 == 1 )
  {
    v43 = *(float *)(this + 14088) + *(float *)(this + 13840);
    goto LABEL_56;
  }
LABEL_58:
  v45 = 0.0;
  v46 = (float *)(this + 13840);
  v47 = 0;
  v48 = (float *)(this + 13840);
  do
  {
    if ( (unsigned int)v47 > 1 )
      v49 = *(float *)(this + 14916);
    else
      v49 = *(float *)(this + 14896);
    v50 = v49 / *v48;
    ++v47;
    v48 += 62;
    v45 = v45 + v50;
  }
  while ( v47 < 4 );
  v51 = v45 * *(float *)(this + 13592);
  v52 = 0;
  *(float *)(this + 15676) = v51;
  v53 = *(float *)(this + 14956);
  *(float *)(this + 15684) = *(float *)(this + 14956);
  v54 = *(float *)(this + 14960) * 4096.0 - *(float *)(this + 13588) * -9.8100004;
  do
  {
    if ( *v46 <= 0.0 )
      v98[v52] = 0.0;
    else
      v98[v52] = v54 / *v46 * v46[10];
    ++v52;
    v46 += 62;
  }
  while ( v52 < 4 );
  v55 = 15;
  v56 = this + 15424;
  *(float *)(this + 15684) = ((v98[3] + v98[2]) * 0.27500001 + (v98[1] + v98[0]) * 0.22499999) * 0.00024414062 + v53;
  if ( a2 )
  {
    *(float *)(this + 15676) = v51 * 0.92000002;
    v57 = 1.0 / *(float *)(this + 15348);
    do
    {
      v58 = *(float *)(v56 - 64);
      v56 += 4;
      --v55;
      *(float *)(v56 - 68) = v58 * v57 * 0.92000002;
      *(float *)(v56 - 4) = *(float *)(v56 - 4) * v57 * 0.83999997;
      *(float *)(v56 + 60) = *(float *)(v56 + 60) * v57 * 0.83999997;
      *(float *)(v56 + 124) = *(float *)(v56 + 124) * v57 * 0.92000002;
    }
    while ( v55 );
  }
  else
  {
    *(float *)(this + 15676) = v51 * flt_7D020C;
    do
    {
      v56 += 4;
      --v55;
      *(float *)(v56 - 68) = flt_7D0230 * *(float *)(v56 - 68);
      v59 = flt_7D0254;
      *(float *)(v56 - 4) = *(float *)(v56 - 4) * flt_7D0254;
      *(float *)(v56 + 60) = *(float *)(v56 + 60) * v59;
      *(float *)(v56 + 124) = *(float *)(v56 + 124) * 0.97000003;
    }
    while ( v55 );
  }
  v60 = 0;
  v77 = 0;
  v61 = (float *)(this + 15616);
  do
  {
    v75 = 0.0;
    v84 = 0.0;
    v95 = 0.0;
    v82 = 128.0;
    v96 = (double)v77 * v87 * 0.071428575;
    while ( 1 )
    {
      v86 = v75 * *(float *)(this + 13588) * v75 * v96;
      v62 = v75 * v75 * *(float *)(this + 14960) - (v75 * v75 * 0.0 - 9.8100004) * *(float *)(this + 13588);
      v91 = v62;
      v63 = v62 * *(float *)(this + 15420);
      v88 = v63;
      sub_5895A2(v63);
      v78 = v63;
      v64 = (int)v78;
      v79 = v64;
      if ( v64 >= 0 )
      {
        if ( v64 >= 14 )
        {
          v64 = 13;
          v79 = 13;
        }
        v65 = *(float *)(this + 4 * v64 + 15424);
        v80 = (*(float *)(this + 4 * v64 + 15428) - v65) * (v88 - (double)v79) + v65;
      }
      else
      {
        v80 = *(float *)(this + 15424);
      }
      v66 = v91 * *(float *)(this + 15484);
      v89 = v66;
      sub_5895A2(v66);
      v92 = v66;
      v67 = (int)v92;
      v93 = v67;
      if ( v67 >= 0 )
      {
        if ( v67 >= 14 )
        {
          v67 = 13;
          v93 = 13;
        }
        v69 = *(float *)(this + 4 * v67 + 15488);
        v68 = v69 + (*(float *)(this + 4 * v67 + 15492) - v69) * (v89 - (double)v93);
      }
      else
      {
        v68 = *(float *)(this + 15488);
      }
      if ( v80 > v68 )
        v68 = v80;
      v97 = v84;
      v84 = v86 == 0.0 ? 1024.0 : v68 / v86;
      if ( v82 < 0.40000001 )
        break;
      v95 = v75;
      if ( v68 < v86 )
        v70 = v75 - v82;
      else
        v70 = v82 + v75;
      v75 = v70;
      v82 = v82 * 0.5;
    }
    v71 = v84 - v97;
    if ( v71 == 0.0 )
    {
      v73 = v75;
    }
    else
    {
      v72 = (v84 - 1.0) / v71;
      if ( v72 >= -1.0 )
      {
        if ( v72 > 2.0 )
          v72 = 2.0;
        v73 = v72 * (v95 - v75) + v75;
      }
      else
      {
        v73 = -1.0 * (v95 - v75) + v75;
      }
    }
    if ( v73 < 0.0 )
      v73 = 0.0;
    ++v60;
    *v61++ = v73;
    v77 = v60;
  }
  while ( v60 < 15 );
}
