int __thiscall VTableDispatchInit(_DWORD *this)
{
  (*(void (__thiscall **)(_DWORD *, _DWORD))(*this + 64))(this, 0);
  return VTableDispatchListIteration(this);
}

