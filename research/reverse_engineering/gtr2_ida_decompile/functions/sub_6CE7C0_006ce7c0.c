int __stdcall sub_6CE7C0(_DWORD *a1)
{
  _DWORD *v1; // ebx
  int v2; // esi
  int v3; // eax
  int v4; // ecx
  int v5; // eax
  _DWORD *v6; // eax
  int v7; // ecx
  bool v8; // cc
  unsigned int v9; // edi
  bool v10; // cf
  int v11; // eax
  int v12; // edx
  int v13; // esi
  int v14; // ecx
  int v15; // edx
  _DWORD *v16; // edi
  int v17; // eax
  int *v18; // ecx
  int v19; // edx
  unsigned int v20; // eax
  int v21; // edx
  unsigned int v22; // edx
  unsigned int v23; // ecx
  _DWORD *v24; // eax
  _DWORD *v26; // eax
  int v27; // edx
  int v28; // ecx
  int v29; // edx
  _DWORD v30[4]; // [esp+Ch] [ebp-34h]
  int v31; // [esp+1Ch] [ebp-24h]
  int v32; // [esp+20h] [ebp-20h]
  int v33; // [esp+24h] [ebp-1Ch]
  int v34; // [esp+28h] [ebp-18h]
  int v35; // [esp+2Ch] [ebp-14h]
  _DWORD *v36; // [esp+30h] [ebp-10h]
  int v37; // [esp+34h] [ebp-Ch]
  int v38; // [esp+38h] [ebp-8h]
  _DWORD *v39; // [esp+3Ch] [ebp-4h]

  v1 = a1;
  v39 = (_DWORD *)a1[108];
  v2 = 0;
  if ( (int)a1[83] > 0 )
  {
    v38 = (int)(a1 + 84);
    do
    {
      v3 = (*(int (__stdcall **)(_DWORD *, _DWORD, int, _DWORD, int))(a1[1] + 32))(
             a1,
             v39[*(_DWORD *)(*(_DWORD *)v38 + 4) + 18],
             *(_DWORD *)(*(_DWORD *)v38 + 12) * a1[38],
             *(_DWORD *)(*(_DWORD *)v38 + 12),
             1);
      v4 = v38;
      v30[v2] = v3;
      v5 = a1[83];
      ++v2;
      v38 = v4 + 4;
    }
    while ( v2 < v5 );
  }
  v6 = v39;
  v7 = v39[6];
  v8 = v7 < v39[7];
  v38 = v7;
  if ( v8 )
  {
    while ( 1 )
    {
      v9 = v6[5];
      v10 = v9 < v1[88];
      v33 = v9;
      if ( v10 )
        break;
LABEL_20:
      v6 = v39;
      v39[5] = 0;
      v21 = v6[7];
      v38 = ++v7;
      if ( v7 >= v21 )
        goto LABEL_21;
    }
    while ( 1 )
    {
      v11 = v1[83];
      v12 = 0;
      v37 = 0;
      v34 = 0;
      if ( v11 > 0 )
      {
        v31 = v11;
        v36 = v1 + 84;
        do
        {
          v13 = *(_DWORD *)(*v36 + 52);
          v14 = *(_DWORD *)(*v36 + 56);
          if ( v14 > 0 )
          {
            v15 = v30[v12];
            v32 = (v9 * *(_DWORD *)(*v36 + 52)) << 7;
            v16 = (_DWORD *)(v15 + 4 * v38);
            v35 = v14;
            do
            {
              v17 = v32 + *v16;
              if ( v13 > 0 )
              {
                v18 = &v39[v37 + 8];
                v19 = v13;
                v37 += v13;
                do
                {
                  *v18++ = v17;
                  v17 += 128;
                  --v19;
                }
                while ( v19 );
                v1 = a1;
              }
              ++v16;
              --v35;
            }
            while ( v35 );
            v9 = v33;
            v12 = v34;
          }
          v34 = ++v12;
          ++v36;
        }
        while ( v12 < v31 );
      }
      if ( !(*(int (__stdcall **)(_DWORD *, _DWORD *))(v1[112] + 4))(v1, v39 + 8) )
        break;
      v20 = v1[88];
      v33 = ++v9;
      if ( v9 >= v20 )
      {
        v7 = v38;
        goto LABEL_20;
      }
    }
    v26 = v39;
    v27 = v38;
    v39[5] = v9;
    v26[6] = v27;
    return 0;
  }
  else
  {
LABEL_21:
    v22 = v1[81];
    v23 = v1[38] + 1;
    v1[38] = v23;
    if ( v23 >= v22 )
    {
      (*(void (__stdcall **)(_DWORD *))(v1[110] + 12))(v1);
      return 4;
    }
    else
    {
      v24 = (_DWORD *)v1[108];
      if ( (int)v1[83] <= 1 )
      {
        v10 = v23 < v22 - 1;
        v28 = v1[84];
        if ( v10 )
          v29 = *(_DWORD *)(v28 + 12);
        else
          v29 = *(_DWORD *)(v28 + 72);
        v24[7] = v29;
        v24[5] = 0;
        v24[6] = 0;
        return 3;
      }
      else
      {
        v24[7] = 1;
        v24[5] = 0;
        v24[6] = 0;
        return 3;
      }
    }
  }
}
