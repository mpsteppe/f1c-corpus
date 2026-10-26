float *__thiscall sub_438380(float *this, float *a2, float a3)
{
  float *result; // eax
  double v4; // st7
  double v5; // st7
  float v6; // [esp+0h] [ebp-Ch]
  float v7; // [esp+4h] [ebp-8h]
  float v8; // [esp+8h] [ebp-4h]

  result = a2;
  v4 = 1.0 / a3;
  v6 = v4 * *this;
  v7 = v4 * this[1];
  v5 = v4 * this[2];
  *a2 = v6;
  a2[1] = v7;
  v8 = v5;
  a2[2] = v8;
  return result;
}
