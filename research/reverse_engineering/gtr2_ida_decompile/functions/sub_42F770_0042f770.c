int __thiscall sub_42F770(_DWORD *this)
{
  int result; // eax

  result = this[28];
  if ( result != this[27] )
    this[27] = result;
  return result;
}
