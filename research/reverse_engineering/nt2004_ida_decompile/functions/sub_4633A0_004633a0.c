int __thiscall sub_4633A0(int *this)
{
  bool v2; // zf
  int v3; // eax

  if ( *(_DWORD *)(*this + 6720) != 4 )
    return *(_DWORD *)(*this + 6720);
  if ( !*(_DWORD *)(*this + 6708) )
    return *(_DWORD *)(*this + 6720);
  v2 = sub_56A630() == 3;
  v3 = *this;
  if ( v2 )
  {
    *(_DWORD *)(v3 + 6720) = 3;
    return *(_DWORD *)(*this + 6720);
  }
  return *(_DWORD *)(v3 + 6720);
}
