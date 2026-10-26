int __thiscall sub_4D4E60(int *this)
{
  int v2; // edx
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v7; // [esp-4h] [ebp-8h]

  this[80] = sub_4CFCC0(this, 0);
  this[81] = sub_4CFCC0(this, 1);
  this[82] = sub_4CFCC0(this, 2);
  this[83] = sub_4CFCC0(this, 3);
  this[84] = sub_4CFCC0(this, 4);
  this[85] = sub_4CFCC0(this, 5);
  this[86] = sub_4CFCC0(this, 6);
  this[87] = sub_4CFCC0(this, 7);
  this[88] = sub_4CFD30(this, 0);
  this[89] = sub_4CFD30(this, 1);
  this[90] = sub_4CFD30(this, 2);
  this[91] = sub_4CFD30(this, 3);
  this[92] = sub_4CFD30(this, 4);
  this[93] = sub_4CFD30(this, 5);
  this[94] = sub_4CFD30(this, 6);
  this[95] = sub_4CFD30(this, 7);
  if ( this[92] < 0 )
    this[92] = this[1];
  if ( this[84] < 0 )
    this[84] = this[3];
  if ( this[93] < 0 )
    this[93] = this[2];
  if ( this[85] < 0 )
    this[85] = this[4];
  v2 = *this;
  v7 = this[77];
  this[105] = 0;
  (*(void (__thiscall **)(int *, int))(v2 + 44))(this, v7);
  if ( this[61] )
  {
    v3 = sub_4E29F0(6);
    if ( v3 )
      this[68] = *(_DWORD *)(v3 + 28);
  }
  if ( this[61] )
  {
    v4 = sub_4E29F0(7);
    if ( v4 )
      this[69] = *(_DWORD *)(v4 + 28);
  }
  if ( this[61] )
  {
    v5 = sub_4E29F0(5);
    if ( v5 )
      this[70] = *(_DWORD *)(v5 + 28);
  }
  sub_4D2DF0();
  sub_615860(WindowName);
  sub_615860(WindowName);
  sub_615860(WindowName);
  this[52] = -16777216;
  sub_615860("ToolTip_bg_01.tga");
  this[55] = 0;
  sub_615860("FTIM14BLKOUTLINED");
  this[58] = 1067030938;
  this[59] = 1067030938;
  this[60] = -1;
  return 0;
}
