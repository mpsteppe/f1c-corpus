int __thiscall TripleVirtualCallDispatch(_DWORD *this)
{
  int v2; // eax

  v2 = *this;
  this[65] = 0;
  (*(void (__stdcall **)(_DWORD))(v2 + 64))(0);
  (*(void (__thiscall **)(_DWORD *, int))(*this + 44))(this, 1);
  return (*(int (__thiscall **)(_DWORD *))(*this + 156))(this);
}
