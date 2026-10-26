int __thiscall sub_48EBD0(int *this)
{
  int v2; // edx
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v10; // [esp-4h] [ebp-8h]

  this[68] = sub_487060(this, 0);
  this[69] = sub_487060(this, 1);
  this[70] = sub_487060(this, 2);
  this[71] = sub_487060(this, 3);
  this[72] = sub_487060(this, 4);
  this[73] = sub_487060(this, 5);
  this[74] = sub_487060(this, 6);
  this[75] = sub_487060(this, 7);
  this[76] = sub_4870E0(this, 0);
  this[77] = sub_4870E0(this, 1);
  this[78] = sub_4870E0(this, 2);
  this[79] = sub_4870E0(this, 3);
  this[80] = sub_4870E0(this, 4);
  this[81] = sub_4870E0(this, 5);
  this[82] = sub_4870E0(this, 6);
  this[83] = sub_4870E0(this, 7);
  if ( this[80] < 0 )
    this[80] = this[1];
  if ( this[72] < 0 )
    this[72] = this[3];
  if ( this[81] < 0 )
    this[81] = this[2];
  if ( this[73] < 0 )
    this[73] = this[4];
  v2 = *this;
  v10 = this[65];
  this[93] = 0;
  (*(void (__thiscall **)(int *, int))(v2 + 64))(this, v10);
  v3 = ConditionalDelegation_6460(this, 6);
  if ( v3 )
  {
    v4 = *(_DWORD *)(v3 + 32);
    if ( v4 )
      this[57] = *(_DWORD *)(v4 + 12);
  }
  v5 = ConditionalDelegation_6460(this, 7);
  if ( v5 )
  {
    v6 = *(_DWORD *)(v5 + 32);
    if ( v6 )
      this[58] = *(_DWORD *)(v6 + 12);
  }
  v7 = ConditionalDelegation_6460(this, 5);
  if ( v7 )
  {
    v8 = *(_DWORD *)(v7 + 32);
    if ( v8 )
      this[59] = *(_DWORD *)(v8 + 12);
  }
  UIWindowTextSetup(this);
  StringCopyWithBufferRealloc(byte_5EA438);
  this[90] = 0;
  return 0;
}
