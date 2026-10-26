// f1c  0x005870e0  size=31
int __thiscall sub_5870E0(int this)
{
  int result; // eax

  sub_587500(this + 4);
  result = 0;
  *(_DWORD *)(this + 20) = -1;
  *(_DWORD *)(this + 16) = 0;
  *(_BYTE *)(this + 24) = 0;
  *(_BYTE *)(this + 25) = 0;
  return result;
}
