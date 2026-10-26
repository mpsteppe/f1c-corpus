float *__thiscall sub_4F2290(float *this, float *a2)
{
  float *result; // eax
  double v3; // st7
  double v4; // st5
  double v5; // st6
  double v6; // st5
  long double v7; // rt0
  double v8; // st5
  long double v9; // st6
  float v10; // [esp+0h] [ebp-8h]
  float v11; // [esp+4h] [ebp-4h]

  result = a2;
  v3 = this[1] * this[1];
  v4 = this[2] * this[2] + v3;
  v11 = 1.0 - (v4 + v4);
  v5 = this[2] * this[3] + *this * this[1];
  v10 = v5 + v5;
  v6 = this[2] * this[1] + *this * this[3];
  v7 = v6 + v6;
  v8 = v3 + *this * *this;
  v9 = atan2((this[2] * *this - this[3] * this[1]) * -2.0, sqrt(v10 * v10 + v11 * v11));
  *a2 = atan2(v7, 1.0 - (v8 + v8));
  a2[1] = v9;
  a2[2] = atan2(v10, v11);
  return result;
}
