int __thiscall sub_54EC40(_DWORD *this, int a2)
{
  int result; // eax

  if ( a2 < 0 )
    return 0;
  if ( a2 >= this[418] || (result = this[2 * a2 + 210], result < 0) )
  {
    if ( a2 >= this[209] )
      return 0;
    result = this[2 * a2 + 1];
    if ( result < 0 )
      return 0;
  }
  return result;
}
