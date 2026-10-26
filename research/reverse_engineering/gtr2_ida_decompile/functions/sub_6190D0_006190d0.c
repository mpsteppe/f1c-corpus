double *__thiscall sub_6190D0(double *this, double *a2, double *a3)
{
  double v3; // st7
  double v4; // rt1
  double v6; // [esp+8h] [ebp-10h]
  double v7; // [esp+10h] [ebp-8h]
  double v8; // [esp+10h] [ebp-8h]

  v3 = this[23];
  v6 = v3 * a2[1];
  v7 = v3 * a2[2];
  this[13] = v3 * *a2 + this[13];
  this[14] = v6 + this[14];
  this[15] = v7 + this[15];
  v8 = *a2 * a3[1] - a2[1] * *a3;
  v4 = a2[2] * *a3 - a3[2] * *a2;
  this[19] = a2[1] * a3[2] - a2[2] * a3[1] + this[19];
  this[20] = v4 + this[20];
  this[21] = v8 + this[21];
  return sub_46FE60(this, this + 19, this + 16);
}
