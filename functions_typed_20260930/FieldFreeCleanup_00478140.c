LPVOID *__thiscall FieldFreeCleanup(LPVOID *this, char a2)
{
  if ( this[58] )
    FreeWrapper_7bcf(this[58]);
  sub_485EB0(this);
  if ( (a2 & 1) != 0 )
    FreeWrapper_7bcf(this);
  return this;
}

