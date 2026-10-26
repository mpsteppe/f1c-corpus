// f1c  0x00595058  size=53
int __cdecl sub_595058(int a1, int a2)
{
  int v2; // esi

  v2 = a2 & a1 | ~a2 & sub_5950A3();
  sub_595135(v2);
  return v2;
}
