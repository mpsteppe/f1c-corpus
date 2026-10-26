int __thiscall sub_405A10(int *this, int a2)
{
  int result; // eax

  result = *this;
  *(_DWORD *)(*this + 28) = a2;
  return result;
}
