void *__thiscall ConditionalDestructor_9260(void *this, char a2)
{
  DestructorWithListWalk(this);
  if ( (a2 & 1) != 0 )
    FreeWrapper_7bcf(this);
  return this;
}

