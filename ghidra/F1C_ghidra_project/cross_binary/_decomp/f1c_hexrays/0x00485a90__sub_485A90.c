// f1c  0x00485a90  size=70
LPVOID *__thiscall sub_485A90(LPVOID *this, char a2)
{
  if ( this[97] )
    sub_587BCF(this[97]);
  if ( this[95] )
    sub_587BCF(this[95]);
  sub_468610(this);
  if ( (a2 & 1) != 0 )
    sub_587BCF(this);
  return this;
}
