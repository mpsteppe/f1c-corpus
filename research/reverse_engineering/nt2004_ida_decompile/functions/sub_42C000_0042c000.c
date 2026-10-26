int __thiscall sub_42C000(_DWORD *this)
{
  int v2; // eax
  int result; // eax

  sub_4EEC20(1);
  sub_4EEC50(1);
  sub_4EECE0(1);
  if ( !*(_DWORD *)(this[20] + 25300) )
  {
    v2 = this[5902];
    if ( v2 && *(float *)(v2 + 24) > 0.0 )
    {
      this[5933] = -1082130432;
      this[5932] = 1092616192;
    }
    else
    {
      this[5933] = 1065353216;
      this[5932] = -1054867456;
    }
  }
  sub_51C0E0(1);
  result = this[5902];
  this[6006] = 9;
  if ( result )
    this[6032] = *(_DWORD *)(result + 24);
  else
    this[6032] = -1063256064;
  return result;
}
