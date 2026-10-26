void __userpurge sub_56C5C0(
        void *a1@<edi>,
        void *a2,
        char *a3,
        void *a4,
        void *a5,
        void *Block,
        int a7,
        void *a8,
        int a9,
        void *a10,
        int a11,
        void *a12,
        int a13,
        int a14,
        int a15,
        int a16,
        char *a17,
        int a18,
        void *a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        char a29,
        int a30,
        int a31,
        int a32,
        int a33,
        int a34,
        int a35,
        int a36,
        int a37,
        int a38,
        int a39,
        int a40,
        int a41,
        int a42,
        int a43,
        char a44,
        int a45,
        int a46,
        int a47,
        int a48,
        int a49,
        int a50,
        int a51,
        int a52,
        char a53,
        int a54,
        int a55,
        int a56,
        int a57,
        int a58,
        int a59,
        char a60,
        int a61,
        int a62,
        int a63)
{
  int a65; // [esp+1B64h] [ebp+104h] BYREF
  const CHAR **v65; // ecx
  const CHAR **v66; // edi
  int v67; // edx
  const CHAR *v68; // eax
  const char *v69; // edx
  int v70; // eax
  const char *i; // eax
  const CHAR *v72; // eax
  const CHAR *v73; // eax
  const CHAR *v74; // eax
  const CHAR **v75; // edi
  const CHAR *v76; // eax
  const char *v77; // edx
  int v78; // eax
  const char *j; // eax
  const char *v80; // ecx
  const char *v81; // eax
  char *v82; // eax
  int v83; // ecx
  char v84; // dl
  unsigned int v85; // eax
  unsigned int *v86; // edi
  char v87; // cl
  char *v88; // edi
  const CHAR *v90; // eax
  const char *v91; // eax
  const char *v92; // esi
  char *v93; // edi
  const CHAR **v95; // eax
  bool v96; // zf
  unsigned int *v97; // ebx
  char *v98; // esi
  const char *v99; // eax
  const char *v100; // eax
  const char *v101; // ecx
  unsigned int *v102; // ecx
  int v103; // esi
  const char *v104; // eax
  const char *v105; // eax
  unsigned int v106; // ecx
  char *v107; // eax
  int v108; // edx
  char v109; // cl
  unsigned int v110; // eax
  char *v111; // edi
  int v113; // eax
  const char **v114; // esi
  const CHAR *v115; // eax
  const char *v116; // edx
  int v117; // eax
  const char *k; // eax
  const CHAR *v119; // eax
  const CHAR *v120; // eax
  const char *v121; // edi
  const char *v122; // ecx
  const char *v123; // eax
  char *v124; // eax
  int v125; // eax
  int *v126; // esi
  int v127; // edi
  const char *v128; // ebx
  int m; // esi
  void *v130; // eax
  const char *v131; // [esp+1A20h] [ebp-40h]
  unsigned int *v132; // [esp+1A24h] [ebp-3Ch]
  int v133; // [esp+1A30h] [ebp-30h]
  const char *v134; // [esp+1A34h] [ebp-2Ch]
  int v135; // [esp+1A38h] [ebp-28h]
  char *v136; // [esp+1A3Ch] [ebp-24h]
  char *v138; // [esp+1A4Ch] [ebp-14h]
  float v139; // [esp+1A50h] [ebp-10h]
  char *v140; // [esp+1A50h] [ebp-10h]
  int *v141; // [esp+1A54h] [ebp-Ch]
  const CHAR **v142; // [esp+1A5Ch] [ebp-4h]
  const CHAR **vars0; // [esp+1A60h] [ebp+0h]
  void *vars0a; // [esp+1A60h] [ebp+0h]
  char *retaddr; // [esp+1A64h] [ebp+4h]
  const char *v146; // [esp+1A7Ch] [ebp+1Ch]

  sub_631BD0();
  v66 = v65;
  a23 = v67;
  vars0 = v65;
  if ( v65 )
  {
    retaddr = (char *)operator new(0x100u);
    *retaddr = 0;
    STACK[0x34C0] = 0;
    *(_BYTE *)operator new(0x100u) = 0;
    LOBYTE(STACK[0x34C0]) = 1;
    *(_BYTE *)operator new(0x100u) = 0;
    LOBYTE(STACK[0x34C0]) = 2;
    a13 = (int)operator new(0x100u);
    *(_BYTE *)a13 = 0;
    a14 = 256;
    LOBYTE(STACK[0x34C0]) = 3;
    v146 = (const char *)operator new(0x100u);
    *v146 = 0;
    v68 = *v66;
    v96 = *v66 == 0;
    LOBYTE(STACK[0x34C0]) = 4;
    if ( v96 )
      v68 = WindowName;
    sub_615860(v68);
    v69 = retaddr;
    if ( !retaddr )
      v69 = WindowName;
    v70 = strlen(v69);
    if ( v70 > 0 )
    {
      for ( i = &v69[v70 - 1]; i >= v69; *i-- = 0 )
      {
        if ( *i == 92 )
          break;
      }
    }
    v72 = retaddr;
    if ( !retaddr )
      v72 = WindowName;
    sub_615860(v72);
    v73 = retaddr;
    if ( !retaddr )
      v73 = WindowName;
    sub_615860(v73);
    v74 = retaddr;
    if ( !retaddr )
      v74 = WindowName;
    sub_615860(v74);
    v75 = vars0;
    v76 = *vars0;
    if ( !*vars0 )
      v76 = WindowName;
    sub_615860(v76);
    v77 = v146;
    if ( !v146 )
      v77 = WindowName;
    v78 = strlen(v77);
    if ( v78 > 0 )
    {
      for ( j = &v77[v78 - 1]; j >= v77; *j-- = 0 )
      {
        if ( *j == 92 )
          break;
      }
    }
    v80 = (const char *)dword_91CAE8;
    if ( !dword_91CAE8 )
      v80 = WindowName;
    v81 = *(const char **)dword_91CA70;
    if ( !*(_DWORD *)dword_91CA70 )
      v81 = WindowName;
    sprintf((char *const)&STACK[0x2634], "%s%s", v81, v80);
    v82 = (char *)(396 * dword_BE1CD4 + dword_BE1CD8 + 4);
    a17 = 0;
    v83 = (char *)&STACK[0x2234] - v82;
    do
    {
      v84 = *v82;
      v82[v83] = *v82;
      ++v82;
    }
    while ( v84 );
    v139 = sub_5529A0(dword_FADD40);
    if ( byte_FADD28 )
      v139 = sub_54B400(dword_BE27B0);
    if ( v139 != -1.0 )
    {
      sub_53A560(v139, &STACK[0x1B88], 64);
      v85 = strlen((const char *)&STACK[0x1B88]) + 1;
      v86 = &STACK[0x222F];
      do
      {
        v87 = *((_BYTE *)v86 + 1);
        v86 = (unsigned int *)((char *)v86 + 1);
      }
      while ( v87 );
      qmemcpy(v86, &STACK[0x1B88], v85);
      v88 = (char *)&STACK[0x222F];
      while ( *++v88 )
        ;
      strcpy(v88, ".GTR");
      sub_5EE940((int)&a16, (char)&STACK[0x2230], 0);
      v75 = v142;
    }
    a15 = 0;
    a14 = 0;
    a19 = 0;
    if ( byte_B71C00 )
    {
      sprintf((char *const)&STACK[0x1BC8], "%s_ULTRA_TEX.GTR", (const char *)v75 + 1716);
      sub_615A50(&STACK[0x1BC8]);
      sub_5EE940((int)&a14, 0, 0);
    }
    if ( byte_B71C18 )
    {
      sprintf((char *const)&STACK[0x1BC8], "%s_CPIT_ULTRA_TEX.GTR", (const char *)v75 + 1716);
      sub_615A50(&STACK[0x1BC8]);
      sub_5EE940((int)&a19, 0, 0);
    }
    sprintf((char *const)&STACK[0x1BC8], "%s_TEX.GTR", (const char *)v75 + 1716);
    sub_615A50(&STACK[0x1BC8]);
    sub_5EE940((int)&a15, 0, 0);
    sub_615A50("TEAM.GTR");
    LOBYTE(v90) = (_BYTE)vars0;
    a17 = 0;
    if ( !vars0 )
      v90 = WindowName;
    sub_5EE940((int)&a17, (char)v90, 0);
    sub_613B30(&a44);
    v91 = v75[8];
    LOBYTE(STACK[0x34BC]) = 5;
    v92 = v91;
    if ( !v91 )
      v92 = WindowName;
    strcpy((char *)&STACK[0x2430], v92);
    if ( !byte_B71194 && strlen(v92) > 4 )
    {
      *((_BYTE *)&STACK[0x242C] + strlen(v92)) = 0;
      v93 = (char *)&STACK[0x242F];
      while ( *++v93 )
        ;
      strcpy(v93, "_2DW.CAS");
    }
    if ( !(unsigned __int8)sub_614460(&STACK[0x2430], 1) && !(unsigned __int8)sub_614460(v92, 1) )
    {
      if ( sub_5612D0(byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\vehgfx.cpp", 795) )
        sub_561210((int)byte_FAE910, "Could not open %s", v92);
      LOBYTE(STACK[0x34BC]) = 4;
      sub_614140(&a44);
      if ( Block )
        j_j__free(Block);
      j_j__free((void *)0x100);
      j_j__free((void *)0x100);
      j_j__free((void *)0x100);
      v95 = vars0;
      v96 = vars0 == 0;
LABEL_154:
      if ( !v96 )
        j_j__free(v95);
      return;
    }
    memset(&STACK[0x2030], 0, 0x200u);
    STACK[0x2018] = 0;
    STACK[0x202C] = 0;
    STACK[0x2024] = 0;
    STACK[0x2028] = 0;
    LOBYTE(STACK[0x201C]) = 1;
    a34 = 0;
    a35 = 0;
    a36 = 0;
    a37 = 0;
    a38 = 0;
    a39 = 0;
    a40 = 0;
    a41 = 0;
    a42 = 0;
    a43 = 0;
    if ( !sub_613DE0((char *)&STACK[0x2030], 512) )
    {
LABEL_75:
      sub_613C30(&a36);
      sprintf((char *const)&STACK[0x1C10], "%s_%s", v136 + 1716, v136 + 2108);
      if ( sub_53A2B0((int)&STACK[0x1D78], 128, "TrackName", 0) )
        LOBYTE(STACK[0x1D78]) = 0;
      v103 = *((_DWORD *)v136 + 686);
      v140 = 0;
      if ( v103 )
      {
        while ( 1 )
        {
          v104 = *(const char **)v103;
          if ( !*(_DWORD *)v103 )
            v104 = WindowName;
          if ( !_stricmp(v104, (const char *)&STACK[0x1D78]) )
            break;
          v103 = *(_DWORD *)(v103 + 16);
          if ( !v103 )
            goto LABEL_88;
        }
        v140 = *(char **)(v103 + 8);
        if ( !v140 )
          v140 = (char *)WindowName;
      }
LABEL_88:
      sub_630A11(&a20, 8, 3, &off_4075B0, sub_498720);
      LOBYTE(STACK[0x349C]) = 6;
      sub_630A11(&a60, 8, 3, &off_4075B0, sub_498720);
      a13 = -1;
      a15 = 0;
      a16 = -1;
      LOBYTE(STACK[0x349C]) = 9;
      do
      {
        v107 = off_903BB8[0];
        v138 = off_903D00[0];
        v108 = (char *)&STACK[0x1B68] - off_903BB8[0];
        do
        {
          v109 = *v107;
          v107[v108] = *v107;
          ++v107;
        }
        while ( v109 );
        if ( a3 )
        {
          v110 = strlen(a3) + 1;
          v111 = (char *)&a65 + 3;
          while ( *++v111 )
            ;
          qmemcpy(v111, a3, v110);
        }
        v113 = 0;
        v135 = 0;
        if ( a14 && *(_BYTE *)a14 )
        {
          v113 = 1;
          a17 = (char *)a14;
          v135 = 1;
        }
        if ( v140 && *v140 )
        {
          (&a17)[v113++] = v140;
          v135 = v113;
        }
        if ( v113 < 3 && LOBYTE(STACK[0x1C10]) )
        {
          (&a17)[v113++] = (char *)&STACK[0x1C10];
          v135 = v113;
        }
        v133 = 0;
        if ( v113 <= 0 )
          goto LABEL_130;
        v114 = (const char **)&a20;
        do
        {
          v115 = *(const CHAR **)v136;
          if ( !*(_DWORD *)v136 )
            v115 = WindowName;
          sub_615860(v115);
          v116 = *v114;
          if ( !*v114 )
            v116 = WindowName;
          v117 = strlen(v116);
          if ( v117 > 0 )
          {
            for ( k = &v116[v117 - 1]; k >= v116; *k-- = 0 )
            {
              if ( *k == 92 )
                break;
            }
          }
          v119 = *v114;
          if ( !*v114 )
            v119 = WindowName;
          sub_615860(v119);
          v120 = *v114;
          if ( !*v114 )
            v120 = WindowName;
          sub_615860(v120);
          sub_615A50(&off_6F4924);
          v121 = (&a17)[v133];
          sub_615A50(v121);
          v122 = *v114;
          if ( !*v114 )
            v122 = WindowName;
          v123 = &v122[strlen(v122)];
          if ( v123 > v122 )
          {
            while ( *v123 != 46 )
            {
              if ( --v123 <= v122 )
                goto LABEL_125;
            }
            *v123 = 0;
          }
LABEL_125:
          sub_615A50(v138);
          v124 = strchr(v121, 46);
          if ( v124 )
            sub_615A50(v124);
          else
            sub_615A50(".bmp");
          v125 = v133 + 1;
          v114 += 2;
          ++v133;
        }
        while ( v133 < v135 );
        if ( v125 < 3 )
        {
LABEL_130:
          v126 = &a20 + 2 * v133;
          v127 = 3 - v133;
          do
          {
            sub_615860(WindowName);
            v126 += 2;
            --v127;
          }
          while ( v127 );
        }
        sub_568230();
        v128 = v131++;
      }
      while ( (int)(v128 + 1) < 81 );
      if ( a4 )
        sub_5EEA30(dword_FB1CE0, a4, 0);
      if ( retaddr )
        sub_5EEA30(dword_FB1CE0, retaddr, 0);
      if ( Block )
        sub_5EEA30(dword_FB1CE0, Block, 0);
      if ( a3 )
        sub_5EEA30(dword_FB1CE0, a3, 0);
      for ( m = 0; m < v135; ++m )
      {
        v130 = *(&a19 + m);
        if ( v130 )
          sub_5EEA30(dword_FB1CE0, v130, 0);
      }
      j_j__free((void *)0x100);
      LOBYTE(STACK[0x3480]) = 6;
      `eh vector destructor iterator'(&a53, 8u, 3, (void (__thiscall *)(void *))sub_498720);
      LOBYTE(STACK[0x3480]) = 5;
      `eh vector destructor iterator'(&a13, 8u, 3, (void (__thiscall *)(void *))sub_498720);
      LOBYTE(STACK[0x3480]) = 4;
      sub_614140(&a29);
      if ( v136 )
        j_j__free(v136);
      if ( v141 )
        j_j__free(v141);
      if ( a1 )
        j_j__free(a1);
      if ( v138 )
        j_j__free(v138);
      v95 = (const CHAR **)v132;
      v96 = v132 == 0;
      goto LABEL_154;
    }
    v141 = &a34;
    v97 = &STACK[0x2830];
    v98 = (char *)&STACK[0x2AB0];
    while ( sub_612EB0(&STACK[0x1E18]) )
    {
LABEL_74:
      if ( !sub_613DE0((char *)&STACK[0x2010], 512) )
        goto LABEL_75;
    }
    v136 = 0;
    v134 = "SEARCHPATH";
    if ( !sub_6137E0(&STACK[0x1E18]) )
    {
LABEL_72:
      v132 = v97;
      v131 = "MASfile";
      if ( sub_6137E0(&STACK[0x1E04]) )
      {
        sub_5EE940((int)v134, (char)v97, 0);
        v97 += 16;
        v141 = (int *)((char *)v141 + 1);
      }
      goto LABEL_74;
    }
    if ( strstr(v98, "<TEAMDIR>") )
    {
      v99 = a3;
      if ( !a3 )
        v99 = WindowName;
      sprintf((char *const)&STACK[0x1C8C], "%s", v99);
      v100 = strstr(v98, ">") + 1;
      if ( strlen(v100) )
      {
        v101 = a3;
        if ( !a3 )
          v101 = WindowName;
        sprintf((char *const)&STACK[0x1C8C], "%s%s", v101, v100);
        sprintf(v98, "%s", (const char *)&STACK[0x1C8C]);
        goto LABEL_71;
      }
      v102 = &STACK[0x1C8C];
    }
    else
    {
      if ( !strstr(v98, "<VEHDIR>") )
        goto LABEL_71;
      sprintf((char *const)&STACK[0x1C8C], "%s", (const char *)&STACK[0x2624]);
      v105 = strstr(v98, ">") + 1;
      v106 = strlen(v105);
      v96 = v106 == 0;
      vars0a = (void *)v106;
      v102 = &STACK[0x2624];
      if ( !v96 )
      {
        sprintf((char *const)&STACK[0x1C8C], "%s%s", (const char *)&STACK[0x2624], v105);
        sprintf(v98, "%s", (const char *)&STACK[0x1C8C]);
        goto LABEL_71;
      }
    }
    sprintf(v98, "%s", (const char *)v102);
LABEL_71:
    sub_5D9420(dword_FB1CE0, v98, 0, "SEARCHPATH");
    v141 = (int *)((char *)v141 + 1);
    v98 += 256;
    goto LABEL_72;
  }
}
