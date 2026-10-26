int __thiscall sub_597B20(_DWORD *this)
{
  int i; // edi
  int j; // esi
  int result; // eax
  int k; // esi

  for ( i = this[65]; i; i = *(_DWORD *)(i + 260) )
  {
    for ( j = *(_DWORD *)(i + 236); j; j = *(_DWORD *)(j + 76) )
    {
      sub_59DFD0(0, 32, 0);
      result = sub_59DF60(0, 0x10000000, 0);
    }
  }
  for ( k = this[67]; k; k = *(_DWORD *)(k + 76) )
  {
    sub_59DFD0(0, 32, 0);
    result = sub_59DF60(0, 0x10000000, 0);
  }
  return result;
}
