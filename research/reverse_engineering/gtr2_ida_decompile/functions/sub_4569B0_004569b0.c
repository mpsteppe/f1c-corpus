float *__thiscall sub_4569B0(int this, float *a2, float *a3)
{
  float *result; // eax
  double v4[3]; // [esp+0h] [ebp-30h] BYREF
  double v5[3]; // [esp+18h] [ebp-18h] BYREF

  sub_44B250((double *)(this + 544), *(_DWORD *)(this + 6312), v4, v5, 1);
  *a2 = v4[0];
  a2[1] = v4[1];
  a2[2] = v4[2];
  result = a3;
  *a3 = v5[0];
  a3[1] = v5[1];
  a3[2] = v5[2];
  return result;
}
