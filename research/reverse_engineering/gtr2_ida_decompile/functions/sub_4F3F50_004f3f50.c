int __thiscall sub_4F3F50(float *this)
{
  double v1; // st7
  double v2; // st5
  float v3; // edx
  float v4; // eax
  long double v5; // st6
  long double v6; // st7
  double v7; // st6
  long double v8; // st5
  long double v9; // st5
  int result; // eax
  float v11; // [esp+0h] [ebp-28h]
  float v12; // [esp+4h] [ebp-24h]
  float v13; // [esp+4h] [ebp-24h]
  float v14; // [esp+8h] [ebp-20h]
  float v15; // [esp+Ch] [ebp-1Ch]
  float v16; // [esp+Ch] [ebp-1Ch]
  float v17; // [esp+10h] [ebp-18h]
  float v18; // [esp+10h] [ebp-18h]
  float v19; // [esp+14h] [ebp-14h]
  float v20; // [esp+18h] [ebp-10h]
  float v21; // [esp+18h] [ebp-10h]
  float v22; // [esp+24h] [ebp-4h]
  float v23; // [esp+24h] [ebp-4h]

  v1 = *this;
  v22 = this[2];
  v2 = this[1];
  v3 = this[5];
  v12 = this[4];
  v15 = this[6];
  v4 = this[9];
  v17 = this[8];
  v20 = this[10];
  v5 = 1.0 / sqrt(v22 * v22 + v2 * v2 + v1 * v1);
  v11 = v5;
  v6 = v1 * v5;
  v7 = v2 * v11;
  v23 = v22 * v11;
  v8 = 1.0 / sqrt(v15 * v15 + v3 * v3 + v12 * v12);
  v13 = v12 * v8;
  v14 = v3 * v8;
  v16 = v15 * v8;
  v9 = 1.0 / sqrt(v20 * v20 + v4 * v4 + v17 * v17);
  v18 = v17 * v9;
  v19 = v4 * v9;
  v21 = v20 * v9;
  this[2] = v23;
  this[4] = v13;
  *this = v6;
  this[5] = v14;
  this[1] = v7;
  this[6] = v16;
  this[8] = v18;
  result = LODWORD(v21);
  this[9] = v19;
  this[10] = v21;
  return result;
}
