int __thiscall sub_4F6B00(_DWORD *this, int a2, float a3)
{
  int v3; // edx
  int result; // eax
  _DWORD *i; // ecx

  v3 = this[4];
  result = 0;
  if ( v3 > 0 )
  {
    for ( i = (_DWORD *)this[5]; i[1] != a2; i += 29 )
    {
      if ( ++result >= v3 )
        return result;
    }
    return sub_4F53B0(i, a3);
  }
  return result;
}
