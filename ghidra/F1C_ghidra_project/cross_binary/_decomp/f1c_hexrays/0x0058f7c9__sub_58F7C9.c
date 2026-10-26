// f1c  0x0058f7c9  size=290
int __cdecl sub_58F7C9(int a1)
{
  LCID v1; // edi
  int v3; // ebx
  int v4; // ebx
  int v5; // ebx
  int v6; // ebx
  int v7; // ebx
  int v8; // ebx
  int v9; // ebx
  int v10; // ebx
  int v11; // ebx
  int v12; // ebx
  int v13; // ebx
  int v14; // ebx
  int v15; // ebx
  int v16; // ebx

  v1 = (unsigned __int16)word_8D3F88;
  if ( !a1 )
    return -1;
  v3 = sub_5968F6(1, (unsigned __int16)word_8D3F88, 0x15u, a1 + 12);
  v4 = sub_5968F6(1, v1, 0x14u, a1 + 16) | v3;
  v5 = sub_5968F6(1, v1, 0x16u, a1 + 20) | v4;
  v6 = sub_5968F6(1, v1, 0x17u, a1 + 24) | v5;
  v7 = sub_5968F6(1, v1, 0x18u, a1 + 28) | v6;
  sub_58F6C7(*(char **)(a1 + 28));
  v8 = sub_5968F6(1, v1, 0x50u, a1 + 32) | v7;
  v9 = sub_5968F6(1, v1, 0x51u, a1 + 36) | v8;
  v10 = sub_5968F6(0, v1, 0x1Au, a1 + 40) | v9;
  v11 = sub_5968F6(0, v1, 0x19u, a1 + 41) | v10;
  v12 = sub_5968F6(0, v1, 0x54u, a1 + 42) | v11;
  v13 = sub_5968F6(0, v1, 0x55u, a1 + 43) | v12;
  v14 = sub_5968F6(0, v1, 0x56u, a1 + 44) | v13;
  v15 = sub_5968F6(0, v1, 0x57u, a1 + 45) | v14;
  v16 = sub_5968F6(0, v1, 0x52u, a1 + 46) | v15;
  return v16 | sub_5968F6(0, v1, 0x53u, a1 + 47);
}
