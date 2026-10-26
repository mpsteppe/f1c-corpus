int __thiscall sub_682643(_DWORD *this)
{
  unsigned int i; // edi
  int v2; // eax
  int v3; // esi
  int v4; // edx
  int *v5; // esi
  int v6; // edi
  _DWORD *v7; // eax
  unsigned int v8; // ebx
  unsigned int v9; // eax
  unsigned int v10; // edi
  int v11; // eax
  int v12; // edx
  int v13; // edx
  int v14; // edx
  int v15; // eax
  int v16; // ebx
  int v17; // edi
  int v18; // eax
  int v19; // edx
  int v20; // edx
  int v21; // ebx
  int v23; // [esp+Ch] [ebp-14h]
  int v24; // [esp+Ch] [ebp-14h]
  int v25; // [esp+Ch] [ebp-14h]
  unsigned int j; // [esp+10h] [ebp-10h]
  unsigned int v27; // [esp+14h] [ebp-Ch]
  unsigned int v28; // [esp+14h] [ebp-Ch]
  unsigned int k; // [esp+14h] [ebp-Ch]
  unsigned int v30; // [esp+18h] [ebp-8h]
  unsigned int v31; // [esp+18h] [ebp-8h]
  unsigned int v32; // [esp+1Ch] [ebp-4h]
  unsigned int v33; // [esp+1Ch] [ebp-4h]

  for ( i = 0; i < this[2]; ++i )
  {
    v2 = *(_DWORD *)(this[5] + 4 * i);
    v3 = *(_DWORD *)(this[4] + 4 * *(_DWORD *)(v2 + 4));
    v4 = *(_DWORD *)(v3 + 4);
    if ( (v4 & 0x30) != 0 && (v4 & 0x200) == 0 )
      *(_DWORD *)(v2 + 4) = this[29];
    if ( (*(_BYTE *)(v3 + 4) & 4) != 0 )
      *(_DWORD *)(v2 + 4) = this[34];
  }
  for ( j = 0; j < this[3]; ++j )
  {
    v5 = *(int **)(this[6] + 4 * j);
    v6 = *v5;
    if ( (*v5 & 0xFFF00000) != 0 )
    {
      v30 = 0;
      if ( v5[3] )
      {
        v7 = (_DWORD *)v5[4];
        v23 = v5[3];
        do
        {
          if ( (**(_BYTE **)(this[5] + 4 * *v7) & 0x20) != 0 )
            ++v30;
          ++v7;
          --v23;
        }
        while ( v23 );
      }
      v8 = v5[3];
      if ( v30 == v8 )
      {
        *v5 = 0;
      }
      else
      {
        if ( v30 < v8 && (v6 & 0xF0000000) >= 0x10000000 && (v6 & 0xF0000000) <= 0x40000000 )
        {
          v9 = v5[1] / (v6 & 0xFFFFFu);
          v10 = 0;
          v32 = 0;
          v31 = v9;
          if ( v8 )
          {
            do
            {
              v11 = v5[4];
              v12 = *(_DWORD *)(v11 + 4 * v32);
              if ( (**(_BYTE **)(this[5] + 4 * v12) & 0x20) == 0 )
              {
                v27 = 0;
                for ( *(_DWORD *)(v11 + 4 * v10) = v12;
                      v27 < v31;
                      *(_DWORD *)(v5[2] + 4 * (v10 + v13)) = *(_DWORD *)(v5[2] + 4 * (v13 + v32)) )
                {
                  v13 = v27 * v5[3];
                  ++v27;
                }
                ++v10;
              }
              ++v32;
            }
            while ( v32 < v5[3] );
          }
          v33 = 1;
          if ( v31 > 1 )
          {
            v24 = 4 * v10;
            do
            {
              v28 = 0;
              if ( v10 )
              {
                v14 = v24;
                do
                {
                  v15 = v5[2];
                  v16 = *(_DWORD *)(v15 + 4 * (v28 + v33 * v5[3]));
                  ++v28;
                  *(_DWORD *)(v14 + v15) = v16;
                  v14 += 4;
                }
                while ( v28 < v10 );
              }
              ++v33;
              v24 += 4 * v10;
            }
            while ( v33 < v31 );
          }
          *v5 ^= (v10 ^ *v5) & 0xFFFFF;
          v5[1] = v31 * v10;
          v5[3] = v10;
        }
        for ( k = 0; k < v5[3]; *(_DWORD *)(v18 + 20) = v19 )
        {
          v17 = this[5];
          v18 = *(_DWORD *)(v17 + 4 * *(_DWORD *)(v5[4] + 4 * k));
          v25 = *(_DWORD *)(v18 + 24);
          v19 = *(_DWORD *)(v18 + 20);
          while ( v19 != -1 && (**(_BYTE **)(4 * v19 + v17) & 0x20) != 0 )
          {
            v20 = *(_DWORD *)(4 * v19 + this[5]);
            v21 = *(_DWORD *)(v20 + 24);
            v19 = *(_DWORD *)(v20 + 20);
            v25 = v21;
          }
          ++k;
          *(_DWORD *)(v18 + 24) = v25;
        }
      }
    }
  }
  return 0;
}
