__int16 __fastcall sub_45DCB0(int a1, int a2, char a3)
{
  int v3; // eax

  LOBYTE(a2) = a3;
  BYTE1(a2) = a3;
  v3 = a2 << 16;
  LOWORD(v3) = a2;
  memset32((void *)(a1 + 640), v3, 0x40u);
  return v3;
}
