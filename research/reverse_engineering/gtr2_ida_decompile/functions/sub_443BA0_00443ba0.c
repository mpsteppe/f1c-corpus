void __thiscall sub_443BA0(double *this)
{
  double v1; // st7
  double v2; // st7
  double v3; // st7
  double v4; // [esp+0h] [ebp-8h]
  double v5; // [esp+0h] [ebp-8h]

  v4 = this[1078];
  v1 = v4;
  if ( v4 <= this[909] )
  {
    if ( this[909] <= v4 )
      goto LABEL_5;
    v1 = v4;
  }
  this[909] = v1;
LABEL_5:
  v5 = this[1079];
  v2 = v5;
  if ( v5 > this[912] )
  {
LABEL_8:
    this[912] = v2;
    goto LABEL_9;
  }
  if ( this[912] > v5 )
  {
    v2 = v5;
    goto LABEL_8;
  }
LABEL_9:
  v3 = this[1077];
  this[991] = v3 * this[911] * v3 + v3 * this[910] + this[909];
  this[1016] = v3 * this[914] * v3 + v3 * this[913] + this[912];
}
