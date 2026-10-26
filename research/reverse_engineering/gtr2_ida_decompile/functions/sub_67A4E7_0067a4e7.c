void __stdcall sub_67A4E7(int a1, int a2, signed int Size, int a4, double *a5)
{
  int v5; // eax
  signed int v6; // ebx
  signed int i; // eax
  signed int j; // eax
  signed int k; // edi
  int v10; // edi
  int m; // eax
  double *v12; // ebx

  v5 = a2;
  if ( a2 < 3 )
  {
    if ( !a2 )
      v5 = 1;
    v6 = Size;
    if ( Size < 0 || !a4 || v5 == 1 )
      v6 = 0;
    *(_BYTE *)(a1 + 385) = v6;
    *(_BYTE *)(a1 + 384) = v5;
    if ( v6 > 0 )
    {
      if ( !*(_DWORD *)(a1 + 388) )
      {
        *(_DWORD *)(a1 + 388) = sub_6B7269(a1, v6);
        for ( i = 0; i < v6; ++i )
          *(_BYTE *)(i + *(_DWORD *)(a1 + 388)) = -1;
      }
      if ( !*(_DWORD *)(a1 + 392) )
      {
        *(_DWORD *)(a1 + 392) = sub_6B7269(a1, 2 * v6);
        *(_DWORD *)(a1 + 396) = sub_6B7269(a1, 2 * v6);
        for ( j = 0; j < v6; ++j )
        {
          *(_WORD *)(*(_DWORD *)(a1 + 392) + 2 * j) = 256;
          *(_WORD *)(*(_DWORD *)(a1 + 396) + 2 * j) = 256;
        }
      }
      for ( k = 0; k < v6; ++k )
      {
        if ( *(double *)(a4 + 8 * k) >= 0.0 )
        {
          *(_WORD *)(*(_DWORD *)(a1 + 396) + 2 * k) = (__int64)(*(double *)(a4 + 8 * k) * 256.0 + 0.5);
          *(_WORD *)(*(_DWORD *)(a1 + 392) + 2 * k) = (__int64)(256.0 / *(double *)(a4 + 8 * k) + 0.5);
        }
        else
        {
          *(_WORD *)(*(_DWORD *)(a1 + 392) + 2 * k) = 256;
          *(_WORD *)(*(_DWORD *)(a1 + 396) + 2 * k) = 256;
        }
      }
    }
    v10 = 0;
    if ( !*(_DWORD *)(a1 + 400) )
    {
      *(_DWORD *)(a1 + 400) = sub_6B7269(a1, 0xAu);
      *(_DWORD *)(a1 + 404) = sub_6B7269(a1, 0xAu);
      for ( m = 0; m < 10; m += 2 )
      {
        *(_WORD *)(m + *(_DWORD *)(a1 + 400)) = 8;
        *(_WORD *)(m + *(_DWORD *)(a1 + 404)) = 8;
      }
    }
    v12 = a5;
    do
    {
      if ( a5 && *v12 >= 0.0 )
      {
        if ( *v12 >= 1.0 )
        {
          *(_WORD *)(v10 + *(_DWORD *)(a1 + 404)) = (__int64)(8.0 / *v12 + 0.5);
          *(_WORD *)(v10 + *(_DWORD *)(a1 + 400)) = (__int64)(*v12 * 8.0 + 0.5);
        }
      }
      else
      {
        *(_WORD *)(v10 + *(_DWORD *)(a1 + 400)) = 8;
        *(_WORD *)(v10 + *(_DWORD *)(a1 + 404)) = 8;
      }
      ++v12;
      v10 += 2;
    }
    while ( v10 < 10 );
  }
  else
  {
    sub_679F26(a1, (int)"Unknown filter heuristic method");
  }
}
