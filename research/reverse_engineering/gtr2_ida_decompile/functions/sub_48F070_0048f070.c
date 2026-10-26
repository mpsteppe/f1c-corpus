int __thiscall sub_48F070(_DWORD *this)
{
  int v2; // eax

  v2 = *this;
  this[76] = 0;
  (*(void (__stdcall **)(_DWORD))(v2 + 44))(0);
  return (*(int (__thiscall **)(_DWORD *))(*this + 148))(this);
}
