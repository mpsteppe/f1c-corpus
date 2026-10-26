// f1c  0x00461480  size=63
int __thiscall sub_461480(_BYTE *this)
{
  int result; // eax

  result = 0;
  *(_DWORD *)this = 0;
  this[4] = 0;
  this[36] = 0;
  this[60] = 0;
  this[92] = 0;
  this[124] = -1;
  this[125] = 0;
  this[126] = -1;
  *((_WORD *)this + 64) = 0;
  *((_WORD *)this + 65) = 0;
  *((_WORD *)this + 66) = 0;
  *((_WORD *)this + 67) = 0;
  this[136] = 0;
  return result;
}
