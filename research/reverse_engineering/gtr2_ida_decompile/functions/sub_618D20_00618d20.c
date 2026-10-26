void __thiscall sub_618D20(double *this)
{
  double v1; // st7
  double v2; // st6
  double v3; // st5
  double v4; // [esp+18h] [ebp-30h]
  double v5; // [esp+20h] [ebp-28h]
  double v6; // [esp+28h] [ebp-20h]
  double v7; // [esp+30h] [ebp-18h]
  double v8; // [esp+38h] [ebp-10h]
  double v9; // [esp+40h] [ebp-8h]

  v1 = this[4] * this[27];
  v2 = this[28] * this[5];
  v3 = this[6] * this[29];
  v4 = this[7] * this[27];
  v5 = this[28] * this[8];
  v6 = this[29] * this[9];
  v7 = this[10] * this[27];
  v8 = this[28] * this[11];
  v9 = this[29] * this[12];
  this[30] = v3 * this[6] + v1 * this[4] + v2 * this[5];
  this[31] = v3 * this[9] + v2 * this[8] + v1 * this[7];
  this[32] = v3 * this[12] + v2 * this[11] + v1 * this[10];
  this[33] = this[31];
  this[34] = v6 * this[9] + v5 * this[8] + v4 * this[7];
  this[35] = v6 * this[12] + v5 * this[11] + v4 * this[10];
  this[36] = this[32];
  this[37] = this[35];
  this[38] = v9 * this[12] + v8 * this[11] + v7 * this[10];
}
