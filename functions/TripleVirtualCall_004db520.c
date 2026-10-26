int __thiscall TripleVirtualCall(void *this)
{
  (*(void (__thiscall **)(void *, _DWORD))(*(_DWORD *)this + 28))(this, 0);
  (*(void (__thiscall **)(void *, int))(*(_DWORD *)this + 32))(this, 1000);
  UILayoutDispatchWithDataPrep(640);
  return 0;
}
