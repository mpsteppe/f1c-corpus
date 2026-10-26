// f1c  0x004761e0  size=91
LPVOID *__thiscall sub_4761E0(LPVOID *this, char a2)
{
  *this = &off_5A4478;
  if ( this[16] )
    sub_587BCF(this[16]);
  *this = &off_5A4450;
  if ( this[12] )
    sub_587BCF(this[12]);
  *this = &off_5A443C;
  if ( this[1] )
    sub_587BCF(this[1]);
  if ( (a2 & 1) != 0 )
    sub_587BCF(this);
  return this;
}
