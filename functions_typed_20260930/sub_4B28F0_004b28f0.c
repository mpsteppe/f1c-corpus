int __thiscall sub_4B28F0(char *this, int a2, float *a3, float *a4)
{
  int result; // eax

  *a3 = (double)this[a2 + 18] * 0.00390625;
  result = *(__int16 *)&this[2 * a2 + 22];
  *a4 = (double)result * 0.0099999998;
  return result;
}

