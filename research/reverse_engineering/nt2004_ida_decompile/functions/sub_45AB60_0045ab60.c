int __thiscall sub_45AB60(int this, float *a2, float *a3)
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
  v4 = a2[15] * v3;
  v11 = a2[16] * v3;
  v12 = a2[17] * v3;
  v10[0] = v4 + *(double *)(this + 220);
  v6 = v10[0];
  v7 = v11 + *(double *)(this + 228);
  v10[1] = v7;
  v10[2] = v12 + *(double *)(this + 236);
  qmemcpy((void *)(this + 220), v10, 0x18u);
  v13 = v6;
  *a3 = v13;
  v9 = v7;
  a3[1] = v9;
  v14 = v10[2];
  a3[2] = v14;
  return sub_59E050(LODWORD(v13), LODWORD(v9), LODWORD(v14));
}
