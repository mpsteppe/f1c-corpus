float *__thiscall sub_51C9F0(
        float *this,
        float a2,
        float a3,
        float a4,
        float a5,
        float a6,
        float a7,
        float a8,
        float a9,
        float a10)
{
  float *result; // eax
  long double v11; // st4
  float v12; // [esp+0h] [ebp-18h]
  float v13; // [esp+4h] [ebp-14h]
  float v14; // [esp+8h] [ebp-10h]
  float v15; // [esp+Ch] [ebp-Ch]
  float v16; // [esp+Ch] [ebp-Ch]
  float v17; // [esp+10h] [ebp-8h]
  float v18; // [esp+10h] [ebp-8h]
  float v19; // [esp+14h] [ebp-4h]
  float v20; // [esp+14h] [ebp-4h]
  float v21; // [esp+28h] [ebp+10h]
  float v22; // [esp+2Ch] [ebp+14h]
  float v23; // [esp+30h] [ebp+18h]

  result = this;
  v15 = a8 - a2;
  v12 = v15;
  v17 = a9 - a3;
  v13 = v17;
  v19 = a10 - a4;
  v14 = v19;
  v16 = a5 - a2;
  v18 = a6 - a3;
  v20 = a7 - a4;
  v21 = v14 * v18 - v13 * v20;
  this[3] = v21;
  v22 = v20 * v12 - v14 * v16;
  this[4] = v22;
  v23 = v13 * v16 - v18 * v12;
  this[5] = v23;
  v11 = sqrt(this[3] * this[3] + this[4] * this[4] + this[5] * this[5]);
  this[3] = 1.0 / v11 * this[3];
  this[4] = 1.0 / v11 * this[4];
  this[5] = 1.0 / v11 * this[5];
  *this = a2;
  this[1] = a3;
  this[2] = a4;
  this[6] = this[3];
  this[7] = this[4];
  this[8] = this[5];
  this[9] = -(a4 * this[5] + a3 * this[4] + a2 * this[3]);
  return result;
}
