int sub_4A4360()
{
  char *v0; // eax
  int v1; // esi
  char *v2; // eax
  char *v3; // eax
  char Buffer[64]; // [esp+8h] [ebp-C0h] BYREF
  char v6[128]; // [esp+48h] [ebp-80h] BYREF

  v0 = dword_B6F708;
  if ( !dword_B6F708 )
    v0 = (char *)WindowName;
  v1 = sub_539670(v0);
  if ( v1 )
  {
    v2 = sub_41D840(&byte_91CC38, (const char *)(v1 + 1980));
    sprintf(Buffer, "%s", v2);
    v3 = sub_41D840(&byte_91CC38, (const char *)(v1 + 1724));
    sprintf(v6, "%s %s", v3, Buffer);
    sub_4CE020(v6);
  }
  return 0;
}
