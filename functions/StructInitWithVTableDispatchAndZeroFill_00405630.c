int __thiscall sub_405630(int this)
{
  int result; // eax

  *(_DWORD *)(this + 28) = -1;
  *(_DWORD *)(this + 32) = 0;
  *(_DWORD *)(this + 36) = 0;
  *(_DWORD *)(this + 40) = 0;
  *(_DWORD *)(this + 44) = 0;
  VirtualCleanup(this + 48);
  (*(void (__thiscall **)(int))(*(_DWORD *)(this + 52) + 4))(this + 52);
  result = 0;
  memset((void *)(this + 68), 0, 0x2Cu);
  *(_BYTE *)(this + 112) = 0;
  return result;
}
