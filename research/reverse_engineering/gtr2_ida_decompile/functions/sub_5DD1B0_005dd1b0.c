int __thiscall sub_5DD1B0(float *this, int a2, int a3, int a4)
{
  int result; // eax

  result = *(_DWORD *)this | 4;
  *(_DWORD *)this = result;
  this[58] = (double)a2 * 0.0039215689;
  this[59] = (double)a3 * 0.0039215689;
  this[60] = (double)a4 * 0.0039215689;
  return result;
}
