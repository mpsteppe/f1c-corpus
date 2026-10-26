int __thiscall sub_664155(int this, unsigned int a2, unsigned int a3, const void *a4)
{
  int v5; // eax
  unsigned int i; // esi
  void *v7; // ecx
  int v8; // eax
  unsigned int j; // esi
  void *v10; // ecx

  v5 = *(_DWORD *)(this + 8);
  for ( i = a2; i < *(_DWORD *)(v5 + 8); ++i )
  {
    v7 = *(void **)(*(_DWORD *)(v5 + 20) + 4 * i);
    if ( v7 )
      sub_663A9B(v7, 1);
    *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 8) + 20) + 4 * i) = 0;
    v5 = *(_DWORD *)(this + 8);
  }
  *(_DWORD *)(*(_DWORD *)(this + 8) + 8) = a2;
  v8 = *(_DWORD *)(this + 8);
  for ( j = a3; j < *(_DWORD *)(v8 + 12); ++j )
  {
    v10 = *(void **)(*(_DWORD *)(v8 + 24) + 4 * j);
    if ( v10 )
      sub_66238F(v10, 1);
    *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 8) + 24) + 4 * j) = 0;
    v8 = *(_DWORD *)(this + 8);
  }
  *(_DWORD *)(*(_DWORD *)(this + 8) + 12) = a3;
  qmemcpy(*(void **)(this + 24), a4, 4 * *(_DWORD *)(*(_DWORD *)(this + 4) + 24));
  return 0;
}
