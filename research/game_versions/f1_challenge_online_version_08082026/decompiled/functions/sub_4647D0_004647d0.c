int *__stdcall sub_4647D0(int a1)
{
  int v1; // eax
  int v2; // ecx
  int *result; // eax
  int v4; // eax
  int v5; // ecx
  int v6; // edi
  int *v7; // esi
  int v8; // edx
  int *v9; // ecx
  int v10; // edi
  int **v11; // ebx
  int v12; // edx
  int *v13; // ecx
  int v14; // edi
  int *v15; // ecx
  int **v16; // [esp+Ch] [ebp+4h]

  v1 = 0;
  v2 = a1;
  if ( !a1 )
    return (int *)a1;
  do
  {
    v2 = *(_DWORD *)(v2 + 4);
    ++v1;
  }
  while ( v2 );
  if ( v1 < 2 )
    return (int *)a1;
  v4 = v1 / 2 - 1;
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
  v7 = (int *)sub_4647D0(a1);
  result = (int *)sub_4647D0(v6);
  if ( !v7 )
    return result;
  if ( !result )
    return v7;
  v8 = *(_DWORD *)(*v7 + 8);
  v9 = (int *)*result;
  if ( v8 == -1 )
  {
    if ( v9[2] != -1 )
      goto LABEL_17;
    v8 = *(_DWORD *)*v7;
    v10 = *v9;
LABEL_15:
    if ( v8 < v10 )
      goto LABEL_16;
LABEL_17:
    v16 = (int **)result;
    v11 = (int **)result;
    result = (int *)result[1];
    goto LABEL_18;
  }
  if ( v9[2] != -1 )
  {
    v10 = v9[2];
    goto LABEL_15;
  }
LABEL_16:
  v16 = (int **)v7;
  v11 = (int **)v7;
  v7 = (int *)v7[1];
LABEL_18:
  while ( v7 )
  {
    if ( !result )
    {
      result = (int *)v16;
      v11[1] = v7;
      return result;
    }
    v12 = *(_DWORD *)(*v7 + 8);
    v13 = (int *)*result;
    if ( v12 == -1 )
    {
      if ( v13[2] != -1 )
        goto LABEL_28;
      v12 = *(_DWORD *)*v7;
      v14 = *v13;
    }
    else
    {
      if ( v13[2] == -1 )
        goto LABEL_27;
      v14 = v13[2];
    }
    if ( v12 >= v14 )
    {
LABEL_28:
      v15 = result;
      result = (int *)result[1];
      goto LABEL_29;
    }
LABEL_27:
    v15 = v7;
    v7 = (int *)v7[1];
LABEL_29:
    v11[1] = v15;
    v11 = (int **)v15;
  }
  if ( result )
  {
    v11[1] = result;
    return (int *)v16;
  }
  else
  {
    result = (int *)v16;
    v11[1] = 0;
  }
  return result;
}
