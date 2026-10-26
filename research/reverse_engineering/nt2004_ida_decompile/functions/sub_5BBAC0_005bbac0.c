int __fastcall sub_5BBAC0(_DWORD *a1, int a2, int a3, int a4, int a5)
{
  sub_5BDB90();
  *a1 = a3;
  a1[1] = a2;
  a1[15] = 0;
  a1[16] = a4;
  a1[17] = a5;
  a1[9] = 0;
  a1[8] = socket(2, 2, 17);
  sub_5BBB10(a1 + 5);
  return sub_5BBB10(a1 + 2);
}
