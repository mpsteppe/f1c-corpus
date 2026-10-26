void __thiscall sub_567400(float *this, float a2, int a3)
{
  long double v3; // st7
  long double v5; // st6
  double v6; // st5
  double v7; // st4
  double v8; // st5
  double v9; // st4
  double v10; // st5
  double v11; // st4
  double v12; // st7
  long double v13; // st7

  v3 = sin(a2);
  v5 = cos(a2);
  v6 = *this;
  v7 = this[2];
  *this = v6 * v5 - v7 * v3;
  this[2] = v7 * v5 + v6 * v3;
  v8 = this[3];
  v9 = this[5];
  this[3] = v8 * v5 - v9 * v3;
  this[5] = v9 * v5 + v8 * v3;
  v10 = this[6];
  v11 = this[8];
  this[6] = v10 * v5 - v11 * v3;
  this[8] = v11 * v5 + v10 * v3;
  v12 = this[5];
  sub_588570(this);
  *(float *)a3 = -v12;
  if ( fabs(this[5]) == 1.0 )
  {
    v13 = atan2(-this[6], *this);
    *(_DWORD *)(a3 + 8) = 0;
    *(float *)(a3 + 4) = v13;
  }
  else
  {
    *(float *)(a3 + 4) = atan2(this[2], this[8]);
    *(float *)(a3 + 8) = atan2(this[3], this[4]);
  }
}
