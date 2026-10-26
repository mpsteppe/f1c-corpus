int __thiscall sub_6B1675(_DWORD *this)
{
  int result; // eax

  result = sub_6C6CB5((int)this);
  if ( result >= 0 )
  {
    result = sub_6875A0(this);
    if ( result >= 0 )
    {
      result = sub_688BDF(this);
      if ( result >= 0 )
      {
        result = sub_6825A9(this);
        if ( result >= 0 )
        {
          sub_6BC1A9(this);
          return 0;
        }
      }
    }
  }
  return result;
}
