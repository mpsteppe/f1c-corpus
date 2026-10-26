int __stdcall sub_6CE540(_DWORD *a1, int a2)
{
  _DWORD *v2; // ebx
  unsigned int v3; // ecx
  int v4; // esi
  int v5; // eax
  unsigned int v6; // edi
  int v7; // ecx
  _DWORD *v8; // esi
  int v9; // eax
  int v10; // edx
  int v11; // edi
  int v12; // eax
  _DWORD *v13; // ebx
  bool v14; // cc
  int v15; // ecx
  unsigned int v16; // edx
  unsigned int v17; // ecx
  _DWORD *v18; // eax
  bool v20; // cf
  int v21; // edx
  int v22; // ecx
  int v23; // [esp+Ch] [ebp-38h]
  void (__stdcall *v24)(_DWORD *, _DWORD *, _DWORD, int, int); // [esp+10h] [ebp-34h]
  unsigned int v25; // [esp+14h] [ebp-30h]
  int v26; // [esp+18h] [ebp-2Ch]
  int i; // [esp+1Ch] [ebp-28h]
  int v28; // [esp+20h] [ebp-24h]
  int v29; // [esp+24h] [ebp-20h]
  unsigned int v30; // [esp+28h] [ebp-1Ch]
  _DWORD *v31; // [esp+2Ch] [ebp-18h]
  int v32; // [esp+30h] [ebp-14h]
  int v33; // [esp+34h] [ebp-10h]
  int v34; // [esp+38h] [ebp-Ch]
  unsigned int v35; // [esp+3Ch] [ebp-8h]
  int v36; // [esp+40h] [ebp-4h]

  v2 = a1;
  v3 = a1[88] - 1;
  v4 = a1[108];
  v25 = a1[81] - 1;
  v5 = *(_DWORD *)(v4 + 24);
  v34 = v4;
  v30 = v3;
  v36 = v5;
  if ( v5 >= *(_DWORD *)(v4 + 28) )
  {
LABEL_23:
    v15 = v2[38];
    ++v2[40];
    v16 = v2[81];
    v17 = v15 + 1;
    v2[38] = v17;
    if ( v17 >= v16 )
    {
      (*(void (__stdcall **)(_DWORD *))(v2[110] + 12))(v2);
      return 4;
    }
    else
    {
      v18 = (_DWORD *)v2[108];
      if ( (int)v2[83] <= 1 )
      {
        v20 = v17 < v16 - 1;
        v21 = v2[84];
        if ( v20 )
          v22 = *(_DWORD *)(v21 + 12);
        else
          v22 = *(_DWORD *)(v21 + 72);
        v18[7] = v22;
        v18[5] = 0;
        v18[6] = 0;
        return 3;
      }
      else
      {
        v18[7] = 1;
        v18[5] = 0;
        v18[6] = 0;
        return 3;
      }
    }
  }
  else
  {
    while ( 1 )
    {
      v6 = *(_DWORD *)(v4 + 20);
      v35 = v6;
      if ( v6 <= v3 )
        break;
LABEL_22:
      *(_DWORD *)(v4 + 20) = 0;
      v36 = ++v5;
      if ( v5 >= *(_DWORD *)(v4 + 28) )
        goto LABEL_23;
    }
    while ( 1 )
    {
      sub_6B6070(*(void **)(v4 + 32), v2[90] << 7);
      if ( !(*(int (__stdcall **)(_DWORD *, int))(v2[112] + 4))(v2, v4 + 32) )
        break;
      v7 = 0;
      v33 = 0;
      v26 = 0;
      if ( (int)v2[83] > 0 )
      {
        v31 = v2 + 84;
        do
        {
          v8 = (_DWORD *)*v31;
          if ( *(_DWORD *)(*v31 + 48) )
          {
            v9 = 4 * v8[1];
            v24 = *(void (__stdcall **)(_DWORD *, _DWORD *, _DWORD, int, int))(v2[113] + v9 + 4);
            if ( v6 >= v30 )
              v10 = v8[17];
            else
              v10 = v8[13];
            v11 = v35 * v8[16];
            v29 = v10;
            v32 = *(_DWORD *)(v9 + a2) + 4 * v36 * v8[9];
            v12 = 0;
            v23 = v11;
            for ( i = 0; v12 < v8[14]; i = v12 )
            {
              if ( (v2[38] < v25 || v12 + v36 < v8[18]) && v29 > 0 )
              {
                v13 = (_DWORD *)(v34 + 4 * v7 + 32);
                v28 = v29;
                do
                {
                  v24(a1, v8, *v13, v32, v11);
                  v11 += v8[9];
                  ++v13;
                  --v28;
                }
                while ( v28 );
                v12 = i;
                v11 = v23;
                v7 = v33;
              }
              v7 += v8[13];
              v2 = a1;
              v32 += 4 * v8[9];
              ++v12;
              v33 = v7;
            }
          }
          else
          {
            v7 += v8[15];
            v33 = v7;
          }
          v6 = v35;
          v14 = ++v26 < v2[83];
          ++v31;
        }
        while ( v14 );
      }
      v4 = v34;
      v35 = ++v6;
      if ( v6 > v30 )
      {
        v5 = v36;
        v3 = v30;
        goto LABEL_22;
      }
    }
    *(_DWORD *)(v34 + 20) = v6;
    *(_DWORD *)(v34 + 24) = v36;
    return 0;
  }
}
