int sub_4A7E20()
{
  const char *v0; // eax
  char *v1; // eax
  char Buffer[32]; // [esp+4h] [ebp-20h] BYREF

  v0 = (const char *)sub_4CFC00(0);
  v1 = sub_41D840(&byte_91CC38, v0);
  sprintf(Buffer, "%d%s", dword_B6FF58, v1);
  sub_4CE770(Buffer);
  return 0;
}
