_DWORD *__thiscall sub_5A1340(_DWORD *this)
{
  _DWORD *v2; // eax

  sub_5918B0(this);
  *this = 2;
  this[1] = 0;
  this[2] = 0;
  this[3] = 0;
  this[4] = 0;
  v2 = operator new(0x24u);
  if ( v2 )
  {
    v2[5] = 0;
    v2[4] = 0;
    v2[3] = 0;
    v2[2] = 0;
    v2[1] = 0;
    *v2 = 0;
    v2[7] = 0;
    v2[6] = 0;
    v2[8] = 0;
    this[6] = 0;
    this[7] = 0;
    this[8] = 0;
    this[5] = v2;
  }
  else
  {
    this[6] = 0;
    this[7] = 0;
    this[8] = 0;
    this[5] = 0;
  }
  return this;
}
