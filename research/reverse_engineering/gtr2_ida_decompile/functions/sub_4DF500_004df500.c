int __thiscall sub_4DF500(_DWORD *this, int a2)
{
  int v3; // eax

  ++this[19];
  *(_DWORD *)(a2 + 68) = this;
  sub_4E2A80(this[1], this[2], this[3], this[4]);
  v3 = this[15];
  if ( v3 )
  {
    for ( ; *(_DWORD *)(v3 + 56); v3 = *(_DWORD *)(v3 + 56) )
      ;
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
