int __thiscall sub_49E6A0(_DWORD *this)
{
  int v1; // eax

  v1 = *(_DWORD *)dword_B72314;
  if ( this[212] != *(_DWORD *)dword_B72314 )
  {
    this[212] = *(_DWORD *)dword_B72314;
    v1 = *(_DWORD *)dword_B72314;
  }
  if ( v1 == 4 )
    (*(void (__thiscall **)(_DWORD *, int))(*this + 36))(this, 1);
  (*(void (__thiscall **)(_DWORD *))(*this + 152))(this);
  return 0;
}
