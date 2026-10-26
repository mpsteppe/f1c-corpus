int __userpurge sub_40E950@<eax>(
        char a1@<cl>,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        char String2,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        int a29,
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
        char a59)
{
  float *v59; // ecx
  float *v60; // esi
  _DWORD *v61; // edi
  unsigned int *v62; // ebx
  void (__thiscall ***v63)(_DWORD); // ecx
  void (__thiscall **v64)(_DWORD); // edx
  void (__thiscall *v65)(void *); // eax
  int v66; // eax
  void (__thiscall ***v67)(_DWORD); // ecx
  void (__thiscall **v68)(_DWORD); // edx
  void *v69; // eax
  int v70; // eax
  void (__thiscall ***v71)(_DWORD); // ecx
  void (__thiscall **v72)(_DWORD); // edx
  void *v73; // eax
  int v74; // eax
  void (__thiscall ***v75)(_DWORD); // ecx
  void (__thiscall **v76)(_DWORD); // edx
  void *v77; // eax
  int v78; // eax
  void (__thiscall ***v79)(_DWORD); // ecx
  void (__thiscall **v80)(_DWORD); // edx
  int v81; // ebx
  unsigned int *v82; // eax
  int v83; // edi
  double v84; // st7
  int v85; // ecx
  int v86; // ecx
  int v87; // eax
  int v88; // ecx
  int v89; // ecx
  int v90; // eax
  int v91; // ecx
  void (__thiscall *v92)(void *); // ecx
  int v93; // eax
  int v94; // ecx
  int v95; // eax
  int v96; // ecx
  int v97; // ebx
  int v98; // edi
  int v99; // ecx
  int v100; // eax
  _DWORD *v101; // ecx
  int v102; // ecx
  float v103; // ecx
  int v104; // eax
  float v105; // ecx
  int v106; // eax
  float v107; // ecx
  int v108; // eax
  int v109; // esi
  float v111; // [esp+21D8h] [ebp-74h] BYREF
  float v112; // [esp+21DCh] [ebp-70h]
  float v113; // [esp+21E0h] [ebp-6Ch]
  float v114; // [esp+21E4h] [ebp-68h]
  float v115; // [esp+21E8h] [ebp-64h]
  float v116; // [esp+21ECh] [ebp-60h] BYREF
  float v117; // [esp+21F0h] [ebp-5Ch]
  _DWORD *v118; // [esp+21F4h] [ebp-58h] BYREF
  float v119; // [esp+21F8h] [ebp-54h]
  int v120; // [esp+21FCh] [ebp-50h] BYREF
  float v121; // [esp+2200h] [ebp-4Ch]
  void (__thiscall *v122)(void *); // [esp+2204h] [ebp-48h] BYREF
  float v123; // [esp+2208h] [ebp-44h]
  int v124; // [esp+220Ch] [ebp-40h] BYREF
  int v125; // [esp+2210h] [ebp-3Ch]
  int v126; // [esp+2214h] [ebp-38h] BYREF
  int v127; // [esp+2218h] [ebp-34h] BYREF
  unsigned int *v128; // [esp+221Ch] [ebp-30h] BYREF
  int p_String2; // [esp+2220h] [ebp-2Ch]
  unsigned int v130; // [esp+2224h] [ebp-28h]
  int v131; // [esp+2228h] [ebp-24h]
  int v132; // [esp+222Ch] [ebp-20h]
  _DWORD v133[2]; // [esp+2234h] [ebp-18h] BYREF
  char v134[4]; // [esp+223Ch] [ebp-10h] BYREF
  int v135; // [esp+2240h] [ebp-Ch]
  char v136[4]; // [esp+2248h] [ebp-4h] BYREF

  sub_631BD0(a1);
  v60 = v59;
  if ( !a2 )
    return 1;
  sub_613B30(v136);
  memset(&STACK[0x2900], 0, 0x200u);
  v61 = 0;
  STACK[0x448C] = 0;
  STACK[0x28E8] = 0;
  STACK[0x28FC] = 0;
  STACK[0x28F4] = 0;
  STACK[0x28F8] = 0;
  LOBYTE(STACK[0x28EC]) = 1;
  sub_46D4A0(&STACK[0x2618]);
  LOBYTE(STACK[0x448C]) = 1;
  sub_46D4A0(&STACK[0x2548]);
  LOBYTE(STACK[0x448C]) = 2;
  sub_46D4A0(&STACK[0x23A8]);
  LOBYTE(STACK[0x448C]) = 3;
  sub_46D4A0(&STACK[0x2478]);
  v132 = (int)sub_46B2D0;
  v131 = (int)sub_46D4A0;
  v130 = 32;
  p_String2 = 204;
  v128 = &STACK[0x2B00];
  LOBYTE(STACK[0x448C]) = 4;
  sub_630A11(v128, p_String2, v130, v131, v132);
  v132 = 1;
  v131 = a2;
  LOBYTE(STACK[0x448C]) = 5;
  v135 = 0;
  if ( (unsigned __int8)sub_614460(v131, v132) )
  {
    if ( sub_613DE0((char *)&STACK[0x2900], 512) )
    {
      v62 = &STACK[0x2B00];
      do
      {
        if ( !sub_612EB0(&STACK[0x26E8]) )
        {
          v132 = 0;
          v131 = (int)&a23;
          v130 = (unsigned int)"LOCALCAM";
          if ( sub_6137E0(&STACK[0x26E8]) )
          {
            if ( !_stricmp(aSwingman, &String2) )
            {
              p_String2 = (int)&String2;
              sub_46D560(&STACK[0x246C], v134);
            }
            else if ( !_stricmp(aCockpit, &String2) )
            {
              p_String2 = (int)&String2;
              sub_46D560(&STACK[0x253C], v134);
            }
            else if ( !_stricmp(aTvcockpit, &String2) )
            {
              p_String2 = (int)&String2;
              sub_46D560(&STACK[0x239C], v134);
            }
            else if ( !_stricmp(aNosecam, &String2) )
            {
              p_String2 = (int)&String2;
              sub_46D560(&STACK[0x260C], v134);
            }
            else if ( v133[0] < 32 )
            {
              p_String2 = (int)&String2;
              sub_46D560(v62, v134);
              ++v132;
              v62 += 51;
            }
          }
        }
      }
      while ( sub_613DE0((char *)&STACK[0x28EC], 512) );
    }
    if ( !v133[1] )
    {
      *(float *)&v127 = COERCE_FLOAT(sub_46B2D0);
      v126 = 32;
      v125 = 204;
      v124 = (int)&STACK[0x2AEC];
      goto LABEL_76;
    }
    sub_613C30(v133);
    v63 = (void (__thiscall ***)(_DWORD))*((_DWORD *)v60 + 7);
    if ( v63 )
    {
      v64 = *v63;
      v127 = 1;
      (*v64)(v63);
    }
    v65 = (void (__thiscall *)(void *))operator new(0xCCu);
    v132 = (int)v65;
    LOBYTE(STACK[0x4474]) = 6;
    if ( v65 )
      v66 = sub_46D4A0(v65);
    else
      v66 = 0;
    LOBYTE(STACK[0x4474]) = 5;
    *((_DWORD *)v60 + 7) = v66;
    if ( v66 )
      sub_46B7A0(&STACK[0x2460]);
    v67 = (void (__thiscall ***)(_DWORD))*((_DWORD *)v60 + 5);
    if ( v67 )
    {
      v68 = *v67;
      v126 = 1;
      (*v68)(v67);
    }
    v69 = operator new(0xCCu);
    v131 = (int)v69;
    LOBYTE(STACK[0x4470]) = 7;
    if ( v69 )
      v70 = sub_46D4A0(v69);
    else
      v70 = 0;
    LOBYTE(STACK[0x4470]) = 5;
    *((_DWORD *)v60 + 5) = v70;
    if ( v70 )
      sub_46B7A0(&STACK[0x252C]);
    v71 = (void (__thiscall ***)(_DWORD))*((_DWORD *)v60 + 6);
    if ( v71 )
    {
      v72 = *v71;
      v125 = 1;
      (*v72)(v71);
    }
    v73 = operator new(0xCCu);
    v130 = (unsigned int)v73;
    LOBYTE(STACK[0x446C]) = 8;
    if ( v73 )
      v74 = sub_46D4A0(v73);
    else
      v74 = 0;
    LOBYTE(STACK[0x446C]) = 5;
    *((_DWORD *)v60 + 6) = v74;
    if ( v74 )
      sub_46B7A0(&STACK[0x2388]);
    v75 = (void (__thiscall ***)(_DWORD))*((_DWORD *)v60 + 4);
    if ( v75 )
    {
      v76 = *v75;
      v124 = 1;
      (*v76)(v75);
    }
    v77 = operator new(0xCCu);
    p_String2 = (int)v77;
    LOBYTE(STACK[0x4468]) = 9;
    if ( v77 )
      v78 = sub_46D4A0(v77);
    else
      v78 = 0;
    LOBYTE(STACK[0x4468]) = 5;
    *((_DWORD *)v60 + 4) = v78;
    if ( v78 )
      sub_46B7A0(&STACK[0x25F4]);
    v79 = (void (__thiscall ***)(_DWORD))*((_DWORD *)v60 + 8);
    if ( v79 )
    {
      if ( *(v79 - 1) )
      {
        v80 = *v79;
        LODWORD(v123) = 3;
        (*v80)(v79);
      }
      else
      {
        j_j__free(v79 - 1);
      }
    }
    v81 = v127;
    if ( v127 <= 0 )
    {
      v60[14] = 0.0;
      v60[15] = 0.0;
    }
    else
    {
      v82 = (unsigned int *)operator new(204 * v127 + 4);
      v128 = v82;
      LOBYTE(STACK[0x4464]) = 10;
      if ( v82 )
      {
        v122 = sub_46B2D0;
        v121 = COERCE_FLOAT(sub_46D4A0);
        v120 = v81;
        v61 = v82 + 1;
        LODWORD(v119) = 204;
        v118 = v82 + 1;
        *v82 = v81;
        sub_630A11(v118, LODWORD(v119), v120, LODWORD(v121), v122);
      }
      else
      {
        v81 = v127;
      }
      LOBYTE(STACK[0x4464]) = 5;
      *((_DWORD *)v60 + 8) = v61;
      if ( v61 )
      {
        if ( v81 > 0 )
        {
          v83 = 0;
          v127 = v81;
          do
          {
            sub_46B7A0((char *)&STACK[0x2AD8] + v83);
            v83 += 204;
            --v127;
          }
          while ( *(float *)&v127 != 0.0 );
        }
        v60[14] = *(float *)&v81;
        v60[15] = 0.0;
      }
    }
    sub_40E380(v60);
    if ( !dword_91BF20 )
    {
LABEL_74:
      LOBYTE(STACK[0x441C]) = 4;
      `eh vector destructor iterator'(&STACK[0x2A90], 0xCCu, 32, sub_46B2D0);
      LOBYTE(STACK[0x441C]) = 3;
      sub_46B2D0(&STACK[0x2408]);
      LOBYTE(STACK[0x441C]) = 2;
      sub_46B2D0(&a59);
      LOBYTE(STACK[0x441C]) = 1;
      sub_46B2D0(&STACK[0x24D8]);
      LOBYTE(STACK[0x441C]) = 0;
      sub_46B2D0(&STACK[0x25A8]);
      STACK[0x441C] = -1;
      sub_614140(&v111);
      return 0;
    }
    sub_5E4DD0(0, &v127);
    if ( dword_B71758 )
    {
      if ( dword_B71758 == 2 )
      {
        v84 = *(float *)&v127 + 250.0;
      }
      else
      {
        if ( dword_B71758 != 3 )
        {
LABEL_70:
          v85 = *((_DWORD *)v60 + 7);
          v122 = 0;
          v121 = COERCE_FLOAT(&v128);
          sub_46B210(v85);
          v86 = v126;
          v87 = *((_DWORD *)v60 + 7);
          v120 = 0;
          *(float *)(v87 + 68) = *(float *)&v125;
          *(_DWORD *)(v87 + 64) = v86;
          v88 = *((_DWORD *)v60 + 6);
          v119 = COERCE_FLOAT(&v126);
          sub_46B210(v88);
          v89 = v124;
          v90 = *((_DWORD *)v60 + 6);
          v118 = 0;
          *(float *)(v90 + 68) = v123;
          *(_DWORD *)(v90 + 64) = v89;
          v91 = *((_DWORD *)v60 + 5);
          v117 = COERCE_FLOAT(&v124);
          sub_46B210(v91);
          v92 = v122;
          v93 = *((_DWORD *)v60 + 5);
          v116 = 0.0;
          *(float *)(v93 + 68) = v121;
          *(_DWORD *)(v93 + 64) = v92;
          v94 = *((_DWORD *)v60 + 4);
          v115 = COERCE_FLOAT(&v122);
          sub_46B210(v94);
          v95 = *((_DWORD *)v60 + 4);
          v96 = v120;
          *(float *)(v95 + 68) = v119;
          *(_DWORD *)(v95 + 64) = v96;
          v97 = 0;
          if ( *((int *)v60 + 14) > 0 )
          {
            v98 = 0;
            do
            {
              v99 = *((_DWORD *)v60 + 8);
              v114 = 0.0;
              v113 = COERCE_FLOAT(&v120);
              sub_46B210(v98 + v99);
              v100 = *((_DWORD *)v60 + 8);
              v101 = v118;
              *(float *)(v100 + v98 + 68) = v117;
              *(_DWORD *)(v98 + v100 + 64) = v101;
              ++v97;
              v98 += 204;
            }
            while ( v97 < *((_DWORD *)v60 + 14) );
          }
          v102 = *((_DWORD *)v60 + 9);
          v112 = 0.0;
          v111 = COERCE_FLOAT(&v118);
          sub_46B210(v102);
          v103 = v116;
          v104 = *((_DWORD *)v60 + 9);
          *(float *)(v104 + 68) = v115;
          *(float *)(v104 + 64) = v103;
          sub_46B210(*((_DWORD *)v60 + 10));
          v105 = v114;
          v106 = *((_DWORD *)v60 + 10);
          *(float *)(v106 + 68) = v113;
          *(float *)(v106 + 64) = v105;
          sub_46B210(*((_DWORD *)v60 + 11));
          v107 = v112;
          v108 = *((_DWORD *)v60 + 11);
          *(float *)(v108 + 68) = v111;
          *(float *)(v108 + 64) = v107;
          sub_46B210(*((_DWORD *)v60 + 12));
          v109 = *((_DWORD *)v60 + 12);
          *(float *)(v109 + 68) = COERCE_FLOAT(&v116);
          *(_DWORD *)(v109 + 64) = 0;
          goto LABEL_74;
        }
        v84 = *(float *)&v127 + 500.0;
      }
    }
    else
    {
      v84 = *(float *)&v127 - 250.0;
    }
    *(float *)&v127 = v84;
    goto LABEL_70;
  }
  v132 = (int)sub_46B2D0;
  v131 = 32;
  v130 = 204;
  p_String2 = (int)&STACK[0x2B00];
LABEL_76:
  LOBYTE(STACK[0x448C]) = 4;
  `eh vector destructor iterator'((void *)p_String2, v130, v131, (void (__thiscall *)(void *))v132);
  LOBYTE(STACK[0x448C]) = 3;
  sub_46B2D0(&STACK[0x2478]);
  LOBYTE(STACK[0x448C]) = 2;
  sub_46B2D0(&STACK[0x23A8]);
  LOBYTE(STACK[0x448C]) = 1;
  sub_46B2D0(&STACK[0x2548]);
  LOBYTE(STACK[0x448C]) = 0;
  sub_46B2D0(&STACK[0x2618]);
  STACK[0x448C] = -1;
  sub_614140(v136);
  return 1;
}
