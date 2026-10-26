int __thiscall sub_4CDD40(_DWORD *this)
{
  if ( this[33] == 2 )
  {
    (*(void (__thiscall **)(_DWORD *, _DWORD))(*this + 44))(this, 0);
  }
  else if ( this[33] == 3 )
  {
    (*(void (__thiscall **)(_DWORD *, int))(*this + 44))(this, 1);
    this[66] = 0;
    return 0;
  }
  this[66] = 0;
  return 0;
}
