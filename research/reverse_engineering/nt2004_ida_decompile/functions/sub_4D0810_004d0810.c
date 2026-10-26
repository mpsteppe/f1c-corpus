double __stdcall sub_4D0810(float *a1)
{
  float v3; // [esp+4h] [ebp+4h]

  v3 = cos(*a1);
  return atan2(sin(a1[1]) * v3, cos(a1[1]) * v3);
}
