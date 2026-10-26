int __stdcall sub_6D4340(_DWORD *a1, int a2)
{
  _DWORD *v2; // eax
  _DWORD *v3; // esi
  int v4; // edi
  int v5; // ecx
  unsigned int v6; // ebx
  int v7; // edi
  int v8; // eax
  int v9; // esi
  _WORD *v10; // esi
  __int16 v11; // cx
  int v12; // eax
  bool v13; // cc
  unsigned int v14; // ebx
  int v15; // eax
  char *v16; // ebx
  int v17; // edi
  unsigned int v18; // ecx
  unsigned int v19; // edx
  __int16 v20; // si
  _WORD *v21; // eax
  int v23; // [esp+8h] [ebp-30h]
  unsigned int v24; // [esp+Ch] [ebp-2Ch]
  int v25; // [esp+10h] [ebp-28h]
  int v26; // [esp+14h] [ebp-24h]
  unsigned int v27; // [esp+18h] [ebp-20h]
  _DWORD *v28; // [esp+1Ch] [ebp-1Ch]
  _DWORD *v29; // [esp+20h] [ebp-18h]
  int v30; // [esp+24h] [ebp-14h]
  _DWORD *v31; // [esp+28h] [ebp-10h]
  unsigned int v32; // [esp+2Ch] [ebp-Ch]
  int v33; // [esp+30h] [ebp-8h]
  int v34; // [esp+30h] [ebp-8h]
  int v35; // [esp+34h] [ebp-4h]
  int v36; // [esp+34h] [ebp-4h]

  v2 = a1;
  v3 = (_DWORD *)a1[17];
  v27 = a1[62] - 1;
  v4 = a1[88];
  v26 = v4;
  v25 = 0;
  v31 = v3;
  if ( (int)a1[15] > 0 )
  {
    v28 = (_DWORD *)a2;
    v29 = (_DWORD *)(v4 + 64);
    while ( 1 )
    {
      v5 = (*(int (__stdcall **)(_DWORD *, _DWORD, int, _DWORD, int))(v2[1] + 32))(
             v2,
             *v29,
             v3[3] * *(_DWORD *)(v4 + 8),
             v3[3],
             1);
      v30 = v5;
      if ( *(_DWORD *)(v4 + 8) >= v27 )
      {
        v33 = v3[8] % v3[3];
        if ( !v33 )
          v33 = v3[3];
      }
      else
      {
        v33 = v3[3];
      }
      v6 = v3[7];
      v32 = v3[2];
      v7 = v6 % v32;
      if ( (int)(v6 % v32) > 0 )
        v7 = v32 - v7;
      v8 = 0;
      v35 = 0;
      if ( v33 > 0 )
      {
        while ( 1 )
        {
          v9 = *(_DWORD *)(v5 + 4 * v8);
          (*(void (__stdcall **)(_DWORD *, _DWORD *, _DWORD, int, int, _DWORD, unsigned int))(a1[92] + 4))(
            a1,
            v31,
            *v28,
            v9,
            8 * v8,
            0,
            v6);
          if ( v7 > 0 )
          {
            v10 = (_WORD *)((v6 << 7) + v9);
            sub_6B6070(v10, v7 << 7);
            v11 = *(v10 - 64);
            v12 = v7;
            do
            {
              *v10 = v11;
              v10 += 64;
              --v12;
            }
            while ( v12 );
          }
          v13 = v35 + 1 < v33;
          v5 = v30;
          ++v35;
          if ( !v13 )
            break;
          v8 = v35;
        }
        v3 = v31;
      }
      if ( *(_DWORD *)(v26 + 8) == v27 )
      {
        v14 = v7 + v6;
        v23 = v14 / v32;
        v15 = v33;
        v36 = v33;
        if ( v33 < v3[3] )
        {
          v24 = v14 << 7;
          while ( 1 )
          {
            v16 = *(char **)(v5 + 4 * v15);
            v17 = *(_DWORD *)(v5 + 4 * v15 - 4);
            sub_6B6070(v16, v24);
            if ( v23 )
            {
              v18 = v32 << 7;
              v34 = v23;
              do
              {
                v19 = v32;
                v20 = *(_WORD *)(v18 + v17 - 128);
                if ( (int)v32 > 0 )
                {
                  v21 = v16;
                  do
                  {
                    *v21 = v20;
                    v21 += 64;
                    --v19;
                  }
                  while ( v19 );
                }
                v16 += v18;
                v17 += v18;
                --v34;
              }
              while ( v34 );
              v3 = v31;
            }
            if ( ++v36 >= v3[3] )
              break;
            v5 = v30;
            v15 = v36;
          }
        }
      }
      ++v29;
      v3 += 21;
      ++v25;
      ++v28;
      v31 = v3;
      v2 = a1;
      if ( v25 >= a1[15] )
        break;
      v4 = v26;
    }
  }
  return sub_6D4130(v2, a2);
}
