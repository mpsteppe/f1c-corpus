_DWORD *__thiscall sub_616890(_DWORD *this, int a2)
{
  _DWORD *result; // eax

  result = this;
  this[3] = 0;
  this[4] = -1;
  this[5] = 0;
  this[6] = -1;
  *this = a2;
  this[1] = 0;
  this[2] = 0;
  if ( a2 )
    this[7] = *(_DWORD *)(a2 + 28);
  else
    this[7] = -1;
  this[8] = 0;
  return result;
}
