int __thiscall sub_4DFCE0(void **this, const char *a2, char a3)
{
  void *v4; // eax
  void **v5; // esi
  _DWORD *v6; // edi
  void *v7; // eax
  void *v8; // eax
  void *v9; // eax
  void *v10; // eax
  int v11; // esi
  _DWORD *v12; // ebx
  int v13; // ecx
  int v14; // edx
  int *v15; // eax
  int v16; // eax
  int v17; // esi
  int v18; // ebx
  int v19; // edi
  bool v20; // zf
  int v21; // esi
  int *v22; // edi
  void *v23; // eax
  void *v24; // eax
  void *v25; // eax
  void *v26; // eax
  void *v27; // eax
  void *v28; // eax
  void *v29; // eax
  void *v30; // ecx
  void *v31; // edx
  void *v32; // ecx
  void *v33; // ecx
  void *v34; // eax
  void **v35; // ebx
  void *v36; // ecx
  void *v37; // ecx
  void *v38; // ecx
  void *v39; // ecx
  int v40; // eax
  int v41; // esi
  _DWORD *v42; // edi
  int v43; // eax
  int v44; // ebx
  _DWORD *v45; // edi
  char *v46; // esi
  int v47; // eax
  void **v48; // eax
  int v49; // edi
  char *v50; // esi
  int v51; // ecx
  double v52; // st7
  double v53; // st7
  _DWORD *v54; // edx
  int k; // esi
  void *v56; // eax
  int result; // eax
  int v58; // ebx
  int v59; // esi
  int v60; // esi
  void *v61; // ecx
  double v62; // st7
  int v63; // edx
  float v64; // ecx
  float v65; // eax
  void *v66; // ecx
  void *v67; // [esp-4h] [ebp-1C0h]
  void *v68; // [esp-4h] [ebp-1C0h]
  void *v69; // [esp-4h] [ebp-1C0h]
  void *v70; // [esp-4h] [ebp-1C0h]
  void *v71; // [esp-4h] [ebp-1C0h]
  void *v72; // [esp-4h] [ebp-1C0h]
  void *v73; // [esp-4h] [ebp-1C0h]
  void *v74; // [esp-4h] [ebp-1C0h]
  void *v75; // [esp-4h] [ebp-1C0h]
  void *v76; // [esp-4h] [ebp-1C0h]
  int v77; // [esp+10h] [ebp-1ACh] BYREF
  int v78; // [esp+14h] [ebp-1A8h]
  _DWORD *v79; // [esp+18h] [ebp-1A4h]
  int i; // [esp+1Ch] [ebp-1A0h]
  int j; // [esp+20h] [ebp-19Ch]
  float v82; // [esp+24h] [ebp-198h] BYREF
  float v83; // [esp+28h] [ebp-194h] BYREF
  float v84; // [esp+2Ch] [ebp-190h] BYREF
  float v85; // [esp+30h] [ebp-18Ch]
  float v86; // [esp+34h] [ebp-188h]
  float v87; // [esp+38h] [ebp-184h]
  _BYTE v88[64]; // [esp+3Ch] [ebp-180h] BYREF
  char v89[64]; // [esp+7Ch] [ebp-140h] BYREF
  char v90[256]; // [esp+BCh] [ebp-100h] BYREF

  v90[0] = 0;
  v89[0] = 0;
  if ( sub_55B6B0(a2) )
  {
    StringRelocationCopy(0, v90);
    if ( StringSplitLoop(dword_8AD25C, 1, (int)aDDevF119992002_6, 1697) )
      DebugLogWrite((int)dword_8AD25C, (int)"Unable to read %s: %s", a2, v90);
  }
  if ( a3 )
  {
    if ( VertexBufferResourceAllocation(dword_8AFE88) )
    {
      StringRelocationCopy(0, v90);
      if ( StringSplitLoop(dword_8AD25C, 1, (int)aDDevF119992002_6, 1708) )
        DebugLogWrite((int)dword_8AD25C, (int)"Unable to setup after reading %s: %s", a2, v90);
    }
    sub_4E2A60(this);
    sub_4CEF30(&dword_8ACEA0);
  }
  StringFormatWithBufferOverflowCheck(v89, "SLOT%03d", *((_DWORD *)*this + 4645));
  v4 = (void *)EvaluateSceneNodeProperty(v89, 0);
  v5 = this + 1;
  this[1] = v4;
  if ( !v4 && StringSplitLoop(dword_8AD25C, 1, (int)aDDevF119992002_6, 1724) )
    DebugLogWrite((int)dword_8AD25C, (int)"Could not find instance \"%s\"", v89);
  FlagFieldBitManipulation(1, 1, 0, 0);
  ConditionalAudioParamSetup((int *)this + 1, 0, 0, 9);
  RenderFlagSetter(*((_DWORD *)*this + 4645), 2048);
  BoundingBoxComputation(*v5, (float *)this + 30, (float *)this + 33);
  SceneNodeVisibilityToggle(0);
  v6 = this + 81;
  this[81] = (void *)EvaluateSceneNodeProperty(aLftire, *v5);
  v7 = (void *)EvaluateSceneNodeProperty(aLfspindle, *v5);
  v67 = *v5;
  this[98] = v7;
  v8 = (void *)EvaluateSceneNodeProperty(aRftire, v67);
  v68 = *v5;
  this[155] = v8;
  this[172] = (void *)EvaluateSceneNodeProperty(aRfspindle, v68);
  v9 = (void *)EvaluateSceneNodeProperty(aLrtire, *v5);
  v69 = *v5;
  this[229] = v9;
  v10 = (void *)EvaluateSceneNodeProperty(aLrspindle, v69);
  v70 = *v5;
  this[246] = v10;
  this[303] = (void *)EvaluateSceneNodeProperty(aRrtire, v70);
  this[320] = (void *)EvaluateSceneNodeProperty(aRrspindle, *v5);
  v11 = 4;
  do
  {
    PhysicsAudioVectorUpdate(*v6, v6[17]);
    v6 += 74;
    --v11;
  }
  while ( v11 );
  v79 = this + 99;
  v77 = 4;
  do
  {
    v12 = v79;
    ConditionalAudioParamSetup(v79 - 18, 1, 0, 3);
    ConditionalAudioParamSetup(v79 - 1, 1, 0, 5);
    if ( !*(v79 - 1) )
    {
      *v79 = *(v79 - 17);
      v13 = *(v12 - 15);
      v12[1] = *(v12 - 16);
      v12[2] = v13;
      v12[3] = *(v12 - 14);
      v14 = *(v12 - 12);
      v12[4] = *(v12 - 13);
      qmemcpy(v12 + 6, v12 - 11, 0x24u);
      v12[5] = v14;
    }
    v12[23] = 0;
    v12[21] = 0;
    v12[22] = 0;
    for ( i = 0; i < 2; ++i )
    {
      if ( i )
        v15 = v79 - 18;
      else
        v15 = v79 - 1;
      v16 = *v15;
      v78 = v16;
      if ( v16 )
      {
        for ( j = SceneGraphChildCount(v16) - 1; j >= 0; --j )
        {
          v17 = LinkedListIndexedAccessor_c230(j);
          v18 = CameraDistanceGetter(v17);
          v19 = 0;
          if ( v18 > 0 )
          {
            while ( 1 )
            {
              if ( ArrayIndexRead(v19) )
              {
                v88[0] = 0;
                ArithmeticComparison_7370(v88);
                if ( !sub_588410(v88, aDiscglow) )
                  break;
              }
              if ( ++v19 >= v18 )
                goto LABEL_31;
            }
            if ( v79[21] )
            {
              v79[22] = v17;
              j = 0;
              i = 1;
            }
            else
            {
              v79[21] = v17;
            }
          }
LABEL_31:
          ;
        }
      }
    }
    v20 = v77 == 1;
    v79 += 74;
    --v77;
  }
  while ( !v20 );
  this[377] = (void *)EvaluateSceneNodeProperty(aFwing, this[1]);
  ConditionalAudioParamSetup((int *)this + 377, 1, 1, 4);
  this[394] = (void *)EvaluateSceneNodeProperty(aRwing, this[1]);
  ConditionalAudioParamSetup((int *)this + 394, 1, 1, 4);
  v21 = 0;
  v22 = (int *)(this + 411);
  do
  {
    StringFormatWithBufferOverflowCheck(v88, "DEBRIS%d", v21);
    *v22 = EvaluateSceneNodeProperty(v88, this[1]);
    ConditionalAudioParamSetup(v22, 1, 1, 5);
    ++v21;
    v22 += 17;
  }
  while ( v21 < 8 );
  this[547] = (void *)EvaluateSceneNodeProperty(aCockpit, this[1]);
  v23 = (void *)EvaluateSceneNodeProperty(aSuspension_0, this[1]);
  v71 = this[1];
  this[548] = v23;
  v24 = (void *)EvaluateSceneNodeProperty(aHelmet, v71);
  v72 = this[1];
  this[549] = v24;
  this[550] = (void *)EvaluateSceneNodeProperty(aArms, v72);
  v25 = (void *)EvaluateSceneNodeProperty(aBody, this[1]);
  v73 = this[1];
  this[551] = v25;
  v26 = (void *)EvaluateSceneNodeProperty(aWheel, v73);
  v74 = this[1];
  this[552] = v26;
  this[553] = (void *)EvaluateSceneNodeProperty(aRainlight, v74);
  v27 = (void *)EvaluateSceneNodeProperty(aBrakelight, this[1]);
  v75 = this[1];
  this[554] = v27;
  v28 = (void *)EvaluateSceneNodeProperty(aHeadlight, v75);
  v76 = this[1];
  this[555] = v28;
  v29 = (void *)EvaluateSceneNodeProperty(aBackfire, v76);
  v30 = this[549];
  this[556] = v29;
  this[588] = 0;
  if ( v30 )
    TripleFieldQuery(this + 588, &v77, &v77);
  VertexClusteringLODGrouping(this);
  sub_4E3360(this);
  v31 = this[31];
  this[24] = this[30];
  v32 = this[32];
  this[25] = v31;
  this[26] = v32;
  v33 = this[34];
  this[27] = this[33];
  v34 = this[35];
  this[28] = v33;
  this[29] = v34;
  v35 = this + 98;
  v77 = 4;
  do
  {
    v36 = *(v35 - 17);
    if ( v36 )
      BoundingBoxUpdate(v36, (float *)this + 24, (float *)this + 27);
    if ( *v35 )
      BoundingBoxUpdate(*v35, (float *)this + 24, (float *)this + 27);
    v35 += 74;
    --v77;
  }
  while ( v77 );
  v37 = this[377];
  if ( v37 )
    BoundingBoxUpdate(v37, (float *)this + 24, (float *)this + 27);
  v38 = this[394];
  if ( v38 )
    BoundingBoxUpdate(v38, (float *)this + 24, (float *)this + 27);
  v39 = this[550];
  this[557] = 0;
  if ( v39 )
  {
    v40 = SceneGraphChildCount(v39);
    this[557] = (void *)v40;
    if ( v40 > 2 )
      this[557] = (void *)2;
    v41 = 0;
    if ( (int)this[557] > 0 )
    {
      v42 = this + 558;
      do
        *v42++ = LinkedListIndexedAccessor_c230(v41++);
      while ( v41 < (int)this[557] );
    }
  }
  v43 = (int)this[557];
  this[560] = 0;
  if ( v43 > 0 )
  {
    v44 = 0;
    v45 = this + 561;
    v46 = (char *)(this + 558);
    do
    {
      v47 = WideStringComparisonWalkingLinkedList(aCatsteer);
      *v45 = v47;
      if ( v47 )
        this[560] = (char *)this[560] + 1;
      ++v44;
      v46 += 4;
      v45 += 4;
    }
    while ( v44 < (int)this[557] );
  }
  v48 = (void **)(dword_8AC394 + 1060 * *((_DWORD *)*this + 4646));
  this[570] = v48[17];
  this[571] = v48[18];
  this[572] = v48[19];
  this[573] = v48[14];
  this[574] = v48[15];
  this[575] = v48[16];
  v49 = 0;
  this[576] = 0;
  this[577] = 0;
  this[578] = 0;
  this[579] = 0;
  this[580] = 0;
  this[581] = 0;
  this[596] = 0;
  this[582] = v48[20];
  this[583] = v48[21];
  this[584] = v48[22];
  this[585] = v48[23];
  this[586] = v48[24];
  this[587] = v48[25];
  v48 += 26;
  this[598] = *v48;
  this[599] = v48[1];
  this[600] = v48[2];
  v50 = (char *)(this + 119);
  v77 = 4;
  do
  {
    v51 = *((_DWORD *)v50 - 38);
    *((_DWORD *)v50 - 3) = 0;
    if ( v51 )
    {
      TripleFieldQuery(v50 - 8, v50 - 4, v50);
      BoundingBoxComputation(*((void **)v50 - 38), (float *)v50 - 66, (float *)v50 - 63);
      v52 = (*((float *)v50 - 63) - *((float *)v50 - 66)) * 0.36750001;
      *((_DWORD *)v50 + 4) = 0;
      *((float *)v50 - 60) = v52;
      sub_5506A0(0, 0, 0);
      v49 = 0;
    }
    v50 += 296;
    --v77;
  }
  while ( v77 );
  this[589] = 0;
  this[590] = 0;
  this[591] = 0;
  this[592] = 0;
  this[593] = 0;
  *((_WORD *)this + 1188) = 0;
  this[596] = 0;
  UITimerTweenUpdate(0.0);
  this[731] = 0;
  dword_8AD3EC = 0;
  dword_8AD3F0 = 0;
  dword_8AD3F4 = 0;
  if ( ValueGetter(dword_8AFE88) )
  {
    dword_8AD3EC = sub_548890(aTread);
    dword_8AD3F0 = sub_548890(aTreadmed);
    dword_8AD3F4 = sub_548890(aTreadlow);
  }
  *((_BYTE *)this + 2412) = 1;
  *((_BYTE *)this + 2413) = 1;
  *((_BYTE *)this + 2425) = 0;
  v53 = flt_8AB274[(unsigned __int8)dword_8AAE70++] * 0.03125;
  v54 = *this;
  *((_BYTE *)this + 2421) = 0;
  *((_BYTE *)this + 2422) = 1;
  *((_BYTE *)this + 2423) = 0;
  *((_BYTE *)this + 2424) = 1;
  *((float *)this + 607) = (v53 + 1.0) * 0.67000002;
  this[604] = (void *)1065353216;
  StatusFieldCopy(dword_5EA560, v54[4645], 1);
  for ( k = *((_DWORD *)this[1] + 17); k; k = *(_DWORD *)(k + 76) )
  {
    SelfRelativeStringCopy(v88);
    if ( sub_587C20(v88, &off_5D4D10) )
    {
      if ( sub_587C20(v88, aTire) )
      {
        v56 = this[2804];
        *(_DWORD *)&v89[4 * (_DWORD)v56 + 32] = k;
        v56 = (char *)v56 + 1;
        this[2804] = v56;
        if ( v56 == (void *)8 )
          break;
      }
    }
  }
  result = (int)this[2804];
  if ( result > 0 )
  {
    this[2805] = (void *)OperatorNewNhMallocWrapper(20 * result);
    result = (int)this[2804];
    v78 = 0;
    if ( result > 0 )
    {
      do
      {
        v58 = *(_DWORD *)&v89[4 * v78 + 32];
        SelfRelativeStringCopy(v88);
        TripleFieldQuery(&v82, &v83, &v84);
        v59 = 0;
        if ( sub_587C20(v88, aRftire) )
        {
          v59 = 1;
        }
        else if ( sub_587C20(v88, aLrtire) )
        {
          v59 = 2;
        }
        else if ( sub_587C20(v88, aRrtire) )
        {
          v59 = 3;
        }
        *(_DWORD *)((char *)this[2805] + v49 + 16) = v58;
        *(_DWORD *)((char *)this[2805] + v49) = v59;
        v60 = 74 * v59;
        v85 = v82 - *(float *)&this[v60 + 82];
        v61 = this[2805];
        v86 = v83 - *(float *)&this[v60 + 83];
        v62 = v84 - *(float *)&this[v60 + 84];
        v63 = (int)v61 + v49 + 4;
        v64 = v86;
        *(float *)v63 = v85;
        v87 = v62;
        v65 = v87;
        *(float *)(v63 + 4) = v64;
        *(float *)(v63 + 8) = v65;
        v66 = this[2804];
        result = v78 + 1;
        v49 += 20;
        ++v78;
      }
      while ( v78 < (int)v66 );
    }
  }
  return result;
}
