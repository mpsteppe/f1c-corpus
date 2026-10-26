void __thiscall sub_593730(float *this, float a2, float a3, float a4)
{
  double v4; // st7
  long double v5; // st7
  int v6; // [esp+0h] [ebp-24h]
  int v7; // [esp+4h] [ebp-20h]
  float v8; // [esp+8h] [ebp-1Ch]
  float v9; // [esp+14h] [ebp-10h]
  float v10; // [esp+1Ch] [ebp-8h]
  float v11; // [esp+20h] [ebp-4h]
  float v12; // [esp+28h] [ebp+4h]
  float v13; // [esp+28h] [ebp+4h]
  float v14; // [esp+2Ch] [ebp+8h]
  float v15; // [esp+30h] [ebp+Ch]

  v10 = this[9] - a2;
  v12 = this[10] - a3;
  v4 = this[11] - a4;
  v14 = v4;
  v5 = sqrt(v4 * v14 + v12 * v12 + v10 * v10);
  if ( v5 != 0.0 )
  {
    v15 = 1.0 / v5;
    v11 = -asin(v15 * v12);
    v13 = atan2(v15 * v14, v15 * v10) + 1.5707964;
    this[12] = -v11;
    this[13] = -v13;
    v9 = -this[14];
    v8 = this[11] - this[17];
    *(float *)&v7 = this[10] - this[16];
    *(float *)&v6 = this[9] - this[15];
    sub_5934A0(v6, v7, v8, v11, v13, v9);
  }
}
