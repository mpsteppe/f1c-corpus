char __thiscall sub_4EC1A0(char *this, float *a2, float *a3, float a4)
{
  char *v5; // eax
  double v6; // st7
  double v7; // st7
  long double v8; // st7
  long double v9; // st7
  int v10; // edi
  char v11; // al
  char v12; // al
  char v13; // al
  char v14; // al
  char v15; // al
  char v16; // al
  double v17; // st6
  double v18; // st4
  double v19; // st5
  double v20; // st7
  double v21; // st7
  double v22; // st6
  double v23; // st7
  double v24; // st6
  double v25; // st7
  double v26; // st6
  double v27; // st5
  double v28; // st5
  double v29; // st5
  double v30; // st7
  double v31; // st7
  double v32; // st7
  int v33; // edx
  int v34; // eax
  int v35; // edx
  double v36; // st6
  double v37; // st4
  double v38; // st5
  double v39; // st7
  double v40; // st7
  double v41; // st6
  double v42; // st7
  double v43; // st6
  double v44; // st7
  double v45; // st6
  double v46; // st5
  double v47; // st5
  double v48; // st5
  double v49; // st7
  double v50; // st7
  double v51; // st7
  int v52; // edx
  int v53; // eax
  int v54; // edx
  float *v55; // ecx
  char *v56; // edx
  int v57; // ebx
  float *v58; // ebp
  float *v59; // edi
  double v60; // st6
  double v61; // st5
  double v62; // st3
  double v63; // st4
  double v64; // st7
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
  double v78; // st5
  double v79; // st7
  int v80; // edx
  int v81; // eax
  int v82; // ebx
  float *v83; // ebp
  float *v84; // edi
  double v85; // st6
  double v86; // st5
  double v87; // st3
  double v88; // st4
  double v89; // st7
  double v90; // st7
  double v91; // st7
  double v92; // st6
  double v93; // st7
  double v94; // st6
  double v95; // st7
  double v96; // st6
  double v97; // st5
  double v98; // st5
  double v99; // st5
  double v100; // st7
  double v101; // st7
  double v102; // st7
  int v103; // edx
  int v104; // eax
  int v105; // eax
  int v106; // eax
  double v107; // st7
  double v108; // st7
  int v110; // [esp-4h] [ebp-74h]
  int v111; // [esp-4h] [ebp-74h]
  int v112; // [esp+0h] [ebp-70h]
  float v113; // [esp+18h] [ebp-58h]
  float v114; // [esp+1Ch] [ebp-54h]
  float v115; // [esp+20h] [ebp-50h]
  char *v116; // [esp+20h] [ebp-50h]
  char *v117; // [esp+20h] [ebp-50h]
  float v118; // [esp+24h] [ebp-4Ch]
  float v119; // [esp+28h] [ebp-48h]
  float v120; // [esp+2Ch] [ebp-44h]
  float v121; // [esp+30h] [ebp-40h]
  float v122; // [esp+34h] [ebp-3Ch]
  float v123; // [esp+38h] [ebp-38h]
  int v124; // [esp+3Ch] [ebp-34h] BYREF
  float v125; // [esp+40h] [ebp-30h]
  float v126; // [esp+44h] [ebp-2Ch]
  float v127; // [esp+48h] [ebp-28h]
  int v128; // [esp+4Ch] [ebp-24h]
  int v129; // [esp+50h] [ebp-20h]
  int v130; // [esp+54h] [ebp-1Ch]
  float v131; // [esp+58h] [ebp-18h]
  float v132; // [esp+5Ch] [ebp-14h]
  float v133; // [esp+60h] [ebp-10h]
  int v134; // [esp+64h] [ebp-Ch]
  int v135; // [esp+68h] [ebp-8h]
  int v136; // [esp+6Ch] [ebp-4h]
  float v137; // [esp+78h] [ebp+8h]
  float v138; // [esp+78h] [ebp+8h]
  float v139; // [esp+78h] [ebp+8h]
  float v140; // [esp+78h] [ebp+8h]
  float v141; // [esp+78h] [ebp+8h]
  float v142; // [esp+78h] [ebp+8h]
  float *v143; // [esp+78h] [ebp+8h]
  float v144; // [esp+78h] [ebp+8h]
  float v145; // [esp+78h] [ebp+8h]
  float v146; // [esp+7Ch] [ebp+Ch]

  if ( *(_DWORD *)this == dword_7C54E8 )
  {
    LOBYTE(v5) = byte_7C749F;
    if ( !byte_7C749F && (!this[13376] || (LOBYTE(v5) = byte_7C74A4) == 0) )
    {
LABEL_9:
      v115 = fabs(a4);
      v6 = (double)dword_7D0014 * v115 * 0.0099999998;
      v146 = v6;
      v7 = v6 * *((float *)this + 3935) + *((float *)this + 3934);
      if ( v7 > *((float *)this + 3936) )
        v7 = *((float *)this + 3936);
      v113 = v7 * v7;
      if ( v146 > (double)*((float *)this + 3937) )
        TireScrubReset(this);
      v114 = v146 * *((float *)this + 3938);
      if ( v115 > (double)*((float *)this + 3939) )
      {
        if ( v114 > 1.0 )
          v114 = 1.0;
        if ( a2[2] >= -1.0 )
        {
          if ( a2[2] >= 1.0 )
            PhysicsTimeStep(v114);
          else
            ForceApplicationRouter(v114);
        }
        else
        {
          FloatParameterForwarder(v114);
        }
        v8 = v114 * *((float *)this + 3940);
        if ( v8 > 1.0 )
          v8 = 1.0;
        v9 = sqrt(v8) / v115;
        v118 = *a3 * v9;
        v119 = a3[1] * v9;
        v120 = a3[2] * v9;
        v10 = dword_8AAE64;
        if ( dword_83EE60 < 1023 )
        {
          ++dword_83EE60;
          dword_8AAE64 += 432;
        }
        *(float *)&v112 = dbl_8AFEA0;
        ProgressBarEventEncode((_DWORD *)v10, 2, 7, 10, *((_DWORD *)this + 1), v112, 0);
        v121 = *a2 * 0.5;
        v122 = a2[1] * 0.66666669;
        v123 = a2[2] * 0.2857143;
        if ( v121 <= 1.0 )
        {
          if ( v121 >= -1.0 )
          {
            v137 = v121 * 127.0;
            v11 = (int)v137;
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
        *(_BYTE *)(v10 + 8) = v11;
        if ( v122 <= 1.0 )
        {
          if ( v122 >= -1.0 )
          {
            v138 = v122 * 127.0;
            v12 = (int)v138;
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
        *(_BYTE *)(v10 + 9) = v12;
        if ( v123 <= 1.0 )
        {
          if ( v123 >= -1.0 )
          {
            v139 = v123 * 127.0;
            v13 = (int)v139;
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
        *(_BYTE *)(v10 + 10) = v13;
        if ( v118 <= 1.0 )
        {
          if ( v118 >= -1.0 )
          {
            v140 = v118 * 127.0;
            v14 = (int)v140;
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
        *(_BYTE *)(v10 + 11) = v14;
        if ( v119 <= 1.0 )
        {
          if ( v119 >= -1.0 )
          {
            v141 = v119 * 127.0;
            v15 = (int)v141;
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
        *(_BYTE *)(v10 + 12) = v15;
        if ( v120 <= 1.0 )
        {
          if ( v120 >= -1.0 )
          {
            v142 = v120 * 127.0;
            v16 = (int)v142;
          }
          else
          {
            v16 = -127;
          }
        }
        else
        {
          v16 = 127;
        }
        *(_BYTE *)(v10 + 13) = v16;
        *(_DWORD *)(v10 + 14) = *((_DWORD *)this + 3371);
        StateTransition((_DWORD *)this + 3248, 1);
      }
      if ( *((_DWORD *)this + 818) )
      {
        if ( this[3336] )
        {
          v17 = a2[2] - *((float *)this + 3945);
          v18 = a2[1] - *((float *)this + 3944);
          v19 = v17 * v17 + v18 * v18;
          if ( v19 < v113 && (1.0 - v19 / v113) * v146 > *((float *)this + 3941) )
          {
            v20 = flt_8AAE74[(unsigned __int8)dword_8AAE70++];
            if ( v20 < *((float *)this + 3942) )
            {
              RepairServiceStateDispatcher(4);
              v21 = *((float *)this + 3374) * *((float *)this + 3945)
                  + *((float *)this + 3373) * *((float *)this + 3944);
              v22 = *((float *)this + 3943) * *((float *)this + 3372);
              v124 = *((_DWORD *)this + 3371);
              v23 = v21 + v22;
              v24 = *((float *)this + 3377) * *((float *)this + 3945)
                  + *((float *)this + 3376) * *((float *)this + 3944)
                  + *((float *)this + 3375) * *((float *)this + 3943);
              v127 = *((float *)this + 3380) * *((float *)this + 3945)
                   + *((float *)this + 3379) * *((float *)this + 3944)
                   + *((float *)this + 3378) * *((float *)this + 3943);
              v125 = v23 + *((float *)this + 3381);
              v25 = v24 + *((float *)this + 3382);
              v26 = v127 + *((float *)this + 3383);
              v27 = flt_8AB274[(unsigned __int8)dword_8AAE70++];
              v125 = v27 * 0.2 + v125;
              v28 = flt_8AB274[(unsigned __int8)dword_8AAE70++];
              v126 = v28 * 0.2 + v25;
              v29 = flt_8AB274[(unsigned __int8)dword_8AAE70++];
              v127 = v29 * 0.2 + v26;
              v30 = flt_8AB274[(unsigned __int8)dword_8AAE70++];
              v131 = v30 + v30;
              v31 = flt_8AB274[(unsigned __int8)dword_8AAE70++];
              v134 = 0;
              v135 = 0;
              v132 = v31 + v31 + 5.0;
              v136 = 0;
              v32 = flt_8AB274[(unsigned __int8)dword_8AAE70++];
              v33 = *((_DWORD *)this + 3385);
              v34 = *((_DWORD *)this + 3386);
              v128 = *((_DWORD *)this + 3384);
              v129 = v33;
              v35 = *((_DWORD *)this + 1);
              v130 = v34;
              v133 = v32 + v32;
              ShortComputation_1330(dword_5EA560, 4, (float *)this + 3946, v35, 0, (float *)&v124);
            }
          }
        }
      }
      if ( *((_DWORD *)this + 835) )
      {
        if ( this[3404] )
        {
          v36 = a2[2] - *((float *)this + 3957);
          v37 = a2[1] - *((float *)this + 3956);
          v38 = v36 * v36 + v37 * v37;
          if ( v38 < v113 && (1.0 - v38 / v113) * v146 > *((float *)this + 3953) )
          {
            v39 = flt_8AAE74[(unsigned __int8)dword_8AAE70++];
            if ( v39 < *((float *)this + 3954) )
            {
              RepairServiceStateDispatcher(5);
              v40 = *((float *)this + 3374) * *((float *)this + 3957)
                  + *((float *)this + 3373) * *((float *)this + 3956);
              v41 = *((float *)this + 3955) * *((float *)this + 3372);
              v124 = *((_DWORD *)this + 3371);
              v42 = v40 + v41;
              v43 = *((float *)this + 3377) * *((float *)this + 3957)
                  + *((float *)this + 3376) * *((float *)this + 3956)
                  + *((float *)this + 3375) * *((float *)this + 3955);
              v127 = *((float *)this + 3380) * *((float *)this + 3957)
                   + *((float *)this + 3379) * *((float *)this + 3956)
                   + *((float *)this + 3378) * *((float *)this + 3955);
              v125 = v42 + *((float *)this + 3381);
              v44 = v43 + *((float *)this + 3382);
              v45 = v127 + *((float *)this + 3383);
              v46 = flt_8AB274[(unsigned __int8)dword_8AAE70++];
              v125 = v46 * 0.2 + v125;
              v47 = flt_8AB274[(unsigned __int8)dword_8AAE70++];
              v126 = v47 * 0.2 + v44;
              v48 = flt_8AB274[(unsigned __int8)dword_8AAE70++];
              v127 = v48 * 0.2 + v45;
              v49 = flt_8AB274[(unsigned __int8)dword_8AAE70++];
              v131 = v49 + v49;
              v50 = flt_8AB274[(unsigned __int8)dword_8AAE70++];
              v134 = 0;
              v135 = 0;
              v132 = v50 + v50 + 5.0;
              v136 = 0;
              v51 = flt_8AB274[(unsigned __int8)dword_8AAE70++];
              v52 = *((_DWORD *)this + 3385);
              v53 = *((_DWORD *)this + 3386);
              v128 = *((_DWORD *)this + 3384);
              v129 = v52;
              v54 = *((_DWORD *)this + 1);
              v130 = v53;
              v133 = v51 + v51;
              ShortComputation_1330(dword_5EA560, 4, (float *)this + 3958, v54, 1, (float *)&v124);
            }
          }
        }
      }
      v55 = (float *)(this + 16016);
      v56 = this + 3408;
      v57 = 0;
      v58 = (float *)(this + 16144);
      v143 = (float *)(this + 16016);
      v116 = this + 3408;
      v59 = (float *)(this + 16052);
      do
      {
        if ( *(_DWORD *)v56 )
        {
          if ( v56[64] )
          {
            v60 = a2[1] - *v59;
            v61 = a2[2] - v59[1];
            v62 = *a2 - *(v59 - 1);
            v63 = v61 * v61 + v60 * v60 + v62 * v62;
            if ( v63 < v113 && (1.0 - v63 / v113) * v146 > *(v55 - 8) )
            {
              v64 = flt_8AAE74[(unsigned __int8)dword_8AAE70++];
              if ( v64 < *v55 )
              {
                RepairServiceStateDispatcher(v57 + 6);
                v65 = *((float *)this + 3374) * v59[1] + *((float *)this + 3373) * *v59;
                v66 = *((float *)this + 3372) * *(v59 - 1);
                v124 = *((_DWORD *)this + 3371);
                v67 = v65 + v66;
                v68 = *((float *)this + 3377) * v59[1]
                    + *((float *)this + 3376) * *v59
                    + *((float *)this + 3375) * *(v59 - 1);
                v127 = *((float *)this + 3380) * v59[1]
                     + *((float *)this + 3379) * *v59
                     + *((float *)this + 3378) * *(v59 - 1);
                v125 = v67 + *((float *)this + 3381);
                v69 = v68 + *((float *)this + 3382);
                v70 = v127 + *((float *)this + 3383);
                v71 = flt_8AB274[(unsigned __int8)dword_8AAE70++];
                v125 = v71 * 0.2 + v125;
                v72 = flt_8AB274[(unsigned __int8)dword_8AAE70++];
                v126 = v72 * 0.2 + v69;
                v73 = flt_8AB274[(unsigned __int8)dword_8AAE70++];
                v127 = v73 * 0.2 + v70;
                v74 = *((float *)this + 3387) * 0.30000001;
                v75 = *((float *)this + 3388) * 0.30000001 + 5.0;
                v76 = *((float *)this + 3389) * 0.30000001;
                v134 = 0;
                v133 = v76;
                v77 = flt_8AB274[(unsigned __int8)dword_8AAE70++];
                v135 = 0;
                v131 = v77 + v77 + v74;
                v136 = 0;
                v78 = flt_8AB274[(unsigned __int8)dword_8AAE70++];
                v132 = v78 + v78 + v75;
                v79 = flt_8AB274[(unsigned __int8)dword_8AAE70++];
                v80 = *((_DWORD *)this + 3385);
                v81 = *((_DWORD *)this + 3386);
                v128 = *((_DWORD *)this + 3384);
                v129 = v80;
                v110 = *((_DWORD *)this + 1);
                v133 = v79 + v79 + v133;
                v130 = v81;
                ShortComputation_1330(dword_5EA560, 5, v58, v110, v57, (float *)&v124);
                v56 = v116;
                v55 = v143;
              }
            }
          }
        }
        ++v57;
        ++v55;
        v56 += 68;
        v59 += 3;
        v58 += 7;
        v143 = v55;
        v116 = v56;
      }
      while ( v57 < 8 );
      v5 = this + 2088;
      v82 = 0;
      v83 = (float *)(this + 15872);
      v117 = this + 2088;
      v84 = (float *)(this + 13712);
      do
      {
        if ( !*(_DWORD *)v5 )
          goto LABEL_96;
        if ( !v5[64] )
          goto LABEL_96;
        v85 = a2[1] - *v84;
        v86 = a2[2] - v84[1];
        v87 = *a2 - *(v84 - 1);
        v88 = v86 * v86 + v85 * v85 + v87 * v87;
        if ( v88 >= v113 )
          goto LABEL_96;
        v89 = (1.0 - v88 / v113) * v146;
        v144 = v89;
        if ( v89 <= *((float *)this + 3965) )
          goto LABEL_96;
        if ( v144 <= (double)*((float *)this + 3966)
          || (v90 = flt_8AAE74[(unsigned __int8)dword_8AAE70], ++dword_8AAE70, v90 >= *((float *)this + 3967)) )
        {
          if ( !*((_DWORD *)this + 3247) )
          {
            v107 = *((float *)this + 3966) - *((float *)this + 3965);
            if ( v107 > 0.0 )
            {
              v108 = (v144 - *((float *)this + 3965)) / v107;
              v145 = v108;
              if ( v108 > 1.0 )
                v145 = 1.0;
              SteeringGeometryUpdate((int *)&dbl_7C7428, v82, v145);
            }
          }
          goto LABEL_96;
        }
        RepairServiceStateDispatcher(v82);
        v91 = *((float *)this + 3373) * *v84 + *((float *)this + 3374) * v84[1];
        v92 = *((float *)this + 3372) * *(v84 - 1);
        v124 = *((_DWORD *)this + 3371);
        v93 = v91 + v92;
        v94 = *((float *)this + 3376) * *v84 + *((float *)this + 3377) * v84[1] + *((float *)this + 3375) * *(v84 - 1);
        v127 = *((float *)this + 3379) * *v84 + *((float *)this + 3380) * v84[1] + *((float *)this + 3378) * *(v84 - 1);
        v125 = v93 + *((float *)this + 3381);
        v95 = v94 + *((float *)this + 3382);
        v96 = v127 + *((float *)this + 3383);
        v97 = flt_8AB274[(unsigned __int8)dword_8AAE70++];
        v125 = v97 * 0.2 + v125;
        v98 = flt_8AB274[(unsigned __int8)dword_8AAE70++];
        v126 = v98 * 0.2 + v95;
        v99 = flt_8AB274[(unsigned __int8)dword_8AAE70++];
        v127 = v99 * 0.2 + v96;
        v100 = flt_8AB274[(unsigned __int8)dword_8AAE70++];
        v131 = v100 + v100;
        v101 = flt_8AB274[(unsigned __int8)dword_8AAE70++];
        v134 = 0;
        v135 = 0;
        v132 = v101 + v101 + 5.0;
        v136 = 0;
        v102 = flt_8AB274[(unsigned __int8)dword_8AAE70++];
        v103 = *((_DWORD *)this + 3385);
        v104 = *((_DWORD *)this + 3386);
        v128 = *((_DWORD *)this + 3384);
        v129 = v103;
        v111 = *((_DWORD *)this + 1);
        v133 = v102 + v102;
        v130 = v104;
        ShortComputation_1330(dword_5EA560, 3, v83, v111, v82, (float *)&v124);
        v105 = *((_DWORD *)this + 3693);
        if ( v105 )
        {
          v106 = v105 - 1;
          if ( v106 && (v106 != 1 || (unsigned int)v82 > 1) )
            goto LABEL_96;
        }
        else if ( v82 != 2 && v82 != 3 )
        {
          goto LABEL_96;
        }
        TireScrubReset(this);
LABEL_96:
        ++v82;
        v5 = v117 + 296;
        v84 += 62;
        v83 += 7;
        v117 += 296;
      }
      while ( v82 < 4 );
    }
  }
  else
  {
    if ( *((_DWORD *)this + 3247) != 1 )
      goto LABEL_9;
    LOBYTE(v5) = dword_7C56A8;
    if ( dword_7C56A8 != 1 && dword_7C56A8 != 3 )
      goto LABEL_9;
  }
  return (char)v5;
}

