int __thiscall sub_573AD0(float *this, float *a2, float *a3)
{
  int result; // eax
  double v4; // st7
  float v5; // [esp+0h] [ebp-18h]
  float v6; // [esp+0h] [ebp-18h]
  float v7; // [esp+4h] [ebp-14h]
  float v8; // [esp+4h] [ebp-14h]
  float v9; // [esp+8h] [ebp-10h]
  float v10; // [esp+8h] [ebp-10h]

  v5 = a2[2] * this[4006] - a2[1] * this[4007];
  v7 = *a2 * this[4007] - a2[2] * this[4005];
  v9 = a2[1] * this[4005] - *a2 * this[4006];
  v6 = v5 + this[4002];
  v8 = v7 + this[4003];
  result = LODWORD(v8);
  v4 = v9 + this[4004];
  *a3 = v6;
  a3[1] = v8;
  v10 = v4;
  a3[2] = v10;
  return result;
}
