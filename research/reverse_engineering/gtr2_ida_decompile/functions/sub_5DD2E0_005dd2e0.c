int __thiscall sub_5DD2E0(float *this, float a2, float a3, float a4, float a5)
{
  long double v5; // st7
  unsigned int v6; // eax

  if ( a2 == 0.0 && a3 == 0.0 && a4 == 0.0 && a5 == 0.0 )
  {
    v5 = 0.0;
    v6 = *(_DWORD *)this & 0xFFFFFBFF;
  }
  else
  {
    v6 = *(_DWORD *)this | 0x400;
    v5 = 1.0 / sqrt(a2 * a2 + a3 * a3 + a4 * a4);
  }
  *(_DWORD *)this = v6;
  this[75] = a5;
  this[72] = a2 * v5;
  this[73] = a3 * v5;
  this[74] = v5 * a4;
  return sub_5D8C20(dword_FB27A8, 0, (int)(this + 72), (int)(this + 77));
}
