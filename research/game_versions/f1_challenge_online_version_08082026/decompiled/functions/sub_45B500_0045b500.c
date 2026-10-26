int __thiscall sub_45B500(int *this, int a2)
{
  int v2; // esi
  int i; // edi
  int result; // eax
  int v5; // edx
  int *v6; // esi

  v2 = this[199];
  for ( i = 0; i < 8; ++i )
  {
    if ( *(float *)&this[23 * (v2 % 8) + 36] <= 0.0 )
      return v2 % 8;
    ++v2;
  }
  result = 0;
  v5 = 1;
  v6 = this + 60;
  do
  {
    if ( *v6 < result )
      result = v5;
    ++v5;
    v6 += 23;
  }
  while ( v5 < 8 );
  if ( a2 > this[23 * result + 37] )
    return -1;
  return result;
}
