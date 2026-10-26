int __thiscall sub_4CDCE0(_DWORD *this)
{
  int v2; // eax

  v2 = this[33];
  if ( v2 )
  {
    if ( v2 != 1 )
      return -1;
    (*(void (__thiscall **)(_DWORD *, int))(*this + 44))(this, 3);
  }
  else
  {
    (*(void (__thiscall **)(_DWORD *, int))(*this + 44))(this, 2);
  }
  if ( this[61] && (int)sub_4E29B0(this[33]) > 0 )
  {
    this[66] = 2;
    return -1;
  }
  return 0;
}
