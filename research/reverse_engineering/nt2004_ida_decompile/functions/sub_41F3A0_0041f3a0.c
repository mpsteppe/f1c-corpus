int __thiscall sub_41F3A0(_DWORD *this, _DWORD *a2)
{
  int v2; // eax
  int v3; // eax

  v2 = this[193];
  if ( !v2 )
    return -1;
  v3 = *(_DWORD *)(v2 + 4);
  if ( !v3 )
    return -1;
  this[193] = v3;
  *a2 = *(_DWORD *)(v3 + 12);
  return *(_DWORD *)(this[193] + 8);
}
