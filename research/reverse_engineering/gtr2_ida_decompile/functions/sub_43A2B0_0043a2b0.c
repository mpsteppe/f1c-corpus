void __thiscall sub_43A2B0(int this, int a2)
{
  *(long double *)a2 = -asin(*(double *)(this + 40));
  if ( 1.0 == fabs(*(double *)(this + 40)) )
  {
    *(long double *)(a2 + 8) = atan2(-*(double *)(this + 48), *(double *)this);
    *(double *)(a2 + 16) = 0.0;
  }
  else
  {
    *(long double *)(a2 + 8) = atan2(*(double *)(this + 16), *(double *)(this + 64));
    *(long double *)(a2 + 16) = atan2(*(double *)(this + 24), *(double *)(this + 32));
  }
}
