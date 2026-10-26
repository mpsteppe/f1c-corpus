int __thiscall sub_48D820(_DWORD **this)
{
  char Buffer[32]; // [esp+4h] [ebp-20h] BYREF

  sprintf(Buffer, "%d", *this[211]);
  sub_4CE770(Buffer);
  return 0;
}
