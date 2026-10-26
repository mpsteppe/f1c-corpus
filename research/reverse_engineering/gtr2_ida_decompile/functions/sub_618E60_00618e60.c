void __thiscall sub_618E60(double *this)
{
  double v1; // st7
  double v2; // st6
  double v3; // [esp+0h] [ebp-30h]

  v3 = (this[10] * this[18] + this[7] * this[17] + this[16] * this[4]) * this[24];
  v1 = (this[5] * this[16] + this[11] * this[18] + this[8] * this[17]) * this[25];
  v2 = (this[6] * this[16] + this[12] * this[18] + this[9] * this[17]) * this[26];
  this[19] = v2 * this[6] + v1 * this[5] + v3 * this[4];
  this[20] = v2 * this[9] + v1 * this[8] + v3 * this[7];
  this[21] = v2 * this[12] + v1 * this[11] + v3 * this[10];
}
