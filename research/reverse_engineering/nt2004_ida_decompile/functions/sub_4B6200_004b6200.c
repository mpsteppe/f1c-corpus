int __thiscall sub_4B6200(_DWORD *this)
{
  int result; // eax

  result = this[3];
  if ( result )
  {
    result = sub_5A2B00(result);
    this[3] = 0;
  }
  return result;
}
