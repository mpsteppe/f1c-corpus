int __thiscall sub_590740(_DWORD *this)
{
  int result; // eax

  memset(this + 10, 0, 0x40u);
  result = 1065353216;
  this[10] = 1065353216;
  this[15] = 1065353216;
  this[20] = 1065353216;
  this[25] = 1065353216;
  *this = 1;
  return result;
}
