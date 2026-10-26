int __stdcall sub_6B7040(int *a1)
{
  int v1; // edi
  _DWORD *v2; // ebx
  int v3; // edi
  _DWORD *v4; // ebx
  int v5; // eax
  _BYTE *v6; // ecx
  bool v7; // zf
  int v8; // eax
  int result; // eax
  _BYTE *v10; // ecx
  int v11; // eax

  sub_6B60A0(a1, 216);
  v1 = 0;
  v2 = a1 + 18;
  do
  {
    if ( *v2 )
      sub_6B6100(a1, v1);
    ++v1;
    ++v2;
  }
  while ( v1 < 4 );
  if ( !a1[45] )
  {
    v3 = 0;
    v4 = a1 + 26;
    do
    {
      if ( *(v4 - 4) )
        sub_6B62D0(0, a1, v3);
      if ( *v4 )
        sub_6B62D0(1, a1, v3);
      ++v3;
      ++v4;
    }
    while ( v3 < 4 );
  }
  v5 = a1[6];
  v6 = *(_BYTE **)v5;
  *v6 = -1;
  *(_DWORD *)v5 = v6 + 1;
  v7 = (*(_DWORD *)(v5 + 4))-- == 1;
  if ( v7 && !(*(int (__stdcall **)(int *))(v5 + 12))(a1) )
  {
    v8 = *a1;
    *(_DWORD *)(v8 + 20) = 24;
    (*(void (__stdcall **)(int *))v8)(a1);
  }
  result = a1[6];
  v10 = *(_BYTE **)result;
  *v10 = -39;
  *(_DWORD *)result = v10 + 1;
  v7 = (*(_DWORD *)(result + 4))-- == 1;
  if ( v7 )
  {
    result = (*(int (__stdcall **)(int *))(result + 12))(a1);
    if ( !result )
    {
      v11 = *a1;
      *(_DWORD *)(v11 + 20) = 24;
      return (*(int (__stdcall **)(int *))v11)(a1);
    }
  }
  return result;
}
