int sub_496A10()
{
  int v0; // edi
  char *v1; // eax
  int v3; // [esp-4h] [ebp-4Ch]
  char Buffer[64]; // [esp+8h] [ebp-40h] BYREF

  v0 = *(_DWORD *)ArgList;
  v3 = dword_B7623C;
  v1 = sub_41D840(&byte_91CC38, "of");
  sub_41D810(Buffer, 0x3Fu, "%d %s %d", v0, v1, v3);
  sub_4CE020(Buffer);
  return 0;
}
