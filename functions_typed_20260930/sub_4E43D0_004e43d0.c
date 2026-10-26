void __thiscall sub_4E43D0(float *this)
{
  double v2; // st7
  double v3; // st7
  double v4; // st7
  double v6; // st6
  unsigned __int8 v7; // c0
  unsigned __int8 v8; // c2
  double v9; // st7
  double v10; // st6
  double v11; // st7
  double v12; // st6
  double v13; // st7
  float v14; // [esp+4h] [ebp-4h]

  this[4] = this[24] + this[13];
  if ( this[12] <= 0.0 )
    v2 = this[22] + this[21];
  else
    v2 = this[21] - this[22];
  v3 = v2 * this[27];
  v14 = v3;
  if ( v3 == 0.0 )
  {
    v4 = 0.0;
LABEL_14:
    this[9] = this[28] * this[12] + this[9];
    this[12] = v4 + this[12];
    goto LABEL_17;
  }
  v4 = v14 * this[28];
  v6 = this[12];
  if ( v7 | v8 )
  {
    if ( v6 < 0.0 || -v4 <= this[12] )
      goto LABEL_14;
  }
  else if ( v6 > 0.0 || -v4 >= this[12] )
  {
    goto LABEL_14;
  }
  v9 = -(this[12] / v14);
  v10 = v9 * this[12];
  this[12] = 0.0;
  this[9] = v10 + this[9];
  v11 = this[28] - v9;
  if ( fabs(this[21]) > this[22] )
  {
    if ( this[21] <= 0.0 )
      v12 = this[22] + this[21];
    else
      v12 = this[21] - this[22];
    this[12] = v11 * this[27] * v12;
  }
LABEL_17:
  if ( fabs(this[9]) > 50.265484 )
  {
    v13 = this[9];
    InterruptDispatch(v13);
    this[9] = v13;
  }
}

