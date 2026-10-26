// f1c  0x004c1e40  size=56
LPVOID *__thiscall sub_4C1E40(LPVOID *this, char a2)
{
  if ( this[2] )
    sub_587BCF(this[2]);
  if ( *this )
    sub_587BCF(*this);
  if ( (a2 & 1) != 0 )
    sub_587BCF(this);
  return this;
}
