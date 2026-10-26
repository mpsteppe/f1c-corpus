LPVOID __thiscall sub_4E7620(LPVOID *this)
{
  LPVOID result; // eax
  void *v3; // esi

  if ( this[14] )
    sub_5BE8AE(this[14]);
  if ( this[8] )
    sub_5BE8AE(this[8]);
  if ( this[6] )
    sub_5BE8AE(this[6]);
  if ( this[4] )
    sub_5BE8AE(this[4]);
  result = this[2];
  if ( result )
    result = (LPVOID)sub_5BE8AE(this[2]);
  v3 = *this;
  if ( v3 )
    return (LPVOID)sub_5BE8AE(v3);
  return result;
}
