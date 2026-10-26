LPVOID *__thiscall DestructorWithConditionalFree_9cc0(LPVOID *this, char a2)
{
  DestructorWithMultipleConditionalFrees(this);
  if ( (a2 & 1) != 0 )
    FreeWrapper_7bcf(this);
  return this;
}

