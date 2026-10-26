int __thiscall sub_567010(float *this)
{
  int v1; // eax
  float v3[9]; // [esp+0h] [ebp-24h] BYREF

  F_33RotationMatrixFromQuaternion(this, v3);
  return RotationMatrixToEuler(v3, v1);
}
