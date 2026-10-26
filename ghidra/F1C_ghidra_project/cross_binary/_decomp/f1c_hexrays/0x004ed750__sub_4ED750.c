// f1c  0x004ed750  size=85
float *__fastcall sub_4ED750(float *a1, float *a2, float *a3)
{
  float *result; // eax
  double v4; // st7
  double v5; // st6
  float v6; // [esp+0h] [ebp-Ch]
  float v7; // [esp+4h] [ebp-8h]
  float v8; // [esp+8h] [ebp-4h]

  result = a3;
  v6 = a2[2] * a1[1] - a2[1] * a1[2];
  v7 = *a2 * a1[2] - a2[2] * *a1;
  v4 = a2[1] * *a1;
  v5 = *a2 * a1[1];
  *a3 = v6;
  a3[1] = v7;
  v8 = v4 - v5;
  a3[2] = v8;
  return result;
}
