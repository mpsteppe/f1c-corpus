int __thiscall sub_4A23B0(_DWORD *this)
{
  int v3; // [esp-4h] [ebp-28h]
  char Buffer[32]; // [esp+4h] [ebp-20h] BYREF

  v3 = dword_B70888;
  this[207] = dword_B70888 <= 16 ? 0 : 2;
  sprintf(Buffer, "%d", v3);
  sub_4CE770(Buffer);
  return sub_4D2320(this);
}
