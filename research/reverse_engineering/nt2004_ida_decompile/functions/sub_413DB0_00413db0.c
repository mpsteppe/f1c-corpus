int __thiscall sub_413DB0(int this)
{
  int result; // eax

  result = this;
  strcpy((char *)this, "l\a");
  *(_DWORD *)(this + 4) = 0;
  *(_DWORD *)(this + 8) = 0;
  *(_DWORD *)(this + 12) = 0;
  *(_BYTE *)(this + 16) = 1;
  *(_DWORD *)(this + 20) = 0;
  *(_DWORD *)(this + 24) = 0;
  return result;
}
