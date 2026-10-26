// f1c  0x00410b80  size=60
int __thiscall sub_410B80(_DWORD *this, int a2)
{
  int v2; // esi
  int v3; // eax
  _DWORD *i; // edx

  v2 = this[15];
  v3 = 0;
  if ( v2 <= 0 )
    return 0;
  for ( i = (_DWORD *)(this[17] + 208); *i != a2; i += 198 )
  {
    if ( ++v3 >= v2 )
      return 0;
  }
  return this[16] + 36 * v3;
}
