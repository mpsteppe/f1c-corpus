int __thiscall sub_49ECA0(_DWORD *this)
{
  int result; // eax

  result = this[1];
  if ( result )
  {
    result = sub_5539F0(result);
    this[1] = 0;
  }
  return result;
}
