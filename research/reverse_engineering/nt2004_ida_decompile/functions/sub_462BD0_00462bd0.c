int __thiscall sub_462BD0(_BYTE *this)
{
  int result; // eax

  result = 0;
  *(_DWORD *)this = 0;
  this[4] = 0;
  this[36] = 0;
  this[68] = 0;
  this[100] = -1;
  this[101] = 0;
  this[102] = -1;
  *((_WORD *)this + 52) = 0;
  *((_WORD *)this + 53) = 0;
  *((_WORD *)this + 54) = 0;
  *((_WORD *)this + 55) = 0;
  this[112] = 0;
  return result;
}
