int __thiscall sub_464EE0(int *this)
{
  int result; // eax

  result = this[20];
  if ( result <= 0 )
    return sub_464E90(*this);
  return result;
}
