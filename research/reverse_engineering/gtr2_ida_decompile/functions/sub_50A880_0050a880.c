int __thiscall sub_50A880(int this)
{
  int v2; // eax
  int v3; // edx
  int v4; // ecx
  int v5; // eax
  int v6; // edx
  int v7; // ecx
  int v8; // eax
  int v9; // edx
  int v10; // ecx
  int v11; // eax
  int v12; // edx
  int v13; // ecx
  double v14; // st7
  float v15; // eax
  double v16; // st7
  float v17; // eax
  int v18; // eax
  int v19; // edx
  int v20; // eax
  int v21; // edx
  int v22; // eax
  int v23; // edx
  int v24; // eax
  int v25; // edx
  double v26; // st7
  float v27; // edx
  double v28; // st7
  int result; // eax
  int v30; // eax
  int v31; // edx
  int v32; // eax
  int v33; // edx
  int v34; // eax
  int v35; // edx
  int v36; // eax
  int v37; // edx
  int v38; // eax
  int v39; // edx
  int v40; // eax
  int v41; // edx
  int v42; // eax
  int v43; // edx
  int v44; // eax
  int v45; // edx
  int v46; // eax
  int v47; // edx
  int v48; // eax
  int v49; // ecx
  int v50; // eax
  int v51; // edx
  int v52; // eax
  int v53; // ecx
  int v54; // eax
  int v55; // edx
  int v56; // eax
  int v57; // ecx
  int v58; // eax
  int v59; // edx
  int v60; // ecx
  int v61; // edx
  int v62; // ecx
  float v63; // [esp+8h] [ebp-4h]

  if ( *(_DWORD *)(this + 10248) == 1 )
  {
    v18 = *(_DWORD *)(this + 4048);
    v19 = *(_DWORD *)(this + 4052);
    *(_DWORD *)(this + 4040) = 1;
    if ( v18 <= 1 )
    {
      if ( v19 < 1 )
        *(_DWORD *)(this + 4040) = v19;
    }
    else
    {
      *(_DWORD *)(this + 4040) = v18;
    }
    v20 = *(_DWORD *)(this + 4084);
    v21 = *(_DWORD *)(this + 4088);
    *(_DWORD *)(this + 4076) = 1;
    if ( v20 <= 1 )
    {
      if ( v21 < 1 )
        *(_DWORD *)(this + 4076) = v21;
    }
    else
    {
      *(_DWORD *)(this + 4076) = v20;
    }
    v22 = *(_DWORD *)(this + 4120);
    v23 = *(_DWORD *)(this + 4124);
    *(_DWORD *)(this + 4112) = 1;
    if ( v22 <= 1 )
    {
      if ( v23 < 1 )
        *(_DWORD *)(this + 4112) = v23;
    }
    else
    {
      *(_DWORD *)(this + 4112) = v22;
    }
    v24 = *(_DWORD *)(this + 10712);
    v25 = *(_DWORD *)(this + 10716);
    *(_DWORD *)(this + 10704) = 1;
    if ( v24 <= 1 )
    {
      if ( v25 < 1 )
        *(_DWORD *)(this + 10704) = v25;
    }
    else
    {
      *(_DWORD *)(this + 10704) = v24;
    }
    v26 = *(float *)(this + 13252);
    v27 = *(float *)(this + 13256);
    *(_DWORD *)(this + 13244) = 1028443341;
    if ( v26 <= *(float *)(this + 13244) )
    {
      if ( *(float *)(this + 13244) > (double)v27 )
        *(float *)(this + 13244) = v27;
    }
    else
    {
      *(float *)(this + 13244) = v26;
    }
    v28 = *(float *)(this + 13288);
    *(_DWORD *)(this + 13280) = 1028443341;
    v63 = *(float *)(this + 13292);
    if ( v28 <= *(float *)(this + 13280) )
    {
      if ( *(float *)(this + 13280) > (double)v63 )
        *(float *)(this + 13280) = v63;
    }
    else
    {
      *(float *)(this + 13280) = v28;
    }
  }
  else if ( *(_DWORD *)(this + 10248) == 2 )
  {
    v2 = *(_DWORD *)(this + 4048);
    v3 = *(_DWORD *)(this + 4052);
    *(_DWORD *)(this + 4040) = 2;
    v4 = *(_DWORD *)(this + 4040);
    if ( v4 >= v2 )
    {
      if ( v4 > v3 )
        *(_DWORD *)(this + 4040) = v3;
    }
    else
    {
      *(_DWORD *)(this + 4040) = v2;
    }
    v5 = *(_DWORD *)(this + 4084);
    v6 = *(_DWORD *)(this + 4088);
    *(_DWORD *)(this + 4076) = 2;
    v7 = *(_DWORD *)(this + 4076);
    if ( v7 >= v5 )
    {
      if ( v7 > v6 )
        *(_DWORD *)(this + 4076) = v6;
    }
    else
    {
      *(_DWORD *)(this + 4076) = v5;
    }
    v8 = *(_DWORD *)(this + 4120);
    v9 = *(_DWORD *)(this + 4124);
    *(_DWORD *)(this + 4112) = 2;
    v10 = *(_DWORD *)(this + 4112);
    if ( v10 >= v8 )
    {
      if ( v10 > v9 )
        *(_DWORD *)(this + 4112) = v9;
    }
    else
    {
      *(_DWORD *)(this + 4112) = v8;
    }
    v11 = *(_DWORD *)(this + 10712);
    v12 = *(_DWORD *)(this + 10716);
    *(_DWORD *)(this + 10704) = 0;
    v13 = *(_DWORD *)(this + 10704);
    if ( v13 >= v11 )
    {
      if ( v13 > v12 )
        *(_DWORD *)(this + 10704) = v12;
    }
    else
    {
      *(_DWORD *)(this + 10704) = v11;
    }
    v14 = *(float *)(this + 13252);
    v15 = *(float *)(this + 13256);
    *(_DWORD *)(this + 13244) = 1056964608;
    if ( v14 <= *(float *)(this + 13244) )
    {
      if ( *(float *)(this + 13244) > (double)v15 )
        *(float *)(this + 13244) = v15;
    }
    else
    {
      *(float *)(this + 13244) = v14;
    }
    v16 = *(float *)(this + 13288);
    v17 = *(float *)(this + 13292);
    *(_DWORD *)(this + 13280) = 1056964608;
    if ( v16 <= *(float *)(this + 13280) )
    {
      if ( *(float *)(this + 13280) > (double)v17 )
        *(float *)(this + 13280) = v17;
    }
    else
    {
      *(float *)(this + 13280) = v16;
    }
  }
  result = *(_DWORD *)(this + 10248);
  if ( result )
  {
    v30 = *(_DWORD *)(this + 14596);
    v31 = *(_DWORD *)(this + 14600);
    *(_DWORD *)(this + 14588) = 1;
    if ( v30 <= 1 )
    {
      if ( v31 < 1 )
        *(_DWORD *)(this + 14588) = v31;
    }
    else
    {
      *(_DWORD *)(this + 14588) = v30;
    }
    v32 = *(_DWORD *)(this + 14632);
    v33 = *(_DWORD *)(this + 14636);
    *(_DWORD *)(this + 14624) = 1;
    if ( v32 <= 1 )
    {
      if ( v33 < 1 )
        *(_DWORD *)(this + 14624) = v33;
    }
    else
    {
      *(_DWORD *)(this + 14624) = v32;
    }
    v34 = *(_DWORD *)(this + 14668);
    v35 = *(_DWORD *)(this + 14672);
    *(_DWORD *)(this + 14660) = 1;
    if ( v34 <= 1 )
    {
      if ( v35 < 1 )
        *(_DWORD *)(this + 14660) = v35;
    }
    else
    {
      *(_DWORD *)(this + 14660) = v34;
    }
    v36 = *(_DWORD *)(this + 14812);
    v37 = *(_DWORD *)(this + 14816);
    *(_DWORD *)(this + 14804) = 1;
    if ( v36 <= 1 )
    {
      if ( v37 < 1 )
        *(_DWORD *)(this + 14804) = v37;
    }
    else
    {
      *(_DWORD *)(this + 14804) = v36;
    }
    v38 = *(_DWORD *)(this + 14920);
    v39 = *(_DWORD *)(this + 14924);
    *(_DWORD *)(this + 14912) = 1;
    if ( v38 <= 1 )
    {
      if ( v39 < 1 )
        *(_DWORD *)(this + 14912) = v39;
    }
    else
    {
      *(_DWORD *)(this + 14912) = v38;
    }
    v40 = *(_DWORD *)(this + 14956);
    v41 = *(_DWORD *)(this + 14960);
    *(_DWORD *)(this + 14948) = 1;
    if ( v40 <= 1 )
    {
      if ( v41 < 1 )
        *(_DWORD *)(this + 14948) = v41;
    }
    else
    {
      *(_DWORD *)(this + 14948) = v40;
    }
    v42 = *(_DWORD *)(this + 14992);
    v43 = *(_DWORD *)(this + 14996);
    *(_DWORD *)(this + 14984) = 1;
    if ( v42 <= 1 )
    {
      if ( v43 < 1 )
        *(_DWORD *)(this + 14984) = v43;
    }
    else
    {
      *(_DWORD *)(this + 14984) = v42;
    }
    v44 = *(_DWORD *)(this + 15136);
    v45 = *(_DWORD *)(this + 15140);
    *(_DWORD *)(this + 15128) = 1;
    if ( v44 <= 1 )
    {
      if ( v45 < 1 )
        *(_DWORD *)(this + 15128) = v45;
    }
    else
    {
      *(_DWORD *)(this + 15128) = v44;
    }
    v46 = sub_41ADF0();
    v47 = *(_DWORD *)(this + 13928);
    *(_DWORD *)(this + 13916) = v46 - 1;
    v48 = *(_DWORD *)(this + 13924);
    v49 = *(_DWORD *)(this + 13916);
    if ( v49 >= v48 )
    {
      if ( v49 > v47 )
        *(_DWORD *)(this + 13916) = v47;
    }
    else
    {
      *(_DWORD *)(this + 13916) = v48;
    }
    v50 = sub_41ADF0();
    v51 = *(_DWORD *)(this + 13964);
    *(_DWORD *)(this + 13952) = v50 - 1;
    v52 = *(_DWORD *)(this + 13960);
    v53 = *(_DWORD *)(this + 13952);
    if ( v53 >= v52 )
    {
      if ( v53 > v51 )
        *(_DWORD *)(this + 13952) = v51;
    }
    else
    {
      *(_DWORD *)(this + 13952) = v52;
    }
    v54 = sub_41ADF0();
    v55 = *(_DWORD *)(this + 14000);
    *(_DWORD *)(this + 13988) = v54 - 1;
    v56 = *(_DWORD *)(this + 13996);
    v57 = *(_DWORD *)(this + 13988);
    if ( v57 >= v56 )
    {
      if ( v57 > v55 )
        *(_DWORD *)(this + 13988) = v55;
    }
    else
    {
      *(_DWORD *)(this + 13988) = v56;
    }
    v58 = *(_DWORD *)(this + 14140);
    v59 = *(_DWORD *)(this + 14144);
    *(_DWORD *)(this + 14132) = 0;
    v60 = *(_DWORD *)(this + 14132);
    if ( v60 >= v58 )
    {
      if ( v60 > v59 )
        *(_DWORD *)(this + 14132) = v59;
    }
    else
    {
      *(_DWORD *)(this + 14132) = v58;
    }
    result = *(_DWORD *)(this + 10784);
    v61 = *(_DWORD *)(this + 10788);
    *(_DWORD *)(this + 10776) = 105;
    v62 = *(_DWORD *)(this + 10776);
    if ( v62 >= result )
    {
      if ( v62 > v61 )
        *(_DWORD *)(this + 10776) = v61;
    }
    else
    {
      *(_DWORD *)(this + 10776) = result;
    }
  }
  return result;
}
