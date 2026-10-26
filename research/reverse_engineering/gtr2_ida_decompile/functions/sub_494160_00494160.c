int __thiscall sub_494160(_DWORD *this, int a2)
{
  int v2; // eax
  int v3; // eax
  int v4; // edx

  v2 = this[211];
  if ( a2 == 1 )
    v3 = v2 + 1;
  else
    v3 = v2 - 1;
  this[211] = v3;
  if ( v3 >= 0 )
  {
    if ( v3 > this[210] )
      this[211] = 0;
    return (*(int (__thiscall **)(_DWORD *))(*this + 184))(this);
  }
  else
  {
    v4 = *this;
    this[211] = this[210];
    return (*(int (**)(void))(v4 + 184))();
  }
}
