float *__thiscall sub_447100(int this, float *a2, float *a3)
{
  float *result; // eax
  double v4[3]; // [esp+0h] [ebp-30h] BYREF
  long double v5[3]; // [esp+18h] [ebp-18h] BYREF

  SuspensionSpringDamperForceComputationWithClampi((char *)(this + 492), *(_DWORD *)(this + 5616), v4, v5);
  *a2 = v4[0];
  a2[1] = v4[1];
  a2[2] = v4[2];
  result = a3;
  *a3 = v5[0];
  a3[1] = v5[1];
  a3[2] = v5[2];
  return result;
}
