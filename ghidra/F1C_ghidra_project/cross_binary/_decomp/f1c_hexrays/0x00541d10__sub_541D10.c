// f1c  0x00541d10  size=148
int __thiscall sub_541D10(int this, float a2, float a3, float a4)
{
  int result; // eax
  double v5; // st7
  double v6; // st6

  *(float *)(this + 36) = a2;
  result = LODWORD(a4);
  *(float *)(this + 40) = a3;
  *(float *)(this + 44) = a4;
  *(float *)(this + 396) = a4 * *(float *)(this + 380) + a3 * *(float *)(this + 364) + a2 * *(float *)(this + 348);
  *(float *)(this + 400) = *(float *)(this + 384) * *(float *)(this + 44)
                         + *(float *)(this + 368) * *(float *)(this + 40)
                         + *(float *)(this + 352) * *(float *)(this + 36);
  v5 = *(float *)(this + 388) * *(float *)(this + 44) + *(float *)(this + 372) * *(float *)(this + 40);
  v6 = *(float *)(this + 356) * *(float *)(this + 36);
  *(_DWORD *)(this + 408) = 1065353216;
  *(float *)(this + 404) = v5 + v6;
  return result;
}
