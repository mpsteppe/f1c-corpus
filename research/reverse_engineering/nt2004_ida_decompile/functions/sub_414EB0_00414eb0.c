char __thiscall sub_414EB0(int *this)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax

  v2 = this[29];
  if ( !v2 )
    return 0;
  v3 = *(_DWORD *)(v2 + 4);
  if ( !v3 || !sub_5A97F0(v3) )
    return 0;
  v4 = sub_5A97F0(*(_DWORD *)(this[29] + 4));
  return sub_414650(this[29], v4);
}
