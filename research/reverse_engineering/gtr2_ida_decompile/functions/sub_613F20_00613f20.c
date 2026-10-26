int __thiscall sub_613F20(int this)
{
  int v2; // eax
  int v3; // edi

  v2 = *(_DWORD *)(this + 20);
  v3 = -1;
  if ( v2 )
  {
    if ( v2 != 5 )
      return sub_62AFD0(*(_DWORD *)(this + 4), *(_DWORD *)(this + 84), 0) == *(_DWORD *)(this + 84);
    *(_DWORD *)(*(_DWORD *)(this + 4) + 24) = *(_DWORD *)(this + 84);
    v3 = *(_DWORD *)(*(_DWORD *)(this + 4) + 24);
  }
  else if ( !fseek(*(FILE **)(this + 4), *(_DWORD *)(this + 84), 0) )
  {
    return 1;
  }
  return v3 == *(_DWORD *)(this + 84);
}
