int __thiscall sub_4583E0(double *this, int a2, int a3)
{
  int result; // eax

  result = a2;
  *(float *)this = (*(float *)a2 + *(float *)a3) * 0.5;
  this[1] = (*(double *)(a2 + 8) + *(double *)(a3 + 8)) * 0.5;
  *((float *)this + 4) = (*(float *)(a2 + 16) + *(float *)(a3 + 16)) * 0.5;
  return result;
}
