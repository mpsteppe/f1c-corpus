void __thiscall sub_549380(_DWORD *this)
{
  int i; // esi

  for ( i = this[62]; i; i = *(_DWORD *)(i + 20) )
    *(_DWORD *)(i + 16) = sub_54A2D0(i);
}
