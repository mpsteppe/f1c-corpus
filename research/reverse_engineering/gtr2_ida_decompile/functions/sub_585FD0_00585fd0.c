double __thiscall sub_585FD0(int this, long double a2)
{
  long double v3; // st7

  if ( *(_BYTE *)(this + 1577) && a2 == 0.0 )
    return 0.0;
  v3 = a2;
  if ( !*(_BYTE *)(this + 1576) )
    v3 = pow(a2, *(double *)(this + 1600)) * *(double *)(this + 1592);
  return v3 + *(double *)(this + 1584);
}
