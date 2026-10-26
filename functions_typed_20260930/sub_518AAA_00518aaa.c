void __cdecl sub_518AAA(int a1, int a2, signed int a3)
{
  int v3; // esi
  int v4; // eax
  unsigned int v5; // edx
  int v6; // ebx
  char *v7; // eax
  _BYTE *v8; // edi
  int v9; // edi
  int v10; // [esp-1Ch] [ebp-28h]
  int v11; // [esp+4h] [ebp-8h]
  int v12; // [esp+8h] [ebp-4h]

  v3 = a1;
  v4 = *(_DWORD *)(a1 + 88);
  if ( (v4 & 1) != 0 )
  {
    if ( (v4 & 4) != 0 )
    {
      CallbackDispatch(a1, (int)"Invalid PLTE after IDAT");
LABEL_10:
      sub_518828(v3, a3);
      return;
    }
    if ( (v4 & 2) != 0 )
      GuardedCallWithLongjmp(a1, (int)"Duplicate PLTE chunk");
  }
  else
  {
    GuardedCallWithLongjmp(a1, (int)"Missing IHDR before PLTE");
  }
  v5 = a3 % 3u;
  *(_DWORD *)(v3 + 88) |= 2u;
  if ( v5 )
  {
    if ( *(_BYTE *)(v3 + 278) != 3 )
    {
      CallbackDispatch(v3, (int)"Invalid palette chunk");
      goto LABEL_10;
    }
    GuardedCallWithLongjmp(v3, (int)"Invalid palette chunk");
  }
  v6 = a3 / 3;
  v7 = sub_513C80(v3, a3 / 3, 3);
  *(_BYTE *)(v3 + 93) |= 0x10u;
  v11 = (int)v7;
  if ( v6 > 0 )
  {
    v8 = v7 + 2;
    v12 = v6;
    do
    {
      sub_517F58(v3, (int)&a1, 3);
      *((_WORD *)v8 - 1) = a1;
      *v8 = BYTE2(a1);
      v8 += 3;
      --v12;
    }
    while ( v12 );
  }
  sub_518828(v3, 0);
  v9 = a2;
  v10 = a2;
  *(_DWORD *)(v3 + 260) = v11;
  *(_WORD *)(v3 + 264) = v6;
  FlagSetterWithGuard(v3, v10, v11, v6);
  if ( *(_BYTE *)(v3 + 278) == 3
    && v9
    && (*(_BYTE *)(v9 + 8) & 0x10) != 0
    && *(_WORD *)(v3 + 266) > *(_WORD *)(v3 + 264) )
  {
    CallbackDispatch(v3, (int)"Truncating incorrect tRNS chunk length");
    *(_WORD *)(v3 + 266) = *(_WORD *)(v3 + 264);
  }
}

