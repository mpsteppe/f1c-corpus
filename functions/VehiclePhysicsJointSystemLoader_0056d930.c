int __thiscall sub_56D930(int *this, int a2)
{
  int v3; // eax
  int v4; // edi
  int v5; // eax
  int v6; // esi
  _DWORD *v7; // eax
  _DWORD *v8; // ebx
  _DWORD *v9; // edi
  _DWORD *v10; // eax
  int v11; // esi
  _DWORD *v12; // eax
  int v13; // esi
  _DWORD *v14; // edx
  _DWORD *v15; // eax
  int v16; // ecx
  _DWORD *v17; // eax
  int v18; // esi
  _DWORD *v19; // eax
  int v20; // esi
  _DWORD *v21; // edx
  _DWORD *v22; // eax
  int v23; // ecx
  _DWORD *v24; // eax
  int v25; // esi
  _DWORD *v26; // eax
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
  int v56; // eax
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
  void *v69; // [esp-8h] [ebp-650h]
  int v70; // [esp-4h] [ebp-64Ch]
  int v71; // [esp+10h] [ebp-638h]
  int v72; // [esp+10h] [ebp-638h]
  int v73; // [esp+10h] [ebp-638h]
  int v74; // [esp+10h] [ebp-638h]
  bool v75; // [esp+16h] [ebp-632h]
  bool v76; // [esp+17h] [ebp-631h]
  int v77; // [esp+18h] [ebp-630h]
  int v78; // [esp+18h] [ebp-630h]
  int v79; // [esp+18h] [ebp-630h]
  int v80; // [esp+18h] [ebp-630h]
  bool v81; // [esp+1Fh] [ebp-629h]
  int v82; // [esp+20h] [ebp-628h]
  int v83; // [esp+20h] [ebp-628h]
  int v84; // [esp+24h] [ebp-624h]
  int v85; // [esp+28h] [ebp-620h]
  int v86; // [esp+2Ch] [ebp-61Ch]
  int v87; // [esp+30h] [ebp-618h]
  double v88; // [esp+38h] [ebp-610h] BYREF
  int v89[2]; // [esp+40h] [ebp-608h] BYREF
  _DWORD v90[2]; // [esp+48h] [ebp-600h] BYREF
  _DWORD v91[2]; // [esp+50h] [ebp-5F8h] BYREF
  _BYTE v92[24]; // [esp+58h] [ebp-5F0h] BYREF
  _BYTE v93[24]; // [esp+70h] [ebp-5D8h] BYREF
  double v94[3]; // [esp+88h] [ebp-5C0h] BYREF
  CHAR SrcStr[64]; // [esp+A0h] [ebp-5A8h] BYREF
  double v96[3]; // [esp+E0h] [ebp-568h] BYREF
  _BYTE v97[24]; // [esp+F8h] [ebp-550h] BYREF
  double v98[3]; // [esp+110h] [ebp-538h] BYREF
  _BYTE v99[24]; // [esp+128h] [ebp-520h] BYREF
  _BYTE v100[24]; // [esp+140h] [ebp-508h] BYREF
  _BYTE v101[24]; // [esp+158h] [ebp-4F0h] BYREF
  char v102[64]; // [esp+170h] [ebp-4D8h] BYREF
  char v103[64]; // [esp+1B0h] [ebp-498h] BYREF
  CHAR v104[64]; // [esp+1F0h] [ebp-458h] BYREF
  char v105[384]; // [esp+230h] [ebp-418h] BYREF
  int v106; // [esp+3B0h] [ebp-298h]
  char v107; // [esp+3B4h] [ebp-294h]
  int v108; // [esp+3BCh] [ebp-28Ch]
  int v109; // [esp+3C0h] [ebp-288h]
  int v110; // [esp+3C4h] [ebp-284h]
  char v111[384]; // [esp+3C8h] [ebp-280h] BYREF
  _BYTE v112[256]; // [esp+548h] [ebp-100h] BYREF

  memset(v111, 0, sizeof(v111));
  v106 = 0;
  v110 = 0;
  v108 = 0;
  v109 = 0;
  v107 = 1;
  sub_56E970(this);
  FileDeleteWithErrorHandling(aPmodelErrorTxt);
  v3 = sub_534B00();
  v4 = v3;
  v86 = v3;
  if ( !v3 )
  {
    StringFormatWithBufferOverflowCheck(v112, "Could not open %s\n", a2);
    goto LABEL_139;
  }
  *this = 0;
  this[2] = 0;
  this[4] = 0;
  this[6] = 0;
  if ( LineInputReader(v3, v111, 384) )
  {
    do
    {
      if ( !sub_5651B0(v105) )
      {
        if ( sub_587C20(v111, aBody_1) )
          ++*this;
        if ( sub_587C20(v111, aJoint) )
          ++this[2];
        if ( sub_587C20(v111, aHinge) )
          ++this[4];
        if ( sub_587C20(v111, aBar) )
          ++this[6];
        if ( sub_587C20(v111, aJointHinge) )
        {
          v5 = this[4] + 1;
          ++this[2];
          this[4] = v5;
        }
      }
    }
    while ( LineInputReader(v4, v111, 384) );
  }
  v6 = *this;
  v7 = (_DWORD *)OperatorNewNhMallocWrapper(580 * *this + 4);
  if ( v7 )
  {
    v8 = v7 + 1;
    *v7 = v6;
    v9 = v7 + 1;
    if ( v6 - 1 >= 0 )
    {
      do
      {
        ShortComputation_8e30(v9);
        v9 += 145;
        --v6;
      }
      while ( v6 );
    }
    v4 = v86;
    v10 = v8;
  }
  else
  {
    v10 = 0;
  }
  v11 = this[2];
  this[1] = (int)v10;
  v12 = (_DWORD *)OperatorNewNhMallocWrapper(48 * v11 + 4);
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
  v19 = (_DWORD *)OperatorNewNhMallocWrapper(48 * v18 + 4);
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
  v26 = (_DWORD *)OperatorNewNhMallocWrapper(72 * v25 + 4);
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
  v71 = 0;
  v84 = 0;
  AudioStreamBufferRead(v4, 0, 0);
  if ( !LineInputReader(v4, v111, 384) )
  {
LABEL_110:
    v43 = 0;
    if ( *this > 0 )
    {
      v44 = 0;
      do
      {
        TripleBufferAllocation((_DWORD *)(v44 + this[1]));
        ++v43;
        v44 += 580;
      }
      while ( v43 < *this );
    }
    this[8] = sub_56D430(this);
    v72 = 0;
    if ( this[2] > 0 )
    {
      v78 = 0;
      do
      {
        v45 = (_DWORD *)(v78 + this[3]);
        qmemcpy(v94, v45 + 5, sizeof(v94));
        v46 = v45[11];
        v47 = F_3DPositionDeltaToBodyFrameVectorTransform(v45[1], v94, v46, 1);
        v48 = v45[3];
        v45[2] = v47;
        v45[4] = F_3DPositionDeltaToBodyFrameVectorTransform(v48, v94, v46, 0);
        v45[11] = 0;
        F_3x3MatrixVectorMultiply(v45);
        v49 = ++v72 < this[2];
        v78 += 48;
      }
      while ( v49 );
    }
    v73 = 0;
    if ( this[4] > 0 )
    {
      v79 = 0;
      do
      {
        v50 = v79 + this[5];
        qmemcpy(v94, (const void *)(v50 + 20), sizeof(v94));
        v51 = *(_DWORD *)(v50 + 44);
        v52 = BufferEntryAppendWithMatrixInit(*(_DWORD **)(v50 + 4), (int)v94, v51, 1, v50);
        v53 = *(_DWORD **)(v50 + 12);
        *(_DWORD *)(v50 + 8) = v52;
        *(_DWORD *)(v50 + 16) = BufferEntryAppendWithMatrixInit(v53, (int)v94, v51, 0, v50);
        *(_DWORD *)(v50 + 44) = 0;
        F_3x3MatrixInverseCoordinateTransform((_DWORD *)v50);
        v49 = ++v73 < this[4];
        v79 += 48;
      }
      while ( v49 );
    }
    v74 = 0;
    if ( this[6] > 0 )
    {
      v80 = 0;
      do
      {
        v54 = (int *)(v80 + this[7]);
        qmemcpy(v94, v54 + 5, sizeof(v94));
        qmemcpy(v98, v54 + 11, sizeof(v98));
        qmemcpy(v96, v94, sizeof(v96));
        v96[1] = v96[1] - v98[1];
        v96[2] = v96[2] - v98[2];
        v83 = v54[17];
        *(double *)&v55 = sqrt(v96[2] * v96[2] + v96[1] * v96[1] + (v94[0] - v98[0]) * (v94[0] - v98[0]));
        v54[2] = F_3DVectorTransformWithBufferWrite(v54[1], v94, v83, 1, v55, HIDWORD(v55));
        v54[4] = F_3DVectorTransformWithBufferWrite(v54[3], v98, v83, 0, v55, HIDWORD(v55));
        v54[17] = 0;
        sub_56D2D0((int)v54);
        v49 = ++v74 < this[6];
        v80 += 72;
      }
      while ( v49 );
    }
    this[10] = OperatorNewNhMallocWrapper(4 * this[8]);
    v56 = OperatorNewNhMallocWrapper(8 * this[8] * this[8]);
    v57 = this[8];
    this[9] = v56;
    v58 = 0;
    for ( i = 0; i < v57; ++i )
    {
      *(_DWORD *)(this[10] + 4 * i) = this[9] + 8 * i * v57;
      v57 = this[8];
    }
    ZeroFillArraysAndCallInitRoutineRepeatedly(this, this[10], this[8]);
    this[12] = 0;
    while ( 1 )
    {
      v60 = v58++;
      v61 = sub_579F89(v60);
      if ( !v61 )
        break;
      if ( (*(unsigned __int8 (__thiscall **)(int, int, int))(*(_DWORD *)v61 + 16))(v61, this[10], this[8]) )
      {
        FreeWrapper_7bcf((LPVOID)this[9]);
        v69 = (void *)this[10];
        this[9] = 0;
        FreeWrapper_7bcf(v69);
        this[10] = (*(int (__thiscall **)(int))(*(_DWORD *)v61 + 8))(v61);
        this[11] = (**(int (__thiscall ***)(int))v61)(v61);
        this[12] = v61;
        break;
      }
    }
    if ( !this[12] )
    {
      ZeroFillArraysAndCallInitRoutineRepeatedly(this, this[10], this[8]);
      v62 = (_DWORD *)OperatorNewNhMallocWrapper(8 * this[8]);
      v70 = this[8];
      v68 = (_DWORD *)this[10];
      this[11] = (int)v62;
      sub_56C830(this + 13, v68, v62, v70);
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
    StreamFileTypeCheckWithDispatch(v86);
    return 0;
  }
  v77 = 0;
  v82 = 0;
  v87 = 0;
  v85 = 0;
  while ( 1 )
  {
    if ( sub_5651B0(v105) )
      goto LABEL_109;
    if ( !sub_587C20(v111, aBody_1) )
      break;
    memset(v97, 0, sizeof(v97));
    memset(v99, 0, sizeof(v99));
    v89[0] = 0;
    memset(v93, 0, sizeof(v93));
    v89[1] = 1072693248;
    memset(v92, 0, sizeof(v92));
    v90[0] = 0;
    v90[1] = 1072693248;
    v91[0] = 0;
    v91[1] = 1072693248;
    SrcStr[0] = 0;
    v88 = 1.0;
    while ( LineInputReader(v86, v111, 384) )
    {
      v32 = sub_5651B0(v105);
      if ( v32 )
      {
        if ( v32 == 1 )
          break;
      }
      else
      {
        if ( sub_565520((int)v105, (int)aName_0, SrcStr, 0) )
          sub_589901(SrcStr);
        sub_565AA0(aMass_0, &v88, 0, 0, 0);
        sub_565AA0(aInertia_0, v89, v90, v91, 0);
        sub_565AA0(&off_5E5314, v92, &v92[8], &v92[16], 0);
        sub_565AA0(&off_5E5310, v93, &v93[8], &v93[16], 0);
        sub_565AA0(&off_5E530C, v99, &v99[8], &v99[16], 0);
        sub_565AA0(&off_5E5308, v97, &v97[8], &v97[16], 0);
      }
    }
    if ( !SrcStr[0] )
    {
      StringFormatWithBufferOverflowCheck(v112, "Body %d must be named\n", v71);
      goto LABEL_139;
    }
    v33 = 0;
    if ( v85 > 0 )
    {
      v34 = 0;
      while ( sub_588410(*(_DWORD *)(v34 + this[1]), SrcStr) )
      {
        ++v33;
        v34 += 580;
        if ( v33 >= v71 )
          goto LABEL_57;
      }
      if ( v33 < v71 )
      {
        StringFormatWithBufferOverflowCheck(v112, "Two bodies named \"%s\"\n", SrcStr);
        goto LABEL_139;
      }
    }
LABEL_57:
    sub_568E70(v85 + this[1], SrcStr, v88, v89);
    qmemcpy((void *)(this[1] + v85 + 4), v92, 0x18u);
    F_3x3RotationTensorMatrixTransform(v85 + this[1], (int)v93);
    qmemcpy((void *)(this[1] + v85 + 100), v99, 0x18u);
    Copy6DwordsToStructCall(v85 + this[1], v97);
    ++v71;
    v85 += 580;
LABEL_109:
    if ( !LineInputReader(v86, v111, 384) )
      goto LABEL_110;
  }
  if ( !sub_587C20(v111, aJoint)
    && !sub_587C20(v111, aHinge)
    && !sub_587C20(v111, aBar)
    && !sub_587C20(v111, aJointHinge) )
  {
    goto LABEL_109;
  }
  v75 = sub_587C20(v111, aJoint) != 0;
  v76 = sub_587C20(v111, aHinge) != 0;
  v81 = sub_587C20(v111, aBar) != 0;
  if ( sub_587C20(v111, aJointHinge) )
  {
    v75 = 1;
    v76 = 1;
  }
  memset(v93, 0, sizeof(v93));
  memset(v92, 0, sizeof(v92));
  SrcStr[0] = 0;
  v103[0] = 0;
  v104[0] = 0;
  v102[0] = 0;
  while ( LineInputReader(v86, v111, 384) )
  {
    v35 = sub_5651B0(v105);
    if ( v35 )
    {
      if ( v35 == 1 )
        break;
    }
    else
    {
      if ( sub_565520((int)v105, (int)aName_0, SrcStr, 0) )
        sub_589901(SrcStr);
      sub_565520((int)v105, (int)aPosbody, v103, 0);
      sub_565520((int)v105, (int)aNegbody, v104, 0);
      sub_565AA0(aAxis, v93, &v93[8], &v93[16], 0);
      sub_565AA0(&off_5E52EC, v100, &v100[8], &v100[16], 0);
      v107 = 0;
      if ( sub_565AA0(&off_5E5314, v101, &v101[8], &v101[16], 0) )
        qmemcpy(v92, v101, sizeof(v92));
      else
        sub_565520((int)v105, (int)&off_5E5314, v102, 0);
      v107 = 1;
    }
  }
  if ( v102[0] )
  {
    v36 = 0;
    if ( v85 > 0 )
    {
      v37 = 0;
      do
      {
        if ( !sub_588410(v102, *(_DWORD *)(v37 + this[1])) )
          break;
        ++v36;
        v37 += 580;
      }
      while ( v36 < v71 );
    }
    if ( v36 == v71 )
    {
      StringFormatWithBufferOverflowCheck(v112, "Invalid copy body name \"%s\" in hinge or joint\n", v102);
      sub_56D8F0();
      return -1;
    }
    qmemcpy(v92, (const void *)(580 * v36 + this[1] + 4), sizeof(v92));
  }
  v38 = 0;
  if ( v85 > 0 )
  {
    v39 = 0;
    do
    {
      if ( !sub_588410(v103, *(_DWORD *)(v39 + this[1])) )
        break;
      ++v38;
      v39 += 580;
    }
    while ( v38 < v71 );
  }
  if ( v38 == v71 )
  {
    StringFormatWithBufferOverflowCheck(v112, "Invalid body name \"%s\" in hinge or joint\n", v103);
    sub_56D8F0();
    return -1;
  }
  if ( v75 )
  {
    *(_DWORD *)(this[3] + v87 + 4) = 580 * v38 + this[1];
    ++*(_DWORD *)(580 * v38 + this[1] + 556);
  }
  if ( v76 )
  {
    *(_DWORD *)(this[5] + v82 + 4) = 580 * v38 + this[1];
    ++*(_DWORD *)(580 * v38 + this[1] + 564);
  }
  if ( v81 )
  {
    v40 = 580 * v38;
    *(_DWORD *)(v77 + this[7] + 4) = v40 + this[1];
    *(_DWORD *)(v40 + this[1] + 572) = *(_DWORD *)(this[1] + v40 + 572) + 1;
  }
  v41 = 0;
  if ( v85 > 0 )
  {
    v42 = 0;
    do
    {
      if ( !sub_588410(v104, *(_DWORD *)(v42 + this[1])) )
        break;
      ++v41;
      v42 += 580;
    }
    while ( v41 < v71 );
  }
  if ( v41 != v71 )
  {
    if ( v75 )
    {
      *(_DWORD *)(this[3] + v87 + 12) = 580 * v41 + this[1];
      *(_DWORD *)(580 * v41 + this[1] + 556) = *(_DWORD *)(this[1] + 580 * v41 + 556) + 1;
      if ( SrcStr[0] )
      {
        *(_DWORD *)(v87 + this[3]) = OperatorNewNhMallocWrapper(strlen(SrcStr) + 1);
        strcpy(*(char **)(v87 + this[3]), SrcStr);
      }
      qmemcpy((void *)(this[3] + v87 + 20), v92, 0x18u);
      *(_DWORD *)(this[3] + v87 + 44) = v84++;
      v87 += 48;
    }
    if ( v76 )
    {
      *(_DWORD *)(this[5] + v82 + 12) = 580 * v41 + this[1];
      *(_DWORD *)(580 * v41 + this[1] + 564) = *(_DWORD *)(this[1] + 580 * v41 + 564) + 1;
      if ( SrcStr[0] )
      {
        *(_DWORD *)(v82 + this[5]) = OperatorNewNhMallocWrapper(strlen(SrcStr) + 1);
        strcpy(*(char **)(v82 + this[5]), SrcStr);
      }
      qmemcpy((void *)(this[5] + v82 + 20), v93, 0x18u);
      *(_DWORD *)(this[5] + v82 + 44) = v84++;
      v82 += 48;
    }
    if ( v81 )
    {
      *(_DWORD *)(v77 + this[7] + 12) = 580 * v41 + this[1];
      *(_DWORD *)(580 * v41 + this[1] + 572) = *(_DWORD *)(this[1] + 580 * v41 + 572) + 1;
      if ( SrcStr[0] )
      {
        *(_DWORD *)(v77 + this[7]) = OperatorNewNhMallocWrapper(strlen(SrcStr) + 1);
        strcpy(*(char **)(v77 + this[7]), SrcStr);
      }
      qmemcpy((void *)(v77 + this[7] + 20), v92, 0x18u);
      qmemcpy((void *)(v77 + this[7] + 44), v100, 0x18u);
      *(_DWORD *)(v77 + this[7] + 68) = v84++;
      v77 += 72;
    }
    goto LABEL_109;
  }
  StringFormatWithBufferOverflowCheck(v112, "Invalid body name \"%s\" in hinge or joint\n", v104);
LABEL_139:
  sub_56D8F0();
  return -1;
}
