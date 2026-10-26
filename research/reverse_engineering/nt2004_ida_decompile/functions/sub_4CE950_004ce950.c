int __thiscall sub_4CE950(_DWORD *this)
{
  int result; // eax

  if ( dword_75CBB0 == 5 || (result = dword_75CBB0 - 7, dword_75CBB0 == 7) )
  {
    result = this[2427] - 3;
    if ( this[2427] != 3 )
    {
      result = this[2427] - 4;
      if ( this[2427] == 4 )
      {
        result = (unsigned __int8)byte_7D74C8;
        if ( byte_7D74C8 )
          return sub_4E5D80(1);
      }
    }
  }
  return result;
}
