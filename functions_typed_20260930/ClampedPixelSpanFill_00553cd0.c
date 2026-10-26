int __fastcall ClampedPixelSpanFill(int a1, int a2, int a3, int a4, int a5, int a6)
{
  int v6; // eax

  if ( a1 > a2 )
  {
    v6 = a1;
    a1 = a2;
    a2 = v6;
  }
  return F_16BitShortArrayFill(a1 + a5 * a3, a2 - a1 + 1, a4, a6);
}

