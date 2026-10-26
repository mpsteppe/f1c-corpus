_DWORD *__thiscall sub_54EAF0(_DWORD *this)
{
  _DWORD *v2; // ecx

  *this = 0;
  v2 = this + 1;
  *v2 = 0;
  v2[1] = 0;
  v2[2] = 0;
  this[7] = 0;
  this[8] = 0;
  this[9] = 0;
  memset(this + 13, 0, 0x40u);
  return this;
}
