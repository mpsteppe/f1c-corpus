int __thiscall sub_4DFED0(_DWORD *this)
{
  int result; // eax

  result = this[16];
  if ( result > 0 )
  {
    result = this[3] - 1;
    if ( result >= 0 )
    {
      if ( result > 9999 )
        result = 9999;
    }
    else
    {
      result = 0;
    }
    this[3] = result;
    if ( this[12] == 1 )
    {
      result = this[43];
      if ( result > 0 )
        this[43] = --result;
    }
  }
  return result;
}
