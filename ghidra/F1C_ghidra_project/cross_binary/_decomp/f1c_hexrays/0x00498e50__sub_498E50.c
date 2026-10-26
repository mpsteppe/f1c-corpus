// f1c  0x00498e50  size=91
int __thiscall sub_498E50(_DWORD *this, int a2)
{
  int v3; // eax
  int i; // ecx

  ++this[22];
  *(_DWORD *)(a2 + 80) = this;
  sub_49A9C0(this[1], this[2], this[3], this[4]);
  v3 = sub_498E30(this);
  if ( v3 )
  {
    for ( i = *(_DWORD *)(v3 + 72); i; i = *(_DWORD *)(i + 72) )
      v3 = i;
    *(_DWORD *)(v3 + 72) = a2;
    return a2;
  }
  else
  {
    this[18] = a2;
    this[20] = a2;
    return a2;
  }
}
