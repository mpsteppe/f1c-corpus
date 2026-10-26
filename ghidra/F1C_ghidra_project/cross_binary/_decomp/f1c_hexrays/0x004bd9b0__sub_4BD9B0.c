// f1c  0x004bd9b0  size=105
int __thiscall sub_4BD9B0(int this, int a2)
{
  int v3; // eax
  int v4; // eax
  int v5; // edi
  int i; // eax
  int result; // eax

  v3 = *(_DWORD *)(this + 24);
  if ( *(_DWORD *)(this + 28) == v3 )
  {
    v4 = v3 + 8;
    *(_DWORD *)(this + 24) = v4;
    v5 = sub_587C03(4 * v4);
    for ( i = 0; i < *(_DWORD *)(this + 28); ++i )
      *(_DWORD *)(v5 + 4 * i) = *(_DWORD *)(*(_DWORD *)(this + 32) + 4 * i);
    if ( *(_DWORD *)(this + 32) )
      sub_587BCF(*(LPVOID *)(this + 32));
    *(_DWORD *)(this + 32) = v5;
  }
  result = *(_DWORD *)(this + 28);
  *(_DWORD *)(*(_DWORD *)(this + 32) + 4 * result) = a2;
  ++*(_DWORD *)(this + 28);
  return result;
}
