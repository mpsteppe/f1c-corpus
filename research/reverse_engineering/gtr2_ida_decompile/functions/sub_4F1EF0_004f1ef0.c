bool __thiscall sub_4F1EF0(int this)
{
  int v2; // eax

  if ( (*(_BYTE *)(this + 12) & 1) == 0 )
    return 1;
  v2 = *(_DWORD *)(this + 296);
  return !v2 || *(_BYTE *)(v2 + 14);
}
