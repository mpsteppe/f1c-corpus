int __stdcall sub_6789F0(int *a1)
{
  int *v1; // ecx
  unsigned __int8 **v2; // ebx
  unsigned __int8 *v3; // esi
  unsigned __int8 *v4; // edi
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v9; // edx
  int v10; // eax
  int v11; // [esp+Ch] [ebp-4h]

  v1 = a1;
  v2 = (unsigned __int8 **)a1[6];
  v3 = v2[1];
  v4 = *v2;
  while ( 1 )
  {
    if ( !v3 )
    {
      if ( !((int (__stdcall *)(int *))v2[3])(v1) )
        return 0;
      v4 = *v2;
      v3 = v2[1];
      v1 = a1;
    }
    v5 = *v4;
    --v3;
    ++v4;
    if ( v5 == 255 )
      goto LABEL_10;
    do
    {
      ++*(_DWORD *)(v1[111] + 24);
      *v2 = v4;
      v2[1] = v3;
      if ( !v3 )
      {
        if ( !((int (__stdcall *)(int *))v2[3])(v1) )
          return 0;
        v4 = *v2;
        v3 = v2[1];
        v1 = a1;
      }
      v6 = *v4;
      --v3;
      ++v4;
    }
    while ( v6 != 255 );
    do
    {
LABEL_10:
      if ( !v3 )
      {
        if ( !((int (__stdcall *)(int *))v2[3])(v1) )
          return 0;
        v4 = *v2;
        v3 = v2[1];
        v1 = a1;
      }
      v7 = *v4;
      --v3;
      ++v4;
      v11 = v7;
    }
    while ( v7 == 255 );
    if ( v7 )
      break;
    *(_DWORD *)(v1[111] + 24) += 2;
    *v2 = v4;
    v2[1] = v3;
  }
  v9 = *(_DWORD *)(v1[111] + 24);
  if ( v9 )
  {
    v10 = *v1;
    *(_DWORD *)(v10 + 20) = 116;
    *(_DWORD *)(v10 + 24) = v9;
    *(_DWORD *)(v10 + 28) = v11;
    (*(void (__stdcall **)(int *, int))(v10 + 4))(v1, -1);
    v7 = v11;
    *(_DWORD *)(a1[111] + 24) = 0;
    v1 = a1;
  }
  *v2 = v4;
  v2[1] = v3;
  v1[105] = v7;
  return 1;
}
