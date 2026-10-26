LPVOID __thiscall sub_4B0D00(LPVOID *this)
{
  LPVOID result; // eax
  void *v3; // esi

  *this = &off_5EA2D0;
  sub_4B0DC0(0);
  sub_4DB110(this + 27);
  if ( this[22] )
    sub_5BE8AE(this[22]);
  if ( this[20] )
    sub_5BE8AE(this[20]);
  if ( this[18] )
    sub_5BE8AE(this[18]);
  if ( this[16] )
    sub_5BE8AE(this[16]);
  if ( this[14] )
    sub_5BE8AE(this[14]);
  if ( this[12] )
    sub_5BE8AE(this[12]);
  if ( this[10] )
    sub_5BE8AE(this[10]);
  if ( this[8] )
    sub_5BE8AE(this[8]);
  result = this[6];
  if ( result )
    result = (LPVOID)sub_5BE8AE(this[6]);
  v3 = this[4];
  if ( v3 )
    return (LPVOID)sub_5BE8AE(v3);
  return result;
}
