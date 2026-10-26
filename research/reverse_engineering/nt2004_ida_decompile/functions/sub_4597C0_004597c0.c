float *__thiscall sub_4597C0(float *this, float *a2, float a3, float a4)
{
  float *result; // eax
  double v5; // st7
  float v6; // [esp+8h] [ebp-10h]
  float v7; // [esp+Ch] [ebp-Ch]

  result = a2;
  v6 = a3 * a2[2];
  v7 = a3 * *a2 * a4;
  v5 = a3 * a2[1] * a4;
  this[8] = v7 + this[8];
  this[9] = v5 + this[9];
  this[10] = v6 * a4 + this[10];
  return result;
}
