int __thiscall sub_644510(int this, int a2)
{
  *(_DWORD *)(this + 4) = 0;
  *(_DWORD *)(this + 8) = 0;
  *(_DWORD *)this = &off_735FDC;
  sub_644450((void **)this, *(const char **)(a2 + 4), *(const char **)(a2 + 8));
  return this;
}
