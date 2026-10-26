int __thiscall sub_4D7150(_DWORD *this, const char *a2)
{
  const char *v3; // ecx
  CHAR *v4; // eax
  int v5; // esi
  _DWORD *v6; // eax
  _DWORD *v7; // edx
  _DWORD *v8; // eax
  int v9; // ecx
  _DWORD *v10; // eax
  int v11; // edi
  _DWORD *v12; // eax
  _DWORD *v13; // ebx
  _DWORD *v14; // esi
  _DWORD *v15; // eax
  int v16; // ecx
  int v17; // esi
  int v18; // ebx
  int v19; // edi
  double *v20; // ecx
  int v21; // ecx
  int v23; // [esp+Ch] [ebp-378h]
  CHAR v24[28]; // [esp+10h] [ebp-374h] BYREF
  CHAR SrcStr[64]; // [esp+2Ch] [ebp-358h] BYREF
  _BYTE v26[384]; // [esp+6Ch] [ebp-318h] BYREF
  int v27; // [esp+1ECh] [ebp-198h]
  char v28; // [esp+1F0h] [ebp-194h]
  int v29; // [esp+1F8h] [ebp-18Ch]
  int v30; // [esp+1FCh] [ebp-188h]
  int v31; // [esp+200h] [ebp-184h]
  _BYTE v32[384]; // [esp+204h] [ebp-180h] BYREF

  ArrayBlockCleanup(this);
  StringCopyWithBufferRealloc(a2);
  UtilityFunction_8a60(91, this + 8);
  v3 = &a2[strlen(a2)];
  if ( v3 > a2 )
  {
    while ( *v3 != 92 )
    {
      if ( --v3 <= a2 )
        goto LABEL_6;
    }
    ++v3;
  }
LABEL_6:
  sub_587DD0(SrcStr, v3, 63);
  SrcStr[63] = 0;
  v4 = &SrcStr[strlen(SrcStr)];
  if ( v4 > SrcStr )
  {
    while ( *v4 != 46 )
    {
      if ( --v4 <= SrcStr )
        goto LABEL_11;
    }
    *v4 = 0;
  }
LABEL_11:
  sub_589901(SrcStr);
  StringCopyWithBufferRealloc(SrcStr);
  ZeroInitSmallStruct(v24);
  if ( (unsigned __int8)AudioStreamOpen(a2, 1) )
  {
    memset(v32, 0, sizeof(v32));
    v27 = 0;
    v31 = 0;
    v29 = 0;
    v30 = 0;
    v28 = 1;
    while ( ConditionalDispatchBasedOnFlag(v32, 384) )
    {
      sub_5651B0(v26);
      if ( sub_587C20(v32, aSlipcurve) )
      {
        ++this[2];
      }
      else if ( sub_587C20(v32, aCompound) )
      {
        ++this[4];
      }
    }
    v5 = this[2];
    v6 = (_DWORD *)OperatorNewNhMallocWrapper(24 * v5 + 4);
    if ( v6 )
    {
      v7 = v6 + 1;
      *v6 = v5;
      v8 = v6 + 1;
      if ( v5 - 1 >= 0 )
      {
        v9 = v5;
        do
        {
          *v8 = 0;
          v8[1] = -1;
          v8[5] = 0;
          v8 += 6;
          --v9;
        }
        while ( v9 );
      }
      v10 = v7;
    }
    else
    {
      v10 = 0;
    }
    v11 = this[4];
    this[3] = v10;
    v12 = (_DWORD *)OperatorNewNhMallocWrapper(680 * v11 + 4);
    if ( v12 )
    {
      v13 = v12 + 1;
      *v12 = v11;
      v14 = v12 + 1;
      if ( v11 - 1 >= 0 )
      {
        do
        {
          *v14 = 0;
          v14[1] = -1;
          PhysicsStateStructureInitializer(v14 + 6);
          PhysicsStateStructureInitializer(v14 + 88);
          v14 += 170;
          --v11;
        }
        while ( v11 );
      }
      v15 = v13;
    }
    else
    {
      v15 = 0;
    }
    v16 = this[4];
    v17 = 0;
    this[5] = v15;
    if ( (!v16 || !v15) && (unsigned __int8)StringSplitLoop(1, aDDevF119992002_4, 893) )
      DebugLogWrite(&dword_8AD25C, aNoCompoundsFou);
    ConditionalAllocInitDispatch(v24);
    v18 = 0;
    v23 = 0;
    if ( ConditionalDispatchBasedOnFlag(v32, 384) )
    {
      v19 = 0;
      do
      {
        sub_5651B0(v26);
        if ( sub_587C20(v32, aSlipcurve) )
        {
          if ( v18 >= this[2] )
          {
            if ( (unsigned __int8)StringSplitLoop(1, aDDevF119992002_4, 913) )
              DebugLogWrite(&dword_8AD25C, aBadSyntaxInFil);
            break;
          }
          v20 = (double *)(v19 + this[3]);
          ++v18;
          v19 += 24;
          TireSlipCurveBuilder(v20, (int)v24);
        }
        if ( sub_587C20(v32, aCompound) )
        {
          if ( v23 >= this[4] )
          {
            if ( (unsigned __int8)StringSplitLoop(1, aDDevF119992002_4, 928) )
              DebugLogWrite(&dword_8AD25C, aBadSyntaxInFil_0);
            break;
          }
          v21 = v17 + this[5];
          ++v23;
          v17 += 680;
          sub_4D6B00(v21, (int)v24);
        }
      }
      while ( ConditionalDispatchBasedOnFlag(v32, 384) );
    }
    if ( (v18 != this[2] || v23 != this[4]) && (unsigned __int8)StringSplitLoop(1, aDDevF119992002_4, 941) )
      DebugLogWrite(&dword_8AD25C, aBadSyntaxInFil_1);
    ConditionalFileHandleCloseWithFlagDispatch(v24);
  }
  else if ( (unsigned __int8)StringSplitLoop(1, aDDevF119992002_4, 870) )
  {
    DebugLogWrite(&dword_8AD25C, aCouldNotOpenS);
  }
  return SubCallWithConditionalFieldFree(v24);
}

