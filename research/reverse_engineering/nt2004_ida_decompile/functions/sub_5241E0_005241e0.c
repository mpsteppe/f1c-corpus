double __thiscall sub_5241E0(int this, long double a2)
{
  long double v2; // st7

  v2 = a2;
  if ( !*(_BYTE *)(this + 1472) )
    v2 = pow(a2, *(double *)(this + 1516)) * *(double *)(this + 1508);
  return v2 + *(double *)(this + 1500);
}
