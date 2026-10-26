void __thiscall sub_41FB90(int this)
{
  int v2; // edi
  int v3; // eax
  double v4; // st7
  double v5; // st7
  double v6; // st7
  double v7; // st7
  double v8; // st7
  double v9; // st7
  double v10; // st7
  double v11; // st7
  int v12; // eax
  int v13; // esi
  const char *v14; // eax
  const char *v15; // eax
  double v16; // st7
  const char *v17; // eax
  const char *v18; // eax
  int v19; // eax
  int v20; // esi
  const char *v21; // eax
  const char *v22; // eax
  double v23; // st7
  const char *v24; // eax
  const char *v25; // eax
  int v26; // eax
  int v27; // esi
  const char *v28; // eax
  const char *v29; // eax
  double v30; // st7
  const char *v31; // eax
  const char *v32; // eax
  int v33; // eax
  int v34; // esi
  const char *v35; // eax
  const char *v36; // eax
  double v37; // st7
  const char *v38; // eax
  const char *v39; // eax
  double v40; // st7
  double v41; // st7
  int v42; // eax
  int v43; // esi
  const char *v44; // eax
  const char *v45; // eax
  double v46; // st7
  const char *v47; // eax
  const char *v48; // eax
  int v49; // eax
  int v50; // esi
  const char *v51; // eax
  const char *v52; // eax
  double v53; // st7
  const char *v54; // eax
  const char *v55; // eax
  int v56; // eax
  int v57; // esi
  const char *v58; // eax
  const char *v59; // eax
  double v60; // st7
  const char *v61; // eax
  const char *v62; // eax
  double v63; // st7
  int v64; // eax
  int v65; // eax
  const char *v66; // eax
  int v67; // eax
  const char *v68; // eax
  double v69; // st7
  double v70; // st7
  double v71; // st6
  double v72; // st7
  double v73; // st7
  double v74; // st7
  double v75; // st7
  char *v76; // ecx
  int v77; // ebp
  const char *v78; // eax
  char *v79; // ecx
  int v80; // eax
  const char *v81; // eax
  int v82; // eax
  const char *v83; // eax
  int v84; // [esp+Ch] [ebp-10h]
  _DWORD *v85; // [esp+Ch] [ebp-10h]
  int v86; // [esp+10h] [ebp-Ch]
  float v87; // [esp+14h] [ebp-8h]
  float v88; // [esp+14h] [ebp-8h]
  float v89; // [esp+14h] [ebp-8h]
  float v90; // [esp+14h] [ebp-8h]
  float v91; // [esp+14h] [ebp-8h]
  float v92; // [esp+14h] [ebp-8h]
  float v93; // [esp+14h] [ebp-8h]
  float v94; // [esp+14h] [ebp-8h]
  float v95; // [esp+14h] [ebp-8h]
  float v96; // [esp+14h] [ebp-8h]
  float v97; // [esp+14h] [ebp-8h]
  float v98; // [esp+14h] [ebp-8h]
  float v99; // [esp+14h] [ebp-8h]
  float v100; // [esp+14h] [ebp-8h]
  float v101; // [esp+14h] [ebp-8h]
  float v102; // [esp+14h] [ebp-8h]
  float v103; // [esp+14h] [ebp-8h]
  float v104; // [esp+14h] [ebp-8h]
  float v105; // [esp+14h] [ebp-8h]
  float v106; // [esp+14h] [ebp-8h]
  float v107; // [esp+14h] [ebp-8h]
  float v108; // [esp+14h] [ebp-8h]
  float v109; // [esp+14h] [ebp-8h]
  float v110; // [esp+14h] [ebp-8h]
  float v111; // [esp+14h] [ebp-8h]
  float v112; // [esp+14h] [ebp-8h]
  float v113; // [esp+14h] [ebp-8h]
  float v114; // [esp+14h] [ebp-8h]
  int v115; // [esp+18h] [ebp-4h]

  v2 = sub_57AE50((char *)(*(_DWORD *)(this + 80) + 24772));
  *(_DWORD *)(this + 24164) = -1138501878;
  *(_DWORD *)(this + 24000) = -1138501878;
  v3 = *(_DWORD *)(this + 80);
  *(_DWORD *)(this + 24008) = 1065353216;
  *(_DWORD *)(this + 24168) = 1065353216;
  *(_DWORD *)(this + 24172) = 1065353216;
  *(_DWORD *)(this + 24176) = 0;
  if ( *(_DWORD *)(v3 + 25300) )
  {
    *(_DWORD *)(this + 23968) = 1065353216;
    *(_DWORD *)(this + 23976) = 1065353216;
    *(_DWORD *)(this + 23980) = 1065353216;
    *(_DWORD *)(this + 23984) = 1065353216;
    *(_DWORD *)(this + 23988) = 1065353216;
    *(_DWORD *)(this + 23992) = 1065353216;
    *(_DWORD *)(this + 23964) = 1065353216;
    *(_DWORD *)(this + 23972) = 1065353216;
  }
  else
  {
    if ( sub_4D1B00(&dword_7D3C50) * 0.050000001 + 0.69999999 > 1.0
      || sub_4D1B00(&dword_7D3C50) * 0.050000001 + 0.69999999 >= 0.0 )
    {
      if ( sub_4D1B00(&dword_7D3C50) * 0.050000001 + 0.69999999 <= 1.0 )
        v4 = sub_4D1B00(&dword_7D3C50) * 0.050000001 + 0.69999999;
      else
        v4 = 1.0;
    }
    else
    {
      v4 = 0.0;
    }
    *(float *)(this + 23968) = v4;
    if ( sub_4D1B00(&dword_7D3C50) * 0.050000001 + 0.69999999 > 1.0
      || sub_4D1B00(&dword_7D3C50) * 0.050000001 + 0.69999999 >= 0.0 )
    {
      if ( sub_4D1B00(&dword_7D3C50) * 0.050000001 + 0.69999999 <= 1.0 )
        v5 = sub_4D1B00(&dword_7D3C50) * 0.050000001 + 0.69999999;
      else
        v5 = 1.0;
    }
    else
    {
      v5 = 0.0;
    }
    *(float *)(this + 23976) = v5;
    if ( sub_4D1B00(&dword_7D3C50) * 0.050000001 + 0.69999999 > 1.0
      || sub_4D1B00(&dword_7D3C50) * 0.050000001 + 0.69999999 >= 0.0 )
    {
      if ( sub_4D1B00(&dword_7D3C50) * 0.050000001 + 0.69999999 <= 1.0 )
        v6 = sub_4D1B00(&dword_7D3C50) * 0.050000001 + 0.69999999;
      else
        v6 = 1.0;
    }
    else
    {
      v6 = 0.0;
    }
    *(float *)(this + 23980) = v6;
    if ( sub_4D1B00(&dword_7D3C50) * 0.050000001 + 0.69999999 > 1.0
      || sub_4D1B00(&dword_7D3C50) * 0.050000001 + 0.69999999 >= 0.0 )
    {
      if ( sub_4D1B00(&dword_7D3C50) * 0.050000001 + 0.69999999 <= 1.0 )
        v7 = sub_4D1B00(&dword_7D3C50) * 0.050000001 + 0.69999999;
      else
        v7 = 1.0;
    }
    else
    {
      v7 = 0.0;
    }
    *(float *)(this + 23984) = v7;
    if ( sub_4D1B00(&dword_7D3C50) * 0.050000001 + 0.69999999 > 1.0
      || sub_4D1B00(&dword_7D3C50) * 0.050000001 + 0.69999999 >= 0.0 )
    {
      if ( sub_4D1B00(&dword_7D3C50) * 0.050000001 + 0.69999999 <= 1.0 )
        v8 = sub_4D1B00(&dword_7D3C50) * 0.050000001 + 0.69999999;
      else
        v8 = 1.0;
    }
    else
    {
      v8 = 0.0;
    }
    *(float *)(this + 23988) = v8;
    if ( sub_4D1B00(&dword_7D3C50) * 0.050000001 + 0.69999999 > 1.0
      || sub_4D1B00(&dword_7D3C50) * 0.050000001 + 0.69999999 >= 0.0 )
    {
      if ( sub_4D1B00(&dword_7D3C50) * 0.050000001 + 0.69999999 <= 1.0 )
        v9 = sub_4D1B00(&dword_7D3C50) * 0.050000001 + 0.69999999;
      else
        v9 = 1.0;
    }
    else
    {
      v9 = 0.0;
    }
    *(float *)(this + 23992) = v9;
    if ( sub_4D1B00(&dword_7D3C50) * 0.050000001 + 0.60000002 > 0.89999998
      || sub_4D1B00(&dword_7D3C50) * 0.050000001 + 0.60000002 >= 0.0 )
    {
      if ( sub_4D1B00(&dword_7D3C50) * 0.050000001 + 0.60000002 <= 0.89999998 )
        v10 = sub_4D1B00(&dword_7D3C50) * 0.050000001 + 0.60000002;
      else
        v10 = 0.89999998;
    }
    else
    {
      v10 = 0.0;
    }
    *(float *)(this + 23964) = v10;
    if ( sub_4D1B00(&dword_7D3C50) * 0.050000001 + 0.80000001 > 1.0
      || sub_4D1B00(&dword_7D3C50) * 0.050000001 + 0.80000001 >= 0.0 )
    {
      if ( sub_4D1B00(&dword_7D3C50) * 0.050000001 + 0.80000001 <= 1.0 )
        v11 = sub_4D1B00(&dword_7D3C50) * 0.050000001 + 0.80000001;
      else
        v11 = 1.0;
    }
    else
    {
      v11 = 0.0;
    }
    *(float *)(this + 23972) = v11;
  }
  *(_DWORD *)(this + 23924) = 1065353216;
  if ( !v2 )
    goto LABEL_126;
  v12 = sub_57A720(aSpeed);
  v13 = v12;
  if ( v12 )
  {
    v14 = (const char *)sub_57A6D0(v12);
    v87 = atof(v14) * 0.0099999998;
    if ( sub_4D1B00(&dword_7D3C50) * 0.050000001 + v87 > 1.0
      || (v15 = (const char *)sub_57A6D0(v13),
          v88 = atof(v15) * 0.0099999998,
          sub_4D1B00(&dword_7D3C50) * 0.050000001 + v88 >= 0.0) )
    {
      v17 = (const char *)sub_57A6D0(v13);
      v89 = atof(v17) * 0.0099999998;
      if ( sub_4D1B00(&dword_7D3C50) * 0.050000001 + v89 <= 1.0 )
      {
        v18 = (const char *)sub_57A6D0(v13);
        v90 = atof(v18) * 0.0099999998;
        v16 = sub_4D1B00(&dword_7D3C50) * 0.050000001 + v90;
      }
      else
      {
        v16 = 1.0;
      }
    }
    else
    {
      v16 = 0.0;
    }
    *(float *)(this + 23968) = v16;
  }
  v19 = sub_57A720(aConcentration);
  v20 = v19;
  if ( v19 )
  {
    v21 = (const char *)sub_57A6D0(v19);
    v91 = atof(v21) * 0.0099999998;
    if ( sub_4D1B00(&dword_7D3C50) * 0.050000001 + v91 > 1.0
      || (v22 = (const char *)sub_57A6D0(v20),
          v92 = atof(v22) * 0.0099999998,
          sub_4D1B00(&dword_7D3C50) * 0.050000001 + v92 >= 0.0) )
    {
      v24 = (const char *)sub_57A6D0(v20);
      v93 = atof(v24) * 0.0099999998;
      if ( sub_4D1B00(&dword_7D3C50) * 0.050000001 + v93 <= 1.0 )
      {
        v25 = (const char *)sub_57A6D0(v20);
        v94 = atof(v25) * 0.0099999998;
        v23 = sub_4D1B00(&dword_7D3C50) * 0.050000001 + v94;
      }
      else
      {
        v23 = 1.0;
      }
    }
    else
    {
      v23 = 0.0;
    }
    *(float *)(this + 23976) = v23;
  }
  v26 = sub_57A720(aFitness);
  v27 = v26;
  if ( v26 )
  {
    v28 = (const char *)sub_57A6D0(v26);
    v95 = atof(v28) * 0.0099999998;
    if ( sub_4D1B00(&dword_7D3C50) * 0.050000001 + v95 > 1.0
      || (v29 = (const char *)sub_57A6D0(v27),
          v96 = atof(v29) * 0.0099999998,
          sub_4D1B00(&dword_7D3C50) * 0.050000001 + v96 >= 0.0) )
    {
      v31 = (const char *)sub_57A6D0(v27);
      v97 = atof(v31) * 0.0099999998;
      if ( sub_4D1B00(&dword_7D3C50) * 0.050000001 + v97 <= 1.0 )
      {
        v32 = (const char *)sub_57A6D0(v27);
        v98 = atof(v32) * 0.0099999998;
        v30 = sub_4D1B00(&dword_7D3C50) * 0.050000001 + v98;
      }
      else
      {
        v30 = 1.0;
      }
    }
    else
    {
      v30 = 0.0;
    }
    *(float *)(this + 23980) = v30;
  }
  v33 = sub_57A720(aAggression);
  v34 = v33;
  if ( v33 )
  {
    v35 = (const char *)sub_57A6D0(v33);
    v99 = atof(v35) * 0.0099999998;
    if ( sub_4D1B00(&dword_7D3C50) * 0.050000001 + v99 > 1.0
      || (v36 = (const char *)sub_57A6D0(v34),
          v100 = atof(v36) * 0.0099999998,
          sub_4D1B00(&dword_7D3C50) * 0.050000001 + v100 >= 0.0) )
    {
      v38 = (const char *)sub_57A6D0(v34);
      v101 = atof(v38) * 0.0099999998;
      if ( sub_4D1B00(&dword_7D3C50) * 0.050000001 + v101 <= 1.0 )
      {
        v39 = (const char *)sub_57A6D0(v34);
        v102 = atof(v39) * 0.0099999998;
        v37 = sub_4D1B00(&dword_7D3C50) * 0.050000001 + v102;
      }
      else
      {
        v37 = 1.0;
      }
    }
    else
    {
      v37 = 0.0;
    }
    *(float *)(this + 23964) = v37 * 0.94999999;
  }
  v40 = flt_768660;
  if ( *(_DWORD *)dword_7689CC == 8 )
  {
    v40 = flt_7687C8;
  }
  else if ( *(_DWORD *)dword_7689CC == 4 )
  {
    v40 = flt_768810;
  }
  v41 = (v40 + 1.0) * 0.5 * *(float *)(this + 23964);
  *(float *)(this + 23964) = v41;
  if ( v41 < 0.0099999998 )
    *(_DWORD *)(this + 23964) = 1008981770;
  *(float *)(this + 23932) = *(float *)(this + 23932) - *(float *)(this + 23964);
  v42 = sub_57A720(aIntimidation);
  v43 = v42;
  if ( v42 )
  {
    v44 = (const char *)sub_57A6D0(v42);
    v103 = atof(v44) * 0.0099999998;
    if ( sub_4D1B00(&dword_7D3C50) * 0.050000001 + v103 > 1.0
      || (v45 = (const char *)sub_57A6D0(v43),
          v104 = atof(v45) * 0.0099999998,
          sub_4D1B00(&dword_7D3C50) * 0.050000001 + v104 >= 0.0) )
    {
      v47 = (const char *)sub_57A6D0(v43);
      v105 = atof(v47) * 0.0099999998;
      if ( sub_4D1B00(&dword_7D3C50) * 0.050000001 + v105 <= 1.0 )
      {
        v48 = (const char *)sub_57A6D0(v43);
        v106 = atof(v48) * 0.0099999998;
        v46 = sub_4D1B00(&dword_7D3C50) * 0.050000001 + v106;
      }
      else
      {
        v46 = 1.0;
      }
    }
    else
    {
      v46 = 0.0;
    }
    *(float *)(this + 23984) = v46;
  }
  v49 = sub_57A720(aStatus);
  v50 = v49;
  if ( v49 )
  {
    v51 = (const char *)sub_57A6D0(v49);
    v107 = atof(v51) * 0.0099999998;
    if ( sub_4D1B00(&dword_7D3C50) * 0.050000001 + v107 > 1.0
      || (v52 = (const char *)sub_57A6D0(v50),
          v108 = atof(v52) * 0.0099999998,
          sub_4D1B00(&dword_7D3C50) * 0.050000001 + v108 >= 0.0) )
    {
      v54 = (const char *)sub_57A6D0(v50);
      v109 = atof(v54) * 0.0099999998;
      if ( sub_4D1B00(&dword_7D3C50) * 0.050000001 + v109 <= 1.0 )
      {
        v55 = (const char *)sub_57A6D0(v50);
        v110 = atof(v55) * 0.0099999998;
        v53 = sub_4D1B00(&dword_7D3C50) * 0.050000001 + v110;
      }
      else
      {
        v53 = 1.0;
      }
    }
    else
    {
      v53 = 0.0;
    }
    *(float *)(this + 23988) = v53;
  }
  v56 = sub_57A720(aCourtesy);
  v57 = v56;
  if ( v56 )
  {
    v58 = (const char *)sub_57A6D0(v56);
    v111 = atof(v58) * 0.0099999998;
    if ( sub_4D1B00(&dword_7D3C50) * 0.050000001 + v111 > 1.0
      || (v59 = (const char *)sub_57A6D0(v57),
          v112 = atof(v59) * 0.0099999998,
          sub_4D1B00(&dword_7D3C50) * 0.050000001 + v112 >= 0.0) )
    {
      v61 = (const char *)sub_57A6D0(v57);
      v113 = atof(v61) * 0.0099999998;
      if ( sub_4D1B00(&dword_7D3C50) * 0.050000001 + v113 <= 1.0 )
      {
        v62 = (const char *)sub_57A6D0(v57);
        v114 = atof(v62) * 0.0099999998;
        v60 = sub_4D1B00(&dword_7D3C50) * 0.050000001 + v114;
      }
      else
      {
        v60 = 1.0;
      }
    }
    else
    {
      v60 = 0.0;
    }
    *(float *)(this + 23992) = v60;
  }
  *(float *)(this + 24004) = (22.0 - *(float *)(this + 24008) * 0.67000002) * 0.045454547;
  v63 = (22.0 - *(float *)(this + 24008)) * 0.045454547;
  *(float *)(this + 24008) = v63;
  v64 = dword_768684;
  v84 = dword_768684;
  if ( *(_DWORD *)dword_7689CC == 8 )
  {
    v64 = dword_7687EC;
LABEL_119:
    v84 = v64;
    goto LABEL_120;
  }
  if ( *(_DWORD *)dword_7689CC == 4 )
  {
    v64 = dword_768834;
    goto LABEL_119;
  }
LABEL_120:
  if ( v64 < 100 )
    *(float *)(this + 24008) = (double)v84 * 0.0099999998 * ((double)v84 * 0.0099999998) * v63;
  v65 = sub_57A720(aCrash);
  if ( v65 )
  {
    v66 = (const char *)sub_57A6D0(v65);
    *(float *)(this + 24012) = atof(v66);
  }
  v67 = sub_57A720(aCompletedlaps);
  if ( v67 )
  {
    v68 = (const char *)sub_57A6D0(v67);
    *(float *)(this + 23972) = atof(v68);
  }
LABEL_126:
  v69 = 1.0 - (1.0 - *(float *)(this + 23968)) * flt_6290B0;
  *(float *)(this + 23996) = v69;
  if ( dword_7D7928 == 1 )
  {
    *(float *)(this + 23996) = v69;
    *(float *)(this + 23924) = flt_6290B4;
    v70 = (flt_6290B4 + 3.0) * 0.25;
    if ( v70 > 1.05 )
      v70 = 1.05;
    *(float *)(this + 23996) = v70 * *(float *)(this + 23996);
  }
  else
  {
    if ( flt_6290B4 <= 1.05 )
      v71 = flt_6290B4;
    else
      v71 = 1.05;
    *(float *)(this + 23996) = v71 * v69;
  }
  v72 = *(float *)(this + 23996) - 1.0;
  *(_DWORD *)(this + 24284) = *(_DWORD *)(this + 23924);
  if ( v72 < 0.0 )
    v72 = 0.0;
  *(float *)(this + 24176) = v72;
  if ( *(float *)(this + 23996) <= 1.0 )
    v73 = *(float *)(this + 23996);
  else
    v73 = 1.0;
  *(float *)(this + 23996) = v73;
  if ( dword_7D7928 == 1 )
  {
    if ( dword_75CBB0 == 7 )
      *(float *)(this + 23924) = *(float *)(this + 23924) - 0.029999999;
  }
  else if ( dword_75CBB0 == 7 )
  {
    *(float *)(this + 23996) = v73 - 0.029999999;
  }
  if ( *(float *)(this + 23924) <= 1.0 )
    v74 = *(float *)(this + 23924);
  else
    v74 = 1.0;
  *(float *)(this + 23924) = v74;
  v75 = *(float *)(this + 23996);
  *(float *)(this + 24168) = *(float *)(this + 23996);
  *(float *)(this + 24172) = v75;
  if ( dword_75CBB0 == 7 && *(_DWORD *)dword_766B6C == 3 && sub_57AE50(aSeasonraces) )
  {
    v76 = dword_766594;
    if ( !dword_766594 )
      v76 = &byte_629120;
    if ( sub_57A720(v76) )
    {
      if ( sub_57A720(aRaceevents) )
      {
        if ( sub_57A720((char *)(*(_DWORD *)(this + 80) + 24772)) )
        {
          v86 = 0;
          v77 = sub_57A700(0);
          if ( v77 )
          {
            v85 = (_DWORD *)(this + 21212);
            do
            {
              *v85 = 6;
              if ( !strcmp((const char *)sub_57A6D0(v77), aStall) )
              {
                *v85 = 4;
              }
              else if ( !strcmp((const char *)sub_57A6D0(v77), aStallDns) )
              {
                *v85 = 5;
              }
              else if ( !strcmp((const char *)sub_57A6D0(v77), aSuspension_0) )
              {
                *v85 = 3;
              }
              else if ( !strcmp((const char *)sub_57A6D0(v77), aBrakes) )
              {
                *v85 = 1;
              }
              else if ( !strcmp((const char *)sub_57A6D0(v77), aEngine_0) )
              {
                *v85 = 0;
              }
              else if ( !strcmp((const char *)sub_57A6D0(v77), aGearbox) )
              {
                *v85 = 2;
              }
              else if ( *v85 == 6 )
              {
                *(v85 - 1) = -1;
                goto LABEL_172;
              }
              v78 = (const char *)sub_57A6C0(v77);
              v115 = strtol(v78, 0, 10);
              *(v85 - 1) = v115;
              *(v85 - 1) = (__int64)((double)v115 / flt_7D74C4);
LABEL_172:
              ++v86;
              v85 += 2;
              v77 = sub_57A700(v86);
            }
            while ( v77 );
          }
        }
      }
    }
  }
  if ( sub_57AE50(aSeasonraces) )
  {
    v79 = dword_766594;
    if ( !dword_766594 )
      v79 = &byte_629120;
    if ( sub_57A720(v79) )
    {
      v80 = sub_57A720(aTireweartotake);
      if ( v80 )
      {
        v81 = (const char *)sub_57A6D0(v80);
        *(float *)(this + 23928) = atof(v81);
      }
      v82 = sub_57A720(aQualifying);
      if ( v82 )
      {
        v83 = (const char *)sub_57A6D0(v82);
        flt_5FD200 = atof(v83) * 0.25;
      }
    }
  }
}
