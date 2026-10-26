void __thiscall sub_579B50(float *this, float a2, int a3)
{
  long double v3; // st7
  long double v4; // st6
  double v5; // st5
  double v6; // st4
  double v7; // st5
  double v8; // st4
  double v9; // st5
  double v10; // st4
  long double v11; // st7

  v3 = sin(a2);
  v4 = cos(a2);
  v5 = this[1];
  v6 = this[2];
  this[1] = v5 * v4 + v6 * v3;
  this[2] = v6 * v4 - v5 * v3;
  v7 = this[4];
  v8 = this[5];
  this[4] = v7 * v4 + v8 * v3;
  this[5] = v8 * v4 - v7 * v3;
  v9 = this[7];
  v10 = this[8];
  this[7] = v9 * v4 + v10 * v3;
  this[8] = v10 * v4 - v9 * v3;
  *(float *)a3 = -asin(this[5]);
  if ( fabs(this[5]) == 1.0 )
  {
    v11 = atan2(-this[6], *this);
    *(_DWORD *)(a3 + 8) = 0;
    *(float *)(a3 + 4) = v11;
  }
  else
  {
    *(float *)(a3 + 4) = atan2(this[2], this[8]);
    *(float *)(a3 + 8) = atan2(this[3], this[4]);
  }
}
