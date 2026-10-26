// f1c  0x004c69b0  size=47
int __thiscall sub_4C69B0(_DWORD *this, int a2)
{
  _DWORD *v3; // esi
  int result; // eax

  v3 = this + 4546;
  sub_587DD0(this + 4546, a2, 7);
  *((_BYTE *)v3 + 7) = 0;
  result = sub_587ECE(v3);
  this[4548] = result;
  return result;
}
