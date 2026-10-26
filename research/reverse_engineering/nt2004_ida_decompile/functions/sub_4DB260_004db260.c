int __stdcall sub_4DB260(int a1)
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
  float *v10; // ebx
  float *v11; // edi
  int v12; // ebp
  float *v13; // ebx
  float *v14; // edi
  int v15; // eax

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
  v1 = sub_4DB260(a1);
  v7 = sub_4DB260(v6);
  v8 = v7;
  v9 = v1;
  if ( !v1 )
    return v7;
  if ( !v7 )
    return v1;
  v10 = *(float **)v1;
  v11 = *(float **)v7;
  if ( **(float **)v1 < (double)**(float **)v7 || *v10 == *v11 && *((_DWORD *)v10 + 2) < *((_DWORD *)v11 + 2) )
  {
    v9 = *(_DWORD *)(v1 + 4);
    v12 = v1;
  }
  else
  {
    v1 = v7;
    v12 = v7;
    v8 = *(_DWORD *)(v7 + 4);
  }
  if ( v9 )
  {
    while ( v8 )
    {
      v13 = *(float **)v9;
      v14 = *(float **)v8;
      if ( **(float **)v9 < (double)**(float **)v8 || *v13 == *v14 && *((_DWORD *)v13 + 2) < *((_DWORD *)v14 + 2) )
      {
        v15 = v9;
        v9 = *(_DWORD *)(v9 + 4);
      }
      else
      {
        v15 = v8;
        v8 = *(_DWORD *)(v8 + 4);
      }
      *(_DWORD *)(v12 + 4) = v15;
      v12 = v15;
      if ( !v9 )
        goto LABEL_21;
    }
    *(_DWORD *)(v12 + 4) = v9;
    return v1;
  }
  else
  {
LABEL_21:
    if ( v8 )
      *(_DWORD *)(v12 + 4) = v8;
    else
      *(_DWORD *)(v12 + 4) = 0;
    return v1;
  }
}
