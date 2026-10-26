// f1c  0x00431a50  size=20
int __thiscall sub_431A50(int this, int a2)
{
  int result; // eax

  result = a2;
  *(_DWORD *)(this + 7356) = a2;
  *(_BYTE *)(this + 7352) = 1;
  return result;
}
