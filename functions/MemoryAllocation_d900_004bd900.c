int __thiscall sub_4BD900(int this, int a2)
{
  int v3; // eax
  int v4; // eax
  int v5; // edi
  int i; // eax
  int result; // eax

  v3 = *(_DWORD *)(this + 12);
  if ( *(_DWORD *)(this + 16) == v3 )
  {
    v4 = v3 + 8;
    *(_DWORD *)(this + 12) = v4;
    v5 = OperatorNewNhMallocWrapper(4 * v4);
    for ( i = 0; i < *(_DWORD *)(this + 16); ++i )
      *(_DWORD *)(v5 + 4 * i) = *(_DWORD *)(*(_DWORD *)(this + 20) + 4 * i);
    if ( *(_DWORD *)(this + 20) )
      FreeWrapper_7bcf(*(LPVOID *)(this + 20));
    *(_DWORD *)(this + 20) = v5;
  }
  result = *(_DWORD *)(this + 16);
  *(_DWORD *)(*(_DWORD *)(this + 20) + 4 * result) = a2;
  ++*(_DWORD *)(this + 16);
  return result;
}
