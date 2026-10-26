int __fastcall sub_5677B0(int a1, int a2)
{
  int v2; // ebp
  int v3; // esi
  int v4; // edi
  int v5; // ebx
  bool v6; // zf
  int v7; // ebx
  _DWORD *v8; // eax
  int v9; // edi
  int v10; // ebx
  double v11; // st7
  int v12; // edi
  int v13; // eax
  double v14; // st7
  int j; // ecx
  int v16; // edi
  int v17; // ebp
  double *v18; // ebx
  int v19; // ebp
  int v20; // edi
  double i; // [esp+18h] [ebp-8h]
  double v24; // [esp+18h] [ebp-8h]

  v2 = a1;
  v3 = 0;
  if ( a2 <= 0 )
    return 0;
  while ( 1 )
  {
    v4 = *(_DWORD *)(v2 + 4 * v3);
    if ( *(double *)(v4 + 8 * v3) == 0.0 )
      break;
LABEL_11:
    v12 = *(_DWORD *)(v2 + 4 * v3);
    if ( *(_DWORD *)(v12 + 8 * v3) || *(_DWORD *)(v12 + 8 * v3 + 4) != 1072693248 )
    {
      v13 = v3 + 1;
      for ( i = 1.0 / *(double *)(v12 + 8 * v3); v13 <= a2; *(double *)(v12 + 8 * v13 - 8) = v14 )
        v14 = i * *(double *)(v12 + 8 * v13++);
    }
    for ( j = 0; j < a2; ++j )
    {
      if ( v3 != j )
      {
        v16 = *(_DWORD *)(v2 + 4 * j);
        if ( *(double *)(v16 + 8 * v3) != 0.0 )
        {
          v17 = *(_DWORD *)(v2 + 4 * v3);
          v24 = -*(double *)(v16 + 8 * v3);
          if ( v3 + 1 <= a2 )
          {
            v18 = (double *)(v16 + 8 * (v3 + 1));
            v19 = v17 - v16;
            v20 = a2 - v3;
            do
            {
              if ( *(double *)((char *)v18 + v19) != 0.0 )
                *v18 = v24 * *(double *)((char *)v18 + v19) + *v18;
              ++v18;
              --v20;
            }
            while ( v20 );
          }
          v2 = a1;
        }
      }
    }
    if ( ++v3 >= a2 )
      return 0;
  }
  v5 = v3 + 1;
  v6 = v3 + 1 == a2;
  if ( v3 + 1 < a2 )
  {
    do
    {
      if ( *(double *)(*(_DWORD *)(v2 + 4 * v5) + 8 * v3) != 0.0 )
        break;
      ++v5;
    }
    while ( v5 < a2 );
    v6 = v5 == a2;
  }
  if ( !v6 )
  {
    v7 = *(_DWORD *)(v2 + 4 * v5);
    if ( v3 <= a2 )
    {
      v8 = (_DWORD *)(v7 + 8 * v3);
      v9 = v4 - v7;
      v10 = a2 - v3 + 1;
      do
      {
        v11 = *(double *)((char *)v8 + v9);
        *(_DWORD *)((char *)v8 + v9) = *v8;
        *(_DWORD *)((char *)v8 + v9 + 4) = v8[1];
        *(double *)v8 = v11;
        v8 += 2;
        --v10;
      }
      while ( v10 );
    }
    goto LABEL_11;
  }
  return -1;
}

