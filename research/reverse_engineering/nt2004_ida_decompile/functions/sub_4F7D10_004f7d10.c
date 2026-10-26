_DWORD *__thiscall sub_4F7D10(_DWORD *this, int a2)
{
  _DWORD *result; // eax

  result = this;
  if ( a2 >= 0 && a2 < this[96] )
    return &this[2 * a2];
  return result;
}
