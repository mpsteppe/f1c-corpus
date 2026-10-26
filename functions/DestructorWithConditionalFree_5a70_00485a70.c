_DWORD *__thiscall DestructorWithConditionalFree_5a70(_DWORD *this, char a2)
{
  ShortComputation_6140(this);
  if ( (a2 & 1) != 0 )
    FreeWrapper_7bcf(this);
  return this;
}
