double __stdcall sub_591300(float *a1, float *a2)
{
  double v2; // st6
  double v3; // st5
  double v4; // st3

  v2 = a1[1] - a2[1];
  v3 = *a1 - *a2;
  v4 = a1[2] - a2[2];
  return v3 * v3 + v2 * v2 + v4 * v4;
}
