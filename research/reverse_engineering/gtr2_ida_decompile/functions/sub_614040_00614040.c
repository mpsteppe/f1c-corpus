int __thiscall sub_614040(_DWORD *this)
{
  int v1; // eax
  int v3; // ecx

  v1 = this[5];
  if ( !v1 )
    return sub_634320(this[1]);
  v3 = this[1];
  if ( v1 == 5 )
    return *(_DWORD *)(v3 + 24);
  else
    return sub_62B120(v3);
}
