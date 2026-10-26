int __thiscall sub_6A7E91(
        _DWORD *this,
        int a2,
        unsigned int a3,
        unsigned int a4,
        _DWORD *a5,
        int a6,
        unsigned int *a7,
        _DWORD *a8,
        _DWORD *a9)
{
  unsigned int v9; // eax
  int *v10; // esi
  int v11; // eax
  int v12; // ecx
  int v13; // eax
  int v14; // edx
  int v15; // ebx
  int v16; // ecx
  unsigned int j; // edx
  int v19; // [esp+4h] [ebp-2Ch]
  unsigned int v20; // [esp+8h] [ebp-28h]
  unsigned int i; // [esp+Ch] [ebp-24h]
  int v22; // [esp+10h] [ebp-20h]
  unsigned int v23; // [esp+14h] [ebp-1Ch]
  int v24; // [esp+18h] [ebp-18h]
  unsigned int v26; // [esp+20h] [ebp-10h]
  unsigned int v27; // [esp+24h] [ebp-Ch]
  _DWORD *v28; // [esp+28h] [ebp-8h]
  int v29; // [esp+2Ch] [ebp-4h]
  int v30; // [esp+3Ch] [ebp+Ch]

  *a8 = 0;
  *a9 = 0;
  v9 = a3;
  v27 = 0;
  for ( i = a3; i < a4; ++i )
  {
    v10 = *(int **)(a2 + 4 * v9);
    if ( v10 )
    {
      v11 = *v10;
      if ( *v10 )
      {
        v12 = v11 & 0xFFFFF;
        v19 = v11 & 0xFFFFF;
        v26 = 0;
        v20 = v10[1] / (v11 & 0xFFFFFu);
        if ( a6 )
        {
          v28 = a5;
          v22 = a6;
          do
          {
            if ( v20 )
            {
              v29 = 0;
              v23 = v20;
              do
              {
                v30 = 0;
                if ( v12 )
                {
                  v13 = v29;
                  v24 = v12;
                  do
                  {
                    v14 = *(_DWORD *)(v13 + v10[2]);
                    v15 = this[5];
                    if ( *(_DWORD *)(*(_DWORD *)(v15 + 4 * v14) + 56) == *v28 || v14 == *v28 )
                    {
                      ++v30;
                      v16 = ++v26;
                      if ( v26 > v27 )
                        v27 = v16;
                      if ( v10[3] == 1 && *(_DWORD *)(*(_DWORD *)(v15 + 4 * *(_DWORD *)v10[4]) + 16) == 3 )
                        *a8 = 1;
                      if ( (*v10 & 0xFFF00000) != 0x50000000 )
                      {
                        for ( j = 0; j < v10[3]; ++j )
                        {
                          if ( *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *(_DWORD *)(v10[4] + 4 * j)) + 16) == 3 )
                            *a8 = 1;
                        }
                      }
                    }
                    v13 += 4;
                    --v24;
                  }
                  while ( v24 );
                  v12 = v19;
                }
                if ( v30 != v12 && v30 )
                  *a9 = 1;
                v29 += 4 * v12;
                --v23;
              }
              while ( v23 );
            }
            ++v28;
            --v22;
          }
          while ( v22 );
        }
      }
    }
    v9 = i + 1;
  }
  *a7 = v27;
  return 0;
}
