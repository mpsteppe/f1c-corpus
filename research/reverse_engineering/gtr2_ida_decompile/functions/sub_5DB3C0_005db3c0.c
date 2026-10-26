int __thiscall sub_5DB3C0(float *this, float a2, float a3, float a4, float a5)
{
  long double v5; // st7
  unsigned int v6; // eax
  int result; // eax

  if ( a2 == 0.0 && a3 == 0.0 && a4 == 0.0 && a5 == 0.0 )
  {
    v5 = 0.0;
    v6 = *(_DWORD *)this & 0xFFFFFDFF;
  }
  else
  {
    v6 = *(_DWORD *)this | 0x200;
    v5 = 1.0 / sqrt(a2 * a2 + a3 * a3 + a4 * a4);
  }
  *(_DWORD *)this = v6;
  result = LODWORD(a5);
  this[13] = a5;
  this[10] = a2 * v5;
  this[11] = a3 * v5;
  this[12] = v5 * a4;
  return result;
}
