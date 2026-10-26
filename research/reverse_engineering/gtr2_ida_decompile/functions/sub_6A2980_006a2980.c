int __thiscall sub_6A2980(_DWORD *this)
{
  int v1; // eax
  int v2; // edx
  int v3; // edi
  int v4; // edx
  unsigned int v5; // esi
  int v6; // eax
  unsigned int j; // edx
  int v8; // eax
  unsigned int v10; // [esp+0h] [ebp-14h]
  _DWORD *v11; // [esp+4h] [ebp-10h]
  int v12; // [esp+8h] [ebp-Ch]
  unsigned int i; // [esp+Ch] [ebp-8h]
  unsigned int v14; // [esp+10h] [ebp-4h]

  if ( (*(_DWORD *)this[64] & 0xFFF00000) == 0x10000000 && (unsigned __int16)this[50] < 0x104u )
  {
    v1 = this[64];
    v2 = this[5];
    v3 = *(_DWORD *)(v2 + 4 * **(_DWORD **)(v1 + 8));
    v4 = *(_DWORD *)(v2 + 4 * **(_DWORD **)(v1 + 16));
    v5 = *(_DWORD *)v1 & 0xFFFFF;
    v10 = v5;
    if ( !*(_DWORD *)(v3 + 60)
      && (*(_BYTE *)(v4 + 61) & 2) != 0
      && *(_BYTE *)(v3 + 108) == 3
      && *(_DWORD *)(v4 + 4) == this[34] )
    {
      for ( i = 0; i < v5; ++i )
      {
        v12 = 4 * i;
        v6 = *(_DWORD *)(this[5] + 4 * *(_DWORD *)(4 * i + *(_DWORD *)(this[64] + 8)));
        *(_BYTE *)(v6 + 61) |= 2u;
        for ( j = this[63]; j < this[3]; ++j )
        {
          v8 = *(_DWORD *)(this[6] + 4 * j);
          v14 = 0;
          if ( *(_DWORD *)(v8 + 4) )
          {
            do
            {
              v11 = (_DWORD *)(*(_DWORD *)(v8 + 8) + 4 * v14);
              if ( *v11 == *(_DWORD *)(v12 + *(_DWORD *)(this[64] + 16)) )
                *v11 = *(_DWORD *)(v12 + *(_DWORD *)(this[64] + 8));
              ++v14;
            }
            while ( v14 < *(_DWORD *)(v8 + 4) );
            v5 = v10;
          }
        }
      }
      *(_DWORD *)this[64] = 0;
    }
  }
  return 0;
}
