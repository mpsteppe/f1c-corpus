void __thiscall sub_422260(int this)
{
  double v2; // st7
  int v3; // ebp
  int v4; // edi
  int v5; // edx
  int v6; // eax
  int v7; // ecx
  int v8; // edi
  int v9; // edx
  float v10; // eax
  int v11; // ecx
  float v12; // edi
  int v13; // ecx
  int v14; // ecx
  double v15; // st7
  int v16; // eax
  double v17; // st5
  double v18; // st4
  long double v19; // st5
  long double v20; // st7
  unsigned __int8 v22; // c0
  unsigned __int8 v23; // c2
  int v24; // eax
  double v25; // st6
  double v26; // st4
  long double v27; // st5
  int v28; // ecx
  long double v29; // st6
  int v30; // ecx
  double v32; // st6
  unsigned __int8 v33; // c0
  unsigned __int8 v34; // c3
  double v35; // st6
  double v37; // st7
  unsigned __int8 v38; // c0
  unsigned __int8 v39; // c3
  double v40; // st7
  int v41; // ecx
  long double v42; // st7
  int v43; // eax
  double v44; // st6
  double v45; // st4
  long double v46; // st6
  double v48; // st6
  unsigned __int8 v49; // c0
  unsigned __int8 v50; // c3
  double v51; // st6
  double v53; // st6
  unsigned __int8 v54; // c0
  unsigned __int8 v55; // c3
  double v56; // st6
  double v57; // st5
  int v58; // eax
  double v59; // st7
  double v60; // st6
  float *v61; // eax
  double v62; // st6
  double v63; // st5
  double v64; // st4
  double v65; // st2
  double v66; // st7
  float v67; // edx
  float v68; // ebx
  float v69; // eax
  double v70; // st7
  double v71; // st7
  double v72; // st6
  long double v73; // st6
  int v74; // eax
  int v75; // eax
  double v76; // st7
  double v77; // st7
  double v78; // st7
  double v79; // st7
  int v80; // eax
  int v81; // ecx
  float *v82; // ebp
  int v83; // eax
  int v84; // ecx
  int v85; // ecx
  double v86; // st7
  double v87; // st7
  float *v88; // eax
  double v89; // st7
  double v90; // st7
  float *v91; // eax
  double v92; // st7
  double v93; // st7
  int v94; // edx
  double v95; // st7
  bool v96; // zf
  double v97; // st6
  int v98; // eax
  double v99; // st7
  int v100; // ecx
  double v101; // st7
  int v102; // ecx
  double v103; // st7
  char v104; // al
  double v105; // st7
  int v106; // [esp+0h] [ebp-88h]
  float v107; // [esp+0h] [ebp-88h]
  float v108; // [esp+0h] [ebp-88h]
  float v109; // [esp+4h] [ebp-84h]
  char v110; // [esp+1Eh] [ebp-6Ah]
  char v111; // [esp+1Fh] [ebp-69h]
  float v112; // [esp+20h] [ebp-68h]
  float v113; // [esp+20h] [ebp-68h]
  float v114; // [esp+24h] [ebp-64h]
  float v115; // [esp+28h] [ebp-60h]
  float v116; // [esp+2Ch] [ebp-5Ch]
  float v117; // [esp+2Ch] [ebp-5Ch]
  int v118; // [esp+30h] [ebp-58h]
  int v119; // [esp+34h] [ebp-54h]
  float v120; // [esp+38h] [ebp-50h]
  int v121; // [esp+3Ch] [ebp-4Ch] BYREF
  int v122; // [esp+40h] [ebp-48h] BYREF
  float v123; // [esp+44h] [ebp-44h]
  float v124; // [esp+48h] [ebp-40h]
  float v125; // [esp+4Ch] [ebp-3Ch]
  float v126; // [esp+50h] [ebp-38h]
  float v127; // [esp+54h] [ebp-34h]
  float v128[2]; // [esp+58h] [ebp-30h] BYREF
  float v129; // [esp+60h] [ebp-28h]
  _BYTE v130[12]; // [esp+64h] [ebp-24h] BYREF
  _BYTE v131[12]; // [esp+70h] [ebp-18h] BYREF
  _BYTE v132[12]; // [esp+7Ch] [ebp-Ch] BYREF

  v2 = *(float *)(this + 24712);
  v3 = *(_DWORD *)(this + 24020);
  v126 = *(float *)(this + 23748);
  v118 = 0;
  v110 = 1;
  v119 = v3;
  if ( v2 <= 0.0 )
    goto LABEL_6;
  if ( *(_DWORD *)(this + 24708) != 11 )
  {
    if ( v3 != 11 )
      goto LABEL_6;
    v3 = *(_DWORD *)(this + 24708);
  }
  v119 = v3;
LABEL_6:
  if ( *(float *)(this + 24136) <= (double)*(float *)(this + 23852) )
    v125 = *(float *)(this + 23956);
  else
    v125 = 0.64999998;
  v4 = sub_4040B0(&flt_628F60, (float *)(this + 17604), *(_DWORD **)(this + 23432), *(_DWORD *)(this + 24244), 0.0, 0);
  v120 = *(float *)(v4 + 104);
  if ( !(unsigned __int8)sub_4EED40(*(_DWORD *)(this + 80))
    || *(_DWORD *)(this + 16584) != 1
    || dword_7D7928 != 2
    || dword_6290F4 < 2 )
  {
    v13 = *(_DWORD *)(this + 24240);
    if ( !v13 )
      goto LABEL_18;
    v6 = *(_DWORD *)(v4 + 300);
    if ( !v6 || v13 != *(_DWORD *)(v6 + 328) )
      goto LABEL_18;
LABEL_32:
    v8 = v6;
    goto LABEL_19;
  }
  v5 = *(_DWORD *)(this + 24240);
  if ( v5 )
  {
    v6 = *(_DWORD *)(v4 + 300);
    if ( v6 )
    {
      v7 = *(_DWORD *)(v6 + 328);
      if ( v5 == v7 || v7 == 3 && dword_75CBB4 != 8 )
        goto LABEL_32;
    }
  }
LABEL_18:
  v8 = *(_DWORD *)(v4 + 296);
LABEL_19:
  if ( !(unsigned __int8)sub_4EED40(*(_DWORD *)(this + 80))
    || *(_DWORD *)(this + 16584) != 1
    || dword_7D7928 != 2
    || dword_6290F4 < 2 )
  {
    v14 = *(_DWORD *)(this + 24240);
    if ( !v14 )
      goto LABEL_37;
    v10 = *(float *)(v8 + 300);
    if ( v10 == 0.0 || v14 != *(_DWORD *)(LODWORD(v10) + 328) )
      goto LABEL_37;
    goto LABEL_36;
  }
  v9 = *(_DWORD *)(this + 24240);
  if ( !v9 )
    goto LABEL_37;
  v10 = *(float *)(v8 + 300);
  if ( v10 == 0.0 )
    goto LABEL_37;
  v11 = *(_DWORD *)(LODWORD(v10) + 328);
  if ( v9 == v11 )
  {
LABEL_36:
    v12 = v10;
    goto LABEL_38;
  }
  if ( v11 != 3 || dword_75CBB4 == 8 )
  {
LABEL_37:
    v12 = *(float *)(v8 + 296);
    goto LABEL_38;
  }
  v12 = *(float *)(v8 + 300);
LABEL_38:
  if ( *(_DWORD *)(this + 23752) && *(_DWORD *)(this + 23608) )
  {
    sub_51C1E0(v128, v130);
    v15 = sub_528B60(*(_DWORD *)(this + 23608));
    v116 = v15;
    if ( v15 < 50.0 )
    {
      v15 = v116;
      if ( v116 > -10.0 )
      {
        v16 = *(_DWORD *)(*(_DWORD *)(this + 23608) + 300);
        v17 = v129 - *(float *)(v16 + 204);
        v18 = v128[0] - *(float *)(v16 + 196);
        v19 = sqrt(v17 * v17 + v18 * v18);
        v15 = v19;
        if ( v116 >= v19 )
          v116 = v19;
      }
    }
    sub_514440(*(float *)(this + 23764), v116, 0.40000001);
    if ( v15 > 0.0 )
    {
      *(_DWORD *)(this + 23752) = 0;
      *(float *)(this + 24212) = v116;
    }
    if ( *(float *)(this + 23724) == 0.0 && *(_DWORD *)(*(_DWORD *)(this + 23608) + 300) )
    {
      v20 = sub_528B60(*(_DWORD *)(this + 23608));
      v116 = v20;
      if ( v22 | v23 && v20 > -10.0 )
      {
        v24 = *(_DWORD *)(*(_DWORD *)(this + 23608) + 300);
        v25 = v129 - *(float *)(v24 + 204);
        v26 = v128[0] - *(float *)(v24 + 196);
        v27 = sqrt(v25 * v25 + v26 * v26);
        v116 = v27;
        v20 = v27;
      }
      v28 = *(_DWORD *)(this + 23608);
      v29 = sqrt(*(float *)(v28 + 24) * *(float *)(v28 + 24)) + 19.0;
      if ( v29 > 28.0 )
        v29 = 28.0;
      if ( v20 >= 0.5 * v29 )
      {
        if ( v20 >= v29 )
        {
          if ( v20 < v29 + v29 )
          {
            v37 = *(float *)(v28 + 24);
            if ( v38 | v39 )
              v40 = v37 + 5.0;
            else
              v40 = v37 - 5.0;
            *(_DWORD *)(this + 52) = 0;
            *(float *)(this + 23724) = v40;
          }
        }
        else
        {
          *(_DWORD *)(this + 23752) = 0;
          v32 = *(float *)(v28 + 24);
          if ( v33 | v34 )
            v35 = v32 + 3.0;
          else
            v35 = v32 - 3.0;
          *(float *)(this + 23724) = v35;
          *(float *)(this + 24212) = v20;
        }
      }
      else
      {
        *(_DWORD *)(this + 23752) = 0;
        v30 = *(_DWORD *)(v28 + 24);
        *(float *)(this + 24212) = v20;
        *(_DWORD *)(this + 23724) = v30;
      }
    }
  }
  if ( *(_DWORD *)(this + 23608) && *(float *)(this + 24212) != 0.0 )
  {
    sub_51C1E0(v128, v130);
    v41 = *(_DWORD *)(this + 23608);
    if ( *(_DWORD *)(v41 + 300) )
    {
      v42 = sub_528B60(*(_DWORD *)(this + 23608));
      if ( v42 < 50.0 && v42 > -10.0 )
      {
        v43 = *(_DWORD *)(*(_DWORD *)(this + 23608) + 300);
        v44 = v129 - *(float *)(v43 + 204);
        v45 = v128[0] - *(float *)(v43 + 196);
        v42 = sqrt(v44 * v44 + v45 * v45);
      }
      v41 = *(_DWORD *)(this + 23608);
      v46 = sqrt(*(float *)(v41 + 24) * *(float *)(v41 + 24)) * 1.2 + 17.0;
      if ( v46 > 28.0 )
        v46 = 28.0;
      if ( v42 >= 0.5 * v46 )
      {
        if ( v42 >= v46 )
        {
          if ( v42 < 1.34 * v46 )
          {
            v53 = *(float *)(v41 + 24);
            if ( v54 | v55 )
              v56 = v53 + 5.0;
            else
              v56 = v53 - 5.0;
            *(_DWORD *)(this + 52) = 0;
            *(float *)(this + 23724) = v56;
          }
        }
        else
        {
          *(_DWORD *)(this + 23752) = 0;
          v48 = *(float *)(v41 + 24);
          if ( v49 | v50 )
            v51 = v48 + 3.0;
          else
            v51 = v48 - 3.0;
          *(float *)(this + 23724) = v51;
        }
      }
      else
      {
        *(_DWORD *)(this + 23828) = 0;
        *(_DWORD *)(this + 23752) = 0;
        *(_DWORD *)(this + 23724) = *(_DWORD *)(v41 + 24);
      }
    }
    else
    {
      v42 = v116;
    }
    v57 = v129 - *(float *)(v41 + 8);
    v112 = sqrt(v57 * v57 + (v128[0] - *(float *)v41) * (v128[0] - *(float *)v41));
    if ( *(_DWORD *)(v41 + 300) )
    {
      v42 = sub_528B60(v41);
      if ( v42 < 50.0 )
      {
        if ( v42 <= 0.0 )
        {
LABEL_94:
          if ( (unsigned __int8)sub_4EED40(*(_DWORD *)(this + 80)) && *(float *)(this + 23764) > 6.0 )
          {
            *(_DWORD *)(this + 24212) = 0;
            *(_DWORD *)(this + 23752) = 0;
            *(_DWORD *)(this + 23724) = 0;
          }
          else
          {
            *(_DWORD *)(this + 23752) = 0;
            *(_DWORD *)(this + 23756) = 0;
            sub_51F0F0(this + 84);
            *(_DWORD *)(this + 23596) = 0;
            if ( dword_75CBB0 == 7 )
            {
              *(_DWORD *)(this + 24024) = 1;
            }
            else if ( dword_75CBB0 == 5 )
            {
              *(_DWORD *)(this + 24024) = 3;
            }
            else
            {
              *(_DWORD *)(this + 24024) = 0;
            }
            *(_DWORD *)(this + 24244) = *(_DWORD *)(this + 23612);
            v106 = *(_DWORD *)(this + 80);
            *(_DWORD *)(this + 24212) = 0;
            *(_DWORD *)(this + 23748) = 1065353216;
            *(_DWORD *)(this + 23740) = 0;
            *(_DWORD *)(this + 24240) = 0;
            *(_DWORD *)(this + 23724) = 0;
            sub_4F8F50(v106, v132, v131);
            sub_51BE20(v132, v131);
            *(_BYTE *)(this + 23872) = 1;
            *(_DWORD *)(this + 24688) = 1;
            sub_4EEC20(0);
            sub_51F3D0(0, 2);
          }
          return;
        }
        v58 = *(_DWORD *)(this + 23608);
        v59 = *(float *)v58 - v128[0];
        v60 = *(float *)(v58 + 8);
        v61 = *(float **)(v58 + 300);
        v62 = v60 - v129;
        v63 = v61[3];
        v64 = v61[5];
        v65 = v61[4];
        v123 = v61[3];
        v126 = sqrt(v123 * v123 + v65 * v65 + v64 * v64);
        if ( v126 <= 0.1 )
          v42 = v64 * v62 + v63 * v59;
        else
          v42 = v64 * (1.0 / v126) * v62 + v63 * (1.0 / v126) * v59;
      }
    }
    else if ( v112 <= (double)*(float *)(this + 24212) )
    {
      goto LABEL_97;
    }
    if ( v42 <= 0.0 )
      goto LABEL_94;
LABEL_97:
    if ( v112 > 0.5 )
    {
      v66 = v112 * 0.30000001;
      v67 = *(float *)(this + 23764);
      v109 = v66;
      *(float *)(this + 24212) = v112;
      sub_514440(v67, v109, 0.69999999);
      if ( v66 <= 0.0 )
      {
        *(_DWORD *)(this + 23748) = 0;
        if ( sub_514000(this + 84) >= 0.40000001 )
          *(float *)(this + 23740) = sub_514000(this + 84);
        else
          *(float *)(this + 23740) = 0.40000001;
      }
      else
      {
        *(_DWORD *)(this + 23740) = 0;
        *(_DWORD *)(this + 23748) = 1065353216;
      }
      return;
    }
    goto LABEL_94;
  }
  v68 = 0.0;
  v123 = 0.0;
  v121 = 1065353216;
  v122 = -1082130432;
  switch ( v3 )
  {
    case 7:
      v69 = *(float *)(LODWORD(v12) + 240);
      break;
    case 8:
      v114 = *(float *)(LODWORD(v12) + 236);
      goto LABEL_119;
    case 6:
      v114 = 1.0 / (1.0 / *(float *)(LODWORD(v12) + 240) - 3.5);
      goto LABEL_119;
    case 9:
      v114 = *(float *)(LODWORD(v12) + 236);
      goto LABEL_119;
    default:
      v69 = *(float *)(LODWORD(v12) + 164);
      break;
  }
  v114 = v69;
LABEL_119:
  v70 = *(float *)(LODWORD(v12) + 336);
  if ( v70 <= 0.0 )
    sub_514590(*(float *)(LODWORD(v12) + 168), LODWORD(v12) + 172, v114, 16.0);
  else
    v70 = (*(float *)(this + 24176) + *(float *)(this + 24172)) * *(float *)(LODWORD(v12) + 336);
  v71 = v70 + *(float *)(this + 8);
  if ( v71 >= *(float *)(LODWORD(v12) + 188) )
    v72 = *(float *)(LODWORD(v12) + 188);
  else
    v72 = v71;
  *(float *)(this + 24720) = v72;
  if ( v72 > 80.0 )
    *(_DWORD *)(this + 24720) = 1117782016;
  v73 = *(float *)(*(_DWORD *)(this + 23448) + 260) - *(float *)(*(_DWORD *)(this + 23432) + 260);
  if ( fabs(v73) >= 3.141592653589793 )
  {
    if ( v73 >= 0.0 )
      v73 = v73 - 6.283185307179586;
    else
      v73 = v73 + 6.283185307179586;
  }
  if ( v73 <= 0.050000001 )
  {
    v75 = *(_DWORD *)(this + 52);
    if ( v73 >= -0.050000001 )
    {
      if ( v75 <= 0 )
        v74 = v75 + 1 > 0 ? 0 : v75 + 1;
      else
        v74 = v75 - 1 < 0 ? 0 : v75 - 1;
    }
    else
    {
      v74 = v75 - 1;
      if ( v74 < -20 )
        v74 = -20;
    }
  }
  else
  {
    v74 = *(_DWORD *)(this + 52) + 1;
    if ( v74 > 20 )
      v74 = 20;
  }
  *(_DWORD *)(this + 52) = v74;
  if ( 1.02 * v71 > *(float *)(this + 23764) && 0.98000002 * v71 < *(float *)(this + 23764) )
  {
    if ( *(float *)(this + 24028) < v71 )
      v71 = *(float *)(this + 24028);
    *(float *)(this + 24028) = v71;
  }
  if ( *(float *)(LODWORD(v12) + 96) > (double)*(float *)(this + 23852) && *(_DWORD *)(LODWORD(v12) + 344) )
  {
    v76 = sub_42B090(*(_DWORD *)(this + 24020), LODWORD(v12));
    v107 = v76;
    sub_529BA0(v107, (int)&v121, (int)&v122);
    v113 = v76 + 1.0;
  }
  else
  {
    v113 = 3.4028235e38;
  }
  v77 = *(float *)(LODWORD(v12) + 336);
  if ( v77 <= 0.0 )
  {
    sub_514590(*(float *)(LODWORD(v12) + 168), LODWORD(v12) + 172, v114, 16.0);
    v79 = v77 * *(float *)(this + 24168) + *(float *)(this + 8);
    if ( v79 <= v113 )
    {
      sub_514590(*(float *)(LODWORD(v12) + 168), LODWORD(v12) + 172, v114, 16.0);
      v113 = v79 * *(float *)(this + 24168) + *(float *)(this + 8);
    }
    v68 = v123;
  }
  else
  {
    v78 = (*(float *)(this + 24176) + *(float *)(this + 24172)) * *(float *)(LODWORD(v12) + 336) + *(float *)(this + 8);
    if ( v113 >= v78 )
      v113 = v78;
  }
  v80 = this + 23432;
  v115 = *(float *)(this + 23764);
  if ( LODWORD(v12) != *(_DWORD *)(this + 23432) )
  {
    v81 = 0;
    do
    {
      *(float *)(v80 + 80) = v115;
      ++v81;
      v80 += 4;
    }
    while ( v81 < 20 && LODWORD(v12) != *(_DWORD *)v80 );
    v118 = v81;
  }
  *(_DWORD *)(this + 23596) = 0;
  *(_DWORD *)(this + 23604) = 1176255488;
  v111 = 0;
  *(_BYTE *)(this + 57) = 0;
  if ( v115 > 10.0 )
  {
    v82 = (float *)(this + 4 * v118 + 23512);
    while ( 1 )
    {
      if ( v115 >= (double)v113 )
      {
        if ( v68 == 0.0 )
        {
          if ( *(float *)(this + 60) >= (double)*(float *)(this + 23852) )
          {
            *(float *)(this + 23604) = v113;
          }
          else
          {
            v101 = *(float *)(this + 23852) + 1.0;
            *(float *)(this + 23604) = v113;
            *(float *)(this + 24724) = v101;
          }
        }
        else
        {
          v98 = v121;
          v99 = *(float *)(this + 23852) + 2.0;
          v100 = v122;
          *(float *)(this + 23600) = v68;
          *(_DWORD *)(this + 24732) = v98;
          *(float *)(this + 60) = v99;
          *(_DWORD *)(this + 24736) = v100;
        }
        *(float *)(this + 23596) = v12;
        goto LABEL_224;
      }
      v120 = v120 + *(float *)(LODWORD(v12) + 104);
      if ( v111 )
        v123 = v123 - *(float *)(LODWORD(v12) + 104);
      v83 = *(_DWORD *)(this + 24240);
      if ( v83 )
      {
        v84 = *(_DWORD *)(LODWORD(v12) + 300);
        if ( v84 )
        {
          if ( v83 == *(_DWORD *)(v84 + 328) )
            break;
        }
      }
      v88 = *(float **)(LODWORD(v12) + 296);
      if ( !v88 )
        goto LABEL_172;
      v85 = v119;
      if ( v119 == 11 )
      {
        v114 = v88[41];
        v12 = *(float *)(LODWORD(v12) + 296);
      }
      else if ( v119 == 8 )
      {
        v114 = v88[59];
        v12 = *(float *)(LODWORD(v12) + 296);
      }
      else if ( v119 == 6 )
      {
        v12 = *(float *)(LODWORD(v12) + 296);
        v114 = 1.0 / (1.0 / v88[60] - 3.5);
      }
      else
      {
        if ( v119 == 9 )
          v114 = v88[59];
        else
          v114 = v88[60];
        v12 = *(float *)(LODWORD(v12) + 296);
      }
LABEL_173:
      if ( v12 == 0.0 )
        goto LABEL_224;
      v86 = *(float *)(LODWORD(v12) + 336);
      if ( v86 <= 0.0 )
      {
        sub_514590(*(float *)(LODWORD(v12) + 168), LODWORD(v12) + 172, v114, 16.0);
        v87 = v86 * *(float *)(this + 24168) + *(float *)(this + 8);
      }
      else
      {
        v113 = (*(float *)(this + 24176) + *(float *)(this + 24172)) * *(float *)(LODWORD(v12) + 336)
             + *(float *)(this + 8);
        if ( v85 == 11 )
          goto LABEL_194;
        if ( v85 == 8 )
        {
          v87 = flt_628F68 + v113;
        }
        else
        {
          v89 = flt_628F6C;
          if ( v85 == 6 )
            v89 = v89 - 1.0;
          v87 = v89 + v113;
        }
      }
      v113 = v87;
LABEL_194:
      v90 = 3.4028235e38;
      v68 = 0.0;
      if ( !*(_DWORD *)(*(_DWORD *)(this + 80) + 25300)
        && *(float *)(LODWORD(v12) + 96) > (double)*(float *)(this + 23852) )
      {
        v91 = *(float **)(LODWORD(v12) + 344);
        if ( v91 == &flt_7D74DC )
        {
          v113 = *v91;
        }
        else
        {
          v68 = v12;
          v92 = sub_42D720(LODWORD(v12));
          v108 = v92;
          sub_529BA0(v108, (int)&v121, (int)&v122);
          v96 = *(_DWORD *)(this + 23600) == LODWORD(v12);
          v124 = v92 + 1.0;
          if ( v96 )
          {
            v93 = *(float *)(this + 23852) + 2.0;
            v94 = v122;
            *(_DWORD *)(this + 24732) = v121;
            *(_DWORD *)(this + 24736) = v94;
            *(float *)(this + 60) = v93;
          }
          v95 = v124 - *(float *)(this + 23764);
          if ( v95 >= -0.1 )
          {
            v90 = (float)3.4028235e38;
          }
          else
          {
            v111 = 1;
            v123 = -1.0 / v95 * v120 * v124;
            v90 = v95 / (v123 + v120) * v120 + *(float *)(this + 23764);
          }
        }
      }
      if ( flt_628F78 > v90 )
        v90 = flt_628F78;
      if ( v90 < v113 )
        v113 = v90;
      v96 = v110 == 0;
      if ( v110 )
      {
        sub_5149B0(v115, *(float *)(LODWORD(v12) + 168), LODWORD(v12) + 172, *(float *)(LODWORD(v12) + 164));
        v127 = v90;
        v96 = v110 == 0;
      }
      v110 = v96;
      if ( v115 <= 1.0 )
        goto LABEL_213;
      v97 = v113 * 0.014285714;
      if ( v97 > 1.0 )
        v97 = 1.0;
      v115 = v115 - v97 * (*(float *)(LODWORD(v12) + 104) / v115) * v127 * v125;
      if ( v115 < 0.5 )
LABEL_213:
        v115 = 0.0;
      if ( v118 < 20 )
      {
        *v82 = v115;
        ++v118;
        ++v82;
      }
      if ( v115 <= 10.0 )
        goto LABEL_224;
    }
    if ( *(float *)(LODWORD(v12) + 256) == 0.0 )
      v114 = 3.4028235e38;
    else
      v114 = *(float *)(v84 + 240);
    v12 = *(float *)(LODWORD(v12) + 300);
LABEL_172:
    v85 = v119;
    goto LABEL_173;
  }
LABEL_224:
  if ( *(float *)(this + 60) < (double)*(float *)(this + 23852) )
  {
    *(_DWORD *)(this + 23600) = 0;
    *(_DWORD *)(this + 24732) = 1065353216;
    *(_DWORD *)(this + 24736) = -1082130432;
  }
  if ( *(float *)(this + 24724) > (double)*(float *)(this + 23852) )
    *(_DWORD *)(this + 24720) = *(_DWORD *)(this + 23764);
  *(float *)(this + 24720) = *(float *)(this + 24720) * 0.92000002;
  if ( v115 <= 10.0 )
  {
    v104 = *(_BYTE *)(this + 24208);
    *(_DWORD *)(this + 23748) = 0;
    if ( v104 )
    {
      if ( *(_DWORD *)(this + 23832) )
        v105 = sub_514000(this + 84);
      else
        v105 = 1.0;
    }
    else if ( *(float *)(this + 23764) <= 25.0 )
    {
      v105 = 0.80000001;
    }
    else
    {
      v105 = 0.89999998;
    }
    v117 = *(float *)(this + 24168) * 0.0099999998;
    if ( *(float *)(this + 24140) > (double)*(float *)(this + 23852) && v105 - *(float *)(this + 23740) > v117 )
      v105 = v117 + *(float *)(this + 23740);
    *(float *)(this + 23740) = v105;
  }
  else
  {
    v102 = this + 84;
    if ( v115 - v113 >= 0.5 )
    {
      v103 = sub_5140D0(v102) * *(float *)(this + 23940);
      if ( v103 - v126 > 0.2 )
        v103 = v126 + 0.2;
      *(float *)(this + 23748) = v103;
      *(_DWORD *)(this + 23740) = 0;
    }
    else
    {
      *(float *)(this + 23740) = sub_513FA0(v102);
    }
  }
}
