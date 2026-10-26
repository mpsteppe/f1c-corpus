int __thiscall sub_5F2B30(_DWORD *this, int a2)
{
  int v2; // eax

  v2 = (a2 & 1) != 0;
  if ( (a2 & 2) != 0 )
    v2 |= 2u;
  if ( (a2 & 4) != 0 )
    v2 |= 4u;
  if ( (a2 & 8) != 0 )
    v2 |= 8u;
  this[2359] = a2;
  return (*(int (__thiscall **)(_DWORD *, int, int))(*this + 44))(this, 168, v2);
}
