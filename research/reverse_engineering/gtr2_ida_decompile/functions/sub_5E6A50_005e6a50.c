int __thiscall sub_5E6A50(int *this, int a2, int a3, int a4)
{
  int v5; // eax
  int v7; // ecx
  int v8; // eax
  int v9; // esi
  int v10; // edi
  int v11; // eax

  v5 = *this;
  if ( (*this & 4) != 0 )
    return 0;
  if ( (v5 & 2) == 0 )
    return 128;
  v7 = this[12];
  if ( (**(_BYTE **)(v7 + 392) & 2) != 0 || (*(_BYTE *)v7 & 8) != 0 )
    return 128;
  if ( (v5 & 0x4000) != 0 && a4 )
    *this = v5 | 0x40;
  v8 = *this;
  if ( (*this & 0x40) != 0 )
  {
    *(_DWORD *)this[11] |= 4u;
    if ( a4 )
    {
      v10 = sub_5FFF80(this[11], a2, 0, 0, 1);
      *(_DWORD *)this[11] |= 0x104u;
      v11 = sub_5FFCF0(0, 0, a4, 0);
      *(_DWORD *)this[11] &= ~0x100u;
    }
    else
    {
      v10 = sub_6004D0(a2, 0, 0);
      v11 = 16;
    }
    if ( (*(_BYTE *)this[11] & 4) == 0 )
      *this &= ~0x40u;
    if ( v10 == 16 && v11 == 16 )
      return 128;
  }
  else
  {
    if ( (v8 & 4) != 0 )
      v9 = *(_DWORD *)(this[16] + 44);
    else
      v9 = this[11];
    if ( !*(_DWORD *)(v9 + 152) || (v8 & 0x80u) != 0 )
      return 128;
  }
  ++dword_FB2E94;
  return 0;
}
