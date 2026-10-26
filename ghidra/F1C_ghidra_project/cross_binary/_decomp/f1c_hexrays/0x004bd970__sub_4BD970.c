// f1c  0x004bd970  size=55
int __thiscall sub_4BD970(_DWORD *this, int a2)
{
  int v2; // edx
  int result; // eax
  _DWORD *v4; // edi
  _DWORD *i; // esi
  int v6; // edx

  v2 = this[4];
  result = 0;
  if ( v2 > 0 )
  {
    v4 = (_DWORD *)this[5];
    for ( i = v4; *i != a2; ++i )
    {
      if ( ++result >= v2 )
        return result;
    }
    v6 = v2 - 1;
    this[4] = v6;
    v4[result] = v4[v6];
  }
  return result;
}
