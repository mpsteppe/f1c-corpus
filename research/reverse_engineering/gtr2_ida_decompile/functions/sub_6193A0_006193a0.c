double *__thiscall sub_6193A0(double *this, double *a2, double *a3)
{
  double *result; // eax
  double v4; // st7
  double v5; // st6
  double v6; // st5
  double v7; // st7
  double v8; // [esp+8h] [ebp-10h]

  result = a3;
  this[39] = *a3 + this[39];
  this[40] = a3[1] + this[40];
  this[41] = a3[2] + this[41];
  v4 = *a2 - this[1];
  v5 = a2[1] - this[2];
  v6 = a2[2] - this[3];
  v8 = v6 * *result - v4 * result[2];
  v7 = v4 * result[1] - v5 * *result;
  this[42] = v5 * a3[2] - v6 * a3[1] + this[42];
  this[43] = v8 + this[43];
  this[44] = v7 + this[44];
  return result;
}
