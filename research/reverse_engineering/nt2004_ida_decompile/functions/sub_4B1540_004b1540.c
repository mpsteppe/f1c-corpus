int __thiscall sub_4B1540(_DWORD *this, int a2, int a3)
{
  int result; // eax

  this[1] += a3;
  result = a2;
  this[2] += a3;
  this[3] += a2;
  this[4] += a2;
  return result;
}
