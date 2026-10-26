void *__thiscall ConditionalFree(void *this, char a2)
{
  LinkedListDestructorWithVTableNotification((int)this);
  if ( (a2 & 1) != 0 )
    FreeWrapper_7bcf(this);
  return this;
}

