// f1c  0x0044f640  size=58
char __thiscall sub_44F640(_DWORD *this, int a2)
{
  if ( a2 < 0 || a2 >= this[42] || !this[5 * a2 + 12] )
    return 0;
  SetCursor((HCURSOR)this[5 * a2 + 12]);
  this[43] = a2;
  return 1;
}
