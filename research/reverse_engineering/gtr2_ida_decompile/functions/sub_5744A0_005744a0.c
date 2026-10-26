void __thiscall sub_5744A0(float *this)
{
  double v1; // st7
  double v2; // st7
  double v4; // st6
  unsigned __int8 v5; // c0
  unsigned __int8 v6; // c2
  double v7; // st7
  double v8; // st6
  double v9; // st7
  double v10; // st6
  float v11; // [esp+4h] [ebp-4h]

  this[4] = this[24] + this[13];
  if ( this[12] <= 0.0 )
    v1 = this[22] + this[21];
  else
    v1 = this[21] - this[22];
  v11 = v1 * this[27];
  if ( v11 == 0.0 )
  {
    v2 = 0.0;
LABEL_14:
    this[9] = this[28] * this[12] + this[9];
    this[12] = v2 + this[12];
    goto LABEL_17;
  }
  v2 = v11 * this[28];
  v4 = this[12];
  if ( v5 | v6 )
  {
    if ( v4 < 0.0 || -v2 <= this[12] )
      goto LABEL_14;
  }
  else if ( v4 > 0.0 || -v2 >= this[12] )
  {
    goto LABEL_14;
  }
  v7 = -(this[12] / v11);
  v8 = v7 * this[12];
  this[12] = 0.0;
  this[9] = v8 + this[9];
  v9 = this[28] - v7;
  if ( fabs(this[21]) > this[22] )
  {
    if ( this[21] <= 0.0 )
      v10 = this[22] + this[21];
    else
      v10 = this[21] - this[22];
    this[12] = v9 * this[27] * v10;
  }
LABEL_17:
  if ( fabs(this[9]) > 50.265484 )
    this[9] = fmod(this[9], 6.283185482025146);
}
