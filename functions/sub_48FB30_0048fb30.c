int __thiscall sub_48FB30(_DWORD *this, int a2)
{
  int v2; // eax
  int v3; // edx
  int v4; // eax

  v2 = a2;
  if ( a2 < 0 )
    v2 = this[94];
  v3 = v2 + this[90];
  v4 = this[91];
  this[90] = v3;
  if ( v3 > v4 )
    this[90] = v4;
  return UITileGrid(this);
}
