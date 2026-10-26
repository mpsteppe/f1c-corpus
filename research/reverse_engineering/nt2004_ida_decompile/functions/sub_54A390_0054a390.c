float *__stdcall sub_54A390(float *a1, float a2)
{
  float *result; // eax
  float v3; // [esp+8h] [ebp-8h]
  float v4; // [esp+Ch] [ebp-4h]

  v4 = cos(a2);
  v3 = sin(a2);
  result = a1;
  *a1 = v4;
  a1[1] = 0.0;
  a1[2] = -v3;
  a1[3] = 0.0;
  a1[4] = 0.0;
  a1[5] = 1.0;
  a1[6] = 0.0;
  a1[7] = 0.0;
  a1[8] = v3;
  a1[9] = 0.0;
  a1[10] = v4;
  a1[11] = 0.0;
  a1[12] = 0.0;
  a1[13] = 0.0;
  a1[14] = 0.0;
  a1[15] = 1.0;
  return result;
}
