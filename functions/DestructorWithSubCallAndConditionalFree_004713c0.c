LPVOID *__thiscall DestructorWithSubCallAndConditionalFree(LPVOID *this, char a2)
{
  VTableInit(this);
  if ( (a2 & 1) != 0 )
    FreeWrapper_7bcf(this);
  return this;
}
