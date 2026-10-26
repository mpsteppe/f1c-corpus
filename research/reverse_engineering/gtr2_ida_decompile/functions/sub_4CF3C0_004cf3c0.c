int __thiscall sub_4CF3C0(_DWORD *this)
{
  switch ( this[33] )
  {
    case 1:
      (*(void (__thiscall **)(_DWORD *, int))(*this + 44))(this, 6);
      (*(void (__thiscall **)(_DWORD *))(*this + 148))(this);
      return 0;
    case 2:
      (*(void (__thiscall **)(_DWORD *, int))(*this + 44))(this, 7);
      goto LABEL_6;
    case 4:
      (*(void (__thiscall **)(_DWORD *, int))(*this + 44))(this, 8);
      (*(void (__thiscall **)(_DWORD *))(*this + 148))(this);
      return 0;
    case 5:
      (*(void (__thiscall **)(_DWORD *, int))(*this + 44))(this, 9);
      goto LABEL_6;
    default:
LABEL_6:
      (*(void (__thiscall **)(_DWORD *))(*this + 148))(this);
      return 0;
  }
}
