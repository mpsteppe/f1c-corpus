void __thiscall sub_5FEB00(unsigned int *this)
{
  unsigned int v2; // eax
  int v3; // ecx
  int v4; // ecx
  unsigned int v5; // eax

  if ( (*this & 0x10000) != 0 )
  {
    v2 = this[41];
    if ( v2 )
    {
      v3 = *(_DWORD *)(v2 + 12);
      if ( v3 <= 0 || (v4 = v3 - 1, (*(_DWORD *)(v2 + 12) = v4) == 0) )
        (*(void (__thiscall **)(int, unsigned int, _DWORD))(*(_DWORD *)dword_FB27A4 + 408))(dword_FB27A4, this[41], 0);
    }
    v5 = *this & 0xFFFEFFF3 | 0xC;
    this[41] = 0;
    this[38] = 0;
    *this = v5;
  }
}
