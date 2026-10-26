double __thiscall sub_4E8B80(float *this, float a2, float a3, float a4)
{
  double v4; // st7
  double v6; // st7
  int v7; // eax
  double v8; // st7
  double v9; // st7
  double v10; // st7
  double v12; // st7
  long double v13; // st6
  float v14; // [esp+Ch] [ebp-14h]
  float v15; // [esp+Ch] [ebp-14h]
  float v16; // [esp+10h] [ebp-10h]
  int v17; // [esp+10h] [ebp-10h]
  float v18; // [esp+14h] [ebp-Ch]
  float v19; // [esp+1Ch] [ebp-4h]

  v4 = a2 * a2;
  v19 = v4;
  v14 = v4;
  v6 = (v4 * this[3740] - (v14 * 0.0 - 9.8100004) * this[3397]) * this[3839];
  v18 = v6;
  sub_5895A2(v6);
  v16 = v6;
  v7 = (int)v16;
  v17 = v7;
  if ( v7 >= 0 )
  {
    if ( v7 >= 14 )
    {
      v7 = 13;
      v17 = 13;
    }
    v9 = this[v7 + 3840];
    v8 = v9 + (this[v7 + 3841] - v9) * (v18 - (double)v17);
  }
  else
  {
    v8 = this[3840];
  }
  v10 = v8 * this[3398];
  if ( v10 > this[3919] )
    v10 = this[3919];
  v15 = this[3921] * this[3398] * v14 + v10;
  if ( v15 > 0.0 )
  {
    v12 = v15 * -0.5;
    v13 = v19 - -a3 * v12 * 4.0;
    if ( v13 > 0.0 )
      return a2 - (sqrt(v13) - a2) / (v12 + v12) * v15 * a4;
    else
      return 0.0;
  }
  else if ( a2 >= 1.0 )
  {
    return a2;
  }
  else
  {
    return 0.0;
  }
}
