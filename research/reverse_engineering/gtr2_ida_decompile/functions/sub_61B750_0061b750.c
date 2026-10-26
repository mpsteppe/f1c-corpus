int __thiscall sub_61B750(double *this)
{
  double v2; // st7
  double v3; // st6
  double v4; // st7
  int v5; // ecx
  int v6; // ecx
  int v7; // ecx
  double v9; // [esp+8h] [ebp-30h] BYREF
  double v10; // [esp+10h] [ebp-28h]
  double v11; // [esp+18h] [ebp-20h]
  double v12[2]; // [esp+20h] [ebp-18h] BYREF
  double v13; // [esp+30h] [ebp-8h]

  v2 = this[21] * this[17] - this[20] * this[18];
  v3 = this[18] * this[19] - this[21] * this[16];
  v13 = this[20] * this[16] - this[17] * this[19];
  v9 = this[42] - v2;
  v10 = this[43] - v3;
  v11 = this[44] - v13;
  sub_46FE60(this, &v9, v12);
  v4 = this[23];
  v9 = v4 * this[39];
  v10 = v4 * this[40];
  v11 = v4 * this[41];
  sub_619B50((int)this, v12, &v9);
  sub_619D80((int)this, v12);
  sub_61A080((int)this, v12, &v9);
  sub_61A2A0(v5);
  sub_61AE30(v6);
  return sub_61B360(v7);
}
