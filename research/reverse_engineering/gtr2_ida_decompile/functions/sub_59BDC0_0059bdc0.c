int __thiscall sub_59BDC0(_DWORD *this, _DWORD *a2)
{
  int result; // eax

  *this = *a2;
  this[1] = a2[1];
  this[2] = a2[2];
  result = a2[3];
  this[3] = result;
  return result;
}
