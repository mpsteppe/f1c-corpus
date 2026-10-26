int __thiscall sub_5F7EB0(void *this, int a2)
{
  *(_DWORD *)(a2 + 88) = (*(int (__thiscall **)(void *, const char *, _DWORD))(*(_DWORD *)this + 632))(
                           this,
                           "L0NOLIGHTING",
                           0);
  *(_DWORD *)(*(_DWORD *)(a2 + 4) + 252) = 1;
  return 0;
}
