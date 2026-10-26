char __thiscall sub_4DF110(float *this, float a2, int a3)
{
  float *v3; // ebp
  int v4; // esi
  int v5; // ecx
  float *v6; // edx
  int v7; // eax
  int v8; // edx
  int v9; // eax
  int v10; // edx
  int v11; // esi
  int v12; // edi
  int v13; // eax
  int v14; // ebx
  _DWORD *v15; // ecx
  int v16; // eax
  bool v17; // cc
  int v18; // eax
  int v19; // esi
  int v20; // ecx
  float *v21; // edx
  float *v22; // ecx
  int v23; // eax
  int v24; // esi
  int v25; // eax
  int v26; // edx
  int v27; // eax
  int v28; // edx
  int v29; // edi
  int v30; // eax
  int v31; // ebx
  _DWORD *v32; // ecx
  int v33; // eax
  int v34; // esi
  int v35; // eax
  int v36; // esi
  int v37; // ebx
  int v38; // edi
  int v39; // ecx
  float *v40; // edx
  float *v41; // ecx
  double v42; // st7
  double v43; // st6
  long double v44; // st6
  long double v45; // st6
  double v46; // st7
  float v47; // edx
  int v48; // esi
  int v49; // eax
  int v50; // esi
  int v51; // ebx
  int v52; // edi
  int v53; // edx
  float *v54; // ecx
  float *v55; // edx
  double v56; // st6
  double v57; // st5
  double v58; // st3
  long double v59; // st4
  long double v60; // st7
  long double v61; // st6
  long double v62; // st7
  double v63; // st6
  long double v64; // st5
  long double v65; // st5
  int v66; // ecx
  int v67; // eax
  int v68; // ecx
  int v69; // ebx
  int v70; // esi
  float *v71; // edx
  float *v72; // edi
  double v73; // st6
  double v74; // st5
  double v75; // st3
  double v76; // st4
  double v77; // st7
  double v78; // st6
  double v79; // st4
  double v80; // st3
  double v81; // rt1
  double v82; // st6
  double v83; // st7
  double v84; // st5
  long double v85; // st5
  long double v86; // st7
  double v87; // st6
  long double v88; // st7
  int v89; // edx
  int v90; // ecx
  int v91; // ebp
  int v92; // ecx
  int v93; // ebx
  int v94; // edi
  float *v95; // esi
  float *v96; // eax
  long double v97; // st7
  long double v98; // st7
  int v100; // [esp+0h] [ebp-B0h]
  int v101; // [esp+0h] [ebp-B0h]
  int v102; // [esp+0h] [ebp-B0h]
  int v103; // [esp+0h] [ebp-B0h]
  float v104; // [esp+0h] [ebp-B0h]
  int v105; // [esp+0h] [ebp-B0h]
  int v106; // [esp+4h] [ebp-ACh]
  int v107; // [esp+4h] [ebp-ACh]
  int v108; // [esp+4h] [ebp-ACh]
  float v109; // [esp+4h] [ebp-ACh]
  int v110; // [esp+4h] [ebp-ACh]
  int *v111; // [esp+4h] [ebp-ACh]
  char v112; // [esp+Bh] [ebp-A5h]
  float v113; // [esp+Ch] [ebp-A4h]
  float v114; // [esp+Ch] [ebp-A4h]
  float v115; // [esp+Ch] [ebp-A4h]
  int v116; // [esp+Ch] [ebp-A4h]
  float v117; // [esp+10h] [ebp-A0h]
  float v118; // [esp+10h] [ebp-A0h]
  float v119; // [esp+14h] [ebp-9Ch]
  float v120; // [esp+14h] [ebp-9Ch]
  float v121; // [esp+18h] [ebp-98h]
  float v122; // [esp+18h] [ebp-98h]
  float v123; // [esp+18h] [ebp-98h]
  int v124; // [esp+1Ch] [ebp-94h]
  int v125; // [esp+1Ch] [ebp-94h]
  int v126; // [esp+1Ch] [ebp-94h]
  float *v127; // [esp+20h] [ebp-90h]
  int v128; // [esp+20h] [ebp-90h]
  float v129; // [esp+24h] [ebp-8Ch]
  int v130; // [esp+24h] [ebp-8Ch]
  int v131; // [esp+28h] [ebp-88h]
  int v132; // [esp+28h] [ebp-88h]
  float v133; // [esp+2Ch] [ebp-84h]
  float v134; // [esp+2Ch] [ebp-84h]
  float v135; // [esp+30h] [ebp-80h]
  float v136; // [esp+34h] [ebp-7Ch]
  float v137; // [esp+38h] [ebp-78h]
  float v138; // [esp+3Ch] [ebp-74h]
  float v139; // [esp+40h] [ebp-70h]
  float v140; // [esp+44h] [ebp-6Ch]
  float v141; // [esp+44h] [ebp-6Ch]
  float v143[3]; // [esp+4Ch] [ebp-64h] BYREF
  float v144; // [esp+58h] [ebp-58h]
  float v145; // [esp+5Ch] [ebp-54h]
  float v146; // [esp+60h] [ebp-50h]
  float v147; // [esp+64h] [ebp-4Ch]
  float v148; // [esp+68h] [ebp-48h]
  float v149; // [esp+6Ch] [ebp-44h]
  float v150; // [esp+70h] [ebp-40h]
  float v151; // [esp+78h] [ebp-38h]
  float v152; // [esp+80h] [ebp-30h]
  float v153[2]; // [esp+8Ch] [ebp-24h] BYREF
  char v154; // [esp+94h] [ebp-1Ch] BYREF
  float v155[3]; // [esp+98h] [ebp-18h] BYREF
  float v156[3]; // [esp+A4h] [ebp-Ch] BYREF

  v3 = this;
  v112 = 0;
  if ( a2 >= (double)*this )
  {
    v18 = a3;
    if ( a3 == -1 )
    {
      v19 = *((_DWORD *)this + 6);
      v20 = 0;
      if ( v19 > 0 )
      {
        v21 = v3 + 8;
        do
        {
          if ( *v21 > (double)*v3 )
            break;
          ++v20;
          v21 += 9;
        }
        while ( v20 < v19 );
      }
      v18 = v20;
    }
  }
  else
  {
    v4 = *((_DWORD *)this + 6);
    v5 = 0;
    if ( v4 > 0 )
    {
      v6 = v3 + 8;
      do
      {
        if ( *v6 > (double)a2 && *v6 <= (double)*v3 )
          break;
        ++v5;
        v6 += 9;
      }
      while ( v5 < v4 );
    }
    if ( v5 == v4 )
    {
      LOBYTE(v7) = LOBYTE(a2);
      *v3 = a2;
      return v7;
    }
    v106 = 0;
    if ( *((int *)v3 + 2) > 0 )
    {
      v100 = 0;
      do
      {
        v8 = *((_DWORD *)v3 + 3);
        v9 = *(_DWORD *)(v8 + v100 + 4);
        v10 = v100 + v8;
        v11 = 0;
        if ( v9 > 0 )
        {
          v12 = 0;
          do
          {
            v13 = *(_DWORD *)(v10 + 8);
            v14 = *(_DWORD *)(v13 + v12 + 4);
            v15 = *(_DWORD **)(v13 + v12);
            v16 = v12 + v13;
            *v15 = v14;
            v15[1] = *(_DWORD *)(v16 + 8);
            v15[2] = *(_DWORD *)(v16 + 12);
            ++v11;
            v12 += 64;
          }
          while ( v11 < *(_DWORD *)(v10 + 4) );
        }
        v17 = ++v106 < *((_DWORD *)v3 + 2);
        v100 += 12;
      }
      while ( v17 );
    }
    v18 = 0;
    v112 = 1;
  }
  *v3 = a2;
  v131 = v18;
  if ( v18 < *((_DWORD *)v3 + 6) )
  {
    v22 = &v3[9 * v18 + 14];
    v127 = v22;
    do
    {
      if ( *(v22 - 6) <= (double)a2 )
      {
        v23 = *((_DWORD *)v22 - 7);
        v24 = 0;
        v112 = 1;
        if ( v23 )
        {
          v25 = v23 - 1;
          if ( v25 )
          {
            if ( v25 == 1 )
            {
              v107 = 0;
              if ( *((int *)v3 + 2) > 0 )
              {
                v101 = 0;
                while ( 1 )
                {
                  v26 = *((_DWORD *)v3 + 3);
                  v27 = *(_DWORD *)(v26 + v101 + 4);
                  v28 = v101 + v26;
                  if ( v27 > 0 )
                  {
                    v29 = 0;
                    do
                    {
                      v30 = *(_DWORD *)(v28 + 8);
                      v31 = *(_DWORD *)(v30 + v29 + 4);
                      v32 = *(_DWORD **)(v30 + v29);
                      v33 = v29 + v30;
                      *v32 = v31;
                      v32[1] = *(_DWORD *)(v33 + 8);
                      v32[2] = *(_DWORD *)(v33 + 12);
                      ++v24;
                      v29 += 64;
                    }
                    while ( v24 < *(_DWORD *)(v28 + 4) );
                    v22 = v127;
                  }
                  v17 = ++v107 < *((_DWORD *)v3 + 2);
                  v101 += 12;
                  if ( !v17 )
                    break;
                  v24 = 0;
                }
                goto LABEL_73;
              }
            }
          }
          else
          {
            v108 = 0;
            if ( *((int *)v3 + 2) > 0 )
            {
              v102 = 0;
              do
              {
                v34 = *((_DWORD *)v3 + 3);
                v35 = *(_DWORD *)(v34 + v102 + 4);
                v36 = v102 + v34;
                v37 = 0;
                if ( v35 > 0 )
                {
                  v38 = 0;
                  do
                  {
                    v39 = *(_DWORD *)(v36 + 8);
                    v40 = *(float **)(v39 + v38);
                    v41 = (float *)(v38 + v39);
                    v138 = *v40 - v41[1];
                    v42 = v40[1] - v41[2];
                    v43 = v40[2] - v41[3];
                    v140 = v43;
                    v44 = v43 * v140 + v42 * v42 + v138 * v138;
                    if ( v44 > 0.0056250002 )
                    {
                      v45 = 0.075000003 / sqrt(v44);
                      v139 = v45 * v42;
                      v141 = v45 * v140;
                      *v40 = v138 * v45 + v41[1];
                      v40[1] = v139 + v41[2];
                      v40[2] = v141 + v41[3];
                    }
                    ++v37;
                    v38 += 64;
                  }
                  while ( v37 < *(_DWORD *)(v36 + 4) );
                }
                v17 = ++v108 < *((_DWORD *)v3 + 2);
                v102 += 12;
              }
              while ( v17 );
            }
          }
        }
        else
        {
          v46 = v22[1] + 0.12;
          v145 = *(v22 - 5);
          v47 = *(v22 - 3);
          v146 = *(v22 - 4);
          v109 = v46 * v46;
          v148 = *(v22 - 2);
          v150 = *v22;
          v17 = *((_DWORD *)v3 + 2) <= 0;
          v147 = v47;
          v149 = *(v22 - 1);
          v124 = 0;
          v113 = 1.0 / v46;
          if ( !v17 )
          {
            v103 = 0;
            do
            {
              v48 = *((_DWORD *)v3 + 3);
              v49 = *(_DWORD *)(v48 + v103 + 4);
              v50 = v103 + v48;
              v51 = 0;
              if ( v49 > 0 )
              {
                v52 = 0;
                do
                {
                  v53 = *(_DWORD *)(v50 + 8);
                  v54 = *(float **)(v53 + v52);
                  v55 = (float *)(v52 + v53);
                  v56 = v54[1] - v146;
                  v57 = v54[2] - v147;
                  v58 = *v54 - v145;
                  v59 = v57 * v57 + v56 * v56 + v58 * v58;
                  if ( v59 < v109 )
                  {
                    v60 = 1.0 - sqrt(v59) * v113;
                    v61 = v148 * v60 + *v54;
                    *v54 = v61;
                    v144 = v149 * v60 + v54[1];
                    v54[1] = v144;
                    v133 = v150 * v60 + v54[2];
                    v54[2] = v133;
                    v62 = v61 - v55[1];
                    v151 = v144 - v55[2];
                    v63 = v133 - v55[3];
                    v64 = v63 * v63 + v151 * v151 + v62 * v62;
                    if ( v64 > v55[4] )
                    {
                      v65 = sqrt(v55[4] / v64);
                      *v54 = v65 * v62 + v55[1];
                      v54[1] = v151 * v65 + v55[2];
                      v54[2] = v65 * v63 + v55[3];
                    }
                  }
                  ++v51;
                  v52 += 64;
                }
                while ( v51 < *(_DWORD *)(v50 + 4) );
              }
              v17 = ++v124 < *((_DWORD *)v3 + 2);
              v103 += 12;
            }
            while ( v17 );
          }
          v125 = 0;
          if ( *((int *)v3 + 4) > 0 )
          {
            v110 = 0;
            do
            {
              v66 = *((_DWORD *)v3 + 5);
              v67 = *(_DWORD *)(v66 + v110 + 16);
              v68 = v110 + v66;
              v69 = 0;
              if ( v67 > 0 )
              {
                do
                {
                  v70 = *(_DWORD *)(*(_DWORD *)(v68 + 20) + 4 * v69);
                  v71 = *(float **)v70;
                  v72 = (float *)(v70 + 4);
                  if ( **(float **)v70 != *(float *)(v70 + 4)
                    || v71[1] != *(float *)(v70 + 8)
                    || v71[2] != *(float *)(v70 + 12) )
                  {
                    v73 = v71[1] - *(float *)(v68 + 4);
                    v74 = v71[2] - *(float *)(v68 + 8);
                    v75 = *v71 - *(float *)v68;
                    v76 = v74 * v74 + v73 * v73 + v75 * v75;
                    if ( v76 > 0.0 && v76 < *(float *)(v68 + 12) )
                    {
                      v135 = *v72;
                      v136 = *(float *)(v70 + 8);
                      v117 = *v71 - *v72;
                      v137 = *(float *)(v70 + 12);
                      v129 = *(float *)(v68 + 12);
                      v119 = v71[1] - v136;
                      v121 = v71[2] - v137;
                      v77 = *v72 - *(float *)v68;
                      v152 = v77;
                      v78 = v136 - *(float *)(v68 + 4);
                      v79 = v137 - *(float *)(v68 + 8);
                      v134 = v79;
                      v80 = v152 * v152 + v79 * v79 + v78 * v78;
                      if ( v80 < v129 )
                        v129 = v80;
                      v81 = v78;
                      v82 = v77;
                      v83 = v81;
                      v143[0] = v82;
                      v114 = v121 * v121 + v119 * v119 + v117 * v117;
                      v84 = v121 * v134 + v81 * v119 + v143[0] * v117;
                      v104 = v84 + v84;
                      if ( v114 != 0.0 )
                      {
                        v85 = v104 * v104 - (v134 * v134 + v83 * v83 + v143[0] * v143[0] - v129) * v114 * 4.0;
                        if ( v85 >= 0.0 )
                        {
                          v86 = sqrt(v85);
                          v87 = -1.0 / (v114 + v114);
                          v115 = (v86 + v104) * v87;
                          v88 = v87 * (v104 - v86);
                          if ( fabs(v88) > fabs(v115) )
                            v88 = v115;
                          *v71 = v117 * v88 + v135;
                          v71[1] = v119 * v88 + v136;
                          v71[2] = v88 * v121 + v137;
                        }
                      }
                    }
                  }
                  ++v69;
                }
                while ( v69 < *(_DWORD *)(v68 + 16) );
              }
              v17 = ++v125 < *((_DWORD *)v3 + 4);
              v110 += 24;
            }
            while ( v17 );
          }
        }
        v22 = v127;
      }
LABEL_73:
      v22 += 9;
      v17 = ++v131 < *((_DWORD *)v3 + 6);
      v127 = v22;
    }
    while ( v17 );
  }
  LOBYTE(v7) = v112;
  if ( v112 )
  {
    v7 = *((_DWORD *)v3 + 2);
    v89 = 0;
    if ( v7 > 0 )
    {
      v7 = 0;
      do
      {
        *(_DWORD *)(*(_DWORD *)(*((_DWORD *)v3 + 3) + v7) + 20) &= 0xFEFFFFDF;
        *(_DWORD *)(*(_DWORD *)(*((_DWORD *)v3 + 3) + v7) + 20) |= 0x400000u;
        ++v89;
        v7 += 12;
      }
      while ( v89 < *((_DWORD *)v3 + 2) );
    }
    v126 = 0;
    if ( *((int *)v3 + 2) > 0 )
    {
      v130 = 0;
      while ( 1 )
      {
        v128 = v130 + *((_DWORD *)v3 + 3);
        v105 = 0;
        if ( *(int *)(v128 + 4) > 0 )
        {
          v116 = 0;
          do
          {
            v90 = *(_DWORD *)(v128 + 8);
            v91 = *(_DWORD *)(v90 + v116);
            v92 = v116 + v90;
            if ( *(float *)v91 == *(float *)(v92 + 4)
              && *(float *)(v91 + 4) == *(float *)(v92 + 8)
              && *(float *)(v91 + 8) == *(float *)(v92 + 12) )
            {
              *(_DWORD *)(v91 + 24) = *(_DWORD *)(v92 + 32);
              *(_DWORD *)(v91 + 12) = *(_DWORD *)(v92 + 20);
              *(_DWORD *)(v91 + 16) = *(_DWORD *)(v92 + 24);
              *(_DWORD *)(v91 + 20) = *(_DWORD *)(v92 + 28);
            }
            else
            {
              v118 = 0.0;
              v120 = 0.0;
              v122 = 0.0;
              *(_DWORD *)(v91 + 24) = 10526880;
              v132 = 0;
              v111 = (int *)(v92 + 36);
              do
              {
                v93 = *v111;
                if ( !*v111 )
                  break;
                v94 = 0;
                v95 = (float *)&v154;
                do
                {
                  v96 = (float *)sub_4DE5D0(v93, v94);
                  *(v95 - 2) = *v96;
                  ++v94;
                  *(v95 - 1) = v96[1];
                  v95 += 3;
                  *(v95 - 3) = v96[2];
                }
                while ( v94 < 3 );
                sub_4DD9F0(v153, v155, v156, v143);
                v118 = v143[0] + v118;
                v17 = ++v132 < 7;
                ++v111;
                v120 = v143[1] + v120;
                v122 = v143[2] + v122;
              }
              while ( v17 );
              v97 = sqrt(v122 * v122 + v120 * v120 + v118 * v118);
              if ( v97 > 0.0 )
              {
                v98 = 1.0 / v97;
                v123 = v98 * v122;
                *(float *)(v91 + 20) = v123;
                *(float *)(v91 + 12) = v118 * v98;
                *(float *)(v91 + 16) = v98 * v120;
              }
            }
            v17 = ++v105 < *(_DWORD *)(v128 + 4);
            v116 += 64;
          }
          while ( v17 );
        }
        v130 += 12;
        LOBYTE(v7) = ++v126;
        if ( v126 >= *((_DWORD *)this + 2) )
          break;
        v3 = this;
      }
    }
  }
  return v7;
}
