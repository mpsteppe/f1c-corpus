_DWORD *__thiscall sub_5ADE40(_DWORD *this)
{
  _DWORD *v2; // edi

  v2 = this + 1;
  sub_5918B0(this + 1);
  *v2 = 0;
  this[2] = 0;
  this[22] = 0;
  *((_BYTE *)this + 24) = 0;
  this[4] = 0;
  this[5] = 0;
  this[3] = 0;
  *this = &off_5F6554;
  return this;
}
