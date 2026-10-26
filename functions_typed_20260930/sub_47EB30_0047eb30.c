LPVOID *__thiscall sub_47EB30(LPVOID *this, char a2)
{
  if ( this[59] )
    FreeWrapper_7bcf(this[59]);
  ConstructorWithVTableSet(this);
  if ( (a2 & 1) != 0 )
    FreeWrapper_7bcf(this);
  return this;
}

