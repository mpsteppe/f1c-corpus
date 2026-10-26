int __thiscall sub_5012C0(float *this, float a2)
{
  double v2; // st6
  double v3; // st7
  double v4; // st6
  int v5; // edx
  float *i; // ecx

  if ( a2 < 0.0 )
  {
    do
    {
      v2 = a2 + this[16];
      a2 = v2;
    }
    while ( v2 < 0.0 );
  }
  v3 = this[16];
  if ( a2 > v3 )
  {
    do
    {
      v4 = a2 - v3;
      a2 = v4;
    }
    while ( v4 > v3 );
  }
  if ( *(_DWORD *)this > 2u || this[12] <= 0.0 )
    return -1;
  if ( a2 < (double)this[12] || a2 >= (double)this[6] )
    return 5;
  v5 = 0;
  for ( i = this + 7; a2 >= (double)*i; ++i )
  {
    if ( ++v5 >= 5 )
      return -1;
  }
  return v5;
}
