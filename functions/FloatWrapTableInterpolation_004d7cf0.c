double __thiscall sub_4D7CF0(float *this, float a2, int *a3)
{
  double v3; // st7
  double v5; // st6
  int v6; // eax
  double result; // st7

  v3 = a2;
  if ( a2 < 0.0 )
  {
    do
      v3 = v3 + this[9];
    while ( v3 < 0.0 );
    a2 = v3;
  }
  v5 = this[9];
  if ( v3 > v5 )
  {
    do
      v3 = v3 - v5;
    while ( v3 > v5 );
    a2 = v3;
  }
  v6 = FloatRangeIndexLookup(this, a2);
  result = (a2 - this[v6 + 6]) / (this[v6 + 9] - this[v6 + 6]);
  if ( a3 )
    *a3 = v6;
  return result;
}
