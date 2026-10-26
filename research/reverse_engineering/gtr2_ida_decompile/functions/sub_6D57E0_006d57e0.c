int __stdcall sub_6D57E0(int *a1, int a2)
{
  _DWORD *v3; // eax
  _DWORD *v4; // esi
  int v5; // edx
  int v6; // eax
  int v7; // edi
  int v8; // eax
  int v9; // edi
  int v10; // eax
  int v11; // eax
  bool v12; // cc
  _DWORD *v13; // eax
  int v14; // ebx
  int v15; // eax
  int v17; // [esp+Ch] [ebp-10h]
  char v18; // [esp+10h] [ebp-Ch]
  _DWORD *v19; // [esp+14h] [ebp-8h]
  int v20; // [esp+18h] [ebp-4h]
  int v21; // [esp+24h] [ebp+8h]

  v3 = (_DWORD *)a1[6];
  v4 = (_DWORD *)a1[93];
  v4[4] = *v3;
  v5 = v3[1];
  v6 = a1[50];
  v7 = a1[84];
  v4[5] = v5;
  if ( v6 && !v4[17] )
    sub_6D56F0(v4, v4[18]);
  v20 = 0;
  if ( a1[70] > 0 )
  {
    v18 = v7;
    v19 = a1 + 71;
    do
    {
      v17 = a1[*v19 + 64];
      v8 = (**(__int16 **)(a2 + 4 * v20) >> v18) - v4[*v19 + 9];
      v4[*v19 + 9] = **(__int16 **)(a2 + 4 * v20) >> v18;
      v21 = v8;
      if ( v8 < 0 )
      {
        v8 = -v8;
        --v21;
      }
      v9 = 0;
      if ( v8 )
      {
        do
        {
          v8 >>= 1;
          ++v9;
        }
        while ( v8 );
        if ( v9 > 11 )
        {
          v10 = *a1;
          *(_DWORD *)(v10 + 20) = 6;
          (*(void (__stdcall **)(int *))v10)(a1);
        }
      }
      v11 = *(_DWORD *)(v17 + 20);
      if ( v4[3] )
        ++*(_DWORD *)(v4[v11 + 23] + 4 * v9);
      else
        sub_6D5530((int)v4, *(_DWORD *)(v4[v11 + 19] + 4 * v9), *(char *)(v4[v11 + 19] + v9 + 1024));
      if ( v9 )
        sub_6D5530((int)v4, v21, v9);
      v12 = ++v20 < a1[70];
      ++v19;
    }
    while ( v12 );
  }
  v13 = (_DWORD *)a1[6];
  v14 = a1[50];
  *v13 = v4[4];
  v13[1] = v4[5];
  if ( v14 )
  {
    if ( !v4[17] )
    {
      v15 = ((unsigned __int8)v4[18] + 1) & 7;
      v4[17] = v14;
      v4[18] = v15;
    }
    --v4[17];
  }
  return 1;
}
