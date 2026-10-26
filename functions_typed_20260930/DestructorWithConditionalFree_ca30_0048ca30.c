void *__thiscall DestructorWithConditionalFree_ca30(void *this, char a2)
{
  LinkedListDestructor((int)this);
  if ( (a2 & 1) != 0 )
    FreeWrapper_7bcf(this);
  return this;
}

