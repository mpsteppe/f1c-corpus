// f1c  0x004cf010  size=43
int __thiscall sub_4CF010(_DWORD *this, int a2)
{
  int v2; // edx
  int result; // eax
  _DWORD *i; // ecx

  v2 = this[4];
  result = 0;
  if ( v2 > 0 )
  {
    for ( i = (_DWORD *)this[5]; i[1] != a2; i += 27 )
    {
      if ( ++result >= v2 )
        return result;
    }
    return sub_4CB5E0(i);
  }
  return result;
}
