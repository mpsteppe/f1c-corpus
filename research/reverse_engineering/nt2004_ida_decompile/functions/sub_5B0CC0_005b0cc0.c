void __thiscall sub_5B0CC0(_DWORD *this, int a2)
{
  int v3; // eax

  v3 = this[8];
  if ( (v3 & 0x100) != 0 )
  {
    this[8] = v3 & 0xFFFFFEFF;
    sub_5A80B0(dword_7E6B48, *(_DWORD *)(this[20] + (a2 << 6) + 28));
    *(_DWORD *)(this[20] + (a2 << 6) + 32) = 0;
  }
}
