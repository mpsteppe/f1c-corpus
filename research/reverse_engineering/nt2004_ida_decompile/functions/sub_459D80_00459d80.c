int __thiscall sub_459D80(int *this, int a2)
{
  int result; // eax

  result = *this;
  *(_DWORD *)(*this + 124) = a2;
  return result;
}
