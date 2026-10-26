LPVOID *__thiscall DestructorWithVTableReset(LPVOID *this, char a2)
{
  *this = &off_5A5E40;
  ObjectInitWithVTableCleanup(this);
  if ( (a2 & 1) != 0 )
    FreeWrapper_7bcf(this);
  return this;
}
