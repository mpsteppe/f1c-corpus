int __thiscall sub_4582A0(_DWORD *this, int a2)
{
  int result; // eax

  result = 0;
  if ( a2 >= 0 && a2 < this[1] )
    return *this + 28 * a2;
  return result;
}

