int __thiscall sub_65F877(int this, int a2)
{
  int v3; // eax
  unsigned int v5; // edx
  unsigned int v6; // eax
  bool v7; // cc
  void *v8; // edi
  unsigned int v10; // [esp+14h] [ebp+8h]

  v3 = *(_DWORD *)(this + 92);
  v5 = a2 + v3;
  v6 = *(_DWORD *)(this + 96);
  if ( v5 > v6 )
  {
    v10 = *(_DWORD *)(this + 96);
    if ( !v6 )
      v10 = 256;
    if ( v5 > v10 )
    {
      do
      {
        v7 = a2 + *(_DWORD *)(this + 92) <= 2 * v10;
        v10 *= 2;
      }
      while ( !v7 );
    }
    v8 = operator new(4 * v10);
    if ( !v8 )
      return -2147024882;
    qmemcpy(v8, *(const void **)(this + 88), 4 * *(_DWORD *)(this + 92));
    j__free(*(void **)(this + 88));
    *(_DWORD *)(this + 88) = v8;
    *(_DWORD *)(this + 96) = v10;
  }
  return 0;
}
