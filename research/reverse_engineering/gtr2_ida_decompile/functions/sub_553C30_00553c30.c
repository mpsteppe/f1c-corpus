void __usercall sub_553C30(int a1@<ecx>, int a2@<edi>)
{
  int v3; // ecx
  int v4; // ecx
  _DWORD *v5; // eax
  _DWORD *v6; // edi
  double v7; // st7
  int v8; // edi
  int i; // eax
  int j; // eax
  int v11; // ebp
  char *v12; // eax
  const char *v13; // ebx
  char *v14; // edx
  char v15; // cl
  char *v16; // edi
  char *v18; // edi
  _DWORD *v20; // eax
  char *v21; // eax
  _DWORD *v22; // eax
  char *v23; // eax
  _DWORD *v24; // eax
  char *v25; // eax
  _DWORD *v26; // eax
  char *v27; // eax
  _DWORD *v28; // eax
  char *v29; // eax
  _DWORD *v30; // eax
  char *v31; // eax
  _DWORD *v32; // eax
  char *v33; // eax
  _DWORD *v34; // eax
  char *v35; // eax
  _DWORD *v36; // eax
  char *v37; // eax
  _DWORD *v38; // eax
  char *v39; // eax
  _DWORD *v40; // eax
  char *v41; // eax
  _DWORD *v42; // eax
  char *v43; // eax
  int v44; // ecx
  _DWORD *v45; // eax
  char *v46; // eax
  size_t v47; // kr10_4
  _DWORD *v48; // eax
  char *v49; // eax
  _DWORD *v50; // eax
  char *v51; // eax
  _DWORD *v52; // eax
  char *v53; // eax
  _DWORD *v54; // eax
  char *v55; // eax
  _DWORD *v56; // eax
  char *v57; // eax
  _DWORD *v58; // eax
  char *v59; // eax
  double v60; // st7
  char v61; // al
  int v62; // edi
  double v63; // st7
  int v64; // ecx
  int v65; // ecx
  const char *v66; // ebx
  char *v67; // eax
  char *v68; // edx
  char v69; // cl
  char *v70; // edi
  char *v72; // edi
  _DWORD *v74; // eax
  char *v75; // eax
  _DWORD *v76; // eax
  char *v77; // eax
  _DWORD *v78; // eax
  char *v79; // eax
  _DWORD *v80; // eax
  char *v81; // eax
  int v82; // ecx
  _DWORD *v83; // eax
  char *v84; // eax
  _DWORD *v85; // eax
  char *v86; // eax
  double v87; // st7
  double v88; // st7
  _DWORD *v89; // eax
  char *v90; // eax
  float *v91; // ecx
  char v93; // [esp+48h] [ebp-338h]
  int wSecond; // [esp+4Ch] [ebp-334h] BYREF
  float v95; // [esp+50h] [ebp-330h] BYREF
  int v96; // [esp+54h] [ebp-32Ch] BYREF
  int v97; // [esp+58h] [ebp-328h]
  int v98; // [esp+5Ch] [ebp-324h] BYREF
  int v99; // [esp+60h] [ebp-320h]
  char *v100; // [esp+64h] [ebp-31Ch]
  struct _SYSTEMTIME SystemTime; // [esp+68h] [ebp-318h] BYREF
  char v102[63]; // [esp+78h] [ebp-308h] BYREF
  char v103; // [esp+B7h] [ebp-2C9h] BYREF
  char v104[64]; // [esp+B8h] [ebp-2C8h] BYREF
  char String1[120]; // [esp+F8h] [ebp-288h] BYREF
  int v106; // [esp+170h] [ebp-210h]
  int v107; // [esp+174h] [ebp-20Ch]
  int v108; // [esp+178h] [ebp-208h]
  int v109; // [esp+17Ch] [ebp-204h]
  int v110; // [esp+180h] [ebp-200h]
  int v111; // [esp+184h] [ebp-1FCh]
  int v112; // [esp+18Ch] [ebp-1F4h]
  int v113; // [esp+1A8h] [ebp-1D8h]
  char v114; // [esp+1F7h] [ebp-189h] BYREF
  char v115[63]; // [esp+1F8h] [ebp-188h] BYREF
  char v116; // [esp+237h] [ebp-149h] BYREF
  char v117[63]; // [esp+238h] [ebp-148h] BYREF
  char v118; // [esp+277h] [ebp-109h] BYREF
  char v119[64]; // [esp+278h] [ebp-108h] BYREF
  int v120; // [esp+37Ch] [ebp-4h]

  if ( (unsigned __int8)sub_5612D0((int)byte_FAE910, 2, "\\Dev\\Src\\Copperhead\\App\\Source\\steward.cpp", 4967) )
    sub_561210((int)byte_FAE910, "Entered Steward::Restart()", v93);
  *(_DWORD *)(a1 + 208) = 0;
  *(_DWORD *)(a1 + 248) = 0;
  *(_BYTE *)(a1 + 252) = 0;
  *(_DWORD *)(a1 + 232) = 1065353216;
  *(_DWORD *)(a1 + 360) = 0;
  sub_551380();
  v3 = *(_DWORD *)(a1 + 304);
  *(_DWORD *)(a1 + 300) = 1;
  if ( v3 )
    sub_5E37F0(1, 0, 0);
  if ( *(_DWORD *)(a1 + 308) )
    sub_5E37F0(1, 0, 0);
  v4 = *(_DWORD *)(a1 + 316);
  *(_DWORD *)(a1 + 312) = 2;
  if ( v4 )
    sub_5E37F0(2, 0, 0);
  if ( *(_DWORD *)(a1 + 320) )
    sub_5E37F0(2, 0, 0);
  v5 = *(_DWORD **)(a1 + 336);
  *(_BYTE *)(a1 + 328) = 0;
  *(_DWORD *)(a1 + 344) = -831624408;
  v6 = (_DWORD *)*v5;
  if ( (_DWORD *)*v5 != v5 )
  {
    do
    {
      sub_42F660((_DWORD *)v6[2], 0);
      v6 = (_DWORD *)*v6;
    }
    while ( v6 != *(_DWORD **)(a1 + 336) );
  }
  *(_DWORD *)(a1 + 284) = 2139095039;
  *(_DWORD *)(a1 + 240) = 2139095039;
  *(_BYTE *)(a1 + 244) = 0;
  *(_BYTE *)(a1 + 253) = 0;
  v7 = flt_BE08A4[(unsigned __int8)dword_BE08A0++] * 30.0;
  *(float *)(a1 + 236) = v7 + 50.0;
  sub_52B190(&byte_9034D0, 0);
  v8 = a1 + 480;
  *(_DWORD *)(a1 + 356) = 0;
  *(_DWORD *)(a1 + 348) = 0;
  *(_DWORD *)(a1 + 352) = 5;
  *(_BYTE *)(a1 + 280) = 0;
  *(_BYTE *)(a1 + 480) = 0;
  for ( i = 0; i < 104; ++i )
  {
    *(_DWORD *)(v8 + 8 * i + 4) = -2;
    *(_DWORD *)(v8 + 8 * i + 8) = -1082130432;
  }
  *(_DWORD *)(a1 + 1316) = 0;
  for ( j = 0; j < 104; ++j )
  {
    *(_DWORD *)(v8 + 8 * j + 840) = -2;
    *(_DWORD *)(v8 + 8 * j + 844) = -1082130432;
  }
  *(_DWORD *)(a1 + 2152) = 0;
  *(_DWORD *)(a1 + 2156) = 0;
  *(_DWORD *)(a1 + 2264) = 0;
  memset((void *)(a1 + 2160), 0xFFu, 0x68u);
  *(_DWORD *)(a1 + 2268) = 0;
  v11 = *(_DWORD *)dword_B640C8;
  v97 = *(_DWORD *)dword_B640C8;
  if ( byte_FADD28 )
  {
    v11 = sub_54B420(dword_BE27B0);
    v97 = v11;
  }
  v12 = sub_42FEC0(v11, 0, 1);
  v13 = v12;
  v100 = v12;
  v14 = (char *)(v117 - v12);
  do
  {
    v15 = *v12;
    v12[(_DWORD)v14] = *v12;
    ++v12;
  }
  while ( v15 );
  v16 = &v116;
  while ( *++v16 )
    ;
  *(_DWORD *)v16 = &unk_796144;
  strcpy(v115, v13);
  v18 = &v114;
  while ( *++v18 )
    ;
  strcpy(v18, "Start");
  if ( !v11 || v11 == 5 || v11 == 6 )
    strcpy(v102, "RacePitKPH");
  else
    strcpy(v102, "NormalPitKPH");
  *(_DWORD *)(a1 + 272) = 1102169884;
  *(_DWORD *)(a1 + 276) = 1102169884;
  strcpy((char *)(a1 + 254), "Wednesday");
  *(_DWORD *)(a1 + 268) = 1190993920;
  v99 = sub_616840("DefaultScoring");
  if ( v99 )
  {
    v20 = (_DWORD *)sub_616630("FormationSpeedKPH");
    if ( v20 )
    {
      v21 = sub_48D380(v20);
      *(float *)(a1 + 276) = atof(v21) * 0.2777777777777778;
    }
    v22 = (_DWORD *)sub_616630(v102);
    if ( v22 )
    {
      v23 = sub_48D380(v22);
      *(float *)(a1 + 272) = atof(v23) * 0.2777777777777778;
    }
    v24 = (_DWORD *)sub_616630(v117);
    if ( v24 )
    {
      v25 = sub_48D380(v24);
      sub_630FE0(a1 + 254, v25, 11);
      *(_BYTE *)(a1 + 265) = 0;
    }
    v26 = (_DWORD *)sub_616630(v115);
    if ( v26 )
    {
      v95 = 0.0;
      v27 = sub_48D380(v26);
      if ( sscanf(v27, "%d:%d:%f", &v98, &v96, &v95) >= 2 )
        *(float *)(a1 + 268) = (double)v98 * 3600.0 + (double)v96 * 60.0 + v95;
    }
    if ( (unsigned __int8)sub_4735A0() && (unsigned __int8)sub_4745A0(&dword_B6CBA8) )
    {
      sub_4744E0(String1);
      v120 = 0;
      if ( sub_4747D0(&dword_B6CBA8, (int)String1, 0) )
      {
        v96 = 60 * v111;
        *(float *)(a1 + 228) = (float)(60 * v111);
      }
      v120 = -1;
      nullsub_7(String1);
    }
    else
    {
      v28 = (_DWORD *)sub_616630("RaceTime");
      if ( v28 )
      {
        v29 = sub_48D380(v28);
        if ( sscanf(v29, "%f", &v96) == 1 )
          *(float *)(a1 + 228) = *(float *)&v96 * 60.0;
      }
      v30 = (_DWORD *)sub_616630("RaceTimeScaled");
      if ( v30 )
      {
        v31 = sub_48D380(v30);
        if ( sscanf(v31, "%f", &v96) == 1 )
          *(float *)(a1 + 228) = flt_B728A4 * *(float *)&v96 * 60.0;
      }
    }
  }
  v98 = sub_53A250(0);
  if ( v98 )
  {
    v32 = (_DWORD *)sub_616630("FormationSpeedKPH");
    if ( v32 )
    {
      v33 = sub_48D380(v32);
      *(float *)(a1 + 276) = atof(v33) * 0.2777777777777778;
    }
    v34 = (_DWORD *)sub_616630(v102);
    if ( v34 )
    {
      v35 = sub_48D380(v34);
      *(float *)(a1 + 272) = atof(v35) * 0.2777777777777778;
    }
    v36 = (_DWORD *)sub_616630(v117);
    if ( v36 )
    {
      v37 = sub_48D380(v36);
      sub_630FE0(a1 + 254, v37, 11);
      *(_BYTE *)(a1 + 265) = 0;
    }
    v38 = (_DWORD *)sub_616630(v115);
    if ( v38 )
    {
      v95 = 0.0;
      v39 = sub_48D380(v38);
      if ( sscanf(v39, "%d:%d:%f", &v96, &wSecond, &v95) >= 2 )
        *(float *)(a1 + 268) = (double)v96 * 3600.0 + (double)wSecond * 60.0 + v95;
    }
    if ( (unsigned __int8)sub_4735A0() && (unsigned __int8)sub_4745A0(&dword_B6CBA8) )
    {
      sub_4744E0(String1);
      v120 = 1;
      if ( sub_4747D0(&dword_B6CBA8, (int)String1, 0) )
      {
        wSecond = 60 * v111;
        *(float *)(a1 + 228) = (float)(60 * v111);
      }
      v120 = -1;
      nullsub_7(String1);
    }
    else
    {
      v40 = (_DWORD *)sub_616630("RaceTime");
      if ( v40 )
      {
        v41 = sub_48D380(v40);
        if ( sscanf(v41, "%f", &wSecond) == 1 )
          *(float *)(a1 + 228) = *(float *)&wSecond * 60.0;
      }
      v42 = (_DWORD *)sub_616630("RaceTimeScaled");
      if ( v42 )
      {
        v43 = sub_48D380(v42);
        if ( sscanf(v43, "%f", &wSecond) == 1 )
          *(float *)(a1 + 228) = flt_B728A4 * *(float *)&wSecond * 60.0;
      }
    }
  }
  if ( (unsigned __int8)sub_4735A0() )
  {
    sub_4744E0(String1);
    v120 = 2;
    if ( sub_4747D0(&dword_B6CBA8, (int)String1, 0) )
      dword_B64138 = v112;
    else
      dword_B64138 = dword_B7000C;
    v120 = -1;
    nullsub_7(String1);
  }
  else
  {
    dword_B64138 = dword_B7000C;
  }
  if ( sub_616840("SceneOrder") )
  {
    v44 = dword_BE1CD8 + 396 * dword_BE1CD4;
    if ( v44 )
    {
      if ( sub_616630((char *)(v44 + 260)) )
      {
        v45 = (_DWORD *)sub_616630("StartMode");
        if ( v45 )
        {
          v46 = sub_48D380(v45);
          if ( sscanf(v46, "%s", String1) >= 0 )
          {
            v47 = strlen(String1);
            if ( !_strnicmp(String1, "StandingStart", v47) )
            {
              dword_B64138 = 0;
            }
            else if ( !_strnicmp(String1, "FormationRollingStart", v47) )
            {
              dword_B64138 = 1;
            }
          }
        }
        v48 = (_DWORD *)sub_616630("FormationSpeedKPH");
        if ( v48 )
        {
          v49 = sub_48D380(v48);
          *(float *)(a1 + 276) = atof(v49) * 0.2777777777777778;
        }
        v50 = (_DWORD *)sub_616630(v102);
        if ( v50 )
        {
          v51 = sub_48D380(v50);
          *(float *)(a1 + 272) = atof(v51) * 0.2777777777777778;
        }
        v52 = (_DWORD *)sub_616630(v117);
        if ( v52 )
        {
          v53 = sub_48D380(v52);
          sub_630FE0(a1 + 254, v53, 11);
          *(_BYTE *)(a1 + 265) = 0;
        }
        v54 = (_DWORD *)sub_616630(v115);
        if ( v54 )
        {
          v95 = 0.0;
          v55 = sub_48D380(v54);
          if ( sscanf(v55, "%d:%d:%f", &wSecond, &v96, &v95) >= 2 )
            *(float *)(a1 + 268) = (double)wSecond * 3600.0 + (double)v96 * 60.0 + v95;
        }
        if ( (unsigned __int8)sub_4735A0() && (unsigned __int8)sub_4745A0(&dword_B6CBA8) )
        {
          sub_4744E0(String1);
          v120 = 3;
          if ( sub_4747D0(&dword_B6CBA8, (int)String1, 0) )
          {
            wSecond = 60 * v111;
            *(float *)(a1 + 228) = (float)(60 * v111);
          }
          v120 = -1;
          nullsub_7(String1);
        }
        else
        {
          v56 = (_DWORD *)sub_616630("RaceTime");
          if ( v56 )
          {
            v57 = sub_48D380(v56);
            if ( sscanf(v57, "%f", &wSecond) == 1 )
              *(float *)(a1 + 228) = *(float *)&wSecond * 60.0;
          }
          v58 = (_DWORD *)sub_616630("RaceTimeScaled");
          if ( v58 )
          {
            v59 = sub_48D380(v58);
            if ( sscanf(v59, "%f", &wSecond) == 1 )
              *(float *)(a1 + 228) = flt_B728A4 * *(float *)&wSecond * 60.0;
          }
        }
      }
    }
  }
  if ( byte_B722E4 )
  {
    v60 = *(float *)&dword_B72A00;
    *(_DWORD *)(a1 + 216) = 0x7FFFFFFF;
    *(float *)(a1 + 228) = v60 * 86400.0;
  }
  v61 = sub_4735A0();
  v62 = v97;
  if ( v61 && v97 == 6 )
  {
    sub_4744E0(String1);
    v120 = 4;
    if ( sub_4747D0(&dword_B6CBA8, (int)String1, 0) )
      *(float *)(a1 + 268) = (double)v113 * 3600.0;
    v120 = -1;
    nullsub_7(String1);
    goto LABEL_125;
  }
  if ( (unsigned __int8)sub_4735A0() )
    goto LABEL_125;
  if ( dword_BE1204 == 2 )
  {
    v63 = sub_521040(&dword_BE120C);
LABEL_124:
    *(float *)(a1 + 268) = v63;
    goto LABEL_125;
  }
  if ( (!v62 || v62 == 6) && *(_DWORD *)dword_B72314 != 4 && !byte_B722E4 )
    *(float *)(a1 + 268) = (double)dword_B6FF58 * 3600.0;
  if ( byte_B6FF7C )
  {
    GetLocalTime(&SystemTime);
    wSecond = SystemTime.wSecond;
    v63 = (double)SystemTime.wMinute * 60.0 + (double)SystemTime.wHour * 3600.0 + (double)SystemTime.wSecond;
    goto LABEL_124;
  }
LABEL_125:
  switch ( *(_DWORD *)dword_B640C8 )
  {
    case 0:
      sub_430250(&dword_B640C0, 5u);
      *(_DWORD *)(a1 + 216) = 0x7FFFFFFF;
      *(_DWORD *)(a1 + 220) = 0;
      *(_DWORD *)(a1 + 224) = 2139095039;
      v64 = *(_DWORD *)(a1 + 316);
      *(_DWORD *)(a1 + 312) = 1;
      if ( v64 )
        sub_5E37F0(1, 0, 0);
      if ( *(_DWORD *)(a1 + 320) )
        sub_5E37F0(1, 0, 0);
      break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
      sub_430250(&dword_B640C0, 0);
      *(_DWORD *)(a1 + 220) = 1106247680;
      v65 = *(_DWORD *)(a1 + 316);
      *(_DWORD *)(a1 + 312) = 2;
      if ( v65 )
        sub_5E37F0(2, 0, 0);
      if ( *(_DWORD *)(a1 + 320) )
        sub_5E37F0(2, 0, 0);
      if ( *(_DWORD *)dword_B640C8 == 3 || *(_DWORD *)dword_B640C8 == 4 )
        *(_DWORD *)(a1 + 216) = dword_B724D8;
      else
        *(_DWORD *)(a1 + 216) = 0x7FFFFFFF;
      switch ( *(_DWORD *)dword_B640C8 )
      {
        case 1:
        case 2:
        case 3:
        case 4:
          v95 = 3600.0;
          break;
        case 5:
          v95 = 1800.0;
          break;
        default:
          break;
      }
      v66 = v100;
      v67 = v100;
      v68 = (char *)(v119 - v100);
      do
      {
        v69 = *v67;
        v68[(_DWORD)v67] = *v67;
        ++v67;
      }
      while ( v69 );
      v70 = &v118;
      while ( *++v70 )
        ;
      strcpy(v70, "Duration");
      strcpy(v104, v66);
      v72 = &v103;
      while ( *++v72 )
        ;
      strcpy(v72, "Laps");
      if ( v99 )
      {
        v74 = (_DWORD *)sub_616630(v119);
        if ( v74 )
        {
          v75 = sub_48D380(v74);
          v95 = atof(v75) * 60.0;
        }
        v76 = (_DWORD *)sub_616630(v104);
        if ( v76 )
        {
          v77 = sub_48D380(v76);
          *(_DWORD *)(a1 + 216) = atol(v77);
        }
      }
      if ( v98 )
      {
        v78 = (_DWORD *)sub_616630(v119);
        if ( v78 )
        {
          v79 = sub_48D380(v78);
          v95 = atof(v79) * 60.0;
        }
        v80 = (_DWORD *)sub_616630(v104);
        if ( v80 )
        {
          v81 = sub_48D380(v80);
          *(_DWORD *)(a1 + 216) = atol(v81);
        }
      }
      if ( sub_616840("SceneOrder") )
      {
        v82 = dword_BE1CD8 + 396 * dword_BE1CD4;
        if ( v82 )
        {
          if ( sub_616630((char *)(v82 + 260)) )
          {
            v83 = (_DWORD *)sub_616630(v119);
            if ( v83 )
            {
              v84 = sub_48D380(v83);
              v95 = atof(v84) * 60.0;
            }
            v85 = (_DWORD *)sub_616630(v104);
            if ( v85 )
            {
              v86 = sub_48D380(v85);
              *(_DWORD *)(a1 + 216) = atol(v86);
            }
          }
        }
      }
      if ( (unsigned __int8)sub_4735A0() )
      {
        if ( (unsigned __int8)sub_4745A0(&dword_B6CBA8) )
        {
          if ( byte_B73588 == 1 )
          {
            v87 = flt_B728A4 * v95;
            v95 = v87;
            if ( v87 < 600.0 && (*(_DWORD *)dword_B640C8 == 3 || *(_DWORD *)dword_B640C8 == 4) )
              v95 = 600.0;
          }
        }
      }
      if ( (unsigned __int8)sub_4735A0() && (unsigned __int8)sub_4745A0(&dword_B6CBA8) )
      {
        sub_4744E0(String1);
        v120 = 5;
        if ( sub_4747D0(&dword_B6CBA8, (int)String1, 0) && v106 != -1 )
        {
          switch ( *(_DWORD *)dword_B640C8 )
          {
            case 1:
              wSecond = 60 * v106;
              v88 = (double)(60 * v106);
              goto LABEL_181;
            case 2:
              wSecond = 60 * v107;
              v88 = (double)(60 * v107);
              goto LABEL_181;
            case 3:
              wSecond = 60 * v108;
              v88 = (double)(60 * v108);
              goto LABEL_181;
            case 4:
              wSecond = 60 * v109;
              v88 = (double)(60 * v109);
              goto LABEL_181;
            case 5:
              wSecond = 60 * v110;
              v88 = (double)(60 * v110);
LABEL_181:
              v95 = v88;
              break;
            default:
              break;
          }
        }
        v120 = -1;
        nullsub_7(String1);
      }
      *(float *)(a1 + 224) = v95 + *(float *)(a1 + 220);
      break;
    case 6:
      JUMPOUT(0x554BEF);
    default:
      break;
  }
  *(_DWORD *)(a1 + 2272) = 1065353216;
  if ( byte_B722E4 )
  {
    if ( *(_DWORD *)dword_B640C8 == 6 )
      *(float *)(a1 + 2272) = 1.0 / *(float *)&dword_B72A00;
  }
  else
  {
    v89 = (_DWORD *)sub_616840("Time Scale Factor");
    if ( v89 )
    {
      v90 = sub_48D380(v89);
      *(float *)(a1 + 2272) = atof(v90);
    }
    else
    {
      *(_DWORD *)(a1 + 2272) = dword_B70834;
    }
  }
  memset((void *)(a1 + 368), 0xFFu, 0x68u);
  *(_WORD *)(a1 + 472) = -1;
  *(_BYTE *)(a1 + 474) = -1;
  sub_536410(dword_B76270);
  v91 = *(float **)(a1 + 180);
  if ( v91 )
    sub_458080(v91);
  sub_553180(a2, 0);
}
