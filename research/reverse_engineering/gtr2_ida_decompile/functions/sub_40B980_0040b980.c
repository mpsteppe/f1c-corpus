int __thiscall sub_40B980(_DWORD *this)
{
  int v1; // esi

  if ( !this[34] )
    return 0;
  v1 = operator new(0x60u) ? sub_40B500() : 0;
  if ( !v1 )
    return 0;
  sub_5FDFB0(v1, 0);
  return v1;
}
