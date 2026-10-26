// f1c  0x00557240  size=57
_DWORD *__thiscall sub_557240(_DWORD *this)
{
  _DWORD *v2; // esi
  int v3; // ebx

  sub_53C2A0(this);
  v2 = this + 1;
  v3 = 8;
  do
  {
    sub_553DB0(v2);
    v2 += 16;
    --v3;
  }
  while ( v3 );
  this[129] = 0;
  this[130] = 0;
  this[131] = 0;
  return this;
}
