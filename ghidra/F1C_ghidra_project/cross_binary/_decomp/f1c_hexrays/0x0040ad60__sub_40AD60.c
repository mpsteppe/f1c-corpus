// f1c  0x0040ad60  size=48
int __thiscall sub_40AD60(_DWORD *this, int a2)
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
    for ( i = this[3]; i != a2; i += 160 )
    {
      if ( ++v4 >= v2 )
        return result;
    }
    return v4;
  }
  return result;
}
