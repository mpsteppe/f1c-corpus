int __thiscall sub_546450(int this, int a2)
{
  int v2; // ebx
  int v3; // eax
  int v4; // ecx
  int v5; // eax
  int v6; // esi
  int v7; // ecx
  int v8; // esi
  int v9; // eax
  int v10; // esi
  int v11; // eax
  int v12; // eax
  _DWORD *v13; // eax
  int v14; // edi
  _DWORD *v15; // eax
  _DWORD *v16; // ebp
  _DWORD *v17; // edi
  int v18; // eax
  int v19; // edi
  _DWORD *v20; // eax
  char *v21; // ebx
  _DWORD *v22; // ebp
  char *v23; // eax
  char *v24; // ebx
  int v25; // eax
  int v26; // ecx
  char v27; // dl
  _BYTE *v28; // edi
  char *v29; // eax
  char *v30; // edx
  char v31; // cl
  int v32; // eax
  char *v33; // ecx
  char *v34; // ebp
  int v35; // ebx
  int v36; // eax
  int v37; // eax
  void *v38; // edi
  void *v39; // edi
  int v40; // eax
  int v41; // eax
  int v42; // eax
  int v43; // ecx
  char *v44; // eax
  char v45; // cl
  bool v46; // cc
  int v47; // eax
  void *v49; // esi
  int v50; // [esp-4h] [ebp-54h]
  int v51; // [esp-4h] [ebp-54h]
  int v52; // [esp+10h] [ebp-40h]
  char *v54; // [esp+18h] [ebp-38h]
  char *v55; // [esp+1Ch] [ebp-34h]
  _DWORD *v56; // [esp+20h] [ebp-30h]
  int v57; // [esp+20h] [ebp-30h]
  int v58; // [esp+24h] [ebp-2Ch]
  char v59[4]; // [esp+28h] [ebp-28h] BYREF
  int v60; // [esp+2Ch] [ebp-24h] BYREF
  char v61[32]; // [esp+30h] [ebp-20h] BYREF
  int v62; // [esp+54h] [ebp+4h]

  v2 = this;
  v3 = *(_DWORD *)(this + 156);
  v52 = 0;
  if ( (v3 & 1) == 0 || (v3 & 2) == 0 )
    return 0;
  if ( a2 == -1 )
  {
    v4 = *(_DWORD *)(this + 164);
    v5 = 0;
  }
  else
  {
    v5 = a2;
    v4 = a2 + 1;
  }
  v6 = v5;
  v62 = v4;
  v58 = v5;
  if ( v5 >= v4 )
    return 0;
  while ( 1 )
  {
    v7 = *(_DWORD *)(v2 + 168);
    v8 = 148 * v6;
    v9 = *(_DWORD *)(v8 + v7 + 96);
    v10 = v7 + v8;
    if ( v9 != 0x8000000 )
    {
      if ( !*(_BYTE *)v10 )
      {
LABEL_92:
        if ( (*(_BYTE *)(v2 + 156) & 0x40) != 0 )
        {
          v47 = LinkedListFloatSearch(*(float *)(v2 + 176));
          *(_DWORD *)(v2 + 180) = v47;
          if ( !v47 )
          {
            LinkedListNodeAppend_89a0(*(_DWORD *)(v2 + 176));
            *(_DWORD *)(v2 + 180) = LinkedListFloatSearch(*(float *)(v2 + 176));
          }
        }
        goto LABEL_95;
      }
      v18 = StringSearchInLinkedList(v10);
      if ( v18 && (*(_DWORD *)(v10 + 64) & 0x100) == 0 )
      {
        *(_DWORD *)(v10 + 140) = v18;
LABEL_91:
        ++**(_DWORD **)(v10 + 140);
        goto LABEL_92;
      }
      v19 = *(_DWORD *)(v10 + 72);
      v20 = (_DWORD *)OperatorNewNhMallocWrapper(96 * v19 + 4);
      if ( v20 )
      {
        v21 = (char *)(v20 + 1);
        *v20 = v19;
        v22 = v20 + 1;
        if ( v19 - 1 >= 0 )
        {
          do
          {
            StructInitWithZeroFill(v22);
            v22 += 24;
            --v19;
          }
          while ( v19 );
        }
        v23 = v21;
      }
      else
      {
        v23 = 0;
      }
      v24 = v23;
      v51 = *(_DWORD *)(v10 + 72);
      *(_DWORD *)(v10 + 140) = v23;
      v54 = v23;
      StructFieldSetterAt0x4c(v51);
      if ( *(int *)(v10 + 72) > 1 )
        *(_DWORD *)(this + 156) |= 0x400u;
      v25 = 0;
      v26 = strlen((const char *)v10);
      do
      {
        v27 = *((_BYTE *)&dword_5CC79C + v25);
        v59[v25++] = v27;
      }
      while ( v27 );
      if ( v26 > 0 )
      {
        while ( *(_BYTE *)(v26 + v10) != 46 )
        {
          if ( --v26 <= 0 )
            goto LABEL_42;
        }
        v28 = (_BYTE *)(v26 + v10);
        v29 = (char *)(v26 + v10);
        v30 = &v59[-v26 - v10];
        do
        {
          v31 = *v29;
          v29[(_DWORD)v30] = *v29;
          ++v29;
        }
        while ( v31 );
        *v28 = 0;
      }
LABEL_42:
      v32 = *(_DWORD *)(v10 + 72);
      v57 = 0;
      if ( v32 <= 0 )
      {
LABEL_90:
        sub_547860(*(_DWORD *)(v10 + 140));
        v2 = this;
        goto LABEL_91;
      }
      v33 = (char *)((char *)&v60 - v24);
      v34 = v24 + 4;
      v35 = v52;
      v55 = v33;
      while ( 1 )
      {
        if ( v32 <= 1 )
          StringFormatWithBufferOverflowCheck(v34, "%s%s", (const char *)v10, v59);
        else
          StringFormatWithBufferOverflowCheck(v34, "%s%.2d%s", (const char *)v10, v57, v59);
        v36 = *(_DWORD *)(v10 + 96);
        if ( ((unsigned int)&unk_800000 & v36) != 0 && (v36 & 0x4000) != 0 )
        {
          v35 &= ~4u;
          *(_DWORD *)(v10 + 64) |= 2u;
        }
        v37 = *(_DWORD *)(v10 + 64);
        if ( (v37 & 2) != 0 )
        {
          if ( dword_8B8DBC )
          {
            sub_542E50((_DWORD *)dword_8B8DBC);
            v38 = (void *)dword_8B8DBC;
            if ( dword_8B8DBC )
            {
              EmptyStub_7470(dword_8B8DBC);
              FreeWrapper_7bcf(v38);
            }
            dword_8B8DBC = 0;
          }
          else if ( dword_8B8DC0 )
          {
            sub_542E50((_DWORD *)dword_8B8DC0);
            v39 = (void *)dword_8B8DC0;
            if ( dword_8B8DC0 )
            {
              EmptyStub_7470(dword_8B8DC0);
              FreeWrapper_7bcf(v39);
            }
            dword_8B8DC0 = 0;
          }
          v35 |= 0x40008u;
          *(_DWORD *)(v10 + 64) |= 1u;
        }
        else
        {
          v35 |= 4u;
          v52 = v35;
          if ( (v37 & 0x80u) == 0 )
            goto LABEL_63;
          v35 |= 0x800u;
        }
        v52 = v35;
LABEL_63:
        if ( dword_8B8E24 && (*(_BYTE *)(v10 + 64) & 0xC) != 0 )
        {
          *((_DWORD *)v34 + 19) = *(_DWORD *)(v10 + 68) + 1;
          v40 = *(_DWORD *)(v10 + 64);
          if ( (v40 & 8) != 0 )
          {
            v35 |= 0x2000u;
            v52 = v35;
          }
          else if ( (v40 & 4) != 0 )
          {
            v35 |= 0x4000u;
            v52 = v35;
          }
        }
        else
        {
          *(_DWORD *)(v10 + 64) &= 0xFFFFFFF3;
          *((_DWORD *)v34 + 19) = 1;
        }
        if ( (*(_BYTE *)(v10 + 64) & 1) != 0 )
          *((_DWORD *)v34 + 16) |= 1u;
        if ( (*(_DWORD *)(v10 + 96) & 0x400000) != 0 )
        {
          v35 |= (unsigned int)&unk_800000;
          v52 = v35;
        }
        if ( D3DTextureCreation(v34, *(_DWORD *)(v10 + 128), v35) )
          return -1;
        v41 = *(_DWORD *)(v10 + 96);
        if ( ((unsigned int)&unk_800000 & v41) != 0
          && (v41 & 0x4000) != 0
          && LinkedListNodeAppenderWithLazyAllocation(2, this) )
        {
          return -1;
        }
        if ( *(int *)(*(_DWORD *)(v10 + 140) + 80) > 1 )
        {
          v42 = *(_DWORD *)(v10 + 64);
          if ( (v42 & 0xC) == 0 )
            *(_DWORD *)(v10 + 64) = v42 | 8;
        }
        if ( (*(_DWORD *)(v10 + 64) & 0x100) != 0 )
        {
          v43 = strlen(v34);
          if ( v43 > 0 )
          {
            while ( v34[v43] != 46 )
            {
              if ( --v43 <= 0 )
                goto LABEL_89;
            }
            v54[v43 + 4] = 0;
            v44 = v34;
            do
            {
              v45 = *v44;
              v44[(_DWORD)v55] = *v44;
              ++v44;
            }
            while ( v45 );
            StringFormatWithBufferOverflowCheck(v34, "%s%4s%s%c", v61, (const char *)(this + 64), v59, 0);
          }
        }
LABEL_89:
        v34 += 96;
        v32 = *(_DWORD *)(v10 + 72);
        v46 = v57 + 1 < v32;
        v54 += 96;
        v55 -= 96;
        ++v57;
        if ( !v46 )
          goto LABEL_90;
      }
    }
    v11 = OperatorNewNhMallocWrapper(20);
    v12 = v11 ? StructInitWithDefaultScale(v11) : 0;
    *(_DWORD *)(v10 + 144) = v12;
    if ( sub_551A50(v10, 1, 0) )
      break;
    v13 = (_DWORD *)StringSearchInLinkedList(v10);
    if ( v13 )
    {
      *(_DWORD *)(v10 + 140) = v13;
      ++*v13;
    }
    else
    {
      v14 = *(_DWORD *)(v10 + 72);
      v15 = (_DWORD *)OperatorNewNhMallocWrapper(96 * v14 + 4);
      if ( v15 )
      {
        v16 = v15 + 1;
        *v15 = v14;
        v56 = v15 + 1;
        if ( v14 - 1 >= 0 )
        {
          do
          {
            StructInitWithZeroFill(v16);
            v16 += 24;
            --v14;
          }
          while ( v14 );
          v16 = v56;
        }
        v17 = v16;
      }
      else
      {
        v17 = 0;
      }
      v50 = *(_DWORD *)(v10 + 72);
      *(_DWORD *)(v10 + 140) = v17;
      StructFieldSetterAt0x4c(v50);
      if ( sub_54FEC0(v10, *(_DWORD *)(*(_DWORD *)(v10 + 144) + 8), *(_DWORD *)(*(_DWORD *)(v10 + 144) + 12), 0, 4) )
        return -1;
      sub_547860(v17);
      ++**(_DWORD **)(v10 + 140);
    }
LABEL_95:
    v6 = v58 + 1;
    v46 = v58 + 1 < v62;
    *(_DWORD *)(v2 + 156) &= ~2u;
    v58 = v6;
    if ( !v46 )
      return 0;
  }
  v49 = *(void **)(v10 + 144);
  if ( v49 )
  {
    EmptyStub_7470(v49);
    FreeWrapper_7bcf(v49);
  }
  return -1;
}

