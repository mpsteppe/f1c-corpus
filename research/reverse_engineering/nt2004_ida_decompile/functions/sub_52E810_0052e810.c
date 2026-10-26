int __thiscall sub_52E810(float *this)
{
  int result; // eax

  result = 0;
  memset(this + 2, 0, 0xD0u);
  this[3] = 9.9999997e37;
  return result;
}
