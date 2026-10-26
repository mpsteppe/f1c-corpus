float *__thiscall sub_4F21D0(float *this, float a2, float a3, float a4)
{
  float *result; // eax
  long double v5; // st7
  long double v6; // st6
  long double v7; // st7
  long double v8; // st6
  long double v9; // st6
  long double v10; // st5
  float v11; // [esp+0h] [ebp-Ch]
  float v12; // [esp+4h] [ebp-8h]
  float v13; // [esp+8h] [ebp-4h]
  float v14; // [esp+10h] [ebp+4h]
  float v15; // [esp+14h] [ebp+8h]
  float v16; // [esp+18h] [ebp+Ch]
  float v17; // [esp+18h] [ebp+Ch]

  result = this;
  v5 = a3 * 0.5;
  v6 = a2 * 0.5;
  v16 = a4 * 0.5;
  v14 = cos(v5);
  v15 = sin(v5);
  v11 = cos(v6);
  v7 = sin(v6);
  v8 = cos(v16);
  v17 = sin(v16);
  v13 = v8 * v7;
  v12 = v17 * v11;
  *this = v13 * v14 - v12 * v15;
  v9 = v8 * v11;
  v10 = v17 * v7;
  this[1] = v14 * v10 + v9 * v15;
  this[2] = v12 * v14 - v13 * v15;
  this[3] = v10 * v15 + v9 * v14;
  return result;
}
