void __cdecl sub_555CB7(jmp_buf Buf, unsigned int a2, unsigned int a3)
{
  int *__attribute__((__org_typedef(jmp_buf))) v3; // esi
  int v4; // eax
  unsigned int v5; // edi

  v3 = Buf;
  v4 = Buf[22];
  if ( (v4 & 1) == 0 )
    sub_54E7FC(Buf, (int)"Missing IHDR before sRGB");
  if ( (v4 & 4) != 0 )
  {
    sub_54E81A((int)Buf, (int)"Invalid sRGB after IDAT");
    goto LABEL_5;
  }
  if ( (v4 & 2) != 0 )
  {
    sub_54E81A((int)Buf, (int)"Out of place sRGB chunk");
  }
  else if ( a2 && (*(_BYTE *)(a2 + 9) & 8) != 0 )
  {
    sub_54E81A((int)Buf, (int)"Duplicate sRGB chunk");
    goto LABEL_5;
  }
  if ( a3 != 1 )
  {
    sub_54E81A((int)v3, (int)"Incorrect sRGB chunk length");
LABEL_5:
    sub_5557B6(v3, a3);
    return;
  }
  sub_554EE6(v3, (int)&Buf + 3, 1);
  if ( !sub_5557B6(v3, 0) )
  {
    v5 = HIBYTE(Buf);
    if ( HIBYTE(Buf) < 4u )
    {
      if ( (*(_BYTE *)(a2 + 8) & 1) != 0 && fabs(*((float *)v3 + 76) * 100000.0 + 0.5 - 45455.0) > 500.0 )
        sub_54E81A((int)v3, (int)"Ignoring incorrect gAMA value when sRGB is also present");
      sub_550AE4((int)v3, __SPAIR64__(v5, a2));
    }
    else
    {
      sub_54E81A((int)v3, (int)"Unknown sRGB intent");
    }
  }
}
