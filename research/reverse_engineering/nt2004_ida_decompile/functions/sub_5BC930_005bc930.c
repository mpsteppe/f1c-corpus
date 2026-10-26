int __fastcall sub_5BC930(char *a1, int a2, __int16 a3)
{
  u_short v6; // [esp+8h] [ebp-10h] BYREF
  char v7; // [esp+Ah] [ebp-Eh]
  int v8; // [esp+Bh] [ebp-Dh]
  __int16 v9; // [esp+Fh] [ebp-9h]

  if ( *(_DWORD *)a1 == 1 )
  {
    sub_5BC220(a1, 0, 0, 2u, 0);
    if ( *(_DWORD *)a1 == 1 )
      return 3;
  }
  v6 = htons(9u);
  v7 = 1;
  v8 = a2;
  v9 = a3;
  return sub_5BC9A0(a1, &v6, 9);
}
