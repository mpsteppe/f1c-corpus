// f1c  0x00404d30  size=12
int __thiscall sub_404D30(int *this, int a2)
{
  int result; // eax

  result = *this;
  *(_DWORD *)(*this + 24) = a2;
  return result;
}
