int __thiscall sub_4D89D0(_DWORD *this)
{
  int result; // eax

  *this = -1;
  this[1] = -1;
  this[2] = -1;
  this[55] = 1056964608;
  *((_BYTE *)this + 224) = 1;
  this[57] = 1065353216;
  this[58] = 1065353216;
  this[3] = 0;
  this[29] = 0;
  this[30] = 0;
  this[31] = 0;
  result = 0;
  memset(this + 4, 0, 0x64u);
  this[54] = 0;
  return result;
}
