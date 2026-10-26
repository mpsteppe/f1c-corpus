_DWORD *__thiscall DestructorWithConditionalFree(_DWORD *this, char a2)
{
  ObjectConstructorWithVTableAndSubFree(this);
  if ( (a2 & 1) != 0 )
    FreeWrapper_7bcf(this);
  return this;
}

