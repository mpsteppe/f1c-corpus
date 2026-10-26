int __stdcall sub_6D3E70(_DWORD *a1, int a2)
{
  _DWORD *v2; // esi
  unsigned int v3; // ecx
  _DWORD *v4; // edi
  int v5; // eax
  int v6; // edx
  _DWORD *v7; // ecx
  int result; // eax
  int v9; // ebx
  _DWORD *v10; // esi
  _DWORD *v11; // esi
  int v12; // edi
  int v13; // eax
  bool v14; // zf
  _WORD **v15; // ecx
  bool v16; // cc
  int v17; // edx
  int v18; // [esp+Ch] [ebp-34h]
  _WORD *v19; // [esp+10h] [ebp-30h]
  unsigned int v20; // [esp+14h] [ebp-2Ch]
  _DWORD *v21; // [esp+18h] [ebp-28h]
  int v22; // [esp+1Ch] [ebp-24h]
  int v23; // [esp+20h] [ebp-20h]
  _WORD **v24; // [esp+20h] [ebp-20h]
  unsigned int v25; // [esp+24h] [ebp-1Ch]
  int v26; // [esp+28h] [ebp-18h]
  int v27; // [esp+2Ch] [ebp-14h]
  _WORD **v28; // [esp+30h] [ebp-10h]
  int v29; // [esp+30h] [ebp-10h]
  unsigned int v30; // [esp+34h] [ebp-Ch]
  int v31; // [esp+38h] [ebp-8h]
  _DWORD *v32; // [esp+3Ch] [ebp-4h]

  v2 = a1;
  v3 = a1[68] - 1;
  v4 = (_DWORD *)a1[88];
  v20 = a1[62] - 1;
  v5 = v4[4];
  v32 = v4;
  v25 = v3;
  v31 = v5;
  if ( v5 < v4[5] )
  {
    while ( 1 )
    {
      v30 = v4[3];
      if ( v30 <= v3 )
        break;
LABEL_29:
      v4[3] = 0;
      v31 = ++v5;
      if ( v5 >= v4[5] )
        goto LABEL_2;
      v3 = v25;
    }
    while ( 1 )
    {
      v9 = 0;
      v22 = 0;
      if ( (int)v2[63] > 0 )
      {
        v10 = v2 + 64;
        v21 = v10;
        do
        {
          v11 = (_DWORD *)*v10;
          if ( v30 >= v25 )
            v12 = v11[17];
          else
            v12 = v11[13];
          v18 = v30 * v11[16];
          v27 = 8 * v31;
          v26 = 0;
          if ( (int)v11[14] > 0 )
          {
            v13 = v11[13];
            do
            {
              if ( v32[2] < v20 || v31 + v26 < v11[18] )
              {
                (*(void (__stdcall **)(_DWORD *, _DWORD *, _DWORD, _DWORD, int, int, int))(a1[92] + 4))(
                  a1,
                  v11,
                  *(_DWORD *)(a2 + 4 * v11[1]),
                  v32[v9 + 6],
                  v27,
                  v18,
                  v12);
                v13 = v11[13];
                if ( v12 < v13 )
                {
                  sub_6B6070((void *)v32[v12 + 6 + v9], (v13 - v12) << 7);
                  v13 = v11[13];
                  if ( v12 < v13 )
                  {
                    v15 = (_WORD **)&v32[v12 + 6 + v9];
                    v24 = v15;
                    v29 = v13 - v12;
                    do
                    {
                      **v15 = **(v15 - 1);
                      v15 = v24 + 1;
                      v14 = v29 == 1;
                      ++v24;
                      --v29;
                    }
                    while ( !v14 );
                  }
                }
              }
              else
              {
                sub_6B6070((void *)v32[v9 + 6], v13 << 7);
                v13 = v11[13];
                if ( v13 > 0 )
                {
                  v19 = (_WORD *)v32[v9 + 5];
                  v28 = (_WORD **)&v32[v9 + 6];
                  v23 = v11[13];
                  do
                  {
                    **v28 = *v19;
                    v14 = v23 == 1;
                    ++v28;
                    --v23;
                  }
                  while ( !v14 );
                }
              }
              v27 += 8;
              v9 += v13;
              ++v26;
            }
            while ( v26 < v11[14] );
          }
          v10 = v21 + 1;
          v16 = ++v22 < a1[63];
          ++v21;
        }
        while ( v16 );
        v4 = v32;
        v2 = a1;
      }
      if ( !(*(int (__stdcall **)(_DWORD *, _DWORD *))(v2[93] + 4))(v2, v4 + 6) )
        break;
      if ( ++v30 > v25 )
      {
        v5 = v31;
        goto LABEL_29;
      }
    }
    v4[4] = v31;
    v4[3] = v30;
    return 0;
  }
  else
  {
LABEL_2:
    v6 = v2[63];
    v7 = (_DWORD *)v2[88];
    result = 1;
    ++v4[2];
    if ( v6 <= 1 )
    {
      v17 = v2[64];
      if ( v7[2] >= (unsigned int)(v2[62] - 1) )
        v7[5] = *(_DWORD *)(v17 + 72);
      else
        v7[5] = *(_DWORD *)(v17 + 12);
      v7[3] = 0;
      v7[4] = 0;
    }
    else
    {
      v7[5] = 1;
      v7[3] = 0;
      v7[4] = 0;
    }
  }
  return result;
}
