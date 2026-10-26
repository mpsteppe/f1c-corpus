void __thiscall sub_4439F0(double *this)
{
  double v1; // st7
  double v2; // st7
  double v3; // st7
  double v4; // st7
  double v5; // [esp+0h] [ebp-8h]
  double v6; // [esp+0h] [ebp-8h]
  double v7; // [esp+0h] [ebp-8h]

  v5 = this[1074];
  v1 = v5;
  if ( v5 <= this[915] )
  {
    if ( this[915] <= v5 )
      goto LABEL_5;
    v1 = v5;
  }
  this[915] = v1;
LABEL_5:
  v6 = this[1075];
  v2 = v6;
  if ( v6 <= this[917] )
  {
    if ( this[917] <= v6 )
      goto LABEL_9;
    v2 = v6;
  }
  this[917] = v2;
LABEL_9:
  v3 = this[1073];
  this[1043] = v3 * this[916] + this[915];
  this[1020] = v3 * this[918] + this[917];
  this[1123] = v3 * this[920] + this[919];
  v7 = this[1076];
  v4 = v7;
  if ( v7 <= this[1049] )
  {
    if ( this[1049] <= v7 )
      return;
    v4 = v7;
  }
  this[1049] = v4;
}
