int __thiscall sub_4F2A90(_DWORD *this)
{
  int v2; // eax
  int v3; // eax
  int result; // eax

  v2 = this[25];
  this[24] = 0;
  if ( v2 )
  {
    sub_5BE8AE();
    this[25] = 0;
  }
  v3 = this[28];
  this[27] = 0;
  if ( v3 )
  {
    sub_5BE8AE();
    this[28] = 0;
  }
  result = this[23];
  if ( result )
  {
    result = sub_5B1240(this[23]);
    this[23] = 0;
  }
  return result;
}
