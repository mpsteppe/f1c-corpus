int __thiscall sub_416E90(_DWORD *this)
{
  int v2; // edi
  _DWORD *v3; // eax
  _DWORD *v4; // ebx
  _DWORD *v5; // edx
  int v6; // edx
  _DWORD *v7; // eax
  int v8; // edi
  int v9; // ebp
  char *v10; // ebx
  int v11; // ebp
  int v12; // ebx
  int v13; // ebx
  int v14; // ebp
  int v15; // edi
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // eax
  int v24; // eax
  int v25; // eax
  int v26; // eax
  int v27; // ecx
  int v28; // edx
  int v29; // eax
  int v30; // eax
  int v31; // eax
  int v32; // eax
  int v33; // eax
  int v34; // eax
  int v35; // edi
  _DWORD *v36; // eax
  _DWORD *v37; // ebx
  _DWORD *v38; // edx
  int v39; // edx
  int v40; // eax
  int v41; // edi
  int v42; // ebx
  int v43; // edi
  _DWORD *v44; // eax
  _DWORD *v45; // ebx
  _DWORD *v46; // edx
  int v47; // edx
  int v48; // eax
  float v49; // ebp
  int v50; // edi
  int v51; // ebx
  int v52; // edi
  _DWORD *v53; // eax
  _DWORD *v54; // ebx
  _DWORD *v55; // edx
  int v56; // edx
  _DWORD *v57; // eax
  int v58; // ebx
  _DWORD *v59; // eax
  int v60; // ebx
  _DWORD *v61; // ebp
  _DWORD *v62; // edi
  int v63; // ebx
  _DWORD *v64; // eax
  int v65; // edi
  int v66; // ebp
  int v67; // ebx
  int v68; // edi
  _DWORD *v69; // eax
  _DWORD *v70; // ebx
  _DWORD *v71; // edx
  int v72; // edx
  _DWORD *v73; // eax
  int v74; // ebx
  _DWORD *v75; // eax
  _DWORD *v76; // ebp
  _DWORD *v77; // edi
  _DWORD *v78; // eax
  int v79; // edi
  int v80; // ebp
  int v81; // ebx
  int v82; // edi
  _DWORD *v83; // eax
  _DWORD *v84; // ebx
  _DWORD *v85; // edx
  int v86; // edx
  _DWORD *v87; // eax
  int v88; // ebx
  _DWORD *v89; // eax
  _DWORD *v90; // ebp
  _DWORD *v91; // edi
  _DWORD *v92; // eax
  int v93; // edi
  int v94; // ebp
  int v95; // ebx
  int v96; // edi
  _DWORD *v97; // eax
  _DWORD *v98; // ebx
  _DWORD *v99; // edx
  int v100; // edx
  _DWORD *v101; // eax
  int v102; // ebx
  _DWORD *v103; // eax
  _DWORD *v104; // ebp
  _DWORD *v105; // edi
  _DWORD *v106; // eax
  int v107; // edi
  int v108; // ebp
  int v109; // ebx
  int v110; // eax
  int v111; // ecx
  int v112; // edi
  _DWORD *v113; // eax
  _DWORD *v114; // ebx
  _DWORD *v115; // edx
  int v116; // edx
  _DWORD *v117; // eax
  int v118; // ebx
  _DWORD *v119; // eax
  _DWORD *v120; // ebp
  _DWORD *v121; // edi
  _DWORD *v122; // eax
  int v123; // edi
  int v124; // ebp
  int v125; // ebx
  int v126; // ecx
  int v127; // edx
  int v128; // edi
  _DWORD *v129; // eax
  _DWORD *v130; // ebx
  _DWORD *v131; // edx
  int v132; // edx
  _DWORD *v133; // eax
  int v134; // ebx
  _DWORD *v135; // eax
  _DWORD *v136; // ebp
  _DWORD *v137; // edi
  _DWORD *v138; // eax
  int v139; // edi
  int v140; // ebp
  int v141; // ebx
  int v142; // edx
  int v143; // eax
  int v144; // edx
  int v145; // ecx
  int result; // eax
  int v147; // [esp-8h] [ebp-1CA0h]
  int v148; // [esp-4h] [ebp-1C9Ch]
  _BYTE v149[16]; // [esp+0h] [ebp-1C98h] BYREF
  float v150; // [esp+10h] [ebp-1C88h]
  int v151; // [esp+14h] [ebp-1C84h]
  char Str1[64]; // [esp+18h] [ebp-1C80h] BYREF
  char v153[7232]; // [esp+58h] [ebp-1C40h] BYREF

  v2 = 49;
  v148 = 1964;
  this[3] = 49;
  v3 = operator new(v148);
  if ( v3 )
  {
    v4 = v3 + 1;
    *v3 = 49;
    v5 = v3 + 1;
    do
    {
      sub_4157C0(v5);
      v5 = (_DWORD *)(v6 + 40);
      --v2;
    }
    while ( v2 );
    v7 = v4;
  }
  else
  {
    v7 = 0;
  }
  v8 = 0;
  this[4] = v7;
  v9 = 0;
  v10 = (char *)&unk_62BFBC;
  do
  {
    sub_415950(v9 + this[4], v8, (int)v10);
    v10 += 25304;
    ++v8;
    v9 += 40;
  }
  while ( (int)v10 < (int)byte_75483C );
  if ( v8 < this[3] )
  {
    v11 = 40 * v8;
    v12 = 25304 * v8;
    do
    {
      sub_415950(v11 + this[4], v8++, (int)off_5FD348 + v12 - 1214508);
      v12 += 25304;
      v11 += 40;
    }
    while ( v8 < this[3] );
  }
  v13 = 0;
  v14 = sub_597540(dword_7DA9B8);
  v148 = 4 * v14 + 4;
  this[24] = 0;
  this[21] = 0;
  this[18] = 0;
  this[15] = 0;
  this[12] = 0;
  this[9] = 0;
  this[5] = 0;
  this[7] = 0;
  v150 = COERCE_FLOAT(operator new(v148));
  if ( v14 > 0 )
  {
    do
    {
      v15 = sub_597590(v13);
      if ( (*(_BYTE *)(v15 + 60) & 0x10) == 0x10 )
      {
        sub_59EA30(Str1);
        if ( !strncmp(Str1, Str2, 6u) )
        {
          v16 = this[5];
          *(_DWORD *)&v153[4 * v16 + 64] = v15;
          this[5] = v16 + 1;
        }
        if ( !strncmp(Str1, aDsindicator, 0xBu) )
        {
          v17 = this[5];
          *(_DWORD *)&v153[4 * v17 + 64] = v15;
          this[5] = v17 + 1;
        }
        if ( !strncmp(Str1, aDscone, 6u) )
        {
          v18 = this[9];
          *(_DWORD *)&v153[4 * v18 + 1088] = v15;
          this[9] = v18 + 1;
        }
        if ( !strncmp(Str1, aCone, 4u) )
        {
          v19 = this[9];
          *(_DWORD *)&v153[4 * v19 + 1088] = v15;
          this[9] = v19 + 1;
        }
        if ( !strncmp(Str1, aPost, 4u) )
        {
          v20 = this[12];
          *(_DWORD *)&v153[4 * v20 + 3136] = v15;
          this[12] = v20 + 1;
        }
        if ( !strncmp(Str1, aSign, 4u) )
        {
          v21 = this[15];
          *(_DWORD *)&v153[4 * v21 + 5184] = v15;
          this[15] = v21 + 1;
        }
        if ( !strncmp(Str1, aWheel, 5u) )
        {
          v22 = this[18];
          *(_DWORD *)&v153[4 * v22 + 2112] = v15;
          this[18] = v22 + 1;
        }
        if ( !strncmp(Str1, aWing, 4u) )
        {
          v23 = this[21];
          *(_DWORD *)&v153[4 * v23 + 4160] = v15;
          this[21] = v23 + 1;
        }
        if ( !strncmp(Str1, aPart, 4u) )
        {
          v24 = this[24];
          *(_DWORD *)&v153[4 * v24 + 6208] = v15;
          this[24] = v24 + 1;
        }
        sub_5A12F0(0);
      }
      else
      {
        sub_59EA30(v153);
        if ( !strncmp(v153, Str2, 6u) )
        {
          v25 = this[5];
          *(_DWORD *)&v153[4 * v25 + 64] = v15;
          this[5] = v25 + 1;
        }
        else if ( !strncmp(v153, aDsindicator, 0xBu) )
        {
          v26 = this[5];
          *(_DWORD *)&v153[4 * v26 + 64] = v15;
          this[5] = v26 + 1;
        }
        else if ( sub_5A1320(v15)
               && v15 != dword_7D78D8
               && v15 != dword_7D78DC
               && v15 != dword_7D78E0
               && v15 != dword_7D78E4
               && v15 != dword_7D78E8
               && v15 != dword_7D78EC )
        {
          *(_DWORD *)(LODWORD(v150) + 4 * this[7]++) = v15;
        }
      }
      ++v13;
    }
    while ( v13 < v14 );
  }
  v27 = this[24] + 588;
  v28 = this[21] + 98;
  this[18] += 196;
  this[21] = v28;
  this[24] = v27;
  if ( dword_7D78D8 )
  {
    v29 = this[5];
    *(_DWORD *)&v153[4 * v29 + 64] = dword_7D78D8;
    this[5] = v29 + 1;
  }
  if ( dword_7D78DC )
  {
    v30 = this[5];
    *(_DWORD *)&v153[4 * v30 + 64] = dword_7D78DC;
    this[5] = v30 + 1;
  }
  if ( dword_7D78E0 )
  {
    v31 = this[5];
    *(_DWORD *)&v153[4 * v31 + 64] = dword_7D78E0;
    this[5] = v31 + 1;
  }
  if ( dword_7D78E4 )
  {
    v32 = this[5];
    *(_DWORD *)&v153[4 * v32 + 64] = dword_7D78E4;
    this[5] = v32 + 1;
  }
  if ( dword_7D78E8 )
  {
    v33 = this[5];
    *(_DWORD *)&v153[4 * v33 + 64] = dword_7D78E8;
    this[5] = v33 + 1;
  }
  if ( dword_7D78EC )
  {
    v34 = this[5];
    *(_DWORD *)&v153[4 * v34 + 64] = dword_7D78EC;
    this[5] = v34 + 1;
  }
  v35 = this[5];
  v36 = operator new(40 * v35 + 4);
  if ( v36 )
  {
    v37 = v36 + 1;
    *v36 = v35;
    v38 = v36 + 1;
    if ( v35 - 1 >= 0 )
    {
      do
      {
        sub_4157C0(v38);
        v38 = (_DWORD *)(v39 + 40);
        --v35;
      }
      while ( v35 );
    }
  }
  else
  {
    v37 = 0;
  }
  v40 = this[5];
  v41 = 0;
  this[6] = v37;
  if ( v40 > 0 )
  {
    v42 = 0;
    do
    {
      sub_415970(v42 + this[6], v41, *(_DWORD *)&v153[4 * v41 + 64]);
      ++v41;
      v42 += 40;
    }
    while ( v41 < this[5] );
  }
  v43 = this[7];
  v44 = operator new(40 * v43 + 4);
  if ( v44 )
  {
    v45 = v44 + 1;
    *v44 = v43;
    v46 = v44 + 1;
    if ( v43 - 1 >= 0 )
    {
      do
      {
        sub_4157C0(v46);
        v46 = (_DWORD *)(v47 + 40);
        --v43;
      }
      while ( v43 );
    }
  }
  else
  {
    v45 = 0;
  }
  v48 = this[7];
  v49 = v150;
  v50 = 0;
  this[8] = v45;
  if ( v48 > 0 )
  {
    v51 = 0;
    do
    {
      sub_4159A0(v51 + this[8], v50, *(_DWORD *)(LODWORD(v49) + 4 * v50));
      ++v50;
      v51 += 40;
    }
    while ( v50 < this[7] );
  }
  sub_5BE8AE((LPVOID)LODWORD(v49));
  v52 = this[9];
  v53 = operator new(40 * v52 + 4);
  if ( v53 )
  {
    v54 = v53 + 1;
    *v53 = v52;
    v55 = v53 + 1;
    if ( v52 - 1 >= 0 )
    {
      do
      {
        sub_4157C0(v55);
        v55 = (_DWORD *)(v56 + 40);
        --v52;
      }
      while ( v52 );
    }
    v57 = v54;
  }
  else
  {
    v57 = 0;
  }
  v58 = this[9];
  this[10] = v57;
  v59 = operator new(796 * v58 + 4);
  if ( v59 )
  {
    *v59 = v58;
    v60 = v58 - 1;
    v61 = v59 + 1;
    v62 = v59 + 1;
    if ( v60 >= 0 )
    {
      v63 = v60 + 1;
      do
      {
        sub_57BBC0(v62 + 54);
        *v62 = &off_5D5B08;
        sub_45A5E0(v62);
        *v62 = &off_5D5B54;
        v62 += 199;
        --v63;
      }
      while ( v63 );
    }
    v64 = v61;
  }
  else
  {
    v64 = 0;
  }
  this[11] = v64;
  v65 = 0;
  if ( (int)this[9] > 0 )
  {
    v66 = 0;
    v67 = 0;
    do
    {
      sub_4159E0(v66 + this[10], v65, v67 + this[11], *(_DWORD *)&v153[4 * v65 + 1088]);
      ++v65;
      v67 += 796;
      v66 += 40;
    }
    while ( v65 < this[9] );
  }
  v68 = this[12];
  v69 = operator new(40 * v68 + 4);
  if ( v69 )
  {
    v70 = v69 + 1;
    *v69 = v68;
    v71 = v69 + 1;
    if ( v68 - 1 >= 0 )
    {
      do
      {
        sub_4157C0(v71);
        v71 = (_DWORD *)(v72 + 40);
        --v68;
      }
      while ( v68 );
    }
    v73 = v70;
  }
  else
  {
    v73 = 0;
  }
  v74 = this[12];
  v148 = 796 * v74 + 4;
  this[13] = v73;
  v75 = operator new(v148);
  if ( v75 )
  {
    v76 = v75 + 1;
    *v75 = v74;
    v77 = v75 + 1;
    if ( v74 - 1 >= 0 )
    {
      do
      {
        sub_57BBC0(v77 + 54);
        *v77 = &off_5D5B08;
        sub_45A5E0(v77);
        *v77 = &off_5D5B48;
        v77 += 199;
        --v74;
      }
      while ( v74 );
    }
    v78 = v76;
  }
  else
  {
    v78 = 0;
  }
  this[14] = v78;
  v79 = 0;
  if ( (int)this[12] > 0 )
  {
    v80 = 0;
    v81 = 0;
    do
    {
      sub_415A80(v80 + this[13], v79, v81 + this[14], *(_DWORD *)&v153[4 * v79 + 3136]);
      ++v79;
      v81 += 796;
      v80 += 40;
    }
    while ( v79 < this[12] );
  }
  v82 = this[15];
  v83 = operator new(40 * v82 + 4);
  if ( v83 )
  {
    v84 = v83 + 1;
    *v83 = v82;
    v85 = v83 + 1;
    if ( v82 - 1 >= 0 )
    {
      do
      {
        sub_4157C0(v85);
        v85 = (_DWORD *)(v86 + 40);
        --v82;
      }
      while ( v82 );
    }
    v87 = v84;
  }
  else
  {
    v87 = 0;
  }
  v88 = this[15];
  v148 = 796 * v88 + 4;
  this[16] = v87;
  v89 = operator new(v148);
  if ( v89 )
  {
    v90 = v89 + 1;
    *v89 = v88;
    v91 = v89 + 1;
    if ( v88 - 1 >= 0 )
    {
      do
      {
        sub_57BBC0(v91 + 54);
        *v91 = &off_5D5B08;
        sub_45A5E0(v91);
        *v91 = &off_5D5B3C;
        v91 += 199;
        --v88;
      }
      while ( v88 );
    }
    v92 = v90;
  }
  else
  {
    v92 = 0;
  }
  this[17] = v92;
  v93 = 0;
  if ( (int)this[15] > 0 )
  {
    v94 = 0;
    v95 = 0;
    do
    {
      sub_415B20(v94 + this[16], v93, v95 + this[17], *(_DWORD *)&v153[4 * v93 + 5184]);
      ++v93;
      v95 += 796;
      v94 += 40;
    }
    while ( v93 < this[15] );
  }
  v96 = this[18];
  v97 = operator new(40 * v96 + 4);
  if ( v97 )
  {
    v98 = v97 + 1;
    *v97 = v96;
    v99 = v97 + 1;
    if ( v96 - 1 >= 0 )
    {
      do
      {
        sub_4157C0(v99);
        v99 = (_DWORD *)(v100 + 40);
        --v96;
      }
      while ( v96 );
    }
    v101 = v98;
  }
  else
  {
    v101 = 0;
  }
  v102 = this[18];
  this[19] = v101;
  v103 = operator new(812 * v102 + 4);
  if ( v103 )
  {
    v104 = v103 + 1;
    *v103 = v102;
    v105 = v103 + 1;
    if ( v102 - 1 >= 0 )
    {
      do
      {
        sub_57BBC0(v105 + 54);
        *v105 = &off_5D5B08;
        sub_45A5E0(v105);
        *v105 = &off_5D5B30;
        v105 += 203;
        --v102;
      }
      while ( v102 );
    }
    v106 = v104;
  }
  else
  {
    v106 = 0;
  }
  this[20] = v106;
  v107 = 0;
  if ( (int)this[18] > 0 )
  {
    v108 = 0;
    v109 = 0;
    LODWORD(v150) = &v149[1416];
    do
    {
      if ( v109 < 159152 )
      {
        v111 = this[20];
        v148 = 0;
        v147 = v109 + v111;
      }
      else
      {
        v110 = this[20];
        v148 = *(_DWORD *)LODWORD(v150);
        v147 = v109 + v110;
      }
      sub_415C20(v108 + this[19], v107, v147, v148);
      LODWORD(v150) += 4;
      ++v107;
      v109 += 812;
      v108 += 40;
    }
    while ( v107 < this[18] );
  }
  v112 = this[21];
  v113 = operator new(40 * v112 + 4);
  if ( v113 )
  {
    v114 = v113 + 1;
    *v113 = v112;
    v115 = v113 + 1;
    if ( v112 - 1 >= 0 )
    {
      do
      {
        sub_4157C0(v115);
        v115 = (_DWORD *)(v116 + 40);
        --v112;
      }
      while ( v112 );
    }
    v117 = v114;
  }
  else
  {
    v117 = 0;
  }
  v118 = this[21];
  v148 = 796 * v118 + 4;
  this[22] = v117;
  v119 = operator new(v148);
  if ( v119 )
  {
    v120 = v119 + 1;
    *v119 = v118;
    v121 = v119 + 1;
    if ( v118 - 1 >= 0 )
    {
      do
      {
        sub_57BBC0(v121 + 54);
        *v121 = &off_5D5B08;
        sub_45A5E0(v121);
        *v121 = &off_5D5B24;
        v121 += 199;
        --v118;
      }
      while ( v118 );
    }
    v122 = v120;
  }
  else
  {
    v122 = 0;
  }
  this[23] = v122;
  v123 = 0;
  if ( (int)this[21] > 0 )
  {
    v124 = 0;
    v125 = 0;
    LODWORD(v150) = &v149[3856];
    do
    {
      if ( v125 < 78008 )
      {
        v127 = this[23];
        v148 = 0;
        v147 = v125 + v127;
      }
      else
      {
        v126 = this[23];
        v148 = *(_DWORD *)LODWORD(v150);
        v147 = v125 + v126;
      }
      sub_415CC0(v124 + this[22], v123, v147, v148);
      LODWORD(v150) += 4;
      ++v123;
      v125 += 796;
      v124 += 40;
    }
    while ( v123 < this[21] );
  }
  v128 = this[24];
  v129 = operator new(40 * v128 + 4);
  if ( v129 )
  {
    v130 = v129 + 1;
    *v129 = v128;
    v131 = v129 + 1;
    if ( v128 - 1 >= 0 )
    {
      do
      {
        sub_4157C0(v131);
        v131 = (_DWORD *)(v132 + 40);
        --v128;
      }
      while ( v128 );
    }
    v133 = v130;
  }
  else
  {
    v133 = 0;
  }
  v134 = this[24];
  v148 = 796 * v134 + 4;
  this[25] = v133;
  v135 = operator new(v148);
  if ( v135 )
  {
    v136 = v135 + 1;
    *v135 = v134;
    v137 = v135 + 1;
    if ( v134 - 1 >= 0 )
    {
      do
      {
        sub_57BBC0(v137 + 54);
        *v137 = &off_5D5B08;
        sub_45A5E0(v137);
        *v137 = &off_5D5B18;
        v137 += 199;
        --v134;
      }
      while ( v134 );
    }
    v138 = v136;
  }
  else
  {
    v138 = 0;
  }
  this[26] = v138;
  v139 = 0;
  if ( (int)this[24] > 0 )
  {
    v140 = 0;
    v141 = 0;
    LODWORD(v150) = &v149[3944];
    do
    {
      if ( v141 < 468048 )
      {
        v143 = this[26];
        v148 = 0;
        v147 = v141 + v143;
      }
      else
      {
        v142 = this[26];
        v148 = *(_DWORD *)LODWORD(v150);
        v147 = v141 + v142;
      }
      sub_415D60(v140 + this[25], v139, v147, v148);
      LODWORD(v150) += 4;
      ++v139;
      v141 += 796;
      v140 += 40;
    }
    while ( v139 < this[24] );
  }
  v144 = this[3];
  v145 = this[9] + this[15] + this[21] + this[5] + this[12] + this[18] + this[24];
  this[1] = v145 + v144;
  v148 = 4 * (v145 + v144);
  *this = 0;
  this[2] = operator new(v148);
  v150 = 40.0 / (double)dword_7687A4;
  v151 = (int)v150;
  result = 8 * v151;
  this[27] = 8 * v151;
  if ( result >= 8 )
  {
    if ( result > 320 )
      this[27] = 320;
  }
  else
  {
    this[27] = 8;
  }
  return result;
}
