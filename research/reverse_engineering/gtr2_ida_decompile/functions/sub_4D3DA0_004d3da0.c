int __thiscall sub_4D3DA0(_DWORD *this)
{
  int v2; // eax

  --this[139];
  sub_4D0B20(this);
  v2 = this[144];
  this[140] = 0;
  if ( v2 )
    this[140] = (unsigned __int64)((double)(int)this[139] / (double)v2 * (double)(int)this[141] + 0.5);
  return 0;
}
