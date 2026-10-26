int __thiscall sub_684A43(_DWORD *this)
{
  int v1; // edx
  unsigned int v2; // esi
  unsigned int v3; // edx
  int result; // eax
  int v5; // esi
  unsigned int v6; // edi
  unsigned int v7; // ebx
  unsigned int v8; // [esp+Ch] [ebp-8h]
  int v9; // [esp+10h] [ebp-4h]

  v1 = this[27];
  v2 = 0;
  v9 = 0;
  if ( (v1 & 0x4000000) != 0 )
  {
    v3 = this[3];
    result = 0;
    if ( !v3 )
      return result;
    v5 = this[6];
    v9 = (*(_BYTE *)(*(_DWORD *)v5 + 44) & 1) == 0;
    v6 = 1;
    if ( v3 > 1 )
    {
      do
      {
        if ( (*(_BYTE *)(*(_DWORD *)(v5 + 4 * v6) + 44) & 1) != 0
          && *(_DWORD *)(*(_DWORD *)(this[6] + 4 * v6) + 44) != *(_DWORD *)(*(_DWORD *)(this[6] + 4 * v6 - 4) + 44) )
        {
          ++v9;
        }
        ++v6;
      }
      while ( v6 < this[3] );
    }
  }
  else if ( (v1 & 0x8000000) != 0 )
  {
    v7 = this[3];
    if ( v7 )
    {
      v8 = 1;
      do
      {
        if ( (*(_BYTE *)(*(_DWORD *)(this[6] + 4 * v2) + 44) & 1) != 0 )
        {
          ++v9;
          if ( v8 < v7
            && *(_DWORD *)(*(_DWORD *)(this[6] + 4 * v2) + 44) == *(_DWORD *)(*(_DWORD *)(this[6] + 4 * v2 + 4) + 44) )
          {
            ++v2;
            ++v8;
          }
        }
        ++v2;
        ++v8;
      }
      while ( v2 < v7 );
    }
  }
  return v9;
}
