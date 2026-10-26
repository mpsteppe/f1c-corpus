int __thiscall sub_489980(_DWORD *this, int a2)
{
  int result; // eax

  result = (*(int (__thiscall **)(_DWORD *, int))(*this + 184))(this, a2);
  this[217] = result;
  if ( result )
    this[216] = 1065353216;
  return result;
}
