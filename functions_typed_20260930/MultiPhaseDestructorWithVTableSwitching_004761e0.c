LPVOID *__thiscall sub_4761E0(LPVOID *this, char a2)
{
  *this = &off_5A4478;
  if ( this[16] )
    FreeWrapper_7bcf(this[16]);
  *this = &off_5A4450;
  if ( this[12] )
    FreeWrapper_7bcf(this[12]);
  *this = &off_5A443C;
  if ( this[1] )
    FreeWrapper_7bcf(this[1]);
  if ( (a2 & 1) != 0 )
    FreeWrapper_7bcf(this);
  return this;
}

