BOOL __cdecl sub_554F00(jmp_buf Buf)
{
  int *__attribute__((__org_typedef(jmp_buf))) v1; // esi
  int v2; // edi

  v1 = Buf;
  v2 = 1;
  if ( (Buf[67] & 0x20) != 0 )
  {
    if ( (Buf[23] & 0x300) != 0x300 )
      goto LABEL_6;
  }
  else if ( (*((_BYTE *)Buf + 93) & 8) == 0 )
  {
    goto LABEL_6;
  }
  v2 = 0;
LABEL_6:
  sub_550B64(Buf, (int)&Buf, 4);
  return v2 && sub_554EC3((unsigned __int8 *)&Buf) != v1[64];
}
