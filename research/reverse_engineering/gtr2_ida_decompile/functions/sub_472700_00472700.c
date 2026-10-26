int __thiscall sub_472700(int *this, int a2)
{
  int v2; // esi
  int i; // edi
  int result; // eax

  v2 = this[201];
  for ( i = 0; i < 8; ++i )
  {
    if ( *(float *)&this[23 * (v2 % 8) + 38] <= 0.0 )
      return v2 % 8;
    ++v2;
  }
  result = this[62] < 0;
  if ( this[85] < result )
    result = 2;
  if ( this[108] < result )
    result = 3;
  if ( this[131] < result )
    result = 4;
  if ( this[154] < result )
    result = 5;
  if ( this[177] < result )
    result = 6;
  if ( this[200] < result )
    result = 7;
  if ( a2 > this[23 * result + 39] )
    return -1;
  return result;
}
