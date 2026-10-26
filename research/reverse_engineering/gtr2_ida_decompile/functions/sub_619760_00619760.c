double __thiscall sub_619760(double *this, double a2)
{
  double v3; // st7
  double v4; // st4
  double v5; // st3
  long double v6; // st7
  long double v7; // st6
  long double v8; // st7
  double v9; // st7
  double v10; // st4
  double v11; // st3
  double v12; // st4
  double v13; // st3
  long double v14; // st7
  long double v15; // st6
  double v16; // st5
  double v17; // st4
  long double v18; // st7
  long double v19; // st7
  double v20; // st6
  double v21; // st7
  double *v22; // eax
  double v24; // [esp+8h] [ebp-30h]
  double v25; // [esp+10h] [ebp-28h]
  double v26[3]; // [esp+20h] [ebp-18h] BYREF

  v24 = 1.0;
  v3 = this[39] - this[63];
  v4 = this[41] - this[65];
  v5 = this[40] - this[64];
  v6 = v4 * v4 + v5 * v5 + v3 * v3;
  v7 = this[63] * this[63] + this[64] * this[64] + this[65] * this[65];
  if ( v6 > 0.25 * v7 )
  {
    v8 = sqrt(v6) / (sqrt(v7) + this[22] * 128.0);
    if ( v8 > 0.5 )
    {
      v9 = 0.5 / v8;
      if ( v9 < 1.0 )
        v24 = v9;
    }
  }
  v10 = this[44] - this[68];
  v11 = this[43] - this[67];
  v12 = v10 * v10 + v11 * v11;
  v13 = this[42] - this[66];
  v14 = v12 + v13 * v13;
  v15 = this[66] * this[66] + this[67] * this[67] + this[68] * this[68];
  if ( v14 > 0.25 * v15 )
  {
    v16 = this[26];
    v17 = this[25];
    v25 = this[24];
    if ( v25 >= v17 )
    {
      if ( v17 < v16 )
        v16 = v17;
    }
    else if ( v25 < v16 )
    {
      v16 = v25;
    }
    v18 = sqrt(v14) / (sqrt(v15) + v16 * 128.0);
    if ( v18 > 0.5 )
    {
      v19 = 0.5 / v18;
      if ( v19 < v24 )
        v24 = v19;
    }
  }
  this[1] = a2 * this[13] + this[45];
  this[2] = a2 * this[14] + this[46];
  this[3] = a2 * this[15] + this[47];
  v20 = a2 * this[23];
  this[13] = v20 * this[39] + this[57];
  this[14] = v20 * this[40] + this[58];
  this[15] = v20 * this[41] + this[59];
  v26[0] = a2 * this[16];
  v26[1] = a2 * this[17];
  v21 = a2 * this[18];
  qmemcpy(this + 4, this + 48, 0x48u);
  v26[2] = v21;
  sub_61BAD0(v26);
  this[19] = a2 * this[42] + this[60];
  this[20] = a2 * this[43] + this[61];
  this[21] = a2 * this[44] + this[62];
  sub_618D20(this);
  sub_46FE60(this, v22, this + 16);
  return v24;
}
