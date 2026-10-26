int __thiscall sub_6A0FA0(_DWORD *this)
{
  unsigned int v1; // edi
  int v3; // ebx
  int v4; // eax
  int v5; // eax
  unsigned int v6; // eax
  int v7; // edi
  int v8; // eax
  int v9; // ecx
  int v10; // ecx
  int v11; // ebx
  unsigned int v12; // eax
  int v13; // eax
  int v14; // edi
  int v15; // eax
  unsigned int j; // ecx
  _DWORD *v17; // eax
  int v19; // [esp+18h] [ebp-20h]
  unsigned int i; // [esp+1Ch] [ebp-1Ch]
  unsigned int v21; // [esp+20h] [ebp-18h]
  int v22; // [esp+24h] [ebp-14h]
  int v23; // [esp+28h] [ebp-10h]
  unsigned int v24; // [esp+28h] [ebp-10h]
  unsigned int v25; // [esp+2Ch] [ebp-Ch]
  int v26; // [esp+30h] [ebp-8h] BYREF
  unsigned int v27; // [esp+34h] [ebp-4h]

  v1 = 0;
  v3 = -1;
  v22 = 0;
  if ( !this[3] )
    return 0;
  do
  {
    v4 = this[6];
    this[63] = v1;
    v5 = *(_DWORD *)(v4 + 4 * v1);
    this[64] = v5;
    if ( (*(_WORD *)(v5 + 2) & 0xFFF0) != 0 )
    {
      v6 = *(_DWORD *)(v5 + 4) / (*(_DWORD *)v5 & 0xFFFFFu);
      v27 = 0;
      for ( i = v6; v27 < i; ++v27 )
      {
        v25 = 0;
        v21 = sub_680D41((_DWORD *)this[64], v27, &v26);
        if ( v21 )
        {
          do
          {
            v7 = 4 * v25;
            v8 = *(_DWORD *)(this[5] + 4 * *(_DWORD *)(4 * v25 + v26));
            v9 = *(_DWORD *)(*(_DWORD *)(this[4] + 4 * *(_DWORD *)(v8 + 4)) + 4);
            if ( (v9 & 0x10) == 0
              || (v9 & 0x200) != 0
              || (*(int (__thiscall **)(_DWORD *, _DWORD))(*this + 84))(this, *(_DWORD *)(v8 + 108)) != 17
              || !v27 && (*(_DWORD *)this[64] & 0xFFF00000) == 0x30000000 )
            {
              break;
            }
            if ( v3 == -1 )
            {
              v24 = 0;
              if ( this[2] )
              {
                v10 = this[5];
                v11 = this[2];
                do
                {
                  if ( this[34] == *(_DWORD *)(*(_DWORD *)v10 + 4) )
                  {
                    v12 = *(_DWORD *)(*(_DWORD *)v10 + 12);
                    if ( v12 >= v24 )
                      v24 = v12 + 1;
                  }
                  v10 += 4;
                  --v11;
                }
                while ( v11 );
              }
              v3 = sub_681AAA(this, this[34], v24, 0, 0.0);
              if ( v3 == -1 )
                return -2147024882;
              sub_681692(*(_DWORD **)(this[5] + 4 * v3), *(_DWORD **)(this[5] + 4 * *(_DWORD *)(v7 + v26)));
              *(_DWORD *)(*(_DWORD *)(this[5] + 4 * v3) + 108) = -1;
              v19 = *(_DWORD *)(v7 + v26);
              v23 = this[64];
            }
            ++v25;
            *(_DWORD *)(v7 + v26) = v3;
          }
          while ( v25 < v21 );
          v1 = v22;
        }
      }
    }
    v22 = ++v1;
  }
  while ( v1 < this[3] );
  if ( v3 == -1 )
    return 0;
  v13 = sub_681B0A(this, 805306369, 3, 1);
  if ( v13 != -1 )
  {
    v14 = *(_DWORD *)(this[6] + 4 * v13);
    sub_680D22((_DWORD *)v14, v23);
    **(_DWORD **)(v14 + 16) = v3;
    **(_DWORD **)(v14 + 8) = v19;
    *(_DWORD *)(*(_DWORD *)(v14 + 8) + 4) = sub_681AAA(this, this[30], 0, 0, 1.0);
    *(_DWORD *)(*(_DWORD *)(v14 + 8) + 8) = sub_681AAA(this, this[30], 0, 0, -1.0);
    v15 = *(_DWORD *)(v14 + 8);
    if ( *(_DWORD *)(v15 + 4) != -1 && *(_DWORD *)(v15 + 8) != -1 )
    {
      for ( j = this[3]; ; v17[j] = v17[j - 1] )
      {
        v17 = (_DWORD *)this[6];
        if ( j <= 1 )
          break;
        --j;
      }
      *v17 = v14;
      return 0;
    }
  }
  return -2147024882;
}
