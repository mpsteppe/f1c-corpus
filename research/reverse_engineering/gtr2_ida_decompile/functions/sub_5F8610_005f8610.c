int __userpurge sub_5F8610@<eax>(
        int a1@<ecx>,
        int a2@<ebx>,
        char *a3@<edi>,
        int a4@<esi>,
        int *a5,
        int a6,
        int a7,
        int a8,
        int a9,
        void *a10,
        void *a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        char *a17,
        __int64 a18,
        int a19,
        int a20,
        char a21,
        int a22,
        int a23,
        int a24,
        int a25,
        char a26,
        int a27,
        int a28,
        __int64 a29,
        int a30,
        int a31,
        int a32,
        char a33,
        int a34,
        char a35,
        int a36,
        int a37,
        int a38,
        int a39,
        int a40,
        int a41,
        int a42,
        int a43,
        int a44,
        int a45,
        int a46,
        int a47,
        int a48,
        int a49,
        int a50,
        int a51,
        int a52,
        int a53,
        int a54,
        int a55,
        int a56,
        int a57,
        int a58,
        int a59,
        int a60,
        int a61,
        int a62,
        int a63)
{
  char a64; // [esp+1E88h] [ebp+FCh]
  int *v64; // ebx
  void **v65; // ecx
  void **v66; // edi
  void *v68; // eax
  void *v69; // eax
  bool v70; // zf
  unsigned __int16 (__thiscall **v71)(void **); // edx
  int v72; // esi
  int v73; // eax
  int *v74; // ebx
  int v75; // esi
  void *v76; // edi
  char *v77; // edi
  int v78; // eax
  int v79; // eax
  int *v80; // ebx
  int v81; // edx
  char *v82; // eax
  int v83; // edx
  char *v84; // eax
  int *v85; // esi
  int *v86; // ebx
  int v87; // edi
  const char *v88; // esi
  int *v89; // edi
  _DWORD *v90; // eax
  int v91; // edx
  int v92; // eax
  int v93; // eax
  bool v94; // cc
  int v95; // eax
  _DWORD *v96; // eax
  _DWORD *v97; // esi
  int v98; // edx
  char *v99; // eax
  _DWORD *v100; // esi
  _DWORD *v101; // ecx
  int v102; // edi
  const char *v103; // esi
  int v104; // ebx
  unsigned int v105; // edx
  int *v106; // edi
  int v107; // eax
  int v108; // esi
  int v109; // eax
  int v110; // eax
  int v111; // eax
  int v112; // eax
  int v113; // eax
  int v114; // eax
  unsigned int v115; // eax
  unsigned int v116; // eax
  char *v117; // [esp+1CF4h] [ebp-98h]
  unsigned int *v118; // [esp+1CF8h] [ebp-94h]
  char v119; // [esp+1D0Ah] [ebp-82h]
  char v120; // [esp+1D0Bh] [ebp-81h]
  void **v121; // [esp+1D0Ch] [ebp-80h]
  __int16 v122; // [esp+1D12h] [ebp-7Ah]
  void **v123; // [esp+1D14h] [ebp-78h]
  void *v124; // [esp+1D18h] [ebp-74h]
  char *v125; // [esp+1D20h] [ebp-6Ch]
  int v126; // [esp+1D24h] [ebp-68h]
  int *v127; // [esp+1D2Ch] [ebp-60h]
  void **v128; // [esp+1D30h] [ebp-5Ch]
  int v129; // [esp+1D34h] [ebp-58h]
  int v130; // [esp+1D34h] [ebp-58h]
  void **v131; // [esp+1D38h] [ebp-54h]
  _DWORD *v132; // [esp+1D38h] [ebp-54h]
  void *v133; // [esp+1D3Ch] [ebp-50h]
  char v134; // [esp+1D3Eh] [ebp-4Eh]
  int *v135; // [esp+1D40h] [ebp-4Ch]
  void *v136; // [esp+1D44h] [ebp-48h] BYREF
  int v137; // [esp+1D48h] [ebp-44h]
  char *v138; // [esp+1D4Ch] [ebp-40h]
  char *v139; // [esp+1D50h] [ebp-3Ch]
  void *v140; // [esp+1D54h] [ebp-38h]
  char *v141; // [esp+1D58h] [ebp-34h]
  char *v142; // [esp+1D5Ch] [ebp-30h]
  char *v143; // [esp+1D60h] [ebp-2Ch]
  char *v144; // [esp+1D64h] [ebp-28h]
  void *v145; // [esp+1D68h] [ebp-24h] BYREF
  char *v146; // [esp+1D6Ch] [ebp-20h]
  char *v147; // [esp+1D70h] [ebp-1Ch]
  int v148; // [esp+1D74h] [ebp-18h]
  _DWORD *v149; // [esp+1D78h] [ebp-14h] BYREF
  int v150; // [esp+1D7Ch] [ebp-10h]
  int v151; // [esp+1D80h] [ebp-Ch]
  int v152; // [esp+1D84h] [ebp-8h]
  int v153; // [esp+1D88h] [ebp-4h]
  int vars0; // [esp+1D8Ch] [ebp+0h] BYREF
  _UNKNOWN *retaddr; // [esp+1D90h] [ebp+4h]

  v150 = a1;
  sub_631BD0();
  v149 = (_DWORD *)a2;
  v64 = a5;
  v148 = a4;
  v147 = a3;
  v66 = v65;
  v153 = (int)v65;
  a15 = 0;
  a25 = 0;
  BYTE2(v152) = 0;
  while ( sub_5DF750(v64) != 3 )
  {
    if ( *v64 == 3 )
      break;
    if ( *v64 != 2 )
    {
      v146 = 0;
      v145 = 0;
      v144 = 0;
      v143 = 0;
      v142 = 0;
      v141 = 0;
      v140 = 0;
      v139 = (char *)&STACK[0x22C8];
      v138 = "SHADERNAME";
      LOBYTE(STACK[0x22C8]) = 0;
      LOBYTE(STACK[0x2088]) = 0;
      LOBYTE(STACK[0x2048]) = 0;
      a26 = 1;
      if ( sub_5DF240((int)v64, v138, v139, (char *)v140, v141, v142, v143, v144, (char *)v145, v146) )
      {
        a16 = 0;
        a9 = 0;
        a11 = 0;
        a8 = 1;
        HIBYTE(v152) = 1;
        if ( sub_5DF750(v64) != 1 )
        {
          do
          {
            if ( *v64 == 3 )
              break;
            if ( *v64 != 2 )
            {
              sub_5DF060(v64, "SHADERDESC", (char *)&STACK[0x3718]);
              sub_5DF060(v64, "SHADERLONGDESC", (char *)&STACK[0x3918]);
              sub_5DF240((int)v64, "SHADERDOWNGRADE", (char *)&STACK[0x2088], 0, 0, 0, 0, 0, 0, 0);
              sub_5DF240((int)v64, "SHADERUPGRADE", (char *)&STACK[0x2048], 0, 0, 0, 0, 0, 0, 0);
              if ( sub_5DF240((int)v64, "SHADERPUBLIC", (char *)&STACK[0x2508], 0, 0, 0, 0, 0, 0, 0)
                && _stricmp((const char *)&STACK[0x2508], "TRUE") )
              {
                a26 = 0;
              }
              if ( sub_5DF580(v64, "SHADERLEVEL", &a25, 0, 0, 0) )
              {
                a15 = 0;
                HIWORD(v150) = 257;
                strcpy((char *)&a29, "ps_1_1");
                switch ( a25 )
                {
                  case 0:
                    strcpy((char *)&a18, "vs_1_1");
                    a8 = 1;
                    strcpy(&a21, "NULL");
                    goto LABEL_29;
                  case 1:
                    strcpy((char *)&a18, "vs_1_1");
                    a8 = 2;
                    strcpy(&a21, "ps_1_2");
                    goto LABEL_24;
                  case 2:
                    v68 = v66[27];
                    strcpy((char *)&a18, "vs_2_0");
                    a8 = 3;
                    strcpy(&a21, "ps_2_0");
                    if ( v68 == (void *)1 || v68 == (void *)2 )
                      HIBYTE(v150) = 0;
                    v69 = v66[28];
                    if ( v69 == (void *)256 )
                      goto LABEL_28;
                    v70 = v69 == (void *)512;
LABEL_27:
                    if ( v70 )
LABEL_28:
                      BYTE2(v150) = 0;
LABEL_29:
                    if ( sub_5DF750(v64) == 1 )
                      continue;
                    break;
                  case 3:
                    strcpy((char *)&a18, "vs_1_1");
                    strcpy(&a21, "ps_1_4");
                    v71 = (unsigned __int16 (__thiscall **)(void **))*v66;
                    a8 = 2;
                    v72 = (unsigned __int8)(v71[144](v66) >> 8);
                    v73 = (*((unsigned __int8 (__thiscall **)(void **))*v66 + 144))(v66);
                    if ( v72 <= 1 && v73 < 4 )
                      HIWORD(v150) = 0;
LABEL_24:
                    if ( v66[27] == (void *)1 )
                      HIBYTE(v150) = 0;
                    v70 = v66[28] == (void *)256;
                    goto LABEL_27;
                  default:
                    goto LABEL_29;
                }
                while ( *v64 != 3 )
                {
                  if ( *v64 != 2 && sub_5DF580(v64, "PASS", &a15, 0, 0, 0) )
                  {
                    LOBYTE(retaddr) = 1;
                    HIBYTE(vars0) = 0;
                    v151 = 0;
                    LOBYTE(STACK[0x1FC8]) = 0;
                    a64 = 0;
                    if ( sub_5DF750(v64) != 1 )
                    {
                      do
                      {
                        if ( *v64 == 3 )
                          break;
                        if ( *v64 != 2 )
                        {
                          v74 = a5;
                          if ( sub_5DF240((int)a5, "CONDITIONAL", (char *)&STACK[0x2508], 0, 0, 0, 0, 0, 0, 0)
                            && !_stricmp((const char *)&STACK[0x2508], "TRUE") )
                          {
                            HIBYTE(vars0) = 1;
                          }
                          if ( sub_5DF060(v74, "VERTEXSHADER", (char *)&STACK[0x1FC8]) )
                          {
                            v75 = 0;
                            STACK[0x2F10] = 0;
                            memset(&STACK[0x2F14], 0, 0x400u);
                            memset(&STACK[0x3314], 0, 0x400u);
                            v76 = 0;
                            a5 = 0;
                            LOBYTE(STACK[0x2008]) = 0;
                            LOBYTE(STACK[0x1F48]) = 0;
                            LOBYTE(STACK[0x2488]) = 0;
                            STACK[0x20C8] = 1329811278;
                            STACK[0x20CC] = 5526350;
                            a6 = 0;
                            if ( sub_5DF750(v74) != 1 )
                            {
                              while ( *v74 != 3 )
                              {
                                if ( *v74 != 2 )
                                {
                                  if ( sub_5DF240((int)v74, "FILE", (char *)&STACK[0x2008], 0, 0, 0, 0, 0, 0, 0) )
                                  {
                                    if ( !_stricmp((const char *)&STACK[0x2008], off_72D0FC) )
                                    {
                                      v75 = 1;
                                    }
                                    else if ( !_stricmp((const char *)&STACK[0x2008], "hlsl") )
                                    {
                                      v75 = 2;
                                    }
                                    else
                                    {
                                      v77 = (char *)v153;
                                      v78 = sub_5E0740((void *)(v153 + 4), (const char *)&STACK[0x2008], 0);
                                      v151 = v78;
                                      if ( !v78 )
                                      {
                                        v146 = (char *)&STACK[0x2008];
                                        v145 = "Error opening vertex shader file %s";
                                        goto LABEL_266;
                                      }
                                      v76 = *(void **)v78;
                                      a14 = *(_DWORD *)(v78 + 8);
                                    }
                                    LOBYTE(retaddr) = 0;
                                  }
                                  if ( sub_5DF240((int)v74, "LANGUAGE", (char *)&STACK[0x2508], 0, 0, 0, 0, 0, 0, 0) )
                                  {
                                    if ( !_stricmp((const char *)&STACK[0x2508], off_72D0E4) )
                                    {
                                      v75 = 1;
                                    }
                                    else if ( !_stricmp((const char *)&STACK[0x2508], "HLSL") )
                                    {
                                      v75 = 2;
                                    }
                                  }
                                  sub_5DF240((int)v74, "DESC", (char *)&STACK[0x1F48], 0, 0, 0, 0, 0, 0, 0);
                                  sub_5DF240((int)v74, "VERTEXDECL", (char *)&STACK[0x2488], 0, 0, 0, 0, 0, 0, 0);
                                  if ( sub_5DF240(
                                         (int)v74,
                                         "DEFINE",
                                         (char *)&STACK[0x2F14] + 32 * STACK[0x2F10],
                                         (char *)&STACK[0x3314] + 32 * STACK[0x2F10],
                                         0,
                                         0,
                                         0,
                                         0,
                                         0,
                                         0) )
                                  {
                                    ++STACK[0x2F10];
                                  }
                                  v79 = sub_5DF240(
                                          (int)v74,
                                          "SHADERCONSTANTS",
                                          (char *)&STACK[0x20C8],
                                          (char *)&STACK[0x2108],
                                          (char *)&STACK[0x2148],
                                          (char *)&STACK[0x2188],
                                          (char *)&STACK[0x21C8],
                                          (char *)&STACK[0x2208],
                                          (char *)&STACK[0x2248],
                                          (char *)&STACK[0x2288]);
                                  if ( a6 <= v79 )
                                    a6 = sub_5DF240(
                                           (int)v74,
                                           "SHADERCONSTANTS",
                                           (char *)&STACK[0x20C8],
                                           (char *)&STACK[0x2108],
                                           (char *)&STACK[0x2148],
                                           (char *)&STACK[0x2188],
                                           (char *)&STACK[0x21C8],
                                           (char *)&STACK[0x2208],
                                           (char *)&STACK[0x2248],
                                           (char *)&STACK[0x2288]);
                                }
                                if ( sub_5DF750(v74) == 1 )
                                  break;
                              }
                            }
                            if ( HIBYTE(v150) )
                            {
                              sub_5F79C0((_DWORD *)(v153 + 9140), (const char *)&STACK[0x1FC8], &a16);
                              if ( !a16 )
                              {
                                v80 = (int *)v153;
                                v81 = *(_DWORD *)v153;
                                v146 = (char *)&a28;
                                v145 = &STACK[0x2488];
                                v82 = (char *)(*(int (__thiscall **)(int))(v81 + 648))(v153);
                                if ( v76 )
                                {
                                  v83 = *v80;
                                  LOBYTE(v82) = v75 == 1;
                                  v144 = v82;
                                  v143 = (char *)v153;
                                  v142 = (char *)&vars0;
                                  v141 = 0;
                                  v140 = &a16;
                                  v139 = (char *)&STACK[0x1FC0];
                                  v138 = (char *)&STACK[0x2F08];
                                  v137 = a12;
                                  v136 = v76;
                                  if ( (*(int (__thiscall **)(int *))(v83 + 604))(v80) )
                                  {
                                    sub_5D8C80(
                                      (int)(v80 + 1),
                                      (char *)0xFFFFFFFF,
                                      "Fatal error compiling vertex shader %s.  Please compile offline for more info.",
                                      (char)&STACK[0x1FDC]);
                                    return -1;
                                  }
                                  if ( v140 )
                                  {
                                    sub_5DF6E0((void **)v140);
                                    v140 = 0;
                                  }
                                }
                                v84 = (char *)operator new(0x180u);
                                a17 = v84;
                                STACK[0x3AF8] = 0;
                                if ( v84 )
                                {
                                  v85 = (int *)(v84 + 4);
                                  *(_DWORD *)v84 = 1;
                                  sub_630A11(v84 + 4, 380, 1, sub_5F8040, sub_5F77C0);
                                  v86 = v85;
                                }
                                else
                                {
                                  v86 = 0;
                                }
                                v132 = v145;
                                v129 = a18;
                                STACK[0x3AF8] = -1;
                                a5 = v86;
                                if ( sub_5F6E80(
                                       v86,
                                       (const char *)&STACK[0x1F1C],
                                       (const char *)&STACK[0x1F9C],
                                       v129,
                                       v132,
                                       0,
                                       3) )
                                {
                                  return -1;
                                }
                                v87 = 0;
                                if ( (int)v146 > 0 )
                                {
                                  v88 = (const char *)&STACK[0x209C];
                                  v147 = v146;
                                  do
                                  {
                                    _stricmp(v88, "NONE");
                                    if ( !_stricmp(v88, "VIEWPROJ") )
                                      v87 |= 1u;
                                    if ( !_stricmp(v88, "WORLD") )
                                      v87 |= 2u;
                                    if ( !_stricmp(v88, "MATLIGHT") )
                                      v87 |= 4u;
                                    if ( !_stricmp(v88, "DEFAULT") )
                                      v87 |= 7u;
                                    if ( !_stricmp(v88, "SHADOWPROJECT") )
                                      v87 |= 8u;
                                    if ( !_stricmp(v88, "SHADOWDRAW") )
                                      v87 |= 0x200u;
                                    if ( !_stricmp(v88, "FOG") )
                                      v87 |= 0x10u;
                                    if ( !_stricmp(v88, "OMNILIGHT") )
                                      v87 |= 0x20u;
                                    if ( !_stricmp(v88, "SPOTLIGHT") )
                                      v87 |= 0x40u;
                                    if ( !_stricmp(v88, "BONES") )
                                      v87 |= 0x80u;
                                    if ( !_stricmp(v88, "BUMPMAP") )
                                      v87 |= 0x100u;
                                    if ( !_stricmp(v88, "USERDEFINED") )
                                      v87 |= 0x1000u;
                                    v88 += 64;
                                    --v147;
                                  }
                                  while ( v147 );
                                }
                                if ( HIBYTE(v143) )
                                  v87 |= 0x80000000;
                                v86[84] = v148;
                                sub_5F6390(v86, v87, 0);
                                sub_5FDFB0(v86, 0);
                                v74 = a5;
                              }
                            }
                            if ( v140 )
                            {
                              sub_5DF6E0((void **)v140);
                              v140 = 0;
                            }
                          }
                          if ( sub_5DF060(v74, "PIXELSHADER", (char *)&a53) )
                          {
                            STACK[0x26DC] = 0;
                            memset(&STACK[0x26E0], 0, 0x400u);
                            memset(&STACK[0x2AE0], 0, 0x400u);
                            LOBYTE(STACK[0x1F5C]) = 0;
                            LOBYTE(STACK[0x1F1C]) = 0;
                            STACK[0x20A0] = 5526350;
                            STACK[0x209C] = 1329811278;
                            memset(&a22, 4u, 0x40u);
                            v89 = a5;
                            v147 = 0;
                            v145 = 0;
                            v146 = 0;
                            v152 = 0;
                            BYTE2(v143) = 0;
                            v153 = 0;
                            v150 = 0;
                            if ( sub_5DF750(a5) != 1 )
                            {
                              v74 = 0;
                              while ( *v89 != 3 )
                              {
                                if ( *v89 != 2 )
                                {
                                  if ( sub_5DF240((int)v89, "FILE", (char *)&STACK[0x1F5C], 0, 0, 0, 0, 0, 0, 0) )
                                  {
                                    if ( !_stricmp((const char *)&STACK[0x1F5C], off_72D0FC) )
                                    {
                                      v152 = 1;
                                    }
                                    else if ( !_stricmp((const char *)&STACK[0x1F5C], "hlsl") )
                                    {
                                      v152 = 2;
                                    }
                                    else
                                    {
                                      v90 = (_DWORD *)sub_5E0740(v142 + 4, (const char *)&STACK[0x1F5C], 0);
                                      v140 = v90;
                                      if ( !v90 )
                                      {
                                        sub_5D8C80(
                                          (int)(v142 + 4),
                                          (char *)0xFFFFFFFF,
                                          "Error opening pixel shader file %s",
                                          (char)&STACK[0x1F5C]);
                                        return -1;
                                      }
                                      v91 = v90[2];
                                      v147 = (char *)*v90;
                                      vars0 = v91;
                                    }
                                    LOBYTE(v144) = 0;
                                  }
                                  if ( sub_5DF240((int)v89, "ALTPROFILE", (char *)&STACK[0x24DC], 0, 0, 0, 0, 0, 0, 0)
                                    && !_stricmp((const char *)&STACK[0x24DC], "TRUE") )
                                  {
                                    BYTE2(v143) = 1;
                                  }
                                  if ( sub_5DF240((int)v89, "LANGUAGE", (char *)&STACK[0x24DC], 0, 0, 0, 0, 0, 0, 0) )
                                  {
                                    if ( !_stricmp((const char *)&STACK[0x24DC], off_72D0E4) )
                                    {
                                      v152 = 1;
                                    }
                                    else if ( !_stricmp((const char *)&STACK[0x24DC], "HLSL") )
                                    {
                                      v152 = 2;
                                    }
                                  }
                                  sub_5DF240((int)v89, "DESC", (char *)&STACK[0x1F1C], 0, 0, 0, 0, 0, 0, 0);
                                  if ( sub_5DF240(
                                         (int)v89,
                                         "DEFINE",
                                         (char *)&STACK[0x26E0] + 32 * STACK[0x26DC],
                                         (char *)&STACK[0x2AE0] + 32 * STACK[0x26DC],
                                         0,
                                         0,
                                         0,
                                         0,
                                         0,
                                         0) )
                                  {
                                    ++STACK[0x26DC];
                                  }
                                  v92 = sub_5DF240(
                                          (int)v89,
                                          "SHADERCONSTANTS",
                                          (char *)&STACK[0x209C],
                                          (char *)&STACK[0x20DC],
                                          (char *)&STACK[0x211C],
                                          (char *)&STACK[0x215C],
                                          (char *)&STACK[0x219C],
                                          (char *)&STACK[0x21DC],
                                          (char *)&STACK[0x221C],
                                          (char *)&STACK[0x225C]);
                                  if ( (int)v146 <= v92 )
                                    v146 = (char *)sub_5DF240(
                                                     (int)v89,
                                                     "SHADERCONSTANTS",
                                                     (char *)&STACK[0x209C],
                                                     (char *)&STACK[0x20DC],
                                                     (char *)&STACK[0x211C],
                                                     (char *)&STACK[0x215C],
                                                     (char *)&STACK[0x219C],
                                                     (char *)&STACK[0x21DC],
                                                     (char *)&STACK[0x221C],
                                                     (char *)&STACK[0x225C]);
                                  if ( sub_5DF3F0(
                                         v89,
                                         "STAGESTATE",
                                         &a6,
                                         (char *)&STACK[0x1EDC],
                                         (char *)&STACK[0x1E9C],
                                         0,
                                         0,
                                         0,
                                         0,
                                         0,
                                         0) )
                                  {
                                    v93 = a6;
                                    v94 = v153 <= a6;
                                    STACK[0x249C] = a6;
                                    if ( v94 )
                                      v153 = v93;
                                    if ( !_stricmp((const char *)&STACK[0x1EDC], "DIFFUSEMAP") )
                                    {
                                      a37 = 1;
                                    }
                                    else if ( !_stricmp((const char *)&STACK[0x1EDC], "SPECULARMAP") )
                                    {
                                      a37 = 2;
                                    }
                                    else if ( !_stricmp((const char *)&STACK[0x1EDC], "OPACITYMAP") )
                                    {
                                      a37 = 3;
                                    }
                                    else if ( !_stricmp((const char *)&STACK[0x1EDC], "BUMPMAP") )
                                    {
                                      a37 = 5;
                                    }
                                    else if ( !_stricmp((const char *)&STACK[0x1EDC], "SPECULARPOWERMAP") )
                                    {
                                      a37 = 9;
                                    }
                                    else if ( !_stricmp((const char *)&STACK[0x1EDC], "SPHEREMAP") )
                                    {
                                      a37 = 10;
                                    }
                                    else if ( !_stricmp((const char *)&STACK[0x1EDC], "NORMALIZER") )
                                    {
                                      a37 = 14;
                                    }
                                    else if ( !_stricmp((const char *)&STACK[0x1EDC], "COMPUTATIONAL") )
                                    {
                                      a37 = 15;
                                    }
                                    else if ( !_stricmp((const char *)&STACK[0x1EDC], "MATH") )
                                    {
                                      a37 = 15;
                                    }
                                    else if ( !_stricmp((const char *)&STACK[0x1EDC], "CUBEMAP") )
                                    {
                                      a37 = 11;
                                      v150 = 0;
                                      BYTE2(v141) = 1;
                                    }
                                    return off_16C9500(a5);
                                  }
                                  if ( sub_5DF3F0(
                                         v89,
                                         "SAMPLERSTATE",
                                         &a6,
                                         (char *)&STACK[0x235C],
                                         (char *)&STACK[0x231C],
                                         (char *)&STACK[0x23DC],
                                         0,
                                         0,
                                         0,
                                         0,
                                         0) )
                                  {
                                    v95 = a6;
                                    v94 = v153 <= a6;
                                    *(unsigned int *)((char *)&STACK[0x249C] + (_DWORD)v74) = a6;
                                    if ( v94 )
                                      v153 = v95;
                                    if ( !_stricmp((const char *)&STACK[0x235C], "WRAP") )
                                    {
                                      *(unsigned int *)((char *)&STACK[0x241C] + (_DWORD)v74) = 0;
                                    }
                                    else if ( !_stricmp((const char *)&STACK[0x235C], "CLAMP") )
                                    {
                                      *(unsigned int *)((char *)&STACK[0x241C] + (_DWORD)v74) = 1;
                                    }
                                    else
                                    {
                                      *(unsigned int *)((char *)&STACK[0x241C] + (_DWORD)v74) = _stricmp(
                                                                                                  (const char *)&STACK[0x235C],
                                                                                                  "MIRROR") != 0
                                                                                              ? -1
                                                                                              : 2;
                                    }
                                    if ( !_stricmp((const char *)&STACK[0x231C], "WRAP") )
                                    {
                                      *(unsigned int *)((char *)&STACK[0x239C] + (_DWORD)v74) = 0;
                                    }
                                    else if ( !_stricmp((const char *)&STACK[0x231C], "CLAMP") )
                                    {
                                      *(unsigned int *)((char *)&STACK[0x239C] + (_DWORD)v74) = 1;
                                    }
                                    else
                                    {
                                      *(unsigned int *)((char *)&STACK[0x239C] + (_DWORD)v74) = _stricmp(
                                                                                                  (const char *)&STACK[0x231C],
                                                                                                  "MIRROR") != 0
                                                                                              ? -1
                                                                                              : 2;
                                    }
                                    if ( !_stricmp((const char *)&STACK[0x23DC], "WRAP") )
                                    {
                                      *(unsigned int *)((char *)&STACK[0x22DC] + (_DWORD)v74) = 0;
                                    }
                                    else if ( !_stricmp((const char *)&STACK[0x23DC], "CLAMP") )
                                    {
                                      *(unsigned int *)((char *)&STACK[0x22DC] + (_DWORD)v74) = 1;
                                    }
                                    else
                                    {
                                      *(unsigned int *)((char *)&STACK[0x22DC] + (_DWORD)v74) = _stricmp(
                                                                                                  (const char *)&STACK[0x23DC],
                                                                                                  "MIRROR") != 0
                                                                                              ? -1
                                                                                              : 2;
                                    }
                                    ++v74;
                                  }
                                }
                                if ( sub_5DF750(v89) == 1 )
                                  break;
                              }
                            }
                            if ( BYTE2(v139) )
                            {
                              a17 = v142 + 9140;
                              sub_5F7A70((_DWORD *)v142 + 2285, (const char *)&a53, (int *)&v149);
                              if ( !v149 )
                              {
                                if ( v147 )
                                {
                                  v77 = v142;
                                  LOBYTE(v74) = v152 == 1;
                                  v135 = v74;
                                  v134 = BYTE2(v144);
                                  v131 = &v145;
                                  v130 = 0;
                                  v128 = &a11;
                                  v127 = &a53;
                                  v126 = vars0;
                                  v125 = v147;
                                  if ( (*(int (__thiscall **)(char *))(*(_DWORD *)v142 + 604))(v142) )
                                  {
                                    if ( &a11 )
                                      sub_5DF6E0(&a11);
LABEL_265:
                                    v117 = "Fatal error compiling pixel shader %s.  Please compile offline for more info.";
LABEL_266:
                                    sub_5D8C80((int)(v77 + 4), (char *)0xFFFFFFFF, v117, (char)v118);
                                    return -1;
                                  }
                                  v96 = operator new(0x194u);
                                  v140 = v96;
                                  STACK[0x3AD4] = 1;
                                  if ( v96 )
                                  {
                                    *v96 = 1;
                                    v97 = v96 + 1;
                                    sub_630A11(v96 + 1, 400, 1, sub_5F76A0, sub_5F77C0);
                                  }
                                  else
                                  {
                                    v97 = 0;
                                  }
                                  v124 = v136;
                                  STACK[0x3AD4] = -1;
                                  v140 = v97;
                                  if ( sub_5F7730(v97, (const char *)&STACK[0x1EF8], (const char *)&a44, v124, 3) )
                                  {
                                    if ( !v134 )
                                      goto LABEL_267;
                                    strcpy((char *)&STACK[0x26BC] + 32 * STACK[0x26B8], "ALTPROFILE");
                                    v98 = *(_DWORD *)v77;
                                    *((_WORD *)&STACK[0x2ABC] + 16 * STACK[0x26B8]++) = 49;
                                    v123 = &v136;
                                    v122 = 0;
                                    v121 = &a10;
                                    if ( (*(int (__thiscall **)(char *, char *, void *, unsigned int *, int *))(v98 + 604))(
                                           v77,
                                           v138,
                                           v145,
                                           &STACK[0x26B8],
                                           &a44) )
                                    {
                                      if ( &a10 )
                                        sub_5DF6E0(&a10);
                                      v118 = &STACK[0x1F14];
                                      goto LABEL_265;
                                    }
                                    if ( sub_5F7730(v97, (const char *)&STACK[0x1ED4], &a35, v125, 3) )
                                    {
LABEL_267:
                                      if ( v121 )
                                        sub_5DF6E0(v121);
                                      return -1;
                                    }
                                  }
                                  if ( v121 )
                                  {
                                    sub_5DF6E0(v121);
                                    v121 = 0;
                                  }
                                }
                                else
                                {
                                  v99 = (char *)operator new(0x194u);
                                  v147 = v99;
                                  STACK[0x3AF8] = 2;
                                  if ( v99 )
                                  {
                                    v100 = v99 + 4;
                                    *(_DWORD *)v99 = 1;
                                    sub_630A11(v99 + 4, 400, 1, sub_5F76A0, sub_5F77C0);
                                    v101 = v100;
                                  }
                                  else
                                  {
                                    v101 = 0;
                                  }
                                  v133 = v145;
                                  STACK[0x3AF8] = -1;
                                  v149 = v101;
                                  if ( sub_5F7730(v101, (const char *)&STACK[0x1F1C], (const char *)&a53, v133, 3) )
                                  {
                                    if ( v140 )
                                      sub_5DF6E0((void **)v140);
                                    return -1;
                                  }
                                }
                                v102 = 0;
                                if ( v126 > 0 )
                                {
                                  v103 = (const char *)&STACK[0x2054];
                                  v104 = v126;
                                  do
                                  {
                                    if ( _stricmp(v103, "NONE") )
                                    {
                                      if ( !_stricmp(v103, "LIGHTING") )
                                      {
                                        v102 |= 0x10000u;
                                      }
                                      else if ( !_stricmp(v103, "CUBEMAPBLEND") )
                                      {
                                        v102 |= 0x20000u;
                                      }
                                      else if ( !_stricmp(v103, "SHADOWPROJECT") )
                                      {
                                        v102 |= 0x40000u;
                                      }
                                      else if ( !_stricmp(v103, "SPECPOWER") )
                                      {
                                        v102 |= 0x80000u;
                                      }
                                    }
                                    v103 += 64;
                                    --v104;
                                  }
                                  while ( v104 );
                                }
                                v128[84] = v127;
                                sub_5F6540(v128, v102, v130, 0, 0);
                                sub_5F84A0((int *)v128, (int)v135 + 1);
                                v105 = 0;
                                if ( (int)v128[85] > 0 )
                                {
                                  v106 = (int *)(v128 + 86);
                                  do
                                  {
                                    if ( v105 >= 8 )
                                      v107 = 0;
                                    else
                                      v107 = *v106;
                                    v108 = *(&a20 + v105);
                                    *(_DWORD *)(v107 + 240) = v108;
                                    if ( v105 >= 8 )
                                      v109 = 0;
                                    else
                                      v109 = *v106;
                                    *(_DWORD *)(v109 + 244) = (&a5)[v105];
                                    if ( v105 >= 8 )
                                      v110 = 0;
                                    else
                                      v110 = *v106;
                                    *(_DWORD *)(v110 + 216) = *(&STACK[0x23D4] + v105);
                                    if ( v105 >= 8 )
                                      v111 = 0;
                                    else
                                      v111 = *v106;
                                    *(_DWORD *)(v111 + 220) = *(&STACK[0x2354] + v105);
                                    if ( v105 >= 8 )
                                      v112 = 0;
                                    else
                                      v112 = *v106;
                                    *(_DWORD *)(v112 + 224) = *(&STACK[0x2294] + v105);
                                    if ( (_BYTE)v122 && v130 == v105 )
                                      *(_BYTE *)(sub_5F6520(v128, v105) + 238) = 1;
                                    if ( v108 == 14 || v108 == 9 )
                                    {
                                      if ( v105 >= 8 )
                                        v113 = 0;
                                      else
                                        v113 = *v106;
                                      *(_BYTE *)(v113 + 236) = 0;
                                    }
                                    ++v105;
                                    ++v106;
                                  }
                                  while ( (int)v105 < (int)v128[85] );
                                }
                              }
                            }
                            if ( v121 )
                            {
                              sub_5DF6E0(v121);
                              v121 = 0;
                            }
                          }
                        }
                        v114 = sub_5DF750(a5);
                        v66 = v123;
                        v64 = a5;
                      }
                      while ( v114 != 1 );
                    }
                    if ( v120 && v119 )
                    {
                      if ( v137 )
                      {
                        if ( (_stricmp((const char *)&STACK[0x1F54], WindowName) || _stricmp(&a35, WindowName))
                          && !HIBYTE(v122)
                          && (*((int (__thiscall **)(void **, void **, int, unsigned int *, char *))*v66 + 155))(
                               v66,
                               v131,
                               v137,
                               &STACK[0x1F54],
                               &a35) )
                        {
                          return -1;
                        }
                      }
                      else
                      {
                        HIBYTE(v122) = 1;
                        if ( !(*(int (__thiscall **)(int, unsigned int *, int *))(*(_DWORD *)dword_FB27A4 + 632))(
                                dword_FB27A4,
                                &STACK[0x2254],
                                v127) )
                        {
                          v120 = 0;
                          v123 = (void **)(*((int (__thiscall **)(void **, unsigned int *, int *, unsigned int *, unsigned int *, char *, unsigned int *, char *))*v66
                                           + 154))(
                                            v66,
                                            &STACK[0x224C],
                                            v127,
                                            &STACK[0x369C],
                                            &STACK[0x1F4C],
                                            &a33,
                                            &STACK[0x389C],
                                            v147);
                          if ( !v123 )
                            return -1;
                        }
                      }
                    }
                  }
                  if ( sub_5DF750(v64) == 1 )
                    break;
                }
              }
            }
          }
          while ( sub_5DF750(v64) != 1 );
          if ( v123 )
          {
            if ( _stricmp((const char *)&STACK[0x1FF0], WindowName) )
            {
              sub_630FE0(v123 + 143);
              if ( (int)strlen((const char *)&STACK[0x1FF0]) <= 63 )
                v115 = strlen((const char *)&STACK[0x1FF0]);
              else
                v115 = 63;
              *((_BYTE *)v123 + v115 + 572) = 0;
            }
            if ( _stricmp((const char *)&STACK[0x1FB0], WindowName) )
            {
              sub_630FE0(v123 + 159);
              if ( (int)strlen((const char *)&STACK[0x1FB0]) <= 63 )
                v116 = strlen((const char *)&STACK[0x1FB0]);
              else
                v116 = 63;
              *((_BYTE *)v123 + v116 + 636) = 0;
            }
          }
        }
      }
    }
  }
  return 0;
}
