char __thiscall sub_4F1AA0(int this)
{
  int v2; // eax
  unsigned __int8 v4; // c0
  unsigned __int8 v5; // c2

  if ( !*(_DWORD *)(this + 12988) )
    return byte_7C9080;
  v2 = *(_DWORD *)(this + 13380);
  return v2 >= 2 && v2 <= 4 && (!(v4 | v5) || !DistanceComparison((float *)this));
}
