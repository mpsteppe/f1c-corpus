int __thiscall sub_4700C0(float *this, float *a2, float a3)
{
  double v3; // st7
  double *v4; // ecx
  double v6[3]; // [esp+0h] [ebp-30h] BYREF
  double v7[3]; // [esp+18h] [ebp-18h] BYREF

  this[10] = a3;
  this[9] = a3 + 100.0;
  v3 = a2[1];
  v4 = (double *)(this + 56);
  v7[0] = a2[12] * v3;
  v7[1] = a2[13] * v3;
  v7[2] = a2[14] * v3;
  v6[0] = v4[1] - a2[9];
  v6[1] = v4[2] - a2[10];
  v6[2] = v4[3] - a2[11];
  return sub_6190D0(v7, v6);
}
