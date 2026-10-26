int __thiscall sub_4A5E40(_DWORD *this)
{
  int result; // eax

  result = this[97];
  if ( !result || result == 4 )
    return sub_4A5C80((int)this, 1);
  return result;
}
