int __stdcall sub_6B5770(int *a1)
{
  _DWORD *v1; // edi
  _DWORD *v2; // eax
  int v3; // esi
  int v4; // ebx
  int v5; // ecx
  int result; // eax
  int v7; // ecx
  signed int v8; // ebx
  int *j; // esi
  int v10; // edi
  unsigned int v11; // ecx
  int *k; // esi
  int v13; // edi
  unsigned int v14; // ecx
  int v15; // eax
  int v16; // edx
  int v17; // [esp-4h] [ebp-14h]
  _DWORD *i; // [esp+Ch] [ebp-4h]

  v1 = (_DWORD *)a1[1];
  v2 = (_DWORD *)v1[17];
  v3 = 0;
  v4 = 0;
  for ( i = v1; v2; v2 = (_DWORD *)v2[11] )
  {
    if ( !*v2 )
    {
      v5 = v2[2];
      v3 += v5 * v2[3];
      v4 += v5 * v2[1];
    }
  }
  for ( result = v1[18]; result; result = *(_DWORD *)(result + 44) )
  {
    if ( !*(_DWORD *)result )
    {
      v7 = *(_DWORD *)(result + 8);
      v3 += (v7 * *(_DWORD *)(result + 12)) << 7;
      v4 += (v7 * *(_DWORD *)(result + 4)) << 7;
    }
  }
  if ( v3 > 0 )
  {
    result = sub_6D3B50(a1, v3, v4, v1[19]);
    if ( result < v4 )
    {
      result /= v3;
      v8 = result;
      if ( result <= 0 )
        v8 = 1;
    }
    else
    {
      v8 = 1000000000;
    }
    for ( j = (int *)v1[17]; j; j = (int *)j[11] )
    {
      if ( !*j )
      {
        v10 = j[1];
        v11 = j[3];
        if ( (int)((v10 - 1) / v11 + 1) > v8 )
        {
          v17 = v10 * j[2];
          j[4] = v8 * v11;
          sub_6D3C50(a1, j + 12, v17);
          j[10] = 1;
        }
        else
        {
          j[4] = v10;
        }
        *j = sub_6B5530(a1, 1u, j[2], j[4]);
        j[5] = i[20];
        result = 0;
        j[6] = 0;
        j[7] = 0;
        j[9] = 0;
        v1 = i;
      }
    }
    for ( k = (int *)v1[18]; k; k = (int *)k[11] )
    {
      if ( !*k )
      {
        v13 = k[1];
        v14 = k[3];
        if ( (int)((v13 - 1) / v14 + 1) > v8 )
        {
          k[4] = v8 * v14;
          sub_6D3C50(a1, k + 12, (v13 * k[2]) << 7);
          k[10] = 1;
        }
        else
        {
          k[4] = v13;
        }
        v15 = sub_6B55E0(a1, 1u, k[2], k[4]);
        v16 = i[20];
        *k = v15;
        result = 0;
        k[5] = v16;
        k[6] = 0;
        k[7] = 0;
        k[9] = 0;
      }
    }
  }
  return result;
}
