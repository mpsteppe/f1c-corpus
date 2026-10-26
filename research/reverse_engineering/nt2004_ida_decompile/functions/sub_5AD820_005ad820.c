int __thiscall sub_5AD820(_BYTE **this)
{
  int result; // eax

  this[1] = (_BYTE *)((unsigned int)this[1] & 0xFFFE0FFF | 0x2000);
  sub_5AD770(this, 0, 0);
  sub_5AC680(*this);
  result = sub_5AC740((int *)*this, 1);
  this[4] = 0;
  return result;
}
