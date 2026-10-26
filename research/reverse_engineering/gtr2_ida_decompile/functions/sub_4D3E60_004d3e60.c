int __thiscall sub_4D3E60(_DWORD *this)
{
  int v2; // ecx
  int v3; // eax

  v2 = this[139] - this[145];
  this[139] = v2;
  this[139] = v2 < 0 ? 0 : v2;
  sub_4D0B20(this);
  v3 = this[144];
  this[140] = 0;
  if ( v3 )
    this[140] = (unsigned __int64)((double)(int)this[139] / (double)v3 * (double)(int)this[141] + 0.5);
  return 0;
}
