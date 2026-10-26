long double *__thiscall sub_56BD40(double *this, long double *a2)
{
  long double *result; // eax
  long double v3; // st7
  long double v4; // st6
  long double v5; // st5
  long double v6; // st4
  long double v7; // st3
  long double v8; // [esp+0h] [ebp-18h]
  long double v9; // [esp+8h] [ebp-10h]
  long double v10; // [esp+10h] [ebp-8h]

  result = a2;
  v3 = sin(*a2);
  v4 = cos(*a2);
  v5 = sin(a2[1]);
  v8 = cos(a2[1]);
  v6 = sin(a2[2]);
  v7 = cos(a2[2]);
  v10 = v7 * v8;
  v9 = v6 * v8;
  *this = v5 * v3 * v6 + v10;
  this[1] = v5 * v3 * v7 - v9;
  this[2] = v5 * v4;
  this[3] = v6 * v4;
  this[4] = v7 * v4;
  this[5] = -v3;
  this[6] = v9 * v3 - v7 * v5;
  this[7] = v6 * v5 + v10 * v3;
  this[8] = v8 * v4;
  return result;
}
