int __thiscall sub_5C1620(_DWORD *this, _DWORD *a2)
{
  int result; // eax

  this[3] = *a2;
  this[4] = a2[1];
  result = a2[2];
  this[5] = result;
  return result;
}
