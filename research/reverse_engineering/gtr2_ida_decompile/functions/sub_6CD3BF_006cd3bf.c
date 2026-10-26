unsigned int *__thiscall sub_6CD3BF(_DWORD *this, _DWORD *a2, unsigned int *a3)
{
  unsigned int v3; // ebx
  int v4; // edx
  int v5; // eax
  int v6; // esi
  int v7; // edi
  int v8; // esi
  unsigned int v9; // edi
  unsigned int *result; // eax
  unsigned int v11; // [esp+4h] [ebp-18h]
  unsigned int v12; // [esp+4h] [ebp-18h]
  unsigned int v13; // [esp+8h] [ebp-14h]
  unsigned int j; // [esp+8h] [ebp-14h]
  unsigned int v15; // [esp+Ch] [ebp-10h]
  int v16; // [esp+10h] [ebp-Ch]
  unsigned int i; // [esp+14h] [ebp-8h]
  unsigned int v18; // [esp+18h] [ebp-4h]

  v3 = 0;
  v11 = 0;
  v16 = 0;
  v15 = 0;
  for ( i = 0; i < this[14]; ++i )
  {
    v4 = *(_DWORD *)(this[15] + 4 * i);
    v5 = 4 * v4;
    v6 = *(_DWORD *)(4 * v4 + *(_DWORD *)(this[1] + 24));
    *(_DWORD *)(v5 + this[11]) = v3;
    *(_DWORD *)(v5 + this[10]) = 0;
    if ( (*(_WORD *)(v6 + 2) & 0xFFF0) != 0 )
    {
      v18 = 0;
      v7 = this[4] + 4 * *(_DWORD *)(v5 + this[3]);
      v13 = *(_DWORD *)(v5 + this[2]);
      if ( v13 )
      {
        do
        {
          if ( v4 == *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this[1] + 20) + 4 * *(_DWORD *)(v7 + 4 * v18)) + 88) )
            --*(_DWORD *)(v5 + this[10]);
          ++v18;
        }
        while ( v18 < v13 );
        v3 = v11;
      }
      v8 = this[9] + 4 * *(_DWORD *)(v5 + this[8]);
      v9 = 0;
      v12 = *(_DWORD *)(v5 + this[7]);
      for ( j = 0; j < v12; ++j )
      {
        if ( *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this[1] + 20) + 4 * *(_DWORD *)(v8 + 4 * v9)) + 92) )
          ++*(_DWORD *)(v5 + this[10]);
        v9 = j + 1;
      }
      v16 += v3;
      if ( v3 > v15 )
        v15 = v3;
      v3 += *(_DWORD *)(this[10] + 4 * v4);
      v11 = v3;
    }
  }
  if ( a2 )
    *a2 = v16;
  result = a3;
  if ( a3 )
    *a3 = v15;
  return result;
}
