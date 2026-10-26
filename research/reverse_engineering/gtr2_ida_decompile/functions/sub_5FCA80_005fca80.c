unsigned int __thiscall sub_5FCA80(unsigned int *this, int a2)
{
  unsigned int result; // eax

  if ( (*this & 0x100000) != 0 )
  {
    (*(void (__thiscall **)(int, _DWORD, int))(*(_DWORD *)dword_FB27A4 + 416))(
      dword_FB27A4,
      *(_DWORD *)(this[16] + 44),
      a2);
    result = *this & 0xFFEFFFFF;
    this[17] = 0;
    *this = result;
  }
  return result;
}
