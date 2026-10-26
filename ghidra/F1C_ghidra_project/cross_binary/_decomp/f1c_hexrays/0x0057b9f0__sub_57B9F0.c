// f1c  0x0057b9f0  size=29
_DWORD *__thiscall sub_57B9F0(_DWORD *this, _DWORD *a2)
{
  _DWORD *result; // eax

  result = a2;
  *a2 = *this;
  a2[1] = this[1];
  a2[2] = this[2];
  a2[3] = this[3];
  return result;
}
