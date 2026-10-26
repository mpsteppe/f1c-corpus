int __thiscall sub_4B68C0(_DWORD *this)
{
  int v2; // eax
  int v3; // ecx
  int result; // eax

  v2 = this[622];
  v3 = this[623];
  if ( v2 >= v3 )
  {
    if ( (unsigned __int8)sub_4B69F0(this) )
      return 0;
    v3 = this[623];
    result = this[622] - v3 + 1;
  }
  else
  {
    result = this[621] - v3 + v2 + 1;
  }
  if ( result == 1 && !*(_BYTE *)(176 * v3 + this[620]) )
    return 0;
  return result;
}
