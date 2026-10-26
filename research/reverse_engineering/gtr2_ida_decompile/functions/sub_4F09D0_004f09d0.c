float *__thiscall sub_4F09D0(float *this, float *a2, float *a3, float *a4)
{
  float *result; // eax
  float v5; // [esp+Ch] [ebp-Ch]
  float v6; // [esp+10h] [ebp-8h]
  float v7; // [esp+14h] [ebp-4h]

  v5 = *a3 - *a2;
  v6 = a3[1] - a2[1];
  v7 = a3[2] - a2[2];
  result = a4;
  *a4 = v7 * this[6] + v6 * this[3] + v5 * *this;
  a4[1] = v7 * this[7] + v6 * this[4] + v5 * this[1];
  a4[2] = v7 * this[8] + v6 * this[5] + v5 * this[2];
  return result;
}
