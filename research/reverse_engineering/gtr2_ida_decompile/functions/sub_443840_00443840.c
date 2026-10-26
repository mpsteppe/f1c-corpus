void __thiscall sub_443840(double *this, double a2)
{
  double v2; // st7
  double v3; // st7
  double v4; // st7
  double v5; // [esp+4h] [ebp+4h]
  double v6; // [esp+4h] [ebp+4h]

  this[909] = a2 * 0.23 + this[909];
  this[912] = a2 * 0.18 + this[912];
  v5 = this[1078] + 0.25;
  v2 = this[1078];
  if ( v2 <= this[909] )
  {
    if ( this[909] <= v5 )
      goto LABEL_5;
    v2 = v5;
  }
  this[909] = v2;
LABEL_5:
  v6 = this[1079] + 0.2;
  v3 = this[1079];
  if ( v3 > this[912] )
  {
LABEL_8:
    this[912] = v3;
    goto LABEL_9;
  }
  if ( this[912] > v6 )
  {
    v3 = v6;
    goto LABEL_8;
  }
LABEL_9:
  v4 = this[1077];
  this[991] = v4 * this[911] * v4 + v4 * this[910] + this[909];
  this[1016] = v4 * this[914] * v4 + v4 * this[913] + this[912];
}
