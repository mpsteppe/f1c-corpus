int __thiscall sub_546AA0(float *this, char a2, const char *a3)
{
  int v3; // ebx
  int v4; // esi
  int v5; // ecx
  int v6; // esi
  int v7; // eax
  int v8; // esi
  int v9; // edi
  char *v10; // ebp
  _DWORD *v11; // eax
  int v13; // eax
  int v14; // edi
  int v15; // ebp
  int v16; // eax
  int v17; // ecx
  char v18; // dl
  char *v19; // edi
  char *v20; // eax
  int v21; // edx
  char v22; // cl
  int v23; // eax
  int v24; // edi
  _BYTE *v25; // ebp
  float *v26; // edi
  int v27; // eax
  int v28; // edi
  _DWORD *v29; // eax
  char *v30; // ebx
  _DWORD *v31; // ebp
  char *v32; // edi
  int v33; // ebx
  int v34; // eax
  int v35; // eax
  int v36; // eax
  bool v37; // cc
  int v38; // eax
  int i; // edi
  int v41; // ecx
  int v42; // eax
  void *v43; // ebp
  int v44; // edi
  int v45; // eax
  int v46; // ebx
  int v47; // [esp-4h] [ebp-16Ch]
  const char *v49; // [esp+14h] [ebp-154h]
  int v50; // [esp+18h] [ebp-150h]
  char v51[8]; // [esp+20h] [ebp-148h] BYREF
  char v52[64]; // [esp+28h] [ebp-140h] BYREF
  _BYTE v53[256]; // [esp+68h] [ebp-100h] BYREF

  memset(v53, 0, sizeof(v53));
  v3 = 0;
  v4 = 0;
  if ( (a2 & 1) == 0 )
  {
    if ( (a2 & 2) != 0 )
    {
      v4 = 1;
    }
    else if ( (a2 & 4) != 0 )
    {
      v4 = 2;
    }
    else if ( (a2 & 8) != 0 )
    {
      v4 = 3;
    }
    else if ( (a2 & 0x10) != 0 )
    {
      v4 = 4;
    }
    else if ( (a2 & 0x20) != 0 )
    {
      v4 = 5;
    }
    else if ( (a2 & 0x40) != 0 )
    {
      v4 = 6;
    }
    else if ( a2 < 0 )
    {
      v4 = 7;
    }
  }
  v5 = *((_DWORD *)this + 42);
  v6 = 148 * v4;
  v7 = *(_DWORD *)(v6 + v5 + 140);
  v8 = v5 + v6;
  if ( v7 )
  {
    if ( *(int *)(v8 + 72) > 0 )
    {
      v9 = 0;
      v10 = v53;
      do
      {
        strcpy(v10, (const char *)(v9 + *(_DWORD *)(v8 + 140) + 4));
        ++v3;
        v9 += 96;
        v10 += 32;
      }
      while ( v3 < *(_DWORD *)(v8 + 72) );
    }
    v11 = *(_DWORD **)(v8 + 140);
    if ( (*v11)-- == 1 )
    {
      v13 = *(_DWORD *)(v8 + 140);
      v14 = 0;
      if ( *(int *)(v13 + 76) > 0 )
      {
        v15 = 0;
        do
        {
          DestructorWithConditionalFreeFlagClear(v13 + v15);
          v13 = *(_DWORD *)(v8 + 140);
          ++v14;
          v15 += 96;
        }
        while ( v14 < *(_DWORD *)(v13 + 76) );
      }
      DoublyLinkedListNodeRemovalWithArrayCleanup(*(_DWORD *)(v8 + 140));
    }
    *(_DWORD *)(v8 + 140) = 0;
  }
  if ( a3 )
  {
    strcpy(v52, a3);
    v16 = 0;
    v17 = strlen(v52);
    do
    {
      v18 = *((_BYTE *)&dword_5CC79C + v16);
      v51[v16++] = v18;
    }
    while ( v18 );
    if ( v17 > 0 )
    {
      while ( v52[v17] != 46 )
      {
        if ( --v17 <= 0 )
          goto LABEL_36;
      }
      v19 = &v52[v17];
      v20 = &v52[v17];
      v21 = v51 - &v52[v17];
      do
      {
        v22 = *v20;
        v20[v21] = *v20;
        ++v20;
      }
      while ( v22 );
      *v19 = 0;
    }
LABEL_36:
    v23 = *(_DWORD *)(v8 + 72);
    v24 = 0;
    if ( v23 > 0 )
    {
      v25 = v53;
      do
      {
        if ( v23 <= 1 )
          StringFormatWithBufferOverflowCheck(v25, "%s%s", v52, v51);
        else
          StringFormatWithBufferOverflowCheck(v25, "%s%.2d%s", v52, v24, v51);
        v23 = *(_DWORD *)(v8 + 72);
        ++v24;
        v25 += 32;
      }
      while ( v24 < v23 );
    }
  }
  SelfRelativeCopyNormalize((LPCSTR)v8, a3);
  v26 = this;
  if ( !v52[0] )
    goto LABEL_75;
  v27 = StringSearchInLinkedList(a3);
  if ( v27 && (*(_DWORD *)(v8 + 64) & 0x100) == 0 )
  {
    *(_DWORD *)(v8 + 140) = v27;
LABEL_74:
    ++**(_DWORD **)(v8 + 140);
LABEL_75:
    if ( ((_BYTE)v26[39] & 0x40) != 0 )
    {
      v38 = LinkedListFloatSearch(v26[44]);
      *((_DWORD *)v26 + 45) = v38;
      if ( !v38 )
      {
        LinkedListNodeAppend_89a0(*((_DWORD *)v26 + 44));
        *((_DWORD *)v26 + 45) = LinkedListFloatSearch(v26[44]);
      }
    }
    *((_DWORD *)v26 + 39) &= ~2u;
    return 0;
  }
  v28 = *(_DWORD *)(v8 + 72);
  v29 = (_DWORD *)OperatorNewNhMallocWrapper(96 * v28 + 4);
  if ( v29 )
  {
    v30 = (char *)(v29 + 1);
    *v29 = v28;
    v31 = v29 + 1;
    if ( v28 - 1 >= 0 )
    {
      do
      {
        StructInitWithZeroFill(v31);
        v31 += 24;
        --v28;
      }
      while ( v28 );
    }
    v32 = v30;
  }
  else
  {
    v32 = 0;
  }
  v47 = *(_DWORD *)(v8 + 72);
  *(_DWORD *)(v8 + 140) = v32;
  StructFieldSetterAt0x4c(v47);
  if ( *(int *)(v8 + 72) > 1 )
    *((_DWORD *)this + 39) |= 0x400u;
  v50 = 0;
  if ( *(int *)(v8 + 72) <= 0 )
  {
LABEL_73:
    sub_547860(*(_DWORD *)(v8 + 140));
    v26 = this;
    goto LABEL_74;
  }
  v33 = 0;
  v49 = v53;
  while ( 1 )
  {
    strcpy(v32 + 4, v49);
    v34 = *(_DWORD *)(v8 + 64);
    v33 |= 4u;
    if ( (v34 & 0x80u) != 0 )
      v33 |= 0x800u;
    if ( dword_8B8E24 && (v34 & 0xC) != 0 )
    {
      *((_DWORD *)v32 + 20) = *(_DWORD *)(v8 + 68) + 1;
      v35 = *(_DWORD *)(v8 + 64);
      if ( (v35 & 8) != 0 )
      {
        v33 |= 0x2000u;
      }
      else if ( (v35 & 4) != 0 )
      {
        v33 |= 0x4000u;
      }
    }
    else
    {
      *(_DWORD *)(v8 + 64) = v34 & 0xFFFFFFF3;
      *((_DWORD *)v32 + 20) = 1;
    }
    if ( (*(_BYTE *)(v8 + 64) & 1) != 0 )
      *((_DWORD *)v32 + 17) |= 1u;
    if ( (*(_DWORD *)(v8 + 96) & 0x400000) != 0 )
      v33 |= (unsigned int)&unk_800000;
    if ( D3DTextureCreation(v32 + 4, *(_DWORD *)(v8 + 128), v33) )
      break;
    if ( *(int *)(*(_DWORD *)(v8 + 140) + 80) > 1 )
    {
      v36 = *(_DWORD *)(v8 + 64);
      if ( (v36 & 0xC) == 0 )
        *(_DWORD *)(v8 + 64) = v36 | 8;
    }
    v32 += 96;
    v37 = ++v50 < *(_DWORD *)(v8 + 72);
    v49 += 32;
    if ( !v37 )
      goto LABEL_73;
  }
  for ( i = v50; i > 0; ++i )
    DestructorWithConditionalFreeFlagClear(*(_DWORD *)(v8 + 140));
  v41 = *(_DWORD *)(v8 + 140);
  if ( v41 )
  {
    v42 = *(_DWORD *)(v41 - 4);
    v43 = (void *)(v41 - 4);
    v44 = v41 + 96 * v42;
    v45 = v42 - 1;
    if ( v45 >= 0 )
    {
      v46 = v45 + 1;
      do
      {
        v44 -= 96;
        EmptyStub_7470(v44);
        --v46;
      }
      while ( v46 );
    }
    FreeWrapper_7bcf(v43);
  }
  *(_DWORD *)(v8 + 140) = 0;
  return -1;
}

