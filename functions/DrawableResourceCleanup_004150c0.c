int __thiscall sub_4150C0(int *this)
{
  int v2; // edi
  int result; // eax
  int *v4; // ebp
  char v5; // cl
  LPVOID *v6; // esi
  int i; // esi
  LPVOID **v8; // edi
  char v9; // cl
  LPVOID *v10; // ebp
  int j; // edi
  int *v12; // ebp
  char v13; // cl
  LPVOID *v14; // esi

  v2 = *this;
  for ( result = 0; v2; result = 0 )
  {
    v4 = (int *)v2;
    v5 = *(_BYTE *)(v2 + 8);
    v2 = *(_DWORD *)(v2 + 4);
    if ( v5 )
    {
      v6 = (LPVOID *)*v4;
      if ( *v4 )
      {
        TextFormatStructInitializer(*v4);
        ArrayDestructorIterator((int)(v6 + 34), 20, 2, (int (__thiscall *)(int))ShortComputation_4370);
        ArrayDestructorIterator((int)(v6 + 24), 20, 2, (int (__thiscall *)(int))ShortComputation_4370);
        ArrayDestructorIterator((int)(v6 + 14), 20, 2, (int (__thiscall *)(int))ShortComputation_4370);
        ArrayDestructorIterator((int)(v6 + 4), 20, 2, (int (__thiscall *)(int))ShortComputation_4370);
        ShortComputation_4370(v6);
        FreeWrapper_7bcf(v6);
      }
    }
    FreeWrapper_7bcf(v4);
  }
  *this = 0;
  this[1] = 0;
  this[2] = 0;
  this[3] = 0;
  for ( i = this[4]; i; result = 0 )
  {
    v8 = (LPVOID **)i;
    v9 = *(_BYTE *)(i + 8);
    i = *(_DWORD *)(i + 4);
    if ( v9 )
    {
      v10 = *v8;
      if ( *v8 )
      {
        MultiFieldPointerFree(*v8);
        FreeWrapper_7bcf(v10);
      }
    }
    FreeWrapper_7bcf(v8);
  }
  this[4] = 0;
  this[5] = 0;
  this[6] = 0;
  this[7] = 0;
  for ( j = this[8]; j; result = 0 )
  {
    v12 = (int *)j;
    v13 = *(_BYTE *)(j + 8);
    j = *(_DWORD *)(j + 4);
    if ( v13 )
    {
      v14 = (LPVOID *)*v12;
      if ( *v12 )
      {
        TextFormatStructInitializer_4fe0(*v12);
        ArrayDestructorIterator((int)(v14 + 13), 20, 2, (int (__thiscall *)(int))ShortComputation_4370);
        ArrayDestructorIterator((int)(v14 + 3), 20, 2, (int (__thiscall *)(int))ShortComputation_4370);
        ShortComputation_4370(v14);
        FreeWrapper_7bcf(v14);
      }
    }
    FreeWrapper_7bcf(v12);
  }
  this[8] = 0;
  this[9] = 0;
  this[10] = 0;
  this[11] = 0;
  return result;
}
