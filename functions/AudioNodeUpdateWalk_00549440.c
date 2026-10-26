void __thiscall sub_549440(_DWORD *this)
{
  int i; // esi

  for ( i = this[63]; i; i = *(_DWORD *)(i + 20) )
    *(_DWORD *)(i + 16) = StringLookupInLinkedDictionary(i);
}
