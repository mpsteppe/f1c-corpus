_DWORD *__thiscall sub_607070(_DWORD *this, _DWORD *a2)
{
  _DWORD *result; // eax

  result = a2;
  this[21] = a2;
  if ( a2 && (result = (_DWORD *)(*a2 >> 4), (*a2 & 0x10) != 0) )
    *this |= 0x10u;
  else
    *this &= ~0x10u;
  return result;
}
