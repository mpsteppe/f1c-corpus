int __thiscall sub_487430(int this)
{
  char Buffer[32]; // [esp+4h] [ebp-20h] BYREF

  sub_46FBE0((_DWORD *)this);
  sprintf(Buffer, "%d", **(_DWORD **)(this + 840) - 1);
  return sub_4A1AC0(Buffer);
}
