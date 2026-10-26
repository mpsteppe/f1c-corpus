int __thiscall sub_6C9357(_DWORD *this, int a2)
{
  int result; // eax

  result = sub_6C5921((int)this, 1);
  if ( result >= 0 )
  {
    *(_DWORD *)(this[67] + 4 * this[68]++) = a2;
    return 0;
  }
  return result;
}
