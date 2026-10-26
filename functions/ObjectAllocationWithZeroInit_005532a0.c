_DWORD *__thiscall sub_5532A0(_DWORD *this)
{
  _DWORD *v2; // eax

  GlobalZeroInit_c2a0(this);
  *this = 2;
  this[1] = 0;
  this[2] = 0;
  this[3] = 0;
  this[4] = 0;
  v2 = (_DWORD *)OperatorNewNhMallocWrapper(36);
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
