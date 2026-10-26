int __thiscall sub_65F908(_DWORD *this, int a2)
{
  int result; // eax

  result = sub_65F877((int)this, 1);
  if ( result >= 0 )
  {
    *(_DWORD *)(this[22] + 4 * this[23]++) = a2;
    return 0;
  }
  return result;
}
