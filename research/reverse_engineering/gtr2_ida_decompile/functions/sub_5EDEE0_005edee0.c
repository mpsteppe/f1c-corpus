unsigned int __thiscall sub_5EDEE0(unsigned int *this)
{
  unsigned int v2; // eax
  int v3; // ecx
  int v4; // ecx
  unsigned int result; // eax

  v2 = this[8];
  if ( v2 )
  {
    v3 = *(_DWORD *)(v2 + 12);
    if ( v3 <= 0 || (v4 = v3 - 1, (*(_DWORD *)(v2 + 12) = v4) == 0) )
      (*(void (__thiscall **)(int, unsigned int, _DWORD))(*(_DWORD *)dword_FB27A4 + 408))(dword_FB27A4, this[8], 0);
  }
  result = *this & 0xFFFFFFCF | 0x20;
  this[8] = 0;
  *this = result;
  return result;
}
