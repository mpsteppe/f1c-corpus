unsigned __int64 __thiscall sub_5C59E0(_WORD *this, float *a2, float a3, float a4)
{
  double v4; // st7
  unsigned __int64 result; // rax

  v4 = (double)(unsigned __int16)(unsigned __int64)(1.0 / (a4 - a3) * 65535.0);
  *this = (unsigned __int64)((*a2 - a3) * v4);
  this[1] = (unsigned __int64)((a2[1] - a3) * v4);
  result = (unsigned __int64)((a2[2] - a3) * v4);
  this[2] = result;
  return result;
}
