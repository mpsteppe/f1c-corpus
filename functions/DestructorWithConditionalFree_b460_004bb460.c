LPVOID *__thiscall sub_4BB460(LPVOID *this, char a2)
{
  if ( this[1] )
    FreeWrapper_7bcf(this[1]);
  if ( (a2 & 1) != 0 )
    FreeWrapper_7bcf(this);
  return this;
}
