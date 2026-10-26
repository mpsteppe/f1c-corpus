int __cdecl sub_51E1EF(_DWORD *a1, char *a2)
{
  _DWORD *v2; // esi
  signed int v3; // ebx
  int v4; // edi
  int v5; // eax
  int v6; // ecx
  int v7; // edi
  signed int v8; // edx
  int v9; // eax
  int *v10; // ecx
  int v11; // edi
  int v12; // eax
  int v14; // [esp+Ch] [ebp-10h]
  int v15; // [esp+10h] [ebp-Ch]
  signed int v16; // [esp+14h] [ebp-8h]
  char v17; // [esp+1Bh] [ebp-1h]

  v2 = a1;
  v3 = a1[25];
  v14 = a1[21];
  v4 = 1;
  do
  {
    v5 = ++v4;
    if ( v3 > 1 )
    {
      v6 = v3 - 1;
      do
      {
        v5 *= v4;
        --v6;
      }
      while ( v6 );
    }
  }
  while ( v5 <= a1[21] );
  v7 = v4 - 1;
  if ( v7 < 2 )
  {
    *(_DWORD *)(*a1 + 20) = 55;
    *(_DWORD *)(*a1 + 24) = v5;
    (*(void (__cdecl **)(_DWORD *))*a1)(a1);
  }
  v15 = 1;
  if ( v3 > 0 )
  {
    v8 = v3;
    memset32(a2, v7, v3);
    do
    {
      --v8;
      v15 *= v7;
    }
    while ( v8 );
  }
  while ( 1 )
  {
    v17 = 0;
    v16 = 0;
    if ( v3 <= 0 )
      break;
    while ( 1 )
    {
      v9 = v16;
      if ( v2[10] == 2 )
        v9 = dword_5B06C8[v16];
      v10 = (int *)&a2[4 * v9];
      v11 = *v10 + 1;
      v12 = v11 * (v15 / *v10);
      if ( v12 > v14 )
        break;
      ++v16;
      *v10 = v11;
      v15 = v12;
      v17 = 1;
      if ( v16 >= v3 )
        break;
      v2 = a1;
    }
    if ( !v17 )
      break;
    v2 = a1;
  }
  return v15;
}

