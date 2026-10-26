// f1c  0x0040b6c0  size=48
int __thiscall sub_40B6C0(_DWORD *this, int a2)
{
  int v2; // esi
  int result; // eax
  int v4; // edx
  int i; // ecx

  v2 = this[4];
  result = -1;
  v4 = 0;
  if ( v2 > 0 )
  {
    for ( i = this[3]; i != a2; i += 208 )
    {
      if ( ++v4 >= v2 )
        return result;
    }
    return v4;
  }
  return result;
}
