// f1c  0x004a5e10  size=35
int __thiscall sub_4A5E10(_DWORD *this)
{
  int v1; // eax
  int v2; // eax
  int result; // eax

  v1 = this[97];
  if ( !v1 )
    return sub_4A5C80((int)this, 1);
  v2 = v1 - 1;
  if ( !v2 )
    return sub_4A5C80((int)this, 0);
  result = v2 - 3;
  if ( !result )
    return sub_4A5C80((int)this, 1);
  return result;
}
