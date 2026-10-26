int __thiscall sub_4AA730(_DWORD *this, int a2)
{
  int v3; // eax
  int v4; // eax

  v3 = this[214];
  if ( a2 == 1 )
    v4 = v3 + 1;
  else
    v4 = v3 - 1;
  this[214] = v4;
  if ( v4 >= 0 )
  {
    if ( v4 > this[215] )
      this[214] = 0;
  }
  else
  {
    this[214] = this[215];
  }
  sub_4AA580(this, 1);
  return (*(int (__thiscall **)(_DWORD *))(*this + 184))(this);
}
