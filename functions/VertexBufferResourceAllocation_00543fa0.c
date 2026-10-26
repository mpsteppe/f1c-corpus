int __thiscall sub_543FA0(_DWORD *this)
{
  _DWORD *v1; // ebx
  int v2; // ecx
  int v3; // eax
  void *v4; // ebp
  int v5; // edx
  int v6; // eax
  int v7; // esi
  int v8; // edi
  int v9; // esi
  _DWORD *v10; // eax
  _DWORD *v11; // ebp
  _DWORD *v12; // edi
  int v13; // esi
  int i; // ebp
  int v15; // esi
  int v17; // eax
  void *v18; // ebp
  int v19; // esi
  int v20; // edi
  int v21; // eax
  void *v22; // ebp
  int v23; // esi
  int v24; // edi
  int v25; // eax
  void *v26; // ebp
  int v27; // esi
  int v28; // edi
  int v29; // eax
  void *v30; // ebp
  int v31; // esi
  int v32; // edi
  _DWORD *v33; // eax
  int v34; // esi
  int *v35; // eax
  _DWORD *v36; // edi
  int v37; // esi
  int *v38; // eax
  _DWORD *v39; // edi
  int v40; // esi
  int *v41; // eax
  _DWORD *v42; // edi
  int v43; // esi
  int *v44; // eax
  _DWORD *v45; // edi
  _DWORD *v46; // ebx
  int v47; // eax
  _DWORD *v48; // ebp
  int v49; // eax
  void *v50; // eax
  unsigned int v51; // edx
  int v52; // edi
  _DWORD *v53; // esi
  void *v54; // eax
  int v55; // [esp+10h] [ebp-30h]
  int v56; // [esp+14h] [ebp-2Ch]
  int v57; // [esp+18h] [ebp-28h]
  int v58; // [esp+1Ch] [ebp-24h]
  int v59; // [esp+20h] [ebp-20h]
  int v60; // [esp+24h] [ebp-1Ch]
  int v61; // [esp+28h] [ebp-18h]
  int v62; // [esp+2Ch] [ebp-14h]
  int v63; // [esp+30h] [ebp-10h]
  int v64; // [esp+34h] [ebp-Ch]
  _DWORD *v65; // [esp+38h] [ebp-8h]
  int v66; // [esp+3Ch] [ebp-4h]

  v1 = this;
  v2 = this[84];
  v65 = v1;
  if ( v2 )
  {
    v3 = *(_DWORD *)(v2 - 4);
    v4 = (void *)(v2 - 4);
    v5 = 3 * v3;
    v6 = v3 - 1;
    v7 = v2 + 8 * v5;
    if ( v6 >= 0 )
    {
      v8 = v6 + 1;
      do
      {
        v7 -= 24;
        EmptyStub_0170();
        --v8;
      }
      while ( v8 );
    }
    FreeWrapper_7bcf(v4);
    v1[84] = 0;
    v1[83] = 0;
  }
  v9 = v1[25];
  v10 = (_DWORD *)OperatorNewNhMallocWrapper(24 * v9 + 4);
  if ( v10 )
  {
    v11 = v10 + 1;
    *v10 = v9;
    v12 = v10 + 1;
    if ( v9 - 1 >= 0 )
    {
      do
      {
        ShortComputation_8e00(v12);
        v12 += 6;
        --v9;
      }
      while ( v9 );
    }
  }
  else
  {
    v11 = 0;
  }
  v13 = v1[64];
  v1[84] = v11;
  for ( i = 0; v13; v13 = *(_DWORD *)(v13 + 260) )
  {
    if ( *(_DWORD *)(v13 + 236) )
      SceneGraphRenderWalk();
  }
  if ( v1[66] )
    SceneGraphRenderWalk();
  v15 = v1[66];
  if ( v15 )
  {
    do
    {
      if ( AudioNetworkTreeWalker(v15, 0) )
        return -1;
      if ( ++i % 2 )
      {
        InterlockedDecrement(&Addend);
        AudioVolumeLoadComputation(0);
      }
      v15 = *(_DWORD *)(v15 + 76);
    }
    while ( v15 );
    i = 0;
  }
  if ( (v1[59] & 4) == 0 )
  {
    if ( v1[68] )
    {
      if ( LinkedListWalkInterlockedDec() )
        return -1;
      LinkedListAccumulation(v1[68]);
    }
    if ( sub_544740(v1) )
      return -1;
    UILinkedListCleanupIterator(v1);
    sub_545A40(v1);
    SceneInstanceCollection(v1);
  }
  v17 = v1[110];
  if ( v17 )
  {
    v18 = (void *)(v17 - 4);
    v19 = v17 + 528 * *(_DWORD *)(v17 - 4);
    if ( *(_DWORD *)(v17 - 4) - 1 >= 0 )
    {
      v20 = *(_DWORD *)(v17 - 4);
      do
      {
        v19 -= 528;
        CleanupFunction(v19);
        --v20;
      }
      while ( v20 );
    }
    FreeWrapper_7bcf(v18);
    i = 0;
    v1[110] = 0;
    v1[109] = 0;
  }
  v21 = v1[112];
  if ( v21 )
  {
    v22 = (void *)(v21 - 4);
    v23 = v21 + 528 * *(_DWORD *)(v21 - 4);
    if ( *(_DWORD *)(v21 - 4) - 1 >= 0 )
    {
      v24 = *(_DWORD *)(v21 - 4);
      do
      {
        v23 -= 528;
        CleanupFunction(v23);
        --v24;
      }
      while ( v24 );
    }
    FreeWrapper_7bcf(v22);
    i = 0;
    v1[112] = 0;
    v1[111] = 0;
  }
  v25 = v1[114];
  if ( v25 )
  {
    v26 = (void *)(v25 - 4);
    v27 = v25 + 528 * *(_DWORD *)(v25 - 4);
    if ( *(_DWORD *)(v25 - 4) - 1 >= 0 )
    {
      v28 = *(_DWORD *)(v25 - 4);
      do
      {
        v27 -= 528;
        CleanupFunction(v27);
        --v28;
      }
      while ( v28 );
    }
    FreeWrapper_7bcf(v26);
    i = 0;
    v1[114] = 0;
    v1[113] = 0;
  }
  v29 = v1[116];
  if ( v29 )
  {
    v30 = (void *)(v29 - 4);
    v31 = v29 + 528 * *(_DWORD *)(v29 - 4);
    if ( *(_DWORD *)(v29 - 4) - 1 >= 0 )
    {
      v32 = *(_DWORD *)(v29 - 4);
      do
      {
        v31 -= 528;
        CleanupFunction(v31);
        --v32;
      }
      while ( v32 );
    }
    FreeWrapper_7bcf(v30);
    i = 0;
    v1[116] = 0;
    v1[115] = 0;
  }
  v33 = (_DWORD *)v1[68];
  v1[17] = v33[5];
  v34 = v1[17];
  v1[18] = v33[6];
  v1[19] = v33[7];
  v1[20] = v33[8];
  v1[109] = v34;
  if ( v34 > 0 )
  {
    v35 = (int *)OperatorNewNhMallocWrapper(528 * v34 + 4);
    if ( v35 )
    {
      i = (int)(v35 + 1);
      *v35 = v34;
      v36 = v35 + 1;
      if ( v34 - 1 >= 0 )
      {
        do
        {
          sub_557240(v36);
          v36 += 132;
          --v34;
        }
        while ( v34 );
      }
    }
    v1[110] = i;
    i = 0;
  }
  v37 = v1[18];
  v1[111] = v37;
  if ( v37 > 0 )
  {
    v38 = (int *)OperatorNewNhMallocWrapper(528 * v37 + 4);
    if ( v38 )
    {
      i = (int)(v38 + 1);
      *v38 = v37;
      v39 = v38 + 1;
      if ( v37 - 1 >= 0 )
      {
        do
        {
          sub_557240(v39);
          v39 += 132;
          --v37;
        }
        while ( v37 );
      }
    }
    v1[112] = i;
    i = 0;
  }
  v40 = v1[19];
  v1[113] = v40;
  if ( v40 > 0 )
  {
    v41 = (int *)OperatorNewNhMallocWrapper(528 * v40 + 4);
    if ( v41 )
    {
      i = (int)(v41 + 1);
      *v41 = v40;
      v42 = v41 + 1;
      if ( v40 - 1 >= 0 )
      {
        do
        {
          sub_557240(v42);
          v42 += 132;
          --v40;
        }
        while ( v40 );
      }
    }
    v1[114] = i;
    i = 0;
  }
  v43 = v1[20];
  v1[115] = v43;
  if ( v43 > 0 )
  {
    v44 = (int *)OperatorNewNhMallocWrapper(528 * v43 + 4);
    if ( v44 )
    {
      i = (int)(v44 + 1);
      *v44 = v43;
      v45 = v44 + 1;
      if ( v43 - 1 >= 0 )
      {
        do
        {
          sub_557240(v45);
          v45 += 132;
          --v43;
        }
        while ( v43 );
      }
    }
    v1[116] = i;
  }
  v66 = v1[109] + v1[111] + v1[113] + v1[115];
  v61 = 0;
  v63 = 0;
  v57 = 0;
  v59 = 0;
  v56 = 0;
  if ( v66 > 0 )
  {
    v64 = 0;
    v62 = 0;
    v60 = 0;
    v58 = 0;
    while ( 1 )
    {
      v46 = (_DWORD *)sub_548850(v56);
      v47 = v46[39];
      if ( (v47 & 0x20) != 0 )
      {
        if ( (v47 & 0x100) != 0 )
        {
          v46[40] = v57;
          v48 = (_DWORD *)(v58 + v65[114]);
          ++v57;
          v58 += 528;
        }
        else
        {
          v46[40] = v59;
          v48 = (_DWORD *)(v60 + v65[116]);
          ++v59;
          v60 += 528;
        }
      }
      else if ( (v47 & 0x100) != 0 )
      {
        v46[40] = v61;
        v48 = (_DWORD *)(v62 + v65[110]);
        ++v61;
        v62 += 528;
      }
      else
      {
        v46[40] = v63;
        v48 = (_DWORD *)(v64 + v65[112]);
        ++v63;
        v64 += 528;
      }
      v49 = ShortComputation_6720(v46);
      v48[129] = v49;
      if ( v49 > 0 )
      {
        v50 = (void *)OperatorNewNhMallocWrapper(16 * v49);
        v51 = 16 * v48[129];
        v48[131] = v50;
        memset(v50, 0, v51);
        *v48 = 256;
        v55 = 0;
        if ( (int)v46[41] > 0 )
          break;
      }
LABEL_123:
      if ( ++v56 >= v66 )
      {
        v1 = v65;
        goto LABEL_125;
      }
    }
    v52 = v46[42] + 64;
    v53 = v48 + 10;
    while ( 1 )
    {
      v54 = *(void **)(v52 + 32);
      if ( (int)v54 <= (int)&unk_800000 )
        break;
      if ( v54 == &unk_804000 )
        goto LABEL_101;
LABEL_102:
      if ( (v46[39] & 0x800) != 0 )
        *v48 |= 4u;
      if ( (v46[39] & 0x40) != 0 )
        *v48 |= 0x400u;
      if ( (*(_BYTE *)v52 & 0xC) != 0 )
        v53[3] = 1;
      if ( (v46[39] & 0x20) != 0 )
      {
        *v48 |= 0x800u;
        *v53 = 2;
      }
      if ( *(char *)v52 < 0 )
      {
        *v48 |= 1u;
        *v53 = 3;
      }
      if ( (*(_DWORD *)v52 & 0x200) != 0 )
        *(v53 - 1) = 6;
      v53[4] = 0;
      if ( (*(_DWORD *)v52 & 0x400) != 0 )
      {
        v53[4] = 1;
      }
      else if ( (*(_DWORD *)v52 & 0x1000) != 0 )
      {
        v53[4] = 2;
      }
      v53[5] = 0;
      if ( (*(_DWORD *)v52 & 0x800) != 0 )
      {
        v53[5] = 1;
      }
      else if ( (*(_DWORD *)v52 & 0x2000) != 0 )
      {
        v53[5] = 2;
      }
      v52 += 148;
      v53 += 16;
      if ( ++v55 >= v46[41] )
        goto LABEL_123;
    }
    if ( v54 != &unk_800000 )
    {
      if ( v54 == (void *)0x100000 )
      {
        if ( v55 <= 0 || v55 % Field0x13B0Accessor(dword_8B78A0) )
        {
          switch ( *(_DWORD *)(v52 + 36) )
          {
            case 1:
              *(v53 - 1) = 1;
              *v53 = 2;
              v53[1] = *(_DWORD *)(v52 + 44);
              break;
            case 2:
              *(v53 - 1) = 2;
              *v53 = 2;
              v53[1] = *(_DWORD *)(v52 + 44);
              break;
            case 3:
              *(v53 - 1) = 3;
              *v53 = 4;
              v53[1] = *(_DWORD *)(v52 + 44);
              break;
            case 4:
              *v53 = 2;
              *(v53 - 1) = 4;
              v53[1] = *(_DWORD *)(v52 + 44);
              break;
            case 5:
              *(v53 - 1) = 9;
              *v53 = 4;
              v53[1] = *(_DWORD *)(v52 + 44);
              break;
            case 6:
              *(v53 - 1) = 10;
              *v53 = 4;
              v53[1] = *(_DWORD *)(v52 + 44);
              break;
            case 7:
              *(v53 - 1) = 11;
              *v53 = 4;
              goto LABEL_99;
            default:
LABEL_99:
              v53[1] = *(_DWORD *)(v52 + 44);
              break;
          }
        }
        else
        {
          *(v53 - 1) = 1;
          *v53 = 2;
          v53[1] = *(_DWORD *)(v52 + 44);
        }
      }
      else if ( v54 == (void *)0x400000 )
      {
        *v48 |= 0x800u;
        *(v53 - 1) = 2;
        *v53 = 2;
        v53[1] = 0;
      }
      goto LABEL_102;
    }
LABEL_101:
    *(v53 - 1) = 8;
    *v53 = 1;
    *(_DWORD *)(v52 + 44) = 1;
    v53[1] = 1;
    goto LABEL_102;
  }
LABEL_125:
  DoublyLinkedListNodeRemovalByFlag();
  BitFlagArrayUpdate(v1);
  return 0;
}
