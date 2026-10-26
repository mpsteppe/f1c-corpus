int __thiscall sub_6BCA61(_DWORD *this)
{
  _DWORD *v2; // eax
  unsigned int v3; // esi
  unsigned int v4; // ebx
  _DWORD *v5; // eax
  unsigned int i; // [esp+Ch] [ebp-4h]

  v2 = (_DWORD *)this[64];
  v3 = *v2 & 0xFFFFF;
  if ( v3 != v2[3]
    || sub_680D7E((_DWORD *)this[64])
    || sub_680F76((_DWORD *)this[64]) && !sub_680E0C((_DWORD *)this[64])
    || v3 > 4
    || !v3 )
  {
    return 1;
  }
  for ( i = 0; i < v3; ++i )
  {
    v4 = 0;
    if ( v3 - i != 1 )
    {
      do
      {
        v5 = (_DWORD *)(*(_DWORD *)(this[64] + 16) + 4 * v4);
        if ( *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *v5) + 16) > *(_DWORD *)(*(_DWORD *)(this[5] + 4 * v5[1]) + 16) )
          sub_6BC9F6((_DWORD *)this[64], v4);
        ++v4;
      }
      while ( v4 < v3 - i - 1 );
    }
  }
  return 0;
}
