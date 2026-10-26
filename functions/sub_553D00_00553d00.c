int __fastcall sub_553D00(int a1, int a2, int a3, int a4, int a5, int a6)
{
  int v6; // eax

  v6 = a3;
  if ( a2 > a3 )
  {
    v6 = a2;
    a2 = a3;
  }
  return ShortArrayFillWithStride(a1 + a5 * a2, v6 - a2 + 1, a4, a5, a6);
}
