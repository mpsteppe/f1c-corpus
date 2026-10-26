__int16 __fastcall sub_44F070(int a1, int a2, char a3)
{
  int v3; // eax

  LOBYTE(a2) = a3;
  BYTE1(a2) = a3;
  v3 = a2 << 16;
  LOWORD(v3) = a2;
  memset32((void *)(a1 + 636), v3, 0x40u);
  return v3;
}
