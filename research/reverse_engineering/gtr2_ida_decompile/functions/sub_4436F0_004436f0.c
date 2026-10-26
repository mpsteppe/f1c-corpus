void __thiscall sub_4436F0(double *this, double a2)
{
  double v2; // st7
  double v3; // st7
  double v4; // st7
  double v5; // [esp+4h] [ebp+4h]
  double v6; // [esp+4h] [ebp+4h]

  this[915] = a2 * 0.23 + this[915];
  this[917] = a2 * 0.18 + this[917];
  v5 = this[1074] + 0.25;
  v2 = this[1074];
  if ( v2 <= this[915] )
  {
    if ( this[915] <= v5 )
      goto LABEL_5;
    v2 = v5;
  }
  this[915] = v2;
LABEL_5:
  v6 = this[1075] + 0.2;
  v3 = this[1075];
  if ( v3 > this[917] )
  {
LABEL_8:
    this[917] = v3;
    goto LABEL_9;
  }
  if ( this[917] > v6 )
  {
    v3 = v6;
    goto LABEL_8;
  }
LABEL_9:
  v4 = this[1073];
  this[1043] = v4 * this[916] + this[915];
  this[1020] = v4 * this[918] + this[917];
  this[1123] = v4 * this[920] + this[919];
}
