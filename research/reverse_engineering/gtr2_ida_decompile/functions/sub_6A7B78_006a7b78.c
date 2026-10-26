BOOL __thiscall sub_6A7B78(_DWORD *this)
{
  _DWORD *v1; // eax
  int v2; // esi
  int v3; // eax
  int v4; // edx
  int v5; // eax
  _DWORD *v6; // edx
  unsigned int v8; // [esp+4h] [ebp-28h]
  int v9; // [esp+8h] [ebp-24h]
  unsigned int v10; // [esp+Ch] [ebp-20h]
  unsigned int v11; // [esp+10h] [ebp-1Ch]
  unsigned int v12; // [esp+14h] [ebp-18h]
  int v13; // [esp+18h] [ebp-14h]
  int v14; // [esp+1Ch] [ebp-10h]
  unsigned int v15; // [esp+20h] [ebp-Ch]
  unsigned int v16; // [esp+24h] [ebp-8h]
  unsigned int v17; // [esp+28h] [ebp-4h]

  v1 = (_DWORD *)this[140];
  v11 = 18;
  v2 = 6;
  do
  {
    if ( *v1 && (*(_DWORD *)*v1 & 0xFFF00000) != 0x11000000 )
      v11 -= 3;
    ++v1;
    --v2;
  }
  while ( v2 );
  v12 = 0;
  if ( !this[136] )
    return 0;
  v14 = this[139];
  v9 = this[136];
  do
  {
    if ( *(_DWORD *)v14 )
    {
      v15 = 0;
      v8 = *(_DWORD *)(*(_DWORD *)v14 + 12);
      if ( v8 )
      {
        v3 = this[3];
        do
        {
          v16 = 0;
          if ( v3 )
          {
            v13 = this[6];
            do
            {
              if ( *(_DWORD *)(*(_DWORD *)v13 + 40) != 1 && !sub_6A2293(**(_DWORD **)v13 & 0xFFF00000) )
              {
                v17 = 0;
                v10 = *(_DWORD *)(v4 + 4);
                if ( v10 )
                {
                  v5 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)v14 + 16) + 4 * v15);
                  v6 = *(_DWORD **)(v4 + 8);
                  do
                  {
                    if ( *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *v6) + 56) == v5 )
                      break;
                    if ( *v6 == v5 )
                      break;
                    ++v17;
                    ++v6;
                  }
                  while ( v17 < v10 );
                }
                if ( v17 != v10 )
                  break;
              }
              ++v16;
              v13 += 4;
            }
            while ( v16 < this[3] );
          }
          v3 = this[3];
          if ( v16 != v3 )
            ++v12;
          ++v15;
        }
        while ( v15 < v8 );
      }
    }
    v14 += 4;
    --v9;
  }
  while ( v9 );
  return v12 > v11;
}
