// f1c  0x004b2c20  size=44
unsigned int __thiscall sub_4B2C20(int this, float a2)
{
  int v3; // esi
  unsigned int result; // eax

  v3 = *(_DWORD *)(this + 15);
  result = v3 & 0xFFFFFF03 ^ (4 * (sub_587BDC(a2 * 0.0180018) & 0x3F));
  *(_DWORD *)(this + 15) = result;
  return result;
}
