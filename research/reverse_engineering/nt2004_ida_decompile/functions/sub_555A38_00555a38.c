void __cdecl sub_555A38(jmp_buf Buf, int a2, int a3)
{
  int *__attribute__((__org_typedef(jmp_buf))) v3; // esi
  int v4; // eax
  unsigned int v5; // edx
  int v6; // ebx
  char *v7; // eax
  _BYTE *v8; // edi
  int v9; // edi
  int v10; // [esp-1Ch] [ebp-28h]
  int v11; // [esp+4h] [ebp-8h]
  int v12; // [esp+8h] [ebp-4h]

  v3 = Buf;
  v4 = Buf[22];
  if ( (v4 & 1) == 0 )
    sub_54E7FC(Buf, (int)"Missing IHDR before PLTE");
  if ( (v4 & 4) != 0 )
  {
    sub_54E81A((int)Buf, (int)"Invalid PLTE after IDAT");
LABEL_10:
    sub_5557B6(v3, a3);
    return;
  }
  if ( (v4 & 2) != 0 )
    sub_54E7FC(Buf, (int)"Duplicate PLTE chunk");
  v5 = a3 % 3u;
  Buf[22] |= 2u;
  if ( v5 )
  {
    if ( *((_BYTE *)v3 + 278) == 3 )
      sub_54E7FC(v3, (int)"Invalid palette chunk");
    sub_54E81A((int)v3, (int)"Invalid palette chunk");
    goto LABEL_10;
  }
  v6 = a3 / 3;
  v7 = sub_550C13(v3, a3 / 3, 3);
  *((_BYTE *)v3 + 93) |= 0x10u;
  v11 = (int)v7;
  if ( v6 > 0 )
  {
    v8 = v7 + 2;
    v12 = v6;
    do
    {
      sub_554EE6(v3, (int)&Buf, 3);
      *((_WORD *)v8 - 1) = (_WORD)Buf;
      *v8 = BYTE2(Buf);
      v8 += 3;
      --v12;
    }
    while ( v12 );
  }
  sub_5557B6(v3, 0);
  v9 = a2;
  v10 = a2;
  v3[65] = v11;
  *((_WORD *)v3 + 132) = v6;
  sub_550AA5((int)v3, v10, v11, v6);
  if ( *((_BYTE *)v3 + 278) == 3
    && v9
    && (*(_BYTE *)(v9 + 8) & 0x10) != 0
    && *((_WORD *)v3 + 133) > *((_WORD *)v3 + 132) )
  {
    sub_54E81A((int)v3, (int)"Truncating incorrect tRNS chunk length");
    *((_WORD *)v3 + 133) = *((_WORD *)v3 + 132);
  }
}
