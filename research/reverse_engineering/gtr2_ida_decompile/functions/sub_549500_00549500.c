int __thiscall sub_549500(float *this)
{
  int v2; // eax
  _BYTE *v3; // edx
  char v4; // cl
  const char *v5; // ecx
  const char *v6; // eax
  char v7; // al
  char *v8; // ecx
  int v9; // eax
  char *v10; // edi
  char v11; // cl
  const char *v12; // edi
  char *v13; // eax
  char *v14; // esi
  char v15; // bl
  int v16; // esi
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // esi
  int v21; // eax
  int v22; // esi
  char *v23; // eax
  char *v24; // edi
  char *v25; // eax
  int v26; // eax
  int v27; // edi
  char *v28; // eax
  char *v29; // esi
  const char *v30; // ecx
  const char *v31; // eax
  char v32; // cl
  int v33; // eax
  int v34; // ebx
  int v35; // esi
  int v36; // edi
  int v37; // eax
  int v38; // ecx
  char *v39; // eax
  int v40; // eax
  int v41; // ebx
  int v42; // esi
  _DWORD *v43; // ecx
  int v44; // ecx
  int v45; // edx
  unsigned int v46; // eax
  char *v47; // edi
  char *v49; // edi
  int i; // esi
  int v52; // ebx
  int v53; // edi
  int v54; // ecx
  bool v55; // zf
  int v56; // eax
  int v57; // edx
  int v58; // ecx
  int v59; // eax
  int v60; // eax
  int v61; // eax
  int v62; // ebx
  int v63; // esi
  int v64; // eax
  int v65; // esi
  _DWORD *v66; // eax
  _DWORD *v67; // edi
  int v68; // edi
  int v69; // ebx
  int v70; // esi
  int j; // [esp+4h] [ebp-CA4h]
  void *v73; // [esp+Ch] [ebp-C9Ch]
  char *v74; // [esp+14h] [ebp-C94h] BYREF
  int v75; // [esp+18h] [ebp-C90h]
  const char *v76; // [esp+1Ch] [ebp-C8Ch]
  void *v77; // [esp+20h] [ebp-C88h]
  int v78; // [esp+24h] [ebp-C84h]
  int v79; // [esp+28h] [ebp-C80h] BYREF
  void *Block; // [esp+2Ch] [ebp-C7Ch] BYREF
  char *v81; // [esp+30h] [ebp-C78h]
  int v82; // [esp+34h] [ebp-C74h]
  float v83; // [esp+38h] [ebp-C70h]
  float v84; // [esp+3Ch] [ebp-C6Ch]
  char v85; // [esp+40h] [ebp-C68h] BYREF
  int v86; // [esp+48h] [ebp-C60h]
  int v87; // [esp+54h] [ebp-C54h]
  char *v88; // [esp+58h] [ebp-C50h]
  char *v89; // [esp+60h] [ebp-C48h]
  _DWORD v90[4]; // [esp+64h] [ebp-C44h] BYREF
  char v91[24]; // [esp+74h] [ebp-C34h] BYREF
  _BYTE v92[8]; // [esp+98h] [ebp-C10h] BYREF
  double v93[6]; // [esp+A0h] [ebp-C08h] BYREF
  int v94; // [esp+D0h] [ebp-BD8h]
  char v95[56]; // [esp+108h] [ebp-BA0h] BYREF
  char String[12]; // [esp+140h] [ebp-B68h] BYREF
  char v97[4]; // [esp+14Ch] [ebp-B5Ch] BYREF
  _BYTE v98[12]; // [esp+150h] [ebp-B58h] BYREF
  _BYTE v99[12]; // [esp+15Ch] [ebp-B4Ch] BYREF
  char v100[12]; // [esp+168h] [ebp-B40h] BYREF
  char v101[12]; // [esp+174h] [ebp-B34h] BYREF
  char v102[460]; // [esp+180h] [ebp-B28h] BYREF
  char v103[24]; // [esp+34Ch] [ebp-95Ch] BYREF
  char v104[16]; // [esp+364h] [ebp-944h] BYREF
  char v105[12]; // [esp+374h] [ebp-934h] BYREF
  int v106; // [esp+380h] [ebp-928h]
  char v107; // [esp+384h] [ebp-924h]
  char v108[4]; // [esp+38Ch] [ebp-91Ch] BYREF
  int v109; // [esp+390h] [ebp-918h]
  char v110[4]; // [esp+394h] [ebp-914h] BYREF
  char Str[512]; // [esp+398h] [ebp-910h] BYREF
  _BYTE v112[199]; // [esp+598h] [ebp-710h] BYREF
  char v113; // [esp+65Fh] [ebp-649h] BYREF
  char ArgList[248]; // [esp+660h] [ebp-648h] BYREF
  char v115[8]; // [esp+758h] [ebp-550h] BYREF
  char v116[4]; // [esp+760h] [ebp-548h] BYREF
  char v117[292]; // [esp+774h] [ebp-534h] BYREF
  char Buffer[232]; // [esp+898h] [ebp-410h] BYREF
  char v119[12]; // [esp+980h] [ebp-328h] BYREF
  char v120[12]; // [esp+98Ch] [ebp-31Ch] BYREF
  _BYTE v121[192]; // [esp+998h] [ebp-310h] BYREF
  char v122; // [esp+A58h] [ebp-250h] BYREF
  char v123[256]; // [esp+A74h] [ebp-234h] BYREF
  char v124[36]; // [esp+B74h] [ebp-134h] BYREF
  char v125; // [esp+B98h] [ebp-110h] BYREF
  int v126; // [esp+C4Ch] [ebp-5Ch]
  char v127; // [esp+C80h] [ebp-28h]
  int v128; // [esp+CA4h] [ebp-4h]

  v90[1] = 0;
  v90[0] = 0;
  sub_613B30(v92);
  memset(Str, 0, sizeof(Str));
  v128 = 0;
  v106 = 0;
  *(_DWORD *)v110 = 0;
  *(_DWORD *)v108 = 0;
  v109 = 0;
  v107 = 1;
  if ( (unsigned __int8)sub_5612D0((int)byte_FAE910, 2, "\\Dev\\Src\\Copperhead\\App\\Source\\specialfx.cpp", 3694) )
    sub_561210((int)byte_FAE910, "Entered SpecialFX::Init()", v85);
  v2 = dword_BE1CD8 + 396 * dword_BE1CD4 + 260;
  v3 = &v121[-v2];
  do
  {
    v4 = *(_BYTE *)v2;
    v3[v2] = *(_BYTE *)v2;
    ++v2;
  }
  while ( v4 );
  v5 = (const char *)dword_91CAD8;
  if ( !dword_91CAD8 )
    v5 = WindowName;
  v6 = *(const char **)dword_91CA70;
  if ( !*(_DWORD *)dword_91CA70 )
    v6 = WindowName;
  sprintf(Buffer, "%s%sspecialfx.tec", v6, v5);
  sub_617BD0(181, this + 33);
  v7 = sub_614460(Buffer, 1);
  v8 = v92;
  if ( v7 )
  {
    LODWORD(v84) = 512;
    v83 = COERCE_FLOAT(Str);
    v89 = 0;
    this[2] = 0.0;
    v87 = 0;
    if ( sub_613DE0((char *)LODWORD(v83), SLODWORD(v84)) )
    {
      v88 = &v125;
      do
      {
        if ( !sub_612EB0(v102) )
        {
          if ( strstr(Str, "[TRACKVARS]") && sub_613DE0(Str, 512) )
          {
            do
            {
              v9 = sub_612EB0(v102);
              if ( v9 == 1 || v9 == 4 )
                break;
              if ( !v9 )
              {
                v10 = strchr(Str, 61);
                if ( v10 )
                {
                  if ( (unsigned int)(&Str[strlen(Str) + 1] - &Str[1]) < 0x20 )
                  {
                    *v10 = v11;
                    v12 = v10 + 1;
                    v13 = (char *)operator new(0x28u);
                    if ( v13 )
                    {
                      *((_DWORD *)v13 + 8) = -1082130432;
                      *((_DWORD *)v13 + 9) = 0;
                      v14 = v13;
                    }
                    else
                    {
                      v14 = 0;
                    }
                    strcpy(v14, Str);
                    *((float *)v14 + 8) = atof(v12);
                    v84 = 0.0;
                    v83 = *(float *)&v14;
                    v82 = 32;
                    v81 = String;
                    *((_DWORD *)v14 + 9) = v89;
                    v89 = v14;
                    if ( !sub_53A2B0((int)v81, v82, (char *)LODWORD(v83), (char *)LODWORD(v84)) )
                      *((float *)v14 + 8) = atof(String);
                  }
                }
              }
            }
            while ( sub_613DE0(Str, 512) );
          }
          if ( strstr(Str, "[FEEDBACK]") )
          {
            v15 = 1;
            v16 = 0;
            if ( sub_613DE0(Str, 512) )
            {
              do
              {
                v17 = sub_612EB0(v102);
                if ( v17 == 1 || v17 == 4 )
                  break;
                if ( !v17 )
                {
                  v84 = 0.0;
                  v83 = COERCE_FLOAT(v112);
                  *(float *)&v82 = COERCE_FLOAT("INCLUDETRACKS");
                  if ( sub_6137E0(v102) && !sub_616480(&Str[500], v120) )
                    v15 = 0;
                  v81 = 0;
                  Block = &Str[500];
                  v79 = (int)"EXCLUDETRACKS";
                  if ( sub_6137E0(v101) && sub_616480(&Str[488], v119) )
                    v15 = 0;
                  v78 = 0;
                  *(float *)&v77 = COERCE_FLOAT(&Str[488]);
                  v76 = "REACTION";
                  if ( sub_6137E0(v100) )
                    ++v16;
                }
              }
              while ( sub_613DE0(v105, 512) );
            }
            v18 = v82;
            *(_BYTE *)v82 = v15;
            v82 = v18 + 1;
            if ( v15 )
            {
              v19 = (int)&v81[v16];
              ++*((_DWORD *)this + 2);
              v81 = (char *)v19;
            }
          }
          else if ( strstr(Str, "[LOOSE]") )
          {
            if ( sub_613DE0(Str, 512) )
            {
              v20 = v87;
              do
              {
                v21 = sub_612EB0(v102);
                if ( v21 == 1 || v21 == 4 )
                  break;
                if ( !v21 )
                {
                  v84 = 0.0;
                  v83 = COERCE_FLOAT(v112);
                  *(float *)&v82 = COERCE_FLOAT("REACTION");
                  if ( sub_6137E0(v102) )
                    ++v20;
                }
              }
              while ( sub_613DE0(v108, 512) );
              v86 = v20;
            }
          }
          else if ( strstr(Str, "[LENSFLARE]") && sub_613DE0(Str, 512) )
          {
            do
            {
              v26 = sub_612EB0(v102);
              if ( v26 == 1 || v26 == 4 )
                break;
              if ( !v26 )
              {
                v84 = COERCE_FLOAT(v102);
                sub_46EA60();
              }
            }
            while ( sub_613DE0(v110, 512) );
          }
        }
      }
      while ( sub_613DE0(v105, 512) );
    }
    v22 = *((_DWORD *)this + 2);
    v23 = (char *)operator new(104 * v22 + 4);
    v83 = *(float *)&v23;
    v127 = 1;
    if ( v23 )
    {
      v75 = (int)sub_498720;
      v74 = (char *)sub_5428D0;
      v24 = v23 + 4;
      *(_DWORD *)v23 = v22;
      sub_630A11(v23 + 4, 104, v22, v74, v75);
      v25 = v24;
    }
    else
    {
      v25 = 0;
    }
    v27 = (int)v81;
    v75 = 116 * (_DWORD)v81 + 4;
    v127 = 0;
    *((_DWORD *)this + 3) = v25;
    v28 = (char *)operator new(v75);
    v83 = *(float *)&v28;
    v127 = 2;
    if ( v28 )
    {
      v75 = (int)sub_543690;
      v74 = (char *)sub_542470;
      v29 = v28 + 4;
      *(_DWORD *)v28 = v27;
      sub_630A11(v28 + 4, 116, v27, v74, v75);
    }
    else
    {
      v29 = 0;
    }
    *((_DWORD *)this + 5) = v29;
    this[4] = 0.0;
    v127 = 0;
    v30 = (const char *)dword_91CAE8;
    if ( !dword_91CAE8 )
      v30 = WindowName;
    v31 = *(const char **)dword_91CA70;
    if ( !*(_DWORD *)dword_91CA70 )
      v31 = WindowName;
    sprintf(v117, "%s%s", v31, v30);
    sprintf(v123, "STEX.GTR");
    sub_613F20(v91);
    if ( sub_613DE0(v105, 512) )
    {
      v81 = 0;
      v83 = COERCE_FLOAT(v124);
      do
      {
        if ( !sub_612EB0(v99) )
        {
          if ( strstr(v105, "[FEEDBACK]") )
          {
            v32 = *(_BYTE *)LODWORD(v83);
            v75 = 512;
            ++LODWORD(v83);
            v74 = v105;
            if ( v32 )
            {
              if ( sub_613DE0(v74, v75) )
              {
                do
                {
                  v33 = sub_612EB0(v99);
                  if ( v33 == 1 || v33 == 4 )
                    break;
                  if ( !v33 )
                  {
                    v75 = 0;
                    v74 = &Str[476];
                    if ( sub_6137E0(v99) )
                    {
                      sub_547270((int)v98);
                      v34 = *((_DWORD *)this + 4);
                      v35 = 0;
                      if ( v34 > 0 )
                      {
                        v36 = *((_DWORD *)this + 5);
                        v78 = v36 + 116 * v34;
                        do
                        {
                          if ( sub_5436B0(v36, v78) )
                            break;
                          ++v35;
                          v36 += 116;
                        }
                        while ( v35 < *((_DWORD *)this + 4) );
                      }
                      if ( v35 == v34 )
                        *((_DWORD *)this + 4) = v34 + 1;
                      v37 = *((_DWORD *)this + 3);
                      v27 = *((_DWORD *)this + 5);
                      v38 = *(_DWORD *)((char *)v77 + v37 + 56);
                      v39 = (char *)v77 + v37;
                      *(_DWORD *)&v39[4 * v38 + 60] = v27 + 116 * v35;
                      ++*((_DWORD *)v39 + 14);
                    }
                    sub_5454B0((int)v77 + *((_DWORD *)this + 3), v27, (int)v97, (int)Block);
                  }
                }
                while ( sub_613DE0(v104, 512) );
              }
              v77 = (char *)v77 + 104;
            }
            else if ( sub_613DE0(v74, v75) )
            {
              while ( sub_612EB0(v99) != 1 && sub_613DE0(v105, 512) )
                ;
            }
          }
          else if ( strstr(v105, "[LOOSE]") && sub_613DE0(v105, 512) )
          {
            do
            {
              v40 = sub_612EB0(v99);
              if ( v40 == 1 || v40 == 4 )
                break;
              if ( !v40 )
              {
                v75 = 0;
                v74 = &Str[476];
                if ( sub_6137E0(v99) )
                {
                  sub_547270((int)v98);
                  v41 = *((_DWORD *)this + 4);
                  v42 = 0;
                  if ( v41 > 0 )
                  {
                    v27 = *((_DWORD *)this + 5);
                    v78 = v27 + 116 * v41;
                    do
                    {
                      if ( sub_5436B0(v27, v78) )
                        break;
                      ++v42;
                      v27 += 116;
                    }
                    while ( v42 < *((_DWORD *)this + 4) );
                  }
                  if ( v42 == v41 )
                    *((_DWORD *)this + 4) = v41 + 1;
                }
                sub_6137E0(v97);
                sub_6137E0(String);
              }
            }
            while ( sub_613DE0(v103, 512) );
          }
        }
      }
      while ( sub_613DE0(v104, 512) );
    }
    sub_613C30(v90);
    if ( Block )
    {
      v43 = (_DWORD *)*((_DWORD *)Block + 9);
      if ( v43 )
        sub_542430(v43, 1);
      j__free(Block);
    }
    v44 = 0;
    if ( *((int *)this + 4) > 0 )
    {
      v45 = 0;
      do
      {
        *(_DWORD *)(v45 + *((_DWORD *)this + 5)) = v44++;
        v45 += 116;
      }
      while ( v44 < *((_DWORD *)this + 4) );
    }
    *(float *)&v77 = sub_5529A0(&unk_FADD40);
    if ( byte_FADD28 )
      *(float *)&v77 = sub_54B400(&unk_BE27B0);
    if ( *(float *)&v77 != -1.0 )
    {
      sub_53A560(*(float *)&v77, v95, 64);
      sprintf(ArgList, "STEX");
      v46 = strlen(v95) + 1;
      v47 = &v113;
      while ( *++v47 )
        ;
      qmemcpy(v47, v95, v46);
      v49 = &v113;
      while ( *++v49 )
        ;
      strcpy(v49, ".GTR");
      sub_5EE940((int)&Block, (char)ArgList, 0);
    }
    sub_5D9420(dword_FB1CE0, v116, 0, 0);
    sub_5EE940((int)&v79, (char)&v122, 0);
    for ( i = 0; i < 3; ++i )
    {
      v52 = 0;
      if ( *((int *)this + 4) > 0 )
      {
        v53 = 0;
LABEL_128:
        v54 = v53 + *((_DWORD *)this + 5);
        switch ( *(_DWORD *)(v54 + 4) )
        {
          case 4:
          case 0xD:
          case 0xE:
          case 0xF:
            v55 = i == 1;
            goto LABEL_136;
          case 7:
          case 8:
          case 9:
            v55 = i == 0;
            goto LABEL_136;
          case 0xA:
          case 0xB:
          case 0x10:
            if ( !i )
              sub_547DC0((char *)v54, 0, 0);
            goto LABEL_138;
          case 0xC:
            if ( !i )
              sub_547DC0((char *)v54, 0, 1);
            goto LABEL_138;
          default:
            v55 = i == 2;
LABEL_136:
            if ( v55 )
              sub_547DC0((char *)v54, 1, 0);
LABEL_138:
            ++v52;
            v53 += 116;
            if ( v52 >= *((_DWORD *)this + 4) )
              continue;
            goto LABEL_128;
        }
      }
    }
    sub_5D9900(dword_FB1CE0, v115, 0);
    sub_5EEA30(dword_FB1D04, v77, 0);
    sub_5494A0();
    v56 = *((_DWORD *)this + 4);
    v57 = 0;
    this[6] = 0.0;
    this[7] = 0.0;
    this[8] = 0.0;
    this[9] = 0.0;
    this[10] = 0.0;
    this[11] = 0.0;
    this[12] = 0.0;
    this[13] = 0.0;
    this[14] = 0.0;
    this[15] = 0.0;
    if ( v56 > 0 )
    {
      v58 = *((_DWORD *)this + 5);
      do
      {
        v59 = *(_DWORD *)(v58 + 4);
        switch ( v59 )
        {
          case 14:
            *((_DWORD *)this + 6) = v58;
            break;
          case 15:
            *((_DWORD *)this + 7) = v58;
            break;
          case 1:
            *((_DWORD *)this + 8) = v58;
            break;
          case 3:
            *((_DWORD *)this + 9) = v58;
            break;
          case 4:
            *((_DWORD *)this + 10) = v58;
            break;
          case 5:
            *((_DWORD *)this + 11) = v58;
            break;
          case 16:
            *((_DWORD *)this + 12) = v58;
            break;
          case 17:
            *((_DWORD *)this + 13) = v58;
            break;
          case 18:
            *((_DWORD *)this + 14) = v58;
            break;
          case 19:
            *((_DWORD *)this + 15) = v58;
            break;
        }
        ++v57;
        v58 += 116;
      }
      while ( v57 < *((_DWORD *)this + 4) );
    }
    sub_45D8F0();
    sub_403D10((int)&flt_91BCA0, v52, (int)this);
    sub_4035C0();
    v93[0] = *(float *)&v82;
    v93[1] = v83;
    v94 = 0;
    v93[2] = v84;
    v93[3] = 10.0;
    v93[4] = 9.999999933815813e36;
    v60 = sub_45D190(dbl_B68610, (int)v93);
    if ( v60 )
    {
      v61 = *(_DWORD *)(v60 + 84);
      *((_DWORD *)this + 26) = v61;
      this[27] = *(float *)(v61 + 8) - *(float *)(v61 + 12) * 0.0;
      this[28] = *(float *)(v61 + 8) - *(float *)(v61 + 12);
    }
    this[29] = 1.0;
    this[30] = 1.0;
    this[31] = 1.0;
    this[32] = 1.0;
    if ( !sub_53A2B0((int)&v74, 32, "AIDryGrip", 0) )
      this[27] = atof((const char *)&v74);
    if ( !sub_53A2B0((int)&v74, 32, "AIWetGrip", 0) )
      this[28] = atof((const char *)&v74);
    if ( !sub_53A2B0((int)&v74, 32, "AITireWear", 0) )
      this[29] = atof((const char *)&v74);
    if ( !sub_53A2B0((int)&v74, 32, "AIFuelMult", 0) )
      this[30] = atof((const char *)&v74);
    if ( !sub_53A2B0((int)&v74, 32, "PlayerTireWear", 0) )
      this[31] = atof((const char *)&v74);
    if ( !sub_53A2B0((int)&v74, 32, "PlayerFuelMult", 0) )
      this[32] = atof((const char *)&v74);
    *this = 0.0;
    v62 = sub_5DAB20(dword_FB1D04);
    v63 = 0;
    for ( j = v62; v63 < v62; ++v63 )
    {
      v64 = sub_5DAB30(v63);
      if ( (*(_DWORD *)v64 & 0x10) != 0 && !strncmp((const char *)(v64 + 468), "LPTREE", 6u) )
        ++*(_DWORD *)this;
    }
    v65 = *(_DWORD *)this;
    v66 = operator new(60 * *(_DWORD *)this + 4);
    LOBYTE(v126) = 3;
    if ( v66 )
    {
      v67 = v66 + 1;
      *v66 = v65;
      sub_630A11(v66 + 1, 60, v65, sub_546D20, sub_546D70);
    }
    else
    {
      v67 = 0;
    }
    *((_DWORD *)this + 1) = v67;
    v68 = 0;
    LOBYTE(v126) = 0;
    if ( v62 > 0 )
    {
      v69 = 0;
      do
      {
        v70 = sub_5DAB30(v68);
        if ( (*(_DWORD *)v70 & 0x10) != 0 && !strncmp((const char *)(v70 + 468), "LPTREE", 6u) )
        {
          sub_546DC0((float *)(v69 + *((_DWORD *)this + 1)), v70);
          v69 += 60;
        }
        ++v68;
      }
      while ( v68 < j );
    }
    *((_DWORD *)this + 16) = sub_5E9690("MARBLES", 0, 0);
    *((_DWORD *)this + 17) = sub_5DA9A0("MARBLES00", 0);
    *((_DWORD *)this + 18) = sub_5DA9A0("MARBLES01", 0);
    *((_DWORD *)this + 19) = sub_5DA9A0("MARBLES02", 0);
    *((_DWORD *)this + 20) = sub_5DA9A0("MARBLES03", 0);
    *((_DWORD *)this + 21) = sub_5DA9A0("MARBLES04", 0);
    *((_DWORD *)this + 22) = sub_5DA9A0("MARBLES05", 0);
    *((_DWORD *)this + 23) = sub_5DA9A0("MARBLES06", 0);
    *((_DWORD *)this + 24) = sub_5DA9A0("MARBLES07", 0);
    *((_DWORD *)this + 25) = sub_5DA9A0("MARBLES08", 0);
    if ( v73 )
      sub_5EEA30(dword_FB1D04, v73, 0);
    v8 = &v85;
  }
  v126 = -1;
  return sub_614140(v8);
}
