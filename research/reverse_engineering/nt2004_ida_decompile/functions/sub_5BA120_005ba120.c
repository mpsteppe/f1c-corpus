int __thiscall sub_5BA120(_DWORD *this, int a2)
{
  char Buffer[20]; // [esp+8h] [ebp-14h] BYREF

  sprintf(Buffer, "%d", a2);
  return sub_5BA0E0(this, (int)Buffer);
}
