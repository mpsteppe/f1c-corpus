int __thiscall sub_4B3220(_DWORD *this)
{
  int v2; // eax

  ++this[70];
  v2 = sub_48F410() - 1;
  if ( this[70] > v2 )
    this[70] = v2;
  sub_4A20B0();
  return 0;
}
