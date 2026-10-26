float *__thiscall sub_45EB00(float *this, float *a2, float a3)
{
  float *result; // eax
  double v4; // st7
  float v5; // [esp+0h] [ebp-Ch]
  float v6; // [esp+4h] [ebp-8h]
  float v7; // [esp+8h] [ebp-4h]

  result = a2;
  v5 = a3 * *this;
  v6 = a3 * this[1];
  v4 = a3 * this[2];
  *a2 = v5;
  a2[1] = v6;
  v7 = v4;
  a2[2] = v7;
  return result;
}
