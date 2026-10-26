char __thiscall sub_644260(_DWORD *this, int a2)
{
  unsigned int v2; // eax

  v2 = a2 + this[2];
  if ( v2 > this[1] + this[3] )
    return 0;
  this[2] = v2;
  return 1;
}
