int __thiscall sub_45B430(_DWORD *this, int a2)
{
  int v2; // eax
  int result; // eax

  v2 = (int)&this[23 * a2 + 15];
  *(_BYTE *)v2 = 0;
  *(_DWORD *)(v2 + 80) = -1;
  *(_DWORD *)(v2 + 84) = -1082130432;
  *(_DWORD *)(v2 + 88) = 3;
  result = this[199];
  if ( a2 == result )
  {
    result = (result + 1) % 8;
    this[199] = result;
  }
  return result;
}
