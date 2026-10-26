int __thiscall sub_4FC910(float *this, int a2)
{
  int result; // eax

  *this = (double)*(unsigned __int16 *)(a2 + 8) * 0.000015259022;
  this[1] = (double)*(unsigned __int16 *)(a2 + 10) * 0.000015259022;
  this[2] = (double)*(unsigned __int16 *)(a2 + 12) * 0.000015259022;
  this[3] = (double)*(unsigned __int16 *)(a2 + 14) * 0.000015259022;
  this[4] = (double)*(__int16 *)(a2 + 16) * 0.0078125;
  result = *(__int16 *)(a2 + 18);
  this[5] = (double)result * 0.0078125;
  return result;
}
