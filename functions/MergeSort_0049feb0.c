_DWORD *__stdcall sub_49FEB0(_DWORD *a1)
{
  _DWORD *v1; // esi
  int v2; // eax
  _DWORD *v3; // ecx
  int v4; // eax
  _DWORD *v5; // ecx
  int v6; // edi
  _DWORD *v7; // eax
  _DWORD *v8; // ecx
  _DWORD *v9; // edx
  _DWORD *v10; // edi
  _DWORD *v11; // eax

  v1 = a1;
  v2 = 0;
  v3 = a1;
  if ( !a1 )
    return v1;
  do
  {
    v3 = (_DWORD *)v3[1];
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
      v5 = (_DWORD *)v5[1];
    }
    while ( v4 );
  }
  v6 = v5[1];
  v5[1] = 0;
  v1 = (_DWORD *)MergeSort(a1);
  v7 = (_DWORD *)MergeSort(v6);
  v8 = v7;
  v9 = v1;
  if ( !v1 )
    return v7;
  if ( !v7 )
    return v1;
  if ( *(float *)(*v1 + 4) >= (double)*(float *)(*v7 + 4) )
  {
    v1 = v7;
    v10 = v7;
    v8 = (_DWORD *)v7[1];
  }
  else
  {
    v9 = (_DWORD *)v1[1];
    v10 = v1;
  }
  if ( v9 )
  {
    while ( v8 )
    {
      if ( *(float *)(*v9 + 4) >= (double)*(float *)(*v8 + 4) )
      {
        v11 = v8;
        v8 = (_DWORD *)v8[1];
      }
      else
      {
        v11 = v9;
        v9 = (_DWORD *)v9[1];
      }
      v10[1] = v11;
      v10 = v11;
      if ( !v9 )
        goto LABEL_17;
    }
    v10[1] = v9;
    return v1;
  }
  else
  {
LABEL_17:
    if ( v8 )
      v10[1] = v8;
    else
      v10[1] = 0;
    return v1;
  }
}
