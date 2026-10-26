int __thiscall ShortComputation_75f0(_DWORD *this)
{
  int v2; // eax
  int v3; // eax

  v2 = UtilityFunction_7810(this);
  if ( v2 )
  {
    v3 = *(_DWORD *)(v2 + 372);
    if ( v3 != this[97] )
    {
      this[97] = v3;
      (*(void (__thiscall **)(_DWORD *))(*this + 160))(this);
    }
  }
  return 0;
}
