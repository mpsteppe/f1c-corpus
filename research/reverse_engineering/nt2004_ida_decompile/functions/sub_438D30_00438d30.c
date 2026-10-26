BOOL __thiscall sub_438D30(
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
  long double v15; // st4
  long double v16; // st3
  long double v17; // st6
  double v19; // [esp+14h] [ebp+14h]
  double v20; // [esp+20h] [ebp+20h]
  double v21; // [esp+30h] [ebp+30h]
  double v22; // [esp+38h] [ebp+38h]

  v20 = a3 * a6;
  *this = v20;
  v13 = a4 * a8;
  this[1] = a4 * a8;
  v19 = a9 * a4;
  this[2] = v19;
  v15 = a2 * a5[6];
  this[3] = v15;
  this[4] = (v19 - v13) * v15;
  v21 = a10 * a4;
  this[5] = v21;
  v22 = a4 * a11;
  this[6] = v22;
  v16 = a2 * a5[7];
  this[7] = v16;
  this[8] = (v22 - v21) * v16;
  this[9] = a3 * a5[2];
  this[10] = a3 * a5[3];
  this[11] = a4 * a5[4];
  this[12] = a4 * a5[5];
  v17 = 1.0 / sqrt(a2);
  this[13] = (a12 + *a5 + a13 - a7) * v17;
  this[14] = (a12 + a5[1] + a13) * v17;
  return v20 != 0.0
      || v13 != 0.0
      || v19 != 0.0
      || v21 != 0.0
      || v22 != 0.0
      || this[9] != 0.0
      || this[10] != 0.0
      || this[11] != 0.0
      || this[12] != 0.0;
}
