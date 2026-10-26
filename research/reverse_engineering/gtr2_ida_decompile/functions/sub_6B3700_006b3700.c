int __thiscall sub_6B3700(_DWORD *this, int a2)
{
  int v2; // eax

  v2 = *(_DWORD *)(*(_DWORD *)(this[4] + 4 * *(_DWORD *)(a2 + 4)) + 4);
  if ( (v2 & 0x100) != 0 )
    return sub_6C9357(1);
  if ( (v2 & 0x200) != 0 && (v2 & 0x80u) != 0 )
    return sub_6C9357(9);
  if ( (v2 & 0x200) != 0 )
    return sub_6C9357(2);
  if ( (v2 & 0x10) != 0 )
    return sub_6C9357(3);
  if ( (*(_DWORD *)(*(_DWORD *)(this[4] + 4 * *(_DWORD *)(a2 + 4)) + 4) & 0x2020) == 0x2020 )
    return sub_6C9357(5);
  if ( (v2 & 0x40020) == 0x40020 )
    return sub_6C9357(6);
  if ( (v2 & 0x20) != 0 )
    return sub_6C9357(4);
  if ( (v2 & 1) != 0 )
  {
    if ( (v2 & 2) != 0 )
      return sub_6C9357(7);
  }
  else if ( (v2 & 2) != 0 && (v2 & 4) != 0 )
  {
    return sub_6C9357(8);
  }
  if ( (v2 & 0x10000) != 0 )
    sub_686791(
      (int)this,
      *(_DWORD *)(*(_DWORD *)(this[6] + 4 * *(_DWORD *)(a2 + 72)) + 60),
      4500,
      "clip not supported in texture shaders");
  return -2147467259;
}
