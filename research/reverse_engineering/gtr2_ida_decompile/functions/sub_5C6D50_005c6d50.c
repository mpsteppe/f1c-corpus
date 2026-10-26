float *__thiscall sub_5C6D50(float *this, float *a2, float *a3, float a4)
{
  float *result; // eax
  double v5; // st7
  double v6; // st6
  double v7; // st5
  float v8; // [esp+0h] [ebp-4h]

  v8 = 1.0 - a4;
  if ( a3[3] * this[3] + a3[2] * this[2] + this[1] * a3[1] + *a3 * *this < 0.0 )
    a4 = -a4;
  result = a2;
  v5 = a4 * a3[3] + v8 * this[3];
  v6 = a4 * a3[2] + v8 * this[2];
  v7 = v8 * this[1] + a4 * a3[1];
  *a2 = a4 * *a3 + v8 * *this;
  a2[1] = v7;
  a2[2] = v6;
  a2[3] = v5;
  return result;
}
