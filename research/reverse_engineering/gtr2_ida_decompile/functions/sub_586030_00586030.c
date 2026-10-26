double __thiscall sub_586030(int this, long double a2)
{
  long double v2; // st7

  v2 = a2;
  if ( !*(_BYTE *)(this + 1576) )
    v2 = pow(a2, *(double *)(this + 1624)) * *(double *)(this + 1616);
  return v2 + *(double *)(this + 1608);
}
