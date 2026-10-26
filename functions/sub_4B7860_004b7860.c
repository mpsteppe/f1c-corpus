char __thiscall sub_4B7860(int *this, char a2)
{
  int v3; // eax
  int *v4; // ebp
  int v5; // eax
  _DWORD *v6; // edi
  bool v7; // zf
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // ecx
  int v12; // eax
  int v13; // eax
  int v14; // ecx
  _DWORD *v16; // [esp-10h] [ebp-18h]
  _DWORD *v17; // [esp-10h] [ebp-18h]

  v3 = CircularBufferCheck(this);
  if ( v3 != this[621] && !a2 || v3 <= 0 )
    return 0;
  v4 = this + 12;
  while ( 1 )
  {
    v5 = *v4;
    v6 = 0;
    v7 = *v4 == 0;
    this[14] = this[12];
    if ( !v7 )
    {
      v6 = *(_DWORD **)v5;
      v16 = *(_DWORD **)v5;
      *(_BYTE *)(v5 + 8) = 0;
      if ( !(unsigned __int8)sub_4BB6B0(v16, 1) )
        v6 = 0;
    }
    if ( !v6 )
    {
      v8 = OperatorNewNhMallocWrapper(4) ? ConditionalArrayAlloc(0) : 0;
      ListAppendWithSubListGeneration(v8, 0);
      v6 = 0;
      ShortComputation_a780(this + 12);
      v9 = this[14];
      if ( v9 )
      {
        v6 = *(_DWORD **)v9;
        v17 = *(_DWORD **)v9;
        *(_BYTE *)(v9 + 8) = 0;
        if ( !(unsigned __int8)sub_4BB6B0(v17, 1) )
          v6 = 0;
      }
    }
    v10 = CollisionObjectListManagement((_BYTE *)(this[620] + 176 * this[623]), (int)(this + 441), (int)v6);
    if ( v10 <= 0 )
      break;
    v11 = v10 + this[970];
    ++this[969];
    this[970] = v11;
    if ( v6 )
    {
      v12 = OperatorNewNhMallocWrapper(16);
      if ( v12 )
      {
        *(_DWORD *)v12 = v6;
        *(_DWORD *)(v12 + 4) = 0;
        *(_DWORD *)(v12 + 8) = 0;
        *(_BYTE *)(v12 + 12) = 0;
      }
      else
      {
        v12 = 0;
      }
      if ( this[453] )
      {
        *(_DWORD *)(this[454] + 4) = v12;
        *(_DWORD *)(v12 + 8) = this[454];
      }
      else
      {
        this[453] = v12;
        this[455] = v12;
      }
      this[454] = v12;
      ++this[456];
    }
  }
  SmallStructZeroInit(v6);
  if ( v6 )
  {
    v13 = OperatorNewNhMallocWrapper(12);
    if ( v13 )
    {
      *(_DWORD *)v13 = v6;
      *(_DWORD *)(v13 + 4) = 0;
      *(_BYTE *)(v13 + 8) = 0;
    }
    else
    {
      v13 = 0;
    }
    v14 = this[12];
    if ( v14 )
    {
      *(_DWORD *)(v13 + 4) = v14;
    }
    else
    {
      this[13] = v13;
      this[14] = v13;
    }
    this[12] = v13;
    ++this[15];
  }
  RingBufferCounterWithWrap(this);
  return 1;
}
