int __thiscall sub_4A4870(int *this)
{
  int v2; // edx
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v7; // [esp-4h] [ebp-8h]

  this[80] = sub_49D770(this, 0);
  this[81] = sub_49D770(this, 1);
  this[82] = sub_49D770(this, 2);
  this[83] = sub_49D770(this, 3);
  this[84] = sub_49D770(this, 4);
  this[85] = sub_49D770(this, 5);
  this[86] = sub_49D770(this, 6);
  this[87] = sub_49D770(this, 7);
  this[88] = sub_49D7F0(this, 0);
  this[89] = sub_49D7F0(this, 1);
  this[90] = sub_49D7F0(this, 2);
  this[91] = sub_49D7F0(this, 3);
  this[92] = sub_49D7F0(this, 4);
  this[93] = sub_49D7F0(this, 5);
  this[94] = sub_49D7F0(this, 6);
  this[95] = sub_49D7F0(this, 7);
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
  v3 = sub_49CB60(this, 6);
  if ( v3 )
    this[68] = *(_DWORD *)(v3 + 28);
  v4 = sub_49CB60(this, 7);
  if ( v4 )
    this[69] = *(_DWORD *)(v4 + 28);
  v5 = sub_49CB60(this, 5);
  if ( v5 )
    this[70] = *(_DWORD *)(v5 + 28);
  sub_4A55D0(this);
  sub_578600(&byte_629120);
  sub_578600(&byte_629120);
  sub_578600(&byte_629120);
  this[52] = -16777216;
  sub_578600(aOptionsTooltip);
  this[55] = 0;
  sub_578600(a2003tri14);
  this[58] = 1067030938;
  this[59] = 1067030938;
  this[60] = -1;
  return 0;
}
