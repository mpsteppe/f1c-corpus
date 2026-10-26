LPVOID __thiscall sub_40D5C0(LPVOID *this)
{
  LPVOID result; // eax
  void *v3; // esi

  if ( this[17] )
    sub_5BE8AE(this[17]);
  if ( this[14] )
    sub_5BE8AE(this[14]);
  if ( this[11] )
    sub_5BE8AE(this[11]);
  if ( this[8] )
    sub_5BE8AE(this[8]);
  if ( this[5] )
    sub_5BE8AE(this[5]);
  result = this[2];
  if ( result )
    result = (LPVOID)sub_5BE8AE(this[2]);
  v3 = *this;
  if ( v3 )
    return (LPVOID)sub_5BE8AE(v3);
  return result;
}
