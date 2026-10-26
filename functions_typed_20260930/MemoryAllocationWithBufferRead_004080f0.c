BOOL __stdcall sub_4080F0(int a1)
{
  int v1; // eax
  unsigned int *v2; // edi
  int v3; // eax
  unsigned int v4; // ecx
  unsigned int v5; // eax
  int v6; // ebx

  v1 = *(_DWORD *)(a1 + 12);
  if ( !v1 )
    return 1;
  if ( *(_DWORD *)(a1 + 24) )
    return 1;
  sub_587F64(v1, 0, 0);
  v2 = (unsigned int *)(a1 + 20);
  if ( !ThreadSafeReadWrapper_803f(a1 + 20, 4, 1, *(_DWORD *)(a1 + 12)) )
    return 1;
  v3 = OperatorNewNhMallocWrapper(4 * *v2);
  v4 = *v2;
  *(_DWORD *)(a1 + 24) = v3;
  v5 = 0;
  if ( v4 )
  {
    do
      *(_DWORD *)(*(_DWORD *)(a1 + 24) + 4 * v5++) = 0;
    while ( v5 < *v2 );
  }
  v6 = 0;
  if ( *v2 )
  {
    while ( ThreadSafeReadWrapper_803f(*(_DWORD *)(a1 + 24) + 4 * v6, 4, 1, *(_DWORD *)(a1 + 12)) )
    {
      if ( ++v6 >= *v2 )
        return v6 != *v2;
    }
    pfnAPC(*(_DWORD *)(a1 + 12));
    FreeWrapper_7bcf(*(LPVOID *)(a1 + 24));
    *(_DWORD *)(a1 + 24) = 0;
  }
  return v6 != *v2;
}

