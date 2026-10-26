int __thiscall sub_41C050(_DWORD *this)
{
  int result; // eax

  if ( *this )
  {
    sub_5A2B00(*this);
    *this = 0;
  }
  if ( this[1] )
  {
    sub_592310(this[1]);
    this[1] = 0;
  }
  if ( this[4] )
  {
    sub_5A1AD0(this[4]);
    this[4] = 0;
  }
  result = this[2];
  if ( result )
  {
    result = sub_5A2B00(this[2]);
    this[2] = 0;
    this[3] = 0;
  }
  return result;
}
