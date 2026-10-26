int __stdcall sub_526D20(int a1, int a2, int a3, int a4)
{
  int v4; // eax

  v4 = sub_526B40(a1, a2, a3, a4);
  if ( v4 < 0 )
    return 1;
  dword_6152F0 = a3;
  dword_7DA99C = a4;
  dword_6152E8 = a1;
  dword_7DA998 = v4;
  dword_6152EC = a2;
  return 0;
}
