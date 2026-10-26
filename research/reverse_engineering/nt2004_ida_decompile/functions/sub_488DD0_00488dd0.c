int sub_488DD0()
{
  char Buffer[32]; // [esp+Ch] [ebp-20h] BYREF

  sprintf(Buffer, "%.1f", *(float *)&dword_76782C);
  sub_4A1AC0(Buffer);
  return 0;
}
