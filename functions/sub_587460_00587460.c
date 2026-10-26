_DWORD *__thiscall sub_587460(_DWORD *this, int a2)
{
  this[2] = 0;
  this[1] = 0;
  *this = 0;
  if ( a2 > 0 )
    OperatorNewWithResultCheck(a2, this);
  this[1] = a2;
  return this;
}
