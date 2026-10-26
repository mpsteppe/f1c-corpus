LPVOID *__thiscall sub_4E55F0(LPVOID *this, char a2)
{
  if ( this[2] )
    sub_5BE8AE(this[2]);
  if ( *this )
    sub_5BE8AE(*this);
  if ( (a2 & 1) != 0 )
    sub_5BE8AE(this);
  return this;
}
