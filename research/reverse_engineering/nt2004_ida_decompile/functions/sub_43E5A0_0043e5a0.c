void __thiscall sub_43E5A0(double *this, double a2)
{
  *(double *)((char *)this + 7900) = a2;
  this[912] = a2 * *(double *)((char *)this + 6668) * a2
            + a2 * *(double *)((char *)this + 6660)
            + *(double *)((char *)this + 6652);
  this[937] = a2 * *(double *)((char *)this + 6692) * a2
            + a2 * *(double *)((char *)this + 6684)
            + *(double *)((char *)this + 6676);
}
