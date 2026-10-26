int __thiscall sub_409B00(int *this, int a2)
{
  int result; // eax

  result = *this;
  *(_DWORD *)(*this + 24) = a2;
  return result;
}
