// f1c  0x0053b330  size=31
int __thiscall sub_53B330(_DWORD *this, int a2, int a3, int a4)
{
  int result; // eax

  *this |= 2u;
  this[7] = a2;
  result = a4;
  this[8] = a3;
  this[9] = a4;
  return result;
}
