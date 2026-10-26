// f1c  0x004c5c80  size=48
_DWORD *__thiscall sub_4C5C80(_DWORD *this, int a2, int a3)
{
  _DWORD *v4; // ecx

  v4 = this + 1;
  *v4 = 0;
  v4[1] = -1;
  *this = a2;
  sub_566650(a3);
  sub_4C5CB0(this);
  return this;
}
