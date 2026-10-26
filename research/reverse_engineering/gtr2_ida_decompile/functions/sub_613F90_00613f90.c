char __thiscall sub_613F90(int this)
{
  int v1; // eax
  int v3; // ecx

  v1 = *(_DWORD *)(this + 20);
  if ( !v1 )
    return fseek(*(FILE **)(this + 4), 0, 2) == 0;
  v3 = *(_DWORD *)(this + 4);
  if ( v1 != 5 )
    return sub_62AFD0(v3, 0, 2) == 0;
  *(_DWORD *)(v3 + 24) = *(_DWORD *)(v3 + 20);
  return 1;
}
