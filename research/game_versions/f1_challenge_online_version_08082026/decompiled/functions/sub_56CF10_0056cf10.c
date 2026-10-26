LPVOID __thiscall sub_56CF10(LPVOID *this)
{
  LPVOID result; // eax

  if ( *this )
  {
    sub_587BCF(*this);
    *this = 0;
  }
  if ( this[1] )
  {
    sub_587BCF(this[1]);
    this[1] = 0;
  }
  if ( this[2] )
  {
    sub_587BCF(this[2]);
    this[2] = 0;
  }
  result = this[3];
  if ( result )
  {
    result = (LPVOID)sub_587BCF(this[3]);
    this[3] = 0;
  }
  return result;
}
