LPVOID __thiscall sub_56CF10(LPVOID *this)
{
  LPVOID result; // eax

  if ( *this )
  {
    FreeWrapper_7bcf(*this);
    *this = 0;
  }
  if ( this[1] )
  {
    FreeWrapper_7bcf(this[1]);
    this[1] = 0;
  }
  if ( this[2] )
  {
    FreeWrapper_7bcf(this[2]);
    this[2] = 0;
  }
  result = this[3];
  if ( result )
  {
    result = (LPVOID)FreeWrapper_7bcf(this[3]);
    this[3] = 0;
  }
  return result;
}

