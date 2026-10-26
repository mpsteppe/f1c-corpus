// f1c  0x004d7c10  size=167
int __thiscall sub_4D7C10(float *this, float a2)
{
  double v2; // st7
  int i; // edi
  double j; // st6
  int v6; // ecx
  float *v7; // esi
  int k; // edx

  v2 = a2;
  for ( i = -1; v2 < 0.0; v2 = v2 + this[9] )
    ;
  for ( j = this[9]; v2 > j; v2 = v2 - j )
    ;
  if ( v2 > flt_5EA404 )
    return 0;
  v6 = 2;
  v7 = &flt_5EA404;
  for ( k = 324; k >= 320; k -= 4 )
  {
    if ( v2 > *v7 )
      break;
    i = v6--;
    --v7;
  }
  return i;
}
