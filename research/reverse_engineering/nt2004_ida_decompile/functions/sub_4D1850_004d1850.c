_DWORD *__thiscall sub_4D1850(_DWORD *this, _DWORD *a2)
{
  _DWORD *result; // eax

  result = this;
  if ( ((*a2 >> 6) & 0x3FF) + 8 > 0 )
    qmemcpy(this, a2, ((*a2 >> 6) & 0x3FF) + 8);
  this[51] = a2[51];
  return result;
}
