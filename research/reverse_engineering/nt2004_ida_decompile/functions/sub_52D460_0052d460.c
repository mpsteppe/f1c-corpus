int __stdcall sub_52D460(int a1)
{
  int v1; // esi
  int v2; // eax
  int v3; // ecx
  int v4; // eax
  int v5; // ecx
  int v6; // edi
  int v7; // eax
  int v8; // ecx
  int v9; // edx
  int v10; // edi
  int v11; // eax

  v1 = a1;
  v2 = 0;
  v3 = a1;
  if ( !a1 )
    return v1;
  do
  {
    v3 = *(_DWORD *)(v3 + 4);
    ++v2;
  }
  while ( v3 );
  if ( v2 < 2 )
    return v1;
  v4 = v2 / 2 - 1;
  v5 = a1;
  if ( v4 > 0 )
  {
    do
    {
      --v4;
      v5 = *(_DWORD *)(v5 + 4);
    }
    while ( v4 );
  }
  v6 = *(_DWORD *)(v5 + 4);
  *(_DWORD *)(v5 + 4) = 0;
  v1 = sub_52D460(a1);
  v7 = sub_52D460(v6);
  v8 = v7;
  v9 = v1;
  if ( !v1 )
    return v7;
  if ( !v7 )
    return v1;
  if ( **(float **)v1 >= (double)**(float **)v7 )
  {
    v1 = v7;
    v10 = v7;
    v8 = *(_DWORD *)(v7 + 4);
  }
  else
  {
    v9 = *(_DWORD *)(v1 + 4);
    v10 = v1;
  }
  if ( v9 )
  {
    while ( v8 )
    {
      if ( **(float **)v9 >= (double)**(float **)v8 )
      {
        v11 = v8;
        v8 = *(_DWORD *)(v8 + 4);
      }
      else
      {
        v11 = v9;
        v9 = *(_DWORD *)(v9 + 4);
      }
      *(_DWORD *)(v10 + 4) = v11;
      v10 = v11;
      if ( !v9 )
        goto LABEL_17;
    }
    *(_DWORD *)(v10 + 4) = v9;
    return v1;
  }
  else
  {
LABEL_17:
    if ( v8 )
      *(_DWORD *)(v10 + 4) = v8;
    else
      *(_DWORD *)(v10 + 4) = 0;
    return v1;
  }
}
