int __fastcall sub_5BAB70(int a1, int a2)
{
  char Buffer[20]; // [esp+4h] [ebp-14h] BYREF

  sprintf(Buffer, "%d", a2);
  return sub_5BABA0(a1, Buffer);
}
