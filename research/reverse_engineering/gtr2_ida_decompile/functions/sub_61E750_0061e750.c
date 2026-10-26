int __thiscall sub_61E750(int *this, const char *a2, int a3)
{
  FILE *v4; // esi
  int v5; // eax
  int v6; // edi
  int *v7; // eax
  _DWORD *v8; // ebx
  _DWORD *v9; // eax
  int v10; // edi
  int *v11; // eax
  _DWORD *v12; // ebx
  _DWORD *v13; // eax
  int v14; // edi
  int *v15; // eax
  _DWORD *v16; // ebx
  _DWORD *v17; // eax
  int v18; // edi
  int *v19; // eax
  _DWORD *v20; // ebx
  _DWORD *v21; // eax
  int v22; // eax
  int v23; // ebx
  int v24; // edi
  void **v25; // eax
  _DWORD *v26; // eax
  int v27; // eax
  char *v28; // edi
  int v29; // ebx
  char *v30; // edi
  int v31; // ebx
  int v32; // ebx
  int v33; // edi
  char *v34; // eax
  int v35; // edi
  int v36; // eax
  int *v37; // ecx
  char *v38; // eax
  int v39; // eax
  void *v40; // eax
  int v41; // edx
  int v42; // eax
  _DWORD *v43; // edx
  char *v44; // ecx
  int v45; // eax
  void *v46; // eax
  int v47; // edx
  int v48; // eax
  int *v49; // edx
  _DWORD *v50; // ecx
  char *v51; // ecx
  int v52; // edi
  int v53; // ebx
  int v54; // edi
  int v55; // ebx
  int v56; // eax
  int v57; // ecx
  bool v58; // cc
  int v59; // edi
  int v60; // ebx
  int v61; // eax
  _DWORD *v62; // ecx
  int v63; // edi
  int v64; // ebx
  int v65; // ebx
  int v66; // ebx
  int v67; // eax
  int v68; // ecx
  void *v69; // eax
  int v70; // ecx
  int v71; // eax
  int v72; // edi
  int v73; // ebx
  double *v75; // eax
  int v76; // ecx
  int v77; // edx
  int v78; // edi
  int v79; // eax
  _DWORD *v80; // [esp-Ch] [ebp-80Ch]
  void *v81; // [esp-8h] [ebp-808h]
  int v82; // [esp-4h] [ebp-804h]
  double v83; // [esp+0h] [ebp-800h]
  char *v84; // [esp+4h] [ebp-7FCh]
  int v85; // [esp+8h] [ebp-7F8h]
  const char *v86; // [esp+Ch] [ebp-7F4h]
  char *p_String2; // [esp+10h] [ebp-7F0h]
  int v88; // [esp+14h] [ebp-7ECh]
  const char *v89; // [esp+14h] [ebp-7ECh]
  int v90; // [esp+18h] [ebp-7E8h]
  int v91; // [esp+18h] [ebp-7E8h]
  int v92; // [esp+18h] [ebp-7E8h]
  int v93; // [esp+18h] [ebp-7E8h]
  int v94; // [esp+1Ch] [ebp-7E4h]
  int v95; // [esp+1Ch] [ebp-7E4h]
  int v96; // [esp+1Ch] [ebp-7E4h]
  int v97; // [esp+1Ch] [ebp-7E4h]
  int v98; // [esp+20h] [ebp-7E0h]
  int v99; // [esp+24h] [ebp-7DCh]
  int v100; // [esp+28h] [ebp-7D8h]
  void *Block; // [esp+2Ch] [ebp-7D4h] BYREF
  char *v102; // [esp+30h] [ebp-7D0h]
  int v103; // [esp+34h] [ebp-7CCh] BYREF
  int v104; // [esp+38h] [ebp-7C8h]
  int v105; // [esp+3Ch] [ebp-7C4h] BYREF
  void *v106; // [esp+40h] [ebp-7C0h]
  int v107; // [esp+44h] [ebp-7BCh]
  int v108; // [esp+48h] [ebp-7B8h]
  int v109; // [esp+4Ch] [ebp-7B4h]
  double v110; // [esp+50h] [ebp-7B0h]
  double v111; // [esp+58h] [ebp-7A8h] BYREF
  int v112[2]; // [esp+60h] [ebp-7A0h] BYREF
  int v113[2]; // [esp+68h] [ebp-798h] BYREF
  int v114[2]; // [esp+70h] [ebp-790h] BYREF
  int v115[2]; // [esp+78h] [ebp-788h] BYREF
  int v116; // [esp+80h] [ebp-780h]
  int v117; // [esp+84h] [ebp-77Ch] BYREF
  double v118; // [esp+88h] [ebp-778h]
  double v119; // [esp+90h] [ebp-770h]
  double v120; // [esp+98h] [ebp-768h]
  int v121[2]; // [esp+A0h] [ebp-760h] BYREF
  int v122[2]; // [esp+A8h] [ebp-758h] BYREF
  int v123; // [esp+B0h] [ebp-750h]
  int v124[2]; // [esp+B4h] [ebp-74Ch] BYREF
  int v125[2]; // [esp+BCh] [ebp-744h] BYREF
  int v126; // [esp+C4h] [ebp-73Ch] BYREF
  int v127[2]; // [esp+C8h] [ebp-738h] BYREF
  double v128; // [esp+D0h] [ebp-730h] BYREF
  double v129; // [esp+D8h] [ebp-728h]
  double v130; // [esp+E0h] [ebp-720h]
  int v131; // [esp+E8h] [ebp-718h] BYREF
  int v132[2]; // [esp+ECh] [ebp-714h] BYREF
  int v133; // [esp+F4h] [ebp-70Ch] BYREF
  int v134; // [esp+F8h] [ebp-708h]
  int v135; // [esp+FCh] [ebp-704h] BYREF
  int v136; // [esp+100h] [ebp-700h]
  int v137; // [esp+104h] [ebp-6FCh] BYREF
  int v138; // [esp+108h] [ebp-6F8h]
  int v139[2]; // [esp+10Ch] [ebp-6F4h] BYREF
  int v140[4]; // [esp+114h] [ebp-6ECh] BYREF
  char v141[16]; // [esp+124h] [ebp-6DCh] BYREF
  double v142; // [esp+134h] [ebp-6CCh] BYREF
  char String[4]; // [esp+13Ch] [ebp-6C4h] BYREF
  double v144; // [esp+140h] [ebp-6C0h]
  char String2; // [esp+148h] [ebp-6B8h] BYREF
  char v146[12]; // [esp+164h] [ebp-69Ch] BYREF
  _DWORD v147[2]; // [esp+170h] [ebp-690h] BYREF
  char v148[4]; // [esp+178h] [ebp-688h] BYREF
  char v149[12]; // [esp+17Ch] [ebp-684h] BYREF
  _DWORD v150[25]; // [esp+188h] [ebp-678h] BYREF
  char v151[64]; // [esp+1ECh] [ebp-614h] BYREF
  char v152[24]; // [esp+22Ch] [ebp-5D4h] BYREF
  char v153[40]; // [esp+244h] [ebp-5BCh] BYREF
  char v154[88]; // [esp+26Ch] [ebp-594h] BYREF
  char v155[12]; // [esp+2C4h] [ebp-53Ch] BYREF
  char Buffer[220]; // [esp+2D0h] [ebp-530h] BYREF
  _BYTE v157[12]; // [esp+3ACh] [ebp-454h] BYREF
  _BYTE v158[12]; // [esp+3C4h] [ebp-43Ch] BYREF
  _BYTE v159[480]; // [esp+3D0h] [ebp-430h] BYREF
  char v160; // [esp+5B0h] [ebp-250h]
  char v161[12]; // [esp+5C4h] [ebp-23Ch] BYREF
  int v162; // [esp+5D0h] [ebp-230h]
  char v163; // [esp+5D4h] [ebp-22Ch]
  char v164[4]; // [esp+5D8h] [ebp-228h] BYREF
  char v165[4]; // [esp+5DCh] [ebp-224h] BYREF
  int v166; // [esp+5E0h] [ebp-220h]
  int v167; // [esp+5E4h] [ebp-21Ch]
  char Str[516]; // [esp+5E8h] [ebp-218h] BYREF
  int v169; // [esp+7ECh] [ebp-14h]
  int v170; // [esp+7FCh] [ebp-4h]

  v169 = dword_912B08;
  memset(Str, 0, 0x200u);
  v162 = 0;
  v167 = 0;
  *(_DWORD *)v165 = 0;
  v166 = 0;
  v163 = 1;
  sub_61DA10(this);
  remove("pmodel_error.txt");
  sub_6170B0(v150);
  v170 = 0;
  if ( !sub_617210((int)v150, (int)a2, a3) )
  {
    sprintf(Buffer, "Could not open %s\n", a2);
    v4 = fopen("pmodel_error.txt", "a");
    if ( v4 )
    {
      fprintf(v4, "%s", Buffer);
      goto LABEL_127;
    }
    goto LABEL_128;
  }
  *this = 0;
  this[2] = 0;
  this[4] = 0;
  this[6] = 0;
  while ( sub_6173C0(v150, Str, 0x200u) )
  {
    if ( !sub_612EB0(v159) )
    {
      if ( strstr(Str, "[BODY]") )
        ++*this;
      if ( strstr(Str, "[JOINT]") )
        ++this[2];
      if ( strstr(Str, "[HINGE]") )
        ++this[4];
      if ( strstr(Str, "[BAR]") )
        ++this[6];
      if ( strstr(Str, "[JOINT&HINGE]") )
      {
        v5 = this[4] + 1;
        ++this[2];
        this[4] = v5;
      }
    }
  }
  v6 = *this;
  v7 = (int *)operator new(584 * *this + 4);
  Block = v7;
  LOBYTE(v170) = 1;
  if ( v7 )
  {
    v8 = v7 + 1;
    *v7 = v6;
    sub_630A11(v7 + 1, 584, v6, sub_61B5E0, sub_61B610);
    v9 = v8;
  }
  else
  {
    v9 = 0;
  }
  v10 = this[2];
  LOBYTE(v170) = 0;
  this[1] = (int)v9;
  v11 = (int *)operator new(56 * v10 + 4);
  Block = v11;
  LOBYTE(v170) = 2;
  if ( v11 )
  {
    v12 = v11 + 1;
    *v11 = v10;
    sub_630A11(v11 + 1, 56, v10, &unknown_libname_2, sub_61CF50);
    v13 = v12;
  }
  else
  {
    v13 = 0;
  }
  v14 = this[4];
  this[3] = (int)v13;
  LOBYTE(v170) = 0;
  v15 = (int *)operator new(56 * v14 + 4);
  Block = v15;
  LOBYTE(v170) = 3;
  if ( v15 )
  {
    v16 = v15 + 1;
    *v15 = v14;
    sub_630A11(v15 + 1, 56, v14, &unknown_libname_2, sub_61CF50);
    v17 = v16;
  }
  else
  {
    v17 = 0;
  }
  v18 = this[6];
  LOBYTE(v170) = 0;
  this[5] = (int)v17;
  v19 = (int *)operator new(80 * v18 + 4);
  Block = v19;
  LOBYTE(v170) = 4;
  if ( v19 )
  {
    v20 = v19 + 1;
    *v19 = v18;
    sub_630A11(v19 + 1, 80, v18, &unknown_libname_2, sub_61CF50);
    v21 = v20;
  }
  else
  {
    v21 = 0;
  }
  LOBYTE(v170) = 0;
  this[7] = (int)v21;
  v100 = 0;
  HIDWORD(v110) = 0;
  sub_6175A0((int)v150);
  if ( !sub_6173C0(v150, Str, 0x200u) )
  {
LABEL_104:
    v52 = 0;
    if ( *this > 0 )
    {
      v53 = 0;
      do
      {
        sub_6191E0((_DWORD *)(v53 + this[1]));
        ++v52;
        v53 += 584;
      }
      while ( v52 < *this );
    }
    this[8] = sub_61D500(this);
    v91 = 0;
    if ( this[2] > 0 )
    {
      v95 = 0;
      do
      {
        v54 = v95 + this[3];
        v111 = *(double *)(v54 + 24);
        v112[0] = *(_DWORD *)(v54 + 32);
        v112[1] = *(_DWORD *)(v54 + 36);
        v113[0] = *(_DWORD *)(v54 + 40);
        v113[1] = *(_DWORD *)(v54 + 44);
        v55 = *(_DWORD *)(v54 + 48);
        v56 = sub_619250(*(_DWORD *)(v54 + 4), &v111, v55, 1);
        v57 = *(_DWORD *)(v54 + 12);
        *(_DWORD *)(v54 + 8) = v56;
        *(_DWORD *)(v54 + 16) = sub_619250(v57, &v111, v55, 0);
        *(_DWORD *)(v54 + 48) = 0;
        sub_61CF70((_DWORD *)v54);
        v58 = ++v91 < this[2];
        v95 += 56;
      }
      while ( v58 );
    }
    v92 = 0;
    if ( this[4] > 0 )
    {
      v96 = 0;
      do
      {
        v59 = v96 + this[5];
        v111 = *(double *)(v59 + 24);
        v112[0] = *(_DWORD *)(v59 + 32);
        v112[1] = *(_DWORD *)(v59 + 36);
        v113[0] = *(_DWORD *)(v59 + 40);
        v113[1] = *(_DWORD *)(v59 + 44);
        v60 = *(_DWORD *)(v59 + 48);
        v61 = sub_6192A0(*(_DWORD **)(v59 + 4), (int)&v111, v60, 1, v59);
        v62 = *(_DWORD **)(v59 + 12);
        *(_DWORD *)(v59 + 8) = v61;
        *(_DWORD *)(v59 + 16) = sub_6192A0(v62, (int)&v111, v60, 0, v59);
        *(_DWORD *)(v59 + 48) = 0;
        sub_61D020((_DWORD *)v59);
        v58 = ++v92 < this[4];
        v96 += 56;
      }
      while ( v58 );
    }
    v93 = 0;
    if ( this[6] > 0 )
    {
      v97 = 0;
      do
      {
        v63 = v97 + this[7];
        v128 = *(double *)(v63 + 24);
        v129 = *(double *)(v63 + 32);
        v130 = *(double *)(v63 + 40);
        v111 = *(double *)(v63 + 48);
        v112[0] = *(_DWORD *)(v63 + 56);
        v64 = *(_DWORD *)(v63 + 60);
        v118 = v128;
        v112[1] = v64;
        v65 = *(_DWORD *)(v63 + 64);
        v118 = v128 - v111;
        v113[0] = v65;
        v113[1] = *(_DWORD *)(v63 + 68);
        v119 = v129 - *(double *)v112;
        v120 = v130;
        v66 = *(_DWORD *)(v63 + 72);
        v120 = v130 - *(double *)v113;
        v110 = sqrt(v120 * v120 + v119 * v119 + v118 * v118);
        v67 = sub_619350(*(_DWORD *)(v63 + 4), &v128, v66, 1, v110);
        v68 = *(_DWORD *)(v63 + 12);
        v83 = v110;
        *(_DWORD *)(v63 + 8) = v67;
        *(_DWORD *)(v63 + 16) = sub_619350(v68, &v111, v66, 0, v83);
        *(_DWORD *)(v63 + 72) = 0;
        sub_61D2B0((_DWORD *)v63);
        v58 = ++v93 < this[6];
        v97 += 80;
      }
      while ( v58 );
    }
    this[10] = (int)operator new(4 * this[8]);
    v69 = operator new(8 * this[8] * this[8]);
    v70 = this[8];
    this[9] = (int)v69;
    v71 = 0;
    if ( v70 > 0 )
    {
      do
      {
        *(_DWORD *)(this[10] + 4 * v71) = this[9] + 8 * v71 * this[8];
        ++v71;
      }
      while ( v71 < this[8] );
    }
    sub_61D960(this, (_DWORD *)this[10], this[8]);
    this[12] = 0;
    v72 = sub_62A193(0);
    v73 = 1;
    if ( v72 )
    {
      while ( !(*(unsigned __int8 (__thiscall **)(int, int, int))(*(_DWORD *)v72 + 16))(v72, this[10], this[8]) )
      {
        v72 = sub_62A193(v73++);
        if ( !v72 )
          goto LABEL_130;
      }
      j__free((void *)this[9]);
      v81 = (void *)this[10];
      this[9] = 0;
      j__free(v81);
      this[10] = (*(int (__thiscall **)(int))(*(_DWORD *)v72 + 8))(v72);
      this[11] = (**(int (__thiscall ***)(int))v72)(v72);
      this[12] = v72;
    }
LABEL_130:
    if ( !this[12] )
    {
      sub_61D960(this, (_DWORD *)this[10], this[8]);
      v75 = (double *)operator new(8 * this[8]);
      v82 = this[8];
      v80 = (_DWORD *)this[10];
      this[11] = (int)v75;
      sub_61C360(this + 13, v80, v75, v82);
    }
    v76 = 0;
    if ( *this > 0 )
    {
      v77 = 0;
      do
      {
        v78 = this[11];
        v79 = v77 + this[1];
        *(_DWORD *)(v79 + 556) = this[10];
        *(_DWORD *)(v79 + 552) = v78;
        ++v76;
        v77 += 584;
      }
      while ( v76 < *this );
    }
    sub_613C30((int)v147);
    *(_DWORD *)&Str[508] = -1;
    sub_617170(v147);
    return 0;
  }
  v112[0] = 0;
  v111 = 0.0;
  Block = 0;
  while ( 1 )
  {
    if ( sub_612EB0(v159) )
      goto LABEL_103;
    if ( strstr(Str, "[BODY]") )
    {
      v134 = 0;
      v144 = 1.0;
      v135 = 0;
      v136 = 0;
      *(double *)v127 = 1.0;
      v137 = 0;
      v138 = 0;
      v139[0] = 0;
      v104 = 0;
      v123 = 0;
      v116 = 0;
      v105 = 0;
      v124[0] = 0;
      v117 = 0;
      v106 = 0;
      v124[1] = 0;
      v118 = 0.0;
      v107 = 0;
      v125[0] = 0;
      v108 = 0;
      v125[1] = 0;
      v119 = 0.0;
      v109 = 0;
      v126 = 0;
      String2 = 0;
      v128 = 1.0;
      v129 = COERCE_DOUBLE(__PAIR64__(v127[1], COERCE_UNSIGNED_INT64(1.0)));
      if ( sub_6173C0(v150, Str, 0x200u) )
      {
        do
        {
          v22 = sub_612EB0(v159);
          if ( v22 )
          {
            if ( v22 == 1 )
              break;
          }
          else
          {
            v86 = "name";
            if ( sub_6137E0() )
              _strupr(String);
            sub_6136D0((int)v158, "mass", (int)&v142, 0, 0, 0);
            sub_6136D0((int)v158, "inertia", (int)v125, (int)&v126, (int)&v127[1], 0);
            sub_6136D0((int)v158, (char *)off_72ECB0, (int)&Block, (int)&v103, (int)&v105, 0);
            sub_6136D0((int)v158, (char *)off_72ECAC, (int)&v114[1], (int)&v115[1], (int)&v117, 0);
            sub_6136D0((int)v158, (char *)off_72ECA8, (int)&v121[1], (int)&v122[1], (int)v124, 0);
            sub_6136D0((int)v158, (char *)off_72ECA4, (int)v132, (int)&v133, (int)&v135, 0);
          }
        }
        while ( sub_6173C0(v149, v165, 0x200u) );
      }
      if ( !String[0] )
      {
        sprintf(v155, "Body %d must be named\n", v94);
        goto LABEL_125;
      }
      v23 = LODWORD(v110);
      v24 = 0;
      if ( SLODWORD(v110) > 0 )
      {
        v100 = 0;
        while ( _stricmp(*(const char **)(v100 + this[1]), String) )
        {
          ++v24;
          v100 += 584;
          if ( v24 >= v94 )
            goto LABEL_47;
        }
        if ( v24 < v94 )
        {
          sprintf(v155, "Two bodies named \"%s\"\n", String);
          goto LABEL_125;
        }
      }
LABEL_47:
      sub_61B620(v23 + this[1], String, v142, v125);
      v25 = (void **)(v23 + this[1] + 8);
      *v25 = Block;
      v25[1] = v102;
      v25[2] = (void *)v103;
      v25[3] = (void *)v104;
      v25[4] = (void *)v105;
      v25[5] = v106;
      sub_61B6E0((double *)(v23 + this[1]), (int)&v114[1]);
      v26 = (_DWORD *)(v23 + this[1] + 104);
      *v26 = v121[0];
      v26[1] = v121[1];
      v26[2] = v122[0];
      v26[3] = v122[1];
      v26[4] = v123;
      v26[5] = v124[0];
      sub_61B710(v23 + this[1], &v131);
      ++v90;
      v109 = v23 + 584;
      goto LABEL_103;
    }
    if ( !strstr(Str, "[JOINT]") && !strstr(Str, "[HINGE]") && !strstr(Str, "[BAR]") && !strstr(Str, "[JOINT&HINGE]") )
      goto LABEL_103;
    HIWORD(v102) = 0;
    BYTE1(v102) = strstr(Str, "[JOINT]") != 0;
    if ( strstr(Str, "[HINGE]") )
      BYTE2(v102) = 1;
    if ( strstr(Str, "[BAR]") )
      HIBYTE(v102) = 1;
    if ( strstr(Str, "[JOINT&HINGE]") )
      *(_WORD *)((char *)&v102 + 1) = 257;
    v104 = 0;
    v116 = 0;
    v105 = 0;
    v117 = 0;
    v106 = 0;
    v118 = 0.0;
    v107 = 0;
    v108 = 0;
    v119 = 0.0;
    v109 = 0;
    String2 = 0;
    v153[12] = 0;
    v154[36] = 0;
    v151[36] = 0;
    if ( sub_6173C0(v150, Str, 0x200u) )
    {
      do
      {
        v27 = sub_612EB0(v159);
        if ( v27 )
        {
          if ( v27 == 1 )
            break;
        }
        else
        {
          v88 = 0;
          p_String2 = &String2;
          v86 = "name";
          if ( sub_6137E0() )
            _strupr(String);
          v85 = 0;
          v84 = v153;
          sub_6137E0();
          sub_6137E0();
          sub_6136D0((int)v157, "axis", (int)&v111 + 4, (int)&v112[1], (int)&v113[1], 0);
          sub_6136D0((int)v157, (char *)off_72EC88, (int)v132, (int)&v133, (int)&v135, 0);
          v160 = 0;
          if ( sub_6136D0((int)v157, (char *)off_72ECB0, (int)&v137, (int)v139, (int)v140, 0) )
          {
            v88 = v137;
            v90 = v138;
            v94 = v139[0];
            v98 = v139[1];
            v99 = v140[0];
            v100 = v140[1];
            v160 = 1;
          }
          else
          {
            sub_6137E0();
            v159[468] = 1;
          }
        }
      }
      while ( sub_6173C0(v146, v161, 0x200u) );
    }
    if ( v151[0] )
      break;
LABEL_74:
    v30 = 0;
    if ( v104 > 0 )
    {
      v31 = 0;
      do
      {
        if ( !_stricmp(v152, *(const char **)(v31 + this[1])) )
          break;
        ++v30;
        v31 += 584;
      }
      while ( (int)v30 < (int)v84 );
    }
    v32 = v85;
    if ( v30 == v84 )
      goto LABEL_124;
    if ( BYTE1(v86) )
    {
      *(_DWORD *)(this[3] + v85 + 4) = 584 * (_DWORD)v30 + this[1];
      ++*(_DWORD *)(584 * (_DWORD)v30 + this[1] + 560);
    }
    if ( BYTE2(v86) )
    {
      *(_DWORD *)(v103 + this[5] + 4) = 584 * (_DWORD)v30 + this[1];
      v32 = v85;
      ++*(_DWORD *)(584 * (_DWORD)v30 + this[1] + 568);
    }
    if ( HIBYTE(v86) )
    {
      v33 = 584 * (_DWORD)v30;
      *(_DWORD *)(this[7] + v105 + 4) = v33 + this[1];
      *(_DWORD *)(v33 + this[1] + 576) = *(_DWORD *)(this[1] + v33 + 576) + 1;
    }
    v34 = 0;
    p_String2 = 0;
    if ( v104 > 0 )
    {
      v35 = 0;
      do
      {
        if ( !_stricmp(v154, *(const char **)(v35 + this[1])) )
          break;
        v35 += 584;
        ++p_String2;
      }
      while ( (int)p_String2 < (int)v84 );
      v34 = p_String2;
    }
    if ( v34 == v84 )
      goto LABEL_124;
    if ( BYTE1(v86) )
    {
      v36 = 584 * (_DWORD)v34;
      *(_DWORD *)(this[3] + v32 + 12) = v36 + this[1];
      *(_DWORD *)(v36 + this[1] + 560) = *(_DWORD *)(this[1] + v36 + 560) + 1;
      if ( v141[0] )
      {
        *(_DWORD *)(v32 + this[3]) = operator new(strlen(v141) + 1);
        strcpy(*(char **)(v32 + this[3]), v141);
      }
      v37 = (int *)(this[3] + v32 + 24);
      *v37 = v88;
      v37[1] = v90;
      v37[2] = v94;
      v37[3] = v98;
      v37[4] = v99;
      v37[5] = v100;
      v38 = v102;
      *(_DWORD *)(this[3] + v32 + 48) = v102;
      v102 = v38 + 1;
      v34 = p_String2;
      v85 = v32 + 56;
    }
    if ( BYTE2(v86) )
    {
      v39 = 584 * (_DWORD)v34;
      *(_DWORD *)(v103 + this[5] + 12) = v39 + this[1];
      *(_DWORD *)(v39 + this[1] + 568) = *(_DWORD *)(this[1] + v39 + 568) + 1;
      if ( v141[0] )
      {
        v40 = operator new(strlen(v141) + 1);
        v41 = v103;
        *(_DWORD *)(v103 + this[5]) = v40;
        strcpy(*(char **)(v41 + this[5]), v141);
      }
      v42 = v103;
      v43 = (_DWORD *)(v103 + this[5] + 24);
      *v43 = HIDWORD(v111);
      v43[1] = v112[0];
      v43[2] = v112[1];
      v43[3] = v113[0];
      v43[4] = v113[1];
      v43[5] = v114[0];
      v44 = v102;
      *(_DWORD *)(v42 + this[5] + 48) = v102;
      v103 = v42 + 56;
      v34 = p_String2;
      v102 = v44 + 1;
    }
    if ( HIBYTE(v86) )
    {
      v45 = 584 * (_DWORD)v34;
      *(_DWORD *)(this[7] + v105 + 12) = v45 + this[1];
      *(_DWORD *)(v45 + this[1] + 576) = *(_DWORD *)(this[1] + v45 + 576) + 1;
      if ( v141[0] )
      {
        v46 = operator new(strlen(v141) + 1);
        v47 = v105;
        *(_DWORD *)(v105 + this[7]) = v46;
        strcpy(*(char **)(v47 + this[7]), v141);
      }
      v48 = v105;
      v49 = (int *)(this[7] + v105 + 24);
      *v49 = v88;
      v49[1] = v90;
      v49[2] = v94;
      v49[3] = v98;
      v49[4] = v99;
      v49[5] = v100;
      v50 = (_DWORD *)(this[7] + v48 + 48);
      *v50 = v132[0];
      v50[1] = v132[1];
      v50[2] = v133;
      v50[3] = v134;
      v50[4] = v135;
      v50[5] = v136;
      v51 = v102;
      *(_DWORD *)(this[7] + v48 + 72) = v102;
      v102 = v51 + 1;
      v105 = v48 + 80;
    }
LABEL_103:
    if ( !sub_6173C0(v148, v164, 0x200u) )
      goto LABEL_104;
  }
  v28 = 0;
  if ( v104 > 0 )
  {
    v29 = 0;
    do
    {
      if ( !_stricmp(v151, *(const char **)(v29 + this[1])) )
        break;
      ++v28;
      v29 += 584;
    }
    while ( (int)v28 < (int)v84 );
  }
  if ( v28 != v84 )
  {
    v88 = *(_DWORD *)(584 * (_DWORD)v28 + this[1] + 8);
    v90 = *(_DWORD *)(584 * (_DWORD)v28 + this[1] + 12);
    v94 = *(_DWORD *)(584 * (_DWORD)v28 + this[1] + 16);
    v98 = *(_DWORD *)(584 * (_DWORD)v28 + this[1] + 20);
    v99 = *(_DWORD *)(584 * (_DWORD)v28 + this[1] + 24);
    v100 = *(_DWORD *)(584 * (_DWORD)v28 + this[1] + 28);
    goto LABEL_74;
  }
LABEL_124:
  sprintf(v155, v84, v85, v86, p_String2, v88);
LABEL_125:
  v4 = fopen("pmodel_error.txt", "a");
  if ( v4 )
  {
    fprintf(v4, "%s", v89);
LABEL_127:
    fclose(v4);
  }
LABEL_128:
  v170 = -1;
  sub_617170(v150);
  return -1;
}
