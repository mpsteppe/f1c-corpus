int __thiscall sub_55D530(_DWORD *this, int a2)
{
  int result; // eax
  int v3; // [esp-8h] [ebp-8h]

  v3 = this[1];
  this[20] = a2;
  sub_5416A0(dword_8B78A0, (int)this, v3, 7);
  result = dword_8B8F28;
  *(_DWORD *)(dword_8B8F28 + 236) |= 0x800u;
  return result;
}
