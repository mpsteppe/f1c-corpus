jmp_buf __cdecl sub_554EE6(jmp_buf Buf, int a2, int a3)
{
  int *__attribute__((__org_typedef(jmp_buf))) result; // eax

  sub_550B64(Buf, a2, a3);
  result = Buf;
  if ( (Buf[67] & 0x20) == 0 )
  {
    if ( (*((_BYTE *)Buf + 93) & 8) != 0 )
      return result;
    goto LABEL_5;
  }
  if ( (Buf[23] & 0x300) != 0x300 )
  {
LABEL_5:
    result = (int *)sub_5561CB(Buf[64], a2, a3);
    Buf[64] = (int)result;
  }
  return result;
}
