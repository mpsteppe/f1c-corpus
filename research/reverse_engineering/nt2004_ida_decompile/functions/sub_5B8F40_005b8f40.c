int __thiscall sub_5B8F40(_DWORD *this)
{
  int result; // eax

  result = this[123];
  if ( result )
  {
    result = sub_5BE8AE();
    this[123] = 0;
  }
  return result;
}
