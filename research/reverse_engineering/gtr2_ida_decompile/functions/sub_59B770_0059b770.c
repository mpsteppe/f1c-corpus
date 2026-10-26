int __thiscall sub_59B770(int *this, char a2)
{
  int result; // eax

  result = *this;
  *(_BYTE *)(*this + 97) = a2;
  return result;
}
