int __thiscall sub_557630(_DWORD *this)
{
  int v2; // eax
  int v3; // eax

  v2 = this[8];
  if ( (v2 & 8) != 0 )
  {
    if ( (v2 & 0x400) == 0 )
      return 0;
    v3 = Return0Stub();
  }
  else
  {
    if ( (v2 & 0x400) == 0 )
      return 0;
    v3 = ResourceTeardownWithStateArrayReset(this);
  }
  if ( v3 )
    return -1;
  this[8] &= ~0x400u;
  return 0;
}
