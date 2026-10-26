int __thiscall sub_4FBED0(_DWORD *this, int a2)
{
  int result; // eax

  result = 0;
  if ( *(_BYTE *)(*this + 21676) )
  {
    result = a2;
    this[10] = 2;
  }
  else
  {
    this[10] = 1;
  }
  this[11] = result;
  this[12] = result;
  return result;
}
