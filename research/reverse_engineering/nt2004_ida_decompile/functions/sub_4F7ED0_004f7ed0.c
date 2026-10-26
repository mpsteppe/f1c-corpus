int __thiscall sub_4F7ED0(_DWORD *this)
{
  int result; // eax

  *(_BYTE *)this = 0;
  sub_4F7CC0(this + 1);
  sub_4F7CC0(this + 98);
  this[195] = 0;
  this[208] = 0;
  result = -1;
  memset(this + 196, 0xFFu, 0x30u);
  return result;
}
