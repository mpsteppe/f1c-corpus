// f1c  0x004ed380  size=157
double __thiscall sub_4ED380(float *this, float *a2, float *a3)
{
  double v3; // st7
  double v4; // st6
  float v6; // [esp+0h] [ebp-18h]
  float v7; // [esp+4h] [ebp-14h]
  float v8; // [esp+8h] [ebp-10h]
  float v9; // [esp+Ch] [ebp-Ch]

  v8 = *a2 * a3[1] - *a3 * a2[1];
  v9 = (a3[2] * a2[1] - a3[1] * a2[2]) * this[3402];
  v3 = (*a3 * a2[2] - *a2 * a3[2]) * this[3403];
  v4 = v8 * this[3404];
  v6 = v3 * a2[2] - v4 * a2[1];
  v7 = v4 * *a2 - v9 * a2[2];
  return (v9 * a2[1] - v3 * *a2) * a3[2] + v7 * a3[1] + v6 * *a3 + this[3398];
}
