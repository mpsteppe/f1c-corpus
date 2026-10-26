int __thiscall sub_5806C0(int *this, int a2)
{
  int v3; // eax
  int v4; // edi
  int v5; // eax
  int v6; // esi
  int *v7; // eax
  _DWORD *v8; // ebx
  _DWORD *v9; // edi
  _DWORD *v10; // eax
  int v11; // esi
  int *v12; // eax
  int v13; // esi
  _DWORD *v14; // edx
  _DWORD *v15; // eax
  int v16; // ecx
  _DWORD *v17; // eax
  int v18; // esi
  int *v19; // eax
  int v20; // esi
  _DWORD *v21; // edx
  _DWORD *v22; // eax
  int v23; // ecx
  _DWORD *v24; // eax
  int v25; // esi
  int *v26; // eax
  int v27; // esi
  _DWORD *v28; // edx
  _DWORD *v29; // eax
  int v30; // ecx
  _DWORD *v31; // eax
  int v32; // eax
  int v33; // esi
  int v34; // edi
  int v35; // eax
  int v36; // esi
  int v37; // edi
  int v38; // esi
  int v39; // edi
  int v40; // esi
  int v41; // ebx
  int v42; // esi
  int v43; // esi
  int v44; // edi
  _DWORD *v45; // ebx
  int v46; // esi
  int v47; // eax
  int v48; // ecx
  bool v49; // cc
  int v50; // ebx
  int v51; // esi
  int v52; // eax
  _DWORD *v53; // ecx
  int *v54; // ebx
  unsigned __int64 v55; // st4
  void *v56; // eax
  int v57; // ecx
  int v58; // edi
  int i; // eax
  int v60; // ecx
  int v61; // esi
  _DWORD *v62; // eax
  int v63; // ecx
  int v64; // edx
  int v65; // esi
  int v66; // eax
  _DWORD *v68; // [esp-Ch] [ebp-654h]
  int v69; // [esp-4h] [ebp-64Ch]
  int v70; // [esp+10h] [ebp-638h]
  int v71; // [esp+10h] [ebp-638h]
  int v72; // [esp+10h] [ebp-638h]
  int v73; // [esp+10h] [ebp-638h]
  bool v74; // [esp+16h] [ebp-632h]
  bool v75; // [esp+17h] [ebp-631h]
  int v76; // [esp+18h] [ebp-630h]
  int v77; // [esp+18h] [ebp-630h]
  int v78; // [esp+18h] [ebp-630h]
  int v79; // [esp+18h] [ebp-630h]
  bool v80; // [esp+1Fh] [ebp-629h]
  int v81; // [esp+20h] [ebp-628h]
  int v82; // [esp+20h] [ebp-628h]
  int v83; // [esp+24h] [ebp-624h]
  int v84; // [esp+28h] [ebp-620h]
  int v85; // [esp+2Ch] [ebp-61Ch]
  int v86; // [esp+30h] [ebp-618h]
  double v87; // [esp+38h] [ebp-610h] BYREF
  int v88[2]; // [esp+40h] [ebp-608h] BYREF
  int v89[2]; // [esp+48h] [ebp-600h] BYREF
  int v90[2]; // [esp+50h] [ebp-5F8h] BYREF
  int v91[6]; // [esp+58h] [ebp-5F0h] BYREF
  int v92[6]; // [esp+70h] [ebp-5D8h] BYREF
  double v93[3]; // [esp+88h] [ebp-5C0h] BYREF
  char String2[64]; // [esp+A0h] [ebp-5A8h] BYREF
  double v95[3]; // [esp+E0h] [ebp-568h] BYREF
  int v96[6]; // [esp+F8h] [ebp-550h] BYREF
  double v97[3]; // [esp+110h] [ebp-538h] BYREF
  int v98[6]; // [esp+128h] [ebp-520h] BYREF
  int v99[6]; // [esp+140h] [ebp-508h] BYREF
  int v100[6]; // [esp+158h] [ebp-4F0h] BYREF
  char String1[64]; // [esp+170h] [ebp-4D8h] BYREF
  char v102[64]; // [esp+1B0h] [ebp-498h] BYREF
  char v103[64]; // [esp+1F0h] [ebp-458h] BYREF
  char String[384]; // [esp+230h] [ebp-418h] BYREF
  int v105; // [esp+3B0h] [ebp-298h]
  char v106; // [esp+3B4h] [ebp-294h]
  int v107; // [esp+3BCh] [ebp-28Ch]
  int v108; // [esp+3C0h] [ebp-288h]
  int v109; // [esp+3C4h] [ebp-284h]
  char Str[384]; // [esp+3C8h] [ebp-280h] BYREF
  char Buffer[256]; // [esp+548h] [ebp-100h] BYREF

  memset(Str, 0, sizeof(Str));
  v105 = 0;
  v109 = 0;
  v107 = 0;
  v108 = 0;
  v106 = 1;
  sub_581700(this);
  remove(FileName);
  v3 = sub_536110();
  v4 = v3;
  v85 = v3;
  if ( !v3 )
  {
    sprintf(Buffer, "Could not open %s\n", a2);
    goto LABEL_139;
  }
  *this = 0;
  this[2] = 0;
  this[4] = 0;
  this[6] = 0;
  if ( sub_5367E0(v3, Str, 384) )
  {
    do
    {
      if ( !sub_577B60(String) )
      {
        if ( strstr(Str, aBody_1) )
          ++*this;
        if ( strstr(Str, aJoint) )
          ++this[2];
        if ( strstr(Str, aHinge) )
          ++this[4];
        if ( strstr(Str, aBar) )
          ++this[6];
        if ( strstr(Str, aJointHinge) )
        {
          v5 = this[4] + 1;
          ++this[2];
          this[4] = v5;
        }
      }
    }
    while ( sub_5367E0(v4, Str, 384) );
  }
  v6 = *this;
  v7 = (int *)operator new(580 * *this + 4);
  if ( v7 )
  {
    v8 = v7 + 1;
    *v7 = v6;
    v9 = v7 + 1;
    if ( v6 - 1 >= 0 )
    {
      do
      {
        sub_57BBC0(v9);
        v9 += 145;
        --v6;
      }
      while ( v6 );
    }
    v4 = v85;
    v10 = v8;
  }
  else
  {
    v10 = 0;
  }
  v11 = this[2];
  this[1] = (int)v10;
  v12 = (int *)operator new(48 * v11 + 4);
  if ( v12 )
  {
    *v12 = v11;
    v13 = v11 - 1;
    v14 = v12 + 1;
    v15 = v12 + 1;
    if ( v13 >= 0 )
    {
      v16 = v13 + 1;
      do
      {
        *v15 = 0;
        v15 += 12;
        --v16;
      }
      while ( v16 );
    }
    v17 = v14;
  }
  else
  {
    v17 = 0;
  }
  v18 = this[4];
  this[3] = (int)v17;
  v19 = (int *)operator new(48 * v18 + 4);
  if ( v19 )
  {
    *v19 = v18;
    v20 = v18 - 1;
    v21 = v19 + 1;
    v22 = v19 + 1;
    if ( v20 >= 0 )
    {
      v23 = v20 + 1;
      do
      {
        *v22 = 0;
        v22 += 12;
        --v23;
      }
      while ( v23 );
    }
    v24 = v21;
  }
  else
  {
    v24 = 0;
  }
  v25 = this[6];
  this[5] = (int)v24;
  v26 = (int *)operator new(72 * v25 + 4);
  if ( v26 )
  {
    *v26 = v25;
    v27 = v25 - 1;
    v28 = v26 + 1;
    v29 = v26 + 1;
    if ( v27 >= 0 )
    {
      v30 = v27 + 1;
      do
      {
        *v29 = 0;
        v29 += 18;
        --v30;
      }
      while ( v30 );
    }
    v31 = v28;
  }
  else
  {
    v31 = 0;
  }
  this[7] = (int)v31;
  v70 = 0;
  v83 = 0;
  sub_5369D0(v4, 0, 0);
  if ( !sub_5367E0(v4, Str, 384) )
  {
LABEL_110:
    v43 = 0;
    if ( *this > 0 )
    {
      v44 = 0;
      do
      {
        sub_57C580((_DWORD *)(v44 + this[1]));
        ++v43;
        v44 += 580;
      }
      while ( v43 < *this );
    }
    this[8] = sub_5801C0(this);
    v71 = 0;
    if ( this[2] > 0 )
    {
      v77 = 0;
      do
      {
        v45 = (_DWORD *)(v77 + this[3]);
        qmemcpy(v93, v45 + 5, sizeof(v93));
        v46 = v45[11];
        v47 = sub_57C5F0(v45[1], v93, v46, 1);
        v48 = v45[3];
        v45[2] = v47;
        v45[4] = sub_57C5F0(v48, v93, v46, 0);
        v45[11] = 0;
        sub_57FD00(v45);
        v49 = ++v71 < this[2];
        v77 += 48;
      }
      while ( v49 );
    }
    v72 = 0;
    if ( this[4] > 0 )
    {
      v78 = 0;
      do
      {
        v50 = v78 + this[5];
        qmemcpy(v93, (const void *)(v50 + 20), sizeof(v93));
        v51 = *(_DWORD *)(v50 + 44);
        v52 = sub_57C670(*(_DWORD **)(v50 + 4), (int)v93, v51, 1, v50);
        v53 = *(_DWORD **)(v50 + 12);
        *(_DWORD *)(v50 + 8) = v52;
        *(_DWORD *)(v50 + 16) = sub_57C670(v53, (int)v93, v51, 0, v50);
        *(_DWORD *)(v50 + 44) = 0;
        sub_57FDB0((_DWORD *)v50);
        v49 = ++v72 < this[4];
        v78 += 48;
      }
      while ( v49 );
    }
    v73 = 0;
    if ( this[6] > 0 )
    {
      v79 = 0;
      do
      {
        v54 = (int *)(v79 + this[7]);
        qmemcpy(v93, v54 + 5, sizeof(v93));
        qmemcpy(v97, v54 + 11, sizeof(v97));
        qmemcpy(v95, v93, sizeof(v95));
        v95[1] = v95[1] - v97[1];
        v95[2] = v95[2] - v97[2];
        v82 = v54[17];
        *(double *)&v55 = sqrt(v95[2] * v95[2] + v95[1] * v95[1] + (v93[0] - v97[0]) * (v93[0] - v97[0]));
        v54[2] = sub_57C720(v54[1], v93, v82, 1, v55, HIDWORD(v55));
        v54[4] = sub_57C720(v54[3], v97, v82, 0, v55, HIDWORD(v55));
        v54[17] = 0;
        sub_580060((int)v54);
        v49 = ++v73 < this[6];
        v79 += 72;
      }
      while ( v49 );
    }
    this[10] = (int)operator new(4 * this[8]);
    v56 = operator new(8 * this[8] * this[8]);
    v57 = this[8];
    this[9] = (int)v56;
    v58 = 0;
    for ( i = 0; i < v57; ++i )
    {
      *(_DWORD *)(this[10] + 4 * i) = this[9] + 8 * i * v57;
      v57 = this[8];
    }
    sub_580610(this, this[10], this[8]);
    this[12] = 0;
    while ( 1 )
    {
      v60 = v58++;
      v61 = sub_58CD19(v60);
      if ( !v61 )
        break;
      if ( (*(unsigned __int8 (__thiscall **)(int, int, int))(*(_DWORD *)v61 + 16))(v61, this[10], this[8]) )
      {
        sub_5BE8AE();
        this[9] = 0;
        sub_5BE8AE();
        this[10] = (*(int (__thiscall **)(int))(*(_DWORD *)v61 + 8))(v61);
        this[11] = (**(int (__thiscall ***)(int))v61)(v61);
        this[12] = v61;
        break;
      }
    }
    if ( !this[12] )
    {
      sub_580610(this, this[10], this[8]);
      v62 = operator new(8 * this[8]);
      v69 = this[8];
      v68 = (_DWORD *)this[10];
      this[11] = (int)v62;
      sub_57F5C0(this + 13, v68, v62, v69);
    }
    v63 = 0;
    if ( *this > 0 )
    {
      v64 = 0;
      do
      {
        v65 = this[11];
        v66 = v64 + this[1];
        *(_DWORD *)(v66 + 552) = this[10];
        *(_DWORD *)(v66 + 548) = v65;
        ++v63;
        v64 += 580;
      }
      while ( v63 < *this );
    }
    sub_536BE0(v85);
    return 0;
  }
  v76 = 0;
  v81 = 0;
  v86 = 0;
  v84 = 0;
  while ( 1 )
  {
    if ( sub_577B60(String) )
      goto LABEL_109;
    if ( !strstr(Str, aBody_1) )
      break;
    memset(v96, 0, sizeof(v96));
    memset(v98, 0, sizeof(v98));
    v88[0] = 0;
    memset(v92, 0, sizeof(v92));
    v88[1] = 1072693248;
    memset(v91, 0, sizeof(v91));
    v89[0] = 0;
    v89[1] = 1072693248;
    v90[0] = 0;
    v90[1] = 1072693248;
    String2[0] = 0;
    v87 = 1.0;
    while ( sub_5367E0(v85, Str, 384) )
    {
      v32 = sub_577B60(String);
      if ( v32 )
      {
        if ( v32 == 1 )
          break;
      }
      else
      {
        if ( sub_577ED0(String, aName_2, String2, 0) )
          _strupr(String2);
        sub_578450((int)String, aMass_0, (int)&v87, 0, 0, 0);
        sub_578450((int)String, aInertia_0, (int)v88, (int)v89, (int)v90, 0);
        sub_578450((int)String, off_61B50C, (int)v91, (int)&v91[2], (int)&v91[4], 0);
        sub_578450((int)String, off_61B508, (int)v92, (int)&v92[2], (int)&v92[4], 0);
        sub_578450((int)String, off_61B504, (int)v98, (int)&v98[2], (int)&v98[4], 0);
        sub_578450((int)String, off_61B500, (int)v96, (int)&v96[2], (int)&v96[4], 0);
      }
    }
    if ( !String2[0] )
    {
      sprintf(Buffer, "Body %d must be named\n", v70);
      goto LABEL_139;
    }
    v33 = 0;
    if ( v84 > 0 )
    {
      v34 = 0;
      while ( _strcmpi(*(const char **)(v34 + this[1]), String2) )
      {
        ++v33;
        v34 += 580;
        if ( v33 >= v70 )
          goto LABEL_57;
      }
      if ( v33 < v70 )
      {
        sprintf(Buffer, "Two bodies named \"%s\"\n", String2);
        goto LABEL_139;
      }
    }
LABEL_57:
    sub_57BC00(v84 + this[1], String2, v87, v88);
    qmemcpy((void *)(this[1] + v84 + 4), v91, 0x18u);
    sub_57BF60(v84 + this[1], (int)v92);
    qmemcpy((void *)(this[1] + v84 + 100), v98, 0x18u);
    sub_57C010(v84 + this[1], v96);
    ++v70;
    v84 += 580;
LABEL_109:
    if ( !sub_5367E0(v85, Str, 384) )
      goto LABEL_110;
  }
  if ( !strstr(Str, aJoint) && !strstr(Str, aHinge) && !strstr(Str, aBar) && !strstr(Str, aJointHinge) )
    goto LABEL_109;
  v74 = strstr(Str, aJoint) != 0;
  v75 = strstr(Str, aHinge) != 0;
  v80 = strstr(Str, aBar) != 0;
  if ( strstr(Str, aJointHinge) )
  {
    v74 = 1;
    v75 = 1;
  }
  memset(v92, 0, sizeof(v92));
  memset(v91, 0, sizeof(v91));
  String2[0] = 0;
  v102[0] = 0;
  v103[0] = 0;
  String1[0] = 0;
  while ( sub_5367E0(v85, Str, 384) )
  {
    v35 = sub_577B60(String);
    if ( v35 )
    {
      if ( v35 == 1 )
        break;
    }
    else
    {
      if ( sub_577ED0(String, aName_2, String2, 0) )
        _strupr(String2);
      sub_577ED0(String, aPosbody, v102, 0);
      sub_577ED0(String, aNegbody, v103, 0);
      sub_578450((int)String, aAxis, (int)v92, (int)&v92[2], (int)&v92[4], 0);
      sub_578450((int)String, off_61B4E4, (int)v99, (int)&v99[2], (int)&v99[4], 0);
      v106 = 0;
      if ( sub_578450((int)String, off_61B50C, (int)v100, (int)&v100[2], (int)&v100[4], 0) )
        qmemcpy(v91, v100, sizeof(v91));
      else
        sub_577ED0(String, off_61B50C, String1, 0);
      v106 = 1;
    }
  }
  if ( String1[0] )
  {
    v36 = 0;
    if ( v84 > 0 )
    {
      v37 = 0;
      do
      {
        if ( !_strcmpi(String1, *(const char **)(v37 + this[1])) )
          break;
        ++v36;
        v37 += 580;
      }
      while ( v36 < v70 );
    }
    if ( v36 == v70 )
    {
      sprintf(Buffer, "Invalid copy body name \"%s\" in hinge or joint\n", String1);
      sub_580680(Buffer);
      return -1;
    }
    qmemcpy(v91, (const void *)(580 * v36 + this[1] + 4), sizeof(v91));
  }
  v38 = 0;
  if ( v84 > 0 )
  {
    v39 = 0;
    do
    {
      if ( !_strcmpi(v102, *(const char **)(v39 + this[1])) )
        break;
      ++v38;
      v39 += 580;
    }
    while ( v38 < v70 );
  }
  if ( v38 == v70 )
  {
    sprintf(Buffer, "Invalid body name \"%s\" in hinge or joint\n", v102);
    sub_580680(Buffer);
    return -1;
  }
  if ( v74 )
  {
    *(_DWORD *)(this[3] + v86 + 4) = 580 * v38 + this[1];
    ++*(_DWORD *)(580 * v38 + this[1] + 556);
  }
  if ( v75 )
  {
    *(_DWORD *)(this[5] + v81 + 4) = 580 * v38 + this[1];
    ++*(_DWORD *)(580 * v38 + this[1] + 564);
  }
  if ( v80 )
  {
    v40 = 580 * v38;
    *(_DWORD *)(v76 + this[7] + 4) = v40 + this[1];
    *(_DWORD *)(v40 + this[1] + 572) = *(_DWORD *)(this[1] + v40 + 572) + 1;
  }
  v41 = 0;
  if ( v84 > 0 )
  {
    v42 = 0;
    do
    {
      if ( !_strcmpi(v103, *(const char **)(v42 + this[1])) )
        break;
      ++v41;
      v42 += 580;
    }
    while ( v41 < v70 );
  }
  if ( v41 != v70 )
  {
    if ( v74 )
    {
      *(_DWORD *)(this[3] + v86 + 12) = 580 * v41 + this[1];
      *(_DWORD *)(580 * v41 + this[1] + 556) = *(_DWORD *)(this[1] + 580 * v41 + 556) + 1;
      if ( String2[0] )
      {
        *(_DWORD *)(v86 + this[3]) = operator new(strlen(String2) + 1);
        strcpy(*(char **)(v86 + this[3]), String2);
      }
      qmemcpy((void *)(this[3] + v86 + 20), v91, 0x18u);
      *(_DWORD *)(this[3] + v86 + 44) = v83++;
      v86 += 48;
    }
    if ( v75 )
    {
      *(_DWORD *)(this[5] + v81 + 12) = 580 * v41 + this[1];
      *(_DWORD *)(580 * v41 + this[1] + 564) = *(_DWORD *)(this[1] + 580 * v41 + 564) + 1;
      if ( String2[0] )
      {
        *(_DWORD *)(v81 + this[5]) = operator new(strlen(String2) + 1);
        strcpy(*(char **)(v81 + this[5]), String2);
      }
      qmemcpy((void *)(this[5] + v81 + 20), v92, 0x18u);
      *(_DWORD *)(this[5] + v81 + 44) = v83++;
      v81 += 48;
    }
    if ( v80 )
    {
      *(_DWORD *)(v76 + this[7] + 12) = 580 * v41 + this[1];
      *(_DWORD *)(580 * v41 + this[1] + 572) = *(_DWORD *)(this[1] + 580 * v41 + 572) + 1;
      if ( String2[0] )
      {
        *(_DWORD *)(v76 + this[7]) = operator new(strlen(String2) + 1);
        strcpy(*(char **)(v76 + this[7]), String2);
      }
      qmemcpy((void *)(v76 + this[7] + 20), v91, 0x18u);
      qmemcpy((void *)(v76 + this[7] + 44), v99, 0x18u);
      *(_DWORD *)(v76 + this[7] + 68) = v83++;
      v76 += 72;
    }
    goto LABEL_109;
  }
  sprintf(Buffer, "Invalid body name \"%s\" in hinge or joint\n", v103);
LABEL_139:
  sub_580680(Buffer);
  return -1;
}
