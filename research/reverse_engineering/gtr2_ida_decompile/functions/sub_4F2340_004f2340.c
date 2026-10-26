float *__thiscall sub_4F2340(float *this, float *a2)
{
  double v2; // st7
  double v3; // st6
  double v4; // st6
  double v5; // st5
  double v6; // st5
  double v7; // st4
  double v8; // st3
  float *result; // eax
  float v10; // [esp+8h] [ebp-54h]
  float v11; // [esp+Ch] [ebp-50h]
  float v12; // [esp+10h] [ebp-4Ch]
  float v13; // [esp+14h] [ebp-48h]
  float v14; // [esp+18h] [ebp-44h]
  float v15[16]; // [esp+1Ch] [ebp-40h] BYREF

  v2 = *this * *this;
  v15[3] = 0.0;
  v3 = this[1];
  v15[7] = 0.0;
  v4 = v3 * *this;
  memset(&v15[11], 0, 16);
  v5 = this[1];
  v15[15] = 1.0;
  v12 = v5 * v5;
  v6 = *this * this[2];
  v10 = this[1] * this[2];
  v14 = this[2] * this[2];
  v11 = this[3] * *this;
  v7 = this[1] * this[3];
  v8 = this[3] * this[2];
  v13 = this[3] * this[3];
  v15[0] = v2 - v12 - v14 + v13;
  v15[1] = v8 + v4 + v8 + v4;
  v15[2] = v6 - v7 + v6 - v7;
  v15[4] = v4 - v8 + v4 - v8;
  v15[5] = v12 - v2 - v14 + v13;
  v15[6] = v11 + v10 + v11 + v10;
  v15[8] = v7 + v6 + v7 + v6;
  v15[9] = v10 - v11 + v10 - v11;
  result = a2;
  v15[10] = v13 - (v12 + v2) + v14;
  qmemcpy(a2, v15, 0x40u);
  return result;
}
