// f1c  0x005570c0  size=93
int __thiscall sub_5570C0(_DWORD *this, int a2)
{
  int i; // edi
  _DWORD *j; // esi
  int result; // eax
  _DWORD *k; // esi

  for ( i = this[64]; i; i = *(_DWORD *)(i + 260) )
  {
    for ( j = *(_DWORD **)(i + 236); j; j = (_DWORD *)j[19] )
      result = sub_556CD0(j, a2, 0);
  }
  for ( k = (_DWORD *)this[66]; k; k = (_DWORD *)k[19] )
    result = sub_556CD0(k, a2, 0);
  return result;
}
