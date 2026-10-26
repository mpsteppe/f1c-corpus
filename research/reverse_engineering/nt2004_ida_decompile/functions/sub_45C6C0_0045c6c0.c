int __thiscall sub_45C6C0(_DWORD *this, int a2)
{
  int v2; // eax
  int result; // eax

  v2 = (int)&this[35 * a2 + 17];
  *(_BYTE *)v2 = 0;
  *(_DWORD *)(v2 + 128) = -1;
  *(_DWORD *)(v2 + 132) = -1082130432;
  *(_DWORD *)(v2 + 136) = 3;
  result = this[297];
  if ( a2 == result )
  {
    result = (result + 1) % 8;
    this[297] = result;
  }
  return result;
}
