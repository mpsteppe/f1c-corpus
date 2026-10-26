int __thiscall sub_561B20(_DWORD *this, int a2)
{
  int result; // eax

  result = a2;
  if ( a2 == -1 || this[a2 + 31] )
    this[1] = a2;
  return result;
}
