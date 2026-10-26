jmp_buf __cdecl sub_54E879(_BYTE *a1, int a2, int a3, int a4)
{
  int *v4; // eax
  int v6; // eax
  int v7; // [esp+0h] [ebp-8h]
  int *__attribute__((__org_typedef(jmp_buf))) Buf; // [esp+4h] [ebp-4h]

  v4 = (int *)sub_554DD1(1);
  Buf = v4;
  if ( !v4 )
    return 0;
  if ( _setjmp3(v4, 0, v7) )
  {
    sub_554E56(Buf, (LPVOID)Buf[39]);
    sub_554E13(Buf);
    return 0;
  }
  sub_54E7E2(Buf, a2, a3, a4);
  if ( !a1 || *a1 != 49 )
    sub_54E7FC(Buf, (int)"Incompatible libpng version in application and library");
  Buf[40] = 0x2000;
  Buf[39] = sub_554E20(Buf, 0x2000u);
  Buf[33] = (int)sub_550C13;
  Buf[34] = (int)sub_550C66;
  Buf[35] = (int)Buf;
  v6 = sub_554A53(Buf + 25, "1.1.3", 56);
  if ( v6 == -6 )
    sub_54E7FC(Buf, (int)"zlib version error");
  if ( v6 == -4 || v6 == -2 )
    sub_54E7FC(Buf, (int)"zlib memory error");
  if ( v6 )
    sub_54E7FC(Buf, (int)"Unknown zlib error");
  Buf[28] = Buf[39];
  Buf[29] = Buf[40];
  sub_550B8C(Buf, 0, 0);
  return Buf;
}
