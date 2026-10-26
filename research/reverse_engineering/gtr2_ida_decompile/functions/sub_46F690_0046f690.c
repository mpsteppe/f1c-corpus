int __thiscall sub_46F690(float *this, int a2)
{
  int v3; // eax
  float *v4; // eax
  double v5; // st7
  int result; // eax
  float v7; // [esp+0h] [ebp-24h]
  float v8; // [esp+4h] [ebp-20h]
  float v9; // [esp+8h] [ebp-1Ch]
  float v10; // [esp+10h] [ebp-14h]
  _BYTE v11[4]; // [esp+18h] [ebp-Ch] BYREF
  float *v12; // [esp+1Ch] [ebp-8h] BYREF
  _BYTE v13[4]; // [esp+20h] [ebp-4h] BYREF

  v3 = sub_410A80(&dword_91BF20);
  sub_5E4D90(v3, v11, &v12, v13);
  v4 = v12;
  this += 379;
  this[13] = this[12] / sqrt(v12[2] * v12[2] + *v12 * *v12) * v12[1] - v10;
  v7 = flt_759E30 * *v4;
  v8 = flt_759E30 * v4[1];
  v5 = flt_759E30 * v4[2];
  result = LODWORD(v7);
  *this = v7;
  this[1] = v8;
  v9 = v5;
  this[2] = v9;
  return result;
}
