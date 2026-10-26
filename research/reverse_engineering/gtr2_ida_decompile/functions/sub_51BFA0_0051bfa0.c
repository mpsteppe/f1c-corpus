_DWORD *__thiscall sub_51BFA0(_DWORD *this, _DWORD *a2)
{
  _DWORD *result; // eax

  result = this;
  if ( ((*a2 >> 8) & 0x3FF) + 8 > 0 )
    qmemcpy(this, a2, ((*a2 >> 8) & 0x3FF) + 8);
  this[211] = a2[211];
  return result;
}
