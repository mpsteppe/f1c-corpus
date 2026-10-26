LPVOID *__thiscall DestructorWithConditionalFree_5600(LPVOID *this, char a2)
{
  *this = &off_5AB130;
  InitWithVTableCleanup(this);
  if ( (a2 & 1) != 0 )
    FreeWrapper_7bcf(this);
  return this;
}

