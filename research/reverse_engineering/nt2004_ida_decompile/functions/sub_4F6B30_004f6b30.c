int __thiscall sub_4F6B30(_DWORD *this, int a2)
{
  int v2; // edx
  int result; // eax
  _DWORD *i; // ecx

  v2 = this[4];
  result = 0;
  if ( v2 > 0 )
  {
    for ( i = (_DWORD *)this[5]; i[1] != a2; i += 29 )
    {
      if ( ++result >= v2 )
        return result;
    }
    return sub_4F2B80(i);
  }
  return result;
}
