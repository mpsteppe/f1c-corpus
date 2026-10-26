int __thiscall sub_429EB0(_DWORD *this)
{
  int result; // eax

  result = sub_42AD20(this);
  if ( result < 1 )
  {
    result = this[4436];
    if ( !result && dword_7C56A8 == 5 )
      return sub_42A110(this);
  }
  return result;
}
