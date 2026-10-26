int __thiscall sub_478350(_DWORD *this)
{
  int v2; // eax
  int v3; // eax

  v2 = this[56];
  if ( v2 )
  {
    v3 = *(_DWORD *)(v2 + 372);
    if ( this[57] != v3 )
    {
      this[57] = v3;
      ProfileIconPathSetter(this);
      (*(void (__thiscall **)(_DWORD *, int))(*this + 44))(this, 1);
    }
  }
  return 0;
}
