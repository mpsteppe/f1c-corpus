int __cdecl sub_555B62(jmp_buf Buf, int a2, unsigned int a3)
{
  int v3; // eax

  v3 = Buf[22];
  if ( (v3 & 1) == 0 || (v3 & 4) == 0 )
    sub_54E7FC(Buf, (int)"No image in file");
  Buf[22] |= 0x18u;
  if ( a3 )
    sub_54E81A((int)Buf, (int)"Incorrect IEND chunk length");
  return sub_5557B6(Buf, a3);
}
