int __thiscall sub_4815D0(_BYTE *this)
{
  int result; // eax

  result = (*(int (__thiscall **)(_BYTE *))(*(_DWORD *)this + 180))(this);
  this[864] = 0;
  return result;
}
