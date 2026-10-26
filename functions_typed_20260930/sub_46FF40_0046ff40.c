LPVOID *__thiscall sub_46FF40(LPVOID *this, char a2)
{
  *this = &off_5A01A0;
  if ( this[59] )
    FreeWrapper_7bcf(this[59]);
  VTableSubInit(this);
  if ( (a2 & 1) != 0 )
    FreeWrapper_7bcf(this);
  return this;
}

