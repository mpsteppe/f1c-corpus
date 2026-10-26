int __thiscall sub_459A40(double *this, float *a2, float *a3)
{
  double v3; // st7
  double v4; // st6
  double v6; // st7
  double v7; // st6
  float v9; // [esp+8h] [ebp-34h]
  double v10[3]; // [esp+Ch] [ebp-30h] BYREF
  double v11; // [esp+2Ch] [ebp-10h]
  double v12; // [esp+34h] [ebp-8h]
  float v13; // [esp+40h] [ebp+4h]
  float v14; // [esp+44h] [ebp+8h]

  v3 = a2[2];
  v4 = a2[11] * v3;
  v11 = a2[12] * v3;
  v12 = a2[13] * v3;
  v10[0] = v4 + this[27];
  v6 = v10[0];
  v7 = v11 + this[28];
  v10[1] = v7;
  v10[2] = v12 + this[29];
  qmemcpy(this + 27, v10, 0x18u);
  v13 = v6;
  *a3 = v13;
  v9 = v7;
  a3[1] = v9;
  v14 = v10[2];
  a3[2] = v14;
  return sub_54B3B0(LODWORD(v13), LODWORD(v9), LODWORD(v14));
}
