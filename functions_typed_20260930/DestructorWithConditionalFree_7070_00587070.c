LPVOID *__thiscall DestructorWithConditionalFree_7070(LPVOID *this, char a2)
{
  SetVtablePointerAndCallInit(this);
  if ( (a2 & 1) != 0 )
    FreeWrapper_7bcf(this);
  return this;
}

