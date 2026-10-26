int __thiscall sub_459CD0(int *this, int a2)
{
  int result; // eax

  result = *this;
  *(_DWORD *)(*this + 80) = a2;
  return result;
}
