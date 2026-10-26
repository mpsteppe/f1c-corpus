int __thiscall sub_45C850(_DWORD *this, int a2)
{
  int result; // eax

  this[a2 + 5] = 0;
  this[a2 + 109] = 0;
  *((_BYTE *)this + a2 + 852) = 0;
  *((_BYTE *)this + a2 + 956) = 0;
  result = 0;
  memset(&this[8 * a2 + 265], 0, 0x20u);
  *((_WORD *)this + a2 + 2402) = 0;
  this[a2 + 1097] = -1082130432;
  return result;
}
