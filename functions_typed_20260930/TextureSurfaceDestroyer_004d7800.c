int __thiscall sub_4D7800(int *this)
{
  int result; // eax
  int v3; // esi
  int v4; // ebx
  int v5; // ecx
  int v6; // eax
  void *v7; // ebx
  int v8; // edx
  int v9; // eax
  int v10; // esi
  int v11; // ebp

  result = *this;
  v3 = 0;
  if ( *this > 0 )
  {
    v4 = 0;
    do
    {
      ArrayBlockCleanup((_DWORD *)(v4 + this[1]));
      result = *this;
      ++v3;
      v4 += 36;
    }
    while ( v3 < *this );
  }
  v5 = this[1];
  *this = 0;
  if ( v5 )
  {
    v6 = *(_DWORD *)(v5 - 4);
    v7 = (void *)(v5 - 4);
    v8 = 9 * v6;
    v9 = v6 - 1;
    v10 = v5 + 4 * v8;
    if ( v9 >= 0 )
    {
      v11 = v9 + 1;
      do
      {
        v10 -= 36;
        ArrayBlockCleanup((_DWORD *)v10);
        if ( *(_DWORD *)(v10 + 24) )
          FreeWrapper_7bcf(*(LPVOID *)(v10 + 24));
        if ( *(_DWORD *)v10 )
          FreeWrapper_7bcf(*(LPVOID *)v10);
        --v11;
      }
      while ( v11 );
    }
    result = FreeWrapper_7bcf(v7);
  }
  this[1] = 0;
  return result;
}

