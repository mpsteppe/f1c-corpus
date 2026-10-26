float *__thiscall sub_577430(float *this, float *a2, int a3, float *a4)
{
  double v5; // st7
  float v6; // eax
  double v7; // st6
  double v8; // st7
  float *result; // eax
  double v10; // st7
  float v11; // [esp+4h] [ebp-48h]
  float v12; // [esp+4h] [ebp-48h]
  float v13; // [esp+8h] [ebp-44h]
  float v14; // [esp+8h] [ebp-44h]
  float v15; // [esp+Ch] [ebp-40h]
  float v16; // [esp+Ch] [ebp-40h]
  int v17; // [esp+10h] [ebp-3Ch] BYREF
  float v18; // [esp+14h] [ebp-38h]
  float v19; // [esp+18h] [ebp-34h]
  float v20[3]; // [esp+1Ch] [ebp-30h] BYREF
  float v21[9]; // [esp+28h] [ebp-24h] BYREF

  sub_614A90(a3, v21);
  v5 = this[4104] - this[4136];
  v6 = this[699];
  v7 = this[4041] - this[4073];
  this += 3993;
  v18 = (v5 + v7) * 0.5;
  v17 = 0;
  v19 = v6;
  sub_416420(v21, this, (float *)&v17, v20);
  v11 = *this + *a2;
  v13 = this[1] + a2[1];
  v8 = this[2];
  v18 = v13;
  result = a4;
  v15 = v8 + a2[2];
  v19 = v15;
  v12 = v11 - v20[0];
  *a4 = v12;
  v14 = v13 - v20[1];
  v10 = v19;
  a4[1] = v14;
  v16 = v10 - v20[2];
  a4[2] = v16;
  return result;
}
