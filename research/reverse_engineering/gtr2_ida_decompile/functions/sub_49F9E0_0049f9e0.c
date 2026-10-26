int __thiscall sub_49F9E0(_DWORD *this)
{
  char v3; // [esp+4h] [ebp-4h]

  if ( this[212] != dword_B72338 )
  {
    this[212] = dword_B72338;
    (*(void (__thiscall **)(_DWORD *))(*this + 152))(this);
  }
  if ( dword_B640C0 == 5 || (v3 = 0, byte_B6CBC3) )
    v3 = 1;
  (*(void (__thiscall **)(_DWORD *, char))(*this + 36))(this, v3);
  return 0;
}
