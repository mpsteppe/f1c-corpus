int __thiscall sub_4B0C50(_DWORD *this)
{
  int result; // eax

  result = this[4];
  if ( result )
  {
    result = sub_592C40(result);
    this[4] = 0;
  }
  return result;
}
