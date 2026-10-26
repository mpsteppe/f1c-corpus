int __thiscall sub_543440(_DWORD *this, int a2, int a3, signed int a4, char *a5, int a6)
{
  int result; // eax

  result = sub_543540(&a2, &a3, &a4, &a5);
  if ( a4 > 0 )
  {
    result = (int)a5;
    if ( (int)a5 > 0 )
    {
      result = F_2DSurfaceBlitFill(dword_8B78A0, this, a2, a3, a4, a5, a6);
      this[6] &= ~0x400u;
    }
  }
  return result;
}

