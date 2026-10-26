// f1c  0x00404f70  size=40
LPVOID *__thiscall sub_404F70(LPVOID *this, char a2)
{
  if ( *this )
    sub_587BCF(*this);
  if ( (a2 & 1) != 0 )
    sub_587BCF(this);
  return this;
}
