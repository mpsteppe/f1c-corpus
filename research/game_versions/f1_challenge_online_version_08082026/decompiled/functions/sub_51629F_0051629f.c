int __cdecl sub_51629F(_DWORD *a1)
{
  _DWORD *v1; // edi
  _DWORD *v2; // eax
  int v3; // esi
  int v4; // ebx
  int v5; // ecx
  int result; // eax
  int v7; // ecx
  int i; // esi
  int v9; // ebx
  unsigned int v10; // ecx
  int j; // esi
  int v12; // ebx
  unsigned int v13; // ecx
  signed int v14; // [esp+Ch] [ebp-4h]

  v1 = (_DWORD *)a1[1];
  v2 = (_DWORD *)v1[16];
  v3 = 0;
  v4 = 0;
  while ( v2 )
  {
    if ( !*v2 )
    {
      v5 = v2[2];
      v3 += v5 * v2[3];
      v4 += v5 * v2[1];
    }
    v2 = (_DWORD *)v2[9];
  }
  for ( result = v1[17]; result; result = *(_DWORD *)(result + 36) )
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
    result = sub_51935C(a1, v3, v4);
    if ( result < v4 )
    {
      result /= v3;
      v14 = result;
      if ( result <= 0 )
        v14 = 1;
    }
    else
    {
      v14 = 1000000000;
    }
    for ( i = v1[16]; i; i = *(_DWORD *)(i + 36) )
    {
      if ( !*(_DWORD *)i )
      {
        v9 = *(_DWORD *)(i + 4);
        v10 = *(_DWORD *)(i + 12);
        if ( (int)((v9 - 1) / v10 + 1) > v14 )
        {
          *(_DWORD *)(i + 16) = v14 * v10;
          sub_519361(a1);
          *(_BYTE *)(i + 34) = 1;
        }
        else
        {
          *(_DWORD *)(i + 16) = v9;
        }
        *(_DWORD *)i = sub_5160AD(a1, 1u, *(_DWORD *)(i + 8), *(_DWORD *)(i + 16));
        result = v1[19];
        *(_DWORD *)(i + 24) = 0;
        *(_DWORD *)(i + 28) = 0;
        *(_BYTE *)(i + 33) = 0;
        *(_DWORD *)(i + 20) = result;
      }
    }
    for ( j = v1[17]; j; j = *(_DWORD *)(j + 36) )
    {
      if ( !*(_DWORD *)j )
      {
        v12 = *(_DWORD *)(j + 4);
        v13 = *(_DWORD *)(j + 12);
        if ( (int)((v12 - 1) / v13 + 1) > v14 )
        {
          *(_DWORD *)(j + 16) = v14 * v13;
          sub_519361(a1);
          *(_BYTE *)(j + 34) = 1;
        }
        else
        {
          *(_DWORD *)(j + 16) = v12;
        }
        *(_DWORD *)j = sub_51613F(a1, 1u, *(_DWORD *)(j + 8), *(_DWORD *)(j + 16));
        result = v1[19];
        *(_DWORD *)(j + 24) = 0;
        *(_DWORD *)(j + 28) = 0;
        *(_BYTE *)(j + 33) = 0;
        *(_DWORD *)(j + 20) = result;
      }
    }
  }
  return result;
}
