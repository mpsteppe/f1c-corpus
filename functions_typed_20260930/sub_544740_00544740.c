int __thiscall sub_544740(_DWORD *this)
{
  int v2; // edi
  int v3; // ebx
  int v4; // ebp
  void *v5; // edi
  void *v6; // edi
  int *v7; // eax
  _DWORD *v8; // ebx
  _DWORD *v9; // edi
  _DWORD *v10; // eax
  int v11; // edi
  int v12; // ebx
  int v13; // ebx
  int v14; // edi
  int v15; // ecx
  int v16; // eax
  void *v17; // ebp
  int v18; // edi
  int v19; // eax
  int v20; // ebx
  int v21; // ebx
  int v22; // edi
  int v23; // edi
  int v24; // ebx
  int v25; // eax
  int v26; // ebx
  int v27; // edi
  int v28; // edi
  int i; // esi
  int v31; // [esp+10h] [ebp-24h]
  _BYTE v32[32]; // [esp+14h] [ebp-20h] BYREF

  if ( StructFieldGetter(dword_8B78A0) && (this[59] & 0x100000) != 0 )
  {
    if ( (int)this[88] > 0 )
    {
      v2 = 0;
      v3 = 0;
      do
      {
        DestructorWithConditionalFreeFlagClear(v3 + this[89]);
        ++v2;
        v3 += 96;
      }
      while ( v2 < this[88] );
      DoublyLinkedListNodeRemovalWithArrayCleanup(this[89]);
      this[88] = 0;
      this[89] = 0;
      SubBufferFree(dword_8B78A0);
    }
    this[59] &= ~0x100000u;
  }
  EmptyStub_c440(this);
  if ( (this[59] & 0x100000) == 0 )
  {
    if ( StructFieldGetter(dword_8B78A0) )
    {
      v4 = this[86];
      v31 = v4;
      if ( v4 <= 0 )
        goto LABEL_54;
    }
    else
    {
      if ( (int)this[86] <= 0 )
        goto LABEL_54;
      v31 = 1;
      v4 = 1;
    }
    if ( dword_8B8DBC )
    {
      sub_542E50((_DWORD *)dword_8B8DBC);
      v5 = (void *)dword_8B8DBC;
      if ( dword_8B8DBC )
      {
        EmptyStub_7470(dword_8B8DBC);
        FreeWrapper_7bcf(v5);
      }
      dword_8B8DBC = 0;
    }
    else if ( dword_8B8DC0 )
    {
      sub_542E50((_DWORD *)dword_8B8DC0);
      v6 = (void *)dword_8B8DC0;
      if ( dword_8B8DC0 )
      {
        EmptyStub_7470(dword_8B8DC0);
        FreeWrapper_7bcf(v6);
      }
      dword_8B8DC0 = 0;
    }
    v7 = (int *)OperatorNewNhMallocWrapper(96 * v4 + 4);
    if ( v7 )
    {
      v8 = v7 + 1;
      *v7 = v4;
      v9 = v7 + 1;
      if ( v4 - 1 >= 0 )
      {
        do
        {
          StructInitWithZeroFill(v9);
          v9 += 24;
          --v4;
        }
        while ( v4 );
        v4 = v31;
      }
      v10 = v8;
    }
    else
    {
      v10 = 0;
    }
    v11 = 0;
    this[89] = v10;
    v10[19] = v4;
    if ( v4 > 0 )
    {
      v12 = 0;
      while ( 1 )
      {
        StringFormatWithBufferOverflowCheck(v32, "SHADOWTEX%.3d", v11);
        if ( sub_54FE50(v32) )
          break;
        if ( UtilityFunction_2950(*(_DWORD **)(this[89] + v12 + 84), dword_8B8DF4, dword_8B8DF4, dword_8B8DF8, 262152) )
        {
          if ( v11 >= 0 )
          {
            v21 = 0;
            v22 = v11 + 1;
            do
            {
              DestructorWithConditionalFreeFlagClear(v21 + this[89]);
              v21 += 96;
              --v22;
            }
            while ( v22 );
          }
          DoublyLinkedListNodeRemovalWithArrayCleanup(this[89]);
          goto LABEL_45;
        }
        sub_5435C0(*(_DWORD **)(this[89] + v12 + 84), 16711935);
        ++v11;
        v12 += 96;
        if ( v11 >= v4 )
          goto LABEL_46;
      }
      if ( v11 >= 0 )
      {
        v13 = 0;
        v14 = v11 + 1;
        do
        {
          DestructorWithConditionalFreeFlagClear(v13 + this[89]);
          v13 += 96;
          --v14;
        }
        while ( v14 );
      }
      v15 = this[89];
      if ( v15 )
      {
        v16 = *(_DWORD *)(v15 - 4);
        v17 = (void *)(v15 - 4);
        v18 = v15 + 96 * v16;
        v19 = v16 - 1;
        if ( v19 >= 0 )
        {
          v20 = v19 + 1;
          do
          {
            v18 -= 96;
            EmptyStub_7470(v18);
            --v20;
          }
          while ( v20 );
        }
        FreeWrapper_7bcf(v17);
        v4 = v31;
      }
LABEL_45:
      this[89] = 0;
    }
LABEL_46:
    if ( this[89] )
    {
      sub_547860(this[89]);
      if ( TextureSurfaceAllocation((int)dword_8B78A0, 2048) )
      {
        if ( v4 > 0 )
        {
          v23 = 0;
          v24 = v4;
          do
          {
            DestructorWithConditionalFreeFlagClear(v23 + this[89]);
            v23 += 96;
            --v24;
          }
          while ( v24 );
        }
        DoublyLinkedListNodeRemovalWithArrayCleanup(this[89]);
        this[89] = 0;
      }
    }
    if ( this[89] )
    {
      v25 = this[59] | 0x100000;
      this[88] = v4;
      this[59] = v25;
    }
  }
LABEL_54:
  v26 = this[64];
  if ( v26 )
  {
    while ( 1 )
    {
      v27 = *(_DWORD *)(v26 + 236);
      if ( v27 )
        break;
LABEL_58:
      v26 = *(_DWORD *)(v26 + 260);
      if ( !v26 )
        goto LABEL_59;
    }
    while ( !PriorityQueueRecursiveProcess(v27, 0) )
    {
      v27 = *(_DWORD *)(v27 + 76);
      if ( !v27 )
        goto LABEL_58;
    }
    return -1;
  }
LABEL_59:
  v28 = this[66];
  if ( v28 )
  {
    while ( !PriorityQueueRecursiveProcess(v28, 0) )
    {
      v28 = *(_DWORD *)(v28 + 76);
      if ( !v28 )
        goto LABEL_62;
    }
    return -1;
  }
LABEL_62:
  for ( i = this[82]; i; i = *(_DWORD *)(i + 104) )
    FlagCheckWithConditionalPathDispatch(i);
  return 0;
}

