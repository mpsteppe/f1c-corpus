char __thiscall sub_407520(_DWORD *this, int *a2, int a3)
{
  char result; // al
  int v6; // eax
  bool v7; // zf
  int v8; // esi
  _DWORD **v9; // eax
  _DWORD *v10; // eax
  int v11; // eax
  _DWORD **v12; // eax
  _DWORD *v13; // eax
  _DWORD *v14; // esi
  int v15; // eax
  int v16; // eax
  char v17; // [esp+Fh] [ebp-9h]
  char v18; // [esp+1Ch] [ebp+4h]

  result = 0;
  v17 = 0;
  if ( a2 )
  {
    v6 = *a2;
    v7 = *a2 == 0;
    v18 = 0;
    if ( !v7 )
      StringCopyWithBufferRealloc(v6);
    v8 = a2[1];
    if ( v8 )
      sub_5665B0(v8);
    v9 = (_DWORD **)this[14];
    this[16] = v9;
    if ( v9 )
    {
      v10 = *v9;
      if ( v10 )
      {
        while ( *v10 != a3 )
        {
          v11 = this[16];
          if ( v11 )
            this[16] = *(_DWORD *)(v11 + 4);
          v12 = (_DWORD **)this[16];
          if ( v12 )
          {
            v10 = *v12;
            if ( v10 )
              continue;
          }
          goto LABEL_15;
        }
        v18 = 1;
      }
    }
LABEL_15:
    if ( !sub_588410(&byte_5EA438, &byte_5EA438) )
      return v17;
    if ( v18 )
      return v17;
    v13 = (_DWORD *)OperatorNewNhMallocWrapper(116);
    if ( !v13 )
      return v17;
    v14 = ShortComputation_53e0(v13);
    if ( !v14 )
      return v17;
    v15 = sub_587DB0(&byte_5EA438, aRb);
    v14[3] = v15;
    if ( v15 )
    {
      if ( !MemoryAllocationWithBufferRead(v14) )
      {
        v14[4] = StructFieldGetterAt0x10(v14[3]);
        *v14 = a3;
        StringCopyWithBufferRealloc(&byte_5EA438);
        v16 = OperatorNewNhMallocWrapper(12);
        if ( v16 )
        {
          *(_DWORD *)v16 = v14;
          *(_DWORD *)(v16 + 4) = 0;
          *(_BYTE *)(v16 + 8) = 1;
        }
        else
        {
          v16 = 0;
        }
        if ( this[14] )
        {
          *(_DWORD *)(this[15] + 4) = v16;
        }
        else
        {
          this[14] = v16;
          this[16] = v16;
        }
        this[15] = v16;
        ++this[17];
        return 1;
      }
      FileCloseWithLock(v14[3]);
      v14[3] = 0;
    }
    MultiStageCleanupWithFree(v14);
    FreeWrapper_7bcf(v14);
    return v17;
  }
  return result;
}
