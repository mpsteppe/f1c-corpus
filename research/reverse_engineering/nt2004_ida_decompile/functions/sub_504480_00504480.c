int __thiscall sub_504480(_DWORD *this)
{
  int result; // eax

  if ( *this )
  {
    sub_592310(*this);
    *this = 0;
  }
  if ( this[1] )
  {
    sub_592310(this[1]);
    this[1] = 0;
  }
  if ( this[2] )
  {
    sub_5A2B00(this[2]);
    this[2] = 0;
  }
  result = this[3];
  if ( result )
  {
    result = sub_5A1AD0(this[3]);
    this[3] = 0;
  }
  return result;
}
