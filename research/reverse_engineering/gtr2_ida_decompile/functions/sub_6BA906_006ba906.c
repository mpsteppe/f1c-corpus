void __stdcall sub_6BA906(int a1, int a2, signed int a3)
{
  int v4; // eax
  unsigned int v5; // edx
  int v6; // ebx
  char *v7; // eax
  _BYTE *v8; // edi
  int v9; // [esp+4h] [ebp-4h]
  int v10; // [esp+10h] [ebp+8h]

  v4 = *(_DWORD *)(a1 + 88);
  if ( (v4 & 1) == 0 )
    sub_679F05(a1, (int)"Missing IHDR before PLTE");
  if ( (v4 & 4) != 0 )
  {
    sub_679F26(a1, (int)"Invalid PLTE after IDAT");
LABEL_10:
    sub_6BA69B(a1, a3);
    return;
  }
  if ( (v4 & 2) != 0 )
    sub_679F05(a1, (int)"Duplicate PLTE chunk");
  v5 = a3 % 3u;
  *(_DWORD *)(a1 + 88) |= 2u;
  if ( v5 )
  {
    if ( *(_BYTE *)(a1 + 278) == 3 )
      sub_679F05(a1, (int)"Invalid palette chunk");
    sub_679F26(a1, (int)"Invalid palette chunk");
    goto LABEL_10;
  }
  v6 = a3 / 3;
  v7 = sub_679FD8(a1, a3 / 3, 3);
  *(_BYTE *)(a1 + 93) |= 0x10u;
  v9 = (int)v7;
  if ( v6 > 0 )
  {
    v8 = v7 + 2;
    v10 = v6;
    do
    {
      sub_6B9DC1(a1, (int)&a3, 3);
      *((_WORD *)v8 - 1) = a3;
      *v8 = BYTE2(a3);
      v8 += 3;
      --v10;
    }
    while ( v10 );
  }
  sub_6BA69B(a1, 0);
  *(_DWORD *)(a1 + 260) = v9;
  *(_WORD *)(a1 + 264) = v6;
  sub_67A946(a1, a2, v9, v6);
  if ( *(_BYTE *)(a1 + 278) == 3
    && a2
    && (*(_BYTE *)(a2 + 8) & 0x10) != 0
    && *(_WORD *)(a1 + 266) > *(_WORD *)(a1 + 264) )
  {
    sub_679F26(a1, (int)"Truncating incorrect tRNS chunk length");
    *(_WORD *)(a1 + 266) = *(_WORD *)(a1 + 264);
  }
}
