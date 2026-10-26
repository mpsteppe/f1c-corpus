float *__stdcall sub_5F2F70(float *a1, int a2, int a3, float *a4)
{
  long double v4; // st7
  float *result; // eax
  float v6; // [esp+8h] [ebp-10h]
  float v7; // [esp+8h] [ebp-10h]

  sub_5A9519();
  v4 = pow(v6, *a4);
  result = a1;
  v7 = v4 - 0.5 + v4 - 0.5;
  *a1 = v7;
  a1[1] = v7;
  a1[2] = v7;
  a1[3] = v7;
  return result;
}
