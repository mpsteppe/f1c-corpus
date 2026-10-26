// f1c  0x0059a2d0  size=46
_DWORD *__thiscall sub_59A2D0(_DWORD *this, int a2, int a3)
{
  int v4; // eax

  v4 = this[20];
  if ( !v4 || sub_59BB00(v4, a2, 0, 2 * a3) )
    return 0;
  else
    return this;
}
