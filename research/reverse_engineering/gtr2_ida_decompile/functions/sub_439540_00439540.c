BOOL __thiscall sub_439540(
        double *this,
        long double a2,
        double a3,
        double a4,
        double *a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  double v13; // st7
  double v15; // st5
  long double v16; // st3
  long double v17; // st3
  long double v18; // st6
  double v20; // [esp+14h] [ebp+14h]
  double v21; // [esp+20h] [ebp+20h]
  double v22; // [esp+30h] [ebp+30h]
  double v23; // [esp+38h] [ebp+38h]

  v13 = a3 * a6;
  *this = a3 * a6;
  v15 = a8 * a4;
  v21 = a8 * a4;
  this[1] = v21;
  v20 = a4 * a9;
  this[2] = v20;
  v16 = a2 * a5[6];
  this[3] = v16;
  this[4] = (v20 - v15) * v16;
  v22 = a10 * a4;
  this[5] = v22;
  v23 = a4 * a11;
  this[6] = v23;
  v17 = a2 * a5[7];
  this[7] = v17;
  this[8] = (v23 - v22) * v17;
  this[9] = a3 * a5[2];
  this[10] = a3 * a5[3];
  this[11] = a4 * a5[4];
  this[12] = a4 * a5[5];
  v18 = 1.0 / sqrt(a2);
  this[13] = (a12 + *a5 + a13 - a7) * v18;
  this[14] = (a12 + a5[1] + a13) * v18;
  return v13 != 0.0
      || v21 != 0.0
      || v20 != 0.0
      || v22 != 0.0
      || v23 != 0.0
      || this[9] != 0.0
      || this[10] != 0.0
      || this[11] != 0.0
      || this[12] != 0.0;
}
