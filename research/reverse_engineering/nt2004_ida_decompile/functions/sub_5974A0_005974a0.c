int __thiscall sub_5974A0(_DWORD *this, _DWORD *a2)
{
  int v2; // eax
  int result; // eax
  int i; // ecx

  v2 = a2[15] | 8;
  a2[19] = 0;
  a2[15] = v2;
  sub_596EC0(this, (int)a2);
  result = this[67];
  if ( result )
  {
    for ( i = *(_DWORD *)(result + 76); i; i = *(_DWORD *)(i + 76) )
      result = i;
    *(_DWORD *)(result + 76) = a2;
    a2[141] = this;
    a2[18] = result;
  }
  else
  {
    this[67] = a2;
    a2[141] = this;
    a2[18] = 0;
  }
  return result;
}
