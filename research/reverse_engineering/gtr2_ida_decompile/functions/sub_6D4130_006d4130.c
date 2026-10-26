int __stdcall sub_6D4130(_DWORD *a1, int a2)
{
  _DWORD *v2; // edx
  int v3; // eax
  _DWORD *v4; // ebx
  int v5; // esi
  _DWORD *v6; // edi
  int v7; // eax
  bool v8; // cc
  unsigned int v9; // edi
  bool v10; // cf
  int v11; // eax
  int v12; // esi
  int v13; // ecx
  _DWORD *v14; // edi
  int v15; // eax
  int *v16; // ecx
  int v17; // edx
  unsigned int v18; // eax
  int v19; // ecx
  int v20; // esi
  _DWORD *v21; // ecx
  int result; // eax
  int v23; // eax
  int v24; // esi
  int v25; // edx
  int v26; // [esp-Ch] [ebp-4Ch]
  _DWORD v27[4]; // [esp+Ch] [ebp-34h]
  int v28; // [esp+1Ch] [ebp-24h]
  int v29; // [esp+20h] [ebp-20h]
  int v30; // [esp+24h] [ebp-1Ch]
  int v31; // [esp+28h] [ebp-18h]
  _DWORD *v32; // [esp+2Ch] [ebp-14h]
  _DWORD *v33; // [esp+30h] [ebp-10h]
  int v34; // [esp+34h] [ebp-Ch]
  int v35; // [esp+38h] [ebp-8h]
  int v36; // [esp+3Ch] [ebp-4h]

  v2 = a1;
  v3 = a1[63];
  v4 = (_DWORD *)a1[88];
  v5 = 0;
  v32 = v4;
  if ( v3 > 0 )
  {
    v6 = a1 + 64;
    do
    {
      v26 = *(_DWORD *)(*v6 + 12) * v4[2];
      v4 = v32;
      v27[v5++] = (*(int (__stdcall **)(_DWORD *, _DWORD, int, _DWORD, _DWORD))(v2[1] + 32))(
                    a1,
                    v32[*(_DWORD *)(*v6 + 4) + 16],
                    v26,
                    *(_DWORD *)(*v6 + 12),
                    0);
      ++v6;
      v2 = a1;
    }
    while ( v5 < a1[63] );
  }
  v7 = v4[4];
  v8 = v7 < v4[5];
  v36 = v7;
  if ( v8 )
  {
    while ( 1 )
    {
      v9 = v4[3];
      v10 = v9 < v2[68];
      v30 = v9;
      if ( v10 )
        break;
LABEL_20:
      v4[3] = 0;
      v19 = v4[5];
      v36 = ++v7;
      if ( v7 >= v19 )
        goto LABEL_21;
    }
    while ( 1 )
    {
      v11 = v2[63];
      v35 = 0;
      v34 = 0;
      v28 = v11;
      if ( v11 > 0 )
      {
        v33 = v2 + 64;
        do
        {
          v12 = *(_DWORD *)(*v33 + 52);
          v13 = *(_DWORD *)(*v33 + 56);
          if ( v13 > 0 )
          {
            v29 = (v9 * *(_DWORD *)(*v33 + 52)) << 7;
            v14 = (_DWORD *)(v27[v34] + 4 * v36);
            v31 = v13;
            do
            {
              v15 = v29 + *v14;
              if ( v12 > 0 )
              {
                v16 = &v4[v35 + 6];
                v17 = v12;
                v35 += v12;
                do
                {
                  *v16++ = v15;
                  v15 += 128;
                  --v17;
                }
                while ( v17 );
                v4 = v32;
                v2 = a1;
              }
              ++v14;
              --v31;
            }
            while ( v31 );
            v9 = v30;
          }
          v8 = ++v34 < v28;
          ++v33;
        }
        while ( v8 );
      }
      if ( !(*(int (__stdcall **)(_DWORD *, _DWORD *))(v2[93] + 4))(v2, v4 + 6) )
        break;
      v2 = a1;
      v18 = a1[68];
      v30 = ++v9;
      if ( v9 >= v18 )
      {
        v7 = v36;
        goto LABEL_20;
      }
    }
    v23 = v36;
    v4[3] = v9;
    v4[4] = v23;
    return 0;
  }
  else
  {
LABEL_21:
    v20 = v2[63];
    v21 = (_DWORD *)v2[88];
    result = 1;
    ++v4[2];
    if ( v20 <= 1 )
    {
      v24 = v2[62];
      v25 = v2[64];
      if ( v21[2] >= (unsigned int)(v24 - 1) )
        v21[5] = *(_DWORD *)(v25 + 72);
      else
        v21[5] = *(_DWORD *)(v25 + 12);
      v21[3] = 0;
      v21[4] = 0;
    }
    else
    {
      v21[5] = 1;
      v21[3] = 0;
      v21[4] = 0;
    }
  }
  return result;
}
