void __thiscall sub_4F25A0(float *this, float a2)
{
  long double v2; // st7
  long double v3; // st6
  double v4; // st5
  double v5; // st4
  double v6; // st5
  double v7; // st4
  double v8; // st5
  double v9; // st4
  double v10; // st5
  double v11; // st4

  v2 = sin(a2);
  v3 = cos(a2);
  v4 = *this;
  v5 = this[1];
  *this = v4 * v3 - v5 * v2;
  this[1] = v5 * v3 + v4 * v2;
  v6 = this[4];
  v7 = this[5];
  this[4] = v6 * v3 - v7 * v2;
  this[5] = v7 * v3 + v6 * v2;
  v8 = this[8];
  v9 = this[9];
  this[8] = v8 * v3 - v9 * v2;
  this[9] = v9 * v3 + v8 * v2;
  v10 = this[12];
  v11 = this[13];
  this[12] = v10 * v3 - v11 * v2;
  this[13] = v11 * v3 + v10 * v2;
}
