void __thiscall StoreNegatedAbsoluteValues(float *this, float a2, float a3)
{
  double v3; // st7
  double v4; // st6

  v3 = a2;
  if ( a2 < 0.0 )
    v3 = -v3;
  v4 = a3;
  if ( a3 < 0.0 )
    v4 = -v4;
  this[799] = -v3;
  this[800] = -v4;
}

