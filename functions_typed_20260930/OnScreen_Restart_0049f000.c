int __thiscall sub_49F000(int this)
{
  int result; // eax
  _DWORD *v3; // esi
  int v4; // edi

  if ( (unsigned __int8)StringSplitLoop(2, aDDevF119992002_16, 2635) )
    DebugLogWrite(&dword_8AD25C, aEnteredOnscree_2);
  ShortComputation_bdf0(&dword_7CD204);
  FunctionCallWrapper_f150(0);
  *(_DWORD *)(this + 4) = 1;
  *(_BYTE *)(this + 8) = 0;
  result = ShortComputation_bdf0(&dword_7CD204);
  v3 = &unk_8AD2A8;
  v4 = 25;
  do
  {
    if ( *v3 )
      result = VTableDispatchWithFieldClear();
    ++v3;
    --v4;
  }
  while ( v4 );
  return result;
}

