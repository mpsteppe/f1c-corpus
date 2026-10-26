void __thiscall sub_441BB0(double *this, double a2)
{
  double v2; // st7
  double v3; // st7
  double v4; // [esp+0h] [ebp-8h]
  double v5; // [esp+0h] [ebp-8h]

  *(double *)((char *)this + 6700) = a2 * 0.23 + *(double *)((char *)this + 6700);
  *(double *)((char *)this + 6716) = a2 * 0.18 + *(double *)((char *)this + 6716);
  v4 = *(double *)((char *)this + 7876) + 0.25;
  v2 = *(double *)((char *)this + 7876);
  if ( v2 <= *(double *)((char *)this + 6700) )
  {
    if ( *(double *)((char *)this + 6700) > v4 )
      *(double *)((char *)this + 6700) = v4;
  }
  else
  {
    *(double *)((char *)this + 6700) = v2;
  }
  v5 = *(double *)((char *)this + 7884) + 0.2;
  v3 = *(double *)((char *)this + 7884);
  if ( v3 <= *(double *)((char *)this + 6716) )
  {
    if ( *(double *)((char *)this + 6716) > v5 )
      *(double *)((char *)this + 6716) = v5;
  }
  else
  {
    *(double *)((char *)this + 6716) = v3;
  }
  sub_43E5F0(this, *(double *)((char *)this + 7868));
}
