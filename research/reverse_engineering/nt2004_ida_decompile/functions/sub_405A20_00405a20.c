int __thiscall sub_405A20(int *this, int a2)
{
  int result; // eax

  result = *this;
  *(_DWORD *)(*this + 36) = a2;
  return result;
}
