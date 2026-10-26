LPVOID *__thiscall DestructorWithVTableAndFree(LPVOID *this, char a2)
{
  *this = &off_59E4B4;
  if ( this[1] )
    FreeWrapper_7bcf(this[1]);
  if ( (a2 & 1) != 0 )
    FreeWrapper_7bcf(this);
  return this;
}
