int sub_49BAC0()
{
  const char *v0; // eax
  char Buffer[256]; // [esp+8h] [ebp-100h] BYREF

  sub_4EC220(&unk_B6F135);
  if ( sub_534F50(&unk_B76270) != 3 )
    return 0;
  v0 = (const char *)dword_91CAD0;
  if ( !dword_91CAD0 )
    v0 = WindowName;
  sprintf(Buffer, "%s%s", v0, "FIAShort.bik");
  sub_590B70(&unk_FB1E98, Buffer, 1);
  sub_4CD6D0("CHAMPIONSHIP MAIN");
  return -1;
}
