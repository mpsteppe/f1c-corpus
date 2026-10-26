void __stdcall sub_6BAC50(int a1, int a2, size_t Size)
{
  int v3; // eax
  char v4; // al
  void *v5; // eax
  unsigned __int8 v6[2]; // [esp+8h] [ebp-8h] BYREF
  unsigned __int8 v7[2]; // [esp+Ah] [ebp-6h] BYREF
  unsigned __int8 v8[4]; // [esp+Ch] [ebp-4h] BYREF

  v3 = *(_DWORD *)(a1 + 88);
  if ( (v3 & 1) == 0 )
    sub_679F05(a1, (int)"Missing IHDR before tRNS");
  if ( (v3 & 4) != 0 )
  {
    sub_679F26(a1, (int)"Invalid tRNS after IDAT");
LABEL_13:
    sub_6BA69B(a1, Size);
    return;
  }
  if ( a2 && (*(_BYTE *)(a2 + 8) & 0x10) != 0 )
  {
    sub_679F26(a1, (int)"Duplicate tRNS chunk");
    goto LABEL_13;
  }
  v4 = *(_BYTE *)(a1 + 278);
  if ( v4 == 3 )
  {
    if ( (*(_BYTE *)(a1 + 88) & 2) != 0 )
    {
      if ( Size > *(unsigned __int16 *)(a1 + 264) )
      {
        sub_679F26(a1, (int)"Incorrect tRNS chunk length");
        sub_6BA69B(a1, Size);
        return;
      }
    }
    else
    {
      sub_679F26(a1, (int)"Missing PLTE before tRNS");
    }
    if ( !Size )
    {
      sub_679F26(a1, (int)"Zero length tRNS chunk");
      sub_6BA69B(a1, 0);
      return;
    }
    v5 = sub_6B7269(a1, Size);
    *(_BYTE *)(a1 + 93) |= 0x20u;
    *(_DWORD *)(a1 + 348) = v5;
    sub_6B9DC1(a1, (int)v5, Size);
    *(_WORD *)(a1 + 266) = Size;
    goto LABEL_24;
  }
  if ( v4 == 2 )
  {
    if ( Size == 6 )
    {
      sub_6B9DC1(a1, (int)v6, 6);
      *(_WORD *)(a1 + 266) = 1;
      *(_WORD *)(a1 + 354) = sub_6B9DA7((int)v6, v6);
      *(_WORD *)(a1 + 356) = sub_6B9DA7((int)v7, v7);
      *(_WORD *)(a1 + 358) = sub_6B9DA7((int)v8, v8);
      goto LABEL_24;
    }
    goto LABEL_22;
  }
  if ( v4 )
  {
    sub_679F26(a1, (int)"tRNS chunk not allowed with alpha channel");
    goto LABEL_27;
  }
  if ( Size != 2 )
  {
LABEL_22:
    sub_679F26(a1, (int)"Incorrect tRNS chunk length");
LABEL_27:
    sub_6BA69B(a1, Size);
    return;
  }
  sub_6B9DC1(a1, (int)v6, 2);
  *(_WORD *)(a1 + 266) = 1;
  *(_WORD *)(a1 + 360) = sub_6B9DA7((int)v6, v6);
LABEL_24:
  if ( !sub_6BA69B(a1, 0) )
    sub_67A9C7(a1, a2, *(_DWORD *)(a1 + 348), *(unsigned __int16 *)(a1 + 266), a1 + 352);
}
