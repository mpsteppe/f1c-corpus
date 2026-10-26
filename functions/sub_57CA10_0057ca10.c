char __stdcall sub_57CA10(const char *a1, int a2)
{
  char *v2; // eax
  char *v3; // eax
  unsigned __int8 *v4; // eax
  unsigned __int8 *v5; // eax
  unsigned __int8 *v6; // eax
  char v7; // bl
  unsigned __int8 *v8; // eax
  char v10; // [esp+3h] [ebp-69h]
  unsigned __int8 v11[8]; // [esp+4h] [ebp-68h] BYREF
  _BYTE v12[32]; // [esp+Ch] [ebp-60h] BYREF
  char v13[64]; // [esp+2Ch] [ebp-40h] BYREF
  char v14; // [esp+70h] [ebp+4h]

  v13[0] = 0;
  strcpy(v13, a1);
  v2 = sub_5897CA(v13, byte_5C3F6C);
  if ( !v2 )
    return 0;
  v12[0] = 0;
  sub_587DD0(v12, v2, 0x1Fu);
  v12[31] = 0;
  v3 = sub_5897CA(0, byte_5C3F6C);
  if ( !v3 )
    return 0;
  v11[0] = 0;
  sub_587DD0(v11, v3, 7u);
  v11[7] = 0;
  v4 = sub_5897CA(v12, (char *)&word_5BEB48);
  if ( !v4 )
    return 0;
  v14 = sub_587ECE(v4);
  v5 = sub_5897CA(0, (char *)&word_5BEB48);
  if ( !v5 )
    return 0;
  v10 = sub_587ECE(v5);
  v6 = sub_5897CA(0, (char *)&word_5BEB48);
  if ( !v6 )
    return 0;
  v7 = sub_587ECE(v6);
  v8 = sub_5897CA(0, (char *)&word_5BEB48);
  if ( !v8 )
    return 0;
  *(_BYTE *)(a2 + 7) = sub_587ECE(v8);
  *(_BYTE *)(a2 + 4) = v14;
  *(_BYTE *)(a2 + 5) = v10;
  *(_BYTE *)(a2 + 6) = v7;
  *(_WORD *)(a2 + 2) = sub_587ECE(v11);
  return 1;
}
