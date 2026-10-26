char *__usercall sub_517F04@<eax>(int a1@<ebx>, int a2, char *a3, char a4, unsigned int a5)
{
  int v5; // eax

  LOBYTE(a1) = a4;
  BYTE1(a1) = a4;
  v5 = a1 << 16;
  LOWORD(v5) = a1;
  memset32(a3, v5, a5 >> 2);
  memset(&a3[4 * (a5 >> 2)], a4, a5 & 3);
  return a3;
}

