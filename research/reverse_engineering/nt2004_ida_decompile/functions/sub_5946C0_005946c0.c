void __thiscall sub_5946C0(_DWORD *this)
{
  int i; // esi

  for ( i = this[63]; i; i = *(_DWORD *)(i + 20) )
    *(_DWORD *)(i + 16) = sub_595540(i);
}
