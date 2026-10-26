int __thiscall sub_4A6280(_DWORD *this)
{
  int result; // eax

  switch ( sub_49D1E0(this) )
  {
    case 0:
    case 1:
    case 2:
      (*(void (__thiscall **)(_DWORD *, int))(*this + 44))(this, 1);
      sub_4A64A0(this);
      result = 0;
      break;
    case 3:
    case 4:
    case 5:
      (*(void (__thiscall **)(_DWORD *, int))(*this + 44))(this, 4);
      goto LABEL_4;
    default:
LABEL_4:
      sub_4A64A0(this);
      result = 0;
      break;
  }
  return result;
}
