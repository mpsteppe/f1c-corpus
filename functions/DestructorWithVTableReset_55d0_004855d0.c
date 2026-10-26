LPVOID *__thiscall DestructorWithVTableReset_55d0(LPVOID *this, char a2)
{
  *this = &off_5AB1E0;
  InitWithVTableCleanup(this);
  if ( (a2 & 1) != 0 )
    FreeWrapper_7bcf(this);
  return this;
}
