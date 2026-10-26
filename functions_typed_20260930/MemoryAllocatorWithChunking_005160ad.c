int __cdecl sub_5160AD(_DWORD *a1, unsigned int a2, unsigned int a3, unsigned int a4)
{
  int v4; // edi
  unsigned int v5; // esi
  unsigned int v7; // edi
  _DWORD *v8; // eax
  unsigned int v9; // ecx
  int v11; // [esp+20h] [ebp+14h]

  v4 = a1[1];
  v5 = 0x3B9AC9F0 / a3;
  if ( (int)(0x3B9AC9F0 / a3) <= 0 )
  {
    *(_DWORD *)(*a1 + 20) = 69;
    (*(void (__cdecl **)(_DWORD *))*a1)(a1);
  }
  if ( (int)v5 >= (int)a4 )
    v5 = a4;
  *(_DWORD *)(v4 + 76) = v5;
  v7 = 0;
  v11 = MemoryAllocator(a1, a2, 4 * a4);
  while ( v7 < a4 )
  {
    if ( v5 >= a4 - v7 )
      v5 = a4 - v7;
    v8 = MemoryAllocatorWithAlignment(a1, a2, a3 * v5);
    if ( v5 )
    {
      v9 = v5;
      do
      {
        *(_DWORD *)(v11 + 4 * v7) = v8;
        v8 = (_DWORD *)((char *)v8 + a3);
        ++v7;
        --v9;
      }
      while ( v9 );
    }
  }
  return v11;
}

