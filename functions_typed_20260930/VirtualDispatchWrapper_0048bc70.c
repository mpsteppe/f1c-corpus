int __thiscall VirtualDispatchWrapper(void *this)
{
  UIActiveStateToggle((int)this);
  (*(void (__thiscall **)(void *))(*(_DWORD *)this + 172))(this);
  return 0;
}

