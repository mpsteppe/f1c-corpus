LONG __thiscall sub_5AD860(int this)
{
  *(_DWORD *)(this + 4) = *(_DWORD *)(this + 4) & 0xFFFF8FFF | 0x1000;
  return sub_5AC620(*(LONG **)this);
}
