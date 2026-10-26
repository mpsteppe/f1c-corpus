int __thiscall sub_4D3EE0(_DWORD *this)
{
  int v2; // eax
  int v3; // ecx
  int v4; // eax

  v2 = this[145] + this[139];
  this[139] = v2;
  v3 = this[144];
  if ( v3 < v2 )
    v2 = v3;
  this[139] = v2;
  sub_4D0B20(this);
  v4 = this[144];
  this[140] = 0;
  if ( v4 )
    this[140] = (unsigned __int64)((double)(int)this[139] / (double)v4 * (double)(int)this[141] + 0.5);
  return 0;
}
