LPVOID *__thiscall sub_4C1E40(LPVOID *this, char a2)
{
  if ( this[2] )
    FreeWrapper_7bcf(this[2]);
  if ( *this )
    FreeWrapper_7bcf(*this);
  if ( (a2 & 1) != 0 )
    FreeWrapper_7bcf(this);
  return this;
}
