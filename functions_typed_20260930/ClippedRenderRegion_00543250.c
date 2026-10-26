int __thiscall sub_543250(_DWORD *this, int a2, int a3, _DWORD *a4, int a5, int a6, int a7, int a8, int a9, int a10)
{
  _DWORD *v11; // esi
  int result; // eax

  if ( a5 < 0 )
    a2 -= a5;
  if ( a6 < 0 )
    a3 -= a6;
  sub_543540(&a2, &a3, &a7, &a8);
  v11 = a4;
  sub_543540(&a5, &a6, &a7, &a8);
  result = a7;
  if ( a7 > 0 && a8 > 0 )
  {
    result = F_2DSurfaceCompositing(dword_8B78A0, this, a2, a3, v11, a5, a6, a7, a8, a9);
    v11[6] &= ~0x400u;
  }
  return result;
}

