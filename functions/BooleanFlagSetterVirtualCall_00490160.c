int __thiscall BooleanFlagSetterVirtualCall(_DWORD *this, char a2)
{
  if ( a2 )
    this[56] = 0;
  else
    this[56] = 1;
  return (*(int (__thiscall **)(_DWORD *, int))(*this + 44))(this, 1);
}
