float *__thiscall sub_4F1410(float *this, float *a2, int a3)
{
  float *result; // eax
  double v4; // st7
  float v5; // [esp+0h] [ebp-Ch]
  float v6; // [esp+4h] [ebp-8h]
  float v7; // [esp+8h] [ebp-4h]

  v5 = this[74 * a3 + 117] + this[19];
  v6 = this[74 * a3 + 118] + this[20];
  result = a2;
  v4 = this[74 * a3 + 119] + this[21];
  *a2 = v5;
  a2[1] = v6;
  v7 = v4;
  a2[2] = v7;
  return result;
}
