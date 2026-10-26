int __thiscall sub_4D6280(_DWORD *this)
{
  int v2; // eax
  int v3; // ecx
  int result; // eax

  v2 = this[332];
  v3 = this[333];
  if ( v2 >= v3 )
  {
    if ( (unsigned __int8)sub_4D63B0(this) )
      return 0;
    v3 = this[333];
    result = this[332] - v3 + 1;
  }
  else
  {
    result = this[331] - v3 + v2 + 1;
  }
  if ( result == 1 && !*(_BYTE *)((v3 << 7) + this[330]) )
    return 0;
  return result;
}
