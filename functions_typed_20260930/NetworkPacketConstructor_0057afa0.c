char __thiscall sub_57AFA0(int this, _DWORD *a2)
{
  int v3; // eax
  int v4; // esi
  int v5; // eax

  *(_BYTE *)(this + 4) = 0;
  v3 = OperatorNewNhMallocWrapper(16);
  v4 = v3;
  if ( v3 )
  {
    *(_WORD *)v3 = 2;
    *(_DWORD *)(v3 + 4) = htonl(0);
    *(_WORD *)(v4 + 2) = htons(0);
  }
  else
  {
    v4 = 0;
  }
  *(_DWORD *)v4 = *a2;
  *(_DWORD *)(v4 + 4) = a2[1];
  *(_DWORD *)(v4 + 8) = a2[2];
  *(_DWORD *)(v4 + 12) = a2[3];
  v5 = OperatorNewNhMallocWrapper(12);
  if ( v5 )
  {
    *(_DWORD *)v5 = v4;
    *(_DWORD *)(v5 + 4) = 0;
    *(_BYTE *)(v5 + 8) = 1;
  }
  else
  {
    v5 = 0;
  }
  if ( *(_DWORD *)(this + 8) )
  {
    *(_DWORD *)(*(_DWORD *)(this + 12) + 4) = v5;
  }
  else
  {
    *(_DWORD *)(this + 8) = v5;
    *(_DWORD *)(this + 16) = v5;
  }
  *(_DWORD *)(this + 12) = v5;
  ++*(_DWORD *)(this + 20);
  return 0;
}

