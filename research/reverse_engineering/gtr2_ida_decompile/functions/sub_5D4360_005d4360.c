float *__thiscall sub_5D4360(float *this, float *a2)
{
  long double v2; // st7
  double v3; // st6
  long double v6; // st6
  float *result; // eax
  long double v8; // st5
  long double v9; // st4
  long double v10; // st6
  float v11; // [esp+0h] [ebp-4h]

  v2 = sqrt(*this * *this + this[1] * this[1] + this[2] * this[2]);
  v3 = this[3] * 1.442695040888963407;
  _ST5 = v3;
  __asm { frndint }
  v11 = __FSCALE__(__F2XM1__(v3 - _ST5) + 1.0, _ST5);
  if ( v2 < 0.00001 )
    v6 = 0.0;
  else
    v6 = sin(v2) / v2 * v11;
  result = a2;
  v8 = v6 * this[2];
  v9 = v6;
  v10 = v6 * this[1];
  *a2 = v9 * *this;
  a2[1] = v10;
  a2[2] = v8;
  a2[3] = cos(v2) * v11;
  return result;
}
