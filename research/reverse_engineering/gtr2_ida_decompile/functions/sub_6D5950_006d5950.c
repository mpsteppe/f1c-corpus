int __stdcall sub_6D5950(_DWORD *a1, int *a2)
{
  _DWORD *v2; // ebx
  _DWORD *v3; // eax
  _DWORD *v4; // esi
  int v5; // edx
  int v6; // eax
  int v7; // edi
  int v8; // edx
  int v9; // eax
  int v10; // edi
  int v11; // edi
  unsigned int v12; // ebx
  int v13; // eax
  int v14; // edi
  int v15; // ebx
  int v16; // eax
  int v17; // ecx
  int v18; // eax
  _DWORD *v19; // eax
  int v20; // eax
  _DWORD *v21; // eax
  int v22; // ebx
  int v23; // edx
  int v25; // [esp+Ch] [ebp-14h]
  int v26; // [esp+10h] [ebp-10h]
  int v27; // [esp+14h] [ebp-Ch]
  int v28; // [esp+18h] [ebp-8h]
  int v29; // [esp+1Ch] [ebp-4h]
  int v30; // [esp+2Ch] [ebp+Ch]

  v2 = a1;
  v29 = a1[84];
  v3 = (_DWORD *)a1[6];
  v4 = (_DWORD *)a1[93];
  v4[4] = *v3;
  v5 = v3[1];
  v6 = a1[50];
  v7 = a1[82];
  v25 = v7;
  v4[5] = v5;
  if ( v6 && !v4[17] )
    sub_6D56F0(v4, v4[18]);
  v26 = *a2;
  v8 = a1[81];
  v30 = 0;
  v27 = v8;
  if ( v8 <= v7 )
  {
    do
    {
      v9 = dword_744A70[v8];
      v10 = *(__int16 *)(v26 + 2 * v9);
      if ( *(_WORD *)(v26 + 2 * v9) )
      {
        if ( v10 >= 0 )
        {
          v11 = v10 >> v29;
          v28 = v11;
        }
        else
        {
          v11 = -v10 >> v29;
          v28 = ~v11;
        }
        if ( v11 )
        {
          if ( v4[14] )
            sub_6D5640((int)v4);
          if ( v30 > 15 )
          {
            v12 = ((unsigned int)(v30 - 16) >> 4) + 1;
            v30 += -16 * v12;
            do
            {
              v13 = v4[13];
              if ( v4[3] )
                ++*(_DWORD *)(v4[v13 + 23] + 960);
              else
                sub_6D5530((int)v4, *(_DWORD *)(v4[v13 + 19] + 960), *(char *)(v4[v13 + 19] + 1264));
              --v12;
            }
            while ( v12 );
          }
          v14 = v11 >> 1;
          v15 = 1;
          if ( v14 )
          {
            do
            {
              v14 >>= 1;
              ++v15;
            }
            while ( v14 );
            if ( v15 > 10 )
            {
              v16 = *a1;
              *(_DWORD *)(v16 + 20) = 6;
              (*(void (__stdcall **)(_DWORD *))v16)(a1);
            }
          }
          v17 = v4[13];
          v18 = v15 + 16 * v30;
          if ( v4[3] )
          {
            v19 = (_DWORD *)(v4[v17 + 23] + 4 * v18);
            ++*v19;
          }
          else
          {
            sub_6D5530((int)v4, *(_DWORD *)(v4[v17 + 19] + 4 * v18), *(char *)(v4[v17 + 19] + v18 + 1024));
          }
          sub_6D5530((int)v4, v28, v15);
          v2 = a1;
          v8 = v27;
          v30 = 0;
        }
        else
        {
          ++v30;
        }
      }
      else
      {
        ++v30;
      }
      v27 = ++v8;
    }
    while ( v8 <= v25 );
    if ( v30 > 0 )
    {
      v20 = v4[14] + 1;
      v4[14] = v20;
      if ( v20 == 0x7FFF )
        sub_6D5640((int)v4);
    }
  }
  v21 = (_DWORD *)v2[6];
  v22 = v2[50];
  *v21 = v4[4];
  v21[1] = v4[5];
  if ( v22 )
  {
    if ( !v4[17] )
    {
      v23 = ((unsigned __int8)v4[18] + 1) & 7;
      v4[17] = v22;
      v4[18] = v23;
    }
    --v4[17];
  }
  return 1;
}
