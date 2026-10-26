void __thiscall sub_615180(float *this, float a2, int a3)
{
  long double v3; // st7
  long double v4; // st6
  double v5; // st5
  double v6; // st4
  double v7; // st5
  double v8; // st4
  double v9; // st5
  double v10; // st4

  v3 = sin(a2);
  v4 = cos(a2);
  v5 = *this;
  v6 = this[2];
  *this = v5 * v4 - v6 * v3;
  this[2] = v6 * v4 + v5 * v3;
  v7 = this[3];
  v8 = this[5];
  this[3] = v7 * v4 - v8 * v3;
  this[5] = v8 * v4 + v7 * v3;
  v9 = this[6];
  v10 = this[8];
  this[6] = v9 * v4 - v10 * v3;
  this[8] = v10 * v4 + v9 * v3;
  sub_40D5D0(this, a3);
}
