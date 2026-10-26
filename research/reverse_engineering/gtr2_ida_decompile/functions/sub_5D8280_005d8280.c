int __thiscall sub_5D8280(int *this)
{
  int result; // eax

  memset(this + 1, 0, 0x40u);
  this[1] = 1065353216;
  this[6] = 1065353216;
  this[11] = 1065353216;
  this[16] = 1065353216;
  result = *this | 1;
  *this = result;
  return result;
}
