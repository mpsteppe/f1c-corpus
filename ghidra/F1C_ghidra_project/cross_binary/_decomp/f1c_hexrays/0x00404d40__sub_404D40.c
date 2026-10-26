// f1c  0x00404d40  size=12
int __thiscall sub_404D40(int *this, int a2)
{
  int result; // eax

  result = *this;
  *(_DWORD *)(*this + 32) = a2;
  return result;
}
