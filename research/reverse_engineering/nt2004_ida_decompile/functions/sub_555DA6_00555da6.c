void __cdecl sub_555DA6(jmp_buf Buf, int a2, size_t Size)
{
  int v3; // eax
  char v4; // al
  void *v5; // eax
  __int16 v6; // cx
  __int16 v7; // ax
  __int16 v8; // cx
  unsigned __int8 v9; // [esp+8h] [ebp-8h] BYREF
  unsigned __int8 v10; // [esp+9h] [ebp-7h]
  unsigned __int8 v11; // [esp+Ah] [ebp-6h]
  unsigned __int8 v12; // [esp+Bh] [ebp-5h]
  unsigned __int8 v13; // [esp+Ch] [ebp-4h]
  unsigned __int8 v14; // [esp+Dh] [ebp-3h]

  v3 = Buf[22];
  if ( (v3 & 1) == 0 )
    sub_54E7FC(Buf, (int)"Missing IHDR before tRNS");
  if ( (v3 & 4) != 0 )
  {
    sub_54E81A((int)Buf, (int)"Invalid tRNS after IDAT");
LABEL_13:
    sub_5557B6(Buf, Size);
    return;
  }
  if ( a2 && (*(_BYTE *)(a2 + 8) & 0x10) != 0 )
  {
    sub_54E81A((int)Buf, (int)"Duplicate tRNS chunk");
    goto LABEL_13;
  }
  v4 = *((_BYTE *)Buf + 278);
  if ( v4 == 3 )
  {
    if ( (Buf[22] & 2) != 0 )
    {
      if ( Size > *((unsigned __int16 *)Buf + 132) )
      {
        sub_54E81A((int)Buf, (int)"Incorrect tRNS chunk length");
        sub_5557B6(Buf, Size);
        return;
      }
    }
    else
    {
      sub_54E81A((int)Buf, (int)"Missing PLTE before tRNS");
    }
    if ( !Size )
    {
      sub_54E81A((int)Buf, (int)"Zero length tRNS chunk");
      sub_5557B6(Buf, 0);
      return;
    }
    v5 = sub_554E20(Buf, Size);
    *((_BYTE *)Buf + 93) |= 0x20u;
    Buf[87] = (int)v5;
    sub_554EE6(Buf, (int)v5, Size);
    *((_WORD *)Buf + 133) = Size;
    goto LABEL_25;
  }
  if ( v4 != 2 )
  {
    if ( v4 )
    {
      sub_54E81A((int)Buf, (int)"tRNS chunk not allowed with alpha channel");
      goto LABEL_28;
    }
    if ( Size == 2 )
    {
      sub_554EE6(Buf, (int)&v9, 2);
      *((_WORD *)Buf + 180) = v10 + (v9 << 8);
      goto LABEL_24;
    }
LABEL_22:
    sub_54E81A((int)Buf, (int)"Incorrect tRNS chunk length");
LABEL_28:
    sub_5557B6(Buf, Size);
    return;
  }
  if ( Size != 6 )
    goto LABEL_22;
  sub_554EE6(Buf, (int)&v9, 6);
  v6 = v12;
  *((_WORD *)Buf + 177) = v10 + (v9 << 8);
  v7 = v6 + (v11 << 8);
  v8 = v14;
  *((_WORD *)Buf + 178) = v7;
  *((_WORD *)Buf + 179) = v8 + (v13 << 8);
LABEL_24:
  *((_WORD *)Buf + 133) = 1;
LABEL_25:
  if ( !sub_5557B6(Buf, 0) )
    sub_550B1D((int)Buf, a2, Buf[87], *((unsigned __int16 *)Buf + 133), (int)(Buf + 88));
}
