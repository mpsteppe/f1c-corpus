void __thiscall sub_5BC5A0(float *this, float *a2)
{
  double v2; // st7
  double v3; // st6
  double v4; // st5
  long double v5; // st5
  long double v6; // st5
  double v7; // st7
  long double v8; // st7
  float v9; // [esp+0h] [ebp-24h]
  float v10; // [esp+4h] [ebp-20h]
  float v11; // [esp+8h] [ebp-1Ch]
  float v12; // [esp+10h] [ebp-14h]
  float v13; // [esp+14h] [ebp-10h]
  float v14; // [esp+14h] [ebp-10h]
  float v15; // [esp+18h] [ebp-Ch]
  float v16; // [esp+28h] [ebp+4h]

  v2 = *a2 - *this;
  v3 = a2[1] - this[1];
  v4 = a2[2] - this[2];
  v11 = v4;
  v5 = v4 * v11 + v3 * v3 + v2 * v2;
  if ( v5 > this[4] )
  {
    v16 = this[3];
    v6 = 1.0 / sqrt(v5);
    v12 = v3 * v6;
    v13 = v11 * v6;
    v14 = v13 * v16;
    v15 = v2 - v2 * v6 * v16;
    v9 = v15 * 0.5;
    v10 = (v3 - v12 * v16) * 0.5;
    v7 = (v11 - v14) * 0.5;
    *this = v9 + *this;
    this[1] = v10 + this[1];
    this[2] = v7 + this[2];
    v8 = sqrt(v7 * v7 + v10 * v10 + v9 * v9) + this[3];
    this[3] = v8;
    this[4] = v8 * v8;
  }
}
