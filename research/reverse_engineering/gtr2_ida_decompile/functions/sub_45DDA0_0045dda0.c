char __thiscall sub_45DDA0(_DWORD *this, int a2)
{
  if ( a2 < 0 || a2 >= this[42] || !this[5 * a2 + 12] )
    return 0;
  SetCursor((HCURSOR)this[5 * a2 + 12]);
  this[43] = a2;
  return 1;
}
