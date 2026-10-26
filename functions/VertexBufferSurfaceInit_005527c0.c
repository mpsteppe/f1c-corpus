int __thiscall sub_5527C0(int this)
{
  _DWORD *v2; // eax
  int v4; // eax
  int v5; // ecx
  int v6; // eax
  int v7; // edx

  if ( (*(_DWORD *)(this + 36) & 0x20000) != 0 )
  {
    if ( !*(_DWORD *)(this + 12) )
    {
      v2 = (_DWORD *)OperatorNewNhMallocWrapper(36);
      if ( v2 )
      {
        v2[5] = 0;
        v2[4] = 0;
        v2[3] = 0;
        v2[2] = 0;
        v2[1] = 0;
        *v2 = 0;
        v2[7] = 0;
        v2[6] = 0;
        v2[8] = 0;
      }
      else
      {
        v2 = 0;
      }
      *(_DWORD *)(this + 12) = v2;
    }
    **(_DWORD **)(this + 12) = 34;
    *(_DWORD *)(*(_DWORD *)(this + 12) + 12) = 768;
    *(_DWORD *)(*(_DWORD *)(this + 12) + 8) = 28;
    *(_DWORD *)(*(_DWORD *)(this + 12) + 4) = dword_8CEF78;
    if ( sub_540DF0(dword_8B78A0, *(int **)(this + 12)) )
      return -1;
    v4 = BufferLockAllocate(dword_8B78A0, *(_DWORD **)(this + 12), 96, 0, 0);
    v5 = *(_DWORD *)(this + 12);
    *(_DWORD *)(this + 16) = v4;
    v6 = 0;
    if ( *(int *)(v5 + 12) > 0 )
    {
      do
      {
        *(_DWORD *)(*(_DWORD *)(this + 16) + 8) = 0;
        *(_DWORD *)(*(_DWORD *)(this + 16) + 12) = 1065353216;
        v7 = *(_DWORD *)(this + 12);
        *(_DWORD *)(this + 16) += 28;
        ++v6;
      }
      while ( v6 < *(_DWORD *)(v7 + 12) );
    }
    ArithmeticComparison_0f90(dword_8B78A0, *(_DWORD *)(this + 12));
  }
  return 0;
}
