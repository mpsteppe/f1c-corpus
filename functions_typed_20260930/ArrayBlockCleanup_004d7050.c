int __thiscall sub_4D7050(_DWORD *this)
{
  int v2; // ecx
  int result; // eax
  int v4; // eax
  void *v5; // edi
  int v6; // edx
  int v7; // eax
  LPVOID *v8; // esi
  int v9; // ebx
  int v10; // ecx
  void *v11; // edx
  LPVOID *v12; // edi
  LPVOID *v13; // esi
  int v14; // ebx
  void *v15; // [esp+10h] [ebp-4h]

  StringCopyWithBufferRealloc(byte_5EA438);
  v2 = this[3];
  result = 0;
  this[2] = 0;
  if ( v2 )
  {
    v4 = *(_DWORD *)(v2 - 4);
    v5 = (void *)(v2 - 4);
    v6 = 3 * v4;
    v7 = v4 - 1;
    v8 = (LPVOID *)(v2 + 8 * v6);
    if ( v7 >= 0 )
    {
      v9 = v7 + 1;
      do
      {
        v8 -= 6;
        StructEntryCleanup(v8);
        if ( *v8 )
          FreeWrapper_7bcf(*v8);
        --v9;
      }
      while ( v9 );
    }
    FreeWrapper_7bcf(v5);
    result = 0;
    this[3] = 0;
  }
  v10 = this[5];
  this[4] = 0;
  if ( v10 )
  {
    v11 = (void *)(v10 - 4);
    v12 = (LPVOID *)(v10 + 680 * *(_DWORD *)(v10 - 4));
    v15 = (void *)(v10 - 4);
    if ( *(_DWORD *)(v10 - 4) - 1 >= 0 )
    {
      v13 = v12 + 166;
      v14 = *(_DWORD *)(v10 - 4);
      do
      {
        v13 -= 170;
        v12 -= 170;
        ShortComputation_4370(v13 + 2);
        ShortComputation_4370(v13);
        ShortComputation_4370(v13 - 2);
        ShortComputation_4370(v13 - 80);
        ShortComputation_4370(v13 - 82);
        ShortComputation_4370(v13 - 84);
        ShortComputation_4370(v12);
        --v14;
      }
      while ( v14 );
      v11 = v15;
    }
    FreeWrapper_7bcf(v11);
    result = 0;
    this[5] = 0;
  }
  this[8] = -1;
  return result;
}

