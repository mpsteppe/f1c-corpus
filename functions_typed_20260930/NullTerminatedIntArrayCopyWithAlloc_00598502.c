_DWORD *__cdecl sub_598502(int *a1)
{
  int v1; // ecx
  int *v3; // eax
  int v4; // edx
  _DWORD *v5; // esi
  _DWORD *v6; // ebp
  int v7; // eax
  int *v8; // ebx

  v1 = 0;
  if ( !a1 )
    return 0;
  v3 = a1 + 1;
  if ( *a1 )
  {
    do
    {
      v4 = *v3;
      ++v1;
      ++v3;
    }
    while ( v4 );
  }
  v5 = (_DWORD *)MallocWrapperForNhMalloc(4 * v1 + 4);
  v6 = v5;
  if ( !v5 )
    CRTAmsgExit(9u);
  v7 = *a1;
  v8 = a1;
  while ( v7 )
  {
    ++v8;
    *v5 = StringAllocCopy(v7);
    v7 = *v8;
    ++v5;
  }
  *v5 = 0;
  return v6;
}

