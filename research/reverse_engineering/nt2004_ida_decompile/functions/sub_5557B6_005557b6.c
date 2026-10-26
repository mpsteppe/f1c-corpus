int __cdecl sub_5557B6(jmp_buf Buf, unsigned int a2)
{
  unsigned int i; // edi

  for ( i = Buf[40]; a2 > i; a2 -= i )
    sub_554EE6(Buf, Buf[39], Buf[40]);
  if ( a2 )
    sub_554EE6(Buf, Buf[39], a2);
  if ( !sub_554F00(Buf) )
    return 0;
  if ( ((Buf[67] & 0x20) == 0 || (*((_BYTE *)Buf + 93) & 2) != 0)
    && ((Buf[67] & 0x20) != 0 || (*((_BYTE *)Buf + 93) & 4) == 0) )
  {
    sub_54E82F(Buf, "CRC error");
  }
  sub_54E854((int)Buf, "CRC error");
  return 1;
}
