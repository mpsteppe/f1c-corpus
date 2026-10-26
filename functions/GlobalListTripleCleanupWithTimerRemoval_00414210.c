int GlobalListTripleCleanupWithTimerRemoval()
{
  int result; // eax
  int i; // esi
  LPVOID **v2; // edi
  bool v3; // zf
  LPVOID *v4; // ebp
  int v5; // esi
  LPVOID **v6; // edi
  LPVOID *v7; // ebp
  int v8; // ebp
  _DWORD *v9; // edi
  LPVOID *v10; // esi

  result = DrawableResourceCleanup(&dword_5EA5E8);
  for ( i = dword_5EA608; i; result = FreeWrapper_7bcf(v2) )
  {
    v2 = (LPVOID **)i;
    v3 = *(_BYTE *)(i + 8) == 0;
    i = *(_DWORD *)(i + 4);
    if ( !v3 )
    {
      v4 = *v2;
      if ( *v2 )
      {
        MultiPointerFree(*v2);
        FreeWrapper_7bcf(v4);
      }
    }
  }
  v5 = dword_5EA5F8;
  dword_5EA608 = 0;
  dword_5EA60C = 0;
  dword_5EA610 = 0;
  for ( dword_5EA614 = 0; v5; result = FreeWrapper_7bcf(v6) )
  {
    v6 = (LPVOID **)v5;
    v3 = *(_BYTE *)(v5 + 8) == 0;
    v5 = *(_DWORD *)(v5 + 4);
    if ( !v3 )
    {
      v7 = *v6;
      if ( *v6 )
      {
        MultiFieldPointerFree(*v6);
        FreeWrapper_7bcf(v7);
      }
    }
  }
  v8 = dword_5EA5E8;
  dword_5EA5F8 = 0;
  dword_5EA5FC = 0;
  dword_5EA600 = 0;
  for ( dword_5EA604 = 0; v8; result = FreeWrapper_7bcf(v9) )
  {
    v9 = (_DWORD *)v8;
    v3 = *(_BYTE *)(v8 + 8) == 0;
    v8 = *(_DWORD *)(v8 + 4);
    if ( !v3 )
    {
      v10 = (LPVOID *)*v9;
      if ( *v9 )
      {
        TextFormatStructInitializer(*v9);
        ArrayDestructorIterator((int)(v10 + 34), 20, 2, (int (__thiscall *)(int))ShortComputation_4370);
        ArrayDestructorIterator((int)(v10 + 24), 20, 2, (int (__thiscall *)(int))ShortComputation_4370);
        ArrayDestructorIterator((int)(v10 + 14), 20, 2, (int (__thiscall *)(int))ShortComputation_4370);
        ArrayDestructorIterator((int)(v10 + 4), 20, 2, (int (__thiscall *)(int))ShortComputation_4370);
        ShortComputation_4370(v10);
        FreeWrapper_7bcf(v10);
      }
    }
  }
  dword_5EA5E8 = 0;
  dword_5EA5EC = 0;
  dword_5EA5F0 = 0;
  dword_5EA5F4 = 0;
  return result;
}
