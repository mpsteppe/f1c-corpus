int __thiscall sub_44A900(char *this, int a2, int a3)
{
  int result; // eax

  result = a2;
  *(float *)this = *(float *)a2 - *(float *)a3;
  *(double *)(this + 4) = *(double *)(a2 + 4) - *(double *)(a3 + 4);
  *((float *)this + 3) = *(float *)(a2 + 12) - *(float *)(a3 + 12);
  return result;
}
