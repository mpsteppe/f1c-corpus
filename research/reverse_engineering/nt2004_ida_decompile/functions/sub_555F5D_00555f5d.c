int __cdecl sub_555F5D(jmp_buf Buf, int a2, unsigned int a3)
{
  int v3; // eax

  sub_554F5E(Buf, (unsigned __int8 *)Buf + 268);
  if ( (Buf[67] & 0x20) == 0 )
    sub_54E82F(Buf, "unknown critical chunk");
  v3 = Buf[22];
  if ( (v3 & 4) != 0 )
    Buf[22] = v3 | 8;
  return sub_5557B6(Buf, a3);
}
