int __thiscall sub_451B90(float *this, int a2, int a3, int a4, int a5)
{
  int result; // eax

  *((_DWORD *)this + 3) = a4;
  result = a4 - a2;
  *((_DWORD *)this + 4) = (a2 + a4) >> 1;
  *((_DWORD *)this + 1) = a5;
  *(_DWORD *)this = a3;
  *((_DWORD *)this + 2) = a2;
  *((_DWORD *)this + 5) = (a3 + a5) >> 1;
  this[8] = 1.0 / ((double)(a4 - a2) * 0.5);
  this[9] = 1.0 / ((double)(a5 - a3) * 0.5);
  return result;
}
