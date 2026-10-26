int __thiscall sub_59FDC0(void *this, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10)
{
  int v11; // esi
  int result; // eax

  if ( a5 < 0 )
    a2 -= a5;
  if ( a6 < 0 )
    a3 -= a6;
  sub_5A00B0(&a2, &a3, &a7, &a8);
  v11 = a4;
  sub_5A00B0(&a5, &a6, &a7, &a8);
  result = a7;
  if ( a7 > 0 && a8 > 0 )
  {
    result = sub_5A72D0(this, a2, a3, v11, a5, a6, a7, a8, a9);
    *(_DWORD *)(v11 + 56) &= ~0x400u;
  }
  return result;
}
