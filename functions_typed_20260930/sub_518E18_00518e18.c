void __cdecl sub_518E18(int a1, int a2, unsigned int a3)
{
  int v3; // eax
  char v4; // al
  int v5; // eax
  __int16 v6; // cx
  __int16 v7; // ax
  __int16 v8; // cx
  unsigned __int8 v9; // [esp+8h] [ebp-8h] BYREF
  unsigned __int8 v10; // [esp+9h] [ebp-7h]
  unsigned __int8 v11; // [esp+Ah] [ebp-6h]
  unsigned __int8 v12; // [esp+Bh] [ebp-5h]
  unsigned __int8 v13; // [esp+Ch] [ebp-4h]
  unsigned __int8 v14; // [esp+Dh] [ebp-3h]

  v3 = *(_DWORD *)(a1 + 88);
  if ( (v3 & 1) == 0 )
  {
    GuardedCallWithLongjmp(a1, (int)"Missing IHDR before tRNS");
    goto LABEL_3;
  }
  if ( (v3 & 4) != 0 )
  {
    CallbackDispatch(a1, (int)"Invalid tRNS after IDAT");
LABEL_13:
    sub_518828(a1, a3);
    return;
  }
  if ( a2 && (*(_BYTE *)(a2 + 8) & 0x10) != 0 )
  {
    CallbackDispatch(a1, (int)"Duplicate tRNS chunk");
    goto LABEL_13;
  }
LABEL_3:
  v4 = *(_BYTE *)(a1 + 278);
  if ( v4 == 3 )
  {
    if ( (*(_BYTE *)(a1 + 88) & 2) != 0 )
    {
      if ( a3 > *(unsigned __int16 *)(a1 + 264) )
      {
        CallbackDispatch(a1, (int)"Incorrect tRNS chunk length");
        sub_518828(a1, a3);
        return;
      }
    }
    else
    {
      CallbackDispatch(a1, (int)"Missing PLTE before tRNS");
    }
    if ( !a3 )
    {
      CallbackDispatch(a1, (int)"Zero length tRNS chunk");
      sub_518828(a1, 0);
      return;
    }
    v5 = sub_517E92(a1, a3);
    *(_BYTE *)(a1 + 93) |= 0x20u;
    *(_DWORD *)(a1 + 348) = v5;
    sub_517F58(a1, v5, a3);
    *(_WORD *)(a1 + 266) = a3;
    goto LABEL_25;
  }
  if ( v4 != 2 )
  {
    if ( v4 )
    {
      CallbackDispatch(a1, (int)"tRNS chunk not allowed with alpha channel");
      goto LABEL_28;
    }
    if ( a3 == 2 )
    {
      sub_517F58(a1, (int)&v9, 2);
      *(_WORD *)(a1 + 360) = v10 + (v9 << 8);
      goto LABEL_24;
    }
LABEL_22:
    CallbackDispatch(a1, (int)"Incorrect tRNS chunk length");
LABEL_28:
    sub_518828(a1, a3);
    return;
  }
  if ( a3 != 6 )
    goto LABEL_22;
  sub_517F58(a1, (int)&v9, 6);
  v6 = v12;
  *(_WORD *)(a1 + 354) = v10 + (v9 << 8);
  v7 = v6 + (v11 << 8);
  v8 = v14;
  *(_WORD *)(a1 + 356) = v7;
  *(_WORD *)(a1 + 358) = v8 + (v13 << 8);
LABEL_24:
  *(_WORD *)(a1 + 266) = 1;
LABEL_25:
  if ( !sub_518828(a1, 0) )
    MultiFieldSetterWithFlag(a1, a2, *(_DWORD *)(a1 + 348), *(unsigned __int16 *)(a1 + 266), a1 + 352);
}

