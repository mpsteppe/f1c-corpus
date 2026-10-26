_BYTE *__thiscall sub_59B180(_BYTE *this, const void *a2, unsigned int a3)
{
  _BYTE *result; // eax

  result = this;
  qmemcpy(this + 45, a2, a3);
  this[44] = a3;
  return result;
}
