void __thiscall sub_441CA0(double *this, double a2)
{
  double v2; // st7
  double v3; // st7
  double v4; // [esp+0h] [ebp-8h]
  double v5; // [esp+0h] [ebp-8h]

  *(double *)((char *)this + 6652) = a2 * 0.23 + *(double *)((char *)this + 6652);
  *(double *)((char *)this + 6676) = a2 * 0.18 + *(double *)((char *)this + 6676);
  v4 = *(double *)((char *)this + 7908) + 0.25;
  v2 = *(double *)((char *)this + 7908);
  if ( v2 <= *(double *)((char *)this + 6652) )
  {
    if ( *(double *)((char *)this + 6652) > v4 )
      *(double *)((char *)this + 6652) = v4;
  }
  else
  {
    *(double *)((char *)this + 6652) = v2;
  }
  v5 = *(double *)((char *)this + 7916) + 0.2;
  v3 = *(double *)((char *)this + 7916);
  if ( v3 <= *(double *)((char *)this + 6676) )
  {
    if ( *(double *)((char *)this + 6676) > v5 )
      *(double *)((char *)this + 6676) = v5;
  }
  else
  {
    *(double *)((char *)this + 6676) = v3;
  }
  sub_43E5A0(this, *(double *)((char *)this + 7900));
}
