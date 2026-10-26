// f1c  0x00551440  size=51
int __thiscall sub_551440(_DWORD *this)
{
  int result; // eax

  this[1] = this[1] & 0xFFFE0FFF | 0x2000;
  sub_551390(this, 0, 0);
  sub_5563E0(*this);
  result = sub_556440(*this);
  this[4] = 0;
  return result;
}
