void __thiscall sub_43E520(double *this, double a2)
{
  double v2; // st7

  v2 = a2 - this[713];
  this[713] = a2;
  *(double *)((char *)this + 3684) = v2 * this[714] + *(double *)((char *)this + 3684);
}
