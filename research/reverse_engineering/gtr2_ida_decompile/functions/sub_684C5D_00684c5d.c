BOOL __thiscall sub_684C5D(_DWORD *this)
{
  unsigned int v2; // eax
  int v3; // ebx
  int k; // eax
  int v5; // edx
  int v6; // ecx
  unsigned int v7; // ecx
  _DWORD *v8; // eax
  bool v9; // cf
  int v10; // eax
  _DWORD *v11; // ecx
  _DWORD *v12; // eax
  int i; // [esp+4h] [ebp-18h]
  int v15; // [esp+8h] [ebp-14h]
  int v16; // [esp+8h] [ebp-14h]
  unsigned int j; // [esp+Ch] [ebp-10h]
  _DWORD *v18; // [esp+10h] [ebp-Ch] BYREF
  unsigned int m; // [esp+14h] [ebp-8h]
  unsigned int v20; // [esp+18h] [ebp-4h]

  v2 = 0;
  for ( i = 0; v2 < this[2]; ++v2 )
    *(_DWORD *)(*(_DWORD *)(this[5] + 4 * v2) + 48) = -1;
  for ( j = 0; j < this[3]; ++j )
  {
    v3 = *(_DWORD *)(this[6] + 4 * j);
    if ( (*(_WORD *)(v3 + 2) & 0xFFF0) != 0 )
    {
      v15 = 0;
      for ( k = sub_680D41((_DWORD *)v3, 0, &v18); ; k = sub_680D41((_DWORD *)v3, v15, &v18) )
      {
        v20 = k;
        if ( !k )
          break;
        v5 = 4 * *v18;
        if ( *(_DWORD *)(*(_DWORD *)(v5 + this[5]) + 48) != -1 )
        {
          m = 1;
          if ( v20 <= 1 )
            goto LABEL_12;
          do
          {
            v6 = 4 * v18[m];
            if ( *(_DWORD *)(*(_DWORD *)(v6 + this[5]) + 48) == -1 )
              break;
            if ( *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *(_DWORD *)(*(_DWORD *)(this[5] + v5) + 48)) + 12) != *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *(_DWORD *)(*(_DWORD *)(this[5] + v6) + 48)) + 12) )
              break;
            ++m;
          }
          while ( m < v20 );
          if ( m >= v20 )
          {
LABEL_12:
            v7 = 0;
            if ( v20 )
            {
              do
              {
                v8 = &v18[v7++];
                v9 = v7 < v20;
                *v8 = *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *v8) + 48);
              }
              while ( v9 );
            }
            i = 1;
          }
        }
        ++v15;
      }
      if ( (*(_DWORD *)v3 & 0xFFF00000) == 0x10000000 )
      {
        for ( m = 0; m < *(_DWORD *)(v3 + 12); ++m )
        {
          v10 = this[5];
          v16 = *(_DWORD *)(4 * m + *(_DWORD *)(v3 + 16));
          v11 = *(_DWORD **)(v10 + 4 * v16);
          v12 = *(_DWORD **)(v10 + 4 * *(_DWORD *)(4 * m + *(_DWORD *)(v3 + 8)));
          if ( v11[1] == v12[1]
            && v11[2] == v12[2]
            && v11[4] == v12[4]
            && v11[5] == v12[5]
            && v11[6] == v12[6]
            && v12[14] == -1
            && !v11[15] )
          {
            v12[12] = v16;
          }
        }
      }
    }
  }
  return i == 0;
}
