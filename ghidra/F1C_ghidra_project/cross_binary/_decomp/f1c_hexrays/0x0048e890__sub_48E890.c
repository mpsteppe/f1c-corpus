// f1c  0x0048e890  size=49
char __thiscall sub_48E890(_DWORD *this)
{
  int v2; // eax

  v2 = this[58];
  if ( v2 )
  {
    sub_5461B0(v2);
    this[58] = 0;
  }
  this[59] = 0;
  return 1;
}
