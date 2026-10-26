// f1c  0x004b3a90  size=63
_DWORD *__thiscall sub_4B3A90(_DWORD *this, _DWORD *a2)
{
  _DWORD *result; // eax

  result = this;
  if ( ((*a2 >> 8) & 0x3FF) + 8 > 0 )
    qmemcpy(this, a2, ((*a2 >> 8) & 0x3FF) + 8);
  this[107] = a2[107];
  return result;
}
