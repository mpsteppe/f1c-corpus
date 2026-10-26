float *__thiscall sub_5D43F0(float *this, float *a2)
{
  long double v2; // st7
  long double v3; // st7
  float *result; // eax
  long double v5; // st3
  long double v6; // st5
  long double v7; // st4
  long double v8; // st7
  float v9; // [esp+0h] [ebp-4h]

  v9 = *this * *this;
  v2 = sqrt(this[1] * this[1] + this[2] * this[2] + v9);
  if ( v2 <= 0.00001 )
    v3 = 0.0;
  else
    v3 = atan2(v2, this[3]) / v2;
  result = a2;
  v5 = __FYL2X__(this[1] * this[1] + this[2] * this[2] + this[3] * this[3] + v9, 0.6931471805599453094);
  v6 = v3 * this[2];
  v7 = v3;
  v8 = v3 * this[1];
  *a2 = v7 * *this;
  a2[1] = v8;
  a2[2] = v6;
  a2[3] = v5 * 0.5;
  return result;
}
