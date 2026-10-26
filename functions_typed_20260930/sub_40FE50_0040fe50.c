int __thiscall sub_40FE50(_DWORD *this)
{
  int v2; // edi
  _DWORD *v3; // eax
  _DWORD *v4; // ebx
  _DWORD *v5; // edx
  int v6; // edx
  int v7; // eax
  int v8; // edi
  int v9; // ebp
  char *v10; // ebx
  int v11; // ebx
  int v12; // ebp
  int v13; // edi
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // eax
  int v24; // eax
  int v25; // ecx
  int v26; // edx
  int v27; // eax
  int v28; // eax
  int v29; // eax
  int v30; // eax
  int v31; // eax
  int v32; // edi
  _DWORD *v33; // eax
  _DWORD *v34; // ebx
  _DWORD *v35; // edx
  int v36; // edx
  int v37; // eax
  int v38; // edi
  int v39; // ebx
  int v40; // edi
  _DWORD *v41; // eax
  _DWORD *v42; // ebx
  _DWORD *v43; // edx
  int v44; // edx
  int v45; // eax
  int *v46; // ebp
  int v47; // edi
  int v48; // ebx
  int v49; // edi
  _DWORD *v50; // eax
  int v51; // edi
  _DWORD *v52; // ebx
  _DWORD *v53; // edx
  int v54; // edi
  int v55; // edx
  _DWORD *v56; // eax
  int v57; // ebx
  _DWORD *v58; // eax
  int v59; // ebx
  _DWORD *v60; // ebp
  _DWORD *v61; // edi
  int v62; // ebx
  _DWORD *v63; // eax
  int v64; // edi
  int v65; // ebp
  int v66; // ebx
  int v67; // edi
  _DWORD *v68; // eax
  _DWORD *v69; // ebx
  _DWORD *v70; // edx
  int v71; // edx
  _DWORD *v72; // eax
  int v73; // ebx
  _DWORD *v74; // eax
  _DWORD *v75; // ebp
  _DWORD *v76; // edi
  _DWORD *v77; // eax
  int v78; // edi
  int v79; // ebp
  int v80; // ebx
  int v81; // edi
  _DWORD *v82; // eax
  _DWORD *v83; // ebx
  _DWORD *v84; // edx
  int v85; // edx
  _DWORD *v86; // eax
  int v87; // ebx
  _DWORD *v88; // eax
  _DWORD *v89; // ebp
  _DWORD *v90; // edi
  _DWORD *v91; // eax
  int v92; // edi
  int v93; // ebp
  int v94; // ebx
  int v95; // edi
  _DWORD *v96; // eax
  _DWORD *v97; // ebx
  _DWORD *v98; // edx
  int v99; // edx
  _DWORD *v100; // eax
  int v101; // ebx
  _DWORD *v102; // eax
  _DWORD *v103; // ebp
  _DWORD *v104; // edi
  _DWORD *v105; // eax
  int v106; // edi
  int v107; // ebp
  int v108; // ebx
  int v109; // ecx
  int v110; // edx
  int v111; // edi
  _DWORD *v112; // eax
  _DWORD *v113; // ebx
  _DWORD *v114; // edx
  int v115; // edx
  _DWORD *v116; // eax
  int v117; // ebx
  _DWORD *v118; // eax
  _DWORD *v119; // ebp
  _DWORD *v120; // edi
  _DWORD *v121; // eax
  int v122; // edi
  int v123; // ebp
  int v124; // ebx
  int v125; // edx
  int v126; // eax
  int v127; // edi
  _DWORD *v128; // eax
  _DWORD *v129; // ebx
  _DWORD *v130; // edx
  int v131; // edx
  _DWORD *v132; // eax
  int v133; // ebx
  _DWORD *v134; // eax
  _DWORD *v135; // ebp
  _DWORD *v136; // edi
  _DWORD *v137; // eax
  int v138; // edi
  int v139; // ebp
  int v140; // ebx
  int v141; // eax
  int v142; // ecx
  int v143; // eax
  int result; // eax
  int v145; // [esp-8h] [ebp-1C9Ch]
  int v146; // [esp-4h] [ebp-1C98h]
  _BYTE v147[16]; // [esp+0h] [ebp-1C94h] BYREF
  int *v148; // [esp+10h] [ebp-1C84h]
  _BYTE v149[64]; // [esp+14h] [ebp-1C80h] BYREF
  _BYTE v150[7232]; // [esp+54h] [ebp-1C40h] BYREF

  v2 = 104;
  v146 = 3748;
  this[3] = 104;
  v3 = (_DWORD *)OperatorNewNhMallocWrapper(v146);
  if ( v3 )
  {
    v4 = v3 + 1;
    *v3 = 104;
    v5 = v3 + 1;
    do
    {
      StructInitializerWithSentinelValues(v5);
      v5 = (_DWORD *)(v6 + 36);
      --v2;
    }
    while ( v2 );
  }
  else
  {
    v4 = 0;
  }
  v7 = this[3];
  v8 = 0;
  this[4] = v4;
  if ( v7 > 0 )
  {
    v9 = 0;
    v10 = (char *)&MEMORY[0x5EC6E4];
    do
    {
      ShortComputation_e860(v9 + this[4], v8++, (int)v10);
      v10 += 18624;
      v9 += 36;
    }
    while ( v8 < this[3] );
  }
  v11 = 0;
  v12 = AudioNetworkNodeCount(dword_8AFE88);
  v146 = 4 * v12 + 4;
  this[24] = 0;
  this[21] = 0;
  this[18] = 0;
  this[15] = 0;
  this[12] = 0;
  this[9] = 0;
  this[5] = 0;
  this[7] = 0;
  v148 = (int *)OperatorNewNhMallocWrapper(v146);
  if ( v12 > 0 )
  {
    do
    {
      v13 = LinkedListNodeFinder(v11);
      if ( (*(_DWORD *)(v13 + 60) & 0x10) == 0x10 )
      {
        SelfRelativeStringCopy(v149);
        if ( !sub_588640(v149, aDspoly, 6) )
        {
          v14 = this[5];
          *(_DWORD *)&v150[4 * v14 + 64] = v13;
          this[5] = v14 + 1;
        }
        if ( !sub_588640(v149, aDsindicator, 11) )
        {
          v15 = this[5];
          *(_DWORD *)&v150[4 * v15 + 64] = v13;
          this[5] = v15 + 1;
        }
        if ( !sub_588640(v149, aDscone, 6) )
        {
          v16 = this[9];
          *(_DWORD *)&v150[4 * v16 + 1088] = v13;
          this[9] = v16 + 1;
        }
        if ( !sub_588640(v149, aCone, 4) )
        {
          v17 = this[9];
          *(_DWORD *)&v150[4 * v17 + 1088] = v13;
          this[9] = v17 + 1;
        }
        if ( !sub_588640(v149, aPost, 4) )
        {
          v18 = this[12];
          *(_DWORD *)&v150[4 * v18 + 3136] = v13;
          this[12] = v18 + 1;
        }
        if ( !sub_588640(v149, aSign, 4) )
        {
          v19 = this[15];
          *(_DWORD *)&v150[4 * v19 + 5184] = v13;
          this[15] = v19 + 1;
        }
        if ( !sub_588640(v149, aWheel, 5) )
        {
          v20 = this[18];
          *(_DWORD *)&v150[4 * v20 + 2112] = v13;
          this[18] = v20 + 1;
        }
        if ( !sub_588640(v149, aWing_0, 4) )
        {
          v21 = this[21];
          *(_DWORD *)&v150[4 * v21 + 4160] = v13;
          this[21] = v21 + 1;
        }
        if ( !sub_588640(v149, aPart, 4) )
        {
          v22 = this[24];
          *(_DWORD *)&v150[4 * v22 + 6208] = v13;
          this[24] = v22 + 1;
        }
        SceneNodeVisibilityToggle(0);
      }
      else
      {
        SelfRelativeStringCopy(v150);
        if ( sub_588640(v150, aDspoly, 6) )
        {
          if ( sub_588640(v150, aDsindicator, 11) )
          {
            if ( LinkedListFlagBitExtraction(v13)
              && v13 != dword_8AD074
              && v13 != dword_8AD078
              && v13 != dword_8AD07C
              && v13 != dword_8AD080
              && v13 != dword_8AD084 )
            {
              v148[this[7]++] = v13;
            }
          }
          else
          {
            v24 = this[5];
            *(_DWORD *)&v150[4 * v24 + 64] = v13;
            this[5] = v24 + 1;
          }
        }
        else
        {
          v23 = this[5];
          *(_DWORD *)&v150[4 * v23 + 64] = v13;
          this[5] = v23 + 1;
        }
      }
      ++v11;
    }
    while ( v11 < v12 );
  }
  v25 = this[24] + 832;
  v26 = this[21] + 208;
  this[18] += 416;
  this[21] = v26;
  this[24] = v25;
  if ( dword_8AD074 )
  {
    v27 = this[5];
    *(_DWORD *)&v150[4 * v27 + 64] = dword_8AD074;
    this[5] = v27 + 1;
  }
  if ( dword_8AD078 )
  {
    v28 = this[5];
    *(_DWORD *)&v150[4 * v28 + 64] = dword_8AD078;
    this[5] = v28 + 1;
  }
  if ( dword_8AD07C )
  {
    v29 = this[5];
    *(_DWORD *)&v150[4 * v29 + 64] = dword_8AD07C;
    this[5] = v29 + 1;
  }
  if ( dword_8AD080 )
  {
    v30 = this[5];
    *(_DWORD *)&v150[4 * v30 + 64] = dword_8AD080;
    this[5] = v30 + 1;
  }
  if ( dword_8AD084 )
  {
    v31 = this[5];
    *(_DWORD *)&v150[4 * v31 + 64] = dword_8AD084;
    this[5] = v31 + 1;
  }
  v32 = this[5];
  v33 = (_DWORD *)OperatorNewNhMallocWrapper(36 * v32 + 4);
  if ( v33 )
  {
    v34 = v33 + 1;
    *v33 = v32;
    v35 = v33 + 1;
    if ( v32 - 1 >= 0 )
    {
      do
      {
        StructInitializerWithSentinelValues(v35);
        v35 = (_DWORD *)(v36 + 36);
        --v32;
      }
      while ( v32 );
    }
  }
  else
  {
    v34 = 0;
  }
  v37 = this[5];
  v38 = 0;
  this[6] = v34;
  if ( v37 > 0 )
  {
    v39 = 0;
    do
    {
      StructFieldInitializer_e880(v39 + this[6], v38, *(_DWORD *)&v150[4 * v38 + 64]);
      ++v38;
      v39 += 36;
    }
    while ( v38 < this[5] );
  }
  v40 = this[7];
  v41 = (_DWORD *)OperatorNewNhMallocWrapper(36 * v40 + 4);
  if ( v41 )
  {
    v42 = v41 + 1;
    *v41 = v40;
    v43 = v41 + 1;
    if ( v40 - 1 >= 0 )
    {
      do
      {
        StructInitializerWithSentinelValues(v43);
        v43 = (_DWORD *)(v44 + 36);
        --v40;
      }
      while ( v40 );
    }
  }
  else
  {
    v42 = 0;
  }
  v45 = this[7];
  v46 = v148;
  v47 = 0;
  this[8] = v42;
  if ( v45 > 0 )
  {
    v48 = 0;
    do
    {
      StructSetupWithTwoCalls(v48 + this[8], v47, v46[v47]);
      ++v47;
      v48 += 36;
    }
    while ( v47 < this[7] );
  }
  FreeWrapper_7bcf(v46);
  v49 = this[9];
  v50 = (_DWORD *)OperatorNewNhMallocWrapper(36 * v49 + 4);
  if ( v50 )
  {
    *v50 = v49;
    v51 = v49 - 1;
    v52 = v50 + 1;
    v53 = v50 + 1;
    if ( v51 >= 0 )
    {
      v54 = v51 + 1;
      do
      {
        StructInitializerWithSentinelValues(v53);
        v53 = (_DWORD *)(v55 + 36);
        --v54;
      }
      while ( v54 );
    }
    v56 = v52;
  }
  else
  {
    v56 = 0;
  }
  v57 = this[9];
  v146 = 792 * v57 + 4;
  this[10] = v56;
  v58 = (_DWORD *)OperatorNewNhMallocWrapper(v146);
  if ( v58 )
  {
    *v58 = v57;
    v59 = v57 - 1;
    v60 = v58 + 1;
    v61 = v58 + 1;
    if ( v59 >= 0 )
    {
      v62 = v59 + 1;
      do
      {
        ShortComputation_8e30(v61 + 53);
        *v61 = &off_59E720;
        StructInitWithFloatConstants(v61);
        *v61 = &off_59E768;
        v61 += 198;
        --v62;
      }
      while ( v62 );
    }
    v63 = v60;
  }
  else
  {
    v63 = 0;
  }
  this[11] = v63;
  v64 = 0;
  if ( (int)this[9] > 0 )
  {
    v65 = 0;
    v66 = 0;
    do
    {
      StructInitWithFloatConstantsAndSubCalls(v65 + this[10], v64, v66 + this[11], *(_DWORD *)&v150[4 * v64 + 1088]);
      ++v64;
      v66 += 792;
      v65 += 36;
    }
    while ( v64 < this[9] );
  }
  v67 = this[12];
  v68 = (_DWORD *)OperatorNewNhMallocWrapper(36 * v67 + 4);
  if ( v68 )
  {
    v69 = v68 + 1;
    *v68 = v67;
    v70 = v68 + 1;
    if ( v67 - 1 >= 0 )
    {
      do
      {
        StructInitializerWithSentinelValues(v70);
        v70 = (_DWORD *)(v71 + 36);
        --v67;
      }
      while ( v67 );
    }
    v72 = v69;
  }
  else
  {
    v72 = 0;
  }
  v73 = this[12];
  this[13] = v72;
  v74 = (_DWORD *)OperatorNewNhMallocWrapper(792 * v73 + 4);
  if ( v74 )
  {
    v75 = v74 + 1;
    *v74 = v73;
    v76 = v74 + 1;
    if ( v73 - 1 >= 0 )
    {
      do
      {
        ShortComputation_8e30(v76 + 53);
        *v76 = &off_59E720;
        StructInitWithFloatConstants(v76);
        *v76 = &off_59E75C;
        v76 += 198;
        --v73;
      }
      while ( v73 );
    }
    v77 = v75;
  }
  else
  {
    v77 = 0;
  }
  this[14] = v77;
  v78 = 0;
  if ( (int)this[12] > 0 )
  {
    v79 = 0;
    v80 = 0;
    do
    {
      StructInitWithFloatConstantsAndSubCalls_e990(
        v79 + this[13],
        v78,
        v80 + this[14],
        *(_DWORD *)&v150[4 * v78 + 3136]);
      ++v78;
      v80 += 792;
      v79 += 36;
    }
    while ( v78 < this[12] );
  }
  v81 = this[15];
  v82 = (_DWORD *)OperatorNewNhMallocWrapper(36 * v81 + 4);
  if ( v82 )
  {
    v83 = v82 + 1;
    *v82 = v81;
    v84 = v82 + 1;
    if ( v81 - 1 >= 0 )
    {
      do
      {
        StructInitializerWithSentinelValues(v84);
        v84 = (_DWORD *)(v85 + 36);
        --v81;
      }
      while ( v81 );
    }
    v86 = v83;
  }
  else
  {
    v86 = 0;
  }
  v87 = this[15];
  v146 = 792 * v87 + 4;
  this[16] = v86;
  v88 = (_DWORD *)OperatorNewNhMallocWrapper(v146);
  if ( v88 )
  {
    v89 = v88 + 1;
    *v88 = v87;
    v90 = v88 + 1;
    if ( v87 - 1 >= 0 )
    {
      do
      {
        ShortComputation_8e30(v90 + 53);
        *v90 = &off_59E720;
        StructInitWithFloatConstants(v90);
        *v90 = &off_59E750;
        v90 += 198;
        --v87;
      }
      while ( v87 );
    }
    v91 = v89;
  }
  else
  {
    v91 = 0;
  }
  this[17] = v91;
  v92 = 0;
  if ( (int)this[15] > 0 )
  {
    v93 = 0;
    v94 = 0;
    do
    {
      sub_40EA30(v93 + this[16], v92, v94 + this[17], *(_DWORD *)&v150[4 * v92 + 5184]);
      ++v92;
      v94 += 792;
      v93 += 36;
    }
    while ( v92 < this[15] );
  }
  v95 = this[18];
  v96 = (_DWORD *)OperatorNewNhMallocWrapper(36 * v95 + 4);
  if ( v96 )
  {
    v97 = v96 + 1;
    *v96 = v95;
    v98 = v96 + 1;
    if ( v95 - 1 >= 0 )
    {
      do
      {
        StructInitializerWithSentinelValues(v98);
        v98 = (_DWORD *)(v99 + 36);
        --v95;
      }
      while ( v95 );
    }
    v100 = v97;
  }
  else
  {
    v100 = 0;
  }
  v101 = this[18];
  v146 = 808 * v101 + 4;
  this[19] = v100;
  v102 = (_DWORD *)OperatorNewNhMallocWrapper(v146);
  if ( v102 )
  {
    v103 = v102 + 1;
    *v102 = v101;
    v104 = v102 + 1;
    if ( v101 - 1 >= 0 )
    {
      do
      {
        ShortComputation_8e30(v104 + 53);
        *v104 = &off_59E720;
        StructInitWithFloatConstants(v104);
        *v104 = off_59E744;
        v104 += 202;
        --v101;
      }
      while ( v101 );
    }
    v105 = v103;
  }
  else
  {
    v105 = 0;
  }
  this[20] = v105;
  v106 = 0;
  if ( (int)this[18] > 0 )
  {
    v107 = 0;
    v108 = 0;
    v148 = (int *)&v147[532];
    do
    {
      if ( v108 < 336128 )
      {
        v110 = this[20];
        v146 = 0;
        v145 = v108 + v110;
      }
      else
      {
        v109 = this[20];
        v146 = *v148;
        v145 = v108 + v109;
      }
      CameraProjectionMatrixInitWithFloatConstants(v107 + this[19], v106, v145, v146);
      ++v148;
      ++v106;
      v108 += 808;
      v107 += 36;
    }
    while ( v106 < this[18] );
  }
  v111 = this[21];
  v112 = (_DWORD *)OperatorNewNhMallocWrapper(36 * v111 + 4);
  if ( v112 )
  {
    v113 = v112 + 1;
    *v112 = v111;
    v114 = v112 + 1;
    if ( v111 - 1 >= 0 )
    {
      do
      {
        StructInitializerWithSentinelValues(v114);
        v114 = (_DWORD *)(v115 + 36);
        --v111;
      }
      while ( v111 );
    }
    v116 = v113;
  }
  else
  {
    v116 = 0;
  }
  v117 = this[21];
  v146 = 792 * v117 + 4;
  this[22] = v116;
  v118 = (_DWORD *)OperatorNewNhMallocWrapper(v146);
  if ( v118 )
  {
    v119 = v118 + 1;
    *v118 = v117;
    v120 = v118 + 1;
    if ( v117 - 1 >= 0 )
    {
      do
      {
        ShortComputation_8e30(v120 + 53);
        *v120 = &off_59E720;
        StructInitWithFloatConstants(v120);
        *v120 = &off_59E738;
        v120 += 198;
        --v117;
      }
      while ( v117 );
    }
    v121 = v119;
  }
  else
  {
    v121 = 0;
  }
  this[23] = v121;
  v122 = 0;
  if ( (int)this[21] > 0 )
  {
    v123 = 0;
    v124 = 0;
    v148 = (int *)&v147[3412];
    do
    {
      if ( v124 < 164736 )
      {
        v126 = this[23];
        v146 = 0;
        v145 = v124 + v126;
      }
      else
      {
        v125 = this[23];
        v146 = *v148;
        v145 = v124 + v125;
      }
      UtilityFunction_ebd0(v123 + this[22], v122, v145, v146);
      ++v148;
      ++v122;
      v124 += 792;
      v123 += 36;
    }
    while ( v122 < this[21] );
  }
  v127 = this[24];
  v128 = (_DWORD *)OperatorNewNhMallocWrapper(36 * v127 + 4);
  if ( v128 )
  {
    v129 = v128 + 1;
    *v128 = v127;
    v130 = v128 + 1;
    if ( v127 - 1 >= 0 )
    {
      do
      {
        StructInitializerWithSentinelValues(v130);
        v130 = (_DWORD *)(v131 + 36);
        --v127;
      }
      while ( v127 );
    }
    v132 = v129;
  }
  else
  {
    v132 = 0;
  }
  v133 = this[24];
  this[25] = v132;
  v134 = (_DWORD *)OperatorNewNhMallocWrapper(792 * v133 + 4);
  if ( v134 )
  {
    v135 = v134 + 1;
    *v134 = v133;
    v136 = v134 + 1;
    if ( v133 - 1 >= 0 )
    {
      do
      {
        ShortComputation_8e30(v136 + 53);
        *v136 = &off_59E720;
        StructInitWithFloatConstants(v136);
        *v136 = &off_59E72C;
        v136 += 198;
        --v133;
      }
      while ( v133 );
    }
    v137 = v135;
  }
  else
  {
    v137 = 0;
  }
  this[26] = v137;
  v138 = 0;
  if ( (int)this[24] > 0 )
  {
    v139 = 0;
    v140 = 0;
    v148 = (int *)&v147[2964];
    do
    {
      if ( v140 < 658944 )
      {
        v142 = this[26];
        v146 = 0;
        v145 = v140 + v142;
      }
      else
      {
        v141 = this[26];
        v146 = *v148;
        v145 = v140 + v141;
      }
      StructInitializerWithFloatConstants(v139 + this[25], v138, v145, v146);
      ++v148;
      ++v138;
      v140 += 792;
      v139 += 36;
    }
    while ( v138 < this[24] );
  }
  v143 = this[9] + this[15] + this[21] + this[5] + this[12] + this[18] + this[24] + this[3];
  v146 = 4 * v143;
  *this = 0;
  this[1] = v143;
  result = OperatorNewNhMallocWrapper(v146);
  this[2] = result;
  return result;
}

