char __thiscall sub_4F8460(_DWORD *this, int a2)
{
  bool v2; // bl
  _DWORD *v3; // edx
  int v4; // eax
  int v5; // eax
  bool v6; // zf
  char result; // al

  v2 = 0;
  v3 = this;
  if ( !a2 )
    return v2;
  v4 = this[97];
  if ( v4 > 0 )
    v2 = sub_4F7CF0(this + 1, v4 - 1) == *(_DWORD *)(a2 + 25248);
  v5 = v3[194];
  if ( v5 <= 0 )
    return v2;
  v6 = sub_4F7CF0(v3 + 98, v5 - 1) == *(_DWORD *)(a2 + 25248);
  result = 1;
  if ( !v6 )
    return v2;
  return result;
}
