int __thiscall sub_5001B0(float *this)
{
  int result; // eax

  result = 0;
  memset(this + 2, 0, 0x1B0u);
  this[3] = 9.9999997e37;
  return result;
}

