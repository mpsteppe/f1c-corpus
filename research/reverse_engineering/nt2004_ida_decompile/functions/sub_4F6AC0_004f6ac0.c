int __thiscall sub_4F6AC0(_DWORD *this, int a2, int a3, int a4)
{
  int v4; // edx
  int result; // eax
  int i; // ecx

  v4 = this[4];
  result = 0;
  if ( v4 > 0 )
  {
    for ( i = this[5]; *(_DWORD *)(i + 4) != a2; i += 116 )
    {
      if ( ++result >= v4 )
        return result;
    }
    return sub_4F4D30(i, a3, a4);
  }
  return result;
}
