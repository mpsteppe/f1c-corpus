unsigned __int16 __thiscall sub_411650(unsigned __int16 *this)
{
  unsigned __int16 v1; // si
  unsigned __int16 result; // ax

  v1 = *this;
  result = 0;
  if ( *this > 1u )
  {
    result = this[1];
    this[1] = result + 1;
    if ( (unsigned __int16)(result + 1) >= v1 )
      this[1] = 0;
  }
  return result;
}

