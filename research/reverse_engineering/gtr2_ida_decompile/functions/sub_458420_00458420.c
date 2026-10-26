int __thiscall sub_458420(double *this, int a2, int a3)
{
  int result; // eax

  result = a2;
  *(float *)this = *(float *)a2 - *(float *)a3;
  this[1] = *(double *)(a2 + 8) - *(double *)(a3 + 8);
  *((float *)this + 4) = *(float *)(a2 + 16) - *(float *)(a3 + 16);
  return result;
}
