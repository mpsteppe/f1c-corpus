int __thiscall sub_4B17B0(_DWORD *this)
{
  int result; // eax

  if ( dword_7C56A4 == 5 || (result = dword_7C56A4 - 7, dword_7C56A4 == 7) )
  {
    result = this[2014] - 3;
    if ( this[2014] != 3 )
    {
      result = this[2014] - 4;
      if ( this[2014] == 4 )
      {
        result = (unsigned __int8)byte_8ACFA0;
        if ( byte_8ACFA0 )
          return sub_4C2830(1);
      }
    }
  }
  return result;
}
