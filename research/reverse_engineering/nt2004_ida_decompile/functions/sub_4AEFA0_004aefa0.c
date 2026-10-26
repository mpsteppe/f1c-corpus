int __thiscall sub_4AEFA0(_DWORD *this, int a2)
{
  int v3; // eax
  int i; // ecx

  ++this[19];
  *(_DWORD *)(a2 + 68) = this;
  sub_4B13F0(this[1], this[2], this[3], this[4]);
  v3 = sub_4AEF80(this);
  if ( v3 )
  {
    for ( i = *(_DWORD *)(v3 + 56); i; i = *(_DWORD *)(i + 56) )
      v3 = i;
    *(_DWORD *)(v3 + 56) = a2;
    return a2;
  }
  else
  {
    this[15] = a2;
    this[17] = a2;
    return a2;
  }
}
