LPVOID *__thiscall DestructorWithSubCallConditionalFree(LPVOID *this, char a2)
{
  ShortComputation_76b0(this);
  if ( (a2 & 1) != 0 )
    FreeWrapper_7bcf(this);
  return this;
}

