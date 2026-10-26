// f1c  0x005452f0  size=73
int __thiscall sub_5452F0(_DWORD *this)
{
  int v1; // esi
  int result; // eax
  int i; // edx
  int j; // ecx

  v1 = this[64];
  for ( result = 0; v1; v1 = *(_DWORD *)(v1 + 260) )
  {
    for ( i = *(_DWORD *)(v1 + 236); i; ++result )
      i = *(_DWORD *)(i + 76);
  }
  for ( j = this[66]; j; ++result )
    j = *(_DWORD *)(j + 76);
  return result;
}
