LPVOID *__thiscall FieldFreeUIDtor(LPVOID *this, char a2)
{
  if ( this[93] )
    FreeWrapper_7bcf(this[93]);
  FunctionCallWrapper_9440(this);
  if ( (a2 & 1) != 0 )
    FreeWrapper_7bcf(this);
  return this;
}

