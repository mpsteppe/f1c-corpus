int __thiscall sub_4F8120(int this, int a2)
{
  int v3; // eax
  int v4; // ebx
  int v5; // esi
  int v6; // ebx
  int v7; // edi
  int *v8; // esi
  int v9; // ecx
  float *v10; // eax
  double v11; // st7
  double v12; // st7
  double v13; // st7
  double v14; // st7
  double v15; // st7
  int v16; // eax
  double v17; // st7
  double v18; // st7
  int v19; // edx
  int v20; // edi
  int v21; // ecx
  double v22; // st6
  int v23; // ecx
  double v24; // st6
  double v25; // st6
  bool v26; // cc
  int v27; // eax
  int v28; // esi
  int v29; // edi
  int v30; // ebx
  _DWORD *v31; // esi
  int v32; // edx
  int v33; // esi
  int v34; // edi
  int v35; // ebx
  _DWORD *v36; // esi
  bool v37; // zf
  double v38; // st7
  int v39; // eax
  double v40; // st7
  int v41; // eax
  int v42; // ecx
  int v43; // edx
  int v44; // eax
  int v45; // esi
  int v46; // eax
  int v47; // edi
  _DWORD *v48; // eax
  _DWORD *v49; // ebx
  int v50; // edx
  int v51; // esi
  int v52; // ecx
  int v53; // eax
  int v54; // edi
  _DWORD *v55; // eax
  int v56; // eax
  int *v57; // eax
  int v58; // ecx
  int v59; // eax
  int v60; // esi
  float *v61; // ecx
  double v62; // st7
  double v63; // st7
  double v64; // st7
  int result; // eax
  int *v66; // esi
  int v67; // edi
  int *v68; // ecx
  int v69; // edx
  int *v70; // esi
  int v71; // edi
  int v72; // edx
  int *v73; // esi
  int v74; // edi
  int v75; // edx
  const char *v76; // esi
  int v77; // ebx
  unsigned int v78; // eax
  char *v79; // edi
  int v81; // [esp-8h] [ebp-1A4h]
  int v82; // [esp+0h] [ebp-19Ch]
  int *v83; // [esp+Ch] [ebp-190h]
  int v84; // [esp+24h] [ebp-178h]
  int v85; // [esp+28h] [ebp-174h] BYREF
  int v86; // [esp+2Ch] [ebp-170h] BYREF
  int Buffer; // [esp+30h] [ebp-16Ch] BYREF
  int v88; // [esp+34h] [ebp-168h]
  int v89; // [esp+38h] [ebp-164h]
  int v90; // [esp+3Ch] [ebp-160h]
  int v91; // [esp+40h] [ebp-15Ch]
  int v92; // [esp+44h] [ebp-158h]
  void *v93; // [esp+58h] [ebp-144h]
  _DWORD *v94; // [esp+70h] [ebp-12Ch]
  int v95; // [esp+74h] [ebp-128h] BYREF
  _DWORD v96[6]; // [esp+78h] [ebp-124h] BYREF
  int v97; // [esp+90h] [ebp-10Ch]
  int v98; // [esp+98h] [ebp-104h]
  int v99; // [esp+9Ch] [ebp-100h]
  int v100; // [esp+A0h] [ebp-FCh]
  float v101; // [esp+A8h] [ebp-F4h]
  float v102; // [esp+ACh] [ebp-F0h]
  int v103; // [esp+B0h] [ebp-ECh] BYREF
  char v104[4]; // [esp+B8h] [ebp-E4h] BYREF
  float v105; // [esp+BCh] [ebp-E0h]
  float v106; // [esp+C0h] [ebp-DCh]
  float v107; // [esp+C4h] [ebp-D8h]
  int v108; // [esp+C8h] [ebp-D4h] BYREF
  float v109; // [esp+D0h] [ebp-CCh]
  float v110; // [esp+D4h] [ebp-C8h]
  float v111; // [esp+D8h] [ebp-C4h]
  float v112; // [esp+DCh] [ebp-C0h]
  float v113; // [esp+E0h] [ebp-BCh]
  float v114; // [esp+E4h] [ebp-B8h]
  float v115; // [esp+E8h] [ebp-B4h]
  float v116; // [esp+ECh] [ebp-B0h]
  int v117; // [esp+F0h] [ebp-ACh]
  float v118; // [esp+F4h] [ebp-A8h]
  float v119; // [esp+F8h] [ebp-A4h]
  float v120; // [esp+FCh] [ebp-A0h]
  float v121; // [esp+100h] [ebp-9Ch]
  float v122; // [esp+104h] [ebp-98h]
  int v123; // [esp+108h] [ebp-94h]
  float v124; // [esp+10Ch] [ebp-90h]
  int v125; // [esp+110h] [ebp-8Ch]
  int v126; // [esp+118h] [ebp-84h]
  int v127; // [esp+11Ch] [ebp-80h]
  int v128; // [esp+140h] [ebp-5Ch]
  int v129; // [esp+158h] [ebp-44h]
  int v130; // [esp+160h] [ebp-3Ch]
  int v131; // [esp+170h] [ebp-2Ch]
  int v132; // [esp+17Ch] [ebp-20h]
  int v133; // [esp+18Ch] [ebp-10h]

  v3 = *(_DWORD *)(this + 152);
  v100 = 0;
  if ( v3 > 0 )
  {
    v99 = 0;
    while ( 1 )
    {
      v4 = *(_DWORD *)(this + 156);
      v5 = *(_DWORD *)(v4 + v99 + 112);
      v6 = v99 + v4;
      v7 = 0;
      if ( *(int *)(v5 + 24) > 0 )
      {
        do
        {
          v98 = *(_DWORD *)(*(_DWORD *)(v5 + 32) + 4 * v7);
          if ( !_stricmp(*(const char **)(v98 + 4), "Bip01") )
            break;
          ++v7;
        }
        while ( v7 < *(_DWORD *)(v5 + 24) );
        if ( v7 != *(_DWORD *)(v5 + 24) )
        {
          if ( *(_DWORD *)(v6 + 40) )
          {
            v8 = (int *)(v98 + 48);
            if ( *(int *)(v98 + 48) > 0 )
              break;
          }
        }
      }
LABEL_34:
      v26 = ++v100 < *(_DWORD *)(this + 152);
      v99 += 120;
      if ( !v26 )
        goto LABEL_35;
    }
    v9 = *(_DWORD *)(v6 + 52);
    v101 = *(float *)(*(_DWORD *)(v6 + 112) + 20);
    v102 = 0.0;
    if ( v9 != 1203982208 && *(_DWORD *)(v6 + 64) != 1203982208 )
    {
      if ( *(float *)(v6 + 52) <= (double)*(float *)(v6 + 64) )
        v101 = *(float *)(v6 + 64);
      else
        v101 = *(float *)(v6 + 52);
      if ( *(float *)(v6 + 52) >= (double)*(float *)(v6 + 64) )
        v102 = *(float *)(v6 + 64);
      else
        v102 = *(float *)(v6 + 52);
    }
    sub_4058B0(v98 + 48, &v103, v101);
    sub_4058B0((int)v8, &v108, v102);
    v10 = **(float ***)(this + 4);
    v110 = v10[867] + v10[695];
    v11 = v10[868];
    v119 = v110;
    v111 = v11 + v10[696];
    v12 = v10[869];
    v120 = v111;
    v112 = v12 + v10[697];
    v13 = v10[1015];
    v121 = v112;
    v116 = v13 + v10[695];
    v14 = v10[1016];
    v122 = v116;
    *(float *)&v117 = v14 + v10[696];
    v15 = v10[1017] + v10[697];
    v123 = v117;
    v118 = v15;
    v124 = v118;
    v113 = v116 - v110;
    v105 = v113;
    v114 = *(float *)&v117 - v111;
    v106 = v114;
    v16 = *(_DWORD *)(v6 + 40);
    v115 = v118 - v112;
    v17 = 1.0;
    v107 = v115;
    switch ( v16 )
    {
      case 1:
        v18 = *(float *)v104 - v109;
        break;
      case 2:
        v18 = v109 - *(float *)v104;
        break;
      case 3:
        v18 = *(float *)v104 - v109 - 0.079999998;
        break;
      default:
        goto LABEL_24;
    }
    v17 = v107 / v18;
LABEL_24:
    v19 = 0;
    if ( *v8 > 0 )
    {
      v20 = 0;
      do
      {
        v21 = v8[2];
        v22 = *(float *)(v21 + v20 + 12);
        v23 = v20 + v21;
        if ( v22 >= v102 )
        {
          v24 = *(float *)(v23 + 8);
          if ( *(float *)(v23 + 12) <= (double)v101 )
          {
            v25 = (v24 - v109) * v17 + v109;
          }
          else if ( *(_DWORD *)(v6 + 40) == 1 )
          {
            v25 = v24 - (*(float *)v104 - v109 - v107);
          }
          else
          {
            v25 = v24 + v109 - *(float *)v104 - v107;
          }
          *(float *)(v23 + 8) = v25;
        }
        ++v19;
        v20 += 16;
      }
      while ( v19 < *v8 );
    }
    goto LABEL_34;
  }
LABEL_35:
  if ( *(int *)this >= 4 && *(int *)this <= 5 )
  {
    v27 = *(_DWORD *)(this + 140);
    if ( v27 )
    {
      v28 = *(_DWORD *)(v27 + 8);
      v29 = ((int (__thiscall *)(int, const char *))loc_405290)(v28, "Bip01 L UpperArm");
      v30 = ((int (__thiscall *)(int, const char *))loc_405290)(v28, "Bip01 L Forearm");
      v97 = ((int (__thiscall *)(int, const char *))loc_405290)(v28, "Bip01 L Hand");
      v31 = operator new(0x3Cu);
      v96[5] = v31;
      v133 = 0;
      if ( v31 )
      {
        sub_5C15B0(*(_DWORD *)(*(_DWORD *)(this + 140) + 8), v29, v30, v97);
        *v31 = &off_7146BC;
        v31[14] = 0;
      }
      else
      {
        v31 = 0;
      }
      v32 = *(_DWORD *)(this + 140);
      *(_DWORD *)(this + 176) = v31;
      v33 = *(_DWORD *)(v32 + 8);
      v132 = -1;
      v34 = ((int (__thiscall *)(int, const char *))loc_405290)(v33, "Bip01 R UpperArm");
      v35 = ((int (__thiscall *)(int, const char *))loc_405290)(v33, "Bip01 R Forearm");
      v95 = ((int (__thiscall *)(int, const char *))loc_405290)(v33, "Bip01 R Hand");
      v36 = operator new(0x3Cu);
      v94 = v36;
      v131 = 1;
      if ( v36 )
      {
        sub_5C15B0(*(_DWORD *)(*(_DWORD *)(this + 140) + 8), v34, v35, v95);
        *v36 = &off_7146BC;
        v36[14] = 0;
      }
      else
      {
        v36 = 0;
      }
      v37 = *(_DWORD *)this == 5;
      v130 = -1;
      *(_DWORD *)(this + 180) = v36;
      if ( v37 )
        v38 = 1.0;
      else
        v38 = -1.0;
      *(float *)&v96[2] = v38;
      v96[0] = 0;
      v96[1] = 0;
      sub_5C1640(v96);
      v39 = ((int (__thiscall *)(_DWORD, const char *))loc_405290)(
              *(_DWORD *)(*(_DWORD *)(this + 140) + 8),
              "FU_HandTarg_L");
      sub_5C1570(v39);
      if ( *(_DWORD *)this == 5 )
        v40 = -1.0;
      else
        v40 = 1.0;
      *(float *)&v96[1] = v40;
      v95 = 0;
      v96[0] = 0;
      sub_5C1640(&v95);
      v41 = ((int (__thiscall *)(_DWORD, const char *))loc_405290)(
              *(_DWORD *)(*(_DWORD *)(this + 140) + 8),
              "FU_HandTarg_R");
      sub_5C1570(v41);
      v93 = operator new(0x40u);
      v129 = 2;
      if ( v93 )
      {
        v42 = *(_DWORD *)(*(_DWORD *)(this + 140) + 8);
        v92 = *(_DWORD *)(this + 180);
        v91 = *(_DWORD *)(this + 176);
        v43 = *(_DWORD *)(this + 4);
        v90 = this;
        v89 = v43;
        v88 = *(_DWORD *)(this + 204);
        Buffer = v42;
        v44 = sub_4F0760();
      }
      else
      {
        v44 = 0;
      }
      *(_DWORD *)(this + 172) = v44;
      v86 = v44;
      v128 = -1;
      sub_4F80B0();
      v85 = *(_DWORD *)(this + 176);
      sub_4F80B0();
      v84 = *(_DWORD *)(this + 180);
      sub_4F80B0();
      *(_DWORD *)(*(_DWORD *)(this + 176) + 56) = *(_DWORD *)(this + 172);
      *(_DWORD *)(*(_DWORD *)(this + 180) + 56) = *(_DWORD *)(this + 172);
      (*(void (__thiscall **)(_DWORD, _DWORD, int, int, int, int, int, int, int, int, int))(**(_DWORD **)(this + 172)
                                                                                          + 20))(
        *(_DWORD *)(this + 172),
        0,
        v84,
        v85,
        v86,
        Buffer,
        v88,
        v89,
        v90,
        v91,
        v92);
      (*(void (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)(this + 176) + 20))(*(_DWORD *)(this + 176), 0);
      (*(void (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)(this + 180) + 20))(*(_DWORD *)(this + 180), 0);
    }
  }
  if ( *(int *)this >= 7 && *(int *)this <= 8 && *(_DWORD *)(this + 140) )
  {
    v45 = 1;
    *(_DWORD *)(this + 228) = 0;
    sprintf((char *const)&Buffer, "Bone%02d", 1);
    while ( sub_405320() )
    {
      ++v45;
      ++*(_DWORD *)(this + 228);
      sprintf((char *const)&v86, "Bone%02d", v45);
    }
    v46 = *(_DWORD *)(this + 228);
    if ( v46 )
    {
      v47 = 1;
      *(_DWORD *)(this + 232) = operator new(4 * v46);
      for ( *(_DWORD *)(this + 228) = 0; v47 < v45; ++*(_DWORD *)(this + 228) )
      {
        sprintf((char *const)&v85, "Bone%02d", v47);
        v83 = &v85;
        *(_DWORD *)(*(_DWORD *)(this + 232) + 4 * *(_DWORD *)(this + 228)) = sub_405320();
        ++v47;
      }
      v48 = operator new(0x1Cu);
      v127 = 3;
      if ( v48 )
        v49 = sub_4F16D0(v48, *(_DWORD *)(*(_DWORD *)(this + 140) + 8), this);
      else
        v49 = 0;
      v50 = *(_DWORD *)(this + 140);
      *(_DWORD *)(this + 236) = v49;
      v51 = *(_DWORD *)(v50 + 8);
      v52 = *(_DWORD *)(v51 + 472);
      v53 = *(_DWORD *)(v51 + 468) + 1;
      v127 = -1;
      *(_DWORD *)(v51 + 468) = v53;
      if ( v52 < v53 )
      {
        v54 = v53 + 1;
        sub_4F14D0((int)v83);
        *(_DWORD *)(v51 + 476) = sub_5A8CF0(*(void **)(v51 + 476), 4 * v54, 2, 16, 2);
        *(_DWORD *)(v51 + 472) = v54;
      }
      v55 = (_DWORD *)(*(_DWORD *)(v51 + 476) + 4 * (*(_DWORD *)(v51 + 468) - 1));
      if ( v55 )
        *v55 = v49;
      (*(void (__thiscall **)(_DWORD, int))(**(_DWORD **)(this + 236) + 20))(*(_DWORD *)(this + 236), 1);
    }
    v56 = *(_DWORD *)(this + 136);
    if ( v56 )
    {
      if ( *(int *)(v56 + 544) > 0 )
      {
        v57 = *(int **)(v56 + 532);
        if ( v57 )
        {
          v58 = *v57;
          if ( *v57 )
          {
            *(_DWORD *)(v58 + 20) = 1080184559;
            v59 = 0;
            v60 = v58 + 24;
            do
            {
              v61 = v59 >= 8 ? 0 : (float *)v60;
              if ( (v59 & 2) != 0 )
                v62 = -2.5;
              else
                v62 = 2.5;
              *v61 = v62;
              if ( (v59 & 4) != 0 )
                v63 = 2.5;
              else
                v63 = -2.5;
              *(float *)(v59 >= 8 ? 4 : v60 + 4) = v63;
              if ( (((unsigned __int8)v59 ^ (unsigned __int8)(v59 >> 1)) & 1) != 0 )
                v64 = 2.5;
              else
                v64 = -2.5;
              ++v59;
              v61[2] = v64;
              v60 += 12;
            }
            while ( v59 < 8 );
          }
        }
      }
    }
  }
  result = *(_DWORD *)this;
  if ( *(int *)this >= 1 && result <= 5 && *(_DWORD *)(this + 140) )
  {
    v66 = (int *)operator new(0x18u);
    v126 = 4;
    if ( v66 )
    {
      v67 = *(_DWORD *)(this + 204);
      sub_5BFC50(*(_DWORD *)(*(_DWORD *)(this + 140) + 8));
      *v66 = (int)&off_714684;
      v66[3] = this;
      v66[4] = v67;
      v66[5] = 0;
      v68 = v66;
    }
    else
    {
      v68 = 0;
    }
    *(_DWORD *)(this + 216) = v68;
    v69 = *v68;
    v126 = -1;
    (*(void (__thiscall **)(int *, _DWORD))(v69 + 20))(v68, 0);
    v82 = *(_DWORD *)(this + 216);
    sub_4F80B0();
    v70 = (int *)operator new(0x18u);
    v125 = 5;
    if ( v70 )
    {
      v71 = *(_DWORD *)(this + 208);
      sub_5BFC50(*(_DWORD *)(*(_DWORD *)(this + 140) + 8));
      *v70 = (int)&off_714684;
      v70[3] = this;
      v70[4] = v71;
      v70[5] = 0;
    }
    else
    {
      v70 = 0;
    }
    *(_DWORD *)(this + 220) = v70;
    v72 = *v70;
    v125 = -1;
    (*(void (__thiscall **)(int *, _DWORD, int))(v72 + 20))(v70, 0, v82);
    v81 = *(_DWORD *)(this + 220);
    sub_4F80B0();
    v73 = (int *)operator new(0x18u);
    v123 = 6;
    if ( v73 )
    {
      v74 = *(_DWORD *)(this + 212);
      sub_5BFC50(*(_DWORD *)(*(_DWORD *)(this + 140) + 8));
      *v73 = (int)&off_714684;
      v73[3] = this;
      v73[4] = v74;
      v73[5] = 0;
    }
    else
    {
      v73 = 0;
    }
    *(_DWORD *)(this + 224) = v73;
    v75 = *v73;
    v123 = -1;
    (*(void (__thiscall **)(int *, _DWORD, int))(v75 + 20))(v73, 0, v81);
    result = sub_4F80B0();
  }
  v76 = (const char *)v123;
  if ( v123 )
  {
    result = *(_DWORD *)(this + 136);
    if ( result )
    {
      if ( *(int *)this >= 1 && *(int *)this <= 5 && *(int *)(result + 544) > 0 )
      {
        result = *(_DWORD *)(result + 532);
        if ( result )
        {
          if ( *(_DWORD *)result )
          {
            result = sub_5EA5D0(0);
            if ( result )
            {
              v77 = result + 4;
              result = strncmp((const char *)(result + 4), "_PITCREW_", 9u);
              if ( result )
              {
                strcpy((char *)v96, "PITCREW");
                v78 = strlen(v76) + 1;
                v79 = (char *)&v95 + 3;
                while ( *++v79 )
                  ;
                qmemcpy(v79, v76, v78);
                sub_5E9C00(0, v96);
                sprintf(v104, "_PITCREW_%03d", *(_DWORD *)(**(_DWORD **)(this + 4) + 22468));
                result = sub_630FE0(v77, v104, 63);
                *(_BYTE *)(v77 + 63) = 0;
              }
            }
          }
        }
      }
    }
  }
  return result;
}
