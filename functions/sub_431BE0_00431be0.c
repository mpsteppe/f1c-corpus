int sub_431BE0()
{
  int v0; // esi
  int v1; // edi
  _BYTE *v2; // ebx
  int v3; // edi
  _BYTE *v4; // ebx
  int result; // eax

  v0 = dword_7C73E0[0];
  if ( dword_7C73E0[0] )
  {
    v1 = *(_DWORD *)(dword_7C73E0[0] + 48);
    while ( v1 )
    {
      v2 = (_BYTE *)v1;
      v1 = *(_DWORD *)(v1 + 4);
      DoublePointerFree(v2);
      FreeWrapper_7bcf(v2);
    }
    *(_DWORD *)(v0 + 48) = 0;
    *(_DWORD *)(v0 + 52) = 0;
    *(_DWORD *)(v0 + 56) = 0;
    *(_DWORD *)(v0 + 60) = 0;
    v3 = *(_DWORD *)(v0 + 32);
    while ( v3 )
    {
      v4 = (_BYTE *)v3;
      v3 = *(_DWORD *)(v3 + 4);
      DoublePointerFree(v4);
      FreeWrapper_7bcf(v4);
    }
    *(_DWORD *)(v0 + 32) = 0;
    *(_DWORD *)(v0 + 36) = 0;
    *(_DWORD *)(v0 + 40) = 0;
    *(_DWORD *)(v0 + 44) = 0;
    if ( *(_DWORD *)(v0 + 16) )
      FreeWrapper_7bcf(*(LPVOID *)(v0 + 16));
    if ( *(_DWORD *)(v0 + 8) )
      FreeWrapper_7bcf(*(LPVOID *)(v0 + 8));
    if ( *(_DWORD *)v0 )
      FreeWrapper_7bcf(*(LPVOID *)v0);
    return FreeWrapper_7bcf((LPVOID)v0);
  }
  return result;
}
