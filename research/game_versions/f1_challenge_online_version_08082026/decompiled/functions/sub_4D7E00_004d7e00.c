int __thiscall sub_4D7E00(_BYTE *this)
{
  if ( (*(unsigned __int8 (__thiscall **)(_BYTE *))(*(_DWORD *)this + 24))(this) )
    sub_4D7FE0(this);
  if ( this[8] )
    sub_4D7FF0(this);
  return (*(int (__thiscall **)(_BYTE *))(*(_DWORD *)this + 4))(this);
}
