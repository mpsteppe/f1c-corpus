int __stdcall sub_6D1150(int a1, int a2, char **a3, int *a4)
{
  int v4; // edx
  int v5; // eax
  int v6; // edi
  int result; // eax
  int v8; // ebx
  char *v9; // ecx
  char *v10; // esi
  char v11; // al
  int v12; // eax
  int v13; // eax
  char *v14; // [esp+8h] [ebp-10h]
  int v15; // [esp+Ch] [ebp-Ch]
  int i; // [esp+10h] [ebp-8h]
  int v17; // [esp+14h] [ebp-4h]
  int v18; // [esp+24h] [ebp+Ch]

  v4 = a1;
  v17 = *a4;
  v5 = *(_DWORD *)(a2 + 4) + *(_DWORD *)(a1 + 456);
  v6 = *(unsigned __int8 *)(v5 + 140);
  v18 = *(unsigned __int8 *)(v5 + 150);
  result = *(_DWORD *)(a1 + 316);
  v8 = 0;
  v15 = v6;
  for ( i = 0; v8 < result; i = v8 )
  {
    v9 = *a3;
    v10 = *(char **)(v17 + 4 * v8);
    v14 = &v10[*(_DWORD *)(v4 + 112)];
    while ( v10 < v14 )
    {
      v11 = *v9++;
      if ( v6 > 0 )
      {
        LOBYTE(v8) = v11;
        BYTE1(v8) = v11;
        v12 = v8 << 16;
        LOWORD(v12) = v8;
        v8 = i;
        memset32(v10, v12, (unsigned int)v6 >> 2);
        v4 = a1;
        memset(&v10[4 * ((unsigned int)v6 >> 2)], v12, v6 & 3);
        v6 = v15;
        v10 += v15;
      }
    }
    v13 = v18;
    if ( v18 > 1 )
    {
      sub_6B5FF0(v17, v8, v17, v8 + 1, v18 - 1, *(_DWORD *)(v4 + 112));
      v13 = v18;
      v4 = a1;
    }
    v8 += v13;
    result = *(_DWORD *)(v4 + 316);
    ++a3;
  }
  return result;
}
