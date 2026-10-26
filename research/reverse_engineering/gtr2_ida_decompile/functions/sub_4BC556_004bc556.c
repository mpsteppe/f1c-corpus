// positive sp value has been detected, the output may be wrong!
const char ***__usercall sub_4BC556@<eax>(int a1@<ecx>, const char *a2@<ebp>)
{
  unsigned int v2; // kr00_4
  __int32 v3; // esi
  unsigned int v4; // kr04_4
  char *v5; // eax
  int v7; // edi
  int v8; // eax
  int v9; // eax
  int v10; // eax
  const char ***result; // eax
  const char **v12; // esi
  const char *v13; // eax
  int v14; // eax
  const CHAR ***v15; // eax
  const CHAR **v16; // eax
  const CHAR *v17; // eax
  const char *v18; // eax
  int v19; // eax
  const char ***v20; // eax
  const char **v21; // eax
  const char *v22; // eax
  char *v23; // edx
  const char *v24; // eax
  int v25; // eax
  const CHAR ***v26; // eax
  const CHAR **v27; // eax
  const CHAR *v28; // eax
  const char *v29; // eax
  int v30; // eax
  const CHAR ***v31; // eax
  const CHAR **v32; // eax
  const CHAR *v33; // eax
  const char *v34; // eax
  int v35; // eax
  const CHAR ***v36; // eax
  const CHAR **v37; // esi
  const CHAR *v38; // eax
  const char *v39; // eax
  int v40; // eax
  const CHAR ***v41; // eax
  const CHAR **v42; // eax
  const CHAR *v43; // eax
  const char *v44; // eax
  int v45; // eax
  char *v46; // eax
  int v47; // esi
  char *v48; // eax
  char *v49; // eax
  char *v50; // eax
  const char *v51; // eax
  int v52; // eax
  char *v53; // esi
  char *v54; // eax
  const char *v55; // eax
  _DWORD *v56; // eax
  int v57; // esi
  int v58; // edi
  int v59; // ebp
  char *v60; // eax
  const char *v61; // eax
  const char *v62; // eax
  int v63; // eax
  const char *v64; // eax
  int v65; // eax
  char *v66; // eax
  const char *v67; // eax
  const char *v68; // eax
  int v69; // eax
  const char *v70; // eax
  int v71; // ecx
  int v72; // eax
  int v73; // eax
  int v74; // esi
  char *v75; // eax
  char *v76; // eax
  const char *v77; // eax
  const char *v78; // eax
  char *v80; // edx
  unsigned int v81; // eax
  char *v82; // edi
  const char *v86; // eax
  int v87; // eax
  char *v91; // edi
  unsigned int v92; // ecx
  const char *v93; // eax
  int v94; // esi
  const char *v95; // esi
  char *v96; // eax
  char *v97; // eax
  const char *v98; // eax
  const char *v99; // eax
  int v100; // eax
  const char *v101; // eax
  int v102; // eax
  int v103; // esi
  char *v104; // eax
  const char *v105; // eax
  int v106; // eax
  int v107; // esi
  int v108; // eax
  const char *v109; // eax
  char *v110; // eax
  const char *v111; // eax
  int v112; // eax
  int v113; // esi
  int v114; // eax
  int v115; // eax
  const char *v116; // eax
  int v117; // eax
  int v118; // ebp
  signed int v119; // esi
  int v120; // eax
  const char *v121; // eax
  int v122; // eax
  int v123; // eax
  const char *v124; // eax
  int v125; // eax
  int v126; // esi
  int v127; // eax
  const char *v128; // eax
  const char *v129; // eax
  const CHAR *v130; // eax
  const char *v131; // eax
  _DWORD *v132; // eax
  const CHAR *v133; // eax
  const char *v134; // eax
  const char *v135; // eax
  char v136; // cl
  const char *v137; // edx
  const char *v138; // ecx
  int *v139; // ecx
  int v140; // eax
  int v141; // eax
  char *v142; // esi
  const char *v143; // eax
  int v144; // eax
  char *v145; // [esp-Ch] [ebp-588h]
  char *v146; // [esp-8h] [ebp-584h]
  const char *v147; // [esp-8h] [ebp-584h]
  char *v148; // [esp-4h] [ebp-580h]
  char *v149; // [esp-4h] [ebp-580h]
  char *v150; // [esp-4h] [ebp-580h]
  float v151; // [esp+0h] [ebp-57Ch] BYREF
  const char *v152[4]; // [esp+4h] [ebp-578h] BYREF
  _BYTE v153[3]; // [esp+14h] [ebp-568h] BYREF
  char v154; // [esp+17h] [ebp-565h]
  _BYTE v155[3]; // [esp+18h] [ebp-564h] BYREF
  bool v156; // [esp+1Bh] [ebp-561h]
  char v157[17]; // [esp+1Ch] [ebp-560h] BYREF
  int v158; // [esp+2Dh] [ebp-54Fh]
  int v159; // [esp+31h] [ebp-54Bh]
  _BYTE v160[7]; // [esp+35h] [ebp-547h] BYREF
  float v161; // [esp+3Ch] [ebp-540h]
  float v162; // [esp+40h] [ebp-53Ch]
  float v163; // [esp+44h] [ebp-538h]
  int v164; // [esp+48h] [ebp-534h]
  char v165[21]; // [esp+50h] [ebp-52Ch] BYREF
  _DWORD v166[2]; // [esp+65h] [ebp-517h] BYREF
  _BYTE v167[21]; // [esp+6Dh] [ebp-50Fh] BYREF
  int v168; // [esp+82h] [ebp-4FAh]
  int v169; // [esp+86h] [ebp-4F6h] BYREF
  char v170[4]; // [esp+8Ah] [ebp-4F2h] BYREF
  __int16 ArgList; // [esp+8Eh] [ebp-4EEh]
  _WORD ArgList_2[128]; // [esp+90h] [ebp-4ECh] BYREF
  char v173[4]; // [esp+190h] [ebp-3ECh] BYREF
  char v174[4]; // [esp+198h] [ebp-3E4h] BYREF
  int v175; // [esp+1A0h] [ebp-3DCh] BYREF
  char v176[4]; // [esp+1A4h] [ebp-3D8h] BYREF
  char v177[4]; // [esp+1A8h] [ebp-3D4h] BYREF
  char v178[4]; // [esp+1B0h] [ebp-3CCh] BYREF
  char v179[4]; // [esp+1B4h] [ebp-3C8h] BYREF
  char v180[4]; // [esp+1D0h] [ebp-3ACh] BYREF
  char v181[4]; // [esp+1F8h] [ebp-384h] BYREF
  char v182[4]; // [esp+218h] [ebp-364h] BYREF
  char v183[4]; // [esp+234h] [ebp-348h] BYREF
  char v184[129]; // [esp+2B4h] [ebp-2C8h] BYREF
  __int16 v185; // [esp+335h] [ebp-247h]
  char v186; // [esp+337h] [ebp-245h]
  int v187; // [esp+338h] [ebp-244h] BYREF
  int v188; // [esp+370h] [ebp-20Ch] BYREF
  char v189[4]; // [esp+378h] [ebp-204h] BYREF
  int v190; // [esp+3F4h] [ebp-188h] BYREF
  char v191[4]; // [esp+3F8h] [ebp-184h] BYREF
  char v192[4]; // [esp+478h] [ebp-104h] BYREF

  strcpy(v157, "FT_Standard_TEXT");
  strcpy(v165, "FT_LISTBOX_HIGHLIGHT");
  v166[0] = 0;
  v166[1] = 0;
  *(_WORD *)v167 = 0;
  v167[2] = 0;
  v158 = 0;
  v159 = 0;
  v168 = 0;
  memset(v160, 0, sizeof(v160));
  strcpy(&v167[3], "FT_Standard_VALUE");
  v152[3] = a2;
  v169 = 0;
  *(_DWORD *)v170 = 0;
  memset(ArgList_2, 0, sizeof(ArgList_2));
  ArgList = 0;
  v7 = (int)v173;
  v156 = 0;
  v8 = sub_4CF8C0(a1);
  sub_630FE0(v157, v8, 31);
  v160[6] = 0;
  v9 = sub_4CF8E0(a1);
  sub_630FE0(v165, v9, 31);
  v167[2] = 0;
  v10 = sub_4CF900(a1);
  sub_630FE0(&v167[3], v10, 31);
  result = *(const char ****)(a1 + 600);
  HIBYTE(ArgList) = 0;
  *(_DWORD *)(a1 + 608) = result;
  if ( result )
  {
    v12 = *result;
    if ( *result )
    {
      while ( 1 )
      {
        v13 = *v12;
        if ( !*v12 )
          v13 = WindowName;
        if ( !_stricmp(v13, "<LOGO>") )
        {
          v14 = *(_DWORD *)(a1 + 608);
          if ( v14 )
            *(_DWORD *)(a1 + 608) = *(_DWORD *)(v14 + 4);
          v15 = *(const CHAR ****)(a1 + 608);
          if ( !v15 )
            goto LABEL_264;
          v16 = *v15;
          if ( !v16 )
            goto LABEL_264;
          v17 = *v16;
          if ( !v17 )
            v17 = WindowName;
          sub_41D810((char *)ArgList_2, 0xFFu, "%s%s", "<LOGO>", v17);
          goto LABEL_226;
        }
        v18 = *v12;
        if ( !*v12 )
          v18 = WindowName;
        if ( !_stricmp(v18, "<LOGO_RIGHT>") )
        {
          v19 = *(_DWORD *)(a1 + 608);
          if ( v19 )
            *(_DWORD *)(a1 + 608) = *(_DWORD *)(v19 + 4);
          v20 = *(const char ****)(a1 + 608);
          if ( !v20 )
            goto LABEL_264;
          v21 = *v20;
          if ( !v21 )
            goto LABEL_264;
          v22 = *v21;
          if ( !v22 )
            v22 = WindowName;
          sub_41D810(v192, 0xFFu, "%s%s", "<LOGO_RIGHT>", v22);
          v23 = v192;
          goto LABEL_197;
        }
        v24 = *v12;
        if ( !*v12 )
          v24 = WindowName;
        if ( !_stricmp(v24, "<LOGO_CENTER>") )
        {
          v25 = *(_DWORD *)(a1 + 608);
          if ( v25 )
            *(_DWORD *)(a1 + 608) = *(_DWORD *)(v25 + 4);
          v26 = *(const CHAR ****)(a1 + 608);
          if ( !v26 )
            goto LABEL_264;
          v27 = *v26;
          if ( !v27 )
            goto LABEL_264;
          v28 = *v27;
          if ( !v28 )
            v28 = WindowName;
          sub_41D810((char *)ArgList_2, 0xFFu, "%s%s", "<LOGO_CENTER>", v28);
          goto LABEL_226;
        }
        v29 = *v12;
        if ( !*v12 )
          v29 = WindowName;
        if ( !_stricmp(v29, "<HEADER>") )
        {
          v30 = *(_DWORD *)(a1 + 608);
          if ( v30 )
            *(_DWORD *)(a1 + 608) = *(_DWORD *)(v30 + 4);
          v31 = *(const CHAR ****)(a1 + 608);
          if ( v31 )
          {
            v32 = *v31;
            if ( v32 )
            {
              v33 = *v32;
              if ( !v33 )
                v33 = WindowName;
              sub_4D9550(v33, v165);
            }
          }
          goto LABEL_264;
        }
        v34 = *v12;
        if ( !*v12 )
          v34 = WindowName;
        if ( !_stricmp(v34, "<HEADER2>") )
        {
          v35 = *(_DWORD *)(a1 + 608);
          if ( v35 )
            *(_DWORD *)(a1 + 608) = *(_DWORD *)(v35 + 4);
          v36 = *(const CHAR ****)(a1 + 608);
          if ( v36 )
          {
            v37 = *v36;
            if ( *v36 )
            {
              v152[0] = (const char *)sub_4CF8E0(a1);
              v151 = 0.0;
              sub_4CE460(a1);
              v38 = *v37;
              if ( !*v37 )
                v38 = WindowName;
              sub_4D9550(v38, (char *)v166 + 3);
            }
          }
          goto LABEL_264;
        }
        v39 = *v12;
        if ( !*v12 )
          v39 = WindowName;
        if ( !_stricmp(v39, "<SET_FONT>") )
        {
          v40 = *(_DWORD *)(a1 + 608);
          if ( v40 )
            *(_DWORD *)(a1 + 608) = *(_DWORD *)(v40 + 4);
          v41 = *(const CHAR ****)(a1 + 608);
          if ( v41 )
          {
            v42 = *v41;
            if ( v42 )
            {
              v43 = *v42;
              if ( !v43 )
                v43 = WindowName;
              sub_630FE0(v157, v43, 31);
              v160[6] = 0;
            }
          }
          goto LABEL_264;
        }
        v44 = *v12;
        if ( !*v12 )
          v44 = WindowName;
        if ( !_stricmp(v44, "<STATUS>") )
          break;
        v51 = *v12;
        if ( !*v12 )
          v51 = WindowName;
        if ( !_stricmp(v51, "<BESTTIME>") )
        {
          v52 = (*(int (__thiscall **)(_DWORD, int))(**(_DWORD **)(a1 + 48) + 28))(*(_DWORD *)(a1 + 48), 58);
          if ( !v52 )
            goto LABEL_264;
          v53 = (char *)sub_4CE1C0(v52);
          v7 = sub_41D990(dword_B761EC, v53);
          v54 = sub_41D840(&byte_91CC38, "Best Time:");
          sub_41D810(&v170[2], 0xFFu, "%s", v54);
          v151 = sub_41D9B0(dword_B761EC, v53);
          sub_6153C0(v151);
          sub_41D810(&v170[2], 0xFFu, "%s %d:%06.3f", &v170[2], v164, v163);
          if ( v7 < 3 || v7 > 4 )
            goto LABEL_264;
LABEL_196:
          v23 = &v170[2];
LABEL_197:
          sub_4D93B0(v23, 0, v157, 0, 0, 0, -1, -1, -1, -1);
          goto LABEL_264;
        }
        v55 = *v12;
        if ( !*v12 )
          v55 = WindowName;
        if ( !_stricmp(v55, "<TECHNIQUE_CHALLENGES_COMPLETE>") )
        {
          v56 = (_DWORD *)(*(int (__thiscall **)(_DWORD, int))(**(_DWORD **)(a1 + 48) + 28))(*(_DWORD *)(a1 + 48), 57);
          if ( v56 )
          {
            v57 = v56[149];
            v58 = v56[150];
            v59 = v56[151];
            v60 = sub_41D840(&byte_91CC38, "Challenges Completed:");
            sub_41D810(&v170[2], 0xFFu, "%s", v60);
            v7 = v57 + v58;
            sub_41D810(&v170[2], 0xFFu, "%s %d / %d", &v170[2], v7, v59);
            goto LABEL_196;
          }
        }
        else
        {
          v61 = *v12;
          if ( !*v12 )
            v61 = WindowName;
          if ( !_stricmp(v61, "<TECHNIQUE_GOLDENGEARS>") )
            goto LABEL_257;
          v62 = *v12;
          if ( !*v12 )
            v62 = WindowName;
          v63 = _stricmp(v62, "<TECHNIQUE_GOLDENGEARS_CENTERED>");
          v156 = v63 == 0;
          if ( !v63 )
          {
LABEL_257:
            v139 = *(int **)(a1 + 48);
            v140 = *v139;
            v152[0] = (const char *)57;
            v141 = (*(int (__thiscall **)(int *))(v140 + 28))(v139);
            if ( v141 )
            {
              v142 = *(char **)(v141 + 596);
              v143 = "<LOGO_RIGHT>";
              if ( v154 )
                v143 = "<LOGO_CENTER>";
              sub_41D810(&v170[2], 0xFFu, "%sGoldGear_large.tga", v143);
              sub_4D93B0(&v170[2], 0, v155, 0, 0, 0, -1, -1, -1, -1);
              sub_4D93B0("  ", 0, v155, 0, 0, 0, -1, -1, -1, -1);
              v151 = *(float *)&v142;
              if ( v154 )
                sub_41D810(&v170[2], 0xFFu, "            %d", v151);
              else
                sub_41D810(&v170[2], 0xFFu, "%d  ", v151);
              sub_4D93B0(ArgList_2, v155, 0, 0, 0, -1, -1, -1, -1, v152[0]);
            }
            goto LABEL_264;
          }
          v64 = *v12;
          if ( !*v12 )
            v64 = WindowName;
          if ( !_stricmp(v64, "<TECHNIQUE_GOLD>") )
          {
            v65 = (*(int (__thiscall **)(_DWORD, int))(**(_DWORD **)(a1 + 48) + 28))(*(_DWORD *)(a1 + 48), 58);
            if ( !v65 )
              goto LABEL_264;
            v66 = (char *)sub_4CE1C0(v65);
            if ( sub_41D990(dword_B761EC, v66) != 4 )
              goto LABEL_264;
            sub_41D810(&v170[2], 0xFFu, "%sGoldGear_large.tga", "<LOGO_RIGHT>");
            goto LABEL_226;
          }
          v67 = *v12;
          if ( !*v12 )
            v67 = WindowName;
          if ( !_stricmp(v67, "<CHAMP_ICON>") )
            goto LABEL_250;
          v68 = *v12;
          if ( !*v12 )
            v68 = WindowName;
          v69 = _stricmp(v68, "<CHAMP_ICON_CENTERED>");
          v156 = v69 == 0;
          if ( !v69 )
          {
LABEL_250:
            v152[0] = (const char *)127;
            sub_4152E0();
            sub_40D7E0(v183);
            v135 = v183;
            if ( v183[0] == 32 )
            {
              do
                v136 = *++v135;
              while ( v136 == 32 );
            }
            v137 = "<LOGO_RIGHT>";
            if ( v154 )
              v137 = "<LOGO_CENTER>";
            v138 = *(const char **)dword_91CA70;
            if ( !*(_DWORD *)dword_91CA70 )
              v138 = WindowName;
            sub_41D810(&v170[2], 0xFFu, "%s%s%s_Icon.tga", v137, v138, v135);
            sub_4D93B0(0, v155, 0, 0, 0, -1, -1, -1, -1, v152[0]);
            goto LABEL_264;
          }
          v70 = *v12;
          if ( !*v12 )
            v70 = WindowName;
          if ( !_stricmp(v70, "<TOUNLOCK>") )
          {
            v71 = *(_DWORD *)(a1 + 48);
            LOBYTE(ArgList_2[0]) = 0;
            v72 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v71 + 28))(v71, 66);
            if ( !v72 )
              goto LABEL_264;
            sub_4CE1C0(v72);
            v151 = 0.0;
            v73 = sub_41E110();
            if ( !v73 )
              goto LABEL_264;
            v7 = *(_DWORD *)(v73 + 8);
            v74 = *(_DWORD *)(v73 + 12);
            if ( dword_B76220 >= v7 && dword_B76220 + dword_B76224 >= v74 )
              goto LABEL_264;
            v75 = sub_41D840(&byte_91CC38, "Driving School status needed to unlock:");
            sub_4D93B0(v75, 0, v153, 0, 0, 0, -1, -1, -1, -1);
            if ( v74 > 0 )
            {
              v76 = sub_41D840(&byte_91CC38, "Challenges complete");
              sub_41D810((char *)&v169 + 2, 0xFFu, "   %s - %d", v76, v74);
              sub_4D93B0((char *)&v169 + 2, 0, v153, 0, 0, 0, -1, -1, -1, -1);
            }
            if ( v7 <= 0 )
              goto LABEL_264;
            v146 = sub_41D840(&byte_91CC38, "Gold Gears");
            sub_41D810((char *)&v169 + 2, 0xFFu, "   %s - %d", v146, v7);
            goto LABEL_196;
          }
          v77 = *v12;
          if ( !*v12 )
            v77 = WindowName;
          if ( !_stricmp(v77, "<DRIVER_NAME>") )
          {
            sub_501490(&v187, 63);
            v152[0] = (const char *)&v187;
            v151 = COERCE_FLOAT("Driver Name:");
            goto LABEL_2;
          }
          v78 = *v12;
          if ( !*v12 )
            v78 = WindowName;
          if ( !_stricmp(v78, "<CHAMP_STATUS>") )
          {
            v152[0] = (const char *)255;
            sub_41D840(&byte_91CC38, "Championship Status:");
            sub_4152E0();
            v7 = (int)&v170[1];
            while ( *(_BYTE *)++v7 )
              ;
            *(_WORD *)v7 = 32;
            switch ( sub_534F50(&unk_B76270) )
            {
              case 0:
              case 1:
                v151 = 0.0;
                if ( (unsigned __int8)sub_41E190() )
                {
                  v80 = sub_41D840(&byte_91CC38, "Locked");
                  v81 = strlen(v80) + 1;
                  v82 = &v167[18];
                  while ( *++v82 )
                    ;
                }
                else
                {
                  v80 = sub_41D840(&byte_91CC38, "Open");
                  v81 = strlen(v80) + 1;
                  v82 = &v167[18];
                  while ( *++v82 )
                    ;
                }
                goto LABEL_152;
              case 2:
                v80 = sub_41D840(&byte_91CC38, "In-Progress");
                v81 = strlen(v80) + 1;
                v82 = &v170[1];
                while ( *++v82 )
                  ;
                goto LABEL_152;
              case 3:
                v86 = Str;
                if ( !Str )
                  v86 = WindowName;
                if ( strstr(v86, "Custom") )
                {
                  v151 = 0.0;
                  v87 = sub_41D9E0();
                  if ( v87 <= 0 || v87 > 2 )
                  {
                    v80 = sub_41D840(&byte_91CC38, "Failed");
                    v81 = strlen(v80) + 1;
                    v82 = (char *)&v169 + 1;
                    while ( *++v82 )
                      ;
                  }
                  else
                  {
                    v80 = sub_41D840(&byte_91CC38, "Completed");
                    v81 = strlen(v80) + 1;
                    v82 = (char *)&v169 + 1;
                    while ( *++v82 )
                      ;
                  }
                }
                else
                {
                  v80 = sub_41D840(&byte_91CC38, "Completed");
                  v81 = strlen(v80) + 1;
                  v82 = &v170[1];
                  while ( *++v82 )
                    ;
                }
LABEL_152:
                qmemcpy(v82, v80, 4 * (v81 >> 2));
                v91 = &v82[4 * (v81 >> 2)];
                v92 = v81 & 3;
                qmemcpy(v91, &v80[4 * (v81 >> 2)], v92);
                v7 = (int)&v91[v92];
                break;
              default:
                goto LABEL_226;
            }
            goto LABEL_226;
          }
          v93 = *v12;
          if ( !*v12 )
            v93 = WindowName;
          if ( !_stricmp(v93, "<BEST_FINISH>") )
          {
            v94 = sub_41DA40(dword_B761EC, 0);
            v161 = sub_41DA00(dword_B761EC, 0);
            if ( v94 > -1 )
            {
              v95 = (const char *)(v94 + 1);
              sub_495C10((const char *)v7, (int)v95, v173, 7u);
              v152[0] = v173;
              v96 = sub_41D840(&byte_91CC38, "Best Finish:");
              sub_41D810((char *)ArgList_2, 0xFFu, "%s %s", v96, v152[0]);
              v152[0] = v95;
              v2 = __readeflags();
              v3 = dword_16C6DBC - *(_DWORD *)((char *)&loc_50F5F7 + 1);
              __writeeflags(v2);
              _InterlockedExchange((volatile __int32 *)v152, v3);
              v97 = sub_41D840(&byte_91CC38, v152[0]);
              sub_41D810((char *)ArgList_2, 0xFFu, "%s, %.0f %s", (const char *)ArgList_2, v161, v97);
              goto LABEL_226;
            }
          }
          else
          {
            v98 = *v12;
            if ( !*v12 )
              v98 = WindowName;
            if ( !_stricmp(v98, "<CHAMP_TROPHY>") )
              goto LABEL_246;
            v99 = *v12;
            if ( !*v12 )
              v99 = WindowName;
            v100 = _stricmp(v99, "<CHAMP_TROPHY_CENTERED>");
            v156 = v100 == 0;
            if ( !v100 )
            {
LABEL_246:
              v152[0] = 0;
              if ( sub_41D9E0() == 1 )
              {
                v134 = "<LOGO_RIGHT>";
                if ( v154 )
                  v134 = "<LOGO_CENTER>";
                sub_41D810(&v170[2], 0xFFu, "%strophy_small.tga", v134);
                sub_4D93B0(0, v155, 0, 0, 0, -1, -1, -1, -1, v152[0]);
              }
              goto LABEL_264;
            }
            v101 = *v12;
            if ( !*v12 )
              v101 = WindowName;
            if ( !_stricmp(v101, "<DRIVER_POSITION>") )
            {
              if ( sub_534F50(&unk_B76270) != 2 )
                goto LABEL_264;
              if ( !((int (__thiscall *)(void *))sub_535010)(&unk_B76270) )
                goto LABEL_264;
              v102 = sub_532D20(&unk_B76270);
              v7 = v102;
              if ( !v102 )
                goto LABEL_264;
              v103 = ((int (__thiscall *)(int))sub_5304D0)(v102);
              if ( !v103 || ((int (__thiscall *)(int))sub_5304A0)(v7) <= 0 )
                goto LABEL_264;
              sub_495C10((const char *)v7, *(_DWORD *)(v103 + 800) + 1, v174, 7u);
              v162 = *(float *)(v103 + 792);
              v104 = sub_41D840(&byte_91CC38, "points");
              sub_41D810(v182, 0x1Fu, "%s, %.0f %s", v174, v162, v104);
              v152[0] = v182;
              v151 = COERCE_FLOAT("Position:");
LABEL_2:
              v151 = COERCE_FLOAT(sub_41D840(off_16C9A0C, (const char *)LODWORD(v151)));
              sub_41D810((char *)ArgList_2, 0xFFu, "%s %s", v151, v152[0]);
LABEL_226:
              sub_4D93B0(ArgList_2, 0, v157, 0, 0, 0, -1, -1, -1, -1);
              goto LABEL_264;
            }
            v105 = *v12;
            if ( !*v12 )
              v105 = WindowName;
            if ( !_stricmp(v105, "<CAT_DRIVER_POSITION>") )
            {
              if ( sub_534F50(&unk_B76270) != 2 )
                goto LABEL_264;
              if ( !((int (__thiscall *)(void *))sub_535010)(&unk_B76270) )
                goto LABEL_264;
              v106 = sub_532D20(&unk_B76270);
              v7 = v106;
              if ( !v106 )
                goto LABEL_264;
              v107 = ((int (__thiscall *)(int))sub_5304D0)(v106);
              if ( !v107 || ((int (__thiscall *)(int))sub_5304A0)(v7) <= 0 )
                goto LABEL_264;
              v7 = 0;
              v108 = sub_616840("CATEGORY");
              if ( v108 )
                v7 = sub_6165F0(v108) - 1;
              if ( sub_616840("CategoryLists") )
              {
                v109 = (const char *)sub_616930("CategoryLists");
                v7 = atol(v109);
              }
              if ( *(_DWORD *)(v107 + 844) > v7 )
                goto LABEL_264;
              sub_495C10((const char *)v7, *(_DWORD *)(v107 + 804) + 1, v178, 7u);
              v163 = *(float *)(v107 + 796);
              v110 = sub_41D840(&byte_91CC38, "points");
              sub_41D810(v181, 0x1Fu, "%s, %.0f %s", v178, v163, v110);
              v152[0] = v181;
              v151 = COERCE_FLOAT("Category Position:");
              goto LABEL_2;
            }
            v111 = *v12;
            if ( !*v12 )
              v111 = WindowName;
            if ( !_stricmp(v111, "<TEAM_POSITION>") )
            {
              if ( sub_534F50(&unk_B76270) != 2 )
                goto LABEL_264;
              if ( !((int (__thiscall *)(void *))sub_535010)(&unk_B76270) )
                goto LABEL_264;
              v112 = sub_532D20(&unk_B76270);
              v113 = v112;
              if ( !v112
                || ((int (__thiscall *)(int))sub_5304A0)(v112) <= 0
                || !((int (__thiscall *)(int))sub_5304D0)(v113) )
              {
                goto LABEL_264;
              }
              sub_532290(v191, 128);
              v152[0] = (const char *)7;
              v151 = COERCE_FLOAT(v177);
              v114 = ((int (__thiscall *)(int))sub_532800)(v113);
              sub_495C10((const char *)v7, v114, v191, LODWORD(v151));
              v151 = COERCE_FLOAT(sub_41D840(&byte_91CC38, "points"));
              v115 = sub_5326E0(&v190);
              sub_41D810(v179, 0x1Fu, "%s, %d %s", v176, v115, (const char *)LODWORD(v151));
              v151 = COERCE_FLOAT(v179);
              v149 = sub_41D840(&byte_91CC38, "Team Position:");
              sub_41D810((char *)&v169 + 2, 0xFFu, v145, "%s %s", v149);
              goto LABEL_196;
            }
            v116 = *v12;
            if ( !*v12 )
              v116 = WindowName;
            if ( !_stricmp(v116, "<CAT_TEAM_POSITION>") )
            {
              if ( sub_534F50(&unk_B76270) != 2 )
                goto LABEL_264;
              if ( !((int (__thiscall *)(void *))sub_535010)(&unk_B76270) )
                goto LABEL_264;
              v117 = sub_532D20(&unk_B76270);
              v7 = v117;
              if ( !v117 )
                goto LABEL_264;
              v118 = ((int (__thiscall *)(int))sub_5304D0)(v117);
              if ( !v118 || ((int (__thiscall *)(int))sub_5304A0)(v7) <= 0 )
                goto LABEL_264;
              v119 = 0;
              v120 = sub_616840("CATEGORY");
              if ( v120 )
                v119 = sub_6165F0(v120) - 1;
              if ( sub_616840("CategoryLists") )
              {
                v121 = (const char *)sub_616930("CategoryLists");
                v119 = atol(v121);
              }
              if ( *(_DWORD *)(v118 + 844) > v119 )
                goto LABEL_264;
              sub_532290(v189, 128);
              v152[0] = (const char *)7;
              v151 = COERCE_FLOAT(&v175);
              v122 = ((int (__thiscall *)(int))sub_532EE0)(v7);
              sub_495C10((const char *)v7, v122, v189, v119);
              v150 = sub_41D840(&byte_91CC38, "points");
              v123 = sub_532DB0(&v188, v119);
              sub_41D810(v180, 0x1Fu, "%s, %d %s", v174, v123, v150);
              v148 = v180;
              sub_41D840(&byte_91CC38, "Category Team Position:");
              goto LABEL_225;
            }
            v124 = *v12;
            if ( !*v12 )
              v124 = WindowName;
            if ( !_stricmp(v124, "<CATEGORY>") )
            {
              if ( sub_534F50(&unk_B76270) != 2 )
                goto LABEL_264;
              if ( !((int (__thiscall *)(void *))sub_535010)(&unk_B76270) )
                goto LABEL_264;
              v125 = sub_532D20(&unk_B76270);
              if ( !v125 )
                goto LABEL_264;
              v7 = ((int (__thiscall *)(int))sub_5304D0)(v125);
              if ( !v7 )
                goto LABEL_264;
              v126 = 0;
              v127 = sub_616840("CATEGORY");
              if ( v127 )
                v126 = sub_6165F0(v127) - 1;
              if ( sub_616840("CategoryLists") )
              {
                v128 = (const char *)sub_616930("CategoryLists");
                v126 = atol(v128);
              }
              if ( *(_DWORD *)(v7 + 844) > v126 )
                goto LABEL_264;
              v7 += 912;
              v152[0] = (const char *)v7;
              v151 = COERCE_FLOAT("Category:");
              sub_41D840(&byte_91CC38, v147);
LABEL_225:
              sub_41D810((char *)ArgList_2, 0xFFu, v148, v151, v152[0]);
              goto LABEL_226;
            }
            v129 = *v12;
            if ( !*v12 )
              v129 = WindowName;
            if ( _stricmp(v129, "<NEXT_ROUND>") )
            {
              v133 = *v12;
              if ( !*v12 )
                v133 = WindowName;
              sub_4D9550(v133, v157);
              goto LABEL_264;
            }
            if ( sub_534F50(&unk_B76270) == 2 && ((int (__thiscall *)(void *))sub_535010)(&unk_B76270) )
            {
              memset(&v184[4], 0, 125);
              v185 = 0;
              v186 = 0;
              v7 = (int)&v187;
              v130 = *(const CHAR **)((int (__thiscall *)(void *))sub_535010)(&unk_B76270);
              if ( !v130 )
                v130 = WindowName;
              sub_538860(&unk_BE1CFD, v130, v152[1], v152[2]);
              if ( sub_53A250(0) )
              {
                v131 = Str;
                if ( !Str )
                  v131 = WindowName;
                if ( strstr(v131, "Custom") )
                  v151 = COERCE_FLOAT("VenueName");
                else
                  v151 = COERCE_FLOAT("TrackName");
                v132 = (_DWORD *)sub_616630((char *)LODWORD(v151));
                if ( v132 )
                  strcpy(v184, sub_48D380(v132));
              }
              v151 = COERCE_FLOAT(v184);
              goto LABEL_2;
            }
          }
        }
LABEL_264:
        v144 = *(_DWORD *)(a1 + 608);
        if ( v144 )
          *(_DWORD *)(a1 + 608) = *(_DWORD *)(v144 + 4);
        result = *(const char ****)(a1 + 608);
        if ( result )
        {
          v12 = *result;
          if ( *result )
            continue;
        }
        return result;
      }
      v45 = (*(int (__thiscall **)(_DWORD, int))(**(_DWORD **)(a1 + 48) + 28))(*(_DWORD *)(a1 + 48), 58);
      if ( !v45 )
        goto LABEL_264;
      v46 = (char *)sub_4CE1C0(v45);
      v47 = sub_41D990(dword_B761EC, v46);
      v48 = sub_41D840(&byte_91CC38, "Status:");
      v49 = (char *)sub_41D810(&v170[2], 0xFFu, "%s", v48);
      if ( v47 == 2 )
      {
        v151 = COERCE_FLOAT("FAILED");
      }
      else
      {
        if ( v47 <= 2 || v47 > 4 )
        {
          sub_41D810(&v170[2], 0xFFu, (char *)WindowName);
          goto LABEL_76;
        }
        v151 = *(float *)&v49;
        v4 = __readeflags();
        v5 = (char *)sub_FF8EE0 + dword_16C6DF8 + 1;
        __writeeflags(v4);
        _InterlockedExchange((volatile __int32 *)&v151, (__int32)v5);
      }
      v50 = sub_41D840(&byte_91CC38, (const char *)LODWORD(v151));
      sub_41D810(&v170[2], 0xFFu, "%s %s", &v170[2], v50);
LABEL_76:
      *(_DWORD *)&v160[3] = strlen(&v170[2]);
      if ( *(_DWORD *)&v160[3] )
        goto LABEL_226;
      goto LABEL_264;
    }
  }
  return result;
}
