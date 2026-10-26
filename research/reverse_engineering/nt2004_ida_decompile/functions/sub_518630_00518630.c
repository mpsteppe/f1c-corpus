void __thiscall sub_518630(char *this, float *a2, float *a3, int a4)
{
  double v5; // st7
  double v6; // st7
  long double v7; // st7
  long double v8; // st7
  int v9; // edi
  char v10; // al
  char v11; // al
  char v12; // al
  char v13; // al
  char v14; // al
  char v15; // al
  double v16; // st6
  double v17; // st4
  double v18; // st5
  double v19; // st7
  double v20; // st7
  double v21; // st6
  double v22; // st7
  double v23; // st6
  double v24; // st7
  double v25; // st6
  double v26; // st5
  double v27; // st5
  double v28; // st5
  double v29; // st7
  double v30; // st7
  double v31; // st7
  int v32; // edx
  int v33; // eax
  int v34; // edx
  double v35; // st6
  double v36; // st4
  double v37; // st5
  double v38; // st7
  double v39; // st7
  double v40; // st6
  double v41; // st7
  double v42; // st6
  double v43; // st7
  double v44; // st6
  double v45; // st5
  double v46; // st5
  double v47; // st5
  double v48; // st7
  double v49; // st7
  double v50; // st7
  int v51; // edx
  int v52; // eax
  int v53; // edx
  float *v54; // ecx
  char *v55; // edx
  int v56; // ebx
  float *v57; // ebp
  float *v58; // edi
  double v59; // st6
  double v60; // st5
  double v61; // st3
  double v62; // st4
  double v63; // st7
  _BYTE *v64; // eax
  double v65; // st7
  double v66; // st6
  double v67; // st7
  double v68; // st6
  double v69; // st7
  double v70; // st6
  double v71; // st5
  double v72; // st5
  double v73; // st5
  double v74; // st7
  double v75; // st6
  double v76; // st5
  double v77; // st5
  double v78; // st7
  int v79; // edx
  int v80; // eax
  int v81; // ebx
  float *v82; // edi
  int v83; // ebp
  double v84; // st6
  double v85; // st5
  double v86; // st3
  double v87; // st4
  double v88; // st7
  double v89; // st7
  double v90; // st7
  double v91; // st6
  double v92; // st7
  double v93; // st6
  double v94; // st7
  double v95; // st6
  double v96; // st5
  double v97; // st5
  double v98; // st5
  double v99; // st7
  double v100; // st7
  double v101; // st7
  int v102; // edx
  int v103; // eax
  int v104; // edx
  int v105; // eax
  int v106; // eax
  bool v107; // zf
  double v108; // st7
  double v109; // st7
  double v110; // st7
  int v111; // eax
  double v112; // st7
  int v113; // [esp-4h] [ebp-84h]
  int v114; // [esp+0h] [ebp-80h]
  float v115; // [esp+18h] [ebp-68h]
  float v116; // [esp+1Ch] [ebp-64h]
  float v117; // [esp+20h] [ebp-60h]
  float *v118; // [esp+20h] [ebp-60h]
  float v119; // [esp+24h] [ebp-5Ch]
  char *v120; // [esp+24h] [ebp-5Ch]
  char *v121; // [esp+28h] [ebp-58h]
  char *v122; // [esp+28h] [ebp-58h]
  float v123; // [esp+2Ch] [ebp-54h]
  float v124; // [esp+30h] [ebp-50h]
  float v125; // [esp+34h] [ebp-4Ch]
  float v126; // [esp+38h] [ebp-48h]
  float v127; // [esp+3Ch] [ebp-44h]
  float v128; // [esp+40h] [ebp-40h]
  float v129; // [esp+44h] [ebp-3Ch]
  float v130; // [esp+48h] [ebp-38h]
  int v131; // [esp+4Ch] [ebp-34h] BYREF
  float v132; // [esp+50h] [ebp-30h]
  float v133; // [esp+54h] [ebp-2Ch]
  float v134; // [esp+58h] [ebp-28h]
  int v135; // [esp+5Ch] [ebp-24h]
  int v136; // [esp+60h] [ebp-20h]
  int v137; // [esp+64h] [ebp-1Ch]
  float v138; // [esp+68h] [ebp-18h]
  float v139; // [esp+6Ch] [ebp-14h]
  float v140; // [esp+70h] [ebp-10h]
  int v141; // [esp+74h] [ebp-Ch]
  int v142; // [esp+78h] [ebp-8h]
  int v143; // [esp+7Ch] [ebp-4h]
  float v144; // [esp+88h] [ebp+8h]
  float v145; // [esp+88h] [ebp+8h]
  float v146; // [esp+88h] [ebp+8h]
  float v147; // [esp+88h] [ebp+8h]
  float v148; // [esp+88h] [ebp+8h]
  float v149; // [esp+88h] [ebp+8h]
  float *v150; // [esp+88h] [ebp+8h]
  float v151; // [esp+88h] [ebp+8h]

  if ( *(_DWORD *)this == (sub_42DBA0() ? dword_75AACC : 0) )
  {
    if ( !byte_75E9C7 && (!this[17328] || !byte_75E9CC) )
    {
LABEL_9:
      v119 = fabs(*(float *)(a4 + 4));
      v5 = (double)*(int *)dword_7684BC * v119 * 0.0099999998;
      v116 = v5;
      v6 = v5 * *((float *)this + 4938) + *((float *)this + 4937);
      if ( v6 > *((float *)this + 4939) )
        v6 = *((float *)this + 4939);
      v115 = v6 * v6;
      if ( v116 > (double)*((float *)this + 4940) )
        sub_51C1A0(this);
      v117 = v116 * *((float *)this + 4941);
      if ( v119 > (double)*((float *)this + 4942) )
      {
        if ( v117 > 1.0 )
          v117 = 1.0;
        if ( a2[2] >= -1.0 )
          sub_519820(v117);
        else
          sub_5197F0(v117);
        v7 = v117 * *((float *)this + 4943);
        if ( v7 > 1.0 )
          v7 = 1.0;
        v8 = sqrt(v7) / v119;
        v125 = *a3 * v8;
        v126 = a3[1] * v8;
        v127 = a3[2] * v8;
        v9 = dword_7D3C44;
        if ( dword_79FC40 < 1023 )
        {
          ++dword_79FC40;
          dword_7D3C44 += 208;
        }
        *(float *)&v114 = dbl_7DA9D0;
        sub_4D0D00((_DWORD *)v9, 2, 7, 10, *((_DWORD *)this + 1), v114, 0);
        v128 = *a2 * 0.5;
        v129 = a2[1] * 0.66666669;
        v130 = a2[2] * 0.2857143;
        if ( v128 <= 1.0 )
        {
          if ( v128 >= -1.0 )
          {
            v144 = v128 * 127.0;
            v10 = (int)v144;
          }
          else
          {
            v10 = -127;
          }
        }
        else
        {
          v10 = 127;
        }
        *(_BYTE *)(v9 + 8) = v10;
        if ( v129 <= 1.0 )
        {
          if ( v129 >= -1.0 )
          {
            v145 = v129 * 127.0;
            v11 = (int)v145;
          }
          else
          {
            v11 = -127;
          }
        }
        else
        {
          v11 = 127;
        }
        *(_BYTE *)(v9 + 9) = v11;
        if ( v130 <= 1.0 )
        {
          if ( v130 >= -1.0 )
          {
            v146 = v130 * 127.0;
            v12 = (int)v146;
          }
          else
          {
            v12 = -127;
          }
        }
        else
        {
          v12 = 127;
        }
        *(_BYTE *)(v9 + 10) = v12;
        if ( v125 <= 1.0 )
        {
          if ( v125 >= -1.0 )
          {
            v147 = v125 * 127.0;
            v13 = (int)v147;
          }
          else
          {
            v13 = -127;
          }
        }
        else
        {
          v13 = 127;
        }
        *(_BYTE *)(v9 + 11) = v13;
        if ( v126 <= 1.0 )
        {
          if ( v126 >= -1.0 )
          {
            v148 = v126 * 127.0;
            v14 = (int)v148;
          }
          else
          {
            v14 = -127;
          }
        }
        else
        {
          v14 = 127;
        }
        *(_BYTE *)(v9 + 12) = v14;
        if ( v127 <= 1.0 )
        {
          if ( v127 >= -1.0 )
          {
            v149 = v127 * 127.0;
            v15 = (int)v149;
          }
          else
          {
            v15 = -127;
          }
        }
        else
        {
          v15 = 127;
        }
        *(_BYTE *)(v9 + 13) = v15;
        *(_DWORD *)(v9 + 14) = *((_DWORD *)this + 4370);
        sub_4C0B10((_DWORD *)this + 4126, 1);
      }
      if ( *((_DWORD *)this + 841) )
      {
        if ( this[3428] )
        {
          v16 = a2[2] - *((float *)this + 4948);
          v17 = a2[1] - *((float *)this + 4947);
          v18 = v16 * v16 + v17 * v17;
          if ( v18 < v115 && (1.0 - v18 / v115) * v116 > *((float *)this + 4944) )
          {
            v19 = flt_7D3C54[(unsigned __int8)dword_7D3C50++];
            if ( v19 < *((float *)this + 4945) )
            {
              sub_519850(4);
              v20 = *((float *)this + 4373) * *((float *)this + 4948)
                  + *((float *)this + 4372) * *((float *)this + 4947);
              v21 = *((float *)this + 4946) * *((float *)this + 4371);
              v131 = *((_DWORD *)this + 4370);
              v22 = v20 + v21;
              v23 = *((float *)this + 4376) * *((float *)this + 4948)
                  + *((float *)this + 4375) * *((float *)this + 4947)
                  + *((float *)this + 4374) * *((float *)this + 4946);
              v134 = *((float *)this + 4379) * *((float *)this + 4948)
                   + *((float *)this + 4378) * *((float *)this + 4947)
                   + *((float *)this + 4377) * *((float *)this + 4946);
              v132 = v22 + *((float *)this + 4380);
              v24 = v23 + *((float *)this + 4381);
              v25 = v134 + *((float *)this + 4382);
              v26 = flt_7D4054[(unsigned __int8)dword_7D3C50++];
              v132 = v26 * 0.2 + v132;
              v27 = flt_7D4054[(unsigned __int8)dword_7D3C50++];
              v133 = v27 * 0.2 + v24;
              v28 = flt_7D4054[(unsigned __int8)dword_7D3C50++];
              v134 = v28 * 0.2 + v25;
              v29 = flt_7D4054[(unsigned __int8)dword_7D3C50++];
              v138 = v29 + v29;
              v30 = flt_7D4054[(unsigned __int8)dword_7D3C50++];
              v141 = 0;
              v142 = 0;
              v139 = v30 + v30 + 5.0;
              v143 = 0;
              v31 = flt_7D4054[(unsigned __int8)dword_7D3C50++];
              v32 = *((_DWORD *)this + 4384);
              v33 = *((_DWORD *)this + 4385);
              v135 = *((_DWORD *)this + 4383);
              v136 = v32;
              v34 = *((_DWORD *)this + 1);
              v137 = v33;
              v140 = v31 + v31;
              sub_4183B0(dword_6291D0, 4, (float *)this + 4949, v34, 0, (float *)&v131);
            }
          }
        }
      }
      if ( *((_DWORD *)this + 858) )
      {
        if ( this[3496] )
        {
          v35 = a2[2] - *((float *)this + 4960);
          v36 = a2[1] - *((float *)this + 4959);
          v37 = v35 * v35 + v36 * v36;
          if ( v37 < v115 && (1.0 - v37 / v115) * v116 > *((float *)this + 4956) )
          {
            v38 = flt_7D3C54[(unsigned __int8)dword_7D3C50++];
            if ( v38 < *((float *)this + 4957) )
            {
              sub_519850(5);
              v39 = *((float *)this + 4373) * *((float *)this + 4960)
                  + *((float *)this + 4372) * *((float *)this + 4959);
              v40 = *((float *)this + 4958) * *((float *)this + 4371);
              v131 = *((_DWORD *)this + 4370);
              v41 = v39 + v40;
              v42 = *((float *)this + 4376) * *((float *)this + 4960)
                  + *((float *)this + 4375) * *((float *)this + 4959)
                  + *((float *)this + 4374) * *((float *)this + 4958);
              v134 = *((float *)this + 4379) * *((float *)this + 4960)
                   + *((float *)this + 4378) * *((float *)this + 4959)
                   + *((float *)this + 4377) * *((float *)this + 4958);
              v132 = v41 + *((float *)this + 4380);
              v43 = v42 + *((float *)this + 4381);
              v44 = v134 + *((float *)this + 4382);
              v45 = flt_7D4054[(unsigned __int8)dword_7D3C50++];
              v132 = v45 * 0.2 + v132;
              v46 = flt_7D4054[(unsigned __int8)dword_7D3C50++];
              v133 = v46 * 0.2 + v43;
              v47 = flt_7D4054[(unsigned __int8)dword_7D3C50++];
              v134 = v47 * 0.2 + v44;
              v48 = flt_7D4054[(unsigned __int8)dword_7D3C50++];
              v138 = v48 + v48;
              v49 = flt_7D4054[(unsigned __int8)dword_7D3C50++];
              v141 = 0;
              v142 = 0;
              v139 = v49 + v49 + 5.0;
              v143 = 0;
              v50 = flt_7D4054[(unsigned __int8)dword_7D3C50++];
              v51 = *((_DWORD *)this + 4384);
              v52 = *((_DWORD *)this + 4385);
              v135 = *((_DWORD *)this + 4383);
              v136 = v51;
              v53 = *((_DWORD *)this + 1);
              v137 = v52;
              v140 = v50 + v50;
              sub_4183B0(dword_6291D0, 4, (float *)this + 4961, v53, 1, (float *)&v131);
            }
          }
        }
      }
      v54 = (float *)(this + 20060);
      v55 = this + 3500;
      v56 = 0;
      v57 = (float *)(this + 20252);
      v150 = (float *)(this + 20060);
      v121 = this + 3500;
      v58 = (float *)(this + 20112);
      do
      {
        if ( *(_DWORD *)v55 )
        {
          if ( v55[64] )
          {
            v59 = a2[1] - *v58;
            v60 = a2[2] - v58[1];
            v61 = *a2 - *(v58 - 1);
            v62 = v60 * v60 + v59 * v59 + v61 * v61;
            if ( v62 < v115 && (1.0 - v62 / v115) * v116 > *(v54 - 12) )
            {
              v63 = flt_7D3C54[(unsigned __int8)dword_7D3C50++];
              if ( v63 < *v54 )
              {
                sub_519850(v56 + 6);
                v64 = (_BYTE *)*((_DWORD *)this + 1079);
                if ( v64 && !*v64 )
                  sub_4C0B60((int)(this + 16504));
                v65 = *((float *)this + 4373) * v58[1] + *((float *)this + 4372) * *v58;
                v66 = *((float *)this + 4371);
                v131 = *((_DWORD *)this + 4370);
                v67 = v65 + v66 * *(v58 - 1);
                v68 = *((float *)this + 4376) * v58[1]
                    + *((float *)this + 4375) * *v58
                    + *((float *)this + 4374) * *(v58 - 1);
                v134 = *((float *)this + 4379) * v58[1]
                     + *((float *)this + 4378) * *v58
                     + *((float *)this + 4377) * *(v58 - 1);
                v132 = v67 + *((float *)this + 4380);
                v69 = v68 + *((float *)this + 4381);
                v70 = v134 + *((float *)this + 4382);
                v71 = flt_7D4054[(unsigned __int8)dword_7D3C50++];
                v132 = v71 * 0.2 + v132;
                v72 = flt_7D4054[(unsigned __int8)dword_7D3C50++];
                v133 = v72 * 0.2 + v69;
                v73 = flt_7D4054[(unsigned __int8)dword_7D3C50++];
                v134 = v73 * 0.2 + v70;
                v74 = *((float *)this + 4386) * 0.30000001;
                v75 = *((float *)this + 4387) * 0.30000001 + 5.0;
                v140 = *((float *)this + 4388) * 0.30000001;
                v76 = flt_7D4054[(unsigned __int8)dword_7D3C50++];
                v138 = v76 + v76 + v74;
                v141 = 0;
                v77 = flt_7D4054[(unsigned __int8)dword_7D3C50++];
                v142 = 0;
                v143 = 0;
                v139 = v77 + v77 + v75;
                v78 = flt_7D4054[(unsigned __int8)dword_7D3C50++];
                v79 = *((_DWORD *)this + 4384);
                v80 = *((_DWORD *)this + 4385);
                v135 = *((_DWORD *)this + 4383);
                v136 = v79;
                v113 = *((_DWORD *)this + 1);
                v140 = v78 + v78 + v140;
                v137 = v80;
                sub_4183B0(dword_6291D0, 5, v57, v113, v56, (float *)&v131);
                v55 = v121;
                v54 = v150;
              }
            }
          }
        }
        ++v56;
        ++v54;
        v55 += 68;
        v58 += 3;
        v57 += 7;
        v150 = v54;
        v121 = v55;
      }
      while ( v56 < 12 );
      v81 = 0;
      v122 = (char *)&unk_75EBCC;
      v118 = (float *)(this + 19900);
      v120 = this + 2148;
      v82 = (float *)(this + 17708);
      v83 = 0;
      while ( 1 )
      {
        if ( *(_DWORD *)v120 )
        {
          if ( v120[64] )
          {
            v84 = a2[1] - *v82;
            v85 = a2[2] - v82[1];
            v86 = *a2 - *(v82 - 1);
            v87 = v85 * v85 + v84 * v84 + v86 * v86;
            if ( v87 < v115 )
              break;
          }
        }
LABEL_108:
        v120 += 304;
        v83 += 1256;
        ++v81;
        v82 += 62;
        v118 += 7;
        v122 += 1256;
        if ( v83 >= 5024 )
          return;
      }
      v88 = (1.0 - v87 / v115) * v116;
      v151 = v88;
      if ( v88 <= *((float *)this + 4972) )
      {
LABEL_101:
        v110 = *((float *)this + 4968);
        v111 = *(_DWORD *)(a4 + 12);
        v124 = *((float *)this + 4969);
        if ( v111 == 5 || v111 == 4 )
        {
          v110 = *((float *)this + 4970);
          v124 = *((float *)this + 4971);
        }
        if ( v151 > v110 )
        {
          v112 = flt_7D3C54[(unsigned __int8)dword_7D3C50++];
          if ( v112 < v124 && !*((_DWORD *)this + 4125) )
            sub_43AA80((int)v122);
        }
        goto LABEL_108;
      }
      if ( v151 <= (double)*((float *)this + 4973)
        || (v89 = flt_7D3C54[(unsigned __int8)dword_7D3C50], ++dword_7D3C50, v89 >= *((float *)this + 4974)) )
      {
        if ( !*((_DWORD *)this + 4125) )
        {
          v108 = *((float *)this + 4973) - *((float *)this + 4972);
          if ( v108 > 0.0 )
          {
            v109 = (v151 - *((float *)this + 4972)) / v108;
            v123 = v109;
            if ( v109 > 1.0 )
              v123 = 1.0;
            sub_445390((int *)&dbl_75E930, v81, v123);
          }
        }
        goto LABEL_101;
      }
      sub_519850(v81);
      v90 = *((float *)this + 4373) * v82[1];
      v91 = *((float *)this + 4372);
      v131 = *((_DWORD *)this + 4370);
      v92 = v90 + v91 * *v82 + *((float *)this + 4371) * *(v82 - 1);
      v93 = *((float *)this + 4376) * v82[1] + *((float *)this + 4374) * *(v82 - 1) + *((float *)this + 4375) * *v82;
      v134 = *((float *)this + 4379) * v82[1] + *((float *)this + 4377) * *(v82 - 1) + *((float *)this + 4378) * *v82;
      v132 = v92 + *((float *)this + 4380);
      v94 = v93 + *((float *)this + 4381);
      v95 = v134 + *((float *)this + 4382);
      v96 = flt_7D4054[(unsigned __int8)dword_7D3C50++];
      v132 = v96 * 0.2 + v132;
      v97 = flt_7D4054[(unsigned __int8)dword_7D3C50++];
      v133 = v97 * 0.2 + v94;
      v98 = flt_7D4054[(unsigned __int8)dword_7D3C50++];
      v134 = v98 * 0.2 + v95;
      v99 = flt_7D4054[(unsigned __int8)dword_7D3C50++];
      v138 = v99 + v99;
      v100 = flt_7D4054[(unsigned __int8)dword_7D3C50++];
      v141 = 0;
      v142 = 0;
      v139 = v100 + v100 + 5.0;
      v143 = 0;
      v101 = flt_7D4054[(unsigned __int8)dword_7D3C50++];
      v102 = *((_DWORD *)this + 4384);
      v103 = *((_DWORD *)this + 4385);
      v135 = *((_DWORD *)this + 4383);
      v136 = v102;
      v104 = *((_DWORD *)this + 1);
      v137 = v103;
      v140 = v101 + v101;
      sub_4183B0(dword_6291D0, 3, v118, v104, v81, (float *)&v131);
      v105 = *((_DWORD *)this + 4692);
      if ( v105 )
      {
        v106 = v105 - 1;
        if ( v106 )
        {
          if ( v106 != 1 )
            goto LABEL_93;
          if ( v83 )
          {
            v107 = v83 == 1256;
            goto LABEL_91;
          }
        }
      }
      else if ( v83 != 2512 )
      {
        v107 = v83 == 3768;
LABEL_91:
        if ( v107 )
          goto LABEL_92;
LABEL_93:
        if ( !*((_DWORD *)this + 4125) && !*(_DWORD *)dword_76693C )
          sub_4BA1A0(0, -1.0);
        goto LABEL_101;
      }
LABEL_92:
      sub_51C1A0(this);
      goto LABEL_93;
    }
  }
  else if ( *((_DWORD *)this + 4125) != 1 || dword_75CBB4 != 1 && dword_75CBB4 != 3 )
  {
    goto LABEL_9;
  }
}
