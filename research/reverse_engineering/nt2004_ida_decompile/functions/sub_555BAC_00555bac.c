void __cdecl sub_555BAC(jmp_buf Buf, int a2, unsigned int a3)
{
  int *__attribute__((__org_typedef(jmp_buf))) v3; // esi
  int v4; // eax
  int v5; // edi
  int v6; // eax
  int v7; // eax
  double v8; // st7

  v3 = Buf;
  v4 = Buf[22];
  v5 = a2;
  if ( (v4 & 1) == 0 )
    sub_54E7FC(Buf, (int)"Missing IHDR before gAMA");
  if ( (v4 & 4) != 0 )
  {
    sub_54E81A((int)Buf, (int)"Invalid gAMA after IDAT");
    goto LABEL_5;
  }
  if ( (v4 & 2) != 0 )
  {
    sub_54E81A((int)Buf, (int)"Out of place gAMA chunk");
  }
  else if ( a2 )
  {
    v6 = *(_DWORD *)(a2 + 8);
    if ( (v6 & 1) != 0 && (v6 & 0x800) == 0 )
    {
      sub_54E81A((int)Buf, (int)"Duplicate gAMA chunk");
      goto LABEL_5;
    }
  }
  if ( a3 != 4 )
  {
    sub_54E81A((int)v3, (int)"Incorrect gAMA chunk length");
LABEL_5:
    sub_5557B6(v3, a3);
    return;
  }
  sub_554EE6(v3, (int)&Buf, 4);
  if ( !sub_5557B6(v3, 0) )
  {
    v7 = sub_554EC3((unsigned __int8 *)&Buf);
    if ( v7 )
    {
      if ( (*(_DWORD *)(v5 + 8) & 0x800) != 0 && fabs((double)(unsigned int)v7 - 45455.0) > 500.0 )
      {
        sub_54E81A((int)v3, (int)"Ignoring incorrect gAMA value when sRGB is also present");
      }
      else
      {
        v8 = (double)(unsigned int)v7 * 0.0000099999997;
        *((float *)v3 + 76) = v8;
        sub_5509E9((int)v3, v5, v8);
      }
    }
  }
}
