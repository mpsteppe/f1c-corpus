int __stdcall sub_6D5C00(_DWORD *a1, int *a2)
{
  _DWORD *v2; // edx
  int v3; // ecx
  int *v4; // eax
  int v5; // ecx
  _DWORD *v6; // esi
  int v7; // eax
  int v8; // ebx
  int v9; // edi
  int v10; // eax
  int v11; // eax
  char *v12; // edi
  int v13; // eax
  int v14; // ebx
  int v15; // ecx
  int v16; // eax
  int v17; // eax
  int v18; // ebx
  int j; // ebx
  int v20; // eax
  unsigned int v21; // ebx
  _DWORD *v22; // eax
  int v23; // edx
  _DWORD v25[64]; // [esp+4h] [ebp-114h]
  int v26; // [esp+104h] [ebp-14h]
  int i; // [esp+108h] [ebp-10h]
  int v28; // [esp+10Ch] [ebp-Ch]
  int v29; // [esp+110h] [ebp-8h]
  int v30; // [esp+114h] [ebp-4h]
  int v31; // [esp+124h] [ebp+Ch]

  v2 = a1;
  v3 = a1[84];
  v29 = a1[82];
  v4 = (int *)a1[6];
  v28 = v3;
  v5 = *v4;
  v6 = (_DWORD *)a1[93];
  v6[5] = v4[1];
  v7 = a1[50];
  v6[4] = v5;
  if ( v7 && !v6[17] )
  {
    sub_6D56F0(v6, v6[18]);
    v2 = a1;
  }
  v8 = *a2;
  v9 = v2[81];
  v26 = *a2;
  for ( i = 0; v9 <= v29; ++v9 )
  {
    v10 = *(__int16 *)(v8 + 2 * dword_744A70[v9]);
    if ( v10 < 0 )
      v10 = -v10;
    v11 = v10 >> v28;
    v25[v9] = v11;
    if ( v11 == 1 )
      i = v9;
  }
  v12 = (char *)(v6[15] + v6[16]);
  v14 = 0;
  v31 = 0;
  v30 = v2[81];
  v13 = v30;
  if ( v30 <= v29 )
  {
    do
    {
      v28 = v25[v13];
      v15 = v28;
      if ( v28 )
      {
        for ( ; v14 > 15; v31 = 0 )
        {
          if ( v13 > i )
            break;
          sub_6D5640((int)v6);
          v16 = v6[13];
          if ( v6[3] )
            ++*(_DWORD *)(v6[v16 + 23] + 960);
          else
            sub_6D5530((int)v6, *(_DWORD *)(v6[v16 + 19] + 960), *(char *)(v6[v16 + 19] + 1264));
          v14 -= 16;
          if ( !v6[3] && v31 )
          {
            do
            {
              sub_6D5530((int)v6, *v12++, 1);
              --v31;
            }
            while ( v31 );
          }
          v12 = (char *)v6[16];
          v13 = v30;
          v15 = v28;
        }
        if ( v15 <= 1 )
        {
          sub_6D5640((int)v6);
          v17 = v6[13];
          v18 = 16 * v14 + 1;
          if ( v6[3] )
            ++*(_DWORD *)(v6[v17 + 23] + 4 * v18);
          else
            sub_6D5530((int)v6, *(_DWORD *)(v6[v17 + 19] + 4 * v18), *(char *)(v6[v17 + 19] + v18 + 1024));
          sub_6D5530((int)v6, *(_WORD *)(v26 + 2 * dword_744A70[v30]) >= 0, 1);
          if ( !v6[3] )
          {
            for ( j = v31; j; --j )
              sub_6D5530((int)v6, *v12++, 1);
          }
          v12 = (char *)v6[16];
          v13 = v30;
          v14 = 0;
          v31 = 0;
        }
        else
        {
          v12[v31++] = v15 & 1;
        }
        v2 = a1;
      }
      else
      {
        ++v14;
      }
      v30 = ++v13;
    }
    while ( v13 <= v29 );
    if ( v14 > 0 || v31 )
    {
      v20 = v6[14] + 1;
      v21 = v31 + v6[15];
      v6[14] = v20;
      v6[15] = v21;
      if ( v20 == 0x7FFF || v21 > 0x3A9 )
      {
        sub_6D5640((int)v6);
        v2 = a1;
      }
    }
  }
  v22 = (_DWORD *)v2[6];
  v23 = v2[50];
  *v22 = v6[4];
  v22[1] = v6[5];
  if ( v23 )
  {
    if ( !v6[17] )
    {
      v6[17] = v23;
      v6[18] = ((unsigned __int8)v6[18] + 1) & 7;
    }
    --v6[17];
  }
  return 1;
}
