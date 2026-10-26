void __thiscall sub_5670D0(float *this, float a2, float a3)
{
  long double v3; // st7
  long double v4; // st6
  long double v5; // st5
  long double v6; // st4

  v3 = sin(a2);
  this[5] = 0.0;
  v4 = cos(a2);
  v5 = sin(a3);
  v6 = cos(a3);
  *this = v6 * v4;
  this[1] = -(v5 * v4);
  this[2] = v3;
  this[3] = v5;
  this[4] = v6;
  this[6] = -(v6 * v3);
  this[7] = v5 * v3;
  this[8] = v4;
}
