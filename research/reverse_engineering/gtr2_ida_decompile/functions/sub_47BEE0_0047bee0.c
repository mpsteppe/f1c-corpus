char __userpurge sub_47BEE0@<al>(
        int a1@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        const char *a4,
        int *a5,
        int a6,
        int *a7,
        int a8,
        int *a9,
        int a10,
        __int128 a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int Buffer,
        char String2)
{
  int v28; // ecx
  const char *v29; // edi
  unsigned int v30; // esi
  unsigned int v31; // eax
  int v32; // ebx
  int v33; // esi
  _DWORD *v34; // eax
  _DWORD *v35; // esi
  char *v36; // esi
  int v37; // esi
  int k; // ecx
  int v39; // eax
  char *v40; // esi
  int m; // ecx
  int v42; // eax
  int *v43; // esi
  char *v44; // esi
  const char *v45; // esi
  int i; // ecx
  int v47; // eax
  int v48; // ecx
  int v49; // edi
  float v50; // eax
  int v51; // eax
  int v52; // eax
  char v53; // cl
  int v54; // eax
  char v55; // cl
  unsigned int v56; // eax
  unsigned int *v57; // edi
  char v58; // cl
  FILE *v59; // eax
  const char *v60; // eax
  int v61; // edx
  char v62; // cl
  int j; // ecx
  int v64; // eax
  int v65; // edx
  int v66; // edi
  float v67; // eax
  int v68; // eax
  int v69; // eax
  char v70; // cl
  int v71; // eax
  char v72; // cl
  unsigned int v73; // eax
  unsigned int *v74; // edi
  char v75; // cl
  FILE *v76; // eax
  const char *v77; // eax
  int v78; // edx
  char v79; // cl
  char v80; // bl
  _UNKNOWN **v81; // eax
  _DWORD *v82; // eax
  _DWORD *v83; // ecx
  char *v84; // esi
  int v85; // esi
  char *v86; // ebx
  int v87; // ecx
  int v88; // eax
  _DWORD *v89; // edx
  int v90; // ecx
  int v91; // edx
  _DWORD *v92; // ecx
  int v93; // eax
  _DWORD *v94; // eax
  _DWORD *v95; // ecx
  _DWORD *v96; // eax
  _DWORD *v97; // ecx
  char *v98; // esi
  char *v99; // eax
  char *v100; // edx
  char v101; // cl
  const char *v102; // edi
  int v103; // esi
  _DWORD *v104; // eax
  _DWORD *v105; // esi
  const char *v106; // ebx
  char *v107; // eax
  char *v108; // eax
  char *v109; // esi
  int v110; // eax
  const char *v111; // ecx
  int v112; // esi
  const CHAR *v113; // esi
  unsigned int v114; // esi
  char v115; // al
  const char *v116; // eax
  int v117; // edx
  char v118; // cl
  char *v119; // edi
  char *v121; // edi
  const char *v123; // ecx
  bool v124; // zf
  const char *v125; // eax
  const char **v126; // esi
  const char *v127; // eax
  const char *v128; // eax
  const char *v129; // edi
  const CHAR *v130; // eax
  bool v131; // cc
  int v132; // eax
  const char *v133; // ecx
  char *v134; // edi
  const char *v136; // ecx
  const char *v137; // eax
  int *v138; // esi
  int v139; // eax
  const char *v140; // esi
  char *v141; // eax
  _DWORD *v142; // eax
  _DWORD *v143; // esi
  int v144; // kr18_4
  int v145; // esi
  int *v146; // eax
  int v147; // esi
  int v148; // edx
  unsigned int v149; // ecx
  _DWORD *v150; // eax
  char *v151; // eax
  int v152; // eax
  int *v153; // esi
  double v154; // st7
  double v155; // st7
  double v156; // st7
  bool v157; // cf
  int v158; // esi
  char *v159; // esi
  unsigned int v161; // kr00_4
  int v162; // eax
  float v163; // [esp+3C4Ch] [ebp-3Ch]
  float v164; // [esp+3C60h] [ebp-28h]
  char v165; // [esp+3C60h] [ebp-28h]
  float v166; // [esp+3C60h] [ebp-28h]
  float v167; // [esp+3C60h] [ebp-28h]
  float v168; // [esp+3C64h] [ebp-24h]
  float v169; // [esp+3C64h] [ebp-24h]
  float v170; // [esp+3C64h] [ebp-24h]
  float v171; // [esp+3C64h] [ebp-24h]
  float v172; // [esp+3C64h] [ebp-24h]
  float v173; // [esp+3C64h] [ebp-24h]
  char *v174; // [esp+3C68h] [ebp-20h]
  float v175; // [esp+3C68h] [ebp-20h]
  int v176; // [esp+3C68h] [ebp-20h]
  int v177; // [esp+3C6Ch] [ebp-1Ch]
  int v178; // [esp+3C70h] [ebp-18h]
  char v179; // [esp+3C76h] [ebp-12h]
  char v180; // [esp+3C76h] [ebp-12h]
  unsigned int v181; // [esp+3C78h] [ebp-10h] BYREF
  const char *v182; // [esp+3C7Ch] [ebp-Ch]
  int v183; // [esp+3C80h] [ebp-8h]
  float v184; // [esp+3C84h] [ebp-4h] BYREF
  const CHAR *vars0; // [esp+3C88h] [ebp+0h]
  float retaddr; // [esp+3C8Ch] [ebp+4h] BYREF

  v181 = a1;
  sub_631BD0();
  v178 = a3;
  v177 = a2;
  v29 = a4;
  v30 = *(_DWORD *)a4;
  v31 = (*(_DWORD *)a4 >> 29) - 1;
  v32 = v28;
  HIBYTE(v181) = 1;
  if ( !v31 )
  {
    if ( ((v30 >> 18) & 0x3F) != 0 )
    {
      if ( ((v30 >> 18) & 0x3F) == 7 && (unsigned __int8)v30 < 0x69u )
        dword_925CCC[5654 * (unsigned __int8)v30] = *((_DWORD *)a4 + 1);
    }
    else
    {
      if ( (v30 & 0x3FF00) == 0x2800 )
        sub_51C6D0(a4, v177, v178);
      if ( (unsigned __int8)*(_DWORD *)v29 >= 0x69u )
      {
        if ( dword_B640C0 != 5
          && (unsigned __int8)sub_5612D0((int)byte_FAE910, 2, "\\Dev\\Src\\Copperhead\\App\\Source\\netcomm.cpp", 1666) )
        {
          sub_561210((int)byte_FAE910, "received compressed ziploc from unknown or invalid owner", v177);
        }
      }
      else
      {
        v159 = (char *)&unk_9204A0 + 22616 * (unsigned __int8)*(_DWORD *)v29;
        v124 = *((_DWORD *)v159 + 3705) == 2;
        *((_DWORD *)v159 + 5643) = *((_DWORD *)v29 + 1);
        if ( v124 )
        {
          sub_53F0E0(1);
          sub_53F190(v159, 1, v176, v177);
        }
      }
    }
    return off_16C96F8(*(_DWORD *)v29, a4);
  }
  if ( v31 != 3 )
    return off_16C96F8(*(_DWORD *)v29, a4);
  switch ( (v30 >> 18) & 0x3F )
  {
    case 0u:
      sub_4740A0(v28, *((_DWORD *)a4 + 211));
      return HIBYTE(v177);
    case 1u:
      return HIBYTE(v177);
    case 2u:
      if ( *(_DWORD *)(v28 + 113328) == 3 )
      {
        v43 = (int *)(a4 + 8);
        qmemcpy((void *)(v28 + 113348), a4 + 8, 0x1A0u);
        *(_WORD *)(v28 + 113764) = *((_WORD *)v43 + 208);
        sub_476FC0((_DWORD *)v28);
        *(_DWORD *)(v32 + 16) = 1069547520;
        *(_DWORD *)(dword_91E084 + 19428) = 0;
        if ( *(_BYTE *)(v32 + 1179) )
        {
          *(_BYTE *)(v32 + 1179) = 0;
          *(_DWORD *)(v32 + 2124) = 1084227584;
        }
        else
        {
          v44 = sub_41D840(&byte_91CC38, "Next Session");
          if ( (unsigned __int8)sub_4EB900(off_16C9A94, v44) )
            Sleep(0x3E8u);
          else
            sub_4730C0((int **)&dword_B6CB98, v44, 3, (int)&byte_1020304, 1084227584);
          *(_DWORD *)(v32 + 2124) = 1084227584;
        }
      }
      return HIBYTE(v177);
    case 3u:
      v45 = a4;
      v169 = dbl_FB1D18;
      v182 = (const char *)*((_DWORD *)a4 + 211);
      sub_51B2A0(4, 4, 836, 255, LODWORD(v169), 3);
      memset32((void *)(v45 + 12), -1082130432, 0x68u);
      v179 = sub_4733B0();
      if ( !v179 )
      {
        for ( i = 0; i < dword_757C10; ++i )
        {
          v47 = *(&dword_91E088 + i);
          if ( v47 )
            *(_DWORD *)&v45[4 * *(_DWORD *)(v47 + 22468) + 12] = *(_DWORD *)(v47 + 19436);
        }
      }
      v184 = NAN;
      if ( *sub_4796F0((_DWORD *)(v32 + 113304), &a7, &v181) != *(int **)(v32 + 113308) )
        LODWORD(v184) = *((unsigned __int8 *)*sub_4796F0((_DWORD *)(v32 + 113304), &a9, &v181) + 16);
      if ( v184 == NAN )
      {
        v164 = dbl_FB1D18;
        sub_51B2A0(4, 53, 836, 255, LODWORD(v164), 3);
        sub_4745E0();
        return HIBYTE(v177);
      }
      v48 = *(_DWORD *)(528 * LODWORD(v184) + v32 + 2228);
      v182 = (const char *)(v32 + 528 * LODWORD(v184));
      if ( v48 != 3 || v179 )
      {
        *((_DWORD *)v45 + 2) = -1;
        goto LABEL_118;
      }
      if ( !byte_B7360C )
        goto LABEL_62;
      v49 = 0;
      if ( dword_757C10 <= 0 )
        goto LABEL_62;
      v183 = v32 + 528 * LODWORD(v184) + 2292;
      while ( !sub_616480(*(&dword_91E088 + v49) + 22084, v183) )
      {
        if ( ++v49 >= dword_757C10 )
          goto LABEL_62;
      }
      v50 = v184;
      *((_DWORD *)v45 + 2) = -1;
      sub_474860(*(void **)v32, *(_DWORD *)(v32 + 4 * LODWORD(v50) + 112052), 1);
LABEL_62:
      v51 = sub_473390();
      *(_DWORD *)(v32 + 4 * v51 + 1696) = v181;
      *((_DWORD *)v45 + 2) = v51;
      memset(&STACK[0x3EF8], 0, 0x400u);
      GetModuleFileNameA(0, (LPSTR)&STACK[0x3EF8], 0x400u);
      v52 = strlen((const char *)&STACK[0x3EF8]);
      if ( *((_BYTE *)&STACK[0x3EF8] + v52) != 92 )
      {
        do
        {
          if ( v52 <= 0 )
            break;
          *((_BYTE *)&STACK[0x3EF8] + v52) = 0;
          v53 = *((_BYTE *)&STACK[0x3EF7] + v52--);
        }
        while ( v53 != 92 );
      }
      v54 = 0;
      do
      {
        v55 = *((_BYTE *)&STACK[0x3EF8] + v54);
        *((_BYTE *)&STACK[0x4648] + v54++) = v55;
      }
      while ( v55 );
      v56 = strlen(v182 + 2356) + 1;
      v57 = &STACK[0x4647];
      do
      {
        v58 = *((_BYTE *)v57 + 1);
        v57 = (unsigned int *)((char *)v57 + 1);
      }
      while ( v58 );
      qmemcpy(v57, v182 + 2356, v56);
      v59 = fopen((const char *)&STACK[0x4648], "rb");
      if ( v59 )
      {
        fclose(v59);
      }
      else if ( (unsigned __int8)sub_4735E0(&dword_B6CBA8) && dword_B73498 )
      {
        goto LABEL_77;
      }
      if ( !(unsigned __int8)sub_4735E0(&dword_B6CBA8) )
        goto LABEL_116;
      v60 = v182 + 2676;
      v61 = (char *)&STACK[0x3DF8] - (v182 + 2676);
      do
      {
        v62 = *v60;
        v60[v61] = *v60;
        ++v60;
      }
      while ( v62 );
      goto LABEL_111;
    case 4u:
      if ( dword_B640C0 != 5
        && (unsigned __int8)sub_5612D0((int)byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\netcomm.cpp", 2342) )
      {
        sub_561210((int)byte_FAE910, "Received server verify, setting self as ready...", v177);
      }
      v82 = &unk_92A8E4;
      v83 = v29 + 16;
      do
      {
        *(v82 - 5654) = *(v83 - 1);
        *v82 = *v83;
        v82[5654] = v83[1];
        v82[11308] = v83[2];
        v82[16962] = v83[3];
        v82[22616] = v83[4];
        v82[28270] = v83[5];
        v82[33924] = v83[6];
        v82 += 45232;
        v83 += 8;
      }
      while ( (int)v82 < (int)dword_B68CA4 );
      sub_479360((_DWORD *)v32, *((_DWORD *)v29 + 2));
      sub_475FB0();
      return HIBYTE(v177);
    case 5u:
      if ( !*(_BYTE *)(v28 + 24) )
      {
        *(_DWORD *)(v28 + 20) = 1095237632;
        *(_BYTE *)(v28 + 24) = 1;
      }
      v98 = sub_41D840(&byte_91CC38, "Next Track");
      if ( (unsigned __int8)sub_4EB900(&unk_B6F134, v98) )
        goto LABEL_179;
      sub_4730C0((int **)&dword_B6CB98, v98, 3, (int)&byte_1020304, 1084227584);
      return HIBYTE(v177);
    case 6u:
      v33 = (v30 >> 8) & 0x3FF;
      if ( !v33 )
        return HIBYTE(v177);
      a4[v33 + 8] = 0;
      LOBYTE(STACK[0x3DFC]) = 0;
      sub_4733E0(&STACK[0x3EFC]);
      BYTE1(v181) = 0;
      sub_47A1A0();
      if ( *(_DWORD *)(v32 + 113328) == 1 )
      {
        if ( (unsigned __int8)sub_488890(v29 + 8, &STACK[0x3EF8], *((_DWORD *)v29 + 211)) )
          return HIBYTE(v177);
      }
      else
      {
        v181 = strlen((const char *)&STACK[0x3EF8]);
        if ( !v181 )
          sub_41D840(&byte_91CC38, "SERVER");
        sub_472FE0();
        if ( !byte_B6F118 && byte_B7345C )
          sub_4730C0((int **)&dword_B6CB98, (const char *)&STACK[0x3DE0], 0, (int)&byte_1020304, 1084227584);
        v34 = operator new(8u);
        if ( v34 )
        {
          *v34 = 0;
          v34[1] = -1;
          v35 = v34;
        }
        else
        {
          v35 = 0;
        }
        sub_615860(&STACK[0x3DE0]);
        sub_5FDFB0(v35, 0);
        sub_47B4F0();
      }
      return off_16C96F8(*(_DWORD *)v29, a4);
    case 0x1Cu:
      BYTE2(v181) = (unsigned __int8)sub_473CB0() == 0;
      switch ( v29[12] )
      {
        case 1:
          v99 = sub_41D840(&byte_91CC38, "Booted.  Duplicate car");
          break;
        case 2:
          v99 = sub_41D840(&byte_91CC38, "You have been voted off");
          break;
        case 3:
          v99 = sub_41D840(&byte_91CC38, "Server not ready");
          break;
        case 4:
          v99 = sub_41D840(&byte_91CC38, "Car not present on server.");
          break;
        case 5:
          v99 = sub_41D840(&byte_91CC38, "Booted as possible cheat");
          break;
        default:
          v99 = sub_41D840(&byte_91CC38, "You have been booted");
          break;
      }
      v100 = v99;
      LOBYTE(a11) = 0;
      memset((char *)&a11 + 1, 0, 0x3Cu);
      *(_WORD *)((char *)&a23 + 1) = 0;
      HIBYTE(a23) = 0;
      do
      {
        v101 = *v99;
        v99[(char *)&a11 - v100] = *v99;
        ++v99;
      }
      while ( v101 );
      if ( !BYTE2(v181) )
        return HIBYTE(v177);
      v102 = a4;
      v103 = *((_DWORD *)a4 + 2);
      if ( sub_59B580(*(_DWORD *)(**(_DWORD **)v32 + 113316)) == v103 )
      {
        v104 = operator new(8u);
        if ( v104 )
        {
          *v104 = 0;
          v104[1] = -1;
          v105 = v104;
        }
        else
        {
          v105 = 0;
        }
        sub_615860(&a11);
        sub_5FDFB0(v105, 0);
        sub_4730C0((int **)&dword_B6CB98, (const char *)&a11, 3, (int)&byte_1020304, 1084227584);
        sub_59B460(*(_DWORD *)(v32 + 113316), v177, v178);
        if ( (unsigned __int8)sub_4EB900(&unk_B6F134, &a11) )
LABEL_179:
          Sleep(0x3E8u);
      }
      else if ( v102[12] != 3 )
      {
        v106 = (const char *)sub_473FE0();
        if ( strcmp(v106, "?") )
        {
          v107 = sub_41D840(&byte_91CC38, "was removed from the game");
          sprintf((char *const)&Buffer, "%s %s", v106, v107);
          sub_4730C0((int **)&dword_B6CB98, (const char *)&Buffer, 3, (int)&byte_1020304, 1084227584);
          sub_4EA920(&Buffer);
          v108 = sub_41D840(&byte_91CC38, "Reason:");
          sprintf((char *const)&Buffer, "%s %s", v108, (const char *)&a10);
          sub_4730C0((int **)&dword_B6CB98, (const char *)&Buffer, 3, (int)&byte_1020304, 1084227584);
          sub_4EA920(&Buffer);
        }
      }
      return HIBYTE(v177);
    case 0x1Fu:
      *(_BYTE *)(v28 + 302724) = a4[8];
      *(_BYTE *)(v28 + 302725) = v29[9];
      sub_477040(v28, 1);
      return HIBYTE(v177);
    case 0x20u:
      a4 = 0;
      vars0 = 0;
      v182 = 0;
      v109 = (char *)&unk_9204A0 + 22616 * (unsigned __int8)v30;
      sub_5875F0(&STACK[0x4A4C]);
      STACK[0x86D0] = 0;
      if ( v109 )
      {
        v110 = sub_539670(v109 + 22084);
        v183 = v110;
        if ( v110 )
        {
          v111 = *(const char **)(v110 + 8);
          if ( !v111 )
            v111 = WindowName;
          a4 = sub_40D7B0(v111);
          v182 = *(const char **)v183;
          if ( !v182 )
            v182 = WindowName;
        }
        v112 = *((_DWORD *)v109 + 4296);
        if ( v112 )
        {
          v113 = *(const CHAR **)(v112 + 24);
          if ( !v113 )
            v113 = WindowName;
          vars0 = v113;
        }
      }
      if ( (*(_DWORD *)v29 & 0x3FF00u) > 0x1400 )
      {
        v114 = 0;
        if ( a4[28] != 92 )
        {
          do
          {
            if ( v114 >= strlen(a4 + 28) )
              break;
            v115 = a4[v114++ + 29];
          }
          while ( v115 != 92 );
        }
        if ( v114 != strlen(a4 + 28) )
        {
          sub_630FE0(&String2, a4 + 28, v114);
          v116 = &a4[v114 + 29];
          *(&String2 + v114) = 0;
          v117 = (char *)&STACK[0x3DFC] - v116;
          do
          {
            v118 = *v116;
            v116[v117] = *v116;
            ++v116;
          }
          while ( v118 );
        }
        v119 = (char *)&Buffer + 3;
        while ( *++v119 )
          ;
        strcpy(v119, ".hdc");
        v121 = (char *)&STACK[0x3DFB];
        while ( *++v121 )
          ;
        v123 = a4;
        v124 = a4 == 0;
        strcpy(v121, ".car");
        if ( v124 || (v125 = sub_40D7B0(v123), _stricmp(v125, &String2)) )
        {
          v184 = 0.0;
          if ( dword_BE1BD4 > 0 )
          {
            v183 = 0;
            do
            {
              v126 = (const char **)(dword_BE1BD8 + v183);
              v127 = *(const char **)(dword_BE1BD8 + v183 + 8);
              if ( !v127 )
                v127 = WindowName;
              retaddr = COERCE_FLOAT(sub_40D7B0(v127));
              v128 = *v126;
              if ( !*v126 )
                v128 = WindowName;
              v129 = sub_40D7B0(v128);
              if ( !_stricmp(&String2, (const char *)LODWORD(retaddr)) && !_stricmp((const char *)&STACK[0x3DFC], v129) )
              {
                sub_435800(v177, v178);
                v130 = v126[2];
                LOBYTE(STACK[0x86D0]) = 1;
                if ( !v130 )
                  v130 = WindowName;
                sub_5886A0(v130, &STACK[0x681C], 3);
                vars0 = (const CHAR *)STACK[0x4A4C];
                if ( !vars0 )
                  vars0 = WindowName;
                v182 = *v126;
                if ( !v182 )
                  v182 = WindowName;
                a4 = (const char *)LODWORD(retaddr);
                LOBYTE(STACK[0x86D0]) = 0;
                sub_431AF0(&STACK[0x681C]);
              }
              v131 = ++LODWORD(v184) < dword_BE1BD4;
              v183 += 2824;
            }
            while ( v131 );
          }
        }
      }
      if ( !sub_477540((_BYTE *)v32, (int)a4, (int)v182, (int)a4, (int)vars0) )
      {
        v183 = 0;
        BYTE2(v181) = 0;
        v132 = 0;
        do
        {
          if ( BYTE2(v181) )
            break;
          switch ( v132 )
          {
            case 1:
              if ( (byte_B73690 & 2) != 0 )
                BYTE1(v181) = *(_BYTE *)(v32 + 302727);
              else
                BYTE1(v181) = 1;
              strcpy((char *)&a11, sub_41D840(&byte_91CC38, "Track Geometry"));
              goto LABEL_245;
            case 2:
              BYTE1(v181) = *(_BYTE *)(v32 + 302728);
              if ( v182 )
              {
                sub_40D7B0(v182);
                sub_4152E0();
              }
              else
              {
                LOBYTE(a11) = 0;
              }
              goto LABEL_245;
            case 3:
              BYTE1(v181) = *(_BYTE *)(v32 + 302729);
              strcpy((char *)&a11, "specialfx.tec");
              goto LABEL_245;
            case 4:
              v133 = dword_B6F68C;
              BYTE1(v181) = *(_BYTE *)(v32 + 302730);
              if ( !dword_B6F68C )
                v133 = WindowName;
              sub_40D7B0(v133);
              sub_4152E0();
              sub_40D7E0((const char *)&a10);
              v134 = (char *)&a9 + 3;
              while ( *++v134 )
                ;
              strcpy(v134, ".gdb");
              goto LABEL_245;
            case 5:
              v136 = dword_B7235C;
              BYTE1(v181) = *(_BYTE *)(v32 + 302731);
              if ( !dword_B7235C )
                v136 = WindowName;
              v137 = *(const char **)dword_91CA70;
              if ( !*(_DWORD *)dword_91CA70 )
                v137 = WindowName;
              sub_632041(&a11, 80, "%s%s", v137, v136);
              HIBYTE(Buffer) = 0;
LABEL_245:
              if ( !BYTE1(v181) )
              {
                v161 = __readeflags();
                v162 = *(_DWORD *)__ROR4__(off_16C6D60, dword_1262580);
                __writeeflags(v161);
                if ( v162 == 2 )
                {
                  v138 = *(int **)(v32 + 113308);
                  v184 = *((float *)a4 + 211);
                  if ( *sub_4796F0((_DWORD *)(v32 + 113304), &a7, &v184) != v138 )
                  {
                    v139 = *((unsigned __int8 *)*sub_4796F0((_DWORD *)(v32 + 113304), &a9, &v184) + 16);
                    sub_474860(*(void **)v32, *(_DWORD *)(v32 + 4 * v139 + 112052), 5);
                    BYTE2(v181) = 1;
                  }
                }
                else if ( v162 == 1 )
                {
                  v140 = (const char *)sub_473FE0();
                  v141 = sub_41D840(&byte_91CC38, "mismatch");
                  sprintf((char *const)&Buffer, "%s %s", v140, v141);
                  v142 = operator new(8u);
                  if ( v142 )
                  {
                    *v142 = 0;
                    v142[1] = -1;
                    v143 = v142;
                  }
                  else
                  {
                    v143 = 0;
                  }
                  sub_615860(&Buffer);
                  sub_5FDFB0(v143, 0);
                  sub_4730C0((int **)&dword_B6CB98, (const char *)&Buffer, 3, (int)&byte_1020304, 1084227584);
                  v144 = strlen((const char *)&Buffer);
                  v145 = v144;
                  if ( v144 >= 0 )
                  {
                    if ( v144 > 159 )
                      v145 = 159;
                  }
                  else
                  {
                    v145 = 0;
                  }
                  v167 = dbl_FB1D18;
                  sub_51B2A0(4, 6, v145, 255, LODWORD(v167), 3);
                  sub_4152E0();
                  sub_4745E0();
                }
              }
              break;
            default:
              break;
          }
          v132 = ++v183;
        }
        while ( v183 < 6 );
      }
      sub_43A460((void **)&STACK[0x4A4C]);
      return HIBYTE(v177);
    case 0x2Cu:
      a4[((v30 >> 8) & 0x3FF) + 8] = 0;
      *((_DWORD *)v29 + 34) = *((_DWORD *)v29 + 211);
      if ( !byte_B7360C )
        goto LABEL_278;
      v146 = *(int **)(v28 + 113332);
      *(_DWORD *)(v28 + 113340) = v146;
      if ( !v146 )
        goto LABEL_278;
      v147 = *v146;
      if ( !*v146 )
        goto LABEL_278;
      while ( _stricmp((const char *)v147, v29 + 8) )
      {
        v147 = sub_473B70();
        if ( !v147 )
          goto LABEL_278;
      }
      v148 = *(_DWORD *)(v147 + 128);
      v149 = 0;
      v150 = (_DWORD *)(v32 + 112056);
      while ( *(v150 - 1) != v148 )
      {
        if ( *v150 == v148 )
        {
          ++v149;
          break;
        }
        if ( v150[1] == v148 )
        {
          v149 += 2;
          break;
        }
        if ( v150[2] == v148 )
        {
          v149 += 3;
          break;
        }
        v149 += 4;
        v150 += 4;
        if ( v149 >= 0x68 )
          break;
      }
      if ( v149 == 104 )
      {
        sub_524660(v32 + 113332, v147, 1);
LABEL_278:
        v151 = (char *)operator new(0x84u);
        qmemcpy(v151, a4 + 8, 0x84u);
        sub_5FDFB0(v151, 1);
        v172 = dbl_FB1D18;
        sub_51B2A0(4, 45, 0, 255, LODWORD(v172), 3);
        goto LABEL_151;
      }
      v173 = dbl_FB1D18;
      sub_51B2A0(4, 46, 0, 255, LODWORD(v173), 3);
LABEL_151:
      sub_4745E0();
      return HIBYTE(v177);
    case 0x2Du:
      *(_DWORD *)(v28 + 2116) = 2;
      return HIBYTE(v177);
    case 0x2Eu:
      *(_DWORD *)(v28 + 2116) = 3;
      return HIBYTE(v177);
    case 0x2Fu:
      v152 = *(_DWORD *)(v28 + 112884);
      a4 = 0;
      if ( v152 )
      {
        v153 = (int *)(v28 + 112052);
        v183 = v28 + 2752;
        do
        {
          if ( (*(_BYTE *)v183 & 1) != 0 && sub_47AC90((float *)(v32 + 292692), *v153, (int)&v184, 1) )
          {
            v154 = (double)*((__int16 *)v29 + 4) * 0.00025000001;
            if ( fabs(v154 - v184) > *(float *)(v32 + 2140) || v154 < 0.0 || v184 < 0.0 )
            {
              v156 = *(float *)(v32 + 2140);
              *(_DWORD *)(v32 + 16) = 1065353216;
              *(float *)(v32 + 2140) = v156 + 0.025;
            }
            else
            {
              retaddr = *(float *)(v32 + 2140) * 0.050000001;
              sub_401760(&retaddr, 0.00050000002, 0.0099999998);
              v155 = *(float *)(v32 + 2140) - retaddr;
              *(float *)(v32 + 2140) = v155;
              if ( v155 < 0.0099999998 )
                *(_DWORD *)(v32 + 2140) = 1008981770;
            }
          }
          ++v153;
          v157 = (unsigned int)++a4 < *(_DWORD *)(v32 + 112884);
          v183 += 528;
        }
        while ( v157 );
      }
      return HIBYTE(v177);
    case 0x31u:
      if ( (unsigned __int8)sub_473CB0() )
      {
        v158 = *((__int16 *)v29 + 5);
        if ( v158 != sub_473690() )
        {
          *(_DWORD *)(v32 + 4 * (unsigned __int8)*(_DWORD *)v29 + 1696) = *(_DWORD *)(v32 + 4 * v158 + 112052);
          return off_16C96F8(*(_DWORD *)v29, a4);
        }
      }
      if ( *((__int16 *)v29 + 5) == sub_473690() )
      {
        sub_4733E0(&STACK[0x42FC]);
        sub_473720(*(void **)v32, (int)&STACK[0x42FC]);
        STACK[0x42FC] = 1;
        sub_4736F0();
      }
      return HIBYTE(v177);
    case 0x32u:
      if ( dword_B640C0 != 5
        && (unsigned __int8)sub_5612D0((int)byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\netcomm.cpp", 2364) )
      {
        sub_561210((int)byte_FAE910, "Received server penalty sync...maximium slot:%d", v29[8]);
      }
      v84 = (char *)&unk_9204B0;
      do
      {
        sub_573880(0.0);
        v84 += 22616;
      }
      while ( (int)v84 < (int)byte_B5E870 );
      v85 = 0;
      if ( v29[8] >= 0 )
      {
        v86 = (char *)&unk_9204B0;
        do
        {
          LODWORD(v184) = v29[v85 + 9];
          v175 = (float)SLODWORD(v184);
          sub_573880(v175);
          ++v85;
          v86 += 22616;
        }
        while ( v85 <= v29[8] );
      }
      return HIBYTE(v177);
    case 0x33u:
      v171 = dbl_FB1D18;
      v184 = *((float *)a4 + 211);
      sub_51B2A0(4, 52, 836, 255, LODWORD(v171), 3);
      v87 = dword_757C10;
      v88 = 0;
      if ( dword_757C10 > 0 )
      {
        v89 = v29 + 12;
        do
        {
          v90 = *(&dword_91E088 + v88);
          if ( v90 )
            *(_DWORD *)&v29[4 * *(_DWORD *)(v90 + 22468) + 12] = *(_DWORD *)(v90 + 19436);
          else
            *v89 = -1082130432;
          v87 = dword_757C10;
          ++v88;
          ++v89;
        }
        while ( v88 < dword_757C10 );
      }
      v91 = 0;
      if ( v87 > 0 )
      {
        v92 = v29 + 428;
        do
        {
          v93 = *(&dword_91E088 + v91);
          if ( v93 )
            *(_DWORD *)&v29[4 * *(_DWORD *)(v93 + 22468) + 428] = *(_DWORD *)(v93 + 19448);
          else
            *v92 = -1082130432;
          ++v91;
          ++v92;
        }
        while ( v91 < dword_757C10 );
      }
      goto LABEL_151;
    case 0x34u:
      if ( dword_B640C0 != 5
        && (unsigned __int8)sub_5612D0((int)byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\netcomm.cpp", 2437) )
      {
        sub_561210((int)byte_FAE910, "Received Best Times...", v177);
      }
      v94 = &unk_92A8E4;
      v95 = v29 + 16;
      do
      {
        *(v94 - 5654) = *(v95 - 1);
        *v94 = *v95;
        v94[5654] = v95[1];
        v94[11308] = v95[2];
        v94[16962] = v95[3];
        v94[22616] = v95[4];
        v94[28270] = v95[5];
        v94[33924] = v95[6];
        v94 += 45232;
        v95 += 8;
      }
      while ( (int)v94 < (int)dword_B68CA4 );
      v96 = &unk_92A8F0;
      v97 = v29 + 432;
      do
      {
        *(v96 - 5654) = *(v97 - 1);
        *v96 = *v97;
        v96[5654] = v97[1];
        v96[11308] = v97[2];
        v96[16962] = v97[3];
        v96[22616] = v97[4];
        v96[28270] = v97[5];
        v96[33924] = v97[6];
        v96 += 45232;
        v97 += 8;
      }
      while ( (int)v96 < (int)dword_B68CB0 );
      return HIBYTE(v177);
    case 0x35u:
      v174 = sub_41D840(&byte_91CC38, "Waiting for server...");
      sub_4EB900(off_16C9B14, v174);
      Sleep(0x7D0u);
      v166 = dbl_FB1D18;
      sub_51B2A0(4, 54, 0, 0, LODWORD(v166), 3);
      v80 = sub_4745E0();
      if ( dword_B640C0 != 5
        && (unsigned __int8)sub_5612D0((int)byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\netcomm.cpp", 2325) )
      {
        v81 = (_UNKNOWN **)&unk_6F6718;
        if ( !v80 )
          v81 = &off_6F6714;
        sub_561210((int)byte_FAE910, "Resending server OK request (ret=%s)", (char)v81);
      }
      return HIBYTE(v177);
    case 0x36u:
      v45 = a4;
      v170 = dbl_FB1D18;
      v182 = (const char *)*((_DWORD *)a4 + 211);
      sub_51B2A0(4, 4, 836, 255, LODWORD(v170), 3);
      memset32((void *)(v45 + 12), -1082130432, 0x68u);
      v180 = sub_4733B0();
      if ( !v180 )
      {
        for ( j = 0; j < dword_757C10; ++j )
        {
          v64 = *(&dword_91E088 + j);
          if ( v64 )
            *(_DWORD *)&v45[4 * *(_DWORD *)(v64 + 22468) + 12] = *(_DWORD *)(v64 + 19436);
        }
      }
      v184 = NAN;
      if ( *sub_4796F0((_DWORD *)(v32 + 113304), (int **)&a4, &v181) != *(int **)(v32 + 113308) )
        LODWORD(v184) = *((unsigned __int8 *)*sub_4796F0((_DWORD *)(v32 + 113304), &a5, &v181) + 16);
      if ( v184 == NAN )
      {
        sub_474860(*(void **)v32, v181, 3);
        return HIBYTE(v177);
      }
      v65 = *(_DWORD *)(528 * LODWORD(v184) + v32 + 2228);
      v182 = (const char *)(v32 + 528 * LODWORD(v184));
      if ( v65 != 3 || v180 )
      {
        *((_DWORD *)v45 + 2) = -1;
        goto LABEL_118;
      }
      if ( !byte_B7360C )
        goto LABEL_97;
      v66 = 0;
      if ( dword_757C10 <= 0 )
        goto LABEL_97;
      v183 = v32 + 528 * LODWORD(v184) + 2292;
      break;
    case 0x37u:
      if ( !(unsigned __int8)sub_473CB0() )
        return HIBYTE(v177);
      v36 = (char *)&unk_9204A0 + 22616 * (unsigned __int8)v30;
      if ( v36 )
        v36[22588] = 1;
      v37 = 0;
      for ( k = 0; k < dword_757C10; ++k )
      {
        v39 = *(&dword_91E088 + k);
        if ( v39 && *(_BYTE *)(v39 + 22588) )
          ++v37;
      }
      dword_FADE38 = v37;
      goto LABEL_35;
    case 0x38u:
      if ( !(unsigned __int8)sub_473CB0() )
        return HIBYTE(v177);
      v40 = (char *)&unk_9204A0 + 22616 * (unsigned __int8)v30;
      if ( v40 )
        v40[22588] = 0;
      v37 = 0;
      for ( m = 0; m < dword_757C10; ++m )
      {
        v42 = *(&dword_91E088 + m);
        if ( v42 && *(_BYTE *)(v42 + 22588) )
          ++v37;
      }
LABEL_35:
      v168 = dbl_FB1D18;
      sub_51B2A0(4, 57, 4, 255, LODWORD(v168), 3);
      *((_DWORD *)v29 + 2) = v37;
      sub_4745E0();
      return HIBYTE(v177);
    case 0x39u:
      dword_FADE38 = *((_DWORD *)a4 + 2);
      return HIBYTE(v177);
    default:
      return off_16C96F8(*(_DWORD *)v29, a4);
  }
  while ( !sub_616480(*(&dword_91E088 + v66) + 22084, v183) )
  {
    if ( ++v66 >= dword_757C10 )
      goto LABEL_97;
  }
  v67 = v184;
  *((_DWORD *)v45 + 2) = -1;
  sub_474860(*(void **)v32, *(_DWORD *)(v32 + 4 * LODWORD(v67) + 112052), 1);
LABEL_97:
  v68 = sub_473390();
  *(_DWORD *)(v32 + 4 * v68 + 1696) = v181;
  *((_DWORD *)v45 + 2) = v68;
  memset(&STACK[0x3EF8], 0, 0x400u);
  GetModuleFileNameA(0, (LPSTR)&STACK[0x3EF8], 0x400u);
  v69 = strlen((const char *)&STACK[0x3EF8]);
  if ( *((_BYTE *)&STACK[0x3EF8] + v69) != 92 )
  {
    do
    {
      if ( v69 <= 0 )
        break;
      *((_BYTE *)&STACK[0x3EF8] + v69) = 0;
      v70 = *((_BYTE *)&STACK[0x3EF7] + v69--);
    }
    while ( v70 != 92 );
  }
  v71 = 0;
  do
  {
    v72 = *((_BYTE *)&STACK[0x3EF8] + v71);
    *((_BYTE *)&STACK[0x4648] + v71++) = v72;
  }
  while ( v72 );
  v73 = strlen(v182 + 2356) + 1;
  v74 = &STACK[0x4647];
  do
  {
    v75 = *((_BYTE *)v74 + 1);
    v74 = (unsigned int *)((char *)v74 + 1);
  }
  while ( v75 );
  qmemcpy(v74, v182 + 2356, v73);
  v76 = fopen((const char *)&STACK[0x4648], "rb");
  if ( v76 )
  {
    fclose(v76);
  }
  else if ( (unsigned __int8)sub_4735E0(&dword_B6CBA8) && dword_B73498 )
  {
LABEL_77:
    *((_DWORD *)a4 + 2) = -1;
    goto LABEL_114;
  }
  if ( !(unsigned __int8)sub_4735E0(&dword_B6CBA8) )
    goto LABEL_116;
  v77 = v182 + 2676;
  v78 = (char *)&STACK[0x3DF8] - (v182 + 2676);
  do
  {
    v79 = *v77;
    v77[v78] = *v77;
    ++v77;
  }
  while ( v79 );
LABEL_111:
  if ( !sub_473630(&dword_B6CBA8) || !(unsigned __int8)sub_486BC0(&dword_B6CEA4, &STACK[0x3DF8]) )
  {
LABEL_116:
    if ( !BYTE1(v178) )
    {
      v45 = a4;
LABEL_118:
      sub_4745E0();
      v163 = dbl_FB1D18;
      sub_51B2A0(4, 31, 2, 255, LODWORD(v163), 3);
      *((_BYTE *)v45 + 8) = *(_BYTE *)(v32 + 302704);
      *((_BYTE *)v45 + 9) = *(_BYTE *)(v32 + 302705);
      sub_4745E0();
      byte_FB1F3C = 1;
      sub_475ED0();
    }
    return HIBYTE(v177);
  }
  v165 = 2;
LABEL_114:
  sub_474860(*(void **)v32, *(_DWORD *)(v32 + 4 * v183 + 112052), v165);
  return HIBYTE(v177);
}
