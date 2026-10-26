int __thiscall sub_57BCB0(_DWORD *this)
{
  int v2; // eax
  int v3; // eax
  int result; // eax

  if ( *this )
  {
    sub_5BE8AE();
    *this = 0;
  }
  v2 = this[140];
  this[137] = 0;
  this[138] = 0;
  this[139] = 0;
  if ( v2 )
  {
    sub_5BE8AE();
    this[140] = 0;
  }
  v3 = this[142];
  this[141] = 0;
  if ( v3 )
  {
    sub_5BE8AE();
    this[142] = 0;
  }
  result = this[144];
  this[143] = 0;
  if ( result )
  {
    result = sub_5BE8AE();
    this[144] = 0;
  }
  return result;
}
