int __thiscall sub_561390(float *this, float a2)
{
  double v2; // st7
  int i; // edx
  int k; // ecx
  float j; // [esp+4h] [ebp+4h]

  v2 = a2;
  for ( i = -1; v2 < 0.0; v2 = v2 + this[9] )
    ;
  for ( j = this[9]; v2 > j; v2 = v2 - this[9] )
    ;
  if ( v2 > flt_91BDEC )
    return 0;
  for ( k = 2; k >= 1; --k )
  {
    if ( v2 > flt_91BDE4[k] )
      break;
    i = k;
  }
  return i;
}
