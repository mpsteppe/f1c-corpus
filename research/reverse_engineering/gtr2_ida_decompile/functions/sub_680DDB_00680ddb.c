BOOL __thiscall sub_680DDB(_DWORD *this)
{
  unsigned int v1; // eax

  v1 = *this & 0xFFF00000;
  return v1 == 0x20000000 || v1 == 537919488 || v1 == 541065216 || v1 == 542113792 || v1 == 1342177280;
}
