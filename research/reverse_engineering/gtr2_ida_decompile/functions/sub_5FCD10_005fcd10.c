void __thiscall sub_5FCD10(_DWORD *this, int a2, int a3, int a4, int a5)
{
  int v6; // eax
  int v7; // ecx
  int v8; // eax

  if ( a2 < this[11] )
  {
    v6 = this[13];
    v7 = *(_DWORD *)(v6 + 132 * a2);
    v8 = 132 * a2 + v6;
    if ( (v7 & 0x100) != 0 )
    {
      sub_5D83E0((int *)(v8 + 20), a3, a4, a5);
      *(_DWORD *)(132 * a2 + this[13]) = *(_DWORD *)(this[13] + 132 * a2) | 0x40000;
      *this &= ~0x400000u;
    }
  }
}
