int __thiscall sub_6AC040(_DWORD *this)
{
  unsigned int v1; // edx
  unsigned int v3; // ecx
  bool v4; // zf
  _DWORD *v5; // eax
  int v6; // edi
  unsigned int i; // ecx
  _DWORD *v8; // eax
  int v9; // edi
  unsigned int v10; // eax
  _DWORD *v11; // eax
  _DWORD *v12; // ebx
  int v13; // edx
  unsigned int v14; // edx
  _DWORD *v15; // eax
  int v16; // ebx
  int v17; // edi
  int v18; // eax
  _DWORD *v19; // eax
  char *v20; // edi
  char *v21; // eax
  unsigned int v22; // eax
  int v23; // ecx
  int v24; // edx
  _DWORD *v25; // eax
  char *v26; // eax
  unsigned int v27; // eax
  int v28; // edx
  unsigned int v29; // edi
  int v30; // ecx
  int v31; // eax
  int v32; // eax
  int v33; // edi
  int v34; // eax
  unsigned int v35; // ecx
  int v36; // eax
  _DWORD *v37; // edi
  unsigned int v38; // eax
  int v39; // ecx
  int v40; // eax
  _DWORD *m; // ecx
  unsigned int *v42; // eax
  int v43; // edi
  int v44; // eax
  _DWORD *v45; // eax
  _DWORD *v46; // eax
  unsigned int v47; // eax
  int v48; // ebx
  int *v49; // edi
  int v50; // eax
  unsigned int v51; // ecx
  unsigned int v52; // edi
  int *v53; // edx
  _DWORD *v54; // ecx
  int v55; // ebx
  int v56; // ecx
  int v57; // edx
  int *v58; // edi
  int v59; // eax
  int v60; // ecx
  int v61; // ecx
  unsigned int v62; // edx
  int *v63; // ecx
  _DWORD *v64; // ecx
  int v65; // ecx
  _DWORD *v66; // ebx
  int v67; // eax
  int v68; // edi
  int v69; // eax
  _DWORD *v70; // ecx
  int v71; // edx
  int v72; // eax
  int v73; // edi
  int v74; // eax
  _DWORD *v75; // ecx
  int v76; // edx
  unsigned int v77; // eax
  int v78; // ecx
  int v79; // eax
  int v80; // edx
  bool v81; // cf
  unsigned int v82; // eax
  unsigned int v83; // ecx
  int v84; // edi
  unsigned int j; // eax
  char *v86; // ecx
  int v88; // [esp-8h] [ebp-120h]
  _DWORD v89[40]; // [esp+14h] [ebp-104h] BYREF
  _DWORD v90[4]; // [esp+B4h] [ebp-64h] BYREF
  _DWORD v91[4]; // [esp+C4h] [ebp-54h] BYREF
  int v92; // [esp+D4h] [ebp-44h] BYREF
  int v93; // [esp+D8h] [ebp-40h]
  int v94; // [esp+DCh] [ebp-3Ch]
  int v95; // [esp+E0h] [ebp-38h] BYREF
  int v96; // [esp+E4h] [ebp-34h]
  int v97; // [esp+E8h] [ebp-30h]
  unsigned int v98; // [esp+ECh] [ebp-2Ch]
  char *v99; // [esp+F0h] [ebp-28h] BYREF
  unsigned int v100; // [esp+F4h] [ebp-24h]
  _DWORD *v101; // [esp+F8h] [ebp-20h]
  int v102; // [esp+FCh] [ebp-1Ch]
  char *v103; // [esp+100h] [ebp-18h]
  int k; // [esp+104h] [ebp-14h]
  _DWORD *v105; // [esp+108h] [ebp-10h]
  unsigned int v106; // [esp+10Ch] [ebp-Ch] BYREF
  unsigned int v107; // [esp+110h] [ebp-8h]
  int v108; // [esp+114h] [ebp-4h]

  v1 = 0;
  v3 = 0;
  v4 = this[2] == 0;
  v101 = 0;
  v103 = 0;
  if ( !v4 )
  {
    do
    {
      v5 = *(_DWORD **)(this[5] + 4 * v3);
      v6 = v5[1];
      v5[12] = 0;
      if ( v6 == this[34] )
        v5[3] = -1;
      ++v3;
    }
    while ( v3 < this[2] );
  }
  for ( i = this[19]; i < this[137]; ++i )
  {
    v8 = *(_DWORD **)(this[140] + 4 * i);
    if ( v8 && *v8 && v8[3] )
    {
      do
      {
        v9 = *(_DWORD *)(this[5] + 4 * *(_DWORD *)(v8[4] + 4 * v1++));
        *(_DWORD *)(v9 + 72) = i;
      }
      while ( v1 < v8[3] );
      v1 = 0;
    }
  }
  v10 = this[19];
  v98 = this[137];
  v100 = v10;
  if ( v10 >= v98 )
  {
LABEL_137:
    for ( j = this[19]; j < v98; ++j )
      **(_DWORD **)(this[140] + 4 * j) = 0;
    k = 0;
    goto LABEL_146;
  }
  while ( 1 )
  {
    v105 = *(_DWORD **)(this[140] + 4 * v100);
    if ( v105 )
    {
      if ( *v105 )
        break;
    }
LABEL_136:
    if ( ++v100 >= v98 )
      goto LABEL_137;
  }
  v11 = (_DWORD *)sub_681186(116);
  if ( v11 )
    v103 = (char *)sub_680CEC(v11);
  else
    v103 = 0;
  if ( !v103 )
    goto LABEL_142;
  k = sub_681430(v103, v105);
  if ( k < 0 )
    goto LABEL_148;
  if ( this[137] >= 0x200u )
    goto LABEL_142;
  v12 = v105;
  v13 = *v105;
  v97 = 0;
  v94 = 0;
  v14 = v13 & 0xFFF00000;
  if ( v14 == 1342177280 && v105[3] == 1 )
  {
    v15 = (_DWORD *)v105[4];
    v4 = *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *v15) + 16) == 3;
    v102 = *(_DWORD *)(this[5] + 4 * *v15);
    if ( v4 )
    {
      sub_6A7E91(this, this[140], v100, v98, v15, 1, (unsigned int *)&v99, &v95, &v92);
      if ( v92 )
      {
        v16 = sub_681AAA(this, this[34], 0, 3, 0.0);
        if ( v16 == -1 )
          goto LABEL_142;
        v17 = *(_DWORD *)(this[5] + 4 * v16);
        sub_6815D6((double *)v17, v102);
        v18 = this[34];
        *(_DWORD *)(v17 + 60) = 0;
        *(_DWORD *)(v17 + 4) = v18;
        *(_DWORD *)(v17 + 16) = 3;
        v19 = (_DWORD *)sub_681186(116);
        v20 = v19 ? (char *)sub_680CEC(v19) : 0;
        if ( !v20 )
          goto LABEL_142;
        k = sub_6811D1(v20, 268435457, 1, 1, 0);
        if ( k < 0 || (k = sub_680D22(v20, (int)v105), k < 0) )
        {
          v86 = v20;
          goto LABEL_147;
        }
        **((_DWORD **)v20 + 4) = *(_DWORD *)v105[4];
        **((_DWORD **)v20 + 2) = v16;
        v21 = v103;
        **((_DWORD **)v103 + 4) = v16;
        *(_DWORD *)(this[140] + 4 * this[137]++) = v21;
        v99 = v21;
        if ( sub_681997((int)this, v21) < 0 )
          goto LABEL_142;
        v22 = this[137];
        if ( v22 >= 0x200 )
          goto LABEL_142;
        *(_DWORD *)(this[140] + 4 * v22) = v20;
        ++this[137];
        if ( sub_681997((int)this, v20) < 0 )
          goto LABEL_142;
        goto LABEL_36;
      }
LABEL_45:
      if ( sub_681997((int)this, v103) < 0 )
        goto LABEL_142;
      v26 = v103;
      *(_DWORD *)(this[140] + 4 * this[137]++) = v103;
      v99 = v26;
LABEL_36:
      v12 = v105;
      goto LABEL_48;
    }
  }
  if ( v14 != 0x10000000 || !sub_6A32C7(this, (int)v105) )
    goto LABEL_45;
  v23 = v12[3];
  v97 = 1;
  if ( v23 )
  {
    v24 = this[5];
    v25 = (_DWORD *)v12[4];
    do
    {
      if ( *(_DWORD *)(*(_DWORD *)(v24 + 4 * *v25) + 60) )
        v97 = 0;
      ++v25;
      --v23;
    }
    while ( v23 );
    if ( !v97 )
      goto LABEL_45;
  }
  sub_66238F(v103, 1);
  v99 = 0;
LABEL_48:
  v103 = 0;
  if ( !sub_6A32C7(this, (int)v12) )
    goto LABEL_133;
  v102 = 0;
  v106 = 0;
  memset(v91, 255, sizeof(v91));
  v27 = v12[3];
  if ( v27 )
  {
    v28 = this[5];
    do
    {
      v29 = 4 * v106;
      v30 = *(_DWORD *)(4 * v106 + v12[4]);
      v31 = *(_DWORD *)(v28 + 4 * v30);
      if ( *(_DWORD *)(v31 + 48) )
      {
        v32 = *(_DWORD *)(v31 + 16);
        v91[v32] = v30;
        v89[v32 + 32] = *(_DWORD *)(v29 + v12[2]);
        v102 = 1;
      }
      v27 = v12[3];
      ++v106;
    }
    while ( v106 < v27 );
  }
  v88 = v12[4];
  v33 = 0;
  v106 = 0;
  sub_6A7CF3(this, this[140], v100, v98, v88, v27, (int)v89, &v106);
  if ( !v102 )
  {
    if ( v106 )
    {
      do
      {
        v78 = this[5];
        v79 = *(_DWORD *)(v78 + 4 * v89[v33]);
        v80 = *(_DWORD *)(v79 + 56);
        if ( v80 != -1 )
          v79 = *(_DWORD *)(v78 + 4 * v80);
        v81 = ++v33 < v106;
        *(_DWORD *)(v79 + 48) = 1;
      }
      while ( v81 );
    }
LABEL_133:
    v82 = (unsigned int)v99;
    v83 = 0;
    if ( v99 && *((_DWORD *)v99 + 3) )
    {
      do
      {
        v84 = *(_DWORD *)(this[5] + 4 * *(_DWORD *)(*(_DWORD *)(v82 + 16) + 4 * v83++));
        *(_DWORD *)(v84 + 72) = this[137] - 1;
      }
      while ( v83 < *(_DWORD *)(v82 + 12) );
    }
    goto LABEL_136;
  }
  memset(v90, 255, sizeof(v90));
  v34 = 0;
  for ( k = 0; k < v106; ++k )
  {
    v35 = v89[v34];
    v36 = this[5];
    v37 = *(_DWORD **)(v36 + 4 * v35);
    v4 = v37[14] == -1;
    v107 = v35;
    if ( !v4 )
    {
      v107 = v37[14];
      v37 = *(_DWORD **)(v36 + 4 * v107);
    }
    v38 = v37[18];
    if ( (v38 >= v98 || v38 < v100) && v38 != -1 )
    {
      v39 = this[140];
      v108 = 4 * v38;
      v102 = *(_DWORD *)(4 * v38 + v39);
      if ( sub_6A32C7(this, v102) )
      {
        if ( (*(_DWORD *)v102 & 0xFFF00000) == 0x10000000 && v37[14] == -1 )
        {
          v40 = 0;
          if ( *(_DWORD *)(v102 + 12) )
          {
            for ( m = *(_DWORD **)(v102 + 16); v107 != *m; m = v101 )
            {
              v101 = m + 1;
              if ( (unsigned int)++v40 >= *(_DWORD *)(*(_DWORD *)(v108 + this[140]) + 12) )
                goto LABEL_71;
            }
            v89[v37[4] + 36] = *(_DWORD *)(*(_DWORD *)(v102 + 8) + 4 * v40);
            v94 = 1;
          }
        }
LABEL_71:
        v42 = &v90[v37[4]];
        if ( *v42 == -1 )
        {
          *v42 = v107;
        }
        else if ( *v42 != v107 )
        {
LABEL_139:
          sub_686791(
            (int)this,
            v12[15],
            4537,
            "unable to emmulate write masks for ps_1_%i shader model",
            (unsigned __int8)this[50]);
          return -2147467259;
        }
      }
    }
    v34 = k + 1;
  }
  v43 = 0;
  v44 = 0;
  v106 = 0;
  while ( 2 )
  {
    if ( v90[v44] == -1 )
    {
      if ( v91[v44] != -1 )
        goto LABEL_80;
    }
    else
    {
      if ( v91[v44] != -1 )
        goto LABEL_139;
LABEL_80:
      v106 = ++v43;
    }
    if ( (unsigned int)++v44 < 4 )
      continue;
    break;
  }
  v45 = (_DWORD *)sub_681186(116);
  if ( v45 )
    v46 = sub_680CEC(v45);
  else
    v46 = 0;
  v101 = v46;
  if ( !v46 )
    return -2147024882;
  k = sub_6811D1((char *)v46, v43 & 0xFFFFF | 0x70100000, 3 * v43, v43, 0);
  if ( k < 0 )
    goto LABEL_146;
  k = sub_680D22(v101, (int)v105);
  if ( k < 0 )
    goto LABEL_146;
  v108 = 0;
  v102 = 0;
  v107 = 4 * v106;
  v47 = 0;
  while ( 2 )
  {
    v48 = *(_DWORD *)((char *)v91 + v47);
    if ( v48 != -1 )
    {
      v4 = v97 == 0;
      *(_DWORD *)(v101[4] + 4 * v108) = v48;
      if ( v4 )
      {
        v49 = *(int **)(this[5] + 4 * v48);
        v50 = sub_681AAA(this, this[34], 0, v49[4], 0.0);
        if ( v50 == -1 )
          goto LABEL_142;
        *(_DWORD *)(*(_DWORD *)(this[5] + 4 * v50) + 60) = v49[15];
        v49[15] = 0;
        v49[18] = this[137];
        v51 = (unsigned int)v99;
        v52 = 0;
        if ( *((_DWORD *)v99 + 3) )
        {
          do
          {
            v53 = (int *)(*(_DWORD *)(v51 + 16) + 4 * v52);
            if ( *v53 == v48 )
              *v53 = v50;
            ++v52;
          }
          while ( v52 < *(_DWORD *)(v51 + 12) );
        }
      }
      else
      {
        v50 = *(_DWORD *)((char *)&v89[32] + v47);
        *(_DWORD *)(*(_DWORD *)(this[5] + 4 * v48) + 72) = this[137];
      }
      v54 = v101;
      *(_DWORD *)(v107 + v101[2]) = v50;
      v93 = v50;
      *(_DWORD *)(v54[2] + 4 * v108) = this[273];
      goto LABEL_111;
    }
    v55 = *(_DWORD *)((char *)v90 + v47);
    if ( v55 != -1 )
    {
      v56 = v101[4];
      v57 = 4 * v108;
      v4 = v94 == 0;
      v96 = v57;
      *(_DWORD *)(v57 + v56) = v55;
      if ( v4 )
      {
        v58 = *(int **)(this[5] + 4 * v55);
        v59 = sub_681AAA(this, this[34], 0, v58[4], 0.0);
        if ( v59 == -1 )
          goto LABEL_142;
        *(_DWORD *)(*(_DWORD *)(this[5] + 4 * v59) + 60) = v58[15];
        v60 = v58[18];
        v58[15] = 0;
        if ( v60 == -1 || v60 == this[137] )
        {
          sub_686791((int)this, v105[15], 4810, "internal error: illformed write field");
          goto LABEL_146;
        }
        v61 = *(_DWORD *)(this[140] + 4 * v60);
        v62 = 0;
        v4 = *(_DWORD *)(v61 + 12) == 0;
        v95 = v61;
        if ( !v4 )
        {
          do
          {
            v63 = (int *)(*(_DWORD *)(v61 + 16) + 4 * v62);
            if ( *v63 == v55 )
              *v63 = v59;
            v61 = v95;
            ++v62;
          }
          while ( v62 < *(_DWORD *)(v95 + 12) );
        }
        v57 = v96;
        v58[18] = this[137];
      }
      else
      {
        v59 = *(_DWORD *)((char *)&v89[36] + v47);
        *(_DWORD *)(*(_DWORD *)(this[5] + 4 * v55) + 72) = this[137];
      }
      v64 = v101;
      *(_DWORD *)(v57 + v101[2]) = this[272];
      v65 = v64[2];
      v96 = v59;
      *(_DWORD *)(v65 + 4 * (v108 + 2 * v106)) = v59;
LABEL_111:
      ++v108;
      v107 += 4;
      v47 = v102;
    }
    v47 += 4;
    v102 = v47;
    if ( v47 < 0x10 )
      continue;
    break;
  }
  v108 = 0;
  v66 = v101;
  v105 = 0;
  v107 = 4 * v106;
  while ( 2 )
  {
    v67 = *(_DWORD *)((char *)v91 + (_DWORD)v105);
    if ( v67 != -1 )
    {
      v68 = *(_DWORD *)(this[5] + 4 * v67);
      v69 = sub_681AAA(this, this[34], 0, *(_DWORD *)(v68 + 16), 0.0);
      if ( v69 == -1 )
        goto LABEL_142;
      v70 = *(_DWORD **)(this[5] + 4 * v69);
      v71 = v96;
      v4 = v96 == -1;
      v70[14] = v96;
      v70[15] = *(_DWORD *)(v68 + 60);
      if ( !v4 )
        v70[1] = *(_DWORD *)(*(_DWORD *)(this[5] + 4 * v71) + 4);
      *(_DWORD *)(v66[2] + 4 * (v108 + 2 * v106)) = v69;
      goto LABEL_124;
    }
    v72 = *(_DWORD *)((char *)v90 + (_DWORD)v105);
    if ( v72 != -1 )
    {
      v73 = *(_DWORD *)(this[5] + 4 * v72);
      v74 = sub_681AAA(this, this[34], 0, *(_DWORD *)(v73 + 16), 0.0);
      if ( v74 == -1 )
        goto LABEL_142;
      v75 = *(_DWORD **)(this[5] + 4 * v74);
      v76 = v93;
      v4 = v93 == -1;
      v75[14] = v93;
      v75[15] = *(_DWORD *)(v73 + 60);
      if ( !v4 )
        v75[1] = *(_DWORD *)(*(_DWORD *)(this[5] + 4 * v76) + 4);
      *(_DWORD *)(v107 + v66[2]) = v74;
LABEL_124:
      ++v108;
      v107 += 4;
    }
    if ( (unsigned int)++v105 < 0x10 )
      continue;
    break;
  }
  v77 = this[137];
  if ( v77 < 0x200 )
  {
    *(_DWORD *)(this[140] + 4 * v77) = v66;
    ++this[137];
    if ( sub_681997((int)this, v66) >= 0 )
    {
      v101 = 0;
      goto LABEL_133;
    }
  }
LABEL_142:
  k = -2147024882;
LABEL_146:
  v86 = (char *)v101;
  if ( v101 )
LABEL_147:
    sub_66238F(v86, 1);
LABEL_148:
  if ( v103 )
    sub_66238F(v103, 1);
  return k;
}
