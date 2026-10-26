LPVOID *__thiscall sub_475110(LPVOID *this, char a2)
{
  *this = &off_5D6F48;
  if ( this[23] )
    sub_5BE8AE(this[23]);
  if ( this[21] )
    sub_5BE8AE(this[21]);
  *this = &off_5D6E60;
  if ( this[18] )
    sub_5BE8AE(this[18]);
  if ( this[16] )
    sub_5BE8AE(this[16]);
  *this = &off_5D6E44;
  if ( this[13] )
    sub_5BE8AE(this[13]);
  *this = &off_5D6E28;
  if ( this[5] )
    sub_5BE8AE(this[5]);
  if ( (a2 & 1) != 0 )
    sub_5BE8AE(this);
  return this;
}
