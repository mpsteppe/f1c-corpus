char __thiscall sub_460930(int this)
{
  char result; // al
  int v2; // eax

  result = *(_BYTE *)(this + 676);
  if ( result )
  {
    v2 = *(_DWORD *)(this + 748);
    *(_BYTE *)(this + 676) = 0;
    dword_761FF8 = v2;
    return sub_455BD0(&ppvOut);
  }
  return result;
}
