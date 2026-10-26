// f1c  0x0053c2c0  size=154
_DWORD *__thiscall sub_53C2C0(_DWORD *this)
{
  _DWORD *result; // eax

  sub_53C2A0(this);
  *this = 0;
  this[1] = 0;
  this[11] = 0;
  sub_556260(1);
  qword_8B6C20 = 0;
  qword_8B8E40 = 0x1000100010001LL;
  result = this;
  qword_8B8ED8 = 0x100000000000000LL;
  _m_empty();
  return result;
}
