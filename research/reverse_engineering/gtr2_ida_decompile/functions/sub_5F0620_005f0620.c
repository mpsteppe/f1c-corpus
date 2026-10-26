int __thiscall sub_5F0620(_DWORD *this)
{
  int v2; // eax
  int v3; // ecx
  int v4; // ecx

  if ( (this[4] & 1) != 0 )
  {
    v2 = this[41];
    if ( v2 )
    {
      v3 = *(_DWORD *)(v2 + 12);
      if ( v3 <= 0 || (v4 = v3 - 1, (*(_DWORD *)(v2 + 12) = v4) == 0) )
        (*(void (__thiscall **)(int, _DWORD, int))(*(_DWORD *)dword_FB27A4 + 408))(dword_FB27A4, this[41], 0x2000);
    }
    this[41] = 0;
    this[4] &= ~0x100000u;
  }
  return 0;
}
