int __thiscall sub_4599C0(float *this, float *a2, float a3)
{
  double v3; // st7
  float *v4; // ecx
  double v6[3]; // [esp+0h] [ebp-30h] BYREF
  double v7[3]; // [esp+18h] [ebp-18h] BYREF

  this[9] = a3;
  this[8] = a3 + 100.0;
  v3 = a2[1];
  v4 = this + 53;
  v7[0] = a2[8] * v3;
  v7[1] = a2[9] * v3;
  v7[2] = a2[10] * v3;
  v6[0] = *(double *)(v4 + 1) - a2[5];
  v6[1] = *(double *)(v4 + 3) - a2[6];
  v6[2] = *(double *)(v4 + 5) - a2[7];
  return F_3DVectorCrossProductRotationAccumulation(v7, v6);
}

