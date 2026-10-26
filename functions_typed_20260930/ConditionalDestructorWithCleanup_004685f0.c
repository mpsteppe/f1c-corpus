LPVOID *__thiscall ConditionalDestructorWithCleanup(LPVOID *this, char a2)
{
  DestructorWithFree(this);
  if ( (a2 & 1) != 0 )
    FreeWrapper_7bcf(this);
  return this;
}

