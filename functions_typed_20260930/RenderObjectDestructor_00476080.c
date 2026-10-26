LPVOID *__thiscall RenderObjectDestructor(LPVOID *this, char a2)
{
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

