int __thiscall sub_40B8E0(_DWORD *this, int a2, int a3, int a4)
{
  int v4; // esi

  if ( !this[34] || !a2 )
    return 0;
  v4 = operator new(0x6Cu) ? sub_40A980() : 0;
  if ( !v4 )
    return 0;
  sub_5FDFB0(v4, 0);
  return v4;
}
