void __thiscall sub_50F760(float *this)
{
  double v1; // st7
  double v2; // st7
  double v3; // st7
  double v5; // st6
  unsigned __int8 v6; // c0
  unsigned __int8 v7; // c2
  double v8; // st7
  double v9; // st6
  double v10; // st7
  double v11; // st6
  float v12; // [esp+4h] [ebp-4h]

  this[4] = this[24] + this[13];
  if ( this[12] <= 0.0 )
    v1 = this[22] + this[21];
  else
    v1 = this[21] - this[22];
  v2 = v1 * this[27];
  v12 = v2;
  if ( v2 == 0.0 )
  {
    v3 = 0.0;
LABEL_14:
    this[9] = this[28] * this[12] + this[9];
    this[12] = v3 + this[12];
    goto LABEL_17;
  }
  v3 = v12 * this[28];
  v5 = this[12];
  if ( v6 | v7 )
  {
    if ( v5 < 0.0 || -v3 <= this[12] )
      goto LABEL_14;
  }
  else if ( v5 > 0.0 || -v3 >= this[12] )
  {
    goto LABEL_14;
  }
  v8 = -(this[12] / v12);
  v9 = v8 * this[12];
  this[12] = 0.0;
  this[9] = v9 + this[9];
  v10 = this[28] - v8;
  if ( fabs(this[21]) > this[22] )
  {
    if ( this[21] <= 0.0 )
      v11 = this[22] + this[21];
    else
      v11 = this[21] - this[22];
    this[12] = v10 * this[27] * v11;
  }
LABEL_17:
  if ( fabs(this[9]) > 50.265484 )
    this[9] = fmod(this[9], 6.283185307179586);
}
