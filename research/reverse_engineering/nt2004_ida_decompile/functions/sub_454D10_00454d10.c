int __thiscall sub_454D10(_DWORD *this, int a2, int a3)
{
  int result; // eax

  byte_761FFC[*this] = 0;
  result = a2;
  *this = a2;
  this[1] = a3;
  byte_761FFC[a2] = a3;
  return result;
}
