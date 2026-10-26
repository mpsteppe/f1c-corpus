int __thiscall sub_4CD920(_DWORD *this)
{
  if ( *((_BYTE *)this + 100) )
    return -1;
  switch ( this[33] )
  {
    case 0:
      (*(void (__thiscall **)(_DWORD *, int))(*this + 44))(this, 1);
      break;
    case 2:
      (*(void (__thiscall **)(_DWORD *, int))(*this + 44))(this, 3);
      break;
    case 4:
      if ( (unsigned __int8)sub_4CD720() )
        (*(void (__stdcall **)(int))(*this + 44))(3);
      else
        (*(void (__thiscall **)(_DWORD *, int))(*this + 44))(this, 1);
      break;
    default:
      break;
  }
  (*(void (__thiscall **)(_DWORD *))(*this + 48))(this);
  if ( (*(int (__thiscall **)(_DWORD *))(*this + 144))(this) )
    return -1;
  sub_4CD570();
  return 0;
}
