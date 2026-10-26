int __stdcall sub_6B6E50(int *a1)
{
  int v1; // edi
  int *v2; // ebx
  int v3; // eax
  int v4; // ecx
  int v5; // edi
  int *v6; // eax
  int v7; // eax
  char v9; // al
  int v10; // [esp+Ch] [ebp-4h]

  v1 = 0;
  v10 = 0;
  if ( a1[15] > 0 )
  {
    v2 = (int *)(a1[17] + 16);
    do
    {
      v3 = sub_6B6100(a1, *v2);
      ++v1;
      v2 += 21;
      v10 += v3;
    }
    while ( v1 < a1[15] );
  }
  if ( a1[45] || a1[59] || a1[14] != 8 )
  {
    v5 = 0;
  }
  else
  {
    v4 = a1[15];
    v5 = 1;
    if ( v4 > 0 )
    {
      v6 = (int *)(a1[17] + 24);
      do
      {
        if ( *(v6 - 1) > 1 || *v6 > 1 )
          v5 = 0;
        v6 += 21;
        --v4;
      }
      while ( v4 );
    }
    if ( v10 && v5 )
    {
      v7 = *a1;
      v5 = 0;
      *(_DWORD *)(v7 + 20) = 75;
      (*(void (__stdcall **)(int *, _DWORD))(v7 + 4))(a1, 0);
    }
  }
  if ( a1[45] )
    return sub_6B6510(201, (int)a1);
  if ( a1[59] )
    return sub_6B6510(194, (int)a1);
  v9 = -64;
  if ( !v5 )
    v9 = -63;
  return sub_6B6510(v9, (int)a1);
}
