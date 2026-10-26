int __stdcall sub_541CD0(int a1, int a2, float a3, float a4, float a5, float a6)
{
  RandomRotationMatrixFromEulerAngles(a4, a5, a6);
  return OrientationRotationMatrixUpdate(a1, a2, a3);
}
