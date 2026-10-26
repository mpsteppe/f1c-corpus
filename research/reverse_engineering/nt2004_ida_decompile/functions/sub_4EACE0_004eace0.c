int __thiscall sub_4EACE0(_DWORD *this)
{
  int result; // eax

  result = this[10];
  if ( result )
  {
    result = sub_592310(result);
    this[10] = 0;
  }
  return result;
}
