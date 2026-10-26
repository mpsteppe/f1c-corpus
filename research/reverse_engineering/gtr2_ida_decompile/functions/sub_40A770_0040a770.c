int __thiscall sub_40A770(int this, float a2, int a3, float a4)
{
  double v5; // st7
  unsigned __int8 v6; // c0
  unsigned __int8 v7; // c3
  int result; // eax

  v5 = 1.0;
  if ( !(v6 | v7) )
    v5 = 1.0 / a2;
  result = a3;
  *(float *)(this + 28) = v5;
  *(_DWORD *)(this + 36) = a3;
  *(float *)(this + 32) = 1.0 - v5 * a4;
  return result;
}
