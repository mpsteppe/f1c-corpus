int __thiscall sub_4A22D0(_DWORD *this, int a2, int a3, const CHAR *a4, int a5)
{
  int v6; // esi
  int *v7; // eax
  _DWORD *v8; // ebp
  _DWORD *v9; // edx
  int v10; // edx
  int v11; // edx
  int v12; // eax
  int v13; // eax
  void *v14; // edx
  int v15; // esi
  int v16; // ecx
  int v17; // edi
  int v18; // edi
  int v19; // edx
  int v20; // esi
  int v21; // eax
  int v22; // esi
  int v24; // [esp-10h] [ebp-120h]
  int v25; // [esp+4h] [ebp-10Ch] BYREF
  void *v26; // [esp+8h] [ebp-108h]
  int v27; // [esp+Ch] [ebp-104h]
  _BYTE v28[256]; // [esp+10h] [ebp-100h] BYREF

  v27 = dword_8AFE88;
  if ( this[25] )
  {
    v6 = this[28] + 1;
    v7 = (int *)OperatorNewNhMallocWrapper(28 * v6 + 4);
    if ( v7 )
    {
      v8 = v7 + 1;
      *v7 = v6;
      v9 = v7 + 1;
      if ( v6 - 1 >= 0 )
      {
        do
        {
          FunctionCallWrapper_1fb0(v9);
          v9 = (_DWORD *)(v10 + 28);
          --v6;
        }
        while ( v6 );
      }
    }
    else
    {
      v8 = 0;
    }
    v11 = 0;
    if ( (int)this[28] > 0 )
    {
      v12 = 0;
      do
      {
        qmemcpy(&v8[v12], (const void *)(v12 * 4 + this[29]), 0x1Cu);
        *(_DWORD *)(v12 * 4 + this[29] + 20) = 0;
        ++v11;
        v12 += 7;
      }
      while ( v11 < this[28] );
    }
    v13 = this[29];
    if ( v13 )
    {
      v14 = (void *)(v13 - 4);
      v15 = v13 + 28 * *(_DWORD *)(v13 - 4);
      v16 = *(_DWORD *)(v13 - 4) - 1;
      v26 = (void *)(v13 - 4);
      if ( v16 >= 0 )
      {
        v17 = v16 + 1;
        do
        {
          v15 -= 28;
          ShortComputation_d4d0(v15);
          --v17;
        }
        while ( v17 );
        v14 = v26;
      }
      FreeWrapper_7bcf(v14);
    }
    v24 = 4 * this[26];
    this[29] = v8;
    *(_DWORD *)(28 * this[28] + this[29] + 20) = OperatorNewNhMallocWrapper(v24);
    v18 = 0;
    if ( (int)this[26] > 0 )
    {
      while ( 1 )
      {
        v19 = this[29];
        v20 = 28 * this[28];
        v21 = *(_DWORD *)(v20 + v19 + 20);
        v22 = v19 + v20;
        *(_DWORD *)(v21 + 4 * v18) = 0;
        if ( sub_5518A0(&v25, a3, 0) == -1 || sub_551560(v25) )
          break;
        *(_DWORD *)(*(_DWORD *)(v22 + 20) + 4 * v18) = WideStringComparisonWalkingLinkedList(a2);
        if ( !v18 )
        {
          *(_DWORD *)(v22 + 12) = a5;
          *(float *)(v22 + 16) = *(float *)(v25 + 8);
          if ( a4 )
            *(_DWORD *)(v22 + 24) = PitCrewAnimationStringMapper(a4);
          else
            *(_DWORD *)(v22 + 24) = 24;
        }
        if ( ++v18 >= this[26] )
          goto LABEL_27;
      }
      StringRelocationCopy(0, v28);
      if ( (unsigned __int8)StringSplitLoop(1, aDDevF119992002_2, 327) )
        DebugLogWrite(&dword_8AD25C, aCubeErrorLoadi_0);
    }
LABEL_27:
    if ( v18 == this[26] )
      ++this[28];
  }
  return 0;
}
