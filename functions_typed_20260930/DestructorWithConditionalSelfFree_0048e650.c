LPVOID *__thiscall DestructorWithConditionalSelfFree(LPVOID *this, char a2)
{
  Destructor_e670(this);
  if ( (a2 & 1) != 0 )
    FreeWrapper_7bcf(this);
  return this;
}

