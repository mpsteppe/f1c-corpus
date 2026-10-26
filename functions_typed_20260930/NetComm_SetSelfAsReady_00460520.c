int __thiscall sub_460520(_DWORD *this, int a2)
{
  int v3; // eax
  int v4; // eax
  int v5; // ecx
  int v6; // ebx
  int v7; // eax
  _BYTE v9[124]; // [esp+Ch] [ebp-8Ch] BYREF
  char v10; // [esp+88h] [ebp-10h]
  char v11; // [esp+89h] [ebp-Fh]

  ThunkToFUN00461480(v9);
  FunctionCallWrapper_23e0(v9);
  if ( this[4081] != 1 )
    BitfieldSetClearAt0x88(2, 1);
  BitfieldSetClearAt0x88(4, 0);
  if ( dword_7C569C != 5 && (unsigned __int8)StringSplitLoop(1, aDDevF119992002_1, 4394) )
    DebugLogWrite(&dword_8AD25C, aNetcommSetself);
  v3 = this[4081];
  v11 = dword_7D0E50;
  if ( v3 == 2 || v3 == 1 )
  {
    if ( v10 == -1 )
    {
      v4 = ArraySearchFor1Sentinel(this);
      v5 = this[4078];
      v6 = v4;
      v10 = v4;
      v7 = SingleFunctionCallWrapper_a810(v5);
      ShortComputation_e5d0(this, v6, v7);
      if ( dword_7C569C != 5 )
      {
        if ( (unsigned __int8)StringSplitLoop(1, aDDevF119992002_1, 4408) )
          DebugLogWrite(&dword_8AD25C, aNetcommSetself_0);
      }
    }
    BitfieldSetClearAt0x88(1, 1);
    if ( dword_7C569C != 5 && (unsigned __int8)StringSplitLoop(1, aDDevF119992002_1, 4412) )
      DebugLogWrite(&dword_8AD25C, aNetcommSetself_2);
  }
  else if ( a2 == -1 )
  {
    if ( dword_7C569C != 5 && (unsigned __int8)StringSplitLoop(1, aDDevF119992002_1, 4430) )
      DebugLogWrite(&dword_8AD25C, aNetcommSetself_1);
  }
  else
  {
    v10 = a2;
    if ( dword_7C569C != 5 && (unsigned __int8)StringSplitLoop(1, aDDevF119992002_1, 4423) )
      DebugLogWrite(&dword_8AD25C, aNetcommSetself_0);
  }
  ShortComputation_23b0(v9);
  return EmptyStub_0170(v9);
}

