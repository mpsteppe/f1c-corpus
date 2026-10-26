int __thiscall sub_53DD5A(_DWORD *this)
{
  int result; // eax
  int v3; // esi

  if ( this[1] && this[14] )
    sub_5BE8AE();
  result = this[2];
  if ( result && this[15] )
    result = sub_5BE8AE();
  if ( this[19] )
  {
    sub_53DD5A(this[19]);
    result = sub_5BE8AE();
  }
  v3 = this[20];
  if ( v3 )
  {
    sub_53DD5A(v3);
    return sub_5BE8AE();
  }
  return result;
}
