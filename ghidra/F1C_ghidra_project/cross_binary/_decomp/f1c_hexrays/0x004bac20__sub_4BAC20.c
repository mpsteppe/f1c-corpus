// f1c  0x004bac20  size=25
_DWORD *__thiscall sub_4BAC20(_DWORD *this, int a2, char a3)
{
  _DWORD *result; // eax

  result = this;
  *this = a2;
  this[1] = 0;
  *((_BYTE *)this + 8) = a3;
  return result;
}
