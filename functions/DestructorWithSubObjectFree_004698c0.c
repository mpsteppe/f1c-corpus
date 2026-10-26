LPVOID *__thiscall DestructorWithSubObjectFree(LPVOID *this, char a2)
{
  if ( this[96] )
    FreeWrapper_7bcf(this[96]);
  FunctionCallWrapper_9440(this);
  if ( (a2 & 1) != 0 )
    FreeWrapper_7bcf(this);
  return this;
}
