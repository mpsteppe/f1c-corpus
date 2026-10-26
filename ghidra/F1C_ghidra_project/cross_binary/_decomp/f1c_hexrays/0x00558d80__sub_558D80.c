// f1c  0x00558d80  size=61
void __thiscall sub_558D80(_DWORD *this, int a2)
{
  int v3; // eax

  v3 = this[8];
  if ( (v3 & 0x100) != 0 )
  {
    this[8] = v3 & 0xFFFFFEFF;
    sub_540F90(dword_8B78A0, *(_DWORD *)(this[20] + (a2 << 6) + 28));
    *(_DWORD *)(this[20] + (a2 << 6) + 32) = 0;
  }
}
