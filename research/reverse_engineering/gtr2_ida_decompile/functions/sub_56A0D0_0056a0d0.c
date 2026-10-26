char __thiscall sub_56A0D0(float *this, float a2, int a3)
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
  int v19; // eax
  int v20; // ecx
  float *v21; // edx
  int v22; // ecx
  int v23; // eax
  int v24; // eax
  int v25; // ebx
  int v26; // edx
  int v27; // eax
  int v28; // edx
  int v29; // esi
  int v30; // edi
  int v31; // eax
  int v32; // ebp
  _DWORD *v33; // ecx
  int v34; // eax
  int v35; // esi
  int v36; // eax
  int v37; // esi
  int v38; // ebx
  int v39; // edi
  int v40; // ecx
  float *v41; // edx
  float *v42; // ecx
  double v43; // st7
  double v44; // st6
  long double v45; // st6
  long double v46; // st6
  double v47; // st7
  float v48; // esi
  float v49; // eax
  float v50; // ecx
  int v51; // esi
  int v52; // eax
  int v53; // esi
  int v54; // ebx
  int v55; // edi
  int v56; // edx
  float *v57; // ecx
  float *v58; // edx
  double v59; // st6
  double v60; // st5
  double v61; // st3
  long double v62; // st4
  long double v63; // st7
  long double v64; // st6
  long double v65; // st7
  double v66; // st6
  long double v67; // st5
  long double v68; // st5
  int v69; // ecx
  int v70; // eax
  int v71; // ecx
  int v72; // ebx
  int v73; // esi
  float *v74; // edx
  float *v75; // edi
  double v76; // st6
  double v77; // st5
  double v78; // st3
  double v79; // st4
  double v80; // st7
  double v81; // st6
  double v82; // st5
  double v83; // st7
  long double v84; // st7
  long double v85; // st7
  double v86; // st6
  long double v87; // st7
  int v88; // ecx
  int v89; // edx
  int v90; // edx
  int v91; // eax
  int v92; // edx
  int v93; // ecx
  int v94; // ebx
  double v95; // st7
  int v96; // ecx
  int v97; // esi
  unsigned __int16 **v98; // edi
  unsigned __int16 *v99; // ecx
  int v100; // edx
  int v101; // eax
  float v102; // ebp
  int v103; // eax
  float v104; // ebp
  float *v105; // eax
  float v106; // ebp
  int v107; // eax
  float v108; // ecx
  int v109; // eax
  float v110; // edx
  float v111; // eax
  long double v112; // st7
  long double v113; // st7
  int v115; // [esp+0h] [ebp-D4h]
  int v116; // [esp+0h] [ebp-D4h]
  int v117; // [esp+0h] [ebp-D4h]
  float v118; // [esp+0h] [ebp-D4h]
  int v119; // [esp+0h] [ebp-D4h]
  int v120; // [esp+4h] [ebp-D0h]
  int v121; // [esp+4h] [ebp-D0h]
  int v122; // [esp+4h] [ebp-D0h]
  float v123; // [esp+4h] [ebp-D0h]
  int v124; // [esp+4h] [ebp-D0h]
  int v125; // [esp+4h] [ebp-D0h]
  char v126; // [esp+Bh] [ebp-C9h]
  float v127; // [esp+Ch] [ebp-C8h]
  float v128; // [esp+Ch] [ebp-C8h]
  float v129; // [esp+Ch] [ebp-C8h]
  int v130; // [esp+Ch] [ebp-C8h]
  float v131; // [esp+10h] [ebp-C4h]
  float v132; // [esp+10h] [ebp-C4h]
  float v133; // [esp+14h] [ebp-C0h]
  float v134; // [esp+14h] [ebp-C0h]
  float v135; // [esp+18h] [ebp-BCh]
  float v136; // [esp+18h] [ebp-BCh]
  float v137; // [esp+18h] [ebp-BCh]
  float v138; // [esp+1Ch] [ebp-B8h]
  int v139; // [esp+1Ch] [ebp-B8h]
  int v140; // [esp+20h] [ebp-B4h]
  int v141; // [esp+20h] [ebp-B4h]
  int v142; // [esp+24h] [ebp-B0h]
  int v143; // [esp+24h] [ebp-B0h]
  int v144; // [esp+28h] [ebp-ACh]
  float v145; // [esp+38h] [ebp-9Ch]
  float v146; // [esp+3Ch] [ebp-98h]
  float v147; // [esp+40h] [ebp-94h]
  float v148; // [esp+40h] [ebp-94h]
  float v149; // [esp+44h] [ebp-90h]
  float v150; // [esp+48h] [ebp-8Ch]
  float v151; // [esp+4Ch] [ebp-88h]
  float v153; // [esp+54h] [ebp-80h]
  float v154; // [esp+54h] [ebp-80h]
  float v155; // [esp+64h] [ebp-70h] BYREF
  float v156; // [esp+68h] [ebp-6Ch]
  float v157; // [esp+6Ch] [ebp-68h]
  float v158; // [esp+70h] [ebp-64h]
  float v159; // [esp+74h] [ebp-60h]
  float v160; // [esp+78h] [ebp-5Ch]
  float v161; // [esp+7Ch] [ebp-58h]
  float v162; // [esp+80h] [ebp-54h]
  float v163; // [esp+84h] [ebp-50h]
  float v164; // [esp+88h] [ebp-4Ch]
  float v165; // [esp+8Ch] [ebp-48h]
  float v166; // [esp+90h] [ebp-44h]
  float v167; // [esp+94h] [ebp-40h]
  float v168; // [esp+98h] [ebp-3Ch]
  float v169; // [esp+9Ch] [ebp-38h]
  float v170; // [esp+A0h] [ebp-34h]
  float v171; // [esp+A4h] [ebp-30h]
  float v172; // [esp+A8h] [ebp-2Ch]
  float v173; // [esp+ACh] [ebp-28h]
  float v174[3]; // [esp+B0h] [ebp-24h] BYREF
  float v175[3]; // [esp+BCh] [ebp-18h] BYREF
  float v176[3]; // [esp+C8h] [ebp-Ch] BYREF

  v3 = this;
  v126 = 0;
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
        while ( v20 < *((_DWORD *)v3 + 6) );
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
      while ( v5 < *((_DWORD *)v3 + 6) );
    }
    if ( v5 == v4 )
    {
      LOBYTE(v7) = LOBYTE(a2);
      *v3 = a2;
      return v7;
    }
    v120 = 0;
    if ( *((int *)v3 + 2) > 0 )
    {
      v115 = 0;
      do
      {
        v8 = *((_DWORD *)v3 + 3);
        v9 = *(_DWORD *)(v8 + v115 + 4);
        v10 = v115 + v8;
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
        v17 = ++v120 < *((_DWORD *)v3 + 2);
        v115 += 12;
      }
      while ( v17 );
    }
    v18 = 0;
    v126 = 1;
  }
  *v3 = a2;
  v142 = v18;
  if ( v18 < *((_DWORD *)v3 + 6) )
  {
    v22 = (int)&v3[9 * v18 + 14];
    v144 = v22;
    do
    {
      if ( *(float *)(v22 - 24) <= (double)a2 )
      {
        v23 = *(_DWORD *)(v22 - 28);
        v126 = 1;
        if ( v23 )
        {
          v24 = v23 - 1;
          if ( v24 )
          {
            if ( v24 == 1 )
            {
              v121 = 0;
              if ( *((int *)v3 + 2) > 0 )
              {
                v25 = 0;
                do
                {
                  v26 = *((_DWORD *)v3 + 3);
                  v27 = *(_DWORD *)(v26 + v25 + 4);
                  v28 = v25 + v26;
                  v29 = 0;
                  if ( v27 > 0 )
                  {
                    v30 = 0;
                    do
                    {
                      v31 = *(_DWORD *)(v28 + 8);
                      v32 = *(_DWORD *)(v31 + v30 + 4);
                      v33 = *(_DWORD **)(v31 + v30);
                      v34 = v30 + v31;
                      *v33 = v32;
                      v33[1] = *(_DWORD *)(v34 + 8);
                      v33[2] = *(_DWORD *)(v34 + 12);
                      ++v29;
                      v30 += 64;
                    }
                    while ( v29 < *(_DWORD *)(v28 + 4) );
                    v3 = this;
                  }
                  v25 += 12;
                  ++v121;
                }
                while ( v121 < *((_DWORD *)v3 + 2) );
              }
            }
          }
          else
          {
            v122 = 0;
            if ( *((int *)v3 + 2) > 0 )
            {
              v116 = 0;
              do
              {
                v35 = *((_DWORD *)v3 + 3);
                v36 = *(_DWORD *)(v35 + v116 + 4);
                v37 = v116 + v35;
                v38 = 0;
                if ( v36 > 0 )
                {
                  v39 = 0;
                  do
                  {
                    v40 = *(_DWORD *)(v37 + 8);
                    v41 = *(float **)(v40 + v39);
                    v42 = (float *)(v39 + v40);
                    v145 = *v41 - v42[1];
                    v43 = v41[1] - v42[2];
                    v44 = v41[2] - v42[3];
                    v147 = v44;
                    v45 = v44 * v147 + v43 * v43 + v145 * v145;
                    if ( v45 > 0.0056250002 )
                    {
                      v46 = 0.075000003 / sqrt(v45);
                      v146 = v46 * v43;
                      v148 = v46 * v147;
                      *v41 = v145 * v46 + v42[1];
                      v41[1] = v146 + v42[2];
                      v41[2] = v148 + v42[3];
                    }
                    ++v38;
                    v39 += 64;
                  }
                  while ( v38 < *(_DWORD *)(v37 + 4) );
                }
                v17 = ++v122 < *((_DWORD *)v3 + 2);
                v116 += 12;
              }
              while ( v17 );
            }
          }
        }
        else
        {
          v47 = *(float *)(v22 + 4) + 0.12;
          v171 = *(float *)(v22 - 20);
          v48 = *(float *)(v22 - 20 + 4);
          v173 = *(float *)(v22 - 20 + 8);
          v158 = *(float *)(v22 - 8);
          v123 = v47 * v47;
          v49 = *(float *)(v22 - 4);
          v50 = *(float *)v22;
          v159 = v49;
          v160 = v50;
          v167 = v158;
          v169 = v50;
          v17 = *((_DWORD *)v3 + 2) <= 0;
          v172 = v48;
          v168 = v49;
          v140 = 0;
          v127 = 1.0 / v47;
          if ( !v17 )
          {
            v117 = 0;
            do
            {
              v51 = *((_DWORD *)v3 + 3);
              v52 = *(_DWORD *)(v51 + v117 + 4);
              v53 = v117 + v51;
              v54 = 0;
              if ( v52 > 0 )
              {
                v55 = 0;
                do
                {
                  v56 = *(_DWORD *)(v53 + 8);
                  v57 = *(float **)(v56 + v55);
                  v58 = (float *)(v55 + v56);
                  v59 = v57[1] - v172;
                  v60 = v57[2] - v173;
                  v61 = *v57 - v171;
                  v62 = v60 * v60 + v59 * v59 + v61 * v61;
                  if ( v62 < v123 )
                  {
                    v63 = 1.0 - sqrt(v62) * v127;
                    v64 = v167 * v63 + *v57;
                    *v57 = v64;
                    v170 = v168 * v63 + v57[1];
                    v57[1] = v170;
                    v153 = v169 * v63 + v57[2];
                    v57[2] = v153;
                    v65 = v64 - v58[1];
                    v156 = v170 - v58[2];
                    v66 = v153 - v58[3];
                    v67 = v66 * v66 + v156 * v156 + v65 * v65;
                    if ( v67 > v58[4] )
                    {
                      v68 = sqrt(v58[4] / v67);
                      *v57 = v68 * v65 + v58[1];
                      v57[1] = v156 * v68 + v58[2];
                      v57[2] = v68 * v66 + v58[3];
                    }
                  }
                  ++v54;
                  v55 += 64;
                }
                while ( v54 < *(_DWORD *)(v53 + 4) );
              }
              v17 = ++v140 < *((_DWORD *)v3 + 2);
              v117 += 12;
            }
            while ( v17 );
          }
          v141 = 0;
          if ( *((int *)v3 + 4) > 0 )
          {
            v124 = 0;
            do
            {
              v69 = *((_DWORD *)v3 + 5);
              v70 = *(_DWORD *)(v69 + v124 + 16);
              v71 = v124 + v69;
              v72 = 0;
              if ( v70 > 0 )
              {
                do
                {
                  v73 = *(_DWORD *)(*(_DWORD *)(v71 + 20) + 4 * v72);
                  v74 = *(float **)v73;
                  v75 = (float *)(v73 + 4);
                  if ( **(float **)v73 != *(float *)(v73 + 4)
                    || v74[1] != *(float *)(v73 + 8)
                    || v74[2] != *(float *)(v73 + 12) )
                  {
                    v76 = v74[4] - *(float *)(v71 + 4);
                    v77 = v74[5] - *(float *)(v71 + 8);
                    v78 = v74[3] - *(float *)v71;
                    v79 = v77 * v77 + v76 * v76 + v78 * v78;
                    if ( v79 > 0.0 && v79 < *(float *)(v71 + 12) )
                    {
                      v149 = *v75;
                      v150 = *(float *)(v73 + 8);
                      v131 = *v74 - *v75;
                      v151 = *(float *)(v73 + 12);
                      v138 = *(float *)(v71 + 12);
                      v133 = v74[1] - v150;
                      v135 = v74[2] - v151;
                      v80 = *v75 - *(float *)v71;
                      v161 = v80;
                      v81 = v150 - *(float *)(v71 + 4);
                      v162 = v81;
                      v154 = v151 - *(float *)(v71 + 8);
                      v163 = v154;
                      v82 = v161 * v161 + v154 * v154 + v162 * v162;
                      if ( v82 < v138 )
                        v138 = v82;
                      v164 = v80;
                      v166 = v154;
                      v165 = v81;
                      v128 = v135 * v135 + v133 * v133 + v131 * v131;
                      v83 = v154 * v135 + v165 * v133 + v164 * v131;
                      v118 = v83 + v83;
                      if ( v128 != 0.0 )
                      {
                        v84 = v118 * v118 - (v154 * v154 + v165 * v165 + v164 * v164 - v138) * v128 * 4.0;
                        if ( v84 >= 0.0 )
                        {
                          v85 = sqrt(v84);
                          v86 = -1.0 / (v128 + v128);
                          v129 = (v85 + v118) * v86;
                          v87 = v86 * (v118 - v85);
                          if ( fabs(v87) > fabs(v129) )
                            v87 = v129;
                          *v74 = v131 * v87 + v149;
                          v74[1] = v133 * v87 + v150;
                          v74[2] = v87 * v135 + v151;
                        }
                      }
                    }
                  }
                  ++v72;
                }
                while ( v72 < *(_DWORD *)(v71 + 16) );
              }
              v17 = ++v141 < *((_DWORD *)v3 + 4);
              v124 += 24;
            }
            while ( v17 );
          }
        }
        v22 = v144;
      }
      v22 += 36;
      v17 = ++v142 < *((_DWORD *)v3 + 6);
      v144 = v22;
    }
    while ( v17 );
  }
  LOBYTE(v7) = v126;
  if ( v126 )
  {
    v7 = *((_DWORD *)v3 + 2);
    v88 = 0;
    if ( v7 > 0 )
    {
      v89 = 0;
      do
      {
        **(_DWORD **)(v89 + *((_DWORD *)v3 + 3)) &= ~0x800u;
        v7 = *((_DWORD *)v3 + 2);
        ++v88;
        v89 += 12;
      }
      while ( v88 < v7 );
    }
    v119 = 0;
    if ( *((int *)v3 + 2) > 0 )
    {
      v130 = 0;
      do
      {
        v90 = *((_DWORD *)v3 + 3);
        v91 = *(_DWORD *)(v90 + v130 + 4);
        v92 = v130 + v90;
        v143 = v92;
        v139 = 0;
        if ( v91 > 0 )
        {
          v125 = 0;
          do
          {
            v93 = *(_DWORD *)(v92 + 8);
            v94 = *(_DWORD *)(v93 + v125);
            v95 = *(float *)(v93 + v125 + 4);
            v96 = v125 + v93;
            if ( *(float *)v94 == v95
              && *(float *)(v94 + 4) == *(float *)(v96 + 8)
              && *(float *)(v94 + 8) == *(float *)(v96 + 12) )
            {
              *(_DWORD *)(v94 + 24) = *(_DWORD *)(v96 + 32);
              *(_DWORD *)(v94 + 12) = *(_DWORD *)(v96 + 20);
              *(_DWORD *)(v94 + 16) = *(_DWORD *)(v96 + 24);
              *(_DWORD *)(v94 + 20) = *(_DWORD *)(v96 + 28);
            }
            else
            {
              v132 = 0.0;
              v134 = 0.0;
              v136 = 0.0;
              *(_DWORD *)(v94 + 24) = (unsigned int)&unk_A0A0A0 | *(_DWORD *)(v96 + 32) & 0xFFA0A0A0;
              v97 = 0;
              v98 = (unsigned __int16 **)(v96 + 36);
              do
              {
                v99 = *v98;
                if ( !*v98 )
                  break;
                v100 = *(_DWORD *)(*((_DWORD *)v99 + 2) + 32);
                v101 = *v99 << 6;
                v102 = *(float *)(v101 + v100);
                v103 = v100 + v101;
                v174[0] = v102;
                v104 = *(float *)(v103 + 4);
                v174[2] = *(float *)(v103 + 8);
                v105 = (float *)(v100 + (v99[1] << 6));
                v174[1] = v104;
                v175[0] = *v105;
                v106 = v105[1];
                v175[2] = v105[2];
                v107 = v99[2] << 6;
                v108 = *(float *)(v107 + v100);
                v109 = v100 + v107;
                v110 = *(float *)(v109 + 4);
                v111 = *(float *)(v109 + 8);
                v176[0] = v108;
                v176[1] = v110;
                v175[1] = v106;
                v176[2] = v111;
                sub_568D90(v174, v175, v176, &v155);
                v3 = this;
                v92 = v143;
                ++v97;
                ++v98;
                v132 = v155 + v132;
                v134 = v156 + v134;
                v136 = v157 + v136;
              }
              while ( v97 < 7 );
              v112 = sqrt(v136 * v136 + v134 * v134 + v132 * v132);
              if ( v112 > 0.0 )
              {
                v113 = 1.0 / v112;
                v137 = v113 * v136;
                *(float *)(v94 + 20) = v137;
                *(float *)(v94 + 12) = v132 * v113;
                *(float *)(v94 + 16) = v113 * v134;
              }
            }
            v17 = ++v139 < *(_DWORD *)(v92 + 4);
            v125 += 64;
          }
          while ( v17 );
        }
        LOBYTE(v7) = v119 + 1;
        v17 = ++v119 < *((_DWORD *)v3 + 2);
        v130 += 12;
      }
      while ( v17 );
    }
  }
  return v7;
}
