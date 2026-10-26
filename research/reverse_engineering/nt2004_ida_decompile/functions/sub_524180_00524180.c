double __thiscall sub_524180(int this, long double a2)
{
  long double v3; // st7

  if ( *(_BYTE *)(this + 1473) && a2 == 0.0 )
    return 0.0;
  v3 = a2;
  if ( !*(_BYTE *)(this + 1472) )
    v3 = pow(a2, *(double *)(this + 1492)) * *(double *)(this + 1484);
  return v3 + *(double *)(this + 1476);
}
