// f1c  0x0048faf0  size=52
int __thiscall sub_48FAF0(_DWORD *this, int a2)
{
  int v2; // eax
  int v3; // eax

  v2 = a2;
  if ( a2 < 0 )
    v2 = this[94];
  v3 = this[90] - v2;
  this[90] = v3;
  if ( v3 < 0 )
    this[90] = 0;
  return sub_48F870(this);
}
