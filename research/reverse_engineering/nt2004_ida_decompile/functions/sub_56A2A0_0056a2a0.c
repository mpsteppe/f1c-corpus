int __thiscall sub_56A2A0(int *this, char a2)
{
  int result; // eax

  result = *this;
  *(_BYTE *)(*this + 93) = a2;
  return result;
}
