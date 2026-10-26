char __thiscall sub_4AD760(_DWORD *this)
{
  int v2; // eax

  v2 = this[147];
  if ( v2 > 1 )
  {
    sub_4AD5B0(this, this[v2 + 138], 0, 1);
    --this[147];
  }
  return 0;
}
