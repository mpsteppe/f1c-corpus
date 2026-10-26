int __thiscall sub_567D00(int *this)
{
  int result; // eax

  if ( this[1] )
    return off_16C97BC();
  result = *this;
  if ( *this )
  {
    result = sub_5EE1D0(dword_FB1CE0, *this);
    *this = 0;
  }
  return result;
}
