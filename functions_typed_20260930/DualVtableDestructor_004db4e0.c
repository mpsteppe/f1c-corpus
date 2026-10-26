LPVOID *__thiscall DualVtableDestructor(LPVOID *this, char a2)
{
  *this = &off_5AD0DC;
  if ( this[4] )
    FreeWrapper_7bcf(this[4]);
  *this = &off_5AD06C;
  if ( (a2 & 1) != 0 )
    FreeWrapper_7bcf(this);
  return this;
}

