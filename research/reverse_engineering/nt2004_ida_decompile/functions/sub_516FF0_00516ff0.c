void __thiscall sub_516FF0(int this)
{
  _BYTE *v2; // eax
  int v3; // ecx
  char *v4; // ecx
  int v5; // ebp
  char v6; // bl
  char v7; // dl
  char *v8; // eax
  char *v9; // eax
  int v10; // ecx
  int v11; // ecx
  double v12; // st7
  double v13; // st6
  float *v14; // edx
  int v15; // esi
  double v16; // st7
  float *v17; // eax
  int v18; // edx
  int v19; // eax
  int v20; // esi
  int v21; // eax
  double v22; // st7
  int v23; // ecx
  double v24; // st7
  int v25; // edx
  int v26; // eax
  int v27; // ecx
  double v28; // st7
  int v29; // ecx
  double v30; // st7
  double v31; // st6
  double v32; // st7
  double v33; // st7
  double v34; // st7
  int v35; // ebx
  unsigned __int16 *v36; // edx
  double v37; // st7
  double v38; // st6
  double v39; // st5
  long double v40; // st7
  long double v41; // st7
  long double v42; // st7
  long double v43; // st7
  int v44; // ebp
  int i; // ecx
  float *v46; // eax
  double v47; // st6
  double v48; // st6
  double v49; // st7
  double v50; // st6
  double v51; // st5
  double v52; // st5
  double v53; // st5
  double v54; // st5
  int v55; // ebx
  float v56; // edx
  float v57; // eax
  int v58; // ecx
  double v59; // st7
  double v60; // st7
  double v61; // st7
  double v62; // st7
  double v63; // st7
  int v64; // ebp
  char v65; // al
  char v66; // al
  char v67; // al
  double v68; // st7
  unsigned __int8 v70; // c0
  unsigned __int8 v71; // c3
  double v72; // st7
  double v73; // st7
  double v74; // st7
  int v75; // eax
  double v76; // st6
  double v77; // st5
  int v78; // eax
  double v79; // st7
  double v80; // st7
  double v81; // st6
  double v82; // st5
  int v83; // ebx
  float *v84; // esi
  float v85; // eax
  double v86; // st7
  _DWORD *v87; // ecx
  float *v88; // eax
  double v89; // st7
  long double v90; // st7
  int v91; // esi
  float *v92; // edx
  int v93; // [esp+0h] [ebp-138h]
  float v94; // [esp+4h] [ebp-134h]
  float v95; // [esp+18h] [ebp-120h]
  float v96; // [esp+18h] [ebp-120h]
  float v97; // [esp+18h] [ebp-120h]
  float v98; // [esp+18h] [ebp-120h]
  float v99; // [esp+18h] [ebp-120h]
  float v100; // [esp+18h] [ebp-120h]
  float v101; // [esp+18h] [ebp-120h]
  float v102; // [esp+18h] [ebp-120h]
  float v103; // [esp+18h] [ebp-120h]
  int v104; // [esp+1Ch] [ebp-11Ch]
  char v105; // [esp+23h] [ebp-115h]
  float v106; // [esp+24h] [ebp-114h] BYREF
  float v107; // [esp+28h] [ebp-110h]
  float v108; // [esp+2Ch] [ebp-10Ch]
  float v109; // [esp+30h] [ebp-108h]
  float v110; // [esp+34h] [ebp-104h]
  float v111; // [esp+38h] [ebp-100h]
  float v112; // [esp+3Ch] [ebp-FCh]
  float v113; // [esp+40h] [ebp-F8h]
  float v114; // [esp+44h] [ebp-F4h]
  float v115; // [esp+48h] [ebp-F0h]
  float v116; // [esp+4Ch] [ebp-ECh]
  float v117; // [esp+50h] [ebp-E8h]
  float v118; // [esp+54h] [ebp-E4h]
  float v119; // [esp+58h] [ebp-E0h]
  float v120; // [esp+5Ch] [ebp-DCh]
  float v121; // [esp+60h] [ebp-D8h]
  float v122; // [esp+64h] [ebp-D4h]
  float v123; // [esp+68h] [ebp-D0h]
  float v124; // [esp+6Ch] [ebp-CCh]
  float v125; // [esp+70h] [ebp-C8h]
  float v126; // [esp+74h] [ebp-C4h]
  float v127; // [esp+78h] [ebp-C0h]
  float v128; // [esp+7Ch] [ebp-BCh]
  float v129; // [esp+80h] [ebp-B8h]
  float v130; // [esp+84h] [ebp-B4h]
  float v131; // [esp+88h] [ebp-B0h]
  float v132; // [esp+8Ch] [ebp-ACh]
  float v133; // [esp+90h] [ebp-A8h]
  float v134; // [esp+94h] [ebp-A4h]
  float v135; // [esp+98h] [ebp-A0h]
  float v136; // [esp+9Ch] [ebp-9Ch]
  float v137; // [esp+A0h] [ebp-98h]
  float v138; // [esp+A4h] [ebp-94h]
  float v139; // [esp+A8h] [ebp-90h]
  float v140; // [esp+ACh] [ebp-8Ch]
  float v141; // [esp+B0h] [ebp-88h]
  float v142; // [esp+B4h] [ebp-84h]
  float v143; // [esp+B8h] [ebp-80h]
  int v144; // [esp+BCh] [ebp-7Ch]
  int v145; // [esp+C0h] [ebp-78h]
  int v146; // [esp+C4h] [ebp-74h]
  int v147; // [esp+C8h] [ebp-70h]
  int v148; // [esp+CCh] [ebp-6Ch]
  int v149; // [esp+D0h] [ebp-68h]
  int v150; // [esp+D4h] [ebp-64h]
  float v151; // [esp+DCh] [ebp-5Ch]
  float v152; // [esp+E0h] [ebp-58h]
  float v153; // [esp+E8h] [ebp-50h]
  float v154; // [esp+ECh] [ebp-4Ch]
  float v155; // [esp+F4h] [ebp-44h]
  float v156; // [esp+F8h] [ebp-40h]
  int v157[5]; // [esp+FCh] [ebp-3Ch] BYREF
  float v158; // [esp+110h] [ebp-28h]
  float v159; // [esp+11Ch] [ebp-1Ch]
  float v160; // [esp+128h] [ebp-10h]
  float v161; // [esp+134h] [ebp-4h]

  *(_BYTE *)(this + 19229) = 0;
  v132 = 0.0;
  *(_DWORD *)(this + 172) = 0;
  v133 = 0.0;
  v134 = 0.0;
  *(_DWORD *)(this + 176) = 0;
  *(_DWORD *)(this + 164) = 0;
  *(_DWORD *)(this + 168) = 1065353216;
  *(_DWORD *)(this + 180) = 0;
  if ( *(_DWORD *)(this + 16500) <= 1u )
  {
    if ( *(_BYTE *)(this + 4720) )
    {
      *(_BYTE *)(this + 4720) = 0;
      v2 = (_BYTE *)(this + 4724);
      v3 = 17;
      do
      {
        *v2 = 0;
        v2 += 28;
        --v3;
      }
      while ( v3 );
    }
    v4 = (char *)(this + 19232);
    v5 = 4;
    do
    {
      v6 = *v4;
      if ( *v4 )
      {
        v7 = v4[1];
        *(_BYTE *)(this + 4720) = 1;
        v8 = v4 - 14144;
        *v8 = v6;
        v8[1] = v7;
        v9 = v4 - 14128;
        *(_DWORD *)v9 = *((_DWORD *)v4 + 4);
        *((_DWORD *)v9 + 1) = *((_DWORD *)v4 + 5);
        *((_DWORD *)v9 + 2) = *((_DWORD *)v4 + 6);
        *v4 = 0;
      }
      v4 += 28;
      --v5;
    }
    while ( v5 );
    dword_7D8358 = 0;
    if ( (*(_BYTE *)(*(_DWORD *)this + 25296) & 1) != 0 )
    {
      v94 = sub_515510((float *)this);
      sub_4E0B30((int)dword_7D5DD8, this, (float *)(this + 17520), v94);
    }
    if ( sub_514FD0(this) )
    {
      v118 = sub_5155D0((float *)this, 0);
      sub_4E0CD0((int)dword_7D5DD8, *(_DWORD *)(this + 1812), (float *)(this + 17520), v118);
    }
    sub_5157A0((float *)this);
    sub_516570(v10);
    v11 = dword_7D8358;
    if ( dword_7D8358 > 0 )
    {
      if ( dword_7D8358 > 1 )
      {
        v12 = 0.0;
        v13 = 0.0;
        v117 = 0.0;
        v95 = 0.0;
        if ( dword_7D8358 <= 0 )
          goto LABEL_24;
        v14 = (float *)&unk_7D7A60;
        v15 = dword_7D8358;
        do
        {
          if ( *(v14 - 1) > (double)v95 )
            v95 = *(v14 - 1);
          v13 = v13 + *(v14 - 1);
          if ( *v14 > (double)v117 )
            v117 = *v14;
          v14 += 18;
          --v15;
          v12 = v12 + *(v14 - 18);
        }
        while ( v15 );
        if ( v13 <= 0.0 )
LABEL_24:
          v96 = 1.0;
        else
          v96 = v95 / v13;
        if ( v12 <= 0.0 )
          v16 = 1.0;
        else
          v16 = v117 / v12;
        if ( dword_7D8358 > 0 )
        {
          v17 = (float *)&unk_7D7A60;
          v18 = dword_7D8358;
          do
          {
            v17 += 18;
            --v18;
            *(v17 - 19) = v96 * *(v17 - 19);
            *(v17 - 18) = v16 * *(v17 - 18);
          }
          while ( v18 );
        }
      }
      v19 = 0;
      v118 = 0.0;
      if ( v11 > 0 )
      {
        while ( 2 )
        {
          v20 = 72 * v19 + 8223320;
          sub_518070(v20, 1);
          v21 = *(_DWORD *)(v20 + 12);
          v109 = fabs(*(float *)(v20 + 4));
          v105 = 0;
          *(float *)(v20 + 4) = -*(float *)(v20 + 4);
          switch ( v21 )
          {
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
              sub_416610(*(_DWORD **)(v20 + 16), v20, *(float *)(this + 17480));
              v104 = 38;
              v116 = (v109 - 5.0) * 0.0099999998;
              goto LABEL_134;
            case 6:
              sub_416610(*(_DWORD **)(v20 + 16), v20, *(float *)(this + 17480));
              v22 = (v109 - 1000.0) * 0.000066666667;
              v116 = v22;
              v97 = v22 * 3.0;
              v148 = (int)v97;
              v23 = v148;
              if ( v148 >= 0 )
              {
                if ( v148 > 3 )
                  v23 = 3;
              }
              else
              {
                v23 = 0;
              }
              v105 = byte_767B44;
              v24 = flt_7D4054[(unsigned __int8)dword_7D3C50++];
              if ( v24 > 0.0 )
                ++v23;
              v25 = v23 + 33;
              v104 = v23 + 33;
              goto LABEL_130;
            case 9:
              v26 = *(_DWORD *)(v20 + 16);
              if ( v26 )
              {
                v25 = *(int *)(v26 + 52);
                v104 = v25;
                if ( *(float *)(v26 + 8) - *(float *)(v26 + 12) * 0.0 == 0.0 )
                  *(_BYTE *)(this + 19229) = 1;
              }
              else
              {
                v25 = 28;
                v104 = 28;
              }
              v116 = (v109 - 1000.0) * 0.000066666667;
              if ( *(float *)&v25 != NAN )
              {
                v98 = v116 * 3.0;
                v150 = (int)v98;
                v27 = v150;
                if ( v150 >= 0 )
                {
                  if ( v150 > 3 )
                    v27 = 3;
                }
                else
                {
                  v27 = 0;
                }
                v28 = flt_7D4054[(unsigned __int8)dword_7D3C50++];
                if ( v28 > 0.0 )
                  ++v27;
                v25 += v27;
                v104 = v25;
              }
              v29 = *(_DWORD *)(v20 + 16);
              if ( v29 && *(int *)v20 >= 0 && *(_BYTE *)(v29 + 40) )
                v105 = 1;
              if ( *(_DWORD *)v20 >= 4u || v109 <= (double)*(float *)(this + 20684) || !v29 || !*(_BYTE *)(v29 + 42) )
                goto LABEL_130;
              v30 = *(float *)(v20 + 60) * 0.050000001;
              v31 = *(float *)(v20 + 64) * 0.050000001;
              v158 = *(float *)(v20 + 68) * 0.050000001;
              v135 = v30 + *(float *)(v20 + 24);
              v106 = v135;
              v136 = v31 + *(float *)(v20 + 28);
              v107 = v136;
              v137 = v158 + *(float *)(v20 + 32);
              v32 = *(float *)(this + 20684);
              v108 = v137;
              v33 = v32 + v32;
              if ( v33 < 1.0 )
                v33 = 1.0;
              v34 = (v109 - *(float *)(this + 20684)) / v33;
              if ( v34 <= 1.0 )
                v141 = v34;
              else
                v141 = 1.0;
              v35 = dword_7D73FC;
              if ( !dword_7D73FC )
                goto LABEL_112;
              v36 = *(unsigned __int16 **)(v20 + 20);
              if ( !v36 )
                goto LABEL_112;
              v37 = 0.0;
              v110 = 0.0;
              if ( fabs(*(float *)(v20 + 64)) <= 0.99000001 )
              {
                v37 = 1.0;
                v38 = v110;
              }
              else
              {
                v38 = 1.0;
              }
              v129 = v37 * *(float *)(v20 + 68) - *(float *)(v20 + 64) * 0.0;
              v39 = *(float *)(v20 + 60);
              v113 = v129;
              v130 = v39 * 0.0 - v38 * *(float *)(v20 + 68);
              v114 = v130;
              v131 = v38 * *(float *)(v20 + 64) - v37 * *(float *)(v20 + 60);
              v115 = v131;
              v40 = v131 * v131 + v130 * v130 + v129 * v129;
              if ( v40 > 0.0 )
              {
                v41 = 1.0 / sqrt(v40);
                v113 = v129 * v41;
                v114 = v114 * v41;
                v115 = v41 * v115;
              }
              v126 = v115 * *(float *)(v20 + 64) - v114 * *(float *)(v20 + 68);
              v110 = v126;
              v127 = v113 * *(float *)(v20 + 68) - v115 * *(float *)(v20 + 60);
              v111 = v127;
              v128 = v114 * *(float *)(v20 + 60) - v113 * *(float *)(v20 + 64);
              v112 = v128;
              v42 = v128 * v128 + v127 * v127 + v126 * v126;
              if ( v42 > 0.0 )
              {
                v43 = 1.0 / sqrt(v42);
                v110 = v126 * v43;
                v111 = v111 * v43;
                v112 = v43 * v112;
              }
              v44 = *(_DWORD *)(*((_DWORD *)v36 + 2) + 12);
              for ( i = 0; i < 12; *(float *)((char *)&v137 + i) = v111 * v46[1] + v112 * v46[2] + v110 * *v46 )
              {
                v46 = (float *)(v44 + 48 * *v36);
                i += 4;
                ++v36;
                *(float *)((char *)&v121 + i) = v114 * v46[1] + v115 * v46[2] + v113 * *v46;
              }
              if ( v139 <= (double)v140 )
                v47 = v140;
              else
                v47 = v139;
              if ( v138 <= v47 )
              {
                if ( v139 <= (double)v140 )
                  v48 = v140;
                else
                  v48 = v139;
              }
              else
              {
                v48 = v138;
              }
              v49 = v48 - (v137 * v112 + v136 * v111 + v135 * v110);
              v50 = v137 * v115 + v136 * v114 + v135 * v113;
              if ( v123 <= (double)v124 )
                v51 = v124;
              else
                v51 = v123;
              if ( v122 <= v51 )
              {
                if ( v123 <= (double)v124 )
                  v52 = v124;
                else
                  v52 = v123;
              }
              else
              {
                v52 = v122;
              }
              v125 = v52 - v50;
              if ( v123 >= (double)v124 )
                v53 = v124;
              else
                v53 = v123;
              if ( v122 >= v53 )
              {
                if ( v123 >= (double)v124 )
                  v54 = v124;
                else
                  v54 = v123;
              }
              else
              {
                v54 = v122;
              }
              v55 = v35 + 12;
              v56 = *(float *)v55;
              v57 = *(float *)(v55 + 4);
              v58 = *(_DWORD *)(v55 + 8);
              v109 = v54 - v50;
              v143 = v57;
              v142 = v56;
              v144 = v58;
              v59 = v57 * 0.5 - v49;
              if ( v59 > 0.0 )
              {
                v160 = v59 * v112;
                v106 = v135 - v110 * v59;
                v107 = v107 - v59 * v111;
                v108 = v108 - v160;
              }
              v60 = v142 * 0.5;
              v117 = v109 + v60;
              v99 = v60 - v125;
              if ( v117 <= 0.0 )
              {
                if ( v99 <= 0.0 )
                  goto LABEL_112;
                if ( v125 - v109 >= v142 )
                {
                  v161 = v99 * v115;
                  v106 = v106 - v99 * v113;
                  v107 = v107 - v99 * v114;
                  v62 = v108 - v161;
                }
                else
                {
                  v63 = (v109 + v125) * 0.5;
                  v151 = v63 * v114;
                  v152 = v63 * v115;
                  v106 = v113 * v63 + v106;
                  v107 = v107 + v151;
                  v62 = v108 + v152;
                }
              }
              else if ( v125 - v109 >= v142 )
              {
                v159 = v117 * v115;
                v106 = v117 * v113 + v106;
                v107 = v107 + v117 * v114;
                v62 = v108 + v159;
              }
              else
              {
                v61 = (v109 + v125) * 0.5;
                v155 = v61 * v114;
                v156 = v61 * v115;
                v106 = v113 * v61 + v106;
                v107 = v107 + v155;
                v62 = v108 + v156;
              }
              v108 = v62;
LABEL_112:
              v64 = dword_7D3C44;
              if ( dword_79FC40 < 1023 )
              {
                ++dword_79FC40;
                dword_7D3C44 += 208;
              }
              *(float *)&v93 = dbl_7DA9D0;
              sub_4D0D00((_DWORD *)v64, 2, 13, 28, *(_DWORD *)(this + 4), v93, 0);
              sub_4CF5A0((_DWORD *)(v64 + 8), &v106);
              if ( *(float *)(v20 + 60) <= 1.0 )
              {
                if ( *(float *)(v20 + 60) >= -1.0 )
                {
                  v100 = *(float *)(v20 + 60) * 127.0;
                  v147 = (int)v100;
                  v65 = v147;
                }
                else
                {
                  v65 = -127;
                }
              }
              else
              {
                v65 = 127;
              }
              *(_BYTE *)(v64 + 16) = v65;
              if ( *(float *)(v20 + 64) <= 1.0 )
              {
                if ( *(float *)(v20 + 64) >= -1.0 )
                {
                  v101 = *(float *)(v20 + 64) * 127.0;
                  v149 = (int)v101;
                  v66 = v149;
                }
                else
                {
                  v66 = -127;
                }
              }
              else
              {
                v66 = 127;
              }
              *(_BYTE *)(v64 + 17) = v66;
              if ( *(float *)(v20 + 68) <= 1.0 )
              {
                if ( *(float *)(v20 + 68) >= -1.0 )
                {
                  v102 = *(float *)(v20 + 68) * 127.0;
                  v145 = (int)v102;
                  v67 = v145;
                }
                else
                {
                  v67 = -127;
                }
              }
              else
              {
                v67 = 127;
              }
              v68 = v141;
              *(_BYTE *)(v64 + 18) = v67;
              v103 = v68 * 255.0;
              v146 = (int)v103;
              v25 = v104;
              *(_BYTE *)(v64 + 19) = v146;
LABEL_130:
              if ( v105 && !(v70 | v71) )
              {
                v132 = *(float *)(this + 17544) * 0.5;
                v72 = *(float *)(this + 17548);
                v119 = v132;
                v133 = v72 * 0.5;
                v73 = *(float *)(this + 17552);
                v120 = v133;
                v134 = v73 * 0.5;
                v121 = v134;
                v74 = v133 + 2.0;
                v75 = 28 * *(_DWORD *)v20;
                v76 = *(float *)(v20 + 60) * 0.5;
                v153 = *(float *)(v20 + 64) * 0.5;
                v77 = *(float *)(v20 + 68) * 0.5;
                v78 = v75 + this + 4724;
                *(_BYTE *)(this + 4720) = 1;
                *(_BYTE *)v78 = 8;
                v154 = v77;
                *(_BYTE *)(v78 + 1) = 8;
                v78 += 16;
                v119 = v119 + v76;
                *(float *)v78 = v119;
                v120 = v153 + v74;
                *(float *)(v78 + 4) = v120;
                v121 = v121 + v154;
                *(float *)(v78 + 8) = v121;
              }
              if ( *(float *)&v25 != NAN )
              {
LABEL_134:
                if ( v116 > 0.0099999998 )
                {
                  if ( v116 > 1.0 )
                    v116 = 1.0;
                  v79 = sub_5263B0(v104);
                  if ( v79 < v116 )
                  {
                    v80 = *(float *)(v20 + 36) - *(float *)(this + 17520);
                    v81 = *(float *)(v20 + 40) - *(float *)(this + 17524);
                    v82 = *(float *)(v20 + 44) - *(float *)(this + 17528);
                    *(float *)v157 = v82 * *(float *)(this + 17508)
                                   + v81 * *(float *)(this + 17496)
                                   + v80 * *(float *)(this + 17484);
                    *(float *)&v157[1] = v82 * *(float *)(this + 17512)
                                       + v81 * *(float *)(this + 17500)
                                       + v80 * *(float *)(this + 17488);
                    *(float *)&v157[2] = v82 * *(float *)(this + 17516)
                                       + v81 * *(float *)(this + 17504)
                                       + v80 * *(float *)(this + 17492);
                    sub_5260E0(v104, 2, v116, 1065353216, (int)v157);
                  }
                }
              }
LABEL_139:
              v11 = dword_7D8358;
              v19 = ++LODWORD(v118);
              if ( SLODWORD(v118) >= dword_7D8358 )
                break;
              continue;
            default:
              goto LABEL_139;
          }
          break;
        }
      }
      v83 = 0;
      if ( v11 > 0 )
      {
        v84 = (float *)&unk_7D7A64;
        do
        {
          v85 = *v84;
          if ( *(_DWORD *)v84 != 9 && LODWORD(v85) != 10 )
          {
            switch ( LODWORD(v85) )
            {
              case 0:
              case 3:
                v86 = *(double *)(*(_DWORD *)(*((_DWORD *)v84 + 1) + 36) + 388);
                goto LABEL_149;
              case 1:
              case 4:
                v86 = *(double *)(*(_DWORD *)(*((_DWORD *)v84 + 1) + 36) + 388);
                goto LABEL_149;
              case 2:
              case 5:
                v86 = *(double *)(*(_DWORD *)(*((_DWORD *)v84 + 1) + 36) + 388);
LABEL_149:
                *(float *)&v104 = v86;
                break;
              case 6:
                v104 = *(int *)(*(_DWORD *)(*((_DWORD *)v84 + 1) + 36) + 17584);
                break;
              default:
                break;
            }
            v118 = *(v84 - 1) * *(float *)(this + 17584) / (*(float *)&v104 + *(float *)(this + 17584));
            *(v84 - 1) = *(v84 - 1) - v118;
          }
          sub_518510(v84 - 3);
          if ( *(_DWORD *)v84 != 9 && *(_DWORD *)v84 != 10 )
          {
            v87 = (_DWORD *)*((_DWORD *)v84 + 1);
            *(v84 - 1) = -v118;
            sub_4166B0(v87, (int)(v84 - 3));
          }
          v11 = dword_7D8358;
          ++v83;
          v84 += 18;
        }
        while ( v83 < dword_7D8358 );
      }
      if ( !*(_DWORD *)(this + 19000) )
      {
        sub_514EE0((_DWORD *)this);
        v11 = dword_7D8358;
      }
      v88 = *(float **)(this + 19000);
      v110 = *v88 - *(float *)(this + 17520);
      v111 = v88[1] - *(float *)(this + 17524);
      v89 = v88[2] - *(float *)(this + 17528);
      v119 = v110;
      v120 = v111;
      v112 = v89;
      v121 = v112;
      if ( v110 != 0.0 || v111 != 0.0 || v112 != 0.0 )
      {
        v90 = 1.0 / sqrt(v112 * v112 + v111 * v111 + v110 * v110);
        v119 = v110 * v90;
        v120 = v120 * v90;
        v121 = v121 * v90;
      }
      v91 = 0;
      if ( v11 > 0 )
      {
        v92 = (float *)&unk_7D7A98;
        do
        {
          if ( *((_DWORD *)v92 - 13) == 9 && v121 * v92[1] + v119 * *(v92 - 1) + v120 * *v92 < -0.70700002 )
          {
            *(_BYTE *)(this + 20688) = 1;
            v11 = dword_7D8358;
          }
          ++v91;
          v92 += 18;
        }
        while ( v91 < v11 );
      }
    }
  }
}
