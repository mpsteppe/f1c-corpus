int __thiscall sub_40B6F0(_DWORD *this, int a2)
{
  int result; // eax

  result = a2;
  if ( a2 >= 0 && a2 < this[4] )
  {
    this[5] = a2;
    return (*(int (__thiscall **)(_DWORD *))(*this + 16))(this);
  }
  return result;
}
