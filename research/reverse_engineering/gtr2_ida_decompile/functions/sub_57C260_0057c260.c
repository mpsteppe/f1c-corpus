void __thiscall sub_57C260(float *this, float a2)
{
  long double v2; // st7
  long double v3; // st7
  double v4; // st7
  double v5; // st7
  double v6; // st7
  double v7; // st7
  float v8; // [esp+0h] [ebp-8h]
  float v9; // [esp+4h] [ebp-4h]

  v9 = flt_FB1F2C + 273.16;
  v8 = fabs(this[4004]);
  v2 = ((fabs(this[4112]) * this[4122] + fabs(this[4049]) * this[4059]) * this[4344] * 0.5
      + (v8 * this[4346] + this[4345]) * (v9 - this[4060]))
     * a2
     + this[4060];
  this[4060] = v2;
  this[4123] = v2;
  v3 = ((fabs(this[4238]) * this[4248] + fabs(this[4175]) * this[4185]) * this[4349] * 0.5
      + (v8 * this[4351] + this[4350]) * (v9 - this[4186]))
     * a2
     + this[4186];
  this[4186] = v3;
  this[4249] = v3;
  v4 = (flt_B71710 * this[4060] - 673.1600000000001) * 0.005;
  if ( v4 >= 0.0 )
  {
    if ( v4 > 1.0 )
      v4 = 1.0;
  }
  else
  {
    v4 = 0.0;
  }
  this[829] = v4;
  v5 = (flt_B71710 * this[4123] - 673.1600000000001) * 0.005;
  if ( v5 >= 0.0 )
  {
    if ( v5 > 1.0 )
      v5 = 1.0;
  }
  else
  {
    v5 = 0.0;
  }
  this[903] = v5;
  v6 = (flt_B71710 * this[4186] - 673.1600000000001) * 0.005;
  if ( v6 >= 0.0 )
  {
    if ( v6 > 1.0 )
      v6 = 1.0;
  }
  else
  {
    v6 = 0.0;
  }
  this[977] = v6;
  v7 = (flt_B71710 * this[4249] - 673.1600000000001) * 0.005;
  if ( v7 >= 0.0 )
  {
    if ( v7 <= 1.0 )
      this[1051] = v7;
    else
      this[1051] = 1.0;
  }
  else
  {
    this[1051] = 0.0;
  }
}
