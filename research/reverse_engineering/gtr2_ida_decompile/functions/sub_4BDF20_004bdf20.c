int __thiscall sub_4BDF20(_BYTE *this)
{
  int result; // eax

  result = (*(int (__thiscall **)(_BYTE *, _DWORD))(*(_DWORD *)this + 36))(this, 0);
  this[277] = 0;
  return result;
}
