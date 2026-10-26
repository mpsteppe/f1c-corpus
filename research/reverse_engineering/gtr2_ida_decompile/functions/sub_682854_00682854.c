BOOL __fastcall sub_682854(_DWORD *a1)
{
  int *v1; // esi
  int v2; // edi
  _DWORD *v3; // eax
  unsigned int v4; // eax
  unsigned int v5; // eax
  unsigned int v6; // edi
  int v7; // eax
  int v8; // edx
  int v9; // ebx
  int v10; // edx
  int v11; // eax
  int v12; // edx
  int v13; // ecx
  int v15; // [esp+4h] [ebp-1Ch]
  _DWORD *v16; // [esp+8h] [ebp-18h]
  int v17; // [esp+Ch] [ebp-14h]
  int v18; // [esp+Ch] [ebp-14h]
  unsigned int i; // [esp+10h] [ebp-10h]
  unsigned int v20; // [esp+14h] [ebp-Ch]
  unsigned int v21; // [esp+18h] [ebp-8h]
  unsigned int v22; // [esp+18h] [ebp-8h]
  unsigned int v23; // [esp+1Ch] [ebp-4h]
  unsigned int v24; // [esp+1Ch] [ebp-4h]

  v16 = a1;
  v15 = 0;
  for ( i = 0; i < a1[3]; ++i )
  {
    v1 = *(int **)(a1[6] + 4 * i);
    v2 = *v1;
    if ( (*v1 & 0xFFF00000) != 0 && (*v1 & 0xFFF00000) != 0x10100000 )
    {
      v23 = 0;
      if ( v1[3] )
      {
        v3 = (_DWORD *)v1[4];
        v17 = v1[3];
        do
        {
          if ( (**(_BYTE **)(a1[5] + 4 * *v3) & 0x20) == 0 )
            ++v23;
          ++v3;
          --v17;
        }
        while ( v17 );
        if ( v23 )
        {
          v4 = v1[3];
          v15 = 1;
          if ( v23 == v4 )
          {
            *v1 = 0;
          }
          else if ( v23 < v4 && (v2 & 0xF0000000) >= 0x10000000 && (v2 & 0xF0000000) <= 0x40000000 )
          {
            v5 = v1[1] / (v2 & 0xFFFFFu);
            v6 = 0;
            v24 = v5;
            v7 = 0;
            while ( 1 )
            {
              v8 = v1[4];
              v9 = *(_DWORD *)(v8 + 4 * v7);
              if ( (**(_BYTE **)(a1[5] + 4 * v9) & 0x20) != 0 )
              {
                v21 = 0;
                for ( *(_DWORD *)(v8 + 4 * v6) = v9;
                      v21 < v24;
                      *(_DWORD *)(v1[2] + 4 * (v6 + v10)) = *(_DWORD *)(v1[2] + 4 * (v10 + v7)) )
                {
                  v10 = v21 * v1[3];
                  ++v21;
                }
                ++v6;
              }
              if ( ++v7 >= (unsigned int)v1[3] )
                break;
              a1 = v16;
            }
            v20 = 1;
            if ( v24 > 1 )
            {
              v18 = 4 * v6;
              do
              {
                v22 = 0;
                if ( v6 )
                {
                  v11 = v18;
                  do
                  {
                    v12 = v1[2];
                    v13 = *(_DWORD *)(v12 + 4 * (v22 + v20 * v1[3]));
                    ++v22;
                    *(_DWORD *)(v11 + v12) = v13;
                    v11 += 4;
                  }
                  while ( v22 < v6 );
                }
                ++v20;
                v18 += 4 * v6;
              }
              while ( v20 < v24 );
            }
            a1 = v16;
            *v1 ^= (v6 ^ *v1) & 0xFFFFF;
            v1[1] = v24 * v6;
            v1[3] = v6;
          }
        }
      }
    }
  }
  return v15 == 0;
}
