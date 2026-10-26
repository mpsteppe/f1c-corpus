double __thiscall sub_5C65F0(_DWORD *this, int a2, double a3)
{
  unsigned __int8 *v3; // eax
  double v4; // st5

  v3 = (unsigned __int8 *)(*(_DWORD *)(this[1] + 8) + 8 * a2);
  v4 = a3 * a3 * a3;
  return (double)v3[8] * 0.0039215689 * (a3 * a3 * 3.0 - (v4 + v4))
       + (double)*v3 * 0.0039215689 * (v4 + v4 - a3 * a3 * 3.0 + 1.0)
       + (v4 - (a3 * a3 + a3 * a3) + a3) * *(float *)(this[2] + 4 * a2)
       + (v4 - a3 * a3) * *(float *)(this[2] + 4 * a2 + 4);
}
