LPVOID *__thiscall ConditionalDestructorWithVTable(LPVOID *this, char a2)
{
  *this = &off_5A6068;
  ObjectInitWithVTableCleanup(this);
  if ( (a2 & 1) != 0 )
    FreeWrapper_7bcf(this);
  return this;
}
