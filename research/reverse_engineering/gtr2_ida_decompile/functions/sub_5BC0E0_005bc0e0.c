int __thiscall sub_5BC0E0(_DWORD *this)
{
  int result; // eax
  bool v2; // zf

  result = this[1] - 1;
  v2 = this[1] == 1;
  this[1] = result;
  if ( result < 0 || v2 )
    return (*(int (__thiscall **)(_DWORD *))(*this + 20))(this);
  return result;
}
