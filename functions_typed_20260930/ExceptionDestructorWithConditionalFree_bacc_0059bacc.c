_DWORD *__thiscall ExceptionDestructorWithConditionalFree_bacc(_DWORD *this, char a2)
{
  TypeInfoDestructor(this);
  if ( (a2 & 1) != 0 )
    FreeWrapper_7bcf(this);
  return this;
}

