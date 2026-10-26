int __thiscall sub_49E0E0(_DWORD *this, int a2)
{
  int result; // eax

  result = this[33];
  if ( result != a2 )
  {
    result = 0;
    this[33] = 0;
    this[32] = 0;
  }
  return result;
}
