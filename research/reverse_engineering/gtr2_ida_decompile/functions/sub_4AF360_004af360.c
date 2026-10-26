int __usercall sub_4AF360@<eax>(int a1@<ecx>, int a2@<ebx>, __int32 a3@<ebp>)
{
  unsigned __int64 v4; // rax
  int v5; // ecx
  bool v6; // bl
  int v7; // eax
  int v8; // eax
  bool v9; // zf
  int i; // ebp
  char *v11; // eax
  char *v12; // eax
  char *v14; // eax
  char *v15; // eax
  char v17; // [esp+1Bh] [ebp-4Dh]
  void *v18; // [esp+1Ch] [ebp-4Ch]
  int v19; // [esp+20h] [ebp-48h]
  _BYTE v20[31]; // [esp+24h] [ebp-44h] BYREF
  char v21; // [esp+63h] [ebp-5h]

  LOBYTE(v19) = 1;
  HIBYTE(v18) = sub_4735E0(&dword_B6CBA8);
  if ( !HIBYTE(v18)
    || (v4 = (unsigned __int64)(flt_FADE20 - dbl_FB1D18), (v4 & 0x80000000) == 0LL)
    || (int)abs32(v4) <= dword_B73648 )
  {
LABEL_10:
    v5 = *(_DWORD *)dword_B640C8;
    goto LABEL_11;
  }
  v5 = *(_DWORD *)dword_B640C8;
  if ( *(int *)dword_B640C8 > 0 && *(int *)dword_B640C8 <= 5 )
  {
    if ( dword_B640C0 != 5
      && (unsigned __int8)sub_5612D0((int)byte_FAE910, 2, "\\Dev\\Src\\Copperhead\\App\\Source\\O_AppGz.cpp", 7097) )
    {
      sub_561210(
        (int)byte_FAE910,
        "Auto Advancing Server Session (%d) at et %.3f after %d seconds past session end",
        dword_B640C8[0]);
    }
    sub_49BEE0(a1, a3, 1);
    goto LABEL_10;
  }
LABEL_11:
  v6 = !byte_B722E4 || *(_DWORD *)dword_B72314 == 4;
  if ( (*(_DWORD *)dword_B72314 == 3 || *(_DWORD *)dword_B72314 == 4) && v5 > 0 && v5 <= 5 )
    LOBYTE(v19) = 0;
  if ( (unsigned __int8)sub_4735E0(&dword_B6CBA8) )
    LOBYTE(v19) = 0;
  (*(void (__thiscall **)(int, int, int))(*(_DWORD *)a1 + 36))(a1, v19, a2);
  v7 = *(_DWORD *)dword_B72314;
  if ( (*(_DWORD *)dword_B72314 != 5 || v17) && v6 )
  {
    while ( 1 )
    {
      switch ( *(_DWORD *)dword_B640C8 )
      {
        case 1:
          if ( !byte_B6FEBC && v7 != 4 )
            goto LABEL_48;
          v8 = sub_616840("SkipPractice1");
          goto LABEL_46;
        case 2:
          if ( !byte_B6FED4 && v7 != 4 )
            goto LABEL_48;
          v8 = sub_616840("SkipPractice2");
          goto LABEL_46;
        case 3:
          if ( !byte_B6FEEC && v7 != 4 )
            goto LABEL_48;
          v8 = sub_616840("SkipQualifying1");
          goto LABEL_46;
        case 4:
          if ( !byte_B6FF04 && v7 != 4 )
            goto LABEL_48;
          v8 = sub_616840("SkipQualifying2");
          goto LABEL_46;
        case 5:
          if ( v17 && !byte_B6FEBC && !byte_B6FED4 && !byte_B6FEEC && !byte_B6FF04 )
            goto LABEL_49;
          if ( !byte_B6FF1C && v7 != 4 )
            goto LABEL_48;
          v8 = sub_616840("SkipWarmup");
LABEL_46:
          v9 = v8 == 0;
          v7 = *(_DWORD *)dword_B72314;
          if ( v9 || *(_DWORD *)dword_B72314 != 4 )
            goto LABEL_49;
LABEL_48:
          sub_49BEE0(a1, a3, 0);
          v7 = *(_DWORD *)dword_B72314;
          break;
        default:
          goto LABEL_49;
      }
    }
  }
LABEL_49:
  if ( *(_DWORD *)dword_B640C8 && *(_DWORD *)dword_B640C8 != 6 )
  {
    if ( v7 == 4 )
    {
      BYTE1(v19) = sub_616840("SkipWarmup") == 0;
      LOBYTE(v19) = sub_616840("SkipQualifying2") == 0;
      HIBYTE(v18) = sub_616840("SkipQualifying1") == 0;
      BYTE2(v18) = sub_616840("SkipPractice2") == 0;
    }
    else
    {
      if ( byte_B722E4 )
      {
        v18 = &nullsub_12;
        LOWORD(v19) = (unsigned __int16)&nullsub_12;
        BYTE2(v19) = (unsigned __int8)&nullsub_12;
LABEL_57:
        for ( i = *(_DWORD *)dword_B640C8 + 1; i < 7; ++i )
        {
          if ( *((_BYTE *)&v18 + i) == 1 )
            break;
        }
        if ( !(unsigned __int8)sub_4735A0() || (unsigned __int8)sub_4735E0(&dword_B6CBA8) )
        {
          v12 = sub_41D840(&byte_91CC38, "CONTINUE TO");
          sub_630FE0(v20, v12, 31);
        }
        else
        {
          v11 = sub_41D840(&byte_91CC38, "NEXT SESSION:");
          sub_630FE0(v20, v11, 31);
        }
        return off_16C97DC();
      }
      BYTE1(v19) = byte_B6FF1C;
      LOBYTE(v19) = byte_B6FF04;
      HIBYTE(v18) = byte_B6FEEC;
      BYTE2(v18) = byte_B6FED4;
    }
    BYTE2(v19) = 1;
    goto LABEL_57;
  }
  sub_615860(WindowName);
  sub_615860(WindowName);
  if ( *(_DWORD *)dword_B640C8 == 6 && (unsigned __int8)sub_4735A0() && (unsigned __int8)sub_4735E0(&dword_B6CBA8) )
  {
    v14 = sub_41D840(&byte_91CC38, "RESTART");
    sub_630FE0(v20, v14, 63);
    v21 = 0;
    sub_615860(v20);
    v15 = sub_41D840(&byte_91CC38, "RACE");
    sub_630FE0(v20, v15, 63);
    v21 = 0;
    sub_615860(v20);
  }
  return 0;
}
