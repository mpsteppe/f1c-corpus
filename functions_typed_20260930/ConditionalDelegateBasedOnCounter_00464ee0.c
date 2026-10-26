int __thiscall sub_464EE0(int *this)
{
  int result; // eax

  result = this[20];
  if ( result <= 0 )
    return BufferSizeLookup(*this);
  return result;
}

