void *__thiscall DestructorWithConditionalFree_a950(void *this, char a2)
{
  VtableSetSubCall();
  if ( (a2 & 1) != 0 )
    FreeWrapper_7bcf(this);
  return this;
}

