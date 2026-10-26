float *__thiscall sub_5D1E60(float *this, float *a2)
{
  float *result; // eax
  double v3; // st7
  double v4; // st6
  double v5; // st5
  float v6; // [esp+0h] [ebp-4h]

  result = a2;
  v6 = 1.0 / (*this * *this + this[1] * this[1] + this[2] * this[2] + this[3] * this[3]);
  v3 = v6 * this[3];
  v4 = -(v6 * this[2]);
  v5 = -(v6 * this[1]);
  *a2 = -(v6 * *this);
  a2[1] = v5;
  a2[2] = v4;
  a2[3] = v3;
  return result;
}
