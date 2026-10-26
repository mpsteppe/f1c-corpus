int __thiscall sub_4B4D40(_DWORD *this)
{
  char Buffer[16]; // [esp+4h] [ebp-10h] BYREF

  sub_4B3B40(Buffer, 15);
  return sub_5A3FF0(Buffer, 4, 21, *(_DWORD *)(this[4] + 16), 0);
}
