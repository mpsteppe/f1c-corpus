// f1c  0x004f6880  size=44
double __thiscall sub_4F6880(int this, double a2)
{
  double v2; // st7

  v2 = a2;
  if ( !*(_BYTE *)(this + 1388) )
  {
    sub_5881F0(a2);
    v2 = a2 * *(double *)(this + 1424);
  }
  return v2 + *(double *)(this + 1416);
}
