int __thiscall sub_4A6220(_DWORD *this)
{
  switch ( sub_49D1E0(this) )
  {
    case 0:
    case 1:
    case 2:
      (*(void (__thiscall **)(_DWORD *, int))(*this + 44))(this, 4);
      break;
    case 3:
    case 4:
    case 5:
      (*(void (__thiscall **)(_DWORD *, int))(*this + 44))(this, 1);
      break;
    default:
      break;
  }
  (*(void (__thiscall **)(_DWORD *))(*this + 148))(this);
  sub_4A64A0(this);
  return 0;
}
