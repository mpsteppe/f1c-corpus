// f1c  0x004f17a0  size=39
int __thiscall sub_4F17A0(int this, int a2, float a3, int a4)
{
  int result; // eax
  double v5; // st7

  result = a2;
  v5 = a3 * *(float *)(this + 14716);
  *(_DWORD *)(this + 14740) = a2;
  *(_DWORD *)(this + 13680) = a4;
  *(float *)(this + 14712) = v5;
  return result;
}
