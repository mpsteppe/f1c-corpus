int __thiscall sub_4B61A0(int *this)
{
  int result; // eax

  result = *this;
  if ( *this )
  {
    result = sub_5A1AD0(result);
    *this = 0;
  }
  return result;
}
