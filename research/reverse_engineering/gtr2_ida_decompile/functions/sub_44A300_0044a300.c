double __thiscall sub_44A300(double *this)
{
  double v2; // st7
  double v3; // st7
  double v4; // [esp+8h] [ebp-8h]

  if ( this[57] >= 4.4 )
    return 58.5;
  if ( this[57] <= 0.0 )
    return 0.0;
  v2 = this[57] - 0.4;
  if ( v2 < 0.0 )
    v2 = 0.0;
  v4 = v2 * 0.25;
  if ( this[57] >= 4.0 )
    v3 = 4.0;
  else
    v3 = this[57];
  return (sub_44A210(this) * (v3 * 0.25 - v4) + v4) * 58.5;
}
