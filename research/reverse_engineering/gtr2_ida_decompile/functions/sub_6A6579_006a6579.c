int __thiscall sub_6A6579(_DWORD *this)
{
  int v2; // esi
  int v3; // esi
  unsigned int j; // ecx
  int v5; // esi
  int v6; // edx
  unsigned int i; // [esp+4h] [ebp-4h]

  for ( i = 0; i < this[176]; ++i )
  {
    v2 = *(_DWORD *)(4 * i + this[173]);
    qmemcpy(*(void **)(*(_DWORD *)(this[6] + 4 * i) + 8), *(const void **)(v2 + 8), 4 * *(_DWORD *)(v2 + 4));
    v3 = *(_DWORD *)(4 * i + this[173]);
    qmemcpy(*(void **)(*(_DWORD *)(this[6] + 4 * i) + 16), *(const void **)(v3 + 16), 4 * *(_DWORD *)(v3 + 12));
  }
  for ( j = 0; j < this[175]; *(_DWORD *)(v5 + 56) = v6 )
  {
    v5 = *(_DWORD *)(this[5] + 4 * j);
    v6 = *(_DWORD *)(*(_DWORD *)(this[174] + 4 * j++) + 56);
  }
  return 0;
}
