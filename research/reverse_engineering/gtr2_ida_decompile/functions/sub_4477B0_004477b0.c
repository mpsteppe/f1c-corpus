long double __stdcall sub_4477B0(float a1)
{
  long double v1; // st7

  v1 = fabs(a1) - flt_91BCA4 * 0.5;
  if ( v1 >= 0.0 )
  {
    if ( v1 > 6.0 )
      v1 = 6.0;
  }
  else
  {
    v1 = 0.0;
  }
  return cos(v1 * 0.52359879) * 0.029999999 + 0.97000003;
}
