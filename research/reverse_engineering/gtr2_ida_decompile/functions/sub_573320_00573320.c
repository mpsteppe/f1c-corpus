double __thiscall sub_573320(float *this, float *a2, float *a3)
{
  float v4; // [esp+4h] [ebp-24h]
  float v5; // [esp+4h] [ebp-24h]
  float v6; // [esp+8h] [ebp-20h]
  float v7; // [esp+8h] [ebp-20h]
  float v8; // [esp+Ch] [ebp-1Ch]
  float v9; // [esp+1Ch] [ebp-Ch]
  float v10; // [esp+1Ch] [ebp-Ch]
  float v11; // [esp+20h] [ebp-8h]
  float v12; // [esp+20h] [ebp-8h]
  float v13; // [esp+24h] [ebp-4h]
  float v14; // [esp+24h] [ebp-4h]

  v4 = a3[2] * a2[1] - a3[1] * a2[2];
  v6 = *a3 * a2[2] - *a2 * a3[2];
  v8 = *a2 * a3[1] - *a3 * a2[1];
  v9 = v4 * this[4014];
  v5 = v9;
  v11 = v6 * this[4015];
  v7 = v11;
  v13 = v8 * this[4016];
  v10 = v11 * a2[2] - v13 * a2[1];
  v12 = v13 * *a2 - v5 * a2[2];
  v14 = v5 * a2[1] - v7 * *a2;
  return v14 * a3[2] + v12 * a3[1] + v10 * *a3 + this[4010];
}
