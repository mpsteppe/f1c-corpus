int __thiscall sub_5AE860(_DWORD *this, int a2)
{
  int i; // edi
  _DWORD *j; // esi
  int result; // eax
  _DWORD *k; // esi

  for ( i = this[65]; i; i = *(_DWORD *)(i + 260) )
  {
    for ( j = *(_DWORD **)(i + 236); j; j = (_DWORD *)j[19] )
      result = sub_5AE470(j, a2, 0);
  }
  for ( k = (_DWORD *)this[67]; k; k = (_DWORD *)k[19] )
    result = sub_5AE470(k, a2, 0);
  return result;
}
