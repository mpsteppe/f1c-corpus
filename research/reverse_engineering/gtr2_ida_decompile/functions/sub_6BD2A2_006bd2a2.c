int __thiscall sub_6BD2A2(_DWORD *this)
{
  int v1; // eax
  unsigned int v2; // esi
  int v4; // eax
  int v5; // edx
  int v6; // ebx
  int v7; // eax
  unsigned int i; // [esp+4h] [ebp-4h]

  v1 = this[64];
  v2 = *(_DWORD *)v1 & 0xFFFFF;
  if ( *(char *)(*(_DWORD *)(this[4]
                           + 4
                           * *(_DWORD *)(*(_DWORD *)(this[5]
                                                   + 4
                                                   * *(_DWORD *)(*(_DWORD *)(this[5] + 4 * **(_DWORD **)(v1 + 8)) + 48))
                                       + 4))
               + 4) >= 0 )
    return 1;
  for ( i = 0; i < v2; *(_DWORD *)(v7 + 48) = *(_DWORD *)(v6 + 48) )
  {
    v4 = this[64];
    v5 = this[5];
    v6 = *(_DWORD *)(v5 + 4 * *(_DWORD *)(4 * i + *(_DWORD *)(v4 + 8)));
    v7 = *(_DWORD *)(v5 + 4 * *(_DWORD *)(4 * i++ + *(_DWORD *)(v4 + 16)));
  }
  *(_DWORD *)this[64] = 0;
  return 0;
}
