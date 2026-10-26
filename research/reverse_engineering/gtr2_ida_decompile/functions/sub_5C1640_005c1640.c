int __thiscall sub_5C1640(_DWORD *this, _DWORD *a2)
{
  int result; // eax

  this[6] = *a2;
  this[7] = a2[1];
  result = a2[2];
  this[8] = result;
  return result;
}
