int __thiscall sub_49D0F0(_DWORD *this)
{
  int i; // esi

  for ( i = this[62]; i; i = *(_DWORD *)(i + 24) )
    sub_4B12B0(this);
  return 0;
}
