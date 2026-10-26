int __thiscall sub_459D30(int *this, int a2)
{
  int result; // eax

  result = *this;
  *(_DWORD *)(*this + 144) = a2;
  return result;
}
