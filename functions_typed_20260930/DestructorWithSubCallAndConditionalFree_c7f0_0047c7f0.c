LPVOID *__thiscall DestructorWithSubCallAndConditionalFree_c7f0(LPVOID *this, char a2)
{
  ObjectInitWithVTableCleanup(this);
  if ( (a2 & 1) != 0 )
    FreeWrapper_7bcf(this);
  return this;
}

