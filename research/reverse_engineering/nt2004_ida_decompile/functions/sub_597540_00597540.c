int __thiscall sub_597540(_DWORD *this)
{
  int v1; // esi
  int result; // eax
  int i; // edx
  int j; // ecx

  v1 = this[65];
  for ( result = 0; v1; v1 = *(_DWORD *)(v1 + 260) )
  {
    for ( i = *(_DWORD *)(v1 + 236); i; ++result )
      i = *(_DWORD *)(i + 76);
  }
  for ( j = this[67]; j; ++result )
    j = *(_DWORD *)(j + 76);
  return result;
}
