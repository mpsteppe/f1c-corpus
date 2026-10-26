int __thiscall sub_6C5921(int this, int a2)
{
  unsigned int v3; // ecx
  bool v4; // cc
  void *v5; // edi
  unsigned int v7; // [esp+8h] [ebp-4h]

  v3 = *(_DWORD *)(this + 276);
  v7 = v3;
  if ( !v3 )
    v7 = 1024;
  if ( a2 + *(_DWORD *)(this + 272) > v7 )
  {
    do
    {
      v4 = *(_DWORD *)(this + 272) + a2 <= 2 * v7;
      v7 *= 2;
    }
    while ( !v4 );
  }
  if ( v7 != v3 )
  {
    v5 = operator new(4 * v7);
    if ( !v5 )
      return -2147024882;
    qmemcpy(v5, *(const void **)(this + 268), 4 * *(_DWORD *)(this + 272));
    j__free(*(void **)(this + 268));
    *(_DWORD *)(this + 268) = v5;
    *(_DWORD *)(this + 276) = v7;
  }
  return 0;
}
