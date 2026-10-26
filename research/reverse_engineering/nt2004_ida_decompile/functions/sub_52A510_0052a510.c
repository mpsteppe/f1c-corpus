int __thiscall sub_52A510(_DWORD *this)
{
  _DWORD *v2; // eax
  int v3; // ecx
  int result; // eax

  this[17] = -1;
  *this = 0;
  v2 = this + 4;
  v3 = 3;
  do
  {
    *v2 = 0;
    v2 += 4;
    --v3;
  }
  while ( v3 );
  if ( this[19] )
    sub_5BE8AE();
  result = this[32];
  this[18] = 0;
  this[19] = 0;
  *((_BYTE *)this + 80) = 0;
  this[28] = 0;
  if ( result )
    result = sub_5BE8AE();
  this[31] = 0;
  this[32] = 0;
  *((_BYTE *)this + 132) = 0;
  this[41] = 0;
  return result;
}
