int __stdcall sub_694D2B(int a1, int a2)
{
  int *v2; // esi
  int v3; // edi
  int v4; // eax
  _DWORD *v5; // eax
  _DWORD *v6; // eax
  _DWORD *v7; // eax
  unsigned int v8; // ebx
  _DWORD *v9; // eax
  int *v11; // edx
  int v12; // eax
  int v13; // ecx
  int v14; // edi
  int *v15; // edx
  int v16; // ecx
  int v17; // eax
  int v18; // edi
  int v19; // [esp+14h] [ebp+8h]
  unsigned int v20; // [esp+18h] [ebp+Ch]

  v2 = (int *)(a1 + 28);
  v3 = *(_DWORD *)(a2 + 20) + 16;
  if ( !*(_DWORD *)(a1 + 28) )
    goto LABEL_33;
  do
  {
    v19 = *v2;
    v4 = strcmp(*(const char **)(*(_DWORD *)(a2 + 20) + 24), *(const char **)(*v2 + 16));
    if ( v4 >= 0 )
    {
      if ( v4 <= 0 )
        break;
      v2 = (int *)(v19 + 12);
    }
    else
    {
      v2 = (int *)(v19 + 8);
    }
  }
  while ( *v2 );
  if ( !*v2 )
  {
LABEL_33:
    v5 = (_DWORD *)sub_65B229(24);
    v6 = v5 ? sub_67EDBE(v5, *(_DWORD *)(v3 + 8), 0, 0, 0) : 0;
    *v2 = (int)v6;
    if ( !v6 )
      return -2147024882;
  }
  v7 = (_DWORD *)sub_65B229(20);
  v8 = 0;
  v9 = v7 ? sub_67ED1B(v7, a2, *(_DWORD *)(*v2 + 20), (int)"Stmts") : 0;
  *(_DWORD *)(*v2 + 20) = v9;
  if ( !v9 )
    return -2147024882;
  if ( !*(_DWORD *)(*(_DWORD *)(*v2 + 20) + 12) )
  {
    v11 = v2;
    if ( *v2 )
    {
      do
      {
        while ( 1 )
        {
          v12 = *v11;
          if ( !*v11 )
            break;
          v13 = *(_DWORD *)(v12 + 8);
          if ( !v13 )
            break;
          v14 = *(_DWORD *)(v13 + 12);
          *(_DWORD *)(v13 + 12) = v12;
          *(_DWORD *)(v12 + 8) = v14;
          *v11 = v13;
        }
        v11 = (int *)(v12 + 12);
        ++v8;
      }
      while ( *(_DWORD *)(v12 + 12) );
    }
    while ( 1 )
    {
      v8 >>= 1;
      if ( !v8 )
        break;
      v15 = v2;
      v20 = v8;
      do
      {
        v16 = *v15;
        if ( *v15 )
        {
          v17 = *(_DWORD *)(v16 + 12);
          if ( v17 )
          {
            v18 = *(_DWORD *)(v17 + 8);
            *(_DWORD *)(v17 + 8) = v16;
            *(_DWORD *)(v16 + 12) = v18;
            *v15 = v17;
          }
        }
        v15 = (int *)(*v15 + 12);
        --v20;
      }
      while ( v20 );
    }
  }
  return 0;
}
