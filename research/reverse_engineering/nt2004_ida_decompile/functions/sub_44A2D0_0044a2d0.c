double __thiscall sub_44A2D0(double *this)
{
  double v2; // st7
  double v3; // [esp+0h] [ebp-10h]

  if ( *(double *)((char *)this + 428) >= 4.4 )
    return 58.5;
  if ( *(double *)((char *)this + 428) <= 0.0 )
    return 0.0;
  v2 = *(double *)((char *)this + 428) - 0.4;
  if ( v2 < 0.0 )
    v2 = 0.0;
  if ( *(double *)((char *)this + 428) >= 4.0 )
    v3 = 4.0;
  else
    v3 = *(double *)((char *)this + 428);
  return (sub_44A1D0(this) * (v3 * 0.25 - v2 * 0.25) + v2 * 0.25) * 58.5;
}
