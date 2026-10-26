// f1c  0x005423e0  size=28
int __thiscall sub_5423E0(_DWORD *this, int a2, int a3, int a4)
{
  int result; // eax

  result = a4 + ((a3 + (a2 << 8)) << 8);
  this[31] = result;
  return result;
}
