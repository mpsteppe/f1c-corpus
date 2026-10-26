int __thiscall sub_45C7A0(int *this, int a2)
{
  int v2; // esi
  int i; // edi
  int result; // eax
  int v5; // edx
  int *v6; // esi

  v2 = this[297];
  for ( i = 0; i < 8; ++i )
  {
    if ( *(float *)&this[35 * (v2 % 8) + 50] <= 0.0 )
      return v2 % 8;
    ++v2;
  }
  result = 0;
  v5 = 1;
  v6 = this + 86;
  do
  {
    if ( *v6 < result )
      result = v5;
    ++v5;
    v6 += 35;
  }
  while ( v5 < 8 );
  if ( a2 > this[35 * result + 51] )
    return -1;
  return result;
}
