int __thiscall sub_485E20(_DWORD *this)
{
  int result; // eax

  result = this[211];
  *(_DWORD *)dword_7689CC = result;
  if ( result >= dword_7689D4 )
  {
    if ( result > dword_7689D8 )
      *(_DWORD *)dword_7689CC = dword_7689D8;
  }
  else
  {
    *(_DWORD *)dword_7689CC = dword_7689D4;
  }
  return result;
}
