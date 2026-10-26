char __thiscall sub_459C30(int *this, _DWORD *a2)
{
  _DWORD *v2; // ecx
  int v4; // ecx

  v4 = *this;
  if ( (*(_DWORD *)(v4 + 140) & 8) != 0 )
    return 0;
  if ( a2 )
  {
    v2 = (_DWORD *)(v4 + 88);
    *a2 = *v2;
    a2[1] = v2[1];
    a2[2] = v2[2];
  }
  return 1;
}
