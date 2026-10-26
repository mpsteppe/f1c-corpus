LPVOID *__thiscall sub_485A90(LPVOID *this, char a2)
{
  if ( this[97] )
    FreeWrapper_7bcf(this[97]);
  if ( this[95] )
    FreeWrapper_7bcf(this[95]);
  DestructorWithFree(this);
  if ( (a2 & 1) != 0 )
    FreeWrapper_7bcf(this);
  return this;
}
