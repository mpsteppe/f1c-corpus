char __thiscall sub_59C650(int this, int a2)
{
  _DWORD **v3; // eax
  _DWORD *v4; // eax
  int v5; // eax
  _DWORD **v6; // eax

  if ( *(_BYTE *)(this + 4) )
    return 1;
  v3 = *(_DWORD ***)(this + 24);
  *(_DWORD *)(this + 32) = v3;
  if ( !v3 )
    return 0;
  v4 = *v3;
  if ( !v4 )
    return 0;
  while ( a2 != *v4 )
  {
    v5 = *(_DWORD *)(this + 32);
    if ( v5 )
      *(_DWORD *)(this + 32) = *(_DWORD *)(v5 + 4);
    v6 = *(_DWORD ***)(this + 32);
    if ( v6 )
    {
      v4 = *v6;
      if ( v4 )
        continue;
    }
    return 0;
  }
  return 1;
}
