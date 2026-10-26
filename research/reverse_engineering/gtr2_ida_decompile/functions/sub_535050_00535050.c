int __thiscall sub_535050(_DWORD *this, int a2)
{
  int result; // eax

  result = a2;
  this[12] += a2;
  if ( a2 > 0 )
    this[dword_B72338 + 53] += a2;
  return result;
}
