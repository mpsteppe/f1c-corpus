int __thiscall sub_49DE40(_DWORD *this, char a2)
{
  int result; // eax
  int v4; // edi
  bool v5; // bl
  int v6; // eax
  char v7; // al
  char v8; // al
  bool v9; // zf
  _BYTE v10[16]; // [esp+50h] [ebp-10h] BYREF

  result = this[5];
  if ( !result )
    return result;
  v4 = *(_DWORD *)(result + 84);
  if ( !v4 || !this[7] )
    return result;
  v5 = sub_587BDC(dbl_8AFEA0) % 2 == 0;
  if ( a2 )
    return sub_5432F0(0.0, 0.0, v4, 0.0, 0.0, 1.0, 1.0, 0, 0);
  sub_5432F0(0.0, 0.0, v4, 0.0, 0.0, 1.0, 1.0, 0, 0);
  v6 = dword_7C54E0;
  if ( !*(_DWORD *)(dword_7C54E0 + 3284) )
    goto LABEL_12;
  if ( !*(_BYTE *)(dword_7C54E0 + 3348) && !v5 )
    goto LABEL_14;
  if ( *(_DWORD *)(dword_7C54E0 + 3284) && *(_BYTE *)(dword_7C54E0 + 3348) )
    v7 = 1;
  else
LABEL_12:
    v7 = 0;
  sub_543440(195, 26, 18, 53, v7 != 0 ? -16711936 : -65536);
  v6 = dword_7C54E0;
LABEL_14:
  if ( !*(_DWORD *)(v6 + 3352) )
    goto LABEL_20;
  if ( !*(_BYTE *)(v6 + 3416) && !v5 )
    goto LABEL_22;
  if ( *(_DWORD *)(v6 + 3352) && *(_BYTE *)(v6 + 3416) )
    v8 = 1;
  else
LABEL_20:
    v8 = 0;
  sub_543440(42, 35, 14, 35, v8 != 0 ? -16711936 : -65536);
LABEL_22:
  sub_49E570(2, 48, 16, 25, 15);
  sub_49E570(0, 164, 16, 25, 15);
  sub_49E570(3, 48, 74, 25, 15);
  sub_49E570(1, 164, 74, 25, 15);
  sub_49E7B0(2, 48, 4, 25, 7);
  sub_49E7B0(0, 164, 4, 25, 7);
  sub_49E7B0(3, 48, 94, 25, 7);
  sub_49E7B0(1, 164, 94, 25, 7);
  if ( *(_DWORD *)(dword_7C54F0[dword_7C54DC] + 18580) != *(_DWORD *)(dword_7C54F0[dword_7C54E4] + 18580)
    || (v9 = byte_7C8B40 == 0, byte_7C8B40 = 0, v9) )
  {
    sub_543440(59, 49, 46, 6, -16711936);
  }
  else
  {
    sub_543440(59, 49, 46, 6, -256);
  }
  sub_543440(87, 45, 16, 13, 65280);
  result = this[2];
  if ( result )
  {
    sub_49C700((int)v10, 15);
    sub_49F6A0(v10, 58, 105, this[2], *(_DWORD *)(this[5] + 84), 1);
    sub_49C770((int)v10, 15);
    sub_49F6A0(v10, 66, 105, this[2], *(_DWORD *)(this[5] + 84), 0);
    sub_49C830((int)v10, 15);
    sub_49F6A0(v10, 184, 105, this[2], *(_DWORD *)(this[5] + 84), 1);
    sub_49C8A0((int)v10, 15);
    return sub_49F6A0(v10, 192, 105, this[2], *(_DWORD *)(this[5] + 84), 0);
  }
  return result;
}
