int sub_4968D0()
{
  int v0; // ebx
  int v1; // edi
  char *v3; // [esp-8h] [ebp-98h]
  int v4; // [esp-4h] [ebp-94h]
  char Buffer[125]; // [esp+10h] [ebp-80h] BYREF
  __int16 v6; // [esp+8Dh] [ebp-3h]
  char v7; // [esp+8Fh] [ebp-1h]

  v0 = dword_B76224;
  memset(Buffer, 0, sizeof(Buffer));
  v6 = 0;
  v7 = 0;
  v1 = dword_B76220;
  v4 = dword_B7622C;
  v3 = sub_41D840(&byte_91CC38, "of");
  sub_41D810(Buffer, 0x7Fu, off_16C9AB4, v1 + v0, v3, v4);
  sub_4CE020(Buffer);
  return 0;
}
