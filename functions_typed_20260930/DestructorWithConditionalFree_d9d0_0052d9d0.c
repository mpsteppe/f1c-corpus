_BYTE *__thiscall DestructorWithConditionalFree_d9d0(_BYTE *this, char a2)
{
  CConstructor(this);
  if ( (a2 & 1) != 0 )
    FreeWrapper_7bcf(this);
  return this;
}

