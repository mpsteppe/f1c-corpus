int __thiscall sub_599620(int this, int a2, int a3)
{
  int result; // eax

  if ( a2 >= 1 && a2 <= 8 )
    *(_WORD *)(this + 180) = a2;
  result = a3;
  if ( a3 >= 1 && a3 <= 8 )
    *(_WORD *)(this + 182) = a3;
  if ( a2 != 2 || a3 != 1 )
    *(_DWORD *)(this + 156) |= 0x20u;
  return result;
}
