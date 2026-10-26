int __thiscall sub_4D0390(int *this, char a2)
{
  unsigned __int16 v2; // dx
  int result; // eax

  LOBYTE(v2) = 0;
  HIBYTE(v2) = a2 + 1;
  result = ((unsigned __int16)*this ^ v2) & 0xF00 ^ *this;
  *this = result;
  return result;
}
