// f1c  0x0053b200  size=50
int __thiscall sub_53B200(_DWORD *this, int a2, int a3, int a4)
{
  int result; // eax

  this[1] = a2;
  this[2] = a3;
  this[3] = a4;
  this[22] = a2;
  result = this[2];
  this[23] = result;
  this[24] = this[3];
  this[25] = 1065353216;
  return result;
}
